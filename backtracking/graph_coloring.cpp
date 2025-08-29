/**
 * @file       graph_coloring.cpp
 * @brief      
 * @date       2025/08/26
 * @author     [Gentantun] (nguyenthanhtung8196@gmail.com)
 * @details    
 *              In graph theory, graph coloring is a special case of graph labeling;
 *              it is an assignment of labels traditionally called "colors" to elements of a 
 *              graph subject to certain constraints. In its simplest form, it is a way of 
 *              coloring the vertices of a graph such that no two adjacent vertices are of 
 *              the same color; this is called a vertex coloring. Similarly, an edge coloring 
 *              assign a color to each edge so that no two adjacent edges are of the same
 *              color, and a face coloring of a planer graph assigns a color to each face or 
 *              region so that no two faces that share a boundary have the same color.
 * @ref        
 * @copyright  Copyright (c) 2025 Robotun
*/

#include <iostream>
#include <array>

namespace backtracking
{

namespace graph_coloring
{

template <size_t V>
void printfSolution(const std::array<int, V>& color)
{
    std::cout << "Following are the assigned colors\n" ;
    for (auto& col : color)
    {
        std::cout << col;
    }
    std::cout << "\n";
}

template <size_t V>
bool isSafe(int v, const std::array<std::array<int , V>, V>& graph,
            const std::array<int, V>& color, int c)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && c == color[i])
        {
            return false;
        }
    }
    return true;
}


template <size_t V>
void Solve(const std::array<std::array<int , V>, V>& graph, int m,
            std::array<int, V> color, int v)
{
    /* Recursive exit condition */
    
    if (v == V)
    {
        printfSolution<V>(color);
        return ;
    }

    /* Recursive */
    for (size_t i = 1; i <= m; i++)
    {
        /* code */
        if (isSafe<V>(v, graph, color, i))
        {
            color[v] = i;
            Solve<V>(graph, m, color, v + 1);

            color[v] = 0;
        }
    }
    
}


}   // graph_coloring 
}   // backtracking

int main()
{
    const int V = 4;   /* Number of vertices */
    std::array<std::array<int , V>, V> m_graph = {
        std::array<int, V>({0, 1, 1, 1}), std::array<int, V>({1, 0, 1, 0}),
        std::array<int, V>({1, 1, 0, 1}), std::array<int, V>({1, 0, 1, 0})
    };
    /* Number of colors */
    int m = 3;
    std::array<int, V> color{};

    backtracking::graph_coloring::Solve<V>(m_graph, m, color, 0);

    return 0;
}



