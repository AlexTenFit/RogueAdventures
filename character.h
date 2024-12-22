#include "gameUtils.h"

class Character {
    public:
        Character(int winWidth, int winHeight);
        Vector2 getWorldPos() { return worldPos; }
        void undoMovement() { worldPos = previousWorldPos; }
        void setScreenPos(int winWidth, int winHeight);
        void tick(float deltaTime);
    private:
        Texture2D texture{LoadTexture("characters/Player.png")};
        AnimLoop animLoop{AnimLoop::IDLE_DOWN};
        Rectangle frame{0, 0, (float)texture.width/6.f, (float)texture.height/10.f};
        Vector2 screenPos{};
        Vector2 worldPos{};
        Vector2 previousWorldPos{};
        float scale{4.f};
        float facing{1.f};
        AnimData animData{
            0,
            6,
            0,
            1.f/12.f
        };
        const float speed{400};
};