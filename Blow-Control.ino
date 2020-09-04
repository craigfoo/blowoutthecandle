/* Blow Out the Candle Pressure Control
*/

uint8_t pumpPin = D0;
uint8_t solenoidPin = D1;


void blowHard(const char *event, const char *data)
{
    digitalWrite(pumpPin, HIGH);
    delay(8000);
    digitalWrite(pumpPin, LOW);
    delay(1000);
    digitalWrite(solenoidPin, HIGH);
    Particle.publish("purge", String(currentPressure), PRIVATE);
    delay(1000);
    digitalWrite(solenoidPin, LOW);
}


void setup() {

  pinMode(pumpPin, OUTPUT);
  pinMode(solenoidPin, OUTPUT);
  
  Particle.subscribe("blow", blowHard);
}

void loop() {
    // nothing to see here
    delay(250);

}