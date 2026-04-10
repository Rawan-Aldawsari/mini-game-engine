#pragma once

// =============================================
//  Scene.h  |  Game Architecture Engine
//  Manages all GameObjects in one scene
// =============================================

#include "GameObject.h"
#include <vector>
#include <memory>
#include <string>
#include <iostream>

class Scene {
private:
    std::string name;
    std::vector<std::unique_ptr<GameObject>> objects;

public:
    explicit Scene(const std::string& name = "Main Scene")
        : name(name) {}

    // Add a game object to the scene
    GameObject* addObject(std::unique_ptr<GameObject> obj) {
        objects.push_back(std::move(obj));
        return objects.back().get();
    }

    // Helper: create an object directly
    GameObject* createObject(const std::string& name = "Object") {
        auto obj = std::make_unique<GameObject>(name);
        return addObject(std::move(obj));
    }

    // Update all objects in the scene (one frame)
    void update() {
        for (auto& obj : objects) {
            obj->update();
        }
    }

    // Print scene info
    void printInfo() const {
        std::cout << "\n=== Scene: " << name << " ===\n";
        std::cout << "Objects: " << objects.size() << "\n";
        for (auto& obj : objects) {
            std::cout << "  - " << obj->getName()
                      << " (" << obj->componentCount()
                      << " components)\n";
        }
        std::cout << "=========================\n\n";
    }

    size_t objectCount() const { return objects.size(); }
    const std::string& getName() const { return name; }
};
