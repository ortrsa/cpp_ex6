#include "Game.hpp"
const int MAXSKILLPOINT = 10;
const int HOMERANDFROM = 55;
const int HOMERANDTO = 100;
const int AWAYRANDFROM = 50;
const int AWAYRANDTO = 100;
const int STD = 15;
using std::invalid_argument;

namespace bball{

    Game::Game(Team *H, Team *A){
        if(H->Getname() == A->Getname()){
            throw invalid_argument("This is the same Team!");
        }

        this->Home = H;
        this->Away = A;
        this->scoreAway = 0;
        this->scorehome = 0;

    }

    void Game::RunGame(bool toprint){
        // Get the score of each team (randomly) and add 10 * the team skill
        int Homescore = Game::getnormalscore(HOMERANDFROM, HOMERANDTO);
        int Awayscore = Game::getnormalscore(AWAYRANDFROM, AWAYRANDTO); 

        while(Homescore == Awayscore){// If Tie keep play till one of the Teams win

            Homescore = Game::getnormalscore(HOMERANDFROM, HOMERANDTO);
            Awayscore = Game::getnormalscore(AWAYRANDFROM, AWAYRANDTO); 
        }

        // Home Team wins!
        if(Homescore > Awayscore){
            this->Home->win();
            this->Away->lose();
            if(toprint){
                std::cout << this->Home->Getname() << " WIN " << this->Away->Getname() <<" at Home! " << std::endl;
                std::cout << "score home: " << Homescore << std::endl;
                std::cout << "score Away: " << Awayscore << std::endl << std::endl;
            }
        }
        // Away Team wins!
        else if(Homescore < Awayscore){
            this->Away->win();
            this->Home->lose();
            if(toprint){
                std::cout << this->Away->Getname() << " WIN " << this->Home->Getname() <<" Away! " << std::endl;
                std::cout << "score home: " << Homescore << std::endl;
                std::cout << "score Away: " << Awayscore << std::endl << std::endl;
            }
        }

        this->Home->AddScoringTo(Homescore);
        this->Home->AddGotScored(Awayscore);
        this->Away->AddScoringTo(Awayscore);
        this->Away->AddGotScored(Homescore);
    }

    int Game::getnormalscore (int from, int to){
        double d_from = (double)from;
        double d_to = (double)to;
        double avg = ( d_from + d_to)/2;
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::normal_distribution<> distribution (avg,STD);
        int ans = (int)distribution(gen);
       
        // if the normal dist return value that bigger than "to"
        if(ans > to){
            return to;
        }
        // if the normal dist return value that smaller than "from"
        if(ans < from){
            return from;
        }

        return ans;


    }


}