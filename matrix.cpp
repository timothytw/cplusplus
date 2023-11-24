#include <iostream>
#include <string>

// 3x3 matrix
const int MATRIX_SIZE = 3;

class Matrix3 {
public:
    int value[MATRIX_SIZE][MATRIX_SIZE] = {};

    Matrix3(int col1[], int col2[], int col3[]) {
        int *table[3] = {col1, col2, col3};
        for (int col = 0; col < MATRIX_SIZE; col++) {
            for (int row = 0; row < MATRIX_SIZE; row++) {
                value[row][col] = table[row][col];
            }
        }
    };

    void PrintMatrix() {
        for (int col = 0; col < MATRIX_SIZE; col++) {
            for (int row = 0; row < MATRIX_SIZE; row++) {
                std::cout << value[row][col] << " ";
            }
            std::cout << std::endl;
        }
    }

    void PrintMatrixTranspose() {
        for (int col = 0; col < MATRIX_SIZE; col++) {
            for (int row = 0; row < MATRIX_SIZE; row++) {
                std::cout << value[col][row] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int col1[3] = {1, 2, 3};
    int col2[3] = {5, 9, 1};
    int col3[3] = {0, 1, 2};
    Matrix3 matrix(col1, col2, col3);
    matrix.PrintMatrix();
    std::cout << std::endl;
    matrix.PrintMatrixTranspose();
    return 0;
}
