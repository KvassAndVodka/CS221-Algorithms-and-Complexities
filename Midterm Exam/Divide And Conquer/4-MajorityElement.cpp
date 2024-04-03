#include <iostream>
#include <vector>

int countOccurrences(const std::vector<int>& arr, int x) {
    int count = 0;
    for (int num : arr) {
        if (num == x) {
            count++;
        }
    }
    return count;
}

int majorityElementUtil(const std::vector<int>& arr, int left, int right) {
    // Base case: if the subarray has only one element, return that element
    if (left == right) {
        return arr[left];
    }

    int mid = left + (right - left) / 2;

    // Recursively find the majority element in the left and right subarrays
    int leftMajority = majorityElementUtil(arr, left, mid);
    int rightMajority = majorityElementUtil(arr, mid + 1, right);

    // If the majority elements in the left and right subarrays are the same, return it
    if (leftMajority == rightMajority) {
        return leftMajority;
    }

    // Otherwise, count the occurrences of leftMajority and rightMajority in the entire subarray
    int leftCount = countOccurrences(arr, leftMajority);
    int rightCount = countOccurrences(arr, rightMajority);

    // Return the element with more than n/2 occurrences, where n is the size of the subarray
    return (leftCount > (right - left + 1) / 2) ? leftMajority : rightMajority;
}

int majorityElement(const std::vector<int>& arr) {
    if (arr.empty()) {
        return -1; // No majority element if the array is empty
    }
    return majorityElementUtil(arr, 0, arr.size() - 1);
}

int main() {
    std::vector<int> arr = {3, 2, 3, 1, 3, 4, 3, 8, 3};
    std::cout << "Given array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int majorityElem = majorityElement(arr);
    std::cout << "Majority element: " << majorityElem << " (appears " << countOccurrences(arr, majorityElem) << " times)" << std::endl;

    return 0;
}