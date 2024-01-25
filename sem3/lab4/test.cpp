#include <iostream>
#include <cassert>
#include "graph.h"


int main() {
    // Тесты для graph с типом int
    {
        graph<int> g(false);

        g.addEdge(1, 2, 10);
        g.addEdge(2, 3, 10);
        g.addEdge(3, 4, 10);
        g.addEdge(1, 4, 50);
        std::vector<int> shortestPath;

        // Тест shortestPath
        assert(g.shortestPath(1, 3, shortestPath) == 20);
        shortestPath.clear();
        assert(g.shortestPath(1, 5, shortestPath) == 0);
        shortestPath.clear();

        // Тест vertexCount
        assert(g.vertexCount() == 4);

        // Тест diameter
        assert(g.diameter() == 60);

        // Тест isEmpty
        assert(!g.isEmpty());

        // Тест isDirected
        assert(!g.isDirected());

        graph<int> g1(false);

        // Добавляем большое количество вершин и ребер
        for (int i = 1; i <= 1000; ++i) {
            g1.addEdge(i, i % 1000 + 1);
        }

        // Тест vertexCount
        assert(g1.vertexCount() == 1000);

        // Тест diameter
        assert(g1.diameter() == 500);

        // Тест isEmpty
        assert(!g1.isEmpty());

        // Тест isDirected
        assert(!g1.isDirected());

        // Тест ориентированной версии
        graph<int> g2(true);

        g2.addEdge(1, 2, 1);
        g2.addEdge(2, 3, 1);
        g2.addEdge(3, 4, 1);
        g2.addEdge(4, 5, 1);
        g2.addEdge(5, 6, 1);
        g2.addEdge(6, 1, 1);

        // Тест shortestPath
        assert(g2.shortestPath(1, 2, shortestPath) == 1);
        shortestPath.clear();
        assert(g2.shortestPath(1, 5, shortestPath) != 0);
        shortestPath.clear();

        // Тест vertexCount
        assert(g2.vertexCount() == 6);

        // Тест diameter
        assert(g2.diameter() != 1);

        // Тест isEmpty
        assert(!g2.isEmpty());

        // Тест isDirected
        assert(g2.isDirected());
    }


    // Тесты для graph с типом double
    {
        graph<double> g(false);

        g.addEdge(1.1, 2.1);
        g.addEdge(2.1, 3.1);
        g.addEdge(3.1, 4.1);
        g.addEdge(1.1, 4.1);
        std::vector<double> shortestPath;

        // Тест shortestPath
        assert(g.shortestPath(1.1, 4.1, shortestPath) == 1);
        shortestPath.clear();
        assert(g.shortestPath(1.1, 5.1, shortestPath) == 0);
        shortestPath.clear();

        // Тест vertexCount
        assert(g.vertexCount() == 4);

        // Тест diameter
        assert(g.diameter() == 2);

        // Тест isEmpty
        assert(!g.isEmpty());

        // Тест isDirected
        assert(!g.isDirected());

        graph<double> g1(false);

        // Добавляем большое количество вершин и ребер
        for (int i = 1; i <= 1000; ++i) {
            g1.addEdge(i * 0.5, (i % 1000 + 1) * 0.5);
        }

        // Тест vertexCount
        assert(g1.vertexCount() == 1000);

        // Тест diameter
        assert(g1.diameter() == 500);

        // Тест isEmpty
        assert(!g1.isEmpty());

        // Тест isDirected
        assert(!g1.isDirected());

        // Тест ориентированной версии
        graph<double> g2(true);

        g2.addEdge(1.1, 2.1);
        g2.addEdge(2.1, 3.1);
        g2.addEdge(3.1, 4.1);
        g2.addEdge(1.1, 4.1);

        // Тест vertexCount
        assert(g2.vertexCount() == 4);

        // Тест isEmpty
        assert(!g2.isEmpty());

        // Тест isDirected
        assert(g2.isDirected());
    }


    // Тесты для graph с типом string
    {
        graph<std::string> g(false);

        g.addEdge("A", "B");
        g.addEdge("B", "C");
        g.addEdge("C", "D");
        g.addEdge("A", "D");
        std::vector<std::string> shortestPath;

        // Тест shortestPath
        assert(g.shortestPath("A", "D", shortestPath) == 1);
        shortestPath.clear();
        assert(g.shortestPath("A", "E", shortestPath) == 0);
        shortestPath.clear();

        // Тест vertexCount
        assert(g.vertexCount() == 4);

        // Тест diameter
        assert(g.diameter() == 2);

        // Тест isEmpty
        assert(!g.isEmpty());

        // Тест isDirected
        assert(!g.isDirected());

        graph<std::string> g1(false);

        // Добавляем большое количество вершин и ребер
        for (int i = 1; i <= 1000; ++i) {
            g1.addEdge("Node" + std::to_string(i), "Node" + std::to_string(i % 1000 + 1));
        }

        // Тест vertexCount
        assert(g1.vertexCount() == 1000);

        // Тест diameter
        assert(g1.diameter() == 500);

        // Тест isEmpty
        assert(!g1.isEmpty());

        // Тест isDirected
        assert(!g1.isDirected());

        // Тест ориентированной версии
        graph<std::string> g2(true);

        g2.addEdge("A", "B");
        g2.addEdge("B", "C");
        g2.addEdge("C", "D");
        g2.addEdge("A", "D");

        // Тест shortestPath
        assert(g2.shortestPath("A", "D", shortestPath) != 2);
        shortestPath.clear();
        assert(g2.shortestPath("A", "E", shortestPath) == 0);
        shortestPath.clear();

        // Тест vertexCount
        assert(g2.vertexCount() == 4);

        // Тест isEmpty
        assert(!g2.isEmpty());

        // Тест isDirected
        assert(g2.isDirected());

    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Tests for int with large graph passed!" << std::endl;
    std::cout << "Tests for int passed!" << std::endl;
    std::cout << std::endl;

    std::cout << "Tests for double with large graph passed!" << std::endl;
    std::cout << "Tests for double passed!" << std::endl;
    std::cout << std::endl;

    std::cout << "Tests for std::string with large graph passed!" << std::endl;
    std::cout << "Tests for string passed!" << std::endl;
    std::cout << std::endl;

    return 0;
}
