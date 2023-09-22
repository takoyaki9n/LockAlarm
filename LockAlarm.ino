const uint8_t alarmStart  = 60;
const uint8_t alarmDuration = 60;
const uint8_t alarmEnd = alarmStart + alarmDuration;

const uint8_t pinAlarm = 0;
const uint8_t pinLED = 1;

int count;

void setup() {
  pinMode(pinAlarm, OUTPUT);
  digitalWrite(pinAlarm, LOW);

  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, LOW);

  count = 0;
}

void loop() {
  int ringAlarm = alarmStart <= count && count < alarmEnd;
  digitalWrite(pinAlarm, ringAlarm ? HIGH : LOW);

  digitalWrite(pinLED, HIGH);
  delay(100);
  digitalWrite(pinLED, LOW);
  delay(900);

  count++;
}
