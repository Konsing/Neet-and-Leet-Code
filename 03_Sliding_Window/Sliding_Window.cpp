// Sliding Window

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> prices = {1, 2, 3, 4, 5}; // Example prices
    int k = 3; // Size of the window

    // Ensure k is valid
    if (k > prices.size()){
        cerr << "Window size k is larger than the number of elements in the vector." << endl;
        return -1;
    }

    // Calculate the sum of the first window
    int total = 0;
    for (int i = 0; i < k; ++i) {
        total += prices[i];
    }

    cout << "Sum of first window: " << total << endl;

    // Slide the window from the start to the end of the vector
    for (int i = k; i < prices.size(); ++i){
        total += prices[i] - prices[i - k];
        cout << "Sum of window ending at index " << i << ": " << total << endl;
    }

    return 0;
}