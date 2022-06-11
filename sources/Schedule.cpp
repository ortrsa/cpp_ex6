#include"Schedule.hpp"

namespace bball{

    Schedule::Schedule( Leauge* leauge){
        this->leauge = leauge;
    }

    // this function run the Leaugh games (total of 380 games) 
    // if toprint is true it will print all of the game results.
    void Schedule::runLeauge(bool toprint){
        int leaugesize = this->leauge->size();
        int counter = 0;

        for (size_t i = 0; i < leaugesize; i++)
        {
            for (size_t j = i + 1; j < leaugesize; j++)
            {
                Team* t1 = this->leauge->getTeams().at(i);
                Team* t2 = this->leauge->getTeams().at(j);
                Game thisgame = Game(t1,t2);
                thisgame.RunGame(toprint);
                counter ++;
            }
            
        }
        for (size_t i = 0; i < leaugesize; i++)
        {
            for (size_t j = i + 1; j < leaugesize; j++)
            {
                Team* t1 = this->leauge->getTeams().at(i);
                Team* t2 = this->leauge->getTeams().at(j);
                Game thisgame = Game(t2,t1);
                thisgame.RunGame(toprint);
                counter ++;
            }
            
        }
        std::cout <<counter <<" Games played!" << std::endl;
        this->leauge->EndLeauge();
    }


}