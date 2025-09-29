# 4×4 Speed Bot — UNO R3 + 2× TB6612 + 4× TT

**Goal:** beginner-friendly path for a 14-yo to build a fast 4×4 Arduino robot car, step by step, with tiny wins (Blink → Button→LED → Ultrasonic → Drive 4×4).

**Motto:** *So imperfect we’re perfect. Ship V1. Learn. Perfect.*  
**Idioma:** English with fun ES bits (bilingüe corto).

---

## Hardware (kit mínimo)
- ELEGOO **UNO R3** + USB A-to-B  
- **2× TB6612FNG** motor drivers  
- **4× TT motors** + 65–69 mm wheels + **4WD chassis**  
- **4×AA** battery holder (switch) — motors only  
- Breadboard, jumpers, push-button, 220 Ω resistor  
- (Module 2) **HC-SR04** ultrasonic sensor

> Power: 4×AA → **VM** on both TB6612; UNO by USB; **COMMON GND**.

---

## Folder structure
```
docs/
  student_guide_module_01.md
code/
  step01_blink/step01_blink.ino
  step02_button_led/step02_button_led.ino
images/
  (coming) wiring_button_led.png
```
---

## Quick Start
1. **Install Arduino IDE 2.x** → https://www.arduino.cc/en/software  
2. **Select board/port**: *Arduino Uno* + correct serial port (COMx / `/dev/cu.*`).  
3. Open `code/step01_blink/step01_blink.ino` → **Verify** (✓) → **Upload** (→).  
4. Wire **Button→LED** as in *Module 1* and upload `step02_button_led.ino`.

**Troubleshooting:** no port → try other cable/driver CH34x; LED no enciende → revisar polaridad y resistor; botón siempre ON → usar `INPUT_PULLUP` y la otra pata a GND.

---

## Modules
- **M1 — Install → Blink → Button→LED**  
  ↳ docs/student_guide_module_01.md, code/step01…, code/step02…  
- **M2 — Ultrasonic alert (HC-SR04)** *(next)*  
- **M3 — Wire 2× TB6612 & first 4×4 drive** *(soon)*

---

## Wiring cheat (4×4)
- TB1 (left): `PWMA→D5, AIN1→D7, AIN2→D8; PWMB→D6, BIN1→D9, BIN2→D10; STBY→D4`  
- TB2 (right): `PWMA→D3, AIN1→D12, AIN2→D13; PWMB→D11, BIN1→A0, BIN2→A1`  
- Differential mix: `left=thr+steer`, `right=thr−steer` (0–255)

---

## Contribute (cómo colaborar)
- Open an **Issue** per task (M1/M2/M3…).  
- Create a branch, commit your files inside `code/` or `docs/`, and open a **PR**.  
- Keep images in `/images` (PNG). Avoid PDFs when possible.

---

## License
MIT (friendly for students and schools).

---

*Last updated:* 2025-09-29
