// Led: enciende un LED externo conectado al pin 2 (con resistencia en serie).
const int LED_PIN = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);  // LED encendido
}

void loop() {
}
