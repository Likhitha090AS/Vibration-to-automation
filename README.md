# Automatic Railway Gate Control System (LoRa Based)

## 📌 Project Overview
This project presents a **fully automated railway level crossing gate system** that ensures public safety by eliminating the need for human intervention. The system leverages **vibration sensors, weight sensors, and LoRa communication** to detect approaching trains in real-time, control the gate mechanism, and alert nearby pedestrians and vehicles.

---

## 🎯 Objectives
- Automate the **closure and opening** of railway gates using vibration and weight sensors.  
- Enhance **safety** at railway level crossings, particularly in rural and semi-urban areas.  
- Minimize accidents caused by **human error** in manual gate operations.  
- Provide a **low-cost, scalable, and robust** solution using **LoRa communication** for long-distance data transfer.  

---

## 🛠️ System Components
1. **Vibration Sensor (MPU-9250)**  
   - Installed a few kilometers from the crossing.  
   - Detects train-induced vibrations above a threshold frequency (≥1.7 Hz).  

2. **Weight Sensor**  
   - Placed at the crossing to confirm the train’s presence.  
   - Detects absence of weight for 30 seconds to confirm departure.  

3. **Microcontroller (Arduino UNO / Similar)**  
   - Processes sensor data and manages control logic.  
   - Controls servo motor and alert mechanisms.  

4. **Servo Motor**  
   - Operates the gate (opens/closes) as per microcontroller instructions.  

5. **LoRa Module**  
   - Enables **long-range communication** between sensors and the controller unit.  
   - Ensures real-time updates even when sensors are placed kilometers away.  

6. **Alert Mechanisms**  
   - **Buzzer**: Audible warning for approaching trains.  
   - **LCD Display**: Visual messages like *“Train Arriving”* and *“Train Passed.”*  

---

## ⚙️ Operational Workflow
1. Train approaches → vibration sensor detects vibrations.  
2. LoRa module sends detection signal to the controller.  
3. Controller activates **servo motor**, closing the gate.  
4. **Buzzer + LCD** notify the public of the train’s arrival.  
5. Weight sensor confirms train presence.  
6. After departure (no weight detected for 30s), controller reopens the gate.  
7. Alerts are deactivated, and LCD shows *“Train Passed.”*  

---

## ✅ Advantages
- **Fully automatic** – no manual intervention required.  
- **LoRa-enabled** – long-range, reliable, and real-time communication.  
- **Cost-effective** – affordable and suitable for rural regions.  
- **Safety-focused** – reduces fatal accidents at unmanned crossings.  
- **Scalable** – can be deployed across multiple crossings.  
- **Energy-efficient** – supports solar power integration.  

---

## 📂 Deliverables
- Research Paper / Documentation  
- Project PPT (Canva)  
- Arduino-based working prototype  
- Source Code for microcontroller and LoRa integration  

---

## 👥 Team Members
- [Name 1] – Hardware & Sensor Integration  
- [Name 2] – LoRa Communication & Networking  
- [Name 3] – Microcontroller Programming  
- [Name 4] – Presentation & Documentation  

---

## 🔧 Tools & Technologies
- Arduino UNO / ESP32  
- MPU-9250 (Vibration Sensor)  
- Load Cell / Weight Sensor  
- LoRa Transceiver Module  
- Servo Motor  
- LCD Display & Buzzer  

---

## 🚀 Conclusion
This project introduces a **LoRa-enabled smart railway gate control system** that improves safety, efficiency, and reliability at railway crossings. By combining vibration detection, weight sensing, and real-time communication, it eliminates human errors and reduces accidents in underserved regions.
