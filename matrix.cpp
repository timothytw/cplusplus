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

  Matrix3 operator*(const int r) const {
    Matrix3 scalarMatrix;
    for (int col = 0; col < MATRIX_SIZE; col++) {
      for (int row = 0; row < MATRIX_SIZE; row++) {
        scalarMatrix.value[row][col] = r * value[row][col];
      }
    }
    return scalarMatrix;
  }

  bool operator==(const Matrix3 &m) const {
    for (int col = 0; col < MATRIX_SIZE; col++) {
      for (int row = 0; row < MATRIX_SIZE; row++) {
        if (m.value[row][col] != value[row][col]) {
          return false;
        }
      }
    }
    return true;
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

Matrix3 operator*(const int lhsScalar, const Matrix3 &rhsMatrix) {
  return rhsMatrix * lhsScalar;
}

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
  std::cout << "Trace: " << matrix.Trace() << std::endl << std::endl;
  Matrix3 scalarMatrix1 = matrix * 3;
  scalarMatrix1.PrintMatrix();
  Matrix3 scalarMatrix2 = 3 * matrix;
  scalarMatrix2.PrintMatrix();
  std::cout << "Equal: " << (scalarMatrix1 == scalarMatrix2) << std::endl;
  std::cout << "Not Equal: " << (scalarMatrix1 == matrix) << std::endl;
  return 0;
}
