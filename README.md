# COvid-Patients-Enhanced-MONitoring-(COPEMON)-Hardware-System
COPEMON is a hardware project built on a STM32L475 ARM Cortex-M4 System as part of the NUS module EE2028, aimed at monitoring a COVID patient's health through collecting data through a series of sensors, and transmitting the readings onto a terminal, and sending warnings when the readings suggest an anomaly

Think of COPEMON as a wearable IoT device, such as an Apple Watch, except that it is equipped with certain sensors that the Apple Watch doesn't have. This wearable device is to be worn by a COVID patient, such that caretakers or medical teams are able to remotely monitor the condition of said patient, and be alerted to abnormal readings which suggest the patient is in need of follow-up attention.

## Features

The following 5 sensor modules: Temperature, Pressure, Humidity, Accelerometer, Gyroscope, Magnetometer are used in the following ways to monitor the COVID patient

- Temperature Sensor in Fever Detection 
- Breathing Monitor to detect Abnormal Breathing Patterns
  - Pressure Sensor
  - Humidity Sensor
- Fall Detection 
  - Accelerometer 
  - Gyroscope
  - Magnetometer

The respective thresholds configured for the sensors are configured as follows:

![flowchart](/flowchart_trigger.png)

