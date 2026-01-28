#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>>& matrix){
    int n = matrix.size();
    // Transpose the matrix
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            swap(matrix[i][j], matrix[j][i]);

    // Reverse each row
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n / 2; ++j)
            swap(matrix[i][j], matrix[i][n - 1 - j]);

}

void printMatrix(const vector<vector<int>>& matrix){
    for (const auto& row : matrix){
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main(){
    vector<vector<int>> matrix ={{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    int n = matrix.size() ,m = matrix[0].size();

    cout<<n<<" "<<m<<endl;

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    rotateMatrix(matrix);

    cout << "\nRotated Matrix:" << endl;
    printMatrix(matrix);

    return 0;
}
