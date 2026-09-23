# 🖥️ Computer Graphics Sessional (CSE-4206)

Welcome to my **Computer Graphics Sessional** repository! This repository contains all my lab experiments and interactive 2D graphics projects developed using **C++** and **OpenGL (GLUT)**.

---

## 🚀 Repository Contents

### 🎮 Featured Project: Speed Typing & Character Catching Game
An interactive 2D desktop game designed to test reflexes and typing speed across customized difficulty levels.

* **Folder:** `Character Game/`
* **Key Features:**
  * **3 Difficulty Modes:** Easy (Alphabets & Numbers), Medium (+ Punctuation), Hard (+ Special Symbols)
  * Dynamic visual particle effects on successful keypresses
  * Real-time Score, Combo Multipliers, and Health/Lives HUD
  * Custom Game State Management (Menu, Gameplay, Game Over screens)
* **Demo Video:** Included inside the project folder (`GameVideo.mp4`)

---

### 🧪 Lab Experiments (`Lab-1` to `Lab-5`)
This folder contains implementation of various fundamental computer graphics algorithms and transformations:
* **Lab 1:** Introduction to OpenGL setup, basic primitives (Lines, Points, Polygons)
* **Lab 2 & 3:** Line Drawing Algorithms (DDA & Bresenham's) and Circle Drawing
* **Lab 4 & 5:** 2D Transformations (Translation, Rotation, Scaling) and Complex Scene Rendering

---

## 🛠️ Tech Stack & Prerequisites

* **Language:** C++ (C++98 / C++11)
* **Graphics API:** OpenGL / GLUT (FreeGLUT)
* **IDE:** Code::Blocks

### How to Run in Code::Blocks (Windows)
1. Open any project (`.cbp` file) in Code::Blocks.
2. Go to **Project** ➔ **Build options...** ➔ **Linker settings**.
3. In **Other linker options**, ensure the following flags are added:
   ```text
   -lglut32
   -lopengl32
   -lglu32
