int pinAlarm = 10;
int pinLED = 9;

#define ALARM_START 20
#define ALARM_END 40

int count;

void setup() {
  pinMode(pinAlarm, OUTPUT);
  digitalWrite(pinAlarm, LOW);

  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, LOW);

  count = 0;
}

void loop() {
  int ringAlarm = ALARM_START <= count && count < ALARM_END;
  digitalWrite(pinAlarm, ringAlarm ? HIGH : LOW);

  digitalWrite(pinLED, HIGH);
  delay(100);
  digitalWrite(pinLED, LOW);
  delay(900);

  count++;
}