#include "graph.h"


int main() {
    graph directedGraph(5, true);
    directedGraph.addEdge(0, 1);
    directedGraph.addEdge(0, 2);
    directedGraph.addEdge(1, 3);
    directedGraph.addEdge(2, 4);

    std::cout << "Directed graph:" << std::endl;
    directedGraph.printGraph();
    directedGraph.colorGraph();

    std::cout << std::endl;

    int startVertex = 0;
    std::vector<int> distances = directedGraph.shortestPaths(startVertex);

    std::cout << "Shortest paths from the top " << startVertex << ":" << std::endl;
    for (int i = 0; i < distances.size(); ++i) {
        std::cout << "To the top " << i << ": " << distances[i] << std::endl;
    }

    graph undirectedGraph(5, false);
    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(0, 2);
    undirectedGraph.addEdge(1, 3);
    undirectedGraph.addEdge(2, 4);

    std::cout << "Undirected graph:" << std::endl;
    undirectedGraph.printGraph();
    undirectedGraph.colorGraph();

    distances = undirectedGraph.shortestPaths(startVertex);

    std::cout << "Shortest paths from the top " << startVertex << ":" << std::endl;
    for (int i = 0; i < distances.size(); ++i) {
        std::cout << "To the top " << i << ": " << distances[i] << std::endl;
    }

    return 0;
}
