//1- led every sec

// int leds[] = {2, 3, 4};
// int ledCount = 3;

// void setup() {
//   for (int i = 0; i < ledCount; i++) {
//     pinMode(leds[i], OUTPUT);
//   }
// }

// void loop() {

//   for (int i = 0; i < ledCount; i++) {
//     digitalWrite(leds[i], HIGH);
//     delay(300);
//     digitalWrite(leds[i], LOW);
//   }

// }

//2- Task make diff time for every led

// int leds[] = {2, 3, 4};       
// int ledCount = 3;              


// int ledTime[] = {10000, 4000, 20000};

// void setup() {
//   for (int i = 0; i < ledCount; i++) {
//     pinMode(leds[i], OUTPUT);
//   }
// }

// void loop() {
//   for (int i = 0; i < ledCount; i++) {
//     digitalWrite(leds[i], HIGH);     
//     delay(ledTime[i]);             
//     digitalWrite(leds[i], LOW);  
//     delay(500);                  
//   }
// }


// 3- leds with counter
int leds[] = {2, 3, 4};
int durations[] = {10, 4, 20};
int ledCount = 3;

void setup() {
  Serial.begin(9600); 
  for (int i = 0; i < ledCount; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], HIGH);
    for (int t = durations[i]; t > 0; t--) {
      Serial.print("LED No ");
      Serial.print(i + 1);
      Serial.print(":");
      Serial.print(t);
      Serial.println(" sec");
      delay(1000);
    }
    digitalWrite(leds[i], LOW);
  }
}
