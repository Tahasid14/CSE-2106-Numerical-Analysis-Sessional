#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void solveGaussianElimination(vector<vector<float>>& matrix, int size) {
    for (int row = 0; row < size; row++) {
        for (int nextRow = row + 1; nextRow < size; nextRow++) {
            if (abs(matrix[row][row]) < abs(matrix[nextRow][row])) {
                for (int col = 0; col < size + 1; col++) {
                    swap(matrix[row][col], matrix[nextRow][col]);
                }
            }
        }
        for (int nextRow = row + 1; nextRow < size; nextRow++) {
            float ratio = matrix[nextRow][row] / matrix[row][row];
            for (int col = row; col < size + 1; col++) {
                matrix[nextRow][col] -= ratio * matrix[row][col];
            }
        }
    }
    vector<float> result(size);
    result[size - 1] = matrix[size - 1][size] / matrix[size - 1][size - 1];
    for (int row = size - 2; row >= 0; row--) {
        float sum = matrix[row][size];
        for (int col = row + 1; col < size; col++) {
            sum -= matrix[row][col] * result[col];
        }
        result[row] = sum / matrix[row][row];
    }
    cout << "\nSolution: \n";
    for (int i = 0; i < size; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(4) << result[i] << endl;
    }
}

int main() {
    int size;
    cout << "Enter the number of equations (variables): ";
    cin >> size;
    vector<vector<float>> augmentedMatrix(size, vector<float>(size + 1));
    cout << "Enter the augmented matrix (coefficients + constants):\n";
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size + 1; col++) {
            cout << "a[" << row << "][" << col << "] = ";
            cin >> augmentedMatrix[row][col];
        }
    }
    solveGaussianElimination(augmentedMatrix, size);
    return 0;
}