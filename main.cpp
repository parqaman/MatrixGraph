#include <iostream>
#include "Graph.h"

int main()
{
    Graph<std::string, 8> g1;

    g1.addVertex(0, "HAM");
    g1.addVertex(1, "FRA");
    g1.addVertex(2, "CGN");
    g1.addVertex(3, "MUC");
    g1.addVertex(4, "TXL");
    g1.addVertex(5, "STR");
    g1.addVertex(6, "DUS");
    g1.addVertex(7, "HAJ");

    //A
    g1.addEdge(0, 1, 14);
    g1.addEdge(0, 2, 4);
    g1.addEdge(0, 3, 2);
    g1.addEdge(0, 4, 8);
    g1.addEdge(0, 7, 16);

    //B
    g1.addEdge(1, 2, 11);
    g1.addEdge(1, 4, 15);

    //C
    g1.addEdge(2, 3, 4);
    g1.addEdge(2, 4, 5);

    //D
    g1.addEdge(3, 4, 6);
    g1.addEdge(3, 5, 15);
    g1.addEdge(3, 6, 7);
    g1.addEdge(3, 7, 14);

    //E
    g1.addEdge(4, 5, 10);

    //F
    g1.addEdge(5, 6, 9);

    //G
    g1.addEdge(6, 7, 8);

    try
    {
        int input;
        std::cout << "0 - HAM\n"
            << "1 - FRA\n"
            << "2 - CGN\n"
            << "3 - MUC\n"
            << "4 - TXL\n"
            << "5 - STR\n"
            << "6 - DUS\n"
            << "7 - HAJ\n";
        std::cout << "Start Flughafen-ID eingeben: ";
        std::cin >> input;
        std::cout << std::endl;
        g1.dijkstra(input);
    }
    catch (const std::string& e)
    {
        std::cout << e << std::endl;
    }
}
