
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
/*
You are given a histogram consisting of rectangles of different heights. These heights are represented in an input list, such that [1, 3, 2, 5] corresponds to the following diagram:

      x
      x
  x   x
  x x x
x x x x
Determine the area of the largest rectangle that can be formed only from the bars of the histogram. For the diagram above, for example,
this would be six, representing the 2 x 3 area at the bottom right.
*/
using namespace std;

int LargestRectangleBruteForce(std::vector<int> hist)
{
    int area = 0;
    for (int i = 0; i < hist.size(); ++i)
    {
        for (int j = i + 1; j < hist.size(); ++j)
        {
            // area = length * breath
            // Breath will be (j - i) + 1
            //Length would be minimum of all height in the range
            // Look for all ranges (0,1), (0,2), (0,3), (1,2), (1,3), (2,3)
            auto length = std::min_element(hist.begin() + i, hist.begin() + j);
            int breath = (j - i) + 1;
            int tmpArea = *length * breath;
            if (tmpArea > area)
                area = tmpArea;
        }
    }
    return area;
}
////////////////////////
struct Info
{
    Info(int _height, int _index) : height(_height), index(_index) {}
    int height;
    int index;
};

int LargestRectangle(std::vector<int> hist)
{
    if (hist.empty())
        return 0;

    int maxArea = 0;

    std::stack<Info> heightStk;

    // Put the height and index of the first element in histogram on the stack.
    heightStk.push(Info(hist[0], 0));
    
    for (int i = 1; i < hist.size(); ++i)
    {
        // There can be 2 condition 
        // a) Next item is greater or equal to current than the stack top, that means we have probablity to get
        // bigger rectangle so carry on
        // b) Next item is less then current item that means older height pushed must be discraded and newer
        // one pushed to it. But do check if the area of the previous tall tower was the largest rectangle

        if (hist[i] >= hist[i - 1])
        {
            heightStk.push(Info (hist[i], i));
        }
        else
        {
            int position = 0;
            // Now trace back hence we will have to pop from stack till we find height less then hist[i]
            while (!heightStk.empty() && hist[i] < heightStk.top().height)
            {
                position = heightStk.top().index;
                int tempArea = heightStk.top().height * (i - position);
                if (tempArea > maxArea)
                {
                    maxArea = tempArea;
                }
                heightStk.pop();
            }
            heightStk.push(Info(hist[i], position));
        }
    }
    // Now you have reached to end of the vector so backtrack and check which one forms the largest rectangle
    while (!heightStk.empty())
    {
        int tempArea = heightStk.top().height * (hist.size() - heightStk.top().index);
        if (tempArea > maxArea)
        {
            maxArea = tempArea;
        }
        heightStk.pop();
    }

    return maxArea;
}
#if 0
////////////////////////////////////////////////////////////
int main()
{
    std::vector<int> hist = { 1,3,2,6,6,2,2,2 };
    std::cout << LargestRectangle(hist) << std::endl;
}
#endif