#include <iostream>
#include "benchmarkFunctions.h"

int main()
{
    std::vector<int> array;

    for(int i = 0; i < 5; i++)
    {
        array.push_back(1);
        array.push_back(2);
        array.push_back(3);
        array.push_back(4);
    }

    for(int x : array)
    {
        std::cout << x;
    }
    std::cout << std::endl;

    INTEGERQuickSort(array);

    for(int x : array)
    {
        std::cout << x;
    }
    std::cout << std::endl;

    return 0;
}