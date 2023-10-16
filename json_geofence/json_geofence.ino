#include <ArduinoJson.h>
#include <SoftwareSerial.h>


// GPS module pins
#define GPS_RX 2
#define GPS_TX 3

// GSM module pins
#define GSM_RX 7
#define GSM_TX 8

SoftwareSerial gpsSerial(GPS_RX, GPS_TX); // SoftwareSerial for GPS module
SoftwareSerial gsmSerial(GSM_RX, GSM_TX); // SoftwareSerial for GSM module

char server[] = "https://static.staticsave.com";
char path[] = "/newgeofence/polygons.json";

struct Point {
    double lat;
    double lng;
};

bool isInsidePolygon(Point testPoint, Point polygon[], int numVertices) {
    int count = 0;
    for (int i = 0, j = numVertices - 1; i < numVertices; j = i++) {
        if (((polygon[i].lat > testPoint.lat) != (polygon[j].lat > testPoint.lat)) &&
            (testPoint.lng < (polygon[j].lng - polygon[i].lng) * (testPoint.lat - polygon[i].lat) / (polygon[j].lat - polygon[i].lat) + polygon[i].lng)) {
            count++;
        }
    }
    return count % 2 == 1;
}

void setup() {
    Serial.begin(9600);
    gpsSerial.begin(9600);
    gsmSerial.begin(9600);

    // Initialize GSM module here (similar to the previous examples)

    // Make HTTP request to fetch JSON data
    gsmSerial.println("AT+HTTPINIT");
    delay(1000);
    gsmSerial.print("AT+HTTPPARA=\"CID\",1");
    delay(1000);
    gsmSerial.print("AT+HTTPPARA=\"URL\",\"http://");
    gsmSerial.print(server);
    gsmSerial.print(path);
    gsmSerial.println("\"");
    delay(1000);
    gsmSerial.println("AT+HTTPACTION=0");
    delay(20000); // Wait for the HTTP request to complete

    // Read HTTP response
    gsmSerial.println("AT+HTTPREAD");
    delay(5000); // Wait for the HTTP read response to complete

    // Parse JSON data and check if test point is inside the geofence
    if (gsmSerial.available()) {
        // Read the JSON response
        String jsonResponse = gsmSerial.readString();

        // Parse JSON data
        DynamicJsonDocument jsonDoc(1024); // Adjust the size according to your JSON data size
        DeserializationError error = deserializeJson(jsonDoc, jsonResponse);

        if (error) {
            Serial.println("Error parsing JSON");
        } else {
            // Get geofence coordinates from JSON
            JsonArray polygonArray = jsonDoc["polygons"][0];
            int numVertices = polygonArray.size();
            Point polygon[numVertices];

            for (int i = 0; i < numVertices; ++i) {
                polygon[i].lat = polygonArray[i]["lat"];
                polygon[i].lng = polygonArray[i]["lng"];
            }

            Point testPoint = {51.5145, -0.063}; // Test point coordinates

            bool insidePolygon = isInsidePolygon(testPoint, polygon, numVertices);

            if (insidePolygon) {
                Serial.println("The test coordinates are INSIDE the polygonal geofence.");
            } else {
                Serial.println("The test coordinates are OUTSIDE the polygonal geofence.");
            }
        }
    }

    // Close HTTP service
    gsmSerial.println("AT+HTTPTERM");

    // Rest of your code
}

void loop() {
    // Read GPS data and perform geofencing checks here
}
