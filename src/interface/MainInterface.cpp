//
// Created by bart on 25.10.2020.
//

#include "MainInterface.h"

void MainInterface::initIterations() {
    std::cout<<"How many games shall be played: ";
    std::cin>>gamesToPlay;
    std::cout<<std::endl;
}

void MainInterface::initPlayersNames() {
    std::cout<<"Select algorithms: "<<std::endl;
    for (LinkedList<std::string>::Iterator it(possibleNames); !it.finished(); ++it)
        std::cout<<*it<<std::endl;
    std::cout<<std::endl;

    bool valid;
    do{
        valid = true;
        std::cout<<"Type the names separated by space: ";
        std::string line;
        std::string name;


        std::getline(std::cin, line);
        std::stringstream ss(line);

        while (ss>>name){
            if (!possibleNames.isIn(name)){
                std::cerr<<"Name: "<<name<<" is not a valid name, try again"<<std::endl;
                valid = false;
                playersNames.clearList();
            }
            else{
                playersNames.pushFront(name);
            }
        }
        if ((playersNames.length < 2) || (playersNames.length > 8)){
            std::cerr<<"Players number must be between two and eight"<<std::endl;
            valid = false;
            playersNames.clearList();
        }
    }while (!valid);
}

MainInterface::MainInterface() {
    for (Player* player: {(Player*)new PlayerPlaceholder, (Player*)new AdvancedPlaceholder}){
        possibleNames.pushFront(player->getName());
        delete player;
    }

    std::cout<<"MACAU SIMULATOR by Bartłomiej Pogodziński 2020"<<std::endl<<std::endl;
    initPlayersNames();
    initIterations();
}

void MainInterface::runSimulation() {
    std::cout<<"Starting simulation"<<std::endl;
    std::cout<<"Progress: ";

    int wins[playersNames.length];
    for (int i=0; i<playersNames.length; i++)
        wins[i]=0;

    int gamesFinished = 0;
    int progressBarCounter = 0;

    for (int i=0; i<gamesToPlay; i++){
        Game game(i+42, maxGameMoves, playersNames);

        int winner = game.play();

        if(winner>=0){
            gamesFinished++;
            wins[winner]++;
        }

        progressBarCounter++;
        if(progressBarCounter > (gamesToPlay / totalProgressBarSize)){
            std::cout<<barSign<<std::flush;
            progressBarCounter-=(gamesToPlay / totalProgressBarSize);
        }
    }

    if (gamesFinished == 0){
        std::cout<<std::endl<<std::endl<<"All games have been terminated due to timeout. Consider increasing the timeout or changing the algorithms"<<std::endl;
    }
    else {
        std::cout<<std::endl<<std::endl<<"Results:"<<std::endl;

        int i=0;
        for (LinkedList<std::string>::Iterator it(playersNames); !it.finished(); ++it){
            printf("%15s:\t%.2f%% \n", (*it).c_str(), 100.0*(float)wins[i]/(float)gamesFinished);
            i++;
        }

    }
}
