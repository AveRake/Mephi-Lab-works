#include "graph.h"


int main() {
    graph<char> undirectedGraph(true);

    undirectedGraph.addEdge('A', 'B');
    undirectedGraph.addEdge('A', 'C');
    undirectedGraph.addEdge('B', 'D');
    undirectedGraph.addEdge('C', 'D');

    undirectedGraph.shortestPath('A', 'D');
    undirectedGraph.travelingSalesmanProblem('A');


    graph<int> directedGraph(true);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(2, 3);
    directedGraph.addEdge(3, 4);
    directedGraph.addEdge(4, 1);

    directedGraph.travelingSalesmanProblem(1);
    directedGraph.travelingSalesmanProblem(3);

    return 0;
}
