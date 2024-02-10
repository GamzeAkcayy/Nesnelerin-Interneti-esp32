#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MPU6050_tockn.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();

  /*if (!mpu6050.begin()) {
    Serial.println("Failed to initialize MPU6050!");
    while (1);
  }*/

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(1000);
  display.clearDisplay();
}


void loop() {
  float ax, ay, az;
  float gx, gy, gz;
  float temp;

  mpu6050.update();

  ax = mpu6050.getAccX();
  ay = mpu6050.getAccY();
  az = mpu6050.getAccZ();

  gx = mpu6050.getGyroX();
  gy = mpu6050.getGyroY();
  gz = mpu6050.getGyroZ();

  temp = mpu6050.getTemp();

  Serial.print("Accelerometer (m/s^2): ");
  Serial.print(ax);
  Serial.print("\t");
  Serial.print(ay);
  Serial.print("\t");
  Serial.println(az);

  Serial.print("Gyroscope (rps): ");
  Serial.print(gx);
  Serial.print("\t");
  Serial.print(gy);
  Serial.print("\t");
  Serial.println(gz);

  Serial.print("Temperature (degC): ");
  Serial.println(temp);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Accel (m/s^2):");
  display.print(ax);
  display.print("\t");
  display.print(ay);
  display.print("\t");
  display.println(az);

  display.println("Gyro (rps):");
  display.print(gx);
  display.print("\t");
  display.print(gy);
  display.print("\t");
  display.println(gz);

  display.print("Temp (degC):");
  display.println(temp);
  display.display();

  delay(1000); // 1 saniye gecikme
}
