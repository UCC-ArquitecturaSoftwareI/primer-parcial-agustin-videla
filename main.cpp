#include <raylib.h>
#include "clases/Blocks/BlockFactory.h"
#include "clases/Renderer/BlockRenderer.h"
#include "clases/Tools/ToolFactory.h"
#include <vector>
#include "clases/Vector2Hash/SingletonHash.h"

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
SingletonHash &blocks = SingletonHash::getInstance();
std::vector<Tool*> tools;

static void UpdateDrawFrame(void);          // Función dedicada a operar cada frame

int main() {
    // Inicialización de la ventana
    InitWindow(screenWidth, screenHeight, "raylib template - advance game");
    InitAudioDevice();              // Initialize audio device

    /// Ejemplo de utilización de audio.
    music = LoadMusicStream("resources/Cyberpunk Moonlight Sonata.mp3");

    PlayMusicStream(music);
    factory = new BlockFactory;
    toolFactory = new ToolFactory;

    tools.push_back(toolFactory->create("pickaxe")); //solo para probar que funcione bien
    std::cout<<"the damage caused is: "<<tools[0]->getdamage()<<"\n"; //solo para probar que funcione bien
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
    //UpdateMusicStream(music); //la saqué porque me cansó

    // Verifico Entradas de eventos.
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        if(blocks.hash().find(Vector2Adaptor(GetMousePosition())) == blocks.hash().end())
            blocks.hash()[Vector2Adaptor(GetMousePosition())] = factory->create("iron", 1, GetMousePosition());
    }


    if(IsKeyPressed(KEY_SPACE)) {
        //Si el bloque que se quiere eliminar existe lo borra
        if(blocks.hash().find(Vector2Adaptor(GetMousePosition())) != blocks.hash().end()) {
            blocks.hash()[Vector2Adaptor(GetMousePosition())]->~Block();
            blocks.hash().erase(Vector2Adaptor(GetMousePosition()));
        }
    }


    // Comienzo a dibujar
    BeginDrawing();

    ClearBackground(RAYWHITE); // Limpio la pantalla con blanco

    // Dibujo todos los elementos del juego.
    for(auto i : blocks.hash()) {
        blockRenderer->render(i.second);
    }

    DrawText("SquareCraft", 20, 20, 40, LIGHTGRAY);

    // Finalizo el dibujado
    EndDrawing();
}
