#include <iostream>
#include "Matrix.h"
#include <ctime>

int main()
{
    srand(time(nullptr));

    size_t const Rows = 2;
    size_t const Cols = 2;
    double** matrix = createMatrix(Rows, Cols);
    double** matrix2 = createMatrix(Rows, Cols);


    inputMatrix(matrix, Rows, Cols);
    matrix2 = inv(matrix, 2);
    printMatrix(matrix2, Rows, Cols);

    double** E = multMatrix(matrix, matrix2, 2, 2, 2);
    printMatrix(E, Rows, Cols);

    localMinimum(matrix, -1., Rows, Cols);

    printMatrix(matrix, Rows, Cols);

    std::cout << "rand matrix 2:\n";

    randMatrix(matrix2, Rows, Cols);

    double** C = multMatrix(matrix, matrix2, Rows, Cols, Cols);
    printMatrix(C, Rows, Cols);


    inputMatrix(matrix, Rows, Cols);
    printMatrix(matrix, Rows, Cols);
    double& minmax = minmaxMatrix(matrix, Rows, Cols);
    std::cout << "minmax: " << minmax << "\n";
    minmax = 42;
    std::cout << "changed minmax to " << minmax << ":\n";
    printMatrix(matrix, Rows, Cols);

    std::cout << "mix rows and cols with indices 0 and 2:\n";
    mixMatrix(matrix, Rows, Cols, 0, 2);
    printMatrix(matrix, Rows, Cols);

    std::cout << "matrix with zeros:\n";
    zeros(matrix, Rows, Cols);
    printMatrix(matrix, Rows, Cols);

    std::cout << "matrix with ones:\n";
    ones(matrix, Rows, Cols);
    printMatrix(matrix, Rows, Cols);

    std::cout << "matrix with -1.5:\n";
    fill(matrix, Rows, Cols, -1.5);
    printMatrix(matrix, Rows, Cols);

    std::cout << "fill matrix from 0 to " << Rows * Cols - 1 << ":\n";
    for (size_t r = 0; r < Rows; ++r)
        for (size_t c = 0; c < Cols; ++c)
            matrix[r][c] = r * Cols + c;
    printMatrix(matrix, Rows, Cols);

    std::cout << "rotate 180:\n";
    rotate180(matrix, Rows, Cols);
    printMatrix(matrix, Rows, Cols);

    double& minimum = findMinimum(matrix, Rows, Cols);
    std::cout << "minimum is " << minimum << "\n";
    minimum = 42;
    std::cout << "changed minimum to 42:\n";
    //findMinimum(matrix, Rows, Cols) = 42;
    printMatrix(matrix, Rows, Cols);

    std::cout << "row vector:\n";
    double** vec = linspace(Cols);
    printMatrix(vec, 1, Cols);

    std::cout << "transposed matrix:\n";
    double** transposed = transpose(matrix, Rows, Cols);
    printMatrix(transposed, Cols, Rows);

    deleteMatrix(matrix, Rows, Cols);
    deleteMatrix(vec, 1, Cols);
    deleteMatrix(transposed, Rows, Cols);
    return 0;
}