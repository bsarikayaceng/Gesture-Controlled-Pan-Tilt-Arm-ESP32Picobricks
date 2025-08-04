# Gesture-Controlled Pan-Tilt Arm

## 🦾 Overview

Robot arms have replaced human labor in many areas of the industrial sector. These systems are capable of carrying and rotating heavy or large loads that humans would struggle to manipulate. Their ability to be positioned with precision up to one-thousandth of a millimeter exceeds the precision achievable by human hands.

If you've ever watched manufacturing footage from automotive factories, you've likely seen robot arms in action. They are referred to as “robots” because they can repeat programmed tasks indefinitely, and “arms” because their structure resembles that of a human arm. The number of axes in which a robot arm can rotate and move determines its degrees of freedom.

Robot arms are also used for sculpting and shaping materials like aluminum through CNC routers. These advanced 7-axis machines can carve metal much like a sculptor molds clay.

Depending on the application, robot arms may use stepper motors or servo motors. In this project, you will use **servo motors** controlled via **PicoBricks** to simulate a simplified robot arm (pan-tilt mechanism).

---

## 🤖 Project 2.15: Gesture Controlled Pan-Tilt Arm

### 🔍 Project Description & Algorithm

In this project, we utilize the **gesture detection** feature of the **APDS9960 sensor** on the PicoBricks board. The gesture sensor will detect hand movements in the following directions:

- **Up / Down**
- **Left / Right**

According to the direction of the gesture:
- Servo 1 (horizontal axis) will rotate left or right.
- Servo 2 (vertical axis) will rotate up or down.

Additionally, pressing a button connected to GPIO2 will **reset both servos** to their default center positions (90°), effectively centering the pan-tilt arm.

---

### 🧩 Wiring & Hardware Setup

One of the advantages of PicoBricks is that it allows you to run and test modules directly on the board **without external wiring**. However, if you detach the modules from the board and use them independently, be sure to connect them using **Grove cables**.

- **Gesture Sensor**: I2C connection (SCL → GPIO22, SDA → GPIO21)
- **Button Module**: Connected to **GPIO2**
- **Servo 1 & Servo 2**: Controlled through I2C-based motor driver module

---

## 💾 Installation

1. Open `Gesture_Controlled_Servos.ino` in Arduino IDE.
2. Select ESP32 PicoBricks board and correct port.
3. Upload the code to your device.
4. Open Serial Monitor to view gesture outputs.

---

## 📁 Files

- `Gesture_Controlled_Servos.ino` – Main Arduino source file
- `README.md` – This project documentation
- `LICENSE` – MIT License
- `.gitignore` – Git exclusions for Arduino

---

## 📜 License

This project is licensed under the MIT License.