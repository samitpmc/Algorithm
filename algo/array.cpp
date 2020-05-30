
#include "stdafx.h"
#include "array.h"

///////////////////////////////////////////////////////////////////////////////
void LeftRotate(int arr[], int n, int d)
{
    //int tmp = arr[0];
    // create temporay array 
    int *tmp = new int(d);

    for (auto i = 0; i < d; ++i)
        tmp[i] = arr[i];

    for (auto j = 0; j < n - d; ++j)
        arr[j] = arr[j + d];

    for (auto j = (n - d), i = 0; j < n; ++j, ++i)
        arr[j] = tmp[i];
}

//void ReverseArray(int arr[], int n)
//{
//
//    //for (for int i = 0; i < n; ++i)
//    int start = 0;
//    int end = n - 1;
//    while (start < end)
//    {
//        int temp = arr[start];
//        arr[start] = arr[end];
//        arr[end] = temp;
//        ++start;
//        --end;
//    }
//}

///////////////////////////////////////////////////////////////////////////////
void RightRotate(int arr[], int n, int d)
{
    int *ptr = new int(d);

    for (auto j = (n -d), i = 0; j < n; ++j, ++i)
        ptr[i] = arr[j];

    for (int i = n; i >= d; --i)
        arr[i] = arr[i - d];

    for (int i = 0; i < d; ++i)
        arr[i] = ptr[i];
}

void leftRotate(int arr[], int n, int k)
{
    /* To get the starting point of rotated array */
    int mod = k % n;

    // Prints the rotated array from start position 
    for (int i = 0; i < n; i++)
        std::cout << (arr[(mod + i) % n]) << " ";

    std::cout << "\n";
}
// int arr[] = {1,2,3,4,5,6};

void ReverseArray(int arr[], int len)
{
    int start = 0;
    int end = len - 1;

    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        ++start;
        --end;
    }
}

void ReverseRec(int arr[], int start, int end)
{
    if (start >= end)
        return;
    // Now reverse it

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    ReverseRec(arr, start + 1, end - 1);
}

void PrintArray(int arr[], int len)
{
    for (int i = 0; i < len; ++i)
        std::cout << arr[i] << std::endl;
}



void PrintSubset(int array[], unsigned size)
{
    unsigned count = pow(2, size) - 1; // 7
    for (unsigned i = 1; i <= count; ++i) // 7
    {
        for (unsigned j = 1; j <= size; ++j) // 3
        {
            auto x = 1 << (j - 1);
            if (i & (1 << (j - 1)))
            {
                std::cout << array[j - 1] << " ";
            }
        }
        std::cout << std::endl;
    }
}

void PrintArrayPermutation(int arr[], int len)
{
    // [1,2,3]-> [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3], [2,3,1],[3,1,2]
}