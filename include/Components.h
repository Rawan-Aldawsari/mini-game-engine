#pragma once

// =============================================
//  Components.h  |  Game Architecture Engine
//  All concrete component implementations
// =============================================

#include "Component.h"
#include <iostream>
#include <string>

// ─────────────────────────────────────────────
//  TransformComponent
//  Stores position (x, y) and rotation
// ─────────────────────────────────────────────
struct Vec2 {
    float x = 0.f, y = 0.f;
};

class TransformComponent : public Component {
public:
    Vec2  position;
    Vec2  scale    = {1.f, 1.f};
    float rotation = 0.f;

    TransformComponent(float x = 0.f, float y = 0.f)
        : position{x, y} {}

    void start() override {
        std::cout << "[Transform]  Initialized at ("
                  << position.x << ", " << position.y << ")\n";
    }

    void update() override {
        // In a real engine: sync with physics, etc.
    }

    // Helper to move the object
    void translate(float dx, float dy) {
        position.x += dx;
        position.y += dy;
    }
};

// ─────────────────────────────────────────────
//  MovementComponent
//  Moves the object each frame using velocity
// ─────────────────────────────────────────────
class MovementComponent : public Component {
public:
    Vec2  velocity;
    float speed;
    TransformComponent* transform = nullptr;

    explicit MovementComponent(float speed = 5.f,
                                float vx    = 0.f,
                                float vy    = 0.f)
        : velocity{vx, vy}, speed(speed) {}

    void start() override {
        std::cout << "[Movement]   Speed = " << speed << "\n";
    }

    void update() override {
        if (transform) {
            transform->translate(velocity.x * speed,
                                  velocity.y * speed);
            std::cout << "[Movement]   Position -> ("
                      << transform->position.x << ", "
                      << transform->position.y << ")\n";
        } else {
            std::cout << "[Movement]   Moving... (no transform linked)\n";
        }
    }
};

// ─────────────────────────────────────────────
//  PhysicsComponent
//  Simulates gravity and basic collision
// ─────────────────────────────────────────────
class PhysicsComponent : public Component {
private:
    float gravity     = 9.8f;
    float mass        = 1.0f;
    bool  grounded    = false;
    float vertVelocity = 0.f;

public:
    PhysicsComponent(float mass = 1.f, float gravity = 9.8f)
        : gravity(gravity), mass(mass) {}

    void start() override {
        std::cout << "[Physics]    Mass=" << mass
                  << "  Gravity=" << gravity << "\n";
    }

    void update() override {
        if (!grounded) {
            vertVelocity += gravity * 0.016f; // ~60 fps deltaTime
        }
        std::cout << "[Physics]    Vertical velocity = "
                  << vertVelocity << "\n";
    }

    void setGrounded(bool value) { grounded = value; }
    float getVerticalVelocity()  const { return vertVelocity; }
};

// ─────────────────────────────────────────────
//  InputComponent
//  Reads keyboard input and forwards to movement
// ─────────────────────────────────────────────
class InputComponent : public Component {
private:
    std::string keyMapping;
    MovementComponent* movement = nullptr;

public:
    explicit InputComponent(const std::string& keys = "WASD")
        : keyMapping(keys) {}

    void linkMovement(MovementComponent* m) { movement = m; }

    void start() override {
        std::cout << "[Input]      Key mapping: " << keyMapping << "\n";
    }

    void update() override {
        std::cout << "[Input]      Polling keys (" << keyMapping << ")...\n";
        // In a real engine: SDL_GetKeyboardState / sf::Keyboard::isKeyPressed
    }
};

// ─────────────────────────────────────────────
//  RenderComponent
//  Draws a sprite or mesh to the screen
// ─────────────────────────────────────────────
class RenderComponent : public Component {
private:
    std::string spritePath;
    bool        visible = true;
    int         layer   = 0;

public:
    RenderComponent(const std::string& sprite = "default.png",
                    int layer = 0)
        : spritePath(sprite), layer(layer) {}

    void start() override {
        std::cout << "[Render]     Sprite='" << spritePath
                  << "'  Layer=" << layer << "\n";
    }

    void update() override {
        if (visible) {
            std::cout << "[Render]     Drawing '" << spritePath
                      << "' on layer " << layer << "\n";
        }
    }

    void setVisible(bool v) { visible = v; }
};

// ─────────────────────────────────────────────
//  HealthComponent
//  Tracks HP, handles damage and death events
// ─────────────────────────────────────────────
class HealthComponent : public Component {
private:
    float maxHp;
    float currentHp;
    bool  alive = true;

public:
    explicit HealthComponent(float hp = 100.f)
        : maxHp(hp), currentHp(hp) {}

    void start() override {
        std::cout << "[Health]     HP = "
                  << currentHp << " / " << maxHp << "\n";
    }

    void update() override {
        if (!alive)
            std::cout << "[Health]     *** DEAD ***\n";
    }

    void takeDamage(float amount) {
        currentHp -= amount;
        std::cout << "[Health]     Took " << amount
                  << " dmg  -> HP: " << currentHp << "\n";
        if (currentHp <= 0.f) {
            alive = false;
            std::cout << "[Health]     *** Object destroyed! ***\n";
        }
    }

    float getHp()    const { return currentHp; }
    bool  isAlive()  const { return alive; }
};
