#include "controller.hxx"

#include <stdexcept>

#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
try
{
    int num_players;
    switch(argc)
    {
    case 1:
        num_players = 4;
        break;
    case 2:
        num_players = std::stoi(argv[1]);
        if(num_players>4 || num_players<0)
            num_players = 4;
        break;
    default:
        cerr << "Usage: " << argv[0] << " Number of Players\n";
        return 1;
    }
    Controller(num_players).run();
}
catch (exception const& e)
{
    cerr << argv[0] << ": " << e.what() << "\n";
    return 1;
}