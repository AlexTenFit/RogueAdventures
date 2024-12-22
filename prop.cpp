#include "prop.h"

Prop::Prop(Texture2D tex, Vector2 pos, float scl) : 
    texture(tex) ,worldPos(pos), scale(scl) {}

void Prop::Render(Vector2 playerPos) {
    Vector2 screenpos{Vector2Subtract(worldPos, playerPos)};
    DrawTextureEx(texture, screenpos, 0, scale, WHITE);
}