# Smart-Remote-Controlling-Electrical-Appliances-Using-IOT

# Smart Remote Controlling Electrical Appliances Using IoT

This project enables smart and remote control of electrical appliances (like lights, fans, etc.) using IoT (Internet of Things) technology. It allows users to turn ON/OFF devices wirelessly through a mobile or web-based interface, improving convenience, safety, and energy efficiency.

---

## Technologies Used

- **Hardware**: NodeMCU (ESP8266) / Arduino, 4-Channel Relay Module, Electrical Bulbs, Jumper Wires
- **Software**: Arduino IDE / Embedded C
- **Communication**: Wi-Fi (via Blynk or local server)
- **Power**: 5V for Relay and USB for NodeMCU

---

##  Features

- Remote ON/OFF control of appliances
- Real-time wireless operation
- Multi-device control from mobile/web app
- Compact and energy-efficient design
- Can be upgraded for automation and voice control

---

##  Relay Module Pinout

![Relay Module Pinout](images/relay_pinout.png)

- Each relay supports Normally Open (NO), Normally Closed (NC), and Common terminals.
- Controlled via IN1, IN2, IN3, IN4 from NodeMCU digital pins.

---

## 📸 Hardware Setup (Prototype Images)

### Initial Setup (with bulbs & relay):
![Prototype Setup 1](images/prototype_setup_1.png)

### Final Working Model (All bulbs ON):
![Prototype Setup 2](images/prototype_setup_2.png)

---

##  Getting Started

### 🔧 Steps:

1. Connect relay module to NodeMCU as:
   - IN1 to D1  
   - IN2 to D2  
   - IN3 to D3  
   - IN4 to D4  
   - GND to GND  
   - VCC to 3V

2. Connect appliance terminals to Relay Common & NO.

3. Upload the code to NodeMCU using Arduino IDE.

4. Use a web/mobile interface  to control each relay.

---


