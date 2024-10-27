#include <iostream>
#include <set>

int main() {
    long long s1, s2, s3, s4;
    std::cin >> s1 >> s2 >> s3 >> s4;
    
    // Using set to store unique colors
    std::set<long long> colors;
    colors.insert(s1);
    colors.insert(s2);
    colors.insert(s3);
    colors.insert(s4);
    
    // Number of horseshoes to buy = 4 - number of unique colors
    int result = 4 - colors.size();
    
    std::cout << result << std::endl;
    
    return 0;
}
