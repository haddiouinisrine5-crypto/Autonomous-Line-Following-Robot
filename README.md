# 🤖 Arduino Line-Following & Obstacle-Avoiding Robot

An autonomous mobile robot built using Arduino, IR line sensors, and an ultrasonic distance sensor that can follow a black line path while detecting and avoiding obstacles in real-time. This project demonstrates embedded systems control, sensor integration, and autonomous navigation — perfect for robotics and AI learning foundations.

---

## 🧠 Features
- Follows a black line using three IR sensors  
- Detects obstacles using HC-SR04 ultrasonic sensor  
- Automatically avoids obstacles and returns to path  
- Uses L298N motor driver for dual DC motor control  
- Simple, efficient logic with smooth motion transitions  

---

## ⚙️ Hardware Components
| Component | Quantity | Description |
|------------|-----------|-------------|
| Arduino Uno | 1 | Main microcontroller board |
| L298N Motor Driver | 1 | Controls motor direction and speed |
| IR Sensors (Line Sensors) | 3 | Detects black/white contrast on path |
| Ultrasonic Sensor (HC-SR04) | 1 | Measures distance to obstacles |
| DC Motors + Wheels | 2 | Robot movement |
| Chassis + Battery Pack | 1 | Base and power |
| Jumper Wires | — | Circuit connections |

---

## 🧩 Circuit Connections

| Component | Arduino Pin |
|------------|--------------|
| Left IR Sensor | A0 |
| Middle IR Sensor | A1 |
| Right IR Sensor | A2 |
| Ultrasonic Trig | 9 |
| Ultrasonic Echo | 8 |
| Motor Driver ENA | 10 |
| Motor Driver IN1 | 2 |
| Motor Driver IN2 | 3 |
| Motor Driver IN3 | 4 |
| Motor Driver IN4 | 5 |
| Motor Driver ENB | 11 |

---

## 🧰 Software Requirements
- Arduino IDE (latest version)
- Arduino Uno or compatible board
- No additional libraries required (uses built-in functions)

---

## 🚀 How It Works
1. The IR sensors detect the line’s position (black vs white surface).
2. The Arduino reads sensor inputs and adjusts the motor speeds to follow the path.
3. The ultrasonic sensor continuously monitors for obstacles.
4. When an obstacle is detected (closer than 15 cm), the robot stops, turns, moves around the obstacle, and returns to the line.

---

## 🧪 Demonstration Logic (Summary)
- If middle sensor = HIGH → move forward  
- If left sensor = HIGH → turn left  
- If right sensor = HIGH → turn right  
- If obstacle detected → stop, avoid, and resume following line  

---

## 🛠️ Future Improvements
- Add PID control for smoother turns  
- Add Bluetooth/Wi-Fi for remote monitoring  
- Integrate 5-sensor array for better precision  
- Add LED or buzzer for obstacle alerts  

---

## 📸 Author
Developed by **Nisrine Haddioui**  
Bachelor’s in Computer Science and Technology — *Changsha University of Science and Technology*  
Passionate about robotics, embedded systems, and AI integration.

---

## 🏁 License
This project is released under the MIT License — feel free to modify and share.
