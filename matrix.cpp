#include <iostream>
#include <string>

// 3x3 matrix
const int MATRIX_SIZE = 3;

class Matrix3 {
private:
  int value[MATRIX_SIZE][MATRIX_SIZE] = {};

public:
  Matrix3() {
    int col1[3]{}, col2[3]{}, col3[3]{};
    int *table[3] = {col1, col2, col3};
    for (int col = 0; col < MATRIX_SIZE; col++) {
      for (int row = 0; row < MATRIX_SIZE; row++) {
        value[row][col] = table[row][col];
      }
    }
  };

  Matrix3(int col1[], int col2[], int col3[]) {
    int *table[3] = {col1, col2, col3};
    for (int col = 0; col < MATRIX_SIZE; col++) {
      for (int row = 0; row < MATRIX_SIZE; row++) {
        value[row][col] = table[row][col];
      }
    }
  };

  Matrix3 operator+(const Matrix3 &m) {
    Matrix3 summedMatrix;
    for (int col = 0; col < MATRIX_SIZE; col++) {
      for (int row = 0; row < MATRIX_SIZE; row++) {
        summedMatrix.value[row][col] = value[row][col] + m.value[row][col];
      }
    }
    return summedMatrix;
  }

  Matrix3 operator-() {
    Matrix3 summedMatrix;
    for (int col = 0; col < MATRIX_SIZE; col++) {
      for (int row = 0; row < MATRIX_SIZE; row++) {
        summedMatrix.value[row][col] = -value[row][col];
      }
    }
    return summedMatrix;
  }

  Matrix3 operator-(Matrix3 &m) { return *this + -m; }

  int Trace() {
    int trace = 0;
    for (int i = 0; i < 3; i++) {
      trace += value[i][i];
    }
    return trace;
  }

  void PrintMatrix() {
    for (int col = 0; col < MATRIX_SIZE; col++) {
      for (int row = 0; row < MATRIX_SIZE; row++) {
        std::cout << value[row][col] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  void PrintMatrixTranspose() {
    for (int col = 0; col < MATRIX_SIZE; col++) {
      for (int row = 0; row < MATRIX_SIZE; row++) {
        std::cout << value[col][row] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
};

int main() {
  Matrix3 matrixZero;
  int col1[3] = {1, 2, 3};
  int col2[3] = {5, 9, 1};
  int col3[3] = {0, 1, 2};
  Matrix3 matrix(col1, col2, col3);
  Matrix3 matrixSummed = matrix + matrixZero;
  matrixSummed.PrintMatrix();
  matrixSummed.PrintMatrixTranspose();
  Matrix3 negMatrix = -matrixSummed;
  negMatrix.PrintMatrix();
  Matrix3 matrixSub = matrix - matrix;
  matrixSub.PrintMatrix();
  std::cout << "Trace: " << matrix.Trace() << std::endl;
  return 0;
}
