#include <iostream>
#include <string>
using namespace std;

// Structure to hold name and score
struct Student {
    string name;
    int score;
};

// Partition function for QuickSort
int partition(Student arr[], int low, int high) {
    int pivot = arr[high].score;
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j].score <= pivot) { // Sort in ascending order of scores
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to display the array
void display(const Student arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Name: " << arr[i].name << ", Score: " << arr[i].score << "\n";
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Student students[n]; // Static array for students

    for (int i = 0; i < n; ++i) {
        cout << "Enter name and score for student " << i + 1 << ": ";
        cin >> students[i].name >> students[i].score;
    }
    cout << "\nBefore Sorting:\n";
    display(students, n);

    quickSort(students, 0, n - 1);

    cout << "\nAfter Sorting:\n";
    display(students, n);

    return 0;
}
