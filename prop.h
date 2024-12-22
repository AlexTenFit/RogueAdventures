#include "gameUtils.h"

class Prop {
    public:
        Prop(Texture2D texture ,Vector2 pos, float scl);
        void Render(Vector2 playerPos);
    private:
        Texture2D texture{};
        Vector2 worldPos{};
        float scale{};
};