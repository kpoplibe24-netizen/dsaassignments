#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    cout << "Enter numbers: ";
    for(int i=0;i<n;i++) cin >> arr[i];

    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min]) min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    cout << "Selection Sort: ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
}
