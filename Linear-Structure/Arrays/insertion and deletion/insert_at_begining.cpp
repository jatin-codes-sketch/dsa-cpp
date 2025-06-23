#include<iostream>
using namespace std;

int capacity = 5;

bool arrFull(int size) {
    return capacity == size;
}

bool arrEmpty(int size) {
    return size == 0;
}

void insertAtBegin(int arr[], int val, int &size) {
    if (arrFull(size)) {
        cout << "Array is already full, cannot insert" << endl;
        return;
    }

    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = val;
    size++;
}

void deleteAtBegin(int arr[], int &size) {
    if (arrEmpty(size)) {
        cout << "Array is already empty" << endl;
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
}

int main() {
    int arr[5] = {1, 3, 5};
    int size = 3;

    insertAtBegin(arr, 12, size); // Inserting 12 at beginning
    deleteAtBegin(arr, size);     // Deleting from beginning

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
