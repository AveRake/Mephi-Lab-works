#ifndef LAB4_GRAPH_H
#define LAB4_GRAPH_H
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <queue>
#include <unordered_set>
#include <stack>


template <typename T>
class graph {
public:
    explicit graph(bool directed = true) : directed(directed) {}

    void addEdge(const T& u, const T& v) {
        adjacencyList[u].push_back(v);
        if (!directed) {
            adjacencyList[v].push_back(u);
        }
    }

    void display() const {
        for (const auto& entry : adjacencyList) {
            std::cout << entry.first << ": ";
            for (const T& neighbor : entry.second) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    void colorGraph() {
        std::unordered_map<T, int> colorMap;
        std::set<int> usedColors;

        for (const auto& entry : adjacencyList) {
            T vertex = entry.first;

            for (const T& neighbor : entry.second) {
                if (colorMap.find(neighbor) != colorMap.end()) {
                    usedColors.insert(colorMap[neighbor]);
                }
            }

            if (usedColors.empty()) {
                colorMap[vertex] = 1;
            } else {
                int color = 1;
                while (usedColors.find(color) != usedColors.end()) {
                    color++;
                }

                colorMap[vertex] = color;
            }

            usedColors.clear();
        }

        for (const auto& entry : colorMap) {
            std::cout << entry.first << " is colored with color " << entry.second << std::endl;
        }
    }


    void shortestPath(const T& start, const T& end) {
        std::unordered_map<T, int> distance;
        std::unordered_map<T, T> parent;
        std::queue<T> q;

        for (const auto& entry : adjacencyList) {
            distance[entry.first] = std::numeric_limits<int>::max();
            parent[entry.first] = T();
        }

        distance[start] = 0;
        q.push(start);

        while (!q.empty()) {
            T current = q.front();
            q.pop();

            for (const T& neighbor : adjacencyList[current]) {
                if (distance[current] + 1 < distance[neighbor]) {
                    distance[neighbor] = distance[current] + 1;
                    parent[neighbor] = current;
                    q.push(neighbor);
                }
            }

            if (current == end) {
                break;
            }
        }

        std::cout << "Shortest path from " << start << " to " << end << ": ";
        std::vector<T> path;
        T current = end;
        while (current != T()) {
            path.insert(path.begin(), current);
            current = parent[current];
        }

        if (path.size() > 1) {
            for (const T& vertex : path) {
                std::cout << vertex << " ";
            }
            std::cout << "(Distance: " << distance[end] << ")" << std::endl;
        } else {
            std::cout << "No path from " << start << " to " << end << " exists." << std::endl;
        }
    }

    void travelingSalesmanProblem(const T& start) {
        std::unordered_set<T> visited;
        std::stack<T> pathStack;
        std::vector<T> resultPath;
        pathStack.push(start);

        while (!pathStack.empty()) {
            T current = pathStack.top();
            pathStack.pop();

            if (visited.find(current) == visited.end()) {
                visited.insert(current);
                resultPath.push_back(current);

                for (const T& neighbor : adjacencyList[current]) {
                    if (visited.find(neighbor) == visited.end()) {
                        pathStack.push(neighbor);
                    }
                }
            }
        }

        resultPath.push_back(start);
        std::cout << "Traveling Salesman Path starting from " << start << ": ";
        for (const T& vertex : resultPath) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    }

    void connectedComponents() {
        std::unordered_set<T> visited;
        int componentCount = 0;

        for (const auto& entry : adjacencyList) {
            T vertex = entry.first;
            if (visited.find(vertex) == visited.end()) {
                std::cout << "Connected Component " << ++componentCount << ": ";
                dfsConnectedComponents(vertex, visited);
                std::cout << std::endl;
            }
        }
    }

private:
    std::unordered_map<T, std::vector<T>> adjacencyList;
    bool directed;

    void dfsConnectedComponents(const T& vertex, std::unordered_set<T>& visited) {
        visited.insert(vertex);
        std::cout << vertex << " ";

        for (const T& neighbor : adjacencyList[vertex]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsConnectedComponents(neighbor, visited);
            }
        }
    }
};

#endif //LAB4_GRAPH_H