    #include "SquareMat.hpp"
    #include <iostream>

    using namespace matrix;
    using namespace std;

    int main() {
        cout << "=== SquareMat Demonstration ===" << endl << endl;

        int size = 3;
        cout << "Creating a 3x3 array (arr) with sequential values." << endl;
        double** arr = new double*[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                arr[i][j] = i * size + j + 1;
            }
        }

        cout << "\nInitializing mat1 with arr." << endl;
        SquareMat mat1(size, arr);

        cout << "\nInitializing mat2 with scalar value 5 (mat2)." << endl;
        SquareMat mat2(size, 5);

        cout << "\nCreating mat3 as a copy of mat1 (mat3 = mat1)." << endl;
        SquareMat mat3 = mat1;

        cout << "\n=== Initial Matrices ===" << endl;
        cout << "mat1:" << endl << mat1 << endl;
        cout << "mat2 (scalar 5):" << endl << mat2 << endl;
        cout << "mat3 (copy of mat1):" << endl << mat3 << endl;

        cout << "=== Assignment: Assigning scalar 7 to mat1 ===" << endl;
        mat1 = 7;
        cout << "mat1 after assigning scalar 7:" << endl << mat1 << endl;

        cout << "=== Addition: mat2 + mat3 ===" << endl;
        cout << (mat2 + mat3) << endl;

        cout << "=== Subtraction: mat2 - mat3 ===" << endl;
        cout << (mat2 - mat3) << endl;

        cout << "=== Unary Minus: -mat3 ===" << endl;
        cout << -mat3 << endl;

        cout << "=== Multiplication (Matrix * Matrix): mat2 * mat3 ===" << endl;
        cout << mat2 * mat3 << endl;

        cout << "=== Multiplication (Matrix * Scalar): mat2 * 3 ===" << endl;
        cout << mat2 * 3 << endl;

        cout << "=== Multiplication (Scalar * Matrix): 4 * mat3 ===" << endl;
        cout << 4 * mat3 << endl;

        cout << "=== Element-wise Multiplication: mat2 % mat3 ===" << endl;
        cout << mat2 % mat3 << endl;

        cout << "=== Modulo with Scalar: mat3 % 4 ===" << endl;
        cout << mat3 % 4 << endl;

        cout << "=== Division by Scalar: mat2 / 2 ===" << endl;
        cout << mat2 / 2 << endl;

        cout << "=== Matrix Power: mat3 ^ 2 ===" << endl;
        cout << (mat3 ^ 2) << endl;

        cout << "=== Pre-Increment: ++mat3 ===" << endl;
        ++mat3;
        cout << mat3 << endl;

        cout << "=== Post-Increment: mat3++ ===" << endl;
        mat3++;
        cout << mat3 << endl;

        cout << "=== Pre-Decrement: --mat3 ===" << endl;
        --mat3;
        cout << mat3 << endl;

        cout << "=== Post-Decrement: mat3-- ===" << endl;
        mat3--;
        cout << mat3 << endl;

        cout << "=== Transpose: ~mat3 ===" << endl;
        cout << ~mat3 << endl;

        cout << "=== Equality (mat2 == mat3) ===" << endl;
        cout << (mat2 == mat3 ? "True" : "False") << endl << endl;

        cout << "=== Inequality (mat2 != mat3) ===" << endl;
        cout << (mat2 != mat3 ? "True" : "False") << endl << endl;

        cout << "=== Less Than (mat2 < mat3) ===" << endl;
        cout << (mat2 < mat3 ? "True" : "False") << endl << endl;

        cout << "=== Greater Than (mat2 > mat3) ===" << endl;
        cout << (mat2 > mat3 ? "True" : "False") << endl << endl;

        cout << "=== Less Than or Equal (mat2 <= mat3) ===" << endl;
        cout << (mat2 <= mat3 ? "True" : "False") << endl << endl;

        cout << "=== Greater Than or Equal (mat2 >= mat3) ===" << endl;
        cout << (mat2 >= mat3 ? "True" : "False") << endl << endl;

        cout << "=== Determinant: !mat3 ===" << endl;
        cout << "!mat3 = " << !mat3 << endl << endl;

        cout << "=== Self-Assignment Operations on mat3 ===" << endl;

        mat3 += mat2;
        cout << "After mat3 += mat2:" << endl << mat3 << endl;

        mat3 -= mat2;
        cout << "After mat3 -= mat2:" << endl << mat3 << endl;

        mat3 *= mat2;
        cout << "After mat3 *= mat2:" << endl << mat3 << endl;

        mat3 /= 2;
        cout << "After mat3 /= 2:" << endl << mat3 << endl;

        mat3 %= mat2;
        cout << "After mat3 %= mat2:" << endl << mat3 << endl;

        mat3 *= 2;
        cout << "After mat3 *= 2:" << endl << mat3 << endl;

        mat3 %= 5;
        cout << "After mat3 %= 5:" << endl << mat3 << endl;

        cout << "=== Cleaning up dynamically allocated array ===" << endl;
        for (int i = 0; i < size; ++i) {
            delete[] arr[i];
        }
        delete[] arr;

        cout << "=== Demonstration Completed ===" << endl;

        return 0;
    }
