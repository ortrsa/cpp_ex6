#include <iostream>
#include <vector>
#include <random>

#include"Team.hpp"

using std::string;
using std::vector;
using std::invalid_argument;
using std::ostream;
namespace bball{
    class Game
    {
    private:
        /* data */
        Team *Home;
        Team *Away;
        int scorehome;
        int scoreAway; 


    public:
        Game(Team *H, Team *A);
        void RunGame(bool toprint = false);
        static int getnormalscore(int from, int to);

    };

    
}