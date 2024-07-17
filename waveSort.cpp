#include <iostream>
using namespace std;

void waveSort(int arr[], int n) {
    // Traverse all even indexed elements
    for (int i = 0; i < n; i += 2) {
        // If current even element is smaller than previous
        if (i > 0 && arr[i-1] > arr[i]) {
            swap(arr[i], arr[i-1]);
        }

        // If current even element is smaller than next
        if (i < n-1 && arr[i] < arr[i+1]) {
            swap(arr[i], arr[i+1]);
        }
    }
}

int main() {
    int arr[] = {10, 90, 49, 2, 1, 5, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    waveSort(arr, n);
    cout << "Wave sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
