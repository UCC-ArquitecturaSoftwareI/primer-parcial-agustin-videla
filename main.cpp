#include <raylib.h>
#include "clases/blocks/BlockFactory.h"
#include "clases/Tools/ToolFactory.h"
#include <vector>

#if defined(PLATFORM_WEB) // Para crear HTML5
#include <emscripten/emscripten.h>
#endif
const int screenWidth = 800;
const int screenHeight = 450;

// Variables Globales
Music music;
BlockFactory* block_factory;
std::vector<Block*> blocks;
ToolFactory* tool_factory;
std::vector<Tool*> tools;

static void UpdateDrawFrame(void);          // Función dedicada a operar cada frame

void Delete (Vector2 xCoordinates, std::vector<Block *> *block){ //this function deletes the block is said position
    for(auto i : *block){
        if(i->getCoordinates().x == xCoordinates.x && i->getCoordinates().y == xCoordinates.y){
            delete i;
            std::cout<<"Elimine \n";
        }
    }
}

int main() {
    // Inicialización de la ventana
    InitWindow(screenWidth, screenHeight, "raylib template - advance game");
    InitAudioDevice();              // Initialize audio device

    /// Ejemplo de utilización de audio.
    music = LoadMusicStream("resources/Cyberpunk Moonlight Sonata.mp3");

    PlayMusicStream(music);
    block_factory = new BlockFactory;
    tool_factory = new ToolFactory;
    tools.push_back(tool_factory->create("pickaxe")); //creo un pico por default, mas adelante dependera de la seleccion del usuario
   // player = new Nave("resources/ship.png", Vector2{screenWidth / 2, screenHeight / 2});


#if defined(PLATFORM_WEB)  // Para versión Web.
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    // Main loop
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

    // siempre hay que reproducir la musica que esta actualmente
    //UpdateMusicStream(music);

    // Verifico Entradas de eventos.
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        blocks.push_back(block_factory->create("iron", 1, GetMousePosition()));
    }
    if(IsKeyDown(32)) {
        Delete(GetMousePosition(), &blocks);
    }

    // Comienzo a dibujar
    BeginDrawing();

    ClearBackground(RAYWHITE); // Limpio la pantalla con blanco

    // Dibujo todos los elementos del juego.
    for(auto i : blocks) {
        i->draw();
    }

    DrawText("SquareCraft", 20, 20, 40, LIGHTGRAY);

    // Finalizo el dibujado
    EndDrawing();
}