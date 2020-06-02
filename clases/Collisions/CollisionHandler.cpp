//
// Created by Agus on 30/5/2020.
//

#include "CollisionHandler.h"
#include "../Player/Player.h"


void CollisionHandler::handle(std::vector<int> c) {
    Player &player = Player::getInstance();

    for (auto i : c) {
        switch (i) {
            //arriba-izquierda
            case 0:
                player.cage.x += 1*player.getSpeed().x;
                player.cage.y += 1*player.getSpeed().y;
                break;
            case 1:
                player.cage.y += 1*player.getSpeed().y;
                break;
            case 2:
                player.cage.x += 1*player.getSpeed().x;
                player.cage.y += 1*player.getSpeed().y;
                break;
            case 3:
                player.cage.x -= 1*player.getSpeed().x;
                break;
            case 4:
                player.cage.x -= 1*player.getSpeed().x;
                break;
            case 5:
                player.cage.x -= 1*player.getSpeed().x;
                player.cage.y -= 1*player.getSpeed().y;
                break;
            case 6:
                player.cage.y -= 1*player.getSpeed().y;
                break;
            case 7:
                player.cage.x -= 1*player.getSpeed().x;
                player.cage.y -= 1*player.getSpeed().y;
                break;
            case 8:
                player.cage.x += 1*player.getSpeed().x;
                break;
            case 9:
                player.cage.x += 1*player.getSpeed().x;
                break;
            default:
                std::cout<<"Como llegue aca?\n";
                break;
        }
    }
}
