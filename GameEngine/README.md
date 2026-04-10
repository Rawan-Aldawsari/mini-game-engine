# 🎮 Game Architecture Engine

> Component-Based Game Architecture in C++17  
> Built for scalability, reusability, and clean separation of concerns.

---

## 🧱 Architecture Overview

```
Engine
 └── Scene
      └── GameObject  (Player, Enemy, NPC...)
           ├── TransformComponent   → position, rotation, scale
           ├── MovementComponent    → velocity-based movement
           ├── PhysicsComponent     → gravity, collision
           ├── InputComponent       → keyboard polling
           ├── RenderComponent      → sprite/mesh drawing
           └── HealthComponent      → HP, damage, death
```

---

## 📁 Project Structure

```
GameEngine/
├── include/
│   ├── Component.h        # Abstract base for all components
│   ├── Components.h       # All concrete component implementations
│   ├── GameObject.h       # Container for components
│   ├── Scene.h            # Manages all GameObjects
│   └── Engine.h           # Main engine & game loop
├── main.cpp               # Demo: Player + Enemy
└── CMakeLists.txt         # Build configuration
```

---

## ⚙️ Build & Run

### Using g++ directly:
```bash
g++ -std=c++17 -Wall -O2 -Iinclude main.cpp -o GameEngine
./GameEngine
```

### Using CMake:
```bash
mkdir build && cd build
cmake ..
make
./GameEngine
```

---

## 🔌 Adding a New Component

```cpp
class AudioComponent : public Component {
private:
    std::string audioFile;
public:
    AudioComponent(const std::string& file) : audioFile(file) {}

    void start() override {
        std::cout << "[Audio] Loaded: " << audioFile << "\n";
    }

    void update() override {
        // play looping audio, etc.
    }
};
```

Then attach it to any GameObject:
```cpp
player->addComponent(std::make_unique<AudioComponent>("footstep.wav"));
```

---

## 💡 Design Principles

| Principle | Description |
|-----------|-------------|
| **Separation of Concerns** | Each component handles exactly one responsibility |
| **Composition over Inheritance** | GameObjects are built from parts, not deep class trees |
| **Reusability** | Any component can be attached to any GameObject |
| **Scalability** | Add new behaviors without modifying existing code |

---

## 🚀 Possible Extensions

- `CollisionSystem` — broad/narrow phase collision detection  
- `EventSystem` — decouple components via a message bus  
- `SceneManager` — load/unload multiple scenes  
- `ECS (Entity Component System)` — cache-friendly, data-oriented upgrade  

---

## 👩‍💻 Portfolio Note

> "Built a component-based Game Architecture Engine in C++ that separates responsibilities  
>  across reusable, composable components — enabling any game object to be constructed  
>  from independent, interchangeable behaviors without code duplication."
