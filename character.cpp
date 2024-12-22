#include "character.h"
#include "animation.h"

Character::Character(int winWidth, int winHeight) {
    setScreenPos(winWidth, winHeight);
}

void Character::setScreenPos(int winWidth, int winHeight) {
    // Set character's position on the screen 
    screenPos = {
            static_cast<float>(winWidth) / 2.0f - scale * (0.5f * frame.width), 
            static_cast<float>(winHeight) / 2.0f - scale * (0.5f * frame.height)
    };
}

void Character::tick(float deltaTime) {
        
        // movement logic
        float moveAmount(speed * deltaTime);

        // Determine movement vector by input
        Vector2 direction{};
        if (IsKeyDown(KEY_A)) direction.x -= 1.0;
        if (IsKeyDown(KEY_D)) direction.x += 1.0;
        if (IsKeyDown(KEY_W)) direction.y -= 1.0;
        if (IsKeyDown(KEY_S)) direction.y += 1.0;

        // Subtract input vector from position vector to move the map (opposite of player movement)
        if (Vector2Length(direction) != 0.0) {
            // store previous world pos for bounds calc
            previousWorldPos = worldPos;

            worldPos = Vector2Add( 
                worldPos, 
                Vector2Scale(Vector2Normalize(direction), moveAmount)
                );
            
            // change facing direction of character according to input
            facing = direction.x < 0.f? -1.f : 1.f;
        }
        // Update the animation loop of the player according to the movement direction
        animLoop = handleMovementAnimation(animLoop, direction);

        // Update drawing rectangles and animation data 
        animData = updateAnimData(animData, deltaTime);
        Rectangle src{animData.frame * frame.width, animLoop * frame.height, facing * frame.width, frame.height};
        Rectangle dst{screenPos.x, screenPos.y, scale * frame.width, scale * frame.height};

        // Draw player with pro params
        DrawTexturePro(texture, src, dst, Vector2{}, 0, WHITE);
}
