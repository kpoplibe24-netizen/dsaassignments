#include<iostream>
using namespace std;
int main(){
    int A[]={1,2,3,4};
    int B[]={3,4,5,6};

    int n=sizeof(A)/sizeof(A[0]);
    int m=sizeof(B)/sizeof(B[0]);

    int maxval=0;
    for(int i=0;i<n;i++){
        if(maxval<A[i]) maxval=A[i];
    }
    for(int i=0;i<m;i++){
        if(maxval<B[i]) maxval=B[i];
    }

    int hasha[maxval+1]={0};

    for(int i=0;i<n;i++){
        hasha[A[i]]=1;
    }

    for(int i=0;i<m;i++){
        if(hasha[B[i]]==1){
            cout<<B[i];
        }
        B[i]=0;
    }
}
