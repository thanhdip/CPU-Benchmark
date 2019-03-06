#include <iostream>
#include "benchmarkFunctions.h"

int main()
{
    /*  INTEGER
     */

        //Data Gen
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

        //Sort
    INTEGERQuickSort(array);

    for(int x : array)
    {
        std::cout << x;
    }
    std::cout << std::endl;

    /*  DOUBLE
    */
    int rc = 100;

    std::vector<std::vector<double>> matrix(rc, std::vector<double>(rc));

        //Data Gen
    for(int i = 0; i < rc; i++)
    {
        for(int j = 0; j < rc; j++)
        {
            if(i == j)
            {
                matrix.at(i).at(j) = 2.000000001;
            }
            else
            {
                matrix.at(i).at(j) = 1.000000001;
            } 
        }
    }

        //Invert
    DOUBLEmatrixInv(matrix);



    return 0;
}