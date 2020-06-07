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
std::string element = "Tierra"; //para crear bloques con el inventario

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
static void UpdateDrawFrame(void) {

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


    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        if (!hash.exists(mousePosition))
            hash.put(mousePosition, factory->create(element, 1, mousePosition));

    //cambiar el tipo de bloque a crear según la posicion del mouse
    if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)){
        if(GetMousePosition().x > 60 && GetMousePosition().x < 76 && GetMousePosition().y > 410 && GetMousePosition().y < 426 )
            element = "iron";
        if(GetMousePosition().x > 81 && GetMousePosition().x < 104 && GetMousePosition().y > 410 && GetMousePosition().y < 426 )
            element = "Tierra";
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

    DrawRectangleRec({50,400,700,45}, BROWN);
    DrawRectangleRec({55,405,690,35}, LIGHTGRAY);

    //load inventory data
    int Bloques[3] = {12,461,640};

    SingletonMapa &mapa = SingletonMapa::getInstance("../resources/Mapa/EntitledMap2.json");
    Vector2 position = {60, 410}; //posicion donde se dibujará el bloque
    for(int i = 0; i < 3; i++){
        DrawTextureRec(mapa.getTexture(), mapa.getRec(Bloques[i]), position, WHITE);
        DrawText("64",position.x+2,431,3,BLACK);
        position.x+=23;
    }
}