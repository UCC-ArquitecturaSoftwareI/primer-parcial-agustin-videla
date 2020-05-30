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
                player.setSpeed({0,0});
            case 1:
                player.setSpeed({0,0});
            case 2:
                player.setSpeed({0,0});
            case 3:
                player.setSpeed({0,0});
            case 4:
                player.setSpeed({0,0});
            case 5:
                player.setSpeed({0,0});
            case 6:
                player.setSpeed({0,0});
            case 7:
                player.setSpeed({0,0});
            case 8:
                player.setSpeed({0,0});
            case 9:
                player.setSpeed({0,0});
            default:
                player.setSpeed({1,1});
                break;

        }
    }
}
