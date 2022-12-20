//
// Created by Situ Singh on 20/12/22.
//

#include <string>

#ifndef SNAKE_LADDER_PLAYER_H
#define SNAKE_LADDER_PLAYER_H
class Player {
private:
    std::string m_name;
    std::string m_id;

public:
    Player(std::string name) {
        this->m_name = name;
        this->m_id = std::rand();
    }

    std::string getName() {
        return m_name;
    }

    std::string getId() {
        return m_id;
    }
};
#endif //SNAKE_LADDER_PLAYER_H
