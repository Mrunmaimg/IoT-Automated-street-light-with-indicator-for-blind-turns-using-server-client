IoT-Automated Street Light with Indicator for Blind Turns

Overview

This project implements an IoT-based automated street lighting system that enhances road safety and energy efficiency. It uses infrared (IR) sensors to detect vehicles and pedestrians, dynamically adjusting street light brightness and activating indicators at blind turns to alert drivers of potential hazards.

Features

- Automated Street Lighting: IR sensors detect movement and adjust street light brightness to conserve energy.
- Blind Turn Indicators: IR sensors at blind turns activate indicators to warn drivers of oncoming traffic.
- Server-Client Architecture: Central server manages data and sends control signals to street lights and indicators.
- Real-time Operation: Ensures timely response to sensor inputs for optimal performance and safety.

Components

- IR Sensors: Detect vehicles and pedestrians.
- ESP8266 NodeMCU: Serves as both the server and client device for processing sensor data and controlling street lights and indicators.
- LED Street Lights: Adjust brightness based on sensor inputs.
- Blind Turn Indicators: Alert drivers of potential hazards at blind turns.
- Server: Manages data and control signals.
- Client Devices: Street lights and indicators that respond to server commands.

How It Works

1. Detection: IR sensors detect the presence of vehicles and pedestrians.
2. Signal Processing: ESP8266 NodeMCU processes the data from IR sensors.
3. Lighting Control: Street lights adjust brightness based on the detected movement.
4. Indicator Activation: Blind turn indicators are activated when IR sensors detect approaching vehicles.
5. Server-Client Communication: The ESP8266 NodeMCU server collects data and sends control commands to the client devices for real-time adjustments.

Installation

1. Hardware Setup:
   - Install IR sensors at appropriate locations.
   - Connect IR sensors, ESP8266 NodeMCU, and LED street lights as per the circuit diagram.
   - Set up blind turn indicators with IR sensors.

2. Software Setup:
   - Flash the ESP8266 NodeMCU with the provided firmware.
   - Configure the server software on the ESP8266 NodeMCU to manage data and control signals.

3. Network Configuration:
   - Ensure all devices are connected to the network for seamless server-client communication.

Usage

1. Power On: Turn on the system and ensure all components are functioning.
2. Monitoring: The server monitors sensor data and adjusts street lights and indicators in real-time.
3. Maintenance: Regularly check sensor calibration and connectivity.

Contributing

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new Pull Request.
