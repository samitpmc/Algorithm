// algo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "graph.h"
#include "tree.h"
#include "dp.h"
#include "array.h"

using namespace std;

void FindODD()
{
    int array1[] = { 1,1,2,2,3,3,5,5000,4,5,5,4,5,1,1 };

    int x = 0;
    for (auto i = 0; i < sizeof(array1) / sizeof(array1[0]); ++i)
        x = x^array1[i];

    std::cout << "odd number"<< x << std::endl;

}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

#define INF INT_MAX 
#define N 7 

// This function returns the smallest possible cost to 
// reach station N-1 from station 0. 
int minCost(int cost[][N])
{
    // dist[i] stores minimum cost to reach station i 
    // from station 0. 
    int dist[N];
    for (int i = 0; i<N; i++)
        dist[i] = INF;
    dist[0] = 0;

    // Go through every station and check if using it 
    // as an intermediate station gives better path 
    for (int i = 0; i<N; i++)
        for (int j = i + 1; j<N; j++)
            if (dist[j] > dist[i] + cost[i][j])
                dist[j] = dist[i] + cost[i][j];

    return dist[N - 1];
}

int MinCost(int cost[][N])
{
    int minCost[N] = { 0 };
    minCost[0] = 0;

    for (auto i = 1; i < N; ++i)
    {
        minCost[i] = cost[0][i];

        for (auto j = 0; j < i; ++j)
        {
            if (minCost[i] > minCost[j] + cost[j][i])
                minCost[i] = minCost[j] + cost[j][i];
        }
    }
    return minCost[N - 1];
}
// Driver program to test methods of graph class 
int main()
{
#if 0
    int cost[N][N] = { { 0, 15, 80, 90, 1,95,2000 },
    { INF, 0, 40, 50,5,80,200 },
    { INF, INF, 0, 70,1,90,5 },
    { INF, INF, INF, INF,0,5,6 },
    { INF, INF, INF, INF, INF, 0,56 },
    { INF, INF, INF, INF, INF,0,79 },
    { INF, INF, INF, INF, INF,INF,0 },
    };
    cout << "The Minimum cost to reach station "
        << N << " is " << minCost(cost)<<std::endl;

    cout << "The Minimum cost to reach station "
        << N << " is " << MinCost(cost);
#endif

     int arr[] = {1,2,3};
   // int arr[] = { 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    //ReverseArray(arr, n);
   // ReverseRec(arr, 0, n - 1);
    //PrintArray(arr, n);
    PrintSubset(arr, n);

#if 0
    // Function calling 
    leftRotate(arr, n, 6);
//    RightRotate(arr, n, 2);
    //printArray(arr, n);

#if 0
    //EditDistance("Saturday", "Sunday");
    std::string str2 = "SATURDAY";
    std::string str1 = "SUNDAY";
    std::cout << "MaxLongestSubSequence  " << "  " << MaxLongestSubSequence(str1, str2, str1.length(), str2.length()) << std::endl;

    for (auto N = 0; N < 15; ++N)
    {
        std::cout << "WaysToScore  "  << N << "  "<< WaysToScore(N) << std::endl;
    }


    for (auto N = 0; N < 15; ++N)
    {
        std::cout << "WaysToScoreDP  " << N << "  " << WaysToScoreDP(N) << std::endl;
    }
   // FindODD();

    // Create a graph given in the above diagram 
    Graph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 0);
    g.AddEdge(2, 3);
    g.AddEdge(3, 3);

    cout << "Following is Breadth First Traversal "
        << "(starting from vertex 2) \n";
    g.BFS(2);

    cout << "Following is Depth First Traversal "
        << "(starting from vertex 2) \n";
    g.BFS1(2);
#endif
#if 0
//#endif
    Graph g(6);
    g.AddEdge(5, 2);
    g.AddEdge(5, 0);
    g.AddEdge(4, 0);
    g.AddEdge(4, 1);
    g.AddEdge(2, 3);
    g.AddEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.TopologicalSort();

#endif
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left  = new Node(6);
    root->left->right->right = new Node(7);
    root->left->right->right->right = new Node(8);
    root->right->left = new Node(9);
    root->right->right = new Node(10);

    root->right->left->left = new Node(11);
    root->right->left->right = new Node(12);

    root->right->left->left->left = new Node(13);
    root->right->left->left->right = new Node(14);
    root->left->right->right->right->right = new Node(15);
    root->left->right->right->right->left = new Node(16);
    //Node *root = new Node(1);
    //root->left = new Node(2);
    //root->right = new Node(3);
    //root->left->left = new Node(4);
    //root->left->right = new Node(5);
    //root->right->right = new Node(6);

    Tree t;
//    t.InOrderTraverstal(root);
    cout << "\nPreorder traversal of binary tree is \n";
  //  t.PreOrderTraversal(root);
    std::vector<int> list;
    t.LevelOrderTraversal(root, list);

    cout << "\n Zig Zag traversal of binary tree is \n";
    //t.rightView(root);
//    std::vector<int> list;
    //int sum = 8;
    //bool hasPath = t.HasPathSum(root, sum);

    //std::cout << "Height of tree "<<t.GetHeight(root)<<std::endl;

    //std::cout << "\n Print bounday nodes .. \n";
   // t.PrintBoundaryNodes(root);
    //cout << "\nPreorder interative traversal of binary tree is \n";
    //t.PreorderTraversalNR(root);

    //cout << "\nInorder traversal of binary tree is \n";
   // t.PostOrderTraversal(root);
    //std::cout << "Height of tree " << t.GetHeight(root);

    //cout << "\nInorder traversal of binary tree (without recusion) is \n";
    //t.InorderTraversalNR(root);
#endif
    return 0;
}

