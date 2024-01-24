#include "graph.h"


void printDataType() {
    std::cout << "Choose the dataType" << std::endl;
    std::cout << "Press 1 for int" << std::endl;
    std::cout << "Press 2 for double" << std::endl;
    std::cout << "Press 3 for char" << std::endl;
    std::cout << ">>> ";
}

void printGraphType() {
    std::cout << "Choose the graphType" << std::endl;
    std::cout << "Press 1 for directed" << std::endl;
    std::cout << "Press 2 for undirected" << std::endl;
    std::cout << ">>> ";
}


void fillGraph() {
    std::cout << "Fill your graph" << std::endl;
    std::cout << "Press current and next edges " << std::endl;
}


template<typename T>
void processGraph(graph<T>& g, int methods, T firstEdges, T secondEdges) {
    switch (methods) {
        case 1:
            g.display();
            std::cout << std::endl;
            break;
        case 2:
            g.colorGraph();
            std::cout << std::endl;
            break;
        case 3:
            std::cout << "From what edge we will start find Shortest path = " ;
            std::cin >> firstEdges;
            std::cout << "To which edge will we look for a path = " ;
            std::cin >> secondEdges;

            if (g.shortestPath(firstEdges, secondEdges) != -1) {
                std::cout << "Shortest path distance: " << g.shortestPath(firstEdges, secondEdges) << std::endl;
            } else {
                std::cout << "No path exists." << std::endl;
            }
            std::cout << std::endl;

            break;
        case 4:
            std::cout << "From what edge Traveling Salesman Path will start = ";
            std::cin >> firstEdges;
            g.travelingSalesmanProblem(firstEdges);
            std::cout << std::endl;
            break;
        case 5:
            std::cout << "Connected Components:" << std::endl;
            g.connectedComponents();
            std::cout << std::endl;
            break;
        case 6:
            std::cout << "Graph Diameter: " << g.diameter() << std::endl;
            break;
        case 7:
            std::cout << "Vertex Count: " << g.vertexCount() << std::endl;
            break;
    }
}


int main() {
    std::cout << "Welcome to my programme" << std::endl;

    int dataType;
    printDataType();
    std::cin >> dataType;
    std::cout << std::endl;

    int graphType;
    bool directedOrNo;
    printGraphType();
    std::cin >> graphType;
    std::cout << std::endl;

    if (graphType == 1) {
        directedOrNo = true;
    } else {
        directedOrNo = false;
    }

    graph<int> integerGraph(directedOrNo);
    graph<double> doubleGraph(directedOrNo);
    graph<char> charGraph(directedOrNo);

    int currentEdge;
    int nextEdge;
    double currentEdgeDouble;
    double  nextEdgeDouble;
    char currentEdgeChar;
    char nextEdgeChar;
    int choice = 1;

    while (choice != 0) {
        fillGraph();
        if (dataType == 1) {
            std::cout << "current edge = ";
            std::cin >> currentEdge;
            std::cout << "next edge = ";
            std::cin >> nextEdge;
            integerGraph.addEdge(currentEdge, nextEdge);
        } else if (dataType == 2) {
            std::cout << "current edge = ";
            std::cin >> currentEdgeDouble;
            std::cout << "next edge = ";
            std::cin >> nextEdgeDouble;
            doubleGraph.addEdge(currentEdgeDouble, nextEdgeDouble);
        } else if (dataType == 3) {
            std::cout << "current edge = ";
            std::cin >> currentEdgeChar;
            std::cout << "next edge = ";
            std::cin >> nextEdgeChar;
            charGraph.addEdge(currentEdgeChar, nextEdgeChar);
        }

        std::cout << std::endl;
        std::cout << "If you want stop filling graph - press 0, else - 1" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;
    }

    int methods;
    choice = 1;
    while (choice != 0) {
        std::cout << "Choose the method for your graph" << std::endl;
        std::cout << "Press 1 for display your graph" << std::endl;
        std::cout << "Press 2 for coloring your graph" << std::endl;
        std::cout << "Press 3 for searching shortest path between edges in your graph" << std::endl;
        std::cout << "Press 4 to start traveling Salesman Problem" << std::endl;
        std::cout << "Press 5 to find connected Components in undirected graph" << std::endl;
        std::cout << "Press 6 to find diameter in your graph" << std::endl;
        std::cout << "Press 7 to find vertex count in your graph" << std::endl;
        std::cout << ">>> ";
        std::cin >> methods;
        std::cout << std::endl;

        switch (dataType) {
            case 1:
                processGraph(integerGraph, methods, currentEdge, nextEdge);
                break;
            case 2:
                processGraph(doubleGraph, methods, currentEdgeDouble, nextEdgeDouble);
                break;
            case 3:
                processGraph(charGraph, methods, currentEdgeChar, nextEdgeChar);
                break;
        }

        std::cout << "If you want stop programme - press 0, else - 1" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;
    }

    std::cout << "Press any bottom to end the programme" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    return 0;
}
