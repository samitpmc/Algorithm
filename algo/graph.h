
#include "stdafx.h"

class Graph
{
    DWORD m_vertex = 0;
    std::list<DWORD> *m_adjacentNode = nullptr;
private:
    void TopologicalSortUtil(DWORD node, std::stack<DWORD> & stk, std::vector<bool> & visited);

public:
    Graph(DWORD numVertex);
    void AddEdge(DWORD rootNode, DWORD adjacentNode);
    void DFS(DWORD root);
    void BFS(DWORD root);
    void BFS1(DWORD root);
    void TopologicalSort();

};
