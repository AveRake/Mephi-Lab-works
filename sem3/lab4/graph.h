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

            // Проверяем соседей вершины и присваиваем минимальный доступный цвет
            for (const T& neighbor : entry.second) {
                if (colorMap.find(neighbor) != colorMap.end()) {
                    usedColors.insert(colorMap[neighbor]);
                }
            }

            // Если вершина не имеет соседей, присваиваем ей цвет 1
            if (usedColors.empty()) {
                colorMap[vertex] = 1;
            } else {
                // Находим минимальный доступный цвет
                int color = 1;
                while (usedColors.find(color) != usedColors.end()) {
                    color++;
                }

                // Присваиваем цвет вершине
                colorMap[vertex] = color;
            }

            // Очищаем множество использованных цветов
            usedColors.clear();
        }

        // Выводим результат
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

            // Изменение: если достигли конечной вершины, выходим из цикла
            if (current == end) {
                break;
            }
        }

        // Вывод кратчайшего пути
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

        // Begin traversal from the selected vertex
        pathStack.push(start);

        while (!pathStack.empty()) {
            T current = pathStack.top();
            pathStack.pop();

            if (visited.find(current) == visited.end()) {
                visited.insert(current);
                resultPath.push_back(current);

                // Add unvisited neighbors to the stack
                for (const T& neighbor : adjacencyList[current]) {
                    if (visited.find(neighbor) == visited.end()) {
                        pathStack.push(neighbor);
                    }
                }
            }
        }

        // Add the starting vertex to complete the cycle
        resultPath.push_back(start);

        // Output the result
        std::cout << "Traveling Salesman Path starting from " << start << ": ";
        for (const T& vertex : resultPath) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    }

private:
    std::unordered_map<T, std::vector<T>> adjacencyList;
    bool directed;
};

#endif //LAB4_GRAPH_H
