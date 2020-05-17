#include <raylib.h>
#include "clases/Blocks/BlockFactory.h"
#include "clases/Renderer/BlockRenderer.h"
#include "clases/Renderer/PlayerRenderer.h"
#include "clases/Tools/ToolFactory.h"
#include <vector>
#include "clases/Vector2Functions/HashFacade.h"

#if defined(PLATFORM_WEB) // Para crear HTML5
#include <emscripten/emscripten.h>
#endif
const int screenWidth = 800;
const int screenHeight = 450;

// Variables Globales
Music music;
BlockFactory* factory;
ToolFactory* toolFactory;
BlockRenderer* blockRenderer;
PlayerRenderer* playerRenderer;
Player &player = Player::getInstance();
Hash hash;
std::vector<Tool*> tools;
Camera2D camera;

void initializer();
static void UpdateDrawFrame();          // Función dedicada a operar cada frame

int main() {

    initializer();

#if defined(PLATFORM_WEB)  // Para versión Web.
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    //Main Loop
    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }
#endif


    // Descargar todos los resources cargados

    UnloadMusicStream(music);   // Descargo la musica de RAM
    CloseAudioDevice();         // Cierro el dispositivo de Audio
    CloseWindow();              // Cierro la ventana
    return 0;
}


/**
 *  Función dedicada a dibujar cada frame. Acá adentro se debe poner la logica necesaria para representar un nuevo frame
 *  del juego.
 */
static void UpdateDrawFrame(void) {

    //UpdateMusicStream(music); //la saqué porque me cansó

    // Verifico Entradas de eventos.
    if (IsKeyDown(KEY_RIGHT)) player.pos.x += 5;
    else if (IsKeyDown(KEY_LEFT)) player.pos.x -= 5;
    if (IsKeyDown(KEY_UP)) player.pos.y -= 5;
    else if (IsKeyDown(KEY_DOWN)) player.pos.y += 5;


    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        hash.put(GetMousePosition(), factory->create("iron", 1, GetMousePosition()));
    if(IsKeyPressed(KEY_SPACE))
        hash.remove(GetMousePosition());

    //La camara sigue al jugador
    camera.target = (Vector2){ player.pos.x + player.size.x/2, player.pos.y + player.size.y/2 };

    // Comienzo a dibujar
    BeginDrawing();

    BeginMode2D(camera);

    ClearBackground(RAYWHITE); // Limpio la pantalla con blanco

    // Dibujo todos los elementos del juego.
    for(auto i : hash.table.all()) {
        blockRenderer->render(i.second);
    }
    playerRenderer->render(&player);


    EndMode2D();

    DrawText("SquareCraft", 40, 40, 40, LIGHTGRAY);

    EndDrawing();
}

void initializer() {
    InitWindow(screenWidth, screenHeight, "Squarecraft");
    //music init
    InitAudioDevice();
    music = LoadMusicStream("resources/Cyberpunk Moonlight Sonata.mp3");
    PlayMusicStream(music);

    factory = new BlockFactory;
    toolFactory = new ToolFactory;
    player.pos = (Vector2){screenWidth/2, screenHeight/2};

    //camera init
    camera.target = (Vector2){ player.pos.x + player.size.x/2, player.pos.y + player.size.y/2 };
    camera.offset = (Vector2){ screenWidth/2, screenHeight/2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}