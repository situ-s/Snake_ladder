#include <iostream>
#include "Game.h"
using namespace std;

int main() {
    int noOfSnakes, noOfLadders, noOfPlayers;
    cin>>noOfSnakes;

    vector<Snake> snakes;
    for (int i = 0; i < noOfSnakes; i++) {
        int start, end;
        cin>>start>>end;
        Snake snake(start,end);
        snakes.push_back(snake);
    }
    cout<<snakes.size();

    cin>>noOfLadders;
    vector<Ladder> ladders;
    for (int i = 0; i < noOfLadders; i++) {
        int start, end;
        cin>>start>>end;
        Ladder ladder(start,end);
        ladders.push_back(ladder);
    }
    cout<<ladders.size();

    cin>>noOfPlayers;
    vector<Player> players;
    for (int i = 0; i < noOfPlayers; i++) {
        string name;
        cin>>name;
        Player P(name);
        players.push_back(P);
    }
    cout<<players.size();

    Game G;
    G.setPlayers(players);
    G.setSnakes(snakes);
    G.setLadder(ladders);
    G.startGame();
}
