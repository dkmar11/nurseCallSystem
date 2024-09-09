# Legacy Embedded System Control Project

This project is an example of an old embedded systems program written in C, dating back to around 2010. The purpose of this project was to demonstrate basic skills in embedded systems programming, including I2C and SPI communication protocols, interfacing with peripherals such as LEDs and a real-time clock (RTC), as well as basic file handling using FAT32.

**Please note**: This project is no longer maintained and is shared here strictly for the purpose of showcasing my skills in C and embedded systems programming from that time period.

## Project Overview

This project was designed to create a **nurse call system** for patient rooms in a healthcare facility. The system allows patients to signal for assistance by pressing a button, which lights up an LED corresponding to their room, and logs the call event for tracking purposes.

### Project Features
- **LED Management**: Control of multiple LEDs via a PCA module using I2C, each LED representing a patient room.
- **RTC Integration**: A real-time clock (RTC) module is used to record the exact time when a call is made.
- **Event Logging**: Call events are written to a log file on an MMC card using FAT32, allowing staff to review calls historically.

### How It Works

1. **PCA Module Control:**
   - The PCA module is used to control LEDs that represent different rooms. When a patient presses the call button, the corresponding LED lights up.
   - The functions `PCAon()` and `PCAoff()` handle turning LEDs on and off based on input signals from the rooms.

2. **RTC Module:**
   - The real-time clock (RTC) is initialized and configured via I2C to keep track of the current date and time.
   - When a call is made, the current timestamp is recorded using the `RTC_date_W()` function.

3. **File Writing with FAT32:**
   - Each call event is logged with its corresponding time in a text file on an MMC card using the SPI protocol.
   - The function `Fat_send()` appends the room number and timestamp to the log file.

## Requirements

- Microcontroller with I2C and SPI capabilities.
- PCA module for LED control.
- Real-time clock (RTC) module.
- MMC card for data logging.
- C compiler and programming environment compatible with the microcontroller used.

## Compilation & Flashing

This project was developed in 2010 using legacy tools, and no modern build process is guaranteed. You will need to adapt it to your current microcontroller programming setup. Ensure that your microcontroller supports I2C and SPI and that you configure the pins accordingly.

## Disclaimer

This project is a legacy example and is not intended for production use. It is only shared to demonstrate C programming skills in embedded systems from the early 2010s.
