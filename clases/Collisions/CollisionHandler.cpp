//
// Created by Agus on 30/5/2020.
//

#include "CollisionHandler.h"

void CollisionHandler::handle(const std::vector<int>& c) {
    Player &player = Player::getInstance();
    for (auto i : c) {
        switch (i) {
            case 0: //arriba-izquierda
                if((toGrid(player.getPos()).x - player.getPos().x) > (toGrid(player.getPos()).y - player.getPos().y))
                    player.cage.x += player.getSpeed().x;
                else
                    player.cage.y += player.getSpeed().y;
                break;
            case 1: //arriba
                player.cage.y += player.getSpeed().y;
                break;
            case 2: //arriba-derecha
                if((toGrid(player.getPos()).x - player.getPos().x) > (toGrid(player.getPos()).y - player.getPos().y))
                    player.cage.x -= player.getSpeed().x;
                else
                    player.cage.y += player.getSpeed().y;
                break;
            case 3: //cabeza-derecha
                player.cage.x -= player.getSpeed().x;
                break;
            case 4: //pies-derecha
                player.cage.x -= player.getSpeed().x;
                break;
            case 5: //abajo-derecha
                if((toGrid(player.getPos()).x - player.getPos().x) > (toGrid(player.getPos()).y - player.getPos().y))
                    player.cage.x -= player.getSpeed().x;
                else
                    player.cage.y -= player.getSpeed().y;
                break;
            case 6: //abajo
                player.cage.y -= player.getSpeed().y;
                break;
            case 7: //abajo-izquierda
                if((toGrid(player.getPos()).x - player.getPos().x) > (toGrid(player.getPos()).y - player.getPos().y))
                    player.cage.x += player.getSpeed().x;
                else
                    player.cage.y -= player.getSpeed().y;
                break;
            case 8: //pies-izquierda
                player.cage.x += player.getSpeed().x;
                break;
            case 9: //cabeza-izquierda
                player.cage.x += player.getSpeed().x;
                break;
            default:
                break;
        }
    }
}
