int segPins[] = {13, 12, 11, 10, 9, 8, 7};  // a, b, c, d, e, f, g


int digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

void setup() {
  for (int i=0; i<7; i++) {
    pinMode(segPins[i], OUTPUT);
  }
}

void displayDigit(int num) {
  for (int i=0; i<7; i++) {
    digitalWrite(segPins[i], digits[num][i]);
  }
}

void loop() {
  for (int i=0; i<10; i++) { 
    displayDigit(i);
    delay(600);
  }
}
