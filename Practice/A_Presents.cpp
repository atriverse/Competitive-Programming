#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> result(n + 1);
    
    // For each friend i, store who gave them a gift
    for (int i = 1; i <= n; i++) {
        int p;
        std::cin >> p;
        result[p] = i;
    }
    
    // Print the results
    for (int i = 1; i <= n; i++) {
        std::cout << result[i] << (i == n ? '\n' : ' ');
    }
    
    return 0;
}
