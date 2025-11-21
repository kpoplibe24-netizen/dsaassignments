#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    cout << "Enter numbers: ";
    for(int i=0;i<n;i++) cin >> arr[i];

    int start = 0, end = n-1;
    while(start < end) {
        int min = start;
        int max = start;

        for(int i=start; i<=end; i++){
            if(arr[i] < arr[min]) min = i;
            if(arr[i] > arr[max]) max= i;
        }
        int temp=arr[start];
        arr[start]=arr[min];
        arr[min]=temp;
        if(max==start) max=min;
        temp=arr[end];
        arr[end]=arr[max];
        arr[max] = temp;
        start++;
        end--;
    }
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
}
