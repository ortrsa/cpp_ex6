#include <iostream>
#include <vector>
#include <map>
#include "Game.hpp"

using std::string;
using std::vector;
using std::invalid_argument;
using std::ostream;
#include<algorithm>

namespace bball{
    class Leauge
    {
    private:
        /* data */
        vector<Team*> Teams;
        bool EndOfLeauge;
    public:
        Leauge(const vector<Team*> &giventeams);
        Leauge();

        bool name_is_avilable(const string &name);

        void EndLeauge();

        void BestTeam(int num);
        void BestWinstreak();
        void Bestlosestreak();
        int PosScore();
        void ScoreTeam(bool best);
        vector<Team*> getTeams();
        int size();
        bool havedop(const vector<Team*> &giventeams);
    };

}