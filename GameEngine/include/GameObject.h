#pragma once

// =============================================
//  GameObject.h  |  Game Architecture Engine
//  The container that holds all components
// =============================================

#include "Component.h"
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <iostream>

class GameObject {
private:
    std::string name;
    std::vector<std::unique_ptr<Component>> components;
    bool active = true;

public:
    explicit GameObject(const std::string& name = "GameObject")
        : name(name) {}

    // Add a component (takes ownership via unique_ptr)
    void addComponent(std::unique_ptr<Component> component) {
        component->start();
        components.push_back(std::move(component));
    }

    // Update all components each frame
    void update() {
        if (!active) return;
        for (auto& c : components) {
            c->update();
        }
    }

    // Activate / deactivate this object
    void setActive(bool value) { active = value; }
    bool isActive() const      { return active; }

    const std::string& getName() const { return name; }

    // Get component count (useful for debugging)
    size_t componentCount() const { return components.size(); }
};
