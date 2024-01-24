#include <iostream>
#include <cassert>
#include "graph.h"


int main() {
    // Тесты для graph с типом int
    {
        graph<int> g(false);

        g.addEdge(1, 2);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        g.addEdge(1, 4);

        // Тест shortestPath
        assert(g.shortestPath(1, 4) == 1);
        assert(g.shortestPath(1, 5) == 0);

        // Тест vertexCount
        assert(g.vertexCount() == 4);

        // Тест diameter
        assert(g.diameter() == 2);

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

        std::cout << "Tests for int with large graph passed!" << std::endl;
        std::cout << "Tests for int passed!" << std::endl;
        std::cout << std::endl;
    }

    // Тесты для graph с типом double
    {
        graph<double> g(false);

        g.addEdge(1.0, 2.0);
        g.addEdge(2.0, 3.0);
        g.addEdge(3.0, 4.0);
        g.addEdge(1.0, 4.0);

        // Тест shortestPath
        assert(g.shortestPath(1.0, 4.0) == 1);
        assert(g.shortestPath(1.0, 5.0) == 0);

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

        std::cout << "Tests for double with large graph passed!" << std::endl;
        std::cout << "Tests for double passed!" << std::endl;
        std::cout << std::endl;
    }

    // Тесты для graph с типом string
    {
        graph<std::string> g(false);

        g.addEdge("A", "B");
        g.addEdge("B", "C");
        g.addEdge("C", "D");
        g.addEdge("A", "D");

        // Тест shortestPath
        assert(g.shortestPath("A", "D") == 1);
        assert(g.shortestPath("A", "E") == 0);

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

        std::cout << "Tests for std::string with large graph passed!" << std::endl;
        std::cout << "Tests for string passed!" << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
