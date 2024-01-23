#ifndef LAB4_GRAPH_H
#define LAB4_GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <queue>


template <typename T>
class graph {
private:
    int vertices;
    bool isDirected;
    std::vector<std::vector<T>> adjacencyList;

public:
    graph(int vertices, bool isDirected) : vertices(vertices), isDirected(isDirected) {
        adjacencyList.resize(vertices);
    }

    void addEdge(T from, T to) {
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

        for (int vertex = 0; vertex < vertices; ++vertex) {
            std::set<int> availableColors;

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

    void solveTSP(int startVertex) {
        std::vector<bool> visited(vertices, false);
        std::vector<int> path;
        int totalDistance = 0;

        int currentVertex = startVertex;
        path.push_back(currentVertex);
        visited[currentVertex] = true;

        while (path.size() < vertices) {
            int nearestNeighbor = -1;
            int minDistance = std::numeric_limits<int>::max();

            for (const auto& neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor] && minDistance > 1) {
                    nearestNeighbor = neighbor;
                    minDistance = 1;
                }
            }

            if (nearestNeighbor != -1) {
                path.push_back(nearestNeighbor);
                visited[nearestNeighbor] = true;
                totalDistance += 1;
                currentVertex = nearestNeighbor;
            } else {
                bool allVisited = true;
                for (int i = 0; i < vertices; ++i) {
                    if (!visited[i]) {
                        allVisited = false;
                        break;
                    }
                }

                if (allVisited) {
                    break;
                }

                for (int i = 0; i < vertices; ++i) {
                    if (!visited[i]) {
                        currentVertex = i;
                        path.push_back(currentVertex);
                        visited[currentVertex] = true;
                        break;
                    }
                }

                totalDistance += 1;
            }
        }

        std::cout << "Approximate solution to the traveling salesman problem (nearest neighbor method): " << std::endl;
        std::cout << "Path: ";
        for (const auto& vertex : path) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
        std::cout << "Total distance: " << totalDistance << std::endl;
    }
};


#endif //LAB4_GRAPH_H
