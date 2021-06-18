#include <Adafruit_NeoPixel.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#define PIN 2

#define NUMPIXELS 54

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_MPU6050 mpu;

float _time = (millis() / 1000);

long day = 86400;
int _millis_reduction = 0;

int delayval = 10; // timing delay

int start_time = millis();
int current_Time = 0;

int redColor = random(0);
int greenColor = random(0);
int blueColor = random(0);

int randred = 0;
int randgreen = 0;
int randblue = 0;

int Time_Min = 0;
int Time_Hour = 0;

int Hour_1 = 0;/*slot 1*/
int Hour_2 = 0;/*slot 2*/
int Min_1 = 0;/*slot 3*/
int Min_2 = 0;/*slot 4*/

int LED_1 = 0;
int LED_2 = 0;
int LED_3 = 0;
int LED_4 = 0;
int LED_5 = 0;
int LED_6 = 0;
int LED_7 = 0;
int LED_8 = 0;
int LED_9 = 0;
int LED_10= 0;
int LED_11= 0;
int LED_12= 0;
int LED_13= 0;

int LED_14= 0;
int LED_15= 0;
int LED_16= 0;
int LED_17= 0;
int LED_18= 0;
int LED_19= 0;
int LED_20= 0;
int LED_21= 0;
int LED_22= 0;
int LED_23= 0;
int LED_24= 0;
int LED_25= 0;
int LED_26= 0;

int LED_27= 0;
int LED_28= 0;
int LED_29= 0;
int LED_30= 0;
int LED_31= 0;
int LED_32= 0;
int LED_33= 0;
int LED_34= 0;
int LED_35= 0;
int LED_36= 0;
int LED_37= 0;
int LED_38= 0;
int LED_39= 0;

int LED_40= 0;
int LED_41= 0;
int LED_42= 0;
int LED_43= 0;
int LED_44= 0;
int LED_45= 0;
int LED_46= 0;
int LED_47= 0;
int LED_48= 0;
int LED_49= 0;
int LED_50= 0;
int LED_51= 0;
int LED_52= 0;

int hold = 0;
int button = 0;
int Change_Mode = 2; /* 1 = Hours 2 = Mins*/

int knock = 1;
int knock_Timer;

const int knockSensor = A0;
const int threshold = 100;
int sensorReading = 0;

const int sampleWindow = 50;
unsigned int sample;

void setup() {
  pixels.begin();
  Serial.begin(115200);
  slot1setNumber_0();
  slot2setNumber_0();
  slot3setNumber_0();
  slot4setNumber_0();
  pinMode(13, INPUT);

  while (!Serial) {
    delay(10);
  }

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setGyroRange(MPU6050_RANGE_250_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.println("");
  delay(100);
}

void loop() {

  sensorReading = analogRead(knockSensor);

  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
/*Serial.println(a.acceleration.x);
  Serial.print(",");
  Serial.println(a.acceleration.y);
  Serial.print(",");
*/Serial.println(a.acceleration.z);/*
  Serial.print(", ");
  Serial.print(g.gyro.x);
  Serial.print(",");
  Serial.print(g.gyro.y);
  Serial.print(",");
  Serial.print(g.gyro.z);
  Serial.println("");*/

  randred = random(1, 33);
  randgreen = random(1, 33);
  randblue = random(1, 33);

  if (Time_Hour > 9){
    //Serial.print(Time_Hour);
  }if (Time_Hour <= 9){
    //Serial.print("0");
    //Serial.print(Time_Hour);
  }//Serial.print(":");
  if (Time_Min > 9){
    //Serial.println(Time_Min);
  }if (Time_Min <= 9){
    //Serial.print("0");
    //Serial.println(Time_Min);
  }if (Time_Min < 10){
   Min_1 = 0;
  }if (Time_Min > 9 and Time_Min <20){
    Min_1 = 1;
  }if (Time_Min > 19 and Time_Min < 30){
    Min_1 = 2;
  }if (Time_Min > 29 and Time_Min < 40){
    Min_1 = 3;
  }if (Time_Min > 39 and Time_Min < 50){
    Min_1 = 4;
  }if (Time_Min > 49 and Time_Min < 60){
    Min_1 = 5;
  }if (Time_Min == 0 or Time_Min == 10 or Time_Min == 20 or Time_Min == 30 or Time_Min == 40 or Time_Min == 50){
    Min_2 = 0;
  }if (Time_Min == 1 or Time_Min == 11 or Time_Min == 21 or Time_Min == 31 or Time_Min == 41 or Time_Min == 51){
    Min_2 = 1;
  }if (Time_Min == 2 or Time_Min == 12 or Time_Min == 22 or Time_Min == 32 or Time_Min == 42 or Time_Min == 52){
    Min_2 = 2;
  }if (Time_Min == 3 or Time_Min == 13 or Time_Min == 23 or Time_Min == 33 or Time_Min == 43 or Time_Min == 53){
    Min_2 = 3;
  }if (Time_Min == 4 or Time_Min == 14 or Time_Min == 24 or Time_Min == 34 or Time_Min == 44 or Time_Min == 54){
    Min_2 = 4;
  }if (Time_Min == 5 or Time_Min == 15 or Time_Min == 25 or Time_Min == 35 or Time_Min == 45 or Time_Min == 55){
    Min_2 = 5;
  }if (Time_Min == 6 or Time_Min == 16 or Time_Min == 26 or Time_Min == 36 or Time_Min == 46 or Time_Min == 56){
    Min_2 = 6;
  }if (Time_Min == 7 or Time_Min == 17 or Time_Min == 27 or Time_Min == 37 or Time_Min == 47 or Time_Min == 57){
    Min_2 = 7;
  }if (Time_Min == 8 or Time_Min == 18 or Time_Min == 28 or Time_Min == 38 or Time_Min == 48 or Time_Min == 58){
    Min_2 = 8;
  }if (Time_Min == 9 or Time_Min == 19 or Time_Min == 29 or Time_Min == 39 or Time_Min == 49 or Time_Min == 59){
    Min_2 = 9;
  }

  if (Time_Hour < 10){
    Hour_1 = 0;
  }if (Time_Hour > 9 and Time_Hour <20){
    Hour_1 = 1;
  }if (Time_Hour > 19 and Time_Hour < 30){
    Hour_1 = 2;
  }if (Time_Hour == 0 or Time_Hour == 10 or Time_Hour == 20){
    Hour_2 = 0;
  }if (Time_Hour == 1 or Time_Hour == 11 or Time_Hour == 21){
    Hour_2 = 1;
  }if (Time_Hour == 2 or Time_Hour == 12 or Time_Hour == 22){
    Hour_2 = 2;
  }if (Time_Hour == 3 or Time_Hour == 13 or Time_Hour == 23){
    Hour_2 = 3;
  }if (Time_Hour == 4 or Time_Hour == 14 or Time_Hour == 24){
    Hour_2 = 4;
  }if (Time_Hour == 5 or Time_Hour == 15){
    Hour_2 = 5;
  }if (Time_Hour == 6 or Time_Hour == 16){
    Hour_2 = 6;
  }if (Time_Hour == 7 or Time_Hour == 17){
    Hour_2 = 7;
  }if (Time_Hour == 8 or Time_Hour == 18){
    Hour_2 = 8;
  }if (Time_Hour == 9 or Time_Hour == 19){
    Hour_2 = 9;
  }

  if (_time == 60){
    if (Time_Min < 60){
      Time_Min = Time_Min + 1;
    }if(Time_Min == 60){
      Time_Min = 0;
      if(Time_Hour < 24){
        Time_Hour = Time_Hour + 1;
      }if(Time_Hour == 24){
        Time_Hour = 0;
        _millis_reduction = _millis_reduction + day;
        _time = _time - (_millis_reduction);
      }
    }
  }

  button = digitalRead(13);
  hold = 0;

  while (button == 0){
    hold ++;
    /*Serial.println(button);
    Serial.println(hold);*/
    button = digitalRead(13);
    delay(1000);
    if (hold == 5){
      if (Change_Mode == 2){
        Change_Mode = 1;
        break;
      }else if (Change_Mode == 1){
        Change_Mode = 2;
        break;
      }
    }
  }
  if (button == 0){
    if (Change_Mode == 1){
      Time_Hour ++;
    }
    if (Change_Mode == 2){
      Time_Min ++;
    }
  }
  /*Serial.println(button);*/
  /*Serial.println(hold);*/
  Serial.print ("Hour_1:");
  Serial.println (Hour_1);
  Serial.print ("Hour_2:");
  Serial.println (Hour_2);
  Serial.print ("Min_1:");
  Serial.println (Min_1);
  Serial.print ("Min_2:");
  Serial.println (Min_2);
  //Serial.print("Mode:");
  //Serial.println(Change_Mode);

  Set_Disp();

  _time = ((millis() / 1000) - (Time_Min * 60));
  /*Serial.print("Seconds: ");
  Serial.println (_time);*/

  if (sensorReading >= threshold){
    knock = 0;
    knock_Timer = (millis() / 1000) + 15;
  }else if (sensorReading != threshold and knock_Timer <= millis()){
    knock = 1;
  }

  unsigned long startMillis= millis();
  unsigned int peakToPeak = 0;

  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;

  while (millis() - startMillis < sampleWindow){
    sample = analogRead(A0);
    if (sample < 1024){  // toss out spurious readings
      if (sample > signalMax){
        signalMax = sample;  // save just the max levels
      }else if (sample < signalMin){
        signalMin = sample;  // save just the min levels
      }
    }
  }
  peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
  double volts = (peakToPeak * 5.0) / 1024;  // convert to volts
  /*Serial.println(volts);*/

  if (knock == 0){ //volts *40
    if (redColor < 255 and greenColor < 255 and blueColor < 255){
      redColor = (volts*40) + randred;
      greenColor = (volts * 40) + randgreen;
      blueColor = (volts * 40) + randblue;
    }
  }

  if (knock == 1){
    if (a.acceleration.z < 8 or a.acceleration.z > 4){
      if (redColor < 255 and greenColor < 255 and blueColor < 255){
        redColor = (volts * 40) + randred;
        greenColor = (volts * 40) + randgreen;
        blueColor = (volts * 40) + randblue;
      }
    }
    if (a.acceleration.z > 8 or a.acceleration.z < 4){
    redColor = 255;
    greenColor = 0;
    blueColor = 0;
    }
  }
}

void slot1setNumber_0(){
  LED_1 = 1;
  LED_2 = 1;
  LED_3 = 1;
  LED_4 = 1;
  LED_5 = 1;
  LED_6 = 1;
  LED_7 = 0;
  LED_8 = 1;
  LED_9 = 1;
  LED_10= 1;
  LED_11= 1;
  LED_12= 1;
  LED_13= 1;
}void slot1setNumber_1(){
  LED_1 = 0;
  LED_2 = 0;
  LED_3 = 0;
  LED_4 = 0;
  LED_5 = 0;
  LED_6 = 0;
  LED_7 = 0;
  LED_8 = 0;
  LED_9 = 1;
  LED_10= 1;
  LED_11= 1;
  LED_12= 1;
  LED_13= 1;
}void slot1setNumber_2(){
  LED_1 = 1;
  LED_2 = 1;
  LED_3 = 1;
  LED_4 = 0;
  LED_5 = 1;
  LED_6 = 1;
  LED_7 = 1;
  LED_8 = 1;
  LED_9 = 1;
  LED_10 = 0;
  LED_11 = 1;
  LED_12 = 1;
  LED_13 = 1;
}void slot1setNumber_3(){
  LED_1 = 1;
  LED_2 = 0;
  LED_3 = 1;
  LED_4 = 0;
  LED_5 = 1;
  LED_6 = 1;
  LED_7 = 1;
  LED_8 = 1;
  LED_9 = 1;
  LED_10= 1;
  LED_11= 1;
  LED_12= 1;
  LED_13= 1;
}void slot1setNumber_4(){
  LED_1 = 0;
  LED_2 = 0;
  LED_3 = 1;
  LED_4 = 1;
  LED_5 = 1;
  LED_6 = 0;
  LED_7 = 1;
  LED_8 = 0;
  LED_9 = 1;
  LED_10= 1;
  LED_11= 1;
  LED_12= 1;
  LED_13= 1;
}void slot1setNumber_5(){
  LED_1 = 1;
  LED_2 = 0;
  LED_3 = 1;
  LED_4 = 1;
  LED_5 = 1;
  LED_6 = 1;
  LED_7 = 1;
  LED_8 = 1;
  LED_9 = 1;
  LED_10= 1;
  LED_11= 1;
  LED_12= 0;
  LED_13= 1;
}void slot1setNumber_6(){
  LED_1 = 1;
  LED_2 = 1;
  LED_3 = 1;
  LED_4 = 1;
  LED_5 = 1;
  LED_6 = 1;
  LED_7 = 1;
  LED_8 = 1;
  LED_9 = 1;
  LED_10= 1;
  LED_11= 1;
  LED_12= 0;
  LED_13= 1;
}void slot1setNumber_7(){
  LED_1 = 0;
  LED_2 = 0;
  LED_3 = 0;
  LED_4 = 0;
  LED_5 = 1;
  LED_6 = 0;
  LED_7 = 0;
  LED_8 = 1;
  LED_9 = 1;
  LED_10= 1;
  LED_11= 1;
  LED_12= 1;
  LED_13= 1;
}void slot1setNumber_8(){
  LED_1 = 1;
  LED_2 = 1;
  LED_3 = 1;
  LED_4 = 1;
  LED_5 = 1;
  LED_6 = 1;
  LED_7 = 1;
  LED_8 = 1;
  LED_9 = 1;
  LED_10= 1;
  LED_11= 1;
  LED_12= 1;
  LED_13= 1;
}void slot1setNumber_9(){
  LED_1 = 1;
  LED_2 = 0;
  LED_3 = 1;
  LED_4 = 1;
  LED_5 = 1;
  LED_6 = 1;
  LED_7 = 1;
  LED_8 = 1;
  LED_9 = 1;
  LED_10= 1;
  LED_11= 1;
  LED_12= 1;
  LED_13= 1;
}void slot2setNumber_0(){
  LED_14= 1;
  LED_15= 1;
    LED_16= 1;
  LED_17= 1;
  LED_18= 1;
  LED_19= 1;
  LED_20= 0;
  LED_21= 1;
  LED_22= 1;
  LED_23= 1;
  LED_24= 1;
  LED_25= 1;
  LED_26= 1;
}void slot2setNumber_1(){
  LED_14= 0;
  LED_15= 0;
  LED_16= 0;
  LED_17= 0;
  LED_18= 0;
  LED_19= 0;
  LED_20= 0;
  LED_21= 0;
  LED_22= 1;
  LED_23= 1;
  LED_24= 1;
  LED_25= 1;
  LED_26= 1;
}void slot2setNumber_2(){
  LED_14= 1;
  LED_15= 1;
  LED_16= 1;
  LED_17= 0;
  LED_18= 1;
  LED_19= 1;
  LED_20= 1;
  LED_21= 1;
  LED_22= 1;
  LED_23= 0;
  LED_24= 1;
  LED_25= 1;
  LED_26= 1;
}void slot2setNumber_3(){
  LED_14= 1;
  LED_15= 0;
  LED_16= 1;
  LED_17= 0;
  LED_18= 1;
  LED_19= 1;
  LED_20= 1;
  LED_21= 1;
  LED_22= 1;
  LED_23= 1;
  LED_24= 1;
  LED_25= 1;
  LED_26= 1;
}void slot2setNumber_4(){
  LED_14= 0;
  LED_15= 0;
  LED_16= 1;
  LED_17= 1;
  LED_18= 1;
  LED_19= 0;
  LED_20= 1;
  LED_21= 0;
  LED_22= 1;
  LED_23= 1;
  LED_24= 1;
  LED_25= 1;
  LED_26= 1;
}void slot2setNumber_5(){
  LED_14= 1;
  LED_15= 0;
  LED_16= 1;
  LED_17= 1;
  LED_18= 1;
  LED_19= 1;
  LED_20= 1;
  LED_21= 1;
  LED_22= 1;
  LED_23= 1;
  LED_24= 1;
  LED_25= 0;
  LED_26= 1;
}void slot2setNumber_6(){
  LED_14= 1;
  LED_15= 1;
  LED_16= 1;
  LED_17= 1;
  LED_18= 1;
  LED_19= 1;
  LED_20= 1;
  LED_21= 1;
  LED_22= 1;
  LED_23= 1;
  LED_24= 1;
  LED_25= 0;
  LED_26= 1;
}void slot2setNumber_7(){
  LED_14= 0;
  LED_15= 0;
  LED_16= 0;
  LED_17= 0;
  LED_18= 1;
  LED_19= 0;
  LED_20= 0;
  LED_21= 1;
  LED_22= 1;
  LED_23= 1;
  LED_24= 1;
  LED_25= 1;
  LED_26= 1;
}void slot2setNumber_8(){
  LED_14= 1;
  LED_15= 1;
  LED_16= 1;
  LED_17= 1;
  LED_18= 1;
  LED_19= 1;
  LED_20= 1;
  LED_21= 1;
  LED_22= 1;
  LED_23= 1;
  LED_24= 1;
  LED_25= 1;
  LED_26= 1;
}void slot2setNumber_9(){
  LED_14= 1;
  LED_15= 0;
  LED_16= 1;
  LED_17= 1;
  LED_18= 1;
  LED_19= 1;
  LED_20= 1;
  LED_21= 1;
  LED_22= 1;
  LED_23= 1;
  LED_24= 1;
  LED_25= 1;
  LED_26= 1;
}void slot3setNumber_0(){
  LED_27= 1;
  LED_28= 1;
  LED_29= 1;
  LED_30= 1;
  LED_31= 1;
  LED_32= 1;
  LED_33= 0;
  LED_34= 1;
  LED_35= 1;
  LED_36= 1;
  LED_37= 1;
  LED_38= 1;
  LED_39= 1;
}void slot3setNumber_1(){
  LED_27= 0;
  LED_28= 0;
  LED_29= 0;
  LED_30= 0;
  LED_31= 0;
  LED_32= 0;
  LED_33= 0;
  LED_34= 0;
  LED_35= 1;
  LED_36= 1;
  LED_37= 1;
  LED_38= 1;
  LED_39= 1;
}void slot3setNumber_2(){
  LED_27= 1;
  LED_28= 1;
  LED_29= 1;
  LED_30= 0;
  LED_31= 1;
  LED_32= 1;
  LED_33= 1;
  LED_34= 1;
  LED_35= 1;
  LED_36= 0;
  LED_37= 1;
  LED_38= 1;
  LED_39= 1;
}void slot3setNumber_3(){
  LED_27= 1;
  LED_28= 0;
  LED_29= 1;
  LED_30= 0;
  LED_31= 1;
  LED_32= 1;
  LED_33= 1;
  LED_34= 1;
  LED_35= 1;
  LED_36= 1;
  LED_37= 1;
  LED_38= 1;
  LED_39= 1;
}void slot3setNumber_4(){
  LED_27= 0;
  LED_28= 0;
  LED_29= 1;
  LED_30= 1;
  LED_31= 1;
  LED_32= 0;
  LED_33= 1;
  LED_34= 0;
  LED_35= 1;
  LED_36= 1;
  LED_37= 1;
  LED_38= 1;
  LED_39= 1;
}void slot3setNumber_5(){
  LED_27= 1;
  LED_28= 0;
  LED_29= 1;
  LED_30= 1;
  LED_31= 1;
  LED_32= 1;
  LED_33= 1;
  LED_34= 1;
  LED_35= 1;
  LED_36= 1;
  LED_37= 1;
  LED_38= 0;
  LED_39= 1;
}void slot3setNumber_6(){
  LED_27= 1;
  LED_28= 1;
  LED_29= 1;
  LED_30= 1;
  LED_31= 1;
  LED_32= 1;
  LED_33= 1;
  LED_34= 1;
  LED_35= 1;
  LED_36= 1;
  LED_37= 1;
  LED_38= 0;
  LED_39= 1;
}void slot3setNumber_7(){
  LED_27= 0;
  LED_28= 0;
  LED_29= 0;
  LED_20= 0;
  LED_31= 1;
  LED_32= 0;
  LED_33= 0;
  LED_34= 1;
  LED_35= 1;
  LED_36= 1;
  LED_37= 1;
  LED_38= 1;
  LED_39= 1;
}void slot3setNumber_8(){
  LED_27= 1;
  LED_28= 1;
  LED_29= 1;
  LED_30= 1;
  LED_31= 1;
  LED_32= 1;
  LED_33= 1;
  LED_34= 1;
  LED_35= 1;
  LED_36= 1;
  LED_37= 1;
  LED_38= 1;
  LED_39= 1;
}void slot3setNumber_9(){
  LED_27= 1;
  LED_28= 0;
  LED_29= 1;
  LED_30= 1;
  LED_31= 1;
  LED_32= 1;
  LED_33= 1;
  LED_34= 1;
  LED_35= 1;
  LED_36= 1;
  LED_37= 1;
  LED_38= 1;
  LED_39= 1;
}void slot4setNumber_0(){
  LED_40= 1;
  LED_41= 1;
  LED_42= 1;
  LED_43= 1;
  LED_44= 1;
  LED_45= 1;
  LED_46= 0;
  LED_47= 1;
  LED_48= 1;
  LED_49= 1;
  LED_50= 1;
  LED_51= 1;
  LED_52= 1;
}void slot4setNumber_1(){
  LED_40= 0;
  LED_41= 0;
  LED_42= 0;
  LED_43= 0;
  LED_44= 0;
  LED_45= 0;
  LED_46= 0;
  LED_47= 0;
  LED_48= 1;
  LED_49= 1;
  LED_50= 1;
  LED_51= 1;
  LED_52= 1;
}void slot4setNumber_2(){
  LED_40= 1;
  LED_41= 1;
  LED_42= 1;
  LED_43= 0;
  LED_44= 1;
  LED_45= 1;
  LED_46= 1;
  LED_47= 1;
  LED_48= 1;
  LED_49= 0;
  LED_50= 1;
  LED_51= 1;
  LED_52= 1;
}void slot4setNumber_3(){
  LED_40= 1;
  LED_41= 0;
  LED_42= 1;
  LED_43= 0;
  LED_44= 1;
  LED_45= 1;
  LED_46= 1;
  LED_47= 1;
  LED_48= 1;
  LED_49= 1;
  LED_50= 1;
  LED_51= 1;
  LED_52= 1;
}void slot4setNumber_4(){
  LED_40= 0;
  LED_41= 0;
  LED_42= 1;
  LED_43= 1;
  LED_44= 1;
  LED_45= 0;
  LED_46= 1;
  LED_47= 0;
  LED_48= 1;
  LED_49= 1;
  LED_50= 1;
  LED_51= 1;
  LED_52= 1;
}void slot4setNumber_5(){
  LED_40= 1;
  LED_41= 0;
  LED_42= 1;
  LED_43= 1;
  LED_44= 1;
  LED_45= 1;
  LED_46= 1;
  LED_47= 1;
  LED_48= 1;
  LED_49= 1;
  LED_50= 1;
  LED_51= 0;
  LED_52= 1;
}void slot4setNumber_6(){
  LED_40= 1;
  LED_41= 1;
  LED_42= 1;
  LED_43= 1;
  LED_44= 1;
  LED_45= 1;
  LED_46= 1;
  LED_47= 1;
  LED_48= 1;
  LED_49= 1;
  LED_50= 1;
  LED_51= 0;
  LED_52= 1;
}void slot4setNumber_7(){
  LED_40= 0;
  LED_41= 0;
  LED_42= 0;
  LED_43= 0;
  LED_44= 1;
  LED_45= 0;
  LED_46= 0;
  LED_47= 1;
  LED_48= 1;
  LED_49= 1;
  LED_50= 1;
  LED_51= 1;
  LED_52= 1;
}void slot4setNumber_8(){
  LED_40= 1;
  LED_41= 1;
  LED_42= 1;
  LED_43= 1;
  LED_44= 1;
  LED_45= 1;
  LED_46= 1;
  LED_47= 1;
  LED_48= 1;
  LED_49= 1;
  LED_50= 1;
  LED_51= 1;
  LED_52= 1;
}void slot4setNumber_9(){
  LED_40= 1;
  LED_41= 0;
  LED_42= 1;
  LED_43= 1;
  LED_44= 1;
  LED_45= 1;
  LED_46= 1;
  LED_47= 1;
  LED_48= 1;
  LED_49= 1;
  LED_50= 1;
  LED_51= 1;
  LED_52= 1;
}

void Set_Disp(){
    if (Hour_1 == 0){
      slot1setNumber_0();
    }if (Hour_1 == 1){
      slot1setNumber_1();
    }if (Hour_1 == 2){
      slot1setNumber_2();
    }if (Hour_1 == 3){
      slot1setNumber_3();
    }if (Hour_1 == 4){
      slot1setNumber_4();
    }if (Hour_1 == 5){
      slot1setNumber_5();
    }if (Hour_1 == 6){
      slot1setNumber_6();
    }if (Hour_1 == 7){
      slot1setNumber_7();
    }if (Hour_1 == 8){
      slot1setNumber_8();
    }if (Hour_1 == 9){
      slot1setNumber_9();
    }

    if (Hour_2 == 0){
      slot2setNumber_0();
    }if (Hour_2 == 1){
      slot2setNumber_1();
    }if (Hour_2 == 2){
      slot2setNumber_2();
    }if (Hour_2 == 3){
      slot2setNumber_3();
    }if (Hour_2 == 4){
      slot2setNumber_4();
    }if (Hour_2 == 5){
      slot2setNumber_5();
    }if (Hour_2 == 6){
      slot2setNumber_6();
    }if (Hour_2 == 7){
      slot2setNumber_7();
    }if (Hour_2 == 8){
      slot2setNumber_8();
    }if (Hour_2 == 9){
      slot2setNumber_9();
    }
    
    if (Min_1 == 0){
      slot3setNumber_0();
    }if (Min_1 == 1){
      slot3setNumber_1();
    }if (Min_1 == 2){
      slot3setNumber_2();
    }if (Min_1 == 3){
      slot3setNumber_3();
    }if (Min_1 == 4){
      slot3setNumber_4();
    }if (Min_1 == 5){
      slot3setNumber_5();
    }if (Min_1 == 6){
      slot3setNumber_6();
    }if (Min_1 == 7){
      slot3setNumber_7();
    }if (Min_1 == 8){
      slot3setNumber_8();
    }if (Min_1 == 9){
      slot3setNumber_9();
    }
    
    if (Min_2 == 0){
      slot4setNumber_0();
    }if (Min_2 == 1){
      slot4setNumber_1();
    }if (Min_2 == 2){
      slot4setNumber_2();
    }if (Min_2 == 3){
      slot4setNumber_3();
    }if (Min_2 == 4){
      slot4setNumber_4();
    }if (Min_2 == 5){
      slot4setNumber_5();
    }if (Min_2 == 6){
      slot4setNumber_6();
    }if (Min_2 == 7){
      slot4setNumber_7();
    }if (Min_2 == 8){
      slot4setNumber_8();
    }if (Min_2 == 9){
      slot4setNumber_9();
    }
    
    if (LED_1 == 1){
      pixels.setPixelColor(0, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_2 == 1){
      pixels.setPixelColor(1, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_3 == 1){
      pixels.setPixelColor(2, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_4 == 1){
      pixels.setPixelColor(3, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_5 == 1){
      pixels.setPixelColor(4, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_6 == 1){
      pixels.setPixelColor(5, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_7 == 1){
      pixels.setPixelColor(6, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_8 == 1){
      pixels.setPixelColor(7, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_9 == 1){
      pixels.setPixelColor(8, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_10 == 1){
      pixels.setPixelColor(9, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_11 == 1){
      pixels.setPixelColor(10, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_12 == 1){
      pixels.setPixelColor(11, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_13 == 1){
      pixels.setPixelColor(12, pixels.Color(redColor, greenColor, blueColor));
    }
    
    if (LED_1 == 0){
      pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    }if (LED_2 == 0){
      pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    }if (LED_3 == 0){
      pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    }if (LED_4 == 0){
      pixels.setPixelColor(3, pixels.Color(0, 0, 0));
    }if (LED_5 == 0){
      pixels.setPixelColor(4, pixels.Color(0, 0, 0));
    }if (LED_6 == 0){
      pixels.setPixelColor(5, pixels.Color(0, 0, 0));
    }if (LED_7 == 0){
      pixels.setPixelColor(6, pixels.Color(0, 0, 0));
    }if (LED_8 == 0){
      pixels.setPixelColor(7, pixels.Color(0, 0, 0));
    }if (LED_9 == 0){
      pixels.setPixelColor(8, pixels.Color(0, 0, 0));
    }if (LED_10 == 0){
      pixels.setPixelColor(9, pixels.Color(0, 0, 0));
    }if (LED_11 == 0){
      pixels.setPixelColor(10, pixels.Color(0, 0, 0));
    }if (LED_12 == 0){
      pixels.setPixelColor(11, pixels.Color(0, 0, 0));
    }if (LED_13 == 0){
      pixels.setPixelColor(12, pixels.Color(0, 0, 0));
    }
    
    if (LED_14 == 1){
      pixels.setPixelColor(13, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_15 == 1){
      pixels.setPixelColor(14, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_16 == 1){
      pixels.setPixelColor(15, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_17 == 1){
      pixels.setPixelColor(16, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_18 == 1){
      pixels.setPixelColor(17, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_19 == 1){
      pixels.setPixelColor(18, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_20 == 1){
      pixels.setPixelColor(19, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_21 == 1){
      pixels.setPixelColor(20, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_22 == 1){
      pixels.setPixelColor(21, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_23 == 1){
      pixels.setPixelColor(22, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_24 == 1){
      pixels.setPixelColor(23, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_25 == 1){
      pixels.setPixelColor(24, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_26 == 1){
      pixels.setPixelColor(25, pixels.Color(redColor, greenColor, blueColor));
    }
    
    if (LED_14 == 0){
      pixels.setPixelColor(13, pixels.Color(0, 0, 0));
    }if (LED_15 == 0){
      pixels.setPixelColor(14, pixels.Color(0, 0, 0));
    }if (LED_16 == 0){
      pixels.setPixelColor(15, pixels.Color(0, 0, 0));
    }if (LED_17 == 0){
      pixels.setPixelColor(16, pixels.Color(0, 0, 0));
    }if (LED_18 == 0){
      pixels.setPixelColor(17, pixels.Color(0, 0, 0));
    }if (LED_19 == 0){
      pixels.setPixelColor(18, pixels.Color(0, 0, 0));
    }if (LED_20 == 0){
      pixels.setPixelColor(19, pixels.Color(0, 0, 0));
    }if (LED_21 == 0){
      pixels.setPixelColor(20, pixels.Color(0, 0, 0));
    }if (LED_22 == 0){
      pixels.setPixelColor(21, pixels.Color(0, 0, 0));
    }if (LED_23 == 0){
      pixels.setPixelColor(22, pixels.Color(0, 0, 0));
    }if (LED_24 == 0){
      pixels.setPixelColor(23, pixels.Color(0, 0, 0));
    }if (LED_25 == 0){
      pixels.setPixelColor(24, pixels.Color(0, 0, 0));
    }if (LED_26 == 0){
      pixels.setPixelColor(25, pixels.Color(0, 0, 0));
    }
    
    if (LED_27 == 1){
      pixels.setPixelColor(26, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_28 == 1){
      pixels.setPixelColor(27, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_29 == 1){
      pixels.setPixelColor(28, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_30 == 1){
      pixels.setPixelColor(29, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_31 == 1){
      pixels.setPixelColor(30, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_32 == 1){
      pixels.setPixelColor(31, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_33 == 1){
      pixels.setPixelColor(32, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_34 == 1){
      pixels.setPixelColor(33, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_35 == 1){
      pixels.setPixelColor(34, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_36 == 1){
      pixels.setPixelColor(35, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_37 == 1){
      pixels.setPixelColor(36, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_38 == 1){
      pixels.setPixelColor(37, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_39 == 1){
      pixels.setPixelColor(38, pixels.Color(redColor, greenColor, blueColor));
    }
    
    if (LED_27 == 0){
      pixels.setPixelColor(26, pixels.Color(0, 0, 0));
    }if (LED_28 == 0){
      pixels.setPixelColor(27, pixels.Color(0, 0, 0));
    }if (LED_29 == 0){
      pixels.setPixelColor(28, pixels.Color(0, 0, 0));
    }if (LED_30 == 0){
      pixels.setPixelColor(29, pixels.Color(0, 0, 0));
    }if (LED_31 == 0){
      pixels.setPixelColor(30, pixels.Color(0, 0, 0));
    }if (LED_32 == 0){
      pixels.setPixelColor(31, pixels.Color(0, 0, 0));
    }if (LED_33 == 0){
      pixels.setPixelColor(32, pixels.Color(0, 0, 0));
    }if (LED_34 == 0){
      pixels.setPixelColor(33, pixels.Color(0, 0, 0));
    }if (LED_35 == 0){
      pixels.setPixelColor(34, pixels.Color(0, 0, 0));
    }if (LED_36 == 0){
      pixels.setPixelColor(35, pixels.Color(0, 0, 0));
    }if (LED_37 == 0){
      pixels.setPixelColor(36, pixels.Color(0, 0, 0));
    }if (LED_38 == 0){
      pixels.setPixelColor(37, pixels.Color(0, 0, 0));
    }if (LED_39 == 0){
      pixels.setPixelColor(38, pixels.Color(0, 0, 0));
    }
    
    if (LED_40 == 1){
      pixels.setPixelColor(39, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_41 == 1){
      pixels.setPixelColor(40, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_42 == 1){
      pixels.setPixelColor(41, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_43 == 1){
      pixels.setPixelColor(42, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_44 == 1){
      pixels.setPixelColor(43, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_45 == 1){
      pixels.setPixelColor(44, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_46 == 1){
      pixels.setPixelColor(45, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_47 == 1){
      pixels.setPixelColor(46, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_48 == 1){
      pixels.setPixelColor(47, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_49 == 1){
      pixels.setPixelColor(48, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_50 == 1){
      pixels.setPixelColor(49, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_51 == 1){
      pixels.setPixelColor(50, pixels.Color(redColor, greenColor, blueColor));
    }if (LED_52 == 1){
      pixels.setPixelColor(51, pixels.Color(redColor, greenColor, blueColor));
    }
    
    if (LED_40 == 0){
      pixels.setPixelColor(39, pixels.Color(0, 0, 0));
    }if (LED_41 == 0){
      pixels.setPixelColor(40, pixels.Color(0, 0, 0));
    }if (LED_42 == 0){
      pixels.setPixelColor(41, pixels.Color(0, 0, 0));
    }if (LED_43 == 0){
      pixels.setPixelColor(42, pixels.Color(0, 0, 0));
    }if (LED_44 == 0){
      pixels.setPixelColor(43, pixels.Color(0, 0, 0));
    }if (LED_45 == 0){
      pixels.setPixelColor(44, pixels.Color(0, 0, 0));
    }if (LED_46 == 0){
      pixels.setPixelColor(45, pixels.Color(0, 0, 0));
    }if (LED_47 == 0){
      pixels.setPixelColor(46, pixels.Color(0, 0, 0));
    }if (LED_48 == 0){
      pixels.setPixelColor(47, pixels.Color(0, 0, 0));
    }if (LED_49 == 0){
      pixels.setPixelColor(48, pixels.Color(0, 0, 0));
    }if (LED_50 == 0){
      pixels.setPixelColor(49, pixels.Color(0, 0, 0));
    }if (LED_51 == 0){
      pixels.setPixelColor(50, pixels.Color(0, 0, 0));
    }if (LED_52 == 0){
      pixels.setPixelColor(51, pixels.Color(0, 0, 0));
    }
    pixels.setPixelColor(52, pixels.Color(redColor, greenColor, blueColor));
    pixels.setPixelColor(53, pixels.Color(redColor, greenColor, blueColor));
    pixels.show();
}