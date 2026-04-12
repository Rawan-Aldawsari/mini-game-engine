#pragma once

// =============================================
//  Component.h  |  Game Architecture Engine
//  Base class for all game components
// =============================================

class Component {
public:
    virtual ~Component() = default;

    // Called every frame
    virtual void update() = 0;

    // Optional lifecycle hooks
    virtual void start()   {}   // Called once when added to a GameObject
    virtual void onDestroy() {} // Called before component is removed
};
