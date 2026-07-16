# 💊User-Configurable Medicine Reminder System
<p align="center">

![Embedded System](https://img.shields.io/badge/EMBEDDED%20SYSTEM-555555?style=for-the-badge&logoColor=white)
![LPC2148](https://img.shields.io/badge/LPC2148-2196F3?style=for-the-badge)

![Language](https://img.shields.io/badge/LANGUAGE-555555?style=for-the-badge)
![Embedded C](https://img.shields.io/badge/EMBEDDED%20C-4CAF50?style=for-the-badge)

![RTC](https://img.shields.io/badge/RTC-555555?style=for-the-badge)
![Real Time Clock](https://img.shields.io/badge/REAL%20TIME%20CLOCK-FF9800?style=for-the-badge)

![Interface](https://img.shields.io/badge/INTERFACE-555555?style=for-the-badge)
![4x4 Keypad](https://img.shields.io/badge/4x4%20KEYPAD-E53935?style=for-the-badge)

![Interrupts](https://img.shields.io/badge/INTERRUPTS-555555?style=for-the-badge)
![EINT0 | EINT1](https://img.shields.io/badge/EINT0%20%7C%20EINT1-9C27B0?style=for-the-badge)

![Status](https://img.shields.io/badge/STATUS-555555?style=for-the-badge)
![Completed](https://img.shields.io/badge/COMPLETED-4CAF50?style=for-the-badge)

</p>
User Configurable Medicine Reminder System is a customizable application that helps users manage medication schedules with personalized reminders. It supports configurable dosage timings, notifications, medication tracking, and schedule management, improving adherence while providing a scalable foundation for healthcare and wellness applications.

# 🌐Overview

The **User-Configurable Medicine Reminder System** is a smart embedded application developed using the **LPC2148 ARM7 microcontroller** to help users manage their medication schedules efficiently. It allows users to set and modify medicine timings through a **4×4 Matrix Keypad**, making the system flexible and easy to use.

The system continuously monitors the **Real-Time Clock (RTC)** and compares the current time with the stored medicine schedules. When a scheduled time is reached, it displays a reminder on the **16×2 LCD** and activates a **buzzer** to notify the user. The alert can be acknowledged using a dedicated switch.

Developed using **Embedded C**, this project integrates RTC, LCD, keypad, external interrupts, and buzzer control into a single real-time embedded application. It provides a reliable, user-friendly, and practical solution for improving medication adherence.

- 💊 Personalized medicine reminders.
- ⚙️ Built with LPC2148 ARM7 & Embedded C.
- ⏰ Accurate RTC monitoring with buzzer alerts.
  
# 🎯Objective

- ⏰ Display the current date and time using the Real-Time Clock (RTC).
- 💊 Allow users to configure personalized medicine schedules.
- ⌨️ Accept user input through a 4×4 Matrix Keypad.
- 🕒 Continuously monitor the RTC for scheduled medicine timings.
- 🔔 Generate buzzer alerts when a medicine time is reached.
- 📺 Display reminder notifications on the 16×2 LCD.
- ✅ Allow users to acknowledge reminders using an external interrupt switch.
- 🔄 Support multiple medicine schedules with real-time monitoring.
- ⚙️ Integrate RTC, LCD, keypad, buzzer, and interrupts into a single embedded system.
- ❤️ Provide a reliable and user-friendly solution to improve medication adherence.

# ✨Key Features

- 💊 User-configurable medicine schedules
- ⏰ RTC-based real-time monitoring
- ⌨️ 4×4 Matrix Keypad for easy input
- 📺 16×2 LCD for date, time, and reminders
- 🔔 Buzzer alerts for medicine notifications
- ⚡ External Interrupts (EINT0 & EINT1) for quick user interaction
- 🔄 Continuous monitoring of medicine timings
- 🛠️ Developed using Embedded C on LPC2148 ARM7

# ⚙️Complete System architecture 

![image alt](https://github.com/manaswinimethari/User-Configurable-Medicine-Reminder-System/blob/2eddd3ac8a8940a4a3ad678e206579052dac54b8/Project%20Gallery/IMG-20260716-WA0001.jpg)

# 🔌Hardware Component

| Component | Purpose |
|----------|---------|
| **LPC2148 ARM7** | Controls the entire system and manages all peripherals. |
| **DS1307 RTC Module** | Maintains accurate date and time for reminders. |
| **16×2 LCD Display** | Shows the current time, menu options, and reminder messages. |
| **4×4 Matrix Keypad** | Allows users to configure time and medicine schedules. |
| **Switch-1 (EINT0)** | Enters setup mode for RTC and medicine configuration. |
| **Switch-2 (EINT1)** | Acknowledges the reminder and stops the buzzer. |
| **5V Active Buzzer** | Produces an audible alert at the scheduled medicine time. |
| **5V Power Supply** | Provides regulated power to the complete system. |

# hardware setup

![image alt](https://github.com/manaswinimethari/User-Configurable-Medicine-Reminder-System/blob/413f2788f8db74bb35bac2817afc38b91274fbc3/Project%20Gallery/file_00000000d5247208a7bbcf86418c9a11.png)

# block diagram 

![image alt](
