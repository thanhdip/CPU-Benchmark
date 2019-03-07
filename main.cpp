#include <iostream>
#include "benchmarkFunctions.h"

void printArray(std::vector<int> array);
void printMatrix(std::vector<std::vector<double>> matrix);

/* Using std::vector because allocating on heap is easier to allocate large amount of memory. Vector is also really fast as well. 
 */

int main()
{
    /* ---------------------------------------------------------------------------------------------------
     *  INTEGER
     */

        //Data Gen
    std::vector<int> array;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            array.push_back(j);
        }
    }

        //Sort
    INTEGERQuickSort(array);

        //Check


    /* ---------------------------------------------------------------------------------------------------
     *  DOUBLE
     */

    int rc = 3;

    std::vector<std::vector<double>> matrix(rc, std::vector<double>(rc));

        //Data Gen
    for(int i = 0; i < rc; i++)
    {
        for(int j = 0; j < rc; j++)
        {
            if(i == j)
            {
                matrix.at(i).at(j) = 2.0001;
            }
            else
            {
                matrix.at(i).at(j) = 1.0001;
            } 
        }
    }

        //Invert
    DOUBLEmatrixInv(matrix, rc);

        //Check
    
    return 0;
}

/* Printer Functions
 * Lives here to help print vectors, matrix, and other.
 */

void printArray(std::vector<int> array)
{
    for(int x : array)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void printMatrix(std::vector<std::vector<double>> matrix)
{   
    for(std::vector<double> vec : matrix)
    {
        for(double y : vec)
        {
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}