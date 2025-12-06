#include<iostream>
#include<unordered_set>
using namespace std;
#define MAX 1000
int main(){
    unordered_set<int> seen;
    int target;
    cout<<"enter target: ";
    cin>>target;
    bool found=false;
    int arr[]={0, -1, 2, -3, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0;i<n;i++){
        int complement=target-arr[i];
        
        if(seen.find(complement)!=seen.end()){
            cout<<"Pair: ("<<complement<<","<<arr[i]<<")";
            cout<<endl;
            found=true;
        }
        // cout<<endl;
        seen.insert(arr[i]);
    }
    if(!found) cout<<"sad :(";
}
