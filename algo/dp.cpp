
#include "stdafx.h"
#include "dp.h"

///////////////////////////////////////////////////////////////////////////////
int NumberOfTiles(int N)
{
    if (N == 0)
        return 0;

    if (N == 1)
        return 1;

    if (N == 2)
        return 2;

    return NumberOfTiles(N - 1) + NumberOfTiles(N - 2);
}
///////////////////////////////////////////////////////////////////////////////
int WaysToScore(int N)
{
    if (N < 0)
        return 0;

    if (N == 0)
        return 1;

    return (WaysToScore(N - 10) + WaysToScore(N - 5) + WaysToScore(N - 3));
}
///////////////////////////////////////////////////////////////////////////////
int WaysToScoreDP(int N)
{
    std::vector<int> resultVec(N + 1, 0);

    resultVec[0] = 1;
    int i = 1;

    for (; i <= N ; ++i)
    {
        if (i >= 3)
            resultVec[i] += resultVec[i - 3];

        if (i >= 5)
            resultVec[i] += resultVec[i - 5];

        if (i >= 10)
            resultVec[i] += resultVec[i - 10];
    }
    return resultVec[N];
}
//////////////////////////////////////////////////////////////////////////////
int OurMin(int x, int y, int z)
{
    return min(min(x, y), z);
}
///////////////////////////////////////////////////////////////////////////////
int EditDistance(const std::string str1, const std::string str2, size_t len1, size_t len2)
{
    if (len1 == 0)
        return len2;

    if (len2 == 0)
        return len1;

    if (str1[len1 - 1 ] == str2[len2 - 1])
        return EditDistance(str1, str2, len1 -1, len2-1);

    int insert = EditDistance(str1, str2, len1, len2 - 1);
    int del = EditDistance(str1, str2, len1 - 1, len2);
    int replace = EditDistance(str1, str2, len1 - 1, len2 - 1);
    
    return OurMin(del, replace, insert) + 1;
}

int MaxLongestSubSequence(const std::string &str1, const std::string & str2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    // check last character
    if (str1[m - 1] == str2[n - 1])
        return (1 + MaxLongestSubSequence(str1, str2, m - 1, n - 1));
    else
        return max(MaxLongestSubSequence(str1, str2, m - 1, n), MaxLongestSubSequence(str1, str2, m, n - 1));
}
