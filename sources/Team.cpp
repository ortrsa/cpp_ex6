#include "Team.hpp"


using std::invalid_argument;
namespace bball{
    // init Team with unieq name and 0 <= skill <= 1
    Team::Team(string name,double sk){
        if(sk > 1){
            throw invalid_argument("skill need to be smaller than 1");
        };
        if(sk< 0){
            throw invalid_argument("skill need to be greater than 0");
        };
        if(name == ""){
            throw invalid_argument("pleas add the name of the team");
        }

        this->name = std::move(name);
        this->skill = sk;
        this->Wins = 0;
        this->Loses = 0;
        this->Winstreak = 0;
        this->MaxWinstreak = 0;
        this->Losestreak = 0;
        this->MaxLosestreak = 0;
        this->ScoringTo = 0;
        this->GotScored = 0;
    }
    
    /*getters and seters*/
        string Team::Getname(){return name;}

        int Team::getWins() const {return this->Wins;} 
        void Team::AddWin(){this->Wins++;}

        int Team::getLose() const {return this->Loses;}
        void Team::AddLose(){this->Loses++;}

        double Team::Getskill() const {return this->skill;}
        void Team::Setskill(double sk){this->skill = sk;}

        int Team::GetWinstreak() const {return this->Winstreak;}
        void Team::AddToWinstreak(){this->Winstreak++;}

        int Team::GetMaxWinstreak() const {return this->MaxWinstreak;}
        int Team::GetLosestreak() const {return this->Losestreak;}
        void Team::AddToLosestreak(){this->Losestreak++;}
        int Team::GetMaxLosestreak() const {return this->MaxLosestreak;}

        int Team::GetScoringTo() const {return this->ScoringTo;}
        void Team::AddScoringTo(int score){
            this->ScoringTo += score;
        }
        int Team::GetGotScored() const {return this->GotScored;}
        void Team::AddGotScored(int score){
            this->GotScored += score;
        }
    
    // If the team win reaset the LoseStreak and add to Win streak
    void Team::win(){
        this->AddWin();
        this->AddToWinstreak();

        if(this->Losestreak > this->MaxLosestreak){
            this->MaxLosestreak = this->Losestreak;
        }

        this->Losestreak = 0;

    }
    // If the team lose reaset the Winstreak and add to lose streak
     void Team::lose(){
        this->AddLose();
        this->AddToLosestreak();

        if(this->Winstreak > this->MaxWinstreak){
            this->MaxWinstreak = this->Winstreak;
        }

        this->Winstreak = 0;

    }

    


}