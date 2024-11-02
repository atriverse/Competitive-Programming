#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> heights(n);
    int maxHeight = 0, minHeight = 101;
    int maxIndex = 0, minIndex = 0;
    
    // Read heights and find max and min positions
    for (int i = 0; i < n; i++) {
        std::cin >> heights[i];
        
        // Find leftmost maximum
        if (heights[i] > maxHeight) {
            maxHeight = heights[i];
            maxIndex = i;
        }
        
        // Find rightmost minimum
        if (heights[i] <= minHeight) {
            minHeight = heights[i];
            minIndex = i;
        }
    }
    
    // Calculate swaps needed
    int result = maxIndex + (n - 1 - minIndex);
    
    // If max index is after min index, we counted one position twice
    if (maxIndex > minIndex) {
        result--;
    }
    
    std::cout << result << std::endl;
    
    return 0;
}
