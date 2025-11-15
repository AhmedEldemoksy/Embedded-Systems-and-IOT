// تعريف الأرجل
int buttonPin = 4;     // رجل الزر
int ledPin = 13;        // رجل الليد

// متغير لتخزين حالة الزر
int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);   // تعريف الزر كمدخل
  pinMode(ledPin, OUTPUT);     // تعريف الليد كمخرج
}

void loop() {
  // قراءة حالة الزر
  buttonState = digitalRead(buttonPin);

  // لو الزر مضغوط
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);  // شغل الليد
  } else {
    digitalWrite(ledPin, LOW);   // طفي الليد
  }
}
