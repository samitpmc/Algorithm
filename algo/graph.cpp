
#include "stdafx.h"
#include "graph.h"

///////////////////////////////////////////////////////////////////////////////
Graph::Graph(DWORD numVertex) : m_vertex(numVertex)
{
    m_adjacentNode = new std::list<DWORD>[m_vertex];
}
///////////////////////////////////////////////////////////////////////////////
void Graph::AddEdge(DWORD rootNode, DWORD adjacentNode)
{
    m_adjacentNode[rootNode].push_back(adjacentNode);
}
///////////////////////////////////////////////////////////////////////////////
void Graph::DFS(DWORD root)
{
    std::vector<bool> visited(m_vertex, false);

    std::stack<DWORD> stk;
    visited[root] = true;
    stk.push(root);

    while (!stk.empty())
    {
        DWORD top = stk.top();
        std::cout << top << std::endl;
        stk.pop();

        // Iterate all the adjacent nodes

        std::list<DWORD>::iterator iter;

        for (iter = m_adjacentNode[top].begin(); iter != m_adjacentNode[top].end(); ++iter)
        {
            if (!visited[*iter])
            {
                visited[*iter] = true;
                stk.push(*iter);
            }
        }
    }
}
///////////////////////////////////////////////////////////////////////////////
void Graph::BFS(DWORD root)
{
    std::vector<bool> visited(m_vertex, false);

    std::list <DWORD> queue;
    visited[root] = true;
    queue.push_back(root);

    while (!queue.empty())
    {
        DWORD top = queue.front();
        std::cout << top << std::endl;
        queue.pop_front();

        // Iterate all the adjacent nodes

        std::list<DWORD>::iterator iter;

        for (iter = m_adjacentNode[top].begin(); iter != m_adjacentNode[top].end(); ++iter)
        {
            if (!visited[*iter])
            {
                visited[*iter] = true;
                queue.push_back(*iter);
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
void Graph::TopologicalSortUtil(DWORD node, std::stack<DWORD> & stk, std::vector<bool> & visited)
{
    visited[node] = true;

    std::list<DWORD>::iterator iter;
    for (iter = m_adjacentNode[node].begin(); iter != m_adjacentNode[node].end(); ++iter)
    {
        if (!visited[*iter])
            TopologicalSortUtil(*iter, stk, visited);
    }
    stk.push(node);
}
///////////////////////////////////////////////////////////////////////////////
void Graph::TopologicalSort()
{
    std::stack<DWORD> stk;

    std::vector<bool> visited(m_vertex, false);

    // Get all the adjacent nodes of root

    for (auto x = 0; x < m_vertex; ++x)
    {
        if (!visited[x])
            TopologicalSortUtil(x, stk, visited);
    }

    while (!stk.empty())
    {
        std::cout << stk.top() << std::endl;
        stk.pop();
    }
    // Print stack elements
}
///////////////////////////////////////////////////////////////////////////////
void Graph::BFS1(DWORD root)
{
    std::vector<bool> visited(m_vertex, false); // Initailize all vertex as not visited

    std::list<DWORD> queue;

    queue.push_back(root);
    visited[root] = true;

    while (!queue.empty())
    {
        // traverse all adjacanet node
        DWORD top = queue.front();
        std::cout << top << std::endl;
        queue.pop_front();

        for (auto iter = m_adjacentNode[top].begin(); iter != m_adjacentNode[top].end(); ++iter)
        {
            DWORD node = *iter;
            if (visited[node] != true)
            {
                queue.push_back(node);
                visited[node] = true;
            }
        }

    }

    // get the root element;

}

