#include <iostream>

using namespace std;

int median_of_three(int arr[], int left, int right) {
    /*
     * Finds the median of the left, right, and middle elements of the subarray.
     */
    int mid = left + (right - left) / 2;
    int values[3] = {arr[left], arr[mid], arr[right]};
    
    // Sort the values array
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (values[j] < values[i]) {
                int temp = values[i];
                values[i] = values[j];
                values[j] = temp;
            }
        }
    }
    
    // Find the index of the median value in the original array
    int pivot_index;
    if (arr[left] == values[1]) {
        pivot_index = left;
    } else if (arr[mid] == values[1]) {
        pivot_index = mid;
    } else {
        pivot_index = right;
    }
    
    return pivot_index;
}

int partition(int arr[], int left, int right) {
    /*
     * Partitions the subarray around the pivot element.
     */
    int pivot_index = median_of_three(arr, left, right);
    int pivot_value = arr[pivot_index];
    
    // Swap pivot with rightmost element
    arr[pivot_index] = arr[right];
    arr[right] = pivot_value;
    
    int store_index = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivot_value) {
            // Swap arr[i] and arr[store_index]
            int temp = arr[i];
            arr[i] = arr[store_index];
            arr[store_index] = temp;
            store_index++;
        }
    }
    
    // Swap pivot back to its final place
    arr[right] = arr[store_index];
    arr[store_index] = pivot_value;
    
    return store_index;
}

void quick_sort(int arr[], int left, int right) {
    /*
     * Recursively sorts the array using Quick Sort with Median of Three pivot selection.
     */
    if (left < right) {
        int pivot_index = partition(arr, left, right);
        quick_sort(arr, left, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, right);
    }
}

int main() {
    int given_array[] = {8, 2, 4, 9, 1, 7, 5};
    int size = sizeof(given_array) / sizeof(given_array[0]);

    cout << "Given array: ";
    for (int i = 0; i < size; i++) {
        cout << given_array[i] << " ";
    }
    cout << endl;

    quick_sort(given_array, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << given_array[i] << " ";
    }
    cout << endl;

    return 0;
}