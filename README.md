# ☀️ Solar Tracker Prototype with Collapsible Housing Unit

## 🌍 Problem Statement
Solar energy systems often suffer from efficiency losses due to two major challenges:

🔴 **Fixed-Angle Limitation:** Traditional solar panels remain static, preventing them from optimizing sunlight capture throughout the day.

🔴 **Environmental Wear & Dust Accumulation:** Prolonged exposure to dust and harsh weather leads to reduced efficiency and increased maintenance costs.

### 🌟 The Solution
This project introduces a **smart solar tracker with a collapsible housing unit**, designed to:

✅ **Maximize energy absorption** through dynamic sun tracking.
✅ **Protect panels from environmental wear** by automatically closing at night.
✅ **Reduce maintenance costs** by minimizing dust accumulation and exposure.

This innovative system enhances solar energy efficiency, reliability, and cost-effectiveness—especially for dust-prone and extreme weather regions.

---

## 🔬 Project Goals & Features
### 🎯 Primary Objectives:
- **Enhance energy efficiency** by implementing real-time solar tracking.
- **Minimize maintenance costs** through automated protection.
- **Extend the lifespan of solar panels** by shielding them from environmental degradation.

### ⚙️ Key Features:
✅ **Dual-Axis Solar Tracking** for continuous sun alignment.
✅ **Solar Positioning Algorithm (SPA)** eliminates the need for light sensors.
✅ **Automated Collapsible Housing System** that opens at sunrise and closes at sunset.
✅ **Book-Like Motion** for smooth housing unit operation.

---

## 🔧 Components Used
### 🛠️ Hardware
- **Arduino Mega 2560** – Microcontroller for system operation.
- **Ublox NeoM GPS Module** – Captures real-time longitude, latitude, and time data.
- **Bluetooth Module** – Enables real-time data logging.
- **SC16A Servo Controller** – Dedicated motor control unit.
- **Servo Motors** – Drive the solar tracking and foldable housing system.
- **Power Bank & Battery Unit** – Independent power sources for components.

### 💾 Software
- **SolidWorks** – CAD modeling for design and structural analysis.
- **Arduino IDE & C++** – Programming and automation logic.
- **Supporting Libraries:**
  - **Sunposition.h** – Calculates solar positioning.
  - **TinyGPSPlus.h** – Extracts GPS data.
  - **Unixtime.h** – Converts GPS timestamps to standard format.
  - **Servo.h** – Controls servo motors for precise movement.

---

## 📊 Working Principle & Experimental Setup
### 🔆 **Solar Tracker**
📡 **GPS Signal Lock:** The system waits for GPS synchronization before gathering position and time data.
🕒 **Time & Position Verification:** Ensures data validity before computing solar positioning.
☀️ **Real-Time Sun Tracking:** The foldable housing opens, and servo motors adjust the panel alignment dynamically.
📱 **User Interface:** Displays sun and tracker position updates on a mobile device.
🌙 **Automated Reset:** System resets at night and recalibrates at sunrise.

### 🌫️ **Dust Testing**
🏗️ **Dual Housing Units:** Solar panels are mounted in two housing units (foldable vs. static) for efficiency comparison.
🌪️ **Controlled Dust Exposure:** Panels are placed in a dust-prone environment for uniform accumulation.
📏 **Comparative Efficiency Testing:** Performance data is recorded over several days to assess the impact of dust accumulation.

---

## 🚀 Results
📈 **Solar energy output increased by 24.27%** due to dynamic sun tracking.
📉 **Efficiency improved by 6.4%** by reducing dust accumulation over a 5-day period (tested under 8 lighting conditions).
💰 **Reduced maintenance costs & enhanced power savings**, ensuring long-term sustainability.

---

## 📂 Explore the Project
💻 **Check out the full project on GitHub:** [Solar Tracker Prototype Repository](https://github.com/STBreeze/Solar-Tracker-Prototype_Bachelors-Thesis)

---

## 📜 Research Recognition
This project was submitted as a **Bachelor's Thesis** and has been officially recognized by **ASME (American Society of Mechanical Engineers)**. A confirmation of submission is available in the repository.

