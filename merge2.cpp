#include <iostream>
#include <string>
using namespace std;

// Merge function
void merge(string arr[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    string temp[right - left + 1]; // Temporary array

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int t = 0; t < k; t++) {
        arr[left+t] = temp[t];
    }
}
// Merge Sort function
void mergeSort(string arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Function to display the array
void display(string arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    string arr[n];

    cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "\nAfter Sorting:\n";
    display(arr, n);

    return 0;
}
