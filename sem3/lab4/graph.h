#ifndef LAB4_GRAPH_H
#define LAB4_GRAPH_H
#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#include <unordered_set>
#include <stack>
#include <list>
#include <algorithm>


template <typename T, typename W = int>
class graph {
public:
    explicit graph(bool directed = true) : directed(directed) {}

    void addEdge(const T& u, const T& v, const W& weight = 1) {
        adjacencyList[u].push_back({v, weight});
        if (!directed) {
            adjacencyList[v].push_back({u, weight});
        }
    }

    void display() const {
        for (const auto& entry : adjacencyList) {
            std::cout << entry.first << ": ";
            for (const auto& neighbor : entry.second) {
                std::cout << neighbor.first << " (Weight: " << neighbor.second << ") ";
            }
            std::cout << std::endl;
        }
    }

    void colorGraph() {
        std::unordered_map<T, int> colorMap;
        std::set<int> usedColors;

        for (const auto& entry : adjacencyList) {
            T vertex = entry.first;

            for (const auto& neighbor : entry.second) {
                if (colorMap.find(neighbor.first) != colorMap.end()) {
                    usedColors.insert(colorMap[neighbor.first]);
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

    int shortestPath(const T& start, const T& end, std::vector<T>& path) {
        std::unordered_map<T, W> distance;
        std::unordered_map<T, T> parent;
        std::queue<T> q;

        for (const auto& entry : adjacencyList) {
            distance[entry.first] = std::numeric_limits<W>::max();
            parent[entry.first] = T();
        }

        distance[start] = 0;
        q.push(start);

        while (!q.empty()) {
            T current = q.front();
            q.pop();

            for (const auto& neighbor : adjacencyList[current]) {
                if (distance[current] + neighbor.second < distance[neighbor.first]) {
                    distance[neighbor.first] = distance[current] + neighbor.second;
                    parent[neighbor.first] = current;
                    q.push(neighbor.first);
                }
            }

            if (current == end) {
                break;
            }
        }

        if (distance[end] != std::numeric_limits<W>::max()) {
            // Reconstruct path
            path.clear();
            T current = end;
            while (current != T()) {
                path.push_back(current);
                current = parent[current];
            }
            std::reverse(path.begin(), path.end());

            // Output the path
            std::cout << "Shortest Path from " << start << " to " << end << ": ";
            for (const T& vertex : path) {
                std::cout << vertex << " ";
            }
            std::cout << "(Distance: " << distance[end] << ")" << std::endl;

            return distance[end];
        } else {
            std::cout << "No path found from " << start << " to " << end << std::endl;
            return -1;
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

                for (const auto& neighbor : adjacencyList[current]) {
                    if (visited.find(neighbor.first) == visited.end()) {
                        pathStack.push(neighbor.first);
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

    [[nodiscard]] int vertexCount() const {
        std::unordered_set<T> uniqueVertices;

        for (const auto& entry : adjacencyList) {
            uniqueVertices.insert(entry.first);
            for (const auto& neighbor : entry.second) {
                uniqueVertices.insert(neighbor.first);
            }
        }

        return uniqueVertices.size();
    }

    [[nodiscard]] int diameter() const {
        int maxDiameter = 0;

        for (const auto& entry : adjacencyList) {
            T startVertex = entry.first;
            std::unordered_map<T, W> distance;

            std::queue<T> q;
            q.push(startVertex);
            distance[startVertex] = 0;

            while (!q.empty()) {
                T current = q.front();
                q.pop();

                for (const auto& neighbor : adjacencyList.at(current)) {
                    if (distance.find(neighbor.first) == distance.end()) {
                        distance[neighbor.first] = distance[current] + neighbor.second;
                        q.push(neighbor.first);
                    }
                }
            }

            int maxDistance = 0;
            for (const auto& entry : distance) {
                maxDistance = std::max(maxDistance, static_cast<int>(entry.second));
            }

            maxDiameter = std::max(maxDiameter, maxDistance);
        }

        return maxDiameter;
    }

    [[nodiscard]] bool isEmpty() const {
        return adjacencyList.empty();
    }

    [[nodiscard]] bool isDirected() const {
        return directed;
    }

private:
    std::unordered_map<T, std::list<std::pair<T, W>>> adjacencyList;
    bool directed;

    void dfsConnectedComponents(const T& vertex, std::unordered_set<T>& visited) {
        visited.insert(vertex);
        std::cout << vertex << " ";

        for (const auto& neighbor : adjacencyList[vertex]) {
            if (visited.find(neighbor.first) == visited.end()) {
                dfsConnectedComponents(neighbor.first, visited);
            }
        }
    }
};

#endif //LAB4_GRAPH_H
