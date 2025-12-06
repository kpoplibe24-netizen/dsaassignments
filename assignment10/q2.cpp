#include<iostream>
using namespace std;

#define MAX 100000

void find(int arr[], int n){
    int hash[MAX]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    for(int i=0;i<n;i++){
        if(hash[arr[i]]==1){
            cout<<arr[i];
            break;
        }
    }

}
int main(){
    int arr[]={4,5,1,2,0,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    find(arr,n);


}
