#include<iostream>
#include<unordered_map>
using namespace std;
#define MAX 1000
int main(){
    unordered_map<int,int> freq;
    int arr[]={10,20,10,20,30,20,20};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    int maxfreq=0;
    int result=-1;
    
    for(auto &p:freq){
        int element=p.first;
        int count=p.second;
        
        if(count>maxfreq){
            maxfreq=count;
            result =element;
        }
        else if(maxfreq==count && element>result){
            result =element;
        }
    }
    cout<<"max freq is of "<< result;
}
