#pragma once

// =============================================
//  Engine.h  |  Game Architecture Engine
//  The main engine: holds scene & runs loop
// =============================================

#include "Scene.h"
#include <iostream>
#include <thread>
#include <chrono>

class Engine {
private:
    Scene*  activeScene = nullptr;
    bool    running     = false;
    int     targetFPS   = 60;

public:
    Engine() {
        std::cout << "\n╔══════════════════════════════════╗\n";
        std::cout <<   "║   Game Architecture Engine v1.0  ║\n";
        std::cout <<   "╚══════════════════════════════════╝\n\n";
    }

    void setScene(Scene* scene) {
        activeScene = scene;
        std::cout << "[Engine]  Active scene: " << scene->getName() << "\n";
    }

    // Run for N frames (demo mode)
    void runFrames(int frames) {
        if (!activeScene) {
            std::cerr << "[Engine]  ERROR: No scene loaded!\n";
            return;
        }

        std::cout << "\n──── Starting Game Loop ("
                  << frames << " frames) ────\n";

        for (int f = 1; f <= frames; ++f) {
            std::cout << "\n[Frame " << f << "]\n";
            activeScene->update();

            // Simulate ~60fps
            std::this_thread::sleep_for(std::chrono::milliseconds(16));
        }

        std::cout << "\n──── Game Loop Ended ────\n";
    }

    void setTargetFPS(int fps) { targetFPS = fps; }
};
