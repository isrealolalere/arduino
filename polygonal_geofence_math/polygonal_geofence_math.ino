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
    Point polygon[] = {
        {51.51477345859524, -0.06422817707061769},
        {51.51419759024719, -0.06422013044357301},
        {51.51418089830245, -0.06384462118148805},
        {51.51410467164307, -0.06359785795211793},
        {51.51409632565444, -0.06300508975982667},
        {51.51472505249964, -0.06297558546066286},
        {51.514776796890324, -0.06300777196884157}
    };

    Point testPoint = {51.514633, -0.064346}; // Test point coordinates

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
