#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

const int ROWS1 = 7, COLS1 = 6;  
const int ROWS2 = 5, COLS2 = 9;  
const int MIN_VAL = 7, MAX_VAL1 = 62, MAX_VAL2 = 65;

void generateMatrix(vector<vector<int>>& matrix, int rows, int cols, int minVal, int maxVal, int row = 0, int col = 0) 
{
    if (row == rows) 
        return; 
    if (col == cols) 
    {
        generateMatrix(matrix, rows, cols, minVal, maxVal, row + 1, 0); 
    } 
    else 
    {
        matrix[row][col] = minVal + rand() % (maxVal - minVal + 1);
        generateMatrix(matrix, rows, cols, minVal, maxVal, row, col + 1); 
    }
}

void processMatrixElements(vector<vector<int>>& matrix, int& count, int& sum, int row = 0, int col = 0) 
{
    if (row == matrix.size()) 
        return; 
    if (col == matrix[row].size()) 
    {
        processMatrixElements(matrix, count, sum, row + 1, 0); 
    } 
    else 
    {
        if (matrix[row][col] % 2 == 0 && (row + col) % 8 != 0) 
        { 
            sum += matrix[row][col];
            count++;
            matrix[row][col] = 0; 
        }
        processMatrixElements(matrix, count, sum, row, col + 1); 
    }
}

void printMatrix(const vector<vector<int>>& matrix, int row = 0, int col = 0) 
{
    if (row == matrix.size()) 
    {
        cout << endl;
        return; 
    }
    if (col == matrix[row].size()) 
    {
        cout << endl;
        printMatrix(matrix, row + 1, 0); 
    } 
    else 
    {
        cout << setw(4) << matrix[row][col];
        printMatrix(matrix, row, col + 1); 
    }
}

void sortMatrix(vector<vector<int>>& matrix, int keyRow, int row = 0, int col = 0) 
{
    if (col == matrix[0].size() - 1) 
        return; 
    if (row == matrix.size() - 1) 
    {
        sortMatrix(matrix, keyRow, 0, col + 1); 
    } 
    else 
    {
        if (matrix[row][col] < matrix[row + 1][col]) 
        {
            swap(matrix[row][col], matrix[row + 1][col]); 
        }
        sortMatrix(matrix, keyRow, row + 1, col); 
    }
}

int main() 
{
    srand(time(0)); 

    vector<vector<int>> matrix1(ROWS1, vector<int>(COLS1));
    generateMatrix(matrix1, ROWS1, COLS1, MIN_VAL, MAX_VAL1);
    cout << "Original Matrix 7x6:\n";
    printMatrix(matrix1);

    int count1 = 0, sum1 = 0;
    processMatrixElements(matrix1, count1, sum1);
    cout << "\nProcessed Matrix 7x6 (zeros for specific elements):\n";
    printMatrix(matrix1);
    cout << "Count: " << count1 << ", Sum: " << sum1 << endl;

    sortMatrix(matrix1, 0); 
    cout << "\nSorted Matrix 7x6:\n";
    printMatrix(matrix1);

    
    vector<vector<int>> matrix2(ROWS2, vector<int>(COLS2));
    generateMatrix(matrix2, ROWS2, COLS2, MIN_VAL, MAX_VAL2);
    cout << "\nOriginal Matrix 5x9:\n";
    printMatrix(matrix2);

    int count2 = 0, sum2 = 0;
    processMatrixElements(matrix2, count2, sum2);
    cout << "\nProcessed Matrix 5x9 (zeros for specific elements):\n";
    printMatrix(matrix2);
    cout << "Count: " << count2 << ", Sum: " << sum2 << endl;

    sortMatrix(matrix2, 0); 
    cout << "\nSorted Matrix 5x9:\n";
    printMatrix(matrix2);

    return 0;
}
