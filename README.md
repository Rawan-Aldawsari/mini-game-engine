# 🧠 Mini Game Engine (C++)

> Not just a game… but a scalable game architecture.

---

## 🚀 Overview

This project is a **mini game engine built in C++** using a **Component-Based Architecture**.

Instead of building a single game, this project focuses on designing a **reusable and scalable system** that can be used to create different types of games.

---

## 🎯 Key Concepts

* 🧩 Component-Based Design
* 🧠 Separation of Concerns
* ♻️ Reusability
* 📦 Modular Architecture
* ⚙️ Game Loop System

---

## 🧱 Architecture

### 🧍 GameObject

Represents any entity in the game (Player, Enemy, etc.)

### 🔌 Component

Each behavior is separated into components:

* Movement Component 🏃
* Render Component 🎨
* Physics Component 💥
* Input Component 🎮

📌 A GameObject is just a collection of Components.

---

## 🔁 Game Loop

The engine runs using a simple loop:

```cpp
while (true) {
    gameObject.update();
}
```

Each component updates independently, ensuring clean separation of logic.

---

## 💡 Why This Project?

Most beginner projects focus on building a game.
This project focuses on **building the system behind the game**.

👉 This demonstrates:

* Strong understanding of OOP
* Real-world software architecture thinking
* Clean and maintainable code design

---

## 🔥 Features

* Add/remove components dynamically
* Extendable architecture
* Clean and readable structure
* Easy to scale into a full engine

---

## 🧪 Example Usage

```cpp
GameObject player;

player.addComponent(new MovementComponent());
player.addComponent(new RenderComponent());
player.addComponent(new PhysicsComponent());
player.addComponent(new InputComponent());

player.update();
```

---

## 🛠️ Technologies

* C++
* Object-Oriented Programming (OOP)

---

## 📈 Future Improvements

* Scene Management System
* Event System
* Collision Detection
* Transform Component (Position / Rotation)
* Full Entity Component System (ECS)

---

## 👩‍💻 Author

**Rawan Aldawsari**

---

## ⭐ Final Note

This project represents a shift from writing code to **engineering systems**.
