//
// Created by Situ Singh on 20/12/22.
//
#include<vector>
#include<map>
#include<string>
#include "Snake.h"
#include "Ladder.h"
using namespace std;

#ifndef SNAKE_LADDER_BOARD_H
#define SNAKE_LADDER_BOARD_H
class Board {
private:
    int m_size;
    vector<Snake> m_snakes;
    vector<Ladder> m_ladders;
    map<string, int> m_playerPieces;

public:
    Board(int size) {
        cout<<"Board size"<<size<<endl;
        this->m_size = size;
    }

    int getSize() {
        return m_size;
    }

    vector<Snake> getSnakes() {
        return m_snakes;
    }

    vector<Ladder> getLadder() {
        return m_ladders;
    }

    map<string, int> getPlayerPieces(){
        return m_playerPieces;
    }

    void setSnakes(vector<Snake> snakes) {
        m_snakes = snakes;
    }

    void setLadders(vector<Ladder> ladders) {
        m_ladders = ladders;
    }

    void setPlayerPieces(map<string, int> playerPieces) {
        m_playerPieces = playerPieces;
    }

};
#endif //SNAKE_LADDER_BOARD_H
