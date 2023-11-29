const uint8_t alarmStart  = 60;
const uint8_t alarmEnd = 120;

const uint8_t pinAlarm = 0;
const uint8_t pinLED = 1;

uint16_t count;

void setup() {
  pinMode(pinAlarm, OUTPUT);
  digitalWrite(pinAlarm, LOW);

  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, LOW);

  count = 0;
}

void loop() {
  bool ringAlarm = (alarmStart <= count) && (count < alarmEnd);
  digitalWrite(pinAlarm, ringAlarm ? HIGH : LOW);

  bool ledOn = !ringAlarm && !(count & 1);
  digitalWrite(pinLED, ledOn ? HIGH : LOW);
  
  delay(1000);

  count++;
}
