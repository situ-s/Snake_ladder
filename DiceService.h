//
// Created by Situ Singh on 20/12/22.
//

#include<cstdlib>

#ifndef SNAKE_LADDER_DICESERVICE_H
#define SNAKE_LADDER_DICESERVICE_H

class DiceService{
public:
    static int roll(){
        return (std::rand() % 6 + 1);
    }
};
#endif //SNAKE_LADDER_DICESERVICE_H
