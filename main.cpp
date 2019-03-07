#include <iostream>
#include <chrono>
#include "benchmarkFunctions.h"

void printArray(std::vector<int> array);
void printMatrix(std::vector<std::vector<double>> matrix);

/* Using std::vector because allocating on heap is easier to allocate large amount of memory. Vector is also really fast as well. 
 */

int main()
{
    //PRINT AT BEGINING
    std::cout << "BENCHMARK PROGRAM STARTING..." << std::endl;
    std::cout << "This should run for about 20 seconds. Please give it some time." << std::endl;
    std::cout << "Running...." << std::endl;

    /* ----------------------------------------------------------------------------------------------------------------------------------------
     *  INTEGER
     */

        //Data Gen
        // 10000 * 1000 = 1.51s 10000 * 500 = .67s 10000 * 800 = 1.12s
        // 1000*800 runs just enough to match with matrix inversion to get 500ish avg score on an Intel Core i9-7900X @ 3.30Ghz NO BOOST

    int multa = 5000;
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
    auto starti = std::chrono::steady_clock::now();
    int nint = 0;
    std::cout << "Sort...." << std::endl;
    while(auto t = std::chrono::duration_cast<std::chrono::seconds>( std::chrono::steady_clock::now() - starti ).count() < 10)
    {
        std::vector<int> arr = array;
        INTEGERQuickSort(arr);
        nint++;
    }    

    auto endi = std::chrono::steady_clock::now();
    std::chrono::duration<double> runtimeInt = endi-starti;
    double vint = (60*nint)/runtimeInt.count();

    /* -----------------------------------------------------------------------------------------------------------------------------------------
     *  DOUBLE
     */
    
        //Data Gen
        // 475 = 1.07 always a little above 1 sec.
        // 225 runs just enough to match with sort to get 500ish avg score on an Intel Core i9-7900X @ 3.30Ghz NO BOOST
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
    auto startf = std::chrono::steady_clock::now();
    int nfloat = 0;
    std::cout << "Invert...." << std::endl;
    while(auto t = std::chrono::duration_cast<std::chrono::seconds>( std::chrono::steady_clock::now() - startf ).count() < 10)
    {
        std::vector<std::vector<double>> mat = matrix;
        DOUBLEmatrixInv(mat, rc);
        nfloat++;
    }

    auto endf = std::chrono::steady_clock::now();
    std::chrono::duration<double> runtimeFloat = endf-startf;
    double vfloat = (60*nfloat)/runtimeFloat.count();

    /*---------------------------------------------------------------------------------------------------------------------------------------
     * PRINT AT END
     */
    std::cout << "DONE!!!\n" << std::endl;
    int score = (2*vfloat*vint)/(vfloat+vint);
    std::cout << "YOUR BENCHMARK SCORE IS:" << std::endl;
    std::cout << "!!!! " << score << " !!!!" << std::endl;
    std::cout << "vfloat = " << vfloat << " minv/min " << "|_| vint = " << vint << " sort/min" << std::endl;

    std::cout << "\nEND BENCHMARK" << std::endl;
    std::cout << "Press ENTER to exit..." << std::endl;
    std::cin.get();
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