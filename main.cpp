#include <iostream>
#include <chrono>
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
        // 10000 * 1000 = 1.51s 10000 * 500 = .67s 10000 * 800 = 1.12s
        // 8,000,000 always a little above 1 sec

    int multa = 10000;
    int multb = 800;
    std::vector<int> array;
    for(int i = 0; i < multa; i++)
    {
        for(int j = 0; j < multb; j++)
        {
            array.push_back(j);
        }
    }

        //Sort
    auto start = std::chrono::steady_clock::now();

    //for(int x = 0; x < 10; x++)
    while(auto t = std::chrono::duration_cast<std::chrono::seconds>( std::chrono::steady_clock::now() - start ).count() < 10)
    {
        std::vector<int> arr = array;
        INTEGERQuickSort(arr);
    }    
    
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> runtimeInt = end-start;
    std::cout << "Time: " << runtimeInt.count() << std::endl;


        //Check


    /* ---------------------------------------------------------------------------------------------------
     *  DOUBLE
     */
    
        //Data Gen
        // 475 = 1.07
    int rc = 475;
    std::vector<std::vector<double>> matrix(rc, std::vector<double>(rc));
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
    auto start = std::chrono::steady_clock::now();
    while(auto t = std::chrono::duration_cast<std::chrono::seconds>( std::chrono::steady_clock::now() - start ).count() < 10)
    {
        std::vector<std::vector<double>> mat = matrix;
        DOUBLEmatrixInv(mat, rc);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> runtimeInt = end-start;
    std::cout << "Time: " << runtimeInt.count() << std::endl;
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