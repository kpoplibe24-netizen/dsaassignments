#include<iostream>
#include<algorithm>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size;
    Heap(){
        arr[0]=-1;
        size=0;
    }
    void heapify(int arr1[],int n,int i){
        int largest=i;
        int left=2*i;
        int right=2*i+1;
        if(left<=n && arr1[largest]<arr1[left]){
            largest=left;
        }
        if(right<=n && arr1[largest]< arr1[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr1[largest], arr1[i]);
            heapify(arr1,n,largest);
        }
    }
    void heapsort(int arr[], int n){
        int size=n;
        while(size>1){
            swap(arr[size], arr[1]);
            size--;
            heapify(arr, size,1 );
        }
    }

};
int main(){
    Heap h;
    int arr1[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2; i>0;i--){
        h.heapify(arr1,n,i);
    }
    cout<<endl;
    h.heapsort(arr1,n);
    for(int i=1;i<=n;i++){
        cout<<arr1[i]<<" ";
    }
}
