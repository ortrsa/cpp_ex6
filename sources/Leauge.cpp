#include"Leauge.hpp"
const int MAXTEAMS = 20;
const int INF = 9999999;

/*NBA teams name*/
const vector<string> tname = {
"Atlanta Hawks"
,"Boston Celtics"
,"Brooklyn Nets"
,"Charlotte Hornets"
,"Chicago Bulls"
,"Cleveland Cavaliers"
,"Dallas Mavericks"
,"Denver Nuggets"
,"Detroit Pistons"
,"Golden State Warriors"
,"Houston Rockets"
,"Indiana Pacers"
,"Los Angeles Clippers"
,"Los Angeles Lakers"
,"Memphis Grizzlies"
,"Miami Heat"
,"Milwaukee Bucks"
,"Minnesota Timberwolves"
,"New Orleans Pelicans"
,"New York Knicks"
,"Oklahoma City Thunder"
,"Orlando Magic"
,"Philadelphia "
,"Phoenix Suns"
,"Portland Trail Blazers"
,"Sacramento Kings"
,"San Antonio Spurs"
,"Toronto Raptors"
,"Utah Jazz"
,"Washington Wizards"
};


namespace bball{
    // Init the leauge with given vector of teams.
    // This function will check for doplications and the vector size.
    // If thar are less than 20 teams it will add more teams.  
    Leauge::Leauge(const vector<Team*> &giventeams){
        if(havedop(giventeams)){
            throw invalid_argument("the team shuold be with uniqe names!");
        }
        int num_of_teams = giventeams.size();
        this->EndOfLeauge = false;
        this->Teams = giventeams;
        if(num_of_teams > MAXTEAMS){
            throw invalid_argument("Cant add more than 20 teams");
        }

        unsigned long counter = 0;
        while (num_of_teams< MAXTEAMS)
        {
            string name = tname.at(counter);
            if(this->name_is_avilable(name)){
                Team* newteam = new Team(name, ((double) rand()/ (RAND_MAX)));
                this->Teams.push_back(newteam);
                num_of_teams++;
            }
            counter ++;
            
        }
            
        

    }

    // init leauge with new teams.
    Leauge::Leauge(){
        int num_of_teams = 0;
        this->EndOfLeauge = false;
        
        unsigned long counter = 0;
        while (num_of_teams< MAXTEAMS)
        {
            string name = tname.at(counter);
            if(this->name_is_avilable(name)){
                Team* newteam = new Team(name, ((double) rand()/ (RAND_MAX)));
                this->Teams.push_back(newteam);
                num_of_teams++;
            }
            counter ++;
            
        }
            
        
        
    }

    //checing if new string name is free to use
    bool Leauge::name_is_avilable(const string &name){
            
            for (Team* t : this->Teams)
            {
                if(t->Getname() == name){
                    return false;
                }
            }
            return true;

    }
    // Check if given vector have name dupications. 
    bool Leauge::havedop(const vector<Team*> &giventeams){
        std::map<string, int> countmap;
        for (Team* te : giventeams)
        {
            countmap[te->Getname()]++;
            if(countmap[te->Getname()] > 1){
                return true;
            }
        }
        return false;
        
    }

    // --statistics-- return the "num" best team by Wins and Score diff
    void Leauge::BestTeam(int num){
        vector<Team*> teamvec = this->getTeams();
        if(!this->EndOfLeauge){
            throw invalid_argument("need to play games befor show statistics");
        }

        std::sort(teamvec.begin(), teamvec.end(), [](Team* lhs, Team* rhs) {
                if(lhs->getWins() == rhs->getWins()){
                    return (lhs->GetScoringTo() - lhs->GetGotScored()) > (rhs->GetScoringTo() - rhs->GetGotScored());
                }
                return lhs->getWins() > rhs->getWins();
        });
        
        for (Team* t : teamvec){
            num--;
            std::cout<< std::endl << t->Getname();
            std::cout<<"    Wins: "<< t->getWins();
            std::cout<<"    Score diff: " <<t->GetScoringTo() - t->GetGotScored();
            if(num == 0){
                break;
            }
             
        }
        std::cout<<std::endl;
    }
    // --statistics-- print the team with the best win streak
    void Leauge::BestWinstreak(){
        if(!this->EndOfLeauge){
            throw invalid_argument("need to play games befor show statistics");
        }

        int wStreak = 0;
        Team ans("a", 0);
        for (Team* t : this->getTeams()){
            if(wStreak < t->GetMaxWinstreak()){
                ans = (*t);
                wStreak = t->GetMaxWinstreak();
            }
            
             
        }
        std::cout<< "max win streak team: "<< ans.Getname()<< " with : " << ans.GetMaxWinstreak()<<std::endl;
    }
    // --statistics-- print the team with the best lose streak
    void Leauge::Bestlosestreak(){
        if(!this->EndOfLeauge){
            throw invalid_argument("need to play games befor show statistics");
        }

        int lStreak = 0;
        Team ans("a", 0);
        for (Team* t : this->getTeams()){
            if(lStreak < t->GetMaxLosestreak()){
                ans = (*t);
                lStreak = t->GetMaxLosestreak();
            }
            
             
        }
        std::cout<< "max lose streak team: "<< ans.Getname()<< " with : " << ans.GetMaxLosestreak()<<std::endl;
    }
    // --statistics-- print the number of teams with positive score rate.
    int Leauge::PosScore(){
        if(!this->EndOfLeauge){
            throw invalid_argument("need to play games befor show statistics");
        }

        int counter = 0;
        
        for (Team* t : this->getTeams()){
            if(t->GetScoringTo() > t->GetGotScored()){
                counter++;
            }
             
        }
        std::cout<< "there are: "<< counter << " teams with positive score rate" << std::endl;

        return counter;
    }
    // indicator for running games
    void Leauge::EndLeauge(){
            EndOfLeauge = true;
    }

    // --statistics-- if true print the team with the best score streak
    // --statistics-- if false print the team with the worst score streak
    void Leauge::ScoreTeam(bool best){
        if(!this->EndOfLeauge){
            throw invalid_argument("need to play games befor show statistics");
        }

        int maxs = 0;
        int mins = INF;
        Team ans("a", 0);
        if(best){
            for (Team* t : this->getTeams()){
                if(maxs< t->GetScoringTo()){
                    ans = (*t);
                    maxs = t->GetScoringTo();
                }
            }
            std::cout << "the team with the best scoring is: " << ans.Getname()<<" with: "<< ans.GetScoringTo() <<std::endl;
        }else{
            for (Team* t : this->getTeams()){
                if(mins> t->GetScoringTo()){
                    ans = (*t);
                    mins = t->GetScoringTo();
                }
            }

            std::cout << "the team with the worst scoring is: " << ans.Getname()<<" with: "<< ans.GetScoringTo()<<std::endl;
        }
    }
    
    int Leauge::size(){
            return this->Teams.size();
    }
    
    vector<Team*> Leauge::getTeams(){
            return Teams;
    }

    

}