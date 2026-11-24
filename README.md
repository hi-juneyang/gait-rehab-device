# Wearable Gait Rehabilitation Device 
### Development of an ESP32-based wearable device for real-time arm swing monitoring and rehabilitation feedback
This project explores the development of a wearable rehabilitation device that monitors arm swing during walking using an inertial measurement unit (IMU) and provides real-time auditory feedback to encourage consistent gait patterns.

The project involves embedded systems programming, sensor integration, signal processing, electronic hardware development, and mechanical design.

## Project Motivation
Arm swing plays an important role in maintaining balance, coordination, and walking efficiency. Individuals recovering from neurological or musculoskeletal injuries may experience reduced or asymmetric arm swing during walking.

The objective of this project is to develop an accessible, portable rehabilitation device that allows users to monitor their arm movement and receive feedback based on adjustable rehabilitation targets.

This project was inspired by my personal experience with gait rehabilitation. It also reflects my interest in interdisciplinary engineering, particularly mechatronics — bringing mechanical, electrical, and software systems together to develop a functional product.

## Design Objectives
- Measure arm acceleration and angular velocity during walking.
- Identify arm swing cycles, frequency, and movement patterns.
- Provide real-time auditory feedback based on detected movement.
- Allow users to adjust target arm swing frequency according to their walking speed and rehabilitation progress.
- Establish Bluetooth communication for wireless data transmission and device configuration.
- Develop a compact, battery-powered wearable device with an integrated enclosure.

## Hardware & Development Environment
- Hardware: ESP32, MPU6050
- Programming environment: C++ in Arduino framework

## Project Status 
- Established I2C communication successfully between ESP32 and MPU6050.
- Developed and tested embedded firmware for acceleration and angular velocity measurements.
- Implemented button-controlled initiation and termination of data acquisition.
