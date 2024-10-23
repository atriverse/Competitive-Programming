#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    
    // For even n: f(n) = n/2
    // For odd n:  f(n) = -(n+1)/2
    long long result = (n % 2 == 0) ? n/2 : -(n+1)/2;
    
    std::cout << result << std::endl;
    
    return 0;
}
