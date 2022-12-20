//
// Created by Situ Singh on 20/12/22.
//

#include<queue>
#include "Player.h"
#include "Board.h"

#ifndef SNAKE_LADDER_GAME_H
#define SNAKE_LADDER_GAME_H
class Game{
private:
    Board m_board;
    int m_init_players;
    queue<Player> m_players;
    bool m_isGameCompleted;
    int m_ndice;
    bool m_tillLastPlayer;
    bool m_multipleRollonSix;

    static const int c_defaultBoardSize = 100;
    static const int c_defaultNdice = 1;
public:
    Game(int boardSize): m_board(boardSize) {
        m_ndice = c_defaultNdice;
    }

    Game(): m_board(c_defaultBoardSize) {
        m_ndice = c_defaultNdice;
    }

    void setNdice(int noOfDice){
        this->m_ndice = noOfDice;
    }

    void setTillLastPlayer(bool tillLastPlayer) {
        this->m_tillLastPlayer = tillLastPlayer;
    }

    void setMultipleRollonSix(bool multipleRollonSix) {
        this->m_multipleRollonSix = multipleRollonSix;
    }

    // Board init
    void setPlayers(vector<Player> players) {
        for (const auto& e: players) {
            this->m_players.push(e);
        }
        this->m_init_players = players.size();
        map<string, int> player_pieces;
        for (auto player : players) {
            player_pieces.emplace(player.getId(), 0);
        }
        m_board.setPlayerPieces(player_pieces);
    }

    void setSnakes(vector<Snake> snakes) {
        m_board.setSnakes(snakes);
    }

    void setLadder(vector<Ladder> ladder) {
        m_board.setLadders(ladder);
    }

    // Business logic of Game
private:
    int getNewPositionAfterGoingThroughSnakesAndLadders(int newPosition);
    void movePlayer(Player player, int positions);
    int getTotalValueAfterDiceRolls();
    bool hasPlayerWon(Player player);
    bool isGameCompleted();
public:
    void startGame();
};
#endif //SNAKE_LADDER_GAME_H
