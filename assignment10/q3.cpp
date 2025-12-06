#include<iostream>
using namespace std;
#define MAX 1000
int main(){
    int arr[]={2,3,2,4,3,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    int hash[MAX]={0};
    
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    for (int i = 0; i < MAX; i++) {
        if (hash[i] > 0) {
            cout << i << " → " << hash[i] << " times" << endl;
        }
    }
}
