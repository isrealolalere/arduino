#include <ArduinoJson.h>

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
    // Geofence polygon coordinates
    Point polygon[] = {
        {51.516901239437615, -0.08972525596618654},
        {51.51694797407631, -0.09138822555541994},
        {51.51684115197459, -0.09144186973571779},
        {51.516487301973186, -0.09147405624389648},
        {51.51581965297458, -0.09098052978515626},
        {51.51496504797609, -0.09113073348999025},
        {51.51489160461088, -0.09031534194946289},
        {51.51597988962675, -0.08982181549072267}
    };

    //coordinates to be received from the gps module every set intervals
    Point testPoint = {51.515432, -0.09142}; // Test point coordinates

    int numVertices = sizeof(polygon) / sizeof(polygon[0]);

    bool insidePolygon = isInsidePolygon(testPoint, polygon, numVertices);

    if (insidePolygon) {
        Serial.println("The test coordinates are INSIDE the polygonal geofence.");
    } else {
        Serial.println("The test coordinates are OUTSIDE the polygonal geofence.");
    }
}

void loop() {
    // Nothing to do here for this example
}
