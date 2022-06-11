#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::invalid_argument;
using std::ostream;
namespace bball{
    class Team
    {
    private:
        /* data */
        string name;
        double skill;
        int Wins;
        int Loses;
        int Winstreak;
        int MaxWinstreak;
        int Losestreak;
        int MaxLosestreak;
        int ScoringTo;
        int GotScored;


    public:
        Team(string name,double sk);
        //~Team();

        /*getters and seters*/
        string Getname();

        int getWins() const;
        void AddWin();

        int getLose() const;
        void AddLose();

        double Getskill() const;
        void Setskill(double sk);

        int GetWinstreak() const;
        void AddToWinstreak();

        int GetMaxWinstreak() const;
        int GetLosestreak() const;
        void AddToLosestreak();
        int GetMaxLosestreak() const;

        int GetScoringTo() const;
        void AddScoringTo(int score);
        int GetGotScored() const;
        void AddGotScored(int score);

        void win();
        void lose();

    };
    

    
}