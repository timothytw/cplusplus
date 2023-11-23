#include <iostream>
#include <string>

const int COL_SIZE = 3;

class Matrix3 {
public:
    int value[3][3] = {};

    Matrix3(int col1[3], int col2[3], int col3[3]) {
        bool col1_size_is_3 = (sizeof(*col1) / sizeof(int)) == COL_SIZE;
        bool col2_size_is_3 = sizeof(*col2) / sizeof(int) == COL_SIZE;
        bool col3_size_is_3 = sizeof(*col3) / sizeof(int) == COL_SIZE;
        std::cout << sizeof(*col1) / sizeof(int) << ".. " << sizeof(*col1) << " .. " << sizeof(int) << std::endl;

        if (!(col1_size_is_3 && col2_size_is_3 && col3_size_is_3)) {
            throw("at least one column does not have 3 integers");
        }

        for (int col = 0; col < COL_SIZE; col++) {
            for (int row = 0; row < COL_SIZE; row++) {
                value[col][row] = 3;
            }
        }
    };

    void PrintMatrix() {
        for (int col = 0; col < COL_SIZE; col++) {
            for (int row = 0; row < COL_SIZE; row++) {
                std::cout << value[col][row] << " ";
            }
            std::cout << std::endl;
        }
    }
};

// using namespace std;
int main() {
    // std::vector<std::string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    int col1[3] = {1, 2, 3};
    Matrix3 matrix(col1, col1, col1);
    matrix.PrintMatrix();
    return 0;
}
