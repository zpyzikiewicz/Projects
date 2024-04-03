#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include "funkcje.h"

void print_v(const std::vector<int>& v)
{
    for (const auto& i : v) std::cout << i << " ";
    std::cout << std::endl;
}

void print_f(const std::vector<int>& v, std::ofstream& fout)
{
    for (const auto& i : v) fout << i << " ";
    fout << std::endl;
}

void print_mv(const std::unordered_map<int, std::vector<int>>& mv)
{
    for (const auto& i : mv)
    {
        std::cout << i.first << ": ";
        for (const auto& v : i.second)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}


std::unordered_map<int, bool> visited_map1(std::unordered_map<int, std::vector<int>>& mv)
{
    std::vector<int> all;
    for (const auto& i : mv)
    {
        all.push_back(i.first);
        for (const auto& v : i.second)
        {
            all.push_back(v);
        }
    }
    std::unordered_map<int, bool> visited;
    for (const auto& i : all)
    {
        visited[i] = 0;
    }
    return visited;
}




void read(std::ifstream& fin, std::unordered_map<int, std::vector<int>>& graph1)
{
    int vertex1;
    int vertex2;
    char c;

    if (fin)
    {
        while (fin >> vertex1 >> c >> c >> vertex2)
        {
            graph1[vertex1].push_back(vertex2);

            fin >> c; //reading a coma
        }
        fin.close();
    }
}


//DFS algorithm
void DFS(std::unordered_map<int, std::vector<int>>& graph1, int v, int w,
    std::vector<int>& stack, std::unordered_map<int, bool>& visited, std::ofstream& fout)
{
    visited[w] = true;
    stack.push_back(w);
    for (const auto& u : graph1[w])
    {
        if (u == v)
        {
            print_v(stack);
            print_f(stack, fout);
        }
        if (visited[u] == false) DFS(graph1, v, u, stack, visited, fout);
    }
    visited[stack.back()] = false;
    stack.pop_back();
}