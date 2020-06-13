
#include "stdafx.h"
#include <vector>
#include <iostream>

/*
Example 1:

Input:
11110
11010
11000
00000

Output : 1
    Example 2 :

    Input :
    11000
    11000
    00100
    00011

    Output : 3
*/
using namespace std;

void CountAdjacent(vector<vector<int>> &grid, int row, int column)
{
    //int count;

    if (row < 0 || row >= grid.size() || column < 0 || column >= grid[0].size() || grid[row][column] == 0)
        return;

    grid[row][column] = 0;
    CountAdjacent(grid, row + 1, column);
    CountAdjacent(grid, row, column + 1);
    CountAdjacent(grid, row - 1, column);
    CountAdjacent(grid, row, column - 1);
}
///////////////////////////////////////////////////////////////////////////////
int CountOfIsland(vector<vector<int>> & grid)
{
    int count = 0;

    //std::cout << grid.size() << std::endl;

    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            //std::cout << grid[i][j];
            // we have got the first inland, check how many connected island are present
            // by traversing up, down, left and right
            if (grid[i][j] == 1)
            {
                ++count;
                CountAdjacent(grid, i, j);
            }
        }
        std::cout << std::endl;
    }
    return count;
}
///////////////////////////////////////////////////////////////////////////////
/*int main()
{
    //std::vector<std::vector<int>> grid =
    //{   {1,1,0,0,0},
    //    {1,1,0,0,0},
    //    {0,0,1,0,0},
    //    {0,0,0,1,1}
    //};
    //std::cout<< "Island count : "<<CountOfIsland(grid)<<std::endl;
}*/