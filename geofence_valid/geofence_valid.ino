//Yes, you are correct. In the context of geographical coordinates, latitude and longitude 
//values represent a position on the Earth's surface. Latitude measures how far north or south 
//of the Equator a location is, and longitude measures how far east or west of the Prime Meridian 
//a location is.
//
//When checking if a point is inside a geofence, comparing latitude and longitude with 
//`latitudeVertices[i]` and `longitudeVertices[i]` means that the point should be south of or equal 
//to the latitude and west of or equal to the longitude of the corresponding vertex in the geofence. 
//This is based on the assumption that the vertices in your `latitudeVertices` and `longitudeVertices` 
//arrays represent the southernmost and westernmost points of your geofence, respectively.
//
//If you have a different arrangement of vertices (for example, vertices representing the 
//northernmost and easternmost points), you would need to adjust the conditions accordingly. 
//The logic in the geofencing check should align with the arrangement of vertices to accurately 
//determine if a point is inside or outside the geofence.




double latitudeVertices[] = {7.758408, 7.75984, 7.75825, 7.75833, 7.75930, 7.76159, 7.76050}; // Latitude values of vertices
double longitudeVertices[] = {4.602038, 4.60428, 4.60360, 4.60202, 4.59988, 4.59834, 4.60191}; // Longitude values of vertices

int numVertices = sizeof(latitudeVertices) / sizeof(latitudeVertices[0]); // Number of vertices in the geofence

bool isInsideGeofence(double latitude, double longitude) {
    bool inside = false;

    for (int i = 0; i < numVertices; ++i) {
        // Check if latitude is within range
        if (latitude <= latitudeVertices[i]) {
            // Check if longitude is within range
            if (longitude <= longitudeVertices[i]) {
                inside = !inside;
                break;
            }
        }
    }

    return inside;
}


void setup() {
    Serial.begin(9600);
}

void loop() {
    // Example test point (latitude and longitude)
    double testLatitude = 7.76098;
    double testLongitude = 4.60205;

    bool insideGeofence = isInsideGeofence(testLatitude, testLongitude);

    if (insideGeofence) {
        Serial.println("Inside Geofence");
    } else {
        Serial.println("Outside Geofence");
    }

    delay(1000); // Delay for 1 second before checking again
}
