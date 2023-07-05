//#define SERIAL_ON

int pinSwitch = 6;
int pinAlarm = 2;

#define ALARM_START 20000L
#define ALARM_END 50000L
long timeStart;

void setup() {
#ifdef SERIAL_ON
  Serial.begin(9600);
#endif

  pinMode(pinSwitch, INPUT);

  pinMode(pinAlarm, OUTPUT);
  digitalWrite(pinAlarm, LOW);

  timeStart = millis();
}

void loop() {
  long timeNow = millis();

  int stateSwitch = digitalRead(pinSwitch);
  if (stateSwitch == 0) {
    timeStart = timeNow;
  }
  long timeElapsed = timeNow - timeStart;

#ifdef SERIAL_ON
  Serial.print("Switch: ");
  Serial.print(stateSwitch);
  Serial.print(",\tTime Start: ");
  Serial.print(timeStart);
  Serial.print(",\tTime Now: ");
  Serial.print(timeNow);
  Serial.print(",\tTime Elapsed: ");
  Serial.print(timeElapsed);
  Serial.println();
#endif

  int alarmOn = (ALARM_START < timeElapsed) && (timeElapsed < ALARM_END);
  digitalWrite(pinAlarm, alarmOn ? HIGH : LOW);

  delay(100);
}