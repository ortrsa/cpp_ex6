#include "doctest.h"
#include"Schedule.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using std::string;
using std::vector;
using std::endl;
using std::cout;
const int INF = 999999;  
using namespace bball;


TEST_CASE("Team Checks") {
    // try to add empty name
    CHECK_THROWS(Team T1 = Team("", 0.5));

    //try to add skill more than 1
    CHECK_THROWS(Team T1 = Team("a", 2));
    
    //try to add skill less than 0
    CHECK_THROWS(Team T1 = Team("a", -5));

    //try to add 2 teams with the same name to leauge
    vector<Team*> same_name_team;
    for (size_t i = 0; i < 2; i++)
    {
        same_name_team.push_back(new Team("name", 0.2));
    }
    CHECK_THROWS( Leauge same_name_leauge = Leauge(same_name_team));

}

TEST_CASE("Leauge Checks") {
    
    // Check if there is excectly 20 Teams in leauge:
    Leauge L1 = Leauge();
    vector<Team*> teams1 = L1.getTeams();
    CHECK(teams1.size() == 20);

    // enter 20 teams to Leauge
    vector<Team*> teams2;
    for (size_t i = 0; i < 20; i++)
    {
        string name = std::to_string(i);
        teams2.push_back(new Team(name, 0.2));

    }
    Leauge L2 = Leauge(teams2);
    CHECK(L2.size() == 20);

    // Try to enter more than 20 teams to Leauge
    vector<Team*> teams3;
    for (size_t i = 0; i < 22; i++)
    {
        string name = std::to_string(i);
        teams3.push_back(new Team(name, 0.2));

    }
    CHECK_THROWS( Leauge L3 = Leauge(teams3));

    // Adding less than 20 teams and the constractor will add teams automaticly.
    vector<Team*> teams4;
    for (size_t i = 0; i < 5; i++)
    {
        string name = std::to_string(i);
        teams4.push_back(new Team(name, 0.2));

    }
    Leauge L4 = Leauge(teams4);
    CHECK(L4.size() == 20); 
    

    // checking that the teams that add automaticly have  0 <= skill <= 1
    vector<Team*> teams5 = L4.getTeams();
    for (size_t i = 0; i < 20; i++)
    {
        Team* team = teams5.at(i);
        CHECK(team->Getskill() <= 1);
        CHECK(team->Getskill() >= 0);
    }


    
    
}

TEST_CASE("Game Checks"){

    Team hometeam = Team("h_team", 0.5);
    Team awayteam = Team("a_team", 0.5);

    // team cnnot play vs itself
    CHECK_THROWS( Game fail_game = Game(&hometeam, &hometeam));

    // run normal game
    Game normal_game = Game(&hometeam, &awayteam);
    std::cout<< "-----------This is Game result-----------\n" << std::endl;
    CHECK_NOTHROW( normal_game.RunGame(true));
    std::cout<< "-----------------------------------------" << std::endl;

    // check that the score is in normal range
    int maxscore = 0;
    int minscore = INF;
    for (size_t i = 0; i < 100; i++)
    {
        
        int rnd_score = normal_game.getnormalscore(50,100);
        if(rnd_score < minscore){
            minscore = rnd_score;
        }
        if(rnd_score > maxscore){
            maxscore = rnd_score;
        }
    }
    CHECK(maxscore <= 100);
    CHECK(minscore >= 50);


    maxscore = 0;
    minscore = INF;
    for (size_t i = 0; i < 100; i++)
    {
        
        int rnd_score = normal_game.getnormalscore(55,100);
        if(rnd_score < minscore){
            minscore = rnd_score;
        }
        if(rnd_score > maxscore){
            maxscore = rnd_score;
        }
    }
    CHECK(maxscore <= 100);
    CHECK(minscore >= 50);



}
TEST_CASE("Schedule Checks"){
    
    Leauge leauge_s_test = Leauge();
    Schedule s = Schedule(&leauge_s_test);

    //Try to see statistics before runing games
    CHECK_THROWS(leauge_s_test.BestWinstreak());
    CHECK_THROWS(leauge_s_test.Bestlosestreak());
    CHECK_THROWS(leauge_s_test.PosScore());
    
    CHECK_THROWS(leauge_s_test.BestTeam(3));
    CHECK_THROWS(leauge_s_test.ScoreTeam(/*false is the team with the worst scoring*/false));
    CHECK_THROWS(leauge_s_test.ScoreTeam(/*true is the team with the best scoring*/true));

    s.runLeauge(/*print games parameter*/ false);
    std::cout<< "-----------------------------------------" << std::endl;
    CHECK_NOTHROW(leauge_s_test.BestWinstreak());
    std::cout<< "-----------------------------------------" << std::endl;
    CHECK_NOTHROW(leauge_s_test.Bestlosestreak());
    std::cout<< "-----------------------------------------" << std::endl;
    CHECK_NOTHROW(leauge_s_test.PosScore());
    std::cout<< "-----------------------------------------" << std::endl;
    CHECK_NOTHROW(leauge_s_test.BestTeam(5));
    std::cout<< "-----------------------------------------" << std::endl;
    CHECK_NOTHROW(leauge_s_test.ScoreTeam(false));
    std::cout<< "-----------------------------------------" << std::endl;
    CHECK_NOTHROW(leauge_s_test.ScoreTeam(true));
    

    


}

    


