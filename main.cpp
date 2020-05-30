#include <raylib.h>
#include "clases/Blocks/BlockFactory.h"
#include "clases/Renderer/BlockRenderer.h"
#include "clases/Renderer/PlayerRenderer.h"
#include "clases/Tools/ToolFactory.h"
#include <vector>
#include "clases/Vector2Functions/HashFacade.h"
#include "clases/Collisions/CollisionObserver.h"
#include "resources/Mapa/SingletonMapa.h"
#include "clases/Vector2Functions/VectorTransform.h"

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
CollisionObserver botonazo;


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

    Vector2 mousePosition = mouseTransform(GetMousePosition()); //convierto la posición del mouse

    // Verifico Entradas de eventos.
    if (IsKeyDown(KEY_RIGHT)) player.cage.x += 1*player.getSpeed().x;
    else if (IsKeyDown(KEY_LEFT)) player.cage.x -= 1*player.getSpeed().x;
    if (IsKeyDown(KEY_UP)) player.cage.y -= 1*player.getSpeed().y;
    else if (IsKeyDown(KEY_DOWN)) player.cage.y += 1*player.getSpeed().y;


    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        if (!hash.exists(mousePosition))
            hash.put(mousePosition, factory->create("iron", 1, mousePosition));
    if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
        if (!hash.exists(mousePosition))
            hash.put(mousePosition, factory->create("Tierra", 1, mousePosition));
    }
    if(IsKeyDown(KEY_SPACE))
        hash.remove(mousePosition);

    //La camara sigue al jugador
    camera.target = (Vector2){ player.getPos().x + player.cage.width/2, player.getPos().y + player.cage.height/2 };

    //checkeo colisiones
    botonazo.checkCollision();

    // Comienzo a dibujar
    BeginDrawing();
    BeginMode2D(camera);

    ClearBackground(RAYWHITE); // Limpio la pantalla con blanco
    // Dibujo todos los elementos del juego.
    for(auto i : hash.table.all()) {
        blockRenderer->render(i.second);
    }

    playerRenderer->render(&player);
    DrawRectangle(player.getPos().x, player.getPos().y,10,10, BLUE);


    EndMode2D();
    std::string x = std::to_string((int)player.getPos().x);
    std::string y = std::to_string((int)player.getPos().y);
    std::string coor = x + "," + y;
    const char* c = coor.c_str();

    DrawText("Squarecraft", 40, 40, 40, LIGHTGRAY);

    DrawText(c, screenWidth-200, 40, 40, LIGHTGRAY);
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
    player.cage.x = screenWidth/2;
    player.cage.y = screenHeight/2;

    SingletonMapa &mapa = SingletonMapa::getInstance("../resources/Mapa/EntitledMap2.json");
    //camera init
    camera.target = (Vector2){ player.cage.x + player.cage.width/2, player.cage.y + player.cage.height/2 };
    camera.offset = (Vector2){ screenWidth/2, screenHeight/2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}