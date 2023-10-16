#include <math.h>

double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    // Convert latitude and longitude from degrees to radians
    lat1 = radians(lat1);
    lon1 = radians(lon1);
    lat2 = radians(lat2);
    lon2 = radians(lon2);
    
    // Haversine formula
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    
    // Radius of the Earth in meters (mean value)
    const double R = 6371000; // meters
    
    // Calculate the distance
    double distance = R * c;
    
    return distance;
}

bool isInsideGeofence(double lat, double lon, double fenceLat, double fenceLon, double fenceRadius, double buffer) {
    double distance = calculateDistance(lat, lon, fenceLat, fenceLon);
    return distance <= (fenceRadius + buffer);
}


void setup() {
    double geofenceLat = -0.094333;
    double geofenceLon = 51.514456;
    double geofenceRadius = 36; // in meters
    
    double testLat = -0.094639;
    double testLon = 51.514121;
    Serial.begin(9600);
    
    bool insideGeofence = isInsideGeofence(testLat, testLon, geofenceLat, geofenceLon, geofenceRadius, 5);
    
    if (insideGeofence) {
        Serial.println("The test coordinates are INSIDE the geofence.");
    } else {
        Serial.println("The test coordinates are OUTSIDE the geofence.");
    }
}

void loop() {
    // Nothing to do here for this example
}
