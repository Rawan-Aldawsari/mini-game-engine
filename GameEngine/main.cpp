// =============================================
//  main.cpp  |  Game Architecture Engine
//  Demo: Player + Enemy using Component System
// =============================================

#include "include/Engine.h"
#include "include/Scene.h"
#include "include/GameObject.h"
#include "include/Components.h"
#include <memory>
#include <iostream>

int main() {

    // ─────────────────────────────────────────
    //  1. Create the Engine
    // ─────────────────────────────────────────
    Engine engine;

    // ─────────────────────────────────────────
    //  2. Create a Scene
    // ─────────────────────────────────────────
    Scene scene("Level 1 - Forest");

    // ─────────────────────────────────────────
    //  3. Build the PLAYER GameObject
    // ─────────────────────────────────────────
    std::cout << "──── Creating Player ────\n";
    auto player = std::make_unique<GameObject>("Player");

    // Create components
    auto playerTransform = std::make_unique<TransformComponent>(0.f, 0.f);
    auto playerMove      = std::make_unique<MovementComponent>(5.f, 1.f, 0.f);
    auto playerPhysics   = std::make_unique<PhysicsComponent>(75.f);
    auto playerInput     = std::make_unique<InputComponent>("WASD");
    auto playerRender    = std::make_unique<RenderComponent>("player.png", 1);
    auto playerHealth    = std::make_unique<HealthComponent>(100.f);

    // Link components that depend on each other
    // (movement reads transform to apply velocity)
    TransformComponent* transformPtr = playerTransform.get();
    playerMove->transform = transformPtr;

    // Add all components to the player
    player->addComponent(std::move(playerTransform));
    player->addComponent(std::move(playerMove));
    player->addComponent(std::move(playerPhysics));
    player->addComponent(std::move(playerInput));
    player->addComponent(std::move(playerRender));
    player->addComponent(std::move(playerHealth));

    // ─────────────────────────────────────────
    //  4. Build the ENEMY GameObject
    //     (reuses the SAME components — no code duplication!)
    // ─────────────────────────────────────────
    std::cout << "\n──── Creating Enemy ────\n";
    auto enemy = std::make_unique<GameObject>("Enemy");

    enemy->addComponent(std::make_unique<TransformComponent>(50.f, 0.f));
    enemy->addComponent(std::make_unique<MovementComponent>(2.f, -1.f, 0.f));
    enemy->addComponent(std::make_unique<PhysicsComponent>(50.f));
    enemy->addComponent(std::make_unique<RenderComponent>("enemy.png", 1));
    enemy->addComponent(std::make_unique<HealthComponent>(50.f));

    // ─────────────────────────────────────────
    //  5. Add GameObjects to the Scene
    // ─────────────────────────────────────────
    scene.addObject(std::move(player));
    scene.addObject(std::move(enemy));

    scene.printInfo();

    // ─────────────────────────────────────────
    //  6. Load scene into engine and run 2 frames
    // ─────────────────────────────────────────
    engine.setScene(&scene);
    engine.runFrames(2);

    // ─────────────────────────────────────────
    //  7. Demonstrate HealthComponent damage
    // ─────────────────────────────────────────
    std::cout << "\n──── Simulating Combat ────\n";
    // (In a real engine you'd get the component via getComponent<HealthComponent>())
    // For the demo, we create a standalone health component to show the behavior:
    HealthComponent hp(50.f);
    hp.start();
    hp.takeDamage(20.f);
    hp.takeDamage(15.f);
    hp.takeDamage(20.f); // lethal hit

    std::cout << "\n✅  Demo complete.\n";
    return 0;
}
