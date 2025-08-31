#include<iostream>
using namespace std;

int main() {
    int m;
    cout<<"enter the number of rows ";
    cin>>m;
    int n;
    cout<<"enter the number of columns ";
    cin>>n;
    int arr1[m][n] ;
    cout<<"enter the array elements ";
    for(int i=0;i<m;i++){
        cout<<"enter the elements of row "<<i+1<<" -";
        for(int j=0;j<n;j++){
            cin>>arr1[i][j];
        }
    }


    int u;
    cout<<"enter the number of rows-";
    cin>>u;
    int v;
    cout<<"enter the number of columns-";
    cin>>v;
    int arr2[u][v] ;
    cout<<"enter the elements-";
    for(int i=0;i<u;i++){
        cout<<"enter the elements of row "<<i+1<<" -";
        for(int j=0;j<v;j++){
            cin>>arr2[i][j];
        }
    }
    int arr3[m][v];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < v; j++) {
            arr3[i][j] = 0;
            for (int k = 0; k < n; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < v; j++) {
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }
}
