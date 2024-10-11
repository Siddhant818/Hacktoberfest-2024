#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Linear Search
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;  // Return the index of the target element
        }
    }
    return -1;  // Target element not found
}

// Binary Search (Iterative)
int binarySearch(const vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoids overflow

        if (arr[mid] == target) {
            return mid;  // Target found
        } else if (arr[mid] < target) {
            low = mid + 1;  // Search the right half
        } else {
            high = mid - 1;  // Search the left half
        }
    }

    return -1;  // Target not found
}

// Binary Search using STL
bool stlBinarySearch(const vector<int>& arr, int target) {
    return binary_search(arr.begin(), arr.end(), target);
}

// Function to display the array
void displayArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Menu-driven program for search algorithms
int main() {
    int n, target, choice;
    
    // Input size of array
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    
    // Input array elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    do {
        cout << "\nChoose a search algorithm:\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. STL Binary Search\n";
        cout << "4. Display Array\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice != 4 && choice != 5) {
            // Input target element
            cout << "Enter the element to search: ";
            cin >> target;
        }

        switch (choice) {
            case 1: {
                // Linear Search
                int result = linearSearch(arr, target);
                if (result != -1)
                    cout << "Element found at index " << result << endl;
                else
                    cout << "Element not found" << endl;
                break;
            }

            case 2: {
                // Binary Search (Ensure array is sorted)
                sort(arr.begin(), arr.end());
                int result = binarySearch(arr, target);
                if (result != -1)
                    cout << "Element found at index " << result << endl;
                else
                    cout << "Element not found" << endl;
                break;
            }

            case 3: {
                // STL Binary Search (Ensure array is sorted)
                sort(arr.begin(), arr.end());
                bool found = stlBinarySearch(arr, target);
                if (found)
                    cout << "Element found using STL Binary Search" << endl;
                else
                    cout << "Element not found" << endl;
                break;
            }

            case 4: {
                // Display Array
                cout << "Array elements: ";
                displayArray(arr);
                break;
            }

            case 5: {
                cout << "Exiting...\n";
                break;
            }

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
