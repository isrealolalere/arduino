#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// Define pins for GPS module
#define GPS_RX 2  // Connect GPS TX to this pin
#define GPS_TX 3  // Connect GPS RX to this pin

// Define pins for GSM module
#define GSM_RX 7  // Connect GSM TX to this pin
#define GSM_TX 8  // Connect GSM RX to this pin

// Define fence coordinates
const double fenceLatitude = 17.53;  // Fence Latitude
const double fenceLongitude = 78.36; // Fence Longitude
const double fenceRadius = 0.01;     // Radius in degrees

SoftwareSerial gpsSerial(GPS_RX, GPS_TX); // SoftwareSerial for GPS module
SoftwareSerial gsmSerial(GSM_RX, GSM_TX); // SoftwareSerial for GSM module

TinyGPSPlus gps; // Object to hold GPS data

void setup() {
  Serial.begin(9600);   // Serial monitor
  gpsSerial.begin(9600); // GPS module
  gsmSerial.begin(9600); // GSM module
  
  delay(1000);
  sendSMS("GSM module initialized.");
}

void loop() {
  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      double latitude = gps.location.lat();
      double longitude = gps.location.lng();

      // Check if the GPS coordinates are within the fence
      if (isInsideFence(latitude, longitude)) {
        sendSMS("Device inside the fence. Latitude: " + String(latitude, 6) + ", Longitude: " + String(longitude, 6));
      } else {
        sendSMS("Device outside the fence. Latitude: " + String(latitude, 6) + ", Longitude: " + String(longitude, 6));
      }

      delay(1000); // Wait for a moment before sending another SMS
    }
  }
}

bool isInsideFence(double lat, double lon) {
  // Calculate the distance from the fence center
  double distance = TinyGPSPlus::distanceBetween(lat, lon, fenceLatitude, fenceLongitude);
  
  // Check if the distance is within the fence radius
  return distance <= fenceRadius;
}

void sendSMS(String message) {
  gsmSerial.println("AT+CMGF=1"); // Set the GSM module to text mode
  delay(100);
  
  gsmSerial.print("AT+CMGS=\"+2348160075589\"\r"); // Replace with the phone number you want to send SMS to
  delay(100);
  
  gsmSerial.println(message); // The SMS message
  delay(100);
  
  gsmSerial.println((char)26); // End SMS with Ctrl+Z
  delay(1000);
}
