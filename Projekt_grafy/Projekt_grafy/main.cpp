#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include "funkcje.h"


int main(int argc, char* argv[])
{
    using std::endl;
    using std::cout;

    std::string s, ifname, ofname;
    bool found_g = 0;
    bool found_c = 0;

    for (int i = 0; i < argc; ++i)
    {
        s = argv[i];
        if (s == "-g")
        {
            ifname = argv[i + 1];
            found_g = 1;
        }
        if (s == "-c")
        {
            ofname = argv[i + 1];
            found_c = 1;
        }

    }

    if (!found_g || !found_c)
    {
        cout << endl << "Run the program in the command line. Use parameters: " << endl
            << "-g input file with graph" << endl << "-c output file with cycles." << endl;
        return 0;
    }

    std::ifstream fin(ifname);
    std::ofstream fout(ofname);

    //structure
    std::unordered_map<int, std::vector<int>> graph1;
    read(fin, graph1);
    cout << "Graf: " << endl;
    print_mv(graph1);

    //visited
    std::unordered_map<int, bool> visited = visited_map1(graph1);

    //stack
    std::vector<int> stack;


    //DFS
    cout << endl << "Cykle: " << endl;

    for (const auto& g : graph1)
    {
        DFS(graph1, g.first, g.first, stack, visited, fout);
        visited[g.first] = true;
    }
}