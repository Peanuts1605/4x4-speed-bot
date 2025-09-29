// step02_button_led.ino — Button → LED (using INPUT_PULLUP)
// Wiring:
//  Button: one leg to D2, the other to GND
//  LED: anode (+) to D9, cathode (−) to GND through 220Ω resistor

const int PIN_BTN = 2;   // uses internal pull-up
const int PIN_LED = 9;   // PWM capable

void setup() {
  pinMode(PIN_BTN, INPUT_PULLUP); // HIGH = released, LOW = pressed
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  bool pressed = (digitalRead(PIN_BTN) == LOW);
  digitalWrite(PIN_LED, pressed ? HIGH : LOW);
}
