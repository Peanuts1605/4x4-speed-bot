# M3 — Drive 4x4 with dual TB6612

Goal: Drive a 4WD chassis with two TB6612 motor drivers (left and right sides). Use PWM to control speed and keep STBY HIGH.

## Parts
- Arduino UNO R3
- 4WD chassis with 4x TT motors (wired as Left pair + Right pair)
- 2x TB6612FNG motor drivers
- 4xAA battery holder (with switch) for VM (motors)
- Jumper wires + common GND

## Power
- Motors (VM): 4xAA -> TB6612 VM
- UNO by USB/5V
- Common GND: AA- to both TB6612 GND and UNO GND

## Wiring (per board)
See `images/wiring_4x4.png`.

**Pin plan (classic layout):**
- STBY -> D8
- Left board: AIN1 -> D5, AIN2 -> D6, PWMA -> D3
- Right board: BIN1 -> D10, BIN2 -> D11, PWMB -> D9
- Motor outputs to each side's motors in parallel

## Code
Open `code/step04_drive_4x4/step04_drive_4x4.ino`.

## Safety
Lift wheels on first test. Ramp PWM to avoid stalls. Keep cables clear of gears.
