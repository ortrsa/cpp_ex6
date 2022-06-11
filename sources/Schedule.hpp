#include <iostream>
#include <vector>
#include "Leauge.hpp"


using std::string;
using std::vector;
using std::invalid_argument;
using std::ostream;
namespace bball{
    class Schedule
    {
    private:
        /* data */
        Leauge* leauge;

    public:
        Schedule(Leauge* leauge);
        void runLeauge(bool toprint = false);
        
    };
    
    
    

}