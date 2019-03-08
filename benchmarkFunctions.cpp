#include "benchmarkFunctions.h"
#include <iostream>

/* QUICKSORT AND HELPER FUNCTIONS
 * Uses vector and function based on Hoare partition scheme
 */
        //Partions the array and swaps to sort
int partition(std::vector<int> &array, int lo, int hi)
{
    int pivot = array[(lo+hi)/2];
    int i = lo - 1;
    int j = hi + 1;

    for(;;)
    {
        do
        {
            i = i + 1;
        } while (array[i] < pivot);

        do
        {
            j = j - 1;
        } while (array[j] > pivot);
        
        if(i >= j)
        {
            return j;
        }
        //Swap
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

}
        //Sorts by paritioning then recursively doing so
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
        //Decomposes matrix M = LU where L is lower and U is upper triangle of the square matrix
void LUDecompose(std::vector<std::vector<double>> &matrix, int dimension)
{
    double tem;
    for(int k = 0; k <= dimension - 1; k++)
    {
        for(int j = k + 1; j <= dimension; j++)
        {
            tem = matrix[j][k] / matrix[k][k];
            for(int i = k; i <= dimension; i++)
            {
                matrix[j][i] = matrix[j][i] - tem * matrix[k][i];
            }
            matrix[j][k] = tem;
        }
    }
}
        //Uses the LU decomposition to then go through both upper and lower triangle and invert the matrix
std::vector<std::vector<double>> LUMatrixInvert(std::vector<std::vector<double>> &matrix, int dimension)
{
    std::vector<double> identityVec(dimension + 1, 0.0);
    std::vector<double> y(dimension + 1, 0.0);
    std::vector<std::vector<double>> s(dimension + 1, std::vector<double>(dimension + 1, 0.0));
    double tem;

    for(int m = 0; m <= dimension; m++)
    {
        for(int x = 0; x < dimension; x++)
        {
            identityVec[x] = 0.0;
        }
        identityVec[m] = 1.0;

        for(int i = 0; i <= dimension; i++)
        {
            tem = 0.0;
            for(int j = 0; j <= i - 1; j++)
            {
                tem = tem + (matrix[i][j] * y[j]);
            }
            y[i] = identityVec[i] - tem;
        }

        for(int i = dimension; i >= 0; i--)
        {
            tem = 0.0;
            for(int j = i + 1; j <= dimension; j++)
            {
                tem = tem + (matrix[i][j] * s[j][m]);
            }
            s[i][m] = (y[i] - tem) / matrix[i][i];
        }
    }

    return s;
}

void DOUBLEmatrixInv(std::vector<std::vector<double>> &matrix, int rc)
{
    std::vector<int> piv;

    LUDecompose(matrix, rc - 1);
    matrix = LUMatrixInvert(matrix, rc - 1);
}