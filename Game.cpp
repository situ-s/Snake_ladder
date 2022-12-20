//
// Created by Situ Singh on 20/12/22.
//
#include<iostream>
using namespace std;
#include "Game.h"
#include "DiceService.h"

int Game::getNewPositionAfterGoingThroughSnakesAndLadders(int newPosition){
    int previousPosition;
    do {
        previousPosition = newPosition;
        for (Snake snake : m_board.getSnakes()) {
            if (snake.getStart() == newPosition) {
                newPosition = snake.getEnd(); //the piece should go down to the position of the tail of that snake.
            }
        }

        for (Ladder ladder : m_board.getLadder()) {
            if (ladder.getStart() == newPosition) {
                newPosition = ladder.getEnd(); //the piece should go up to the position of the end of that ladder.
            }
        }
    } while (newPosition != previousPosition); // There could be another snake/ladder at the tail of the snake or the end position of the ladder and the piece should go up/down accordingly.
    return newPosition;
}

void Game::movePlayer(Player player, int positions) {
    int oldPosition = m_board.getPlayerPieces().at(player.getId());
    int newPosition = oldPosition + positions; // Based on the dice value, the player moves their piece forward that number of cells.
    int boardSize = m_board.getSize();

    // Can modify this logic to handle side case when there are multiple dices (Optional requirements)
    if (newPosition > boardSize) {
        newPosition = oldPosition; // After the dice roll, if a piece is supposed to move outside position 100, it does not move.
    } else {
        newPosition = getNewPositionAfterGoingThroughSnakesAndLadders(newPosition);
    }

    m_board.getPlayerPieces().emplace(string(player.getId()), newPosition);

    cout<<player.getName()<<" rolled a "<< positions<<" and moved from "<<oldPosition<<" to "<<newPosition<<endl;
}

int Game::getTotalValueAfterDiceRolls() {
    // Can use noOfDices and setShouldAllowMultipleDiceRollOnSix here to get total value (Optional requirements)
    return DiceService::roll();
}

bool Game::hasPlayerWon(Player player) {
    // Can change the logic a bit to handle special cases when there are more than one dice (Optional requirements)
    int playerPosition = m_board.getPlayerPieces().at(player.getId());
    int winningPosition = m_board.getSize();
    return playerPosition == winningPosition; // A player wins if it exactly reaches the position 100 and the game ends there.
}

bool Game::isGameCompleted() {
    // Can use shouldGameContinueTillLastPlayer to change the logic of determining if game is completed (Optional requirements)
    int currentNumberOfPlayers = m_players.size();
    return currentNumberOfPlayers < m_init_players;
}

void Game::startGame() {
    while (!isGameCompleted()) {
        int totalDiceValue = getTotalValueAfterDiceRolls(); // Each player rolls the dice when their turn comes.
        Player currentPlayer = m_players.front();
        m_players.pop();
        movePlayer(currentPlayer, totalDiceValue);
        if (hasPlayerWon(currentPlayer)) {
           cout<<currentPlayer.getName()<<" wins the game";
            m_board.getPlayerPieces().erase(currentPlayer.getId());
        } else {
            m_players.push(currentPlayer);
        }
    }
}
