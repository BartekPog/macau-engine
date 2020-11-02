//
// Created by bart on 01.11.2020.
//

#include "Game.h"

Game::Game(int randomSeed, const int maxGameLength, LinkedList<std::string> &playerNames):deck(Deck(randomSeed)),
            playersNumber(playerNames.getLength()), maxGameLength(maxGameLength) {

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

    // Init cards stack
    cardsStack = new LinkedList<Card*>;
}

Game::~Game() {
    for(int i=0; i<playersNumber; i++)
        delete players[i];
    delete [] players;
    delete cardsStack; // Cards are freed by deck and players - those are just references
}

int Game::play() {
    int prevId,currentId, nextId, prevHandLength, nextHandLength;

    for (int moveId=0; moveId < maxGameLength; moveId++){
        prevId = toPlayerIndex(moveId - 1);
        currentId = toPlayerIndex(moveId);
        nextId = toPlayerIndex(moveId + 1);

        int handLengths[playersNumber];

        for (int i=0; i<playersNumber; i++)
            handLengths[i] = players[toPlayerIndex(moveId + i)] -> getHandLength();

        players[currentId]->makeMove(cardsStack, playersNumber, handLengths, players[prevId], players[nextId], deck);

        if (players[currentId]->didWin())
            return currentId;
    }

    return -1;
}

int Game::toPlayerIndex(int moveNumber) const {
    return (moveNumber + playersNumber) % playersNumber;
}
