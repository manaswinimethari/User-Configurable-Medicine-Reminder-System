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

The **User-Configurable Medicine Reminder System** is an embedded system developed using the **LPC2148 ARM7 microcontroller** to help users take their medicines on time. Unlike conventional fixed reminder systems, this project allows users to dynamically configure medicine schedules using a **4×4 Matrix Keypad**, making it flexible and user-friendly.

The system continuously monitors the **Real-Time Clock (RTC)** and compares the current time with the stored medicine schedules. When a scheduled time is reached, it alerts the user by displaying a reminder message on the **16×2 LCD** and activating a **buzzer**. The reminder can be acknowledged using a dedicated switch, after which the system returns to normal monitoring mode.

The project demonstrates the integration of **RTC, LCD, Matrix Keypad, External Interrupts (EINT0 & EINT1), and Buzzer Control** using **Embedded C**, making it a practical application of real-time embedded system design for healthcare assistance.
