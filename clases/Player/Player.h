//
// Created by Agus on 16/5/2020.
//

#ifndef SQUARECRAFT_PLAYER_H
#define SQUARECRAFT_PLAYER_H


class Player {
    Player() = default;
public:
    Vector2 pos{};
    Vector2 size = {40, 80};
    static Player& getInstance(){
        static Player player;
        return player;
    }
};


#endif //SQUARECRAFT_PLAYER_H
