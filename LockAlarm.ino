int pinAlarm = 2;
int pinLED = 9;

#define ALARM_START 20
#define ALARM_LEN 20

int ringAlarm = 1;

void setup() {
  pinMode(pinAlarm, OUTPUT);
  digitalWrite(pinAlarm, LOW);

  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, LOW);
}

void blink(int times) {
  for (int i = 0; i < times; i++) {
    delay(900);
    digitalWrite(pinLED, HIGH);
    delay(100);
    digitalWrite(pinLED, LOW);
  }
}

void loop() {
  blink(ALARM_START);

  if (ringAlarm) {
    digitalWrite(pinAlarm, HIGH);
  }

  blink(ALARM_LEN);
  digitalWrite(pinAlarm, LOW);

  ringAlarm = 0;
}