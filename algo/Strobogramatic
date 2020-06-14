#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

// 16891 is strobo as it is same after rotating 180 degree
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 0
// 6 <-> 9, 8<->8, 0<->0, 1<->1

bool IsNumberStrobogramatic(int num, int digit)
{
    std::string str;
    str.assign(to_string(num));
    char selectList[] = {'0', '1', '6', '8', '9'};
    //char rejectList[] = {'2', '3', '4', '5', '7'};
    int start = 0;
    int end = digit-1;
    while(start <= end)
    {
        bool match = false;
        for(int i = 0; i < 5; i++)
        {
            if(str[start] == selectList[i])
            {
                match = true;
                break;
            }
        }
        if (!match )
            return false;
        switch(str[start])
        {
        case '0':
            if(str[start] != str[end])
                return false;
            break;
        case '1':
            if(str[start] != str[end])
                return false;
            break;
        case '6':
            if(str[start] != str[end]-3)
                return false;
            break;
        case '8':
            if(str[start] != str[end])
                return false;
            break;
        case '9':
            if(str[start] != str[end]+3)
                return false;
            break;
        default:
            return false;
        }
        start++;
        end--;
    }
    std::cout << "number " << num << " is strobogramatic\n" << std::endl;
    return true;
}
int main(int argc, char* argv[])
{
    if(!IsNumberStrobogramatic(16891, 5))
        std::cout << "number " << 16891 << " is not strobogramatic\n" << std::endl;

    if(!IsNumberStrobogramatic(11869811, 8))
        std::cout << "number " << 11869811 << " is not strobogramatic\n" << std::endl;

    if(!IsNumberStrobogramatic(69269, 5))
        std::cout << "number " << 69269 << " is not strobogramatic\n" << std::endl;
    
    if(!IsNumberStrobogramatic(6996, 4))
        std::cout << "number " << 6996 << " is not strobogramatic\n" << std::endl;

    if(!IsNumberStrobogramatic(6910169, 7))
        std::cout << "number " << 6910169 << " is not strobogramatic\n" << std::endl;

	return 0;
}
