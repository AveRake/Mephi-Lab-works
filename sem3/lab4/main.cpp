#include "graph.h"


int main() {
    graph<double> directedGraph(7, true);
    directedGraph.addEdge(0.1, 1.1);
    directedGraph.addEdge(0.1, 2.1);
    directedGraph.addEdge(1.1, 3.1);
    directedGraph.addEdge(2.1, 4.1);
    directedGraph.addEdge(1.1, 5.1);
    directedGraph.addEdge(2.1, 6.1);

    std::cout << "Directed graph:" << std::endl;
    directedGraph.printGraph();
    directedGraph.colorGraph();
    directedGraph.solveTSP(0);


    int startVertex = 0;
    std::vector<int> distances = directedGraph.shortestPaths(startVertex);

    std::cout << "Shortest paths from the top " << startVertex << ":" << std::endl;
    for (int i = 0; i < distances.size(); ++i) {
        std::cout << "To the top " << i << ": " << distances[i] << std::endl;
    }


//    graph<int> undirectedGraph(5, false);
//    undirectedGraph.addEdge(0, 1);
//    undirectedGraph.addEdge(0, 2);
//    undirectedGraph.addEdge(1, 3);
//    undirectedGraph.addEdge(2, 4);
//
//    std::cout << "Undirected graph:" << std::endl;
//    undirectedGraph.printGraph();
//    undirectedGraph.colorGraph();
//    undirectedGraph.solveTSP(0);
//
//    distances = undirectedGraph.shortestPaths(startVertex);
//
//    std::cout << "Shortest paths from the top " << startVertex << ":" << std::endl;
//    for (int i = 0; i < distances.size(); ++i) {
//        std::cout << "To the top " << i << ": " << distances[i] << std::endl;
//    }

    return 0;
}
