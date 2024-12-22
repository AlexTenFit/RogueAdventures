#include "animation.h"

AnimData updateAnimData(AnimData data, float deltaTime) {

    // update running time
    data.runningTime += deltaTime;
    if (data.runningTime >= data.updateTime) {
        
        // reset running time
        data.runningTime = 0.f;

        // update animation frame
        data.frame++;

        if (data.frame > data.maxFrame) data.frame = 0;
    }

    return data;
}

AnimLoop handleMovementAnimation(AnimLoop current, Vector2 movement) {

    if (Vector2Length(movement) != 0.0) {
            // determine animation loop
            if (movement.y < 0) current = MOVE_UP;
            else if (movement.y > 0) current = MOVE_DOWN;
            else current = MOVE_SIDE;

    } else {
        // If movement animation is currently set, change to corresponding idle animation
        if (current == MOVE_UP) current = IDLE_UP;
        else if (current == MOVE_SIDE) current = IDLE_SIDE;
        else if (current == MOVE_DOWN) current = IDLE_DOWN;
    }

    return current;
}