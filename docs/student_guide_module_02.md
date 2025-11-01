# M2 — HC-SR04 Alert

Goal: Use the HC-SR04 ultrasonic sensor to measure distance. If something gets closer than 20 cm, turn on the LED and beep the buzzer.

## Parts
- Arduino UNO R3 + USB A-B
- HC-SR04 ultrasonic sensor
- 1x LED + 220 ohm resistor
- Piezo buzzer (active) — optional
- Jumper wires

## Wiring
See `images/wiring_hcsr04.png`.

- VCC -> 5V
- GND -> GND
- TRIG -> D9
- ECHO -> D10
- LED anode -> D3 through 220 ohm, LED cathode -> GND
- Buzzer + -> D4, Buzzer - -> GND (optional)

**Common GND**: the sensor and UNO must share ground.

## Code
Open `code/step03_ultrasonic/step03_ultrasonic.ino`.

## Test
1. Open Serial Monitor at 9600.
2. Move your hand toward the sensor.
3. Under 20 cm the LED turns ON and the buzzer beeps.

## Safety
Do not point the sensor into spinning wheels. Keep wires away from motors.
