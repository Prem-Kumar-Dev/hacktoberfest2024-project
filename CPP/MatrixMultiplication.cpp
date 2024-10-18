#include <iostream>
using namespace std;

void multiplyMatrices(int firstMatrix[][3], int secondMatrix[][3], int resultMatrix[][3], int row1, int col1, int row2, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[][3], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int firstMatrix[3][3] = { {2, 4, 1}, {3, 5, 7}, {5, 6, 8} };
    int secondMatrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int resultMatrix[3][3];
    
    multiplyMatrices(firstMatrix, secondMatrix, resultMatrix, 3, 3, 3, 3);
    
    cout << "Resultant Matrix after Multiplication: \n";
    displayMatrix(resultMatrix, 3, 3);
    
    return 0;
}
