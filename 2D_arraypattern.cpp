#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> arr){
    int rows = arr.size();
    int cols = arr[0].size();
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<arr[i][j]<<" ";
        }
    }
    cout<<endl;
}

//print column wave
void colwave(const vector<vector<int>>& arr) {
    int rows = arr.size();
    int cols = arr[0].size();

    for (int i = 0; i < rows; i++) {
        // If current row is even, print from left to right
        if (i % 2 == 0) {
            for (int j = 0; j < cols; j++) {
                cout << arr[i][j] << " ";
            }
        }
        // If current row is odd, print from right to left
        else {
            for (int j = cols - 1; j >= 0; j--) {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout<<endl;
}

//spiral print
void spiral(vector<vector<int>>& arr){
    int rows = arr.size();
    int cols = arr[0].size();
    
    int count=0;

    int s_col=0, e_col=cols-1, s_row=0, e_row=rows-1;
    
    while(count<rows*cols){
        //left to right
        for(int i=s_col; i<=e_col; i++){
            cout<<arr[s_row][i]<<" ";
            count++;
        }
        s_row++;
        //top to bottom
        for(int i=s_row; i<=e_row; i++){
            cout<<arr[i][e_col]<<" ";
            count++;
        }
        e_col--;
        //right to left
        for(int i=e_col; i>=s_col; i--){
            cout<<arr[e_row][i]<<" ";
            count++;
        }
        e_row--;
        //bottom to top
        for(int i=e_row; i>=s_row; i--){
            cout<<arr[i][s_col]<<" ";
            count++;
        }
        s_col++;
    }
    cout<<endl;
}

int main(){
    vector<vector<int>> arr={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    cout<<"Og. Matrix: ";
    print(arr);
    cout<<"Column Wave: ";
    colwave(arr);
    cout<<"Spiral Matrix: ";
    spiral(arr);
    return 0;
}

