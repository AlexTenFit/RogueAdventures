#include "gameUtils.h"
#include "character.h"
#include "prop.h"

int main() {

    // window def
    const int m_window_height{720};
    const int m_window_width{1280};
    const char* m_widnow_name{"Rogue Clash!"};
    const int m_window_fps{60};
    // init window
    InitWindow(m_window_width, m_window_height, m_widnow_name);

    // char

    // map
    Texture2D startingMap = LoadTexture("nature_tileset/worldmap.png");
    MapData worldMapData{
            {0,0},
            4
        };

    Character player{m_window_width, m_window_height};
    Prop rock1{
        LoadTexture("assets/Naturite vein.png"), 
        {5, 5}, 
        1};

    SetTargetFPS(m_window_fps);
    while (!WindowShouldClose()) {

        // update delta time
        const float dT{GetFrameTime()};

        BeginDrawing();
        ClearBackground(BLUE);
        
        // Set map position according to player position on the map
        worldMapData.pos = Vector2Scale(player.getWorldPos(), -1.f);
        // Draw map
        DrawTextureEx(startingMap, worldMapData.pos, 0, worldMapData.scale, WHITE);
        rock1.Render(player.getWorldPos());

        // Handle all player logic
        player.tick(dT);
        // Check map bounds
        if (player.getWorldPos().x < 0.f || 
            player.getWorldPos().y < 0.f ||
            player.getWorldPos().x + m_window_width > startingMap.width * worldMapData.scale ||
            player.getWorldPos().y + m_window_height > startingMap.height * worldMapData.scale) {
                
                // return player to previous pos if out of bounds
                player.undoMovement();
        }
        
        EndDrawing();
    }
    // cleanup
    UnloadTexture(startingMap);
    CloseWindow();
}