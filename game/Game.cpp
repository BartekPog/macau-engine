//
// Created by bart on 01.11.2020.
//

#include "Game.h"

Game::Game(int randomSeed, LinkedList<std::string> &playerNames):deck(Deck(randomSeed)), playersNumber(playerNames.getLength()) {

    // Init players
    players = new Player* [playersNumber];
    int i=0;
    for (LinkedList<std::string>::Iterator it(playerNames); !it.finished(); ++it){
        for (Player * player: {new PlayerPlaceholder}){
            if (*it == player->getName()){
                players[i] = player;
                i++;
            }
            else {
                delete player;
            }
        }
    }

    // Init hands
    for (int cardNum=0; cardNum < 5; cardNum++){
        for (int playerId=0; playerId<playersNumber; playerId++)
            players[playerId]->pullCard(deck);
    }

    //TODO check if is ok
}
