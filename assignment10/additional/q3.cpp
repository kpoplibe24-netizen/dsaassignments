#include<iostream>
#include<unordered_map>
using namespace std;
#define MAX 1000
int main(){
    unordered_map<int,int> m1;
    unordered_map<int,int> m2;
    // bool found=false;
    int arr1[]={1,2,5,4,0};
    int arr2[]={2,4,5,0,8};
    int m=sizeof(arr1)/sizeof(arr1[0]);
    int n=sizeof(arr2)/sizeof(arr2[0]);
    for(int i=0;i<m;i++){
        m1[arr1[i]]++;
    }
    for(int i=0;i<n;i++){
        m2[arr2[i]]++;
    }
    
    if(m1==m2) cout<<"same";
    else cout<<"not same";
}
