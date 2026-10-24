// Created by Thanh Dat Nguyen (dat_nguyen2284@gmail.com) on 2026-10-24

// Last modified by Thanh Dat Nguyen (dat_nguyen2284@gmail.com) on 2026-10-24

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

/** Reverses the elements form start to end (inclusive).
    @param vec: The vector containing the elements.
    @param start: The index of the first element.
    @param end: The index of the last element.
 */
void reverse(vector<int>& vec, size_t start, size_t end) {
    while(start < end) {
        swap(vec.at(start), vec.at(end));
        ++start;
        --end;
    }
} // Time complexity: O(n), Space complexity: O(1)

/** Rotates the elements of the vector to the right by k positions.
    @param vec: The vector containing the elements.
    @param k: The number of positions to rotate.
*/
void rotate_array(vector<int>& vec, size_t k) {
    size_t n = vec.size();

    if(n <= 1) { return; } // No need to rotate if the array has 0 or 1 element

    k = k % n; // Handle cases where k is greater than n

    if(k == 0) { return; } // No need to rotate if k is 0 or a multiple of n

    // Step 1: Reverse the entire array
    reverse(vec, 0, n - 1);

    // Step 2: Reverse the first k elements
    reverse(vec, 0, k - 1);

    // Step 3: Reverse the remaining (n - k)elements
    reverse(vec, k, n - 1);
}

/** Prints the elements of the vector.
    @param vec: The vector containing the elements.
 */
void print_vector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec.at(i); // Print each element of the vector
        if (i != vec.size() - 1) {
            cout << ", "; // Add a comma and space between elements
        }
    }
    cout << "]" << endl << endl;;
}

/** Tests the rotate_array function.
    @param input: The input vector.
    @param k: The number of positions to rotate.
    @param expected: The expected result.
 */
void test_rotate(vector<int> input, int k, const vector<int>& expected) {
    rotate_array(input, k);
    assert(input == expected);
}
int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};

    cout << "Original array: " << endl;
    print_vector(vec);

    rotate_array(vec, 3);

    cout << "Array after rotating right by 3 positions: \n";
    print_vector(vec);
    cout << endl;

    // Additional test cases
    test_rotate({1, 2, 3, 4, 5}, 2, {4, 5, 1, 2, 3});
    test_rotate({1, 2, 3, 4, 5}, 0, {1, 2, 3, 4, 5});
    test_rotate({1, 2, 3, 4, 5}, 5, {1, 2, 3, 4, 5});
    test_rotate({1, 2, 3, 4, 5}, 7, {4, 5, 1, 2, 3});
    test_rotate({}, 3, {});
    test_rotate({10}, 4, {10});
    test_rotate({1, 2}, 1, {2, 1});
    test_rotate({1, 1, 2, 2, 3}, 2, {2, 3, 1, 1, 2});
    test_rotate({-3, -2, -1, 0, 1}, 3, {-1, 0, 1, -3, -2});
    cout << "All test cases passed!" << endl;

    return 0;
}