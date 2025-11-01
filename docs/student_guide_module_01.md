# Module 1 — Hello Arduino (Install → Blink → Button→LED)
**Project:** 4×4 Speed Bot (UNO R3 + 2× TB6612 + 4× TT)  
**Student:** beginner (14yo) • **Language:** English with fun ES bits  
**Date:** 2025-09-29

> Goal: get the IDE installed, make the board blink, then control an external LED with a push‑button. Small wins, zero drama.

---

## 0) What you need on the table
- ELEGOO **UNO R3** + **USB A‑to‑B** cable  
- Small breadboard, 1 × push‑button, 1 × 220Ω resistor (red‑red‑brown), a few Dupont jumpers  
- Optional: LED (5 mm, any color)

---

## 1) Install Arduino IDE (macOS / Windows)
**Download:** https://www.arduino.cc/en/software (IDE 2.x)

**macOS**
1. Open the `.dmg` and drag **Arduino IDE** to **Applications**.  
2. First run: right‑click → **Open** (macOS security).  
3. If the UNO doesn’t show a serial **Port** later, install the **CH34x** driver (Elegoo uses it). After install: **Restart** → **System Settings → Privacy & Security** → “Allow” if prompted.

**Windows**
1. Run the installer (**Arduino IDE 2.x**).  
2. Allow USB driver install when prompted.  
3. If no COM port later, install **CH340/CH341** driver (Elegoo provides it).

> ES: Si no ves el puerto, calma—cable malo o falta driver. Revisa *Security* en macOS o *Device Manager* en Windows.

---

## 2) Connect & select the board
1. Plug the UNO with the **USB A‑B**. The green **ON** LED should light.  
2. In Arduino IDE: **Tools → Board → Arduino AVR Boards → Arduino Uno**.  
3. **Tools → Port**:  
   - **macOS:** `/dev/cu.usbmodem…` (o `/dev/cu.wchusbserial…` si usa CH340)  
   - **Windows:** `COMx` (x = número)  
4. **Tools → Get Board Info** to confirm.

---

## 3) Blink (your first upload)
Create a new sketch: **File → New**, paste the code from `code/step01_blink/step01_blink.ino` (below), then click **Verify** (✓) and **Upload** (→).  
LED `L` near pin **13** should blink.

Why it matters → You just proved the toolchain: driver + board + compiler + USB.

---

## 4) Button → LED (INPUT_PULLUP)
Now we control an external LED with a push‑button.

### Wiring (text table)
| Part | UNO Pin | Notes |
|---|---|---|
| **Button leg A** | **D2** | Digital input (uses `INPUT_PULLUP`) |
| **Button leg B** | **GND** | |
| **LED anode (+)** | **D9** | Any PWM pin 3/5/6/9/10/11 works |
| **LED cathode (−)** | **220Ω → GND** | Resistor in series to limit current |

> Tip: the button has **2 pairs** of legs connected internally. Make sure A and B are on **opposite sides**.

### Upload
Open `code/step02_button_led/step02_button_led.ino`, **Verify** and **Upload**.  
- Press = LED ON; release = LED OFF (because we use `INPUT_PULLUP`).  
- If it’s inverted, swap the logic in code (or the pins).

Why it matters → You learned `INPUT_PULLUP` (internal pull‑up), de‑bounced enough for now, and controlled an output from an input—base de todo.

---

## 5) Troubleshooting rápido
- **No Port / Upload error** → try other USB port/cable, install CH340, restart IDE, select the right **Board/Port**.  
- **LED never turns on** → check resistor orientation (series with LED to GND), check LED polarity (long leg = +).  
- **Button always ON** → pin must be **D2** with `INPUT_PULLUP` and the **other leg to GND**.

---

## 6) What’s next (Module 2 preview)
- **HC‑SR04 alert** (distance on Serial + beep/LED < 25 cm).  
- Then we’ll wire **2× TB6612** and test the **4×4 drive** with a simple differential mix.

> Motto: **So imperfect we’re perfect.** Ship V1. Learn. Perfect. ¡Listo, piloto!
