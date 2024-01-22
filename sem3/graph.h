#ifndef LAB4_GRAPH_H
#define LAB4_GRAPH_H
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <queue>


class graph {
private:
    int vertices;
    bool isDirected;
    std::vector<std::list<int>> adjacencyList;

public:
    graph(int vertices, bool isDirected) : vertices(vertices), isDirected(isDirected) {
        adjacencyList.resize(vertices);
    }


    void addEdge(int from, int to) {
        adjacencyList[from].push_back(to);

        if (!isDirected) {
            adjacencyList[to].push_back(from);
        }
    }


    void printGraph() {
        for (int i = 0; i < vertices; ++i) {
            std::cout << "Vertex " << i << ": ";
            for (const auto& neighbor : adjacencyList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }


    void colorGraph() {
        std::vector<int> colors(vertices, -1);
        std::set<int> availableColors;

        for (int vertex = 0; vertex < vertices; ++vertex) {
            for (const auto& neighbor : adjacencyList[vertex]) {
                if (colors[neighbor] != -1) {
                    availableColors.insert(colors[neighbor]);
                }
            }

            auto it = availableColors.begin();
            int chosenColor = 0;
            while (it != availableColors.end() && *it == chosenColor) {
                ++it;
                ++chosenColor;
            }

            colors[vertex] = chosenColor;
            availableColors.clear();
        }

        std::cout << "Graph coloring page:" << std::endl;
        for (int i = 0; i < vertices; ++i) {
            std::cout << "Vertex " << i << " painted in color " << colors[i] << std::endl;
        }
    }


    std::vector<int> shortestPaths(int startVertex) {
        std::vector<int> distances(vertices, -1);
        distances[startVertex] = 0;

        std::queue<int> bfsQueue;
        bfsQueue.push(startVertex);

        while (!bfsQueue.empty()) {
            int currentVertex = bfsQueue.front();
            bfsQueue.pop();

            for (const auto& neighbor : adjacencyList[currentVertex]) {
                if (distances[neighbor] == -1) {
                    distances[neighbor] = distances[currentVertex] + 1;
                    bfsQueue.push(neighbor);
                }
            }
        }

        return distances;
    }
};


#endif //LAB4_GRAPH_H
