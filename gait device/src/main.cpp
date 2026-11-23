#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu; // Create an instance of the MPU6050 class
bool isRecording = false;

bool lastButtonState = HIGH;
void setup() {
  pinMode(33, INPUT_PULLUP); // Set pin 33 as input with pull-up resistor, pressed = high,  released = low
  Serial.begin(115200);
  Wire.begin(25, 27); // Initialize I2C with SDA on pin 25 and SCL on pin 27
  
if (!mpu.begin()) {
  Serial.println("MPU6050 connection failed");
  while (1) {
  delay(10);  
  }
}
Serial.println("MPU6050 connection successful");
}

float accel (float &ax, float &ay, float &az) {
 sensors_event_t a, g, temp; // creating an instance of sensors_event_t type struct to hold the acceleration data
 mpu.getEvent(&a, &g, &temp); //& tells getEvent to store value in an object 'a' of type sensors_event_t
  ax = a.acceleration.x; //acceleration.x part comes from unified sensor library. 
                         // sensors_event_t is a struct that contains multiple sensor data (accel, gyro, temp, etc.) 
                         // and .acceleration specifies that we're collecting acceleration
                         // acceleration is a member of sensors_vec_t struct which defines x, y and z component --> we're now specifically storing value to a>acceleration>x
  ay = a.acceleration.y;
  az = a.acceleration.z; 
 float rAccel = sqrt(ax * ax + ay * ay + az * az); // resultant acceleration

 return rAccel;
}

float gyro(float &gx, float &gy, float &gz) {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  gx = g.gyro.x * 180.0 / PI; 
  gy = g.gyro.y * 180.0 / PI;
  gz = g.gyro.z * 180.0 / PI;
  delay ()
  float rGyro = sqrt(gx * gx + gy * gy + gz * gz);

  return rGyro;
}

void loop () {
  bool buttonState = digitalRead(33);
   if (buttonState == LOW && lastButtonState == HIGH) {
    isRecording = !isRecording; // Toggle recording state
    if (isRecording) {
      Serial.println("Recording started");
    } else {
      Serial.println("Recording stopped");
    }
    delay (50); //debounce delay
  }
   lastButtonState = buttonState;
  if (isRecording) {
    float ax, ay, az;
    float gx, gy, gz;

 
    float acceleration = accel(ax, ay, az);
    float angularVelocity = gyro(gx, gy, gz);

    float time = millis() / 1000.0;

    printf("Time: %.2f seconds\n", time);
    printf("Acceleration x: %.2f, y: %.2f, z: %.2f\n", ax, ay, az);
    printf("Resultant acceleration: %.2f m/s^2\n", acceleration);
    printf("Gyroscope x: %.2f, y: %.2f, z: %.2f\n", gx, gy, gz);
    printf("Resultant angular velocity: %.2f deg/s\n", angularVelocity);

    delay(20);
  }
}