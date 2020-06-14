// histogram_largest_rectangle.cpp : Defines the entry point for the console application.
//

//You are given a histogram consisting of rectangles of different heights. 
//These heights are represented in an input list, such that [1, 3, 2, 5] corresponds to the following diagram:
//
//      x
//      x  
//  x   x
//  x x x
//x x x x
//
//Determine the area of the largest rectangle that can be formed only from the bars of the histogram. 
//For the diagram above, for example, this would be six, representing the 2 x 3 area at the bottom right.

#include <stdio.h>
#include <iostream>
#include <string>

int AreaOfRectangle(int len, int height)
{
    return len*height;
}
int MaxAreaOfHistogram(int Arr[], int size)
{
    int maxNo = 0, minNo = 0;

    maxNo = minNo = Arr[0];

    for(int i = 1; i<size-1; i++)
    {
        if(Arr[i] > maxNo)
            maxNo = Arr[i];

        if(Arr[i] < minNo)
            minNo = Arr[i];
    }
    int maxArea = maxNo > minNo*size? maxNo:minNo*size;

    for(int i = 0; i<size; i++)
    {
        int length = 1;
        int height = Arr[i];
        for(int j = i+1; j<size; j++)
        {
            if(Arr[j] < height)
            {
                height = Arr[j];
            }
            length++;
            int newArea = AreaOfRectangle(height,length);
            if( newArea > maxArea)
                maxArea = newArea;
        }

    }

    return maxArea;

}
int main(int argc, char* argv[])
{
    int Array1 [] = {1, 3, 6, 2, 3, 5};
    int maxArea = MaxAreaOfHistogram(Array1, 6);
    std::cout << "max area is " << maxArea << "\n" << std::endl;

    int Array2[] = {6, 2, 1, 4, 3, 5};
    maxArea = MaxAreaOfHistogram(Array2, 6);
    std::cout << "max area is " << maxArea << "\n" << std::endl;

    return 0;
}

