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
const int screenWidth = 1280;
const int screenHeight = 700;

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
//crear un inventario y meter esto ahí
std::string element = "dirt"; //para crear bloques con el inventario
std::string type = "0";
void initializer();
static void UpdateDrawFrame();          // Función dedicada a operar cada frame
void renderInventario();

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
static void UpdateDrawFrame() {

    //UpdateMusicStream(music); //la saqué porque me cansó

    Vector2 mousePosition = mouseTransform(GetMousePosition()); //convierto la posición del mouse

    //checkeo colisiones
    if(botonazo.checkCollision()){
        player.setPos(player.getBack());
    } else {
        if(!IsKeyDown(KEY_UP) && !botonazo.abajo)
            player.cage.y += 1*player.getSpeed().y;
    }

        // Verifico Entradas de eventos.
        if (IsKeyDown(KEY_RIGHT)) player.cage.x += 1*player.getSpeed().x;
        else if (IsKeyDown(KEY_LEFT)) player.cage.x -= 1*player.getSpeed().x;
        if (IsKeyDown(KEY_UP)) player.cage.y -= 1*player.getSpeed().y;
        else if (IsKeyDown(KEY_DOWN)) player.cage.y += 1*player.getSpeed().y;

    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        //cambiar el tipo de bloque a crear según la posicion del mouse
        if(GetMousePosition().x > 60 && GetMousePosition().x < 76 && GetMousePosition().y > screenHeight - 40 && GetMousePosition().y < screenHeight - 24 ){
            element = "iron";
            type = "1";
        } else //cambiar el tipo de bloque a crear según la posicion del mouse
        if(GetMousePosition().x > 81 && GetMousePosition().x < 104 && GetMousePosition().y > screenHeight - 40 && GetMousePosition().y < screenHeight - 24 ){
            element = "dirt";
            type = "0";
        } else
        if(GetMousePosition().x > 109 && GetMousePosition().x < 125 && GetMousePosition().y > screenHeight - 40 && GetMousePosition().y < screenHeight - 24 ){
            element = "dirt";
            type = "1";
        } else
        if (!hash.exists(mousePosition))
            hash.put(mousePosition, factory->create(element, type, mousePosition));
    }

    if(IsKeyDown(KEY_SPACE))
        hash.remove(mousePosition);

    //La camara sigue al jugador
    camera.target = (Vector2){ player.getPos().x + player.cage.width/2, player.getPos().y + player.cage.height/2 };

    // Comienzo a dibujar
    BeginDrawing();
    BeginMode2D(camera);

    ClearBackground(RAYWHITE); // Limpio la pantalla con blanco
    // Dibujo todos los elementos del juego.
    for(auto i : hash.table.all()) {
        blockRenderer->render(i.second);
        //check *-+/colision
        if(CheckCollisionRecs(i.second->getCage(), player.cage)){
            player.setPos(player.getBack());
        }
    }

    playerRenderer->render(&player);

    //Guardo la posicion actual del bloque para futura colisión
    player.setBack();

    EndMode2D();
    std::string x = std::to_string((int)player.getPos().x);
    std::string y = std::to_string((int)player.getPos().y);
    std::string coor = x + "," + y;
    const char* c = coor.c_str();

    DrawText("Squarecraft", 40, 40, 40, LIGHTGRAY);
    DrawText(c, screenWidth-200, 40, 40, LIGHTGRAY);

     x = std::to_string((int)GetMousePosition().x);
     y = std::to_string((int)GetMousePosition().y);
     coor = x + "," + y;
    c = coor.c_str();
    DrawText(c, screenWidth-200, 90, 40, LIGHTGRAY);

    renderInventario();

    EndDrawing();
}

void initializer() {
    InitWindow(screenWidth, screenHeight, "Squarecraft");
    //music init
    InitAudioDevice();
    music = LoadMusicStream("resources/Cyberpunk Moonlight Sonata.mp3");
    PlayMusicStream(music);
    //fabricate everything we need
    factory = new BlockFactory;
    toolFactory = new ToolFactory;
    player.cage.x = screenWidth/2;
    player.cage.y = screenHeight/2;
    //Load map data
    SingletonMapa &mapa = SingletonMapa::getInstance("../resources/Mapa/EntitledMap2.json");
    //camera init
    camera.target = (Vector2){ player.cage.x + player.cage.width/2, player.cage.y + player.cage.height/2 };
    camera.offset = (Vector2){ screenWidth/2, screenHeight/2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}
void renderInventario(){

    DrawRectangleRec({50,screenHeight - 50,screenWidth - 100,45}, BROWN); //outer
    DrawRectangleRec({55,screenHeight - 45,screenWidth - 110,35}, LIGHTGRAY); //inner

    //load inventory data
    int Bloques[3] = {253,461,250};

    SingletonMapa &mapa = SingletonMapa::getInstance("");
    Vector2 position = {60, screenHeight - 40}; //posicion donde se dibujará el bloque
    for(int Bloque : Bloques){
        DrawTextureRec(mapa.getTexture(), mapa.getRec(Bloque), position, WHITE);
        DrawText("64",position.x+2,screenHeight - 20,3,BLACK);
        position.x+=23;
    }
}