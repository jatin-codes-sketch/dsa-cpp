#include<iostream>
#include<vector>
#include<cstdlib> // For abs()
using namespace std;

// Function to count digits
int count_digits(int n) {
    if (n == 0) return 1;
    n = abs(n);
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

// Function to sum digits
int sum_of_digits(int n) {
    n = abs(n);
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Function to print digits
void print_digits(int n) {
    if (n == 0) {
        cout << "0";
        return;
    }

    n = abs(n);
    vector<int> digits;

    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }

    for (int i = digits.size() - 1; i >= 0; i--) {
        cout << digits[i] << " ";
    }
}

int main() {
    int choice;
    int number;

    do {
        cout << "1. Count digits\n";
        cout << "2. Sum of digits\n";
        cout << "3. Print all digits\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            cout << "Enter a number: ";
            cin >> number;
        }

        switch (choice) {
            case 1:
                cout << "Number of digits: " << count_digits(number) << endl;
                break;
            case 2:
                cout << "Sum of digits: " << sum_of_digits(number) << endl;
                break;
            case 3:
                cout << "Digits: ";
                print_digits(number);
                cout << endl;
                break;
            case 0:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
