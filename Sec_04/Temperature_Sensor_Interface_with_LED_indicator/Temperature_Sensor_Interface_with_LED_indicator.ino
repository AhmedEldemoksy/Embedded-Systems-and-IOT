float temp;

void setup() {

pinMode (13, OUTPUT);

Serial.begin (9600);

}

void loop() {

temp= analogRead (A0);

temp= (temp*500)/1024;

Serial.println (temp);

if (temp>30)

digitalWrite (13, HIGH);

else

digitalWrite (13, LOW);

delay (1000);

}
