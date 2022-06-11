// normal_distribution example
#include"sources/Schedule.hpp"
using std::cout;
using std::endl;
using namespace bball;
int main()
{
    

    Leauge L = Leauge();
    int counter = 0 ;
    vector<bball::Team*> ta = L.getTeams();
    Schedule s = Schedule(&L);
    s.runLeauge();
    cout<< "\n--------------BEST TEAMS--------------"<<endl;
    L.BestTeam(0);
    cout<< "\n--------------BEST WIN STREAK--------------"<<endl;
    L.BestWinstreak();
    cout<< "\n--------------BEST LOSE STREAK--------------"<<endl;
    L.Bestlosestreak();
    cout<< "\n--------------TEAMS WITH POSITIVE SCORE DIFF--------------"<<endl;
    L.PosScore();
    cout<< "\n--------------TEAM THAT SCORE THE MOST--------------"<<endl;
    L.ScoreTeam(true);
    cout<< "\n--------------TEAM THAT SCORE THE LAST--------------"<<endl;
    L.ScoreTeam(false);

 
    
}