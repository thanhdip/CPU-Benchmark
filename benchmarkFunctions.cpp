#include "benchmarkFunctions.h"
#include <iostream>

/* QUICKSORT AND HELPER FUNCTIONS
 * Uses vector and function based on Hoare partition scheme
 */

int partition(std::vector<int> &array, int lo, int hi)
{
    int pivot = array.at((lo+hi)/2);
    int i = lo - 1;
    int j = hi + 1;

    for(;;)
    {
        do
        {
            i = i + 1;
        } while (array.at(i) < pivot);

        do
        {
            j = j - 1;
        } while (array.at(j) > pivot);
        
        if(i >= j)
        {
            return j;
        }
        //Swap
        int temp = array.at(i);
        array.at(i) = array.at(j);
        array.at(j) = temp;
    }

}

void quickSort(std::vector<int> &array, int lo, int hi)
{
    if(lo < hi)
    {
        int p = partition(array, lo, hi);
        quickSort(array, lo, p);
        quickSort(array, p+1, hi);
    }
}

void INTEGERQuickSort(std::vector<int> &array)
{
    int end = array.size();
    quickSort(array, 0, end-1);
}

/* MATRIX INVERSION AND HELPER FUNCTIONS
 * Uses vector and based on LU decomposition
 * I.e some matrix A is split into two matrix L and U where they are the upper and lower triangle of the square matrix.
 * This makes solving for the inverse easier.
 */

void LUDecompose(std::vector<std::vector<double>> &matrix, int dimesion, std::vector<int> piv)
{

}

void LUMatrixInvert(std::vector<std::vector<double>> &matrix, std::vector<std::vector<double>> &inverse, int dimesion, std::vector<int> piv)
{

}

void DOUBLEmatrixInv(std::vector<std::vector<double>> &matrix)
{
    
}


/*
 * 
 */

void printBigNum(int num)
{

}