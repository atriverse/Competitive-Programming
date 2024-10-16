#include <iostream>
#include <set>

bool hasDistinctDigits(int year) {
    std::set<int> digits;
    while (year > 0) {
        int digit = year % 10;
        if (digits.find(digit) != digits.end()) {
            return false;
        }
        digits.insert(digit);
        year /= 10;
    }
    return true;
}

int findNextBeautifulYear(int year) {
    while (true) {
        year++;
        if (hasDistinctDigits(year)) {
            return year;
        }
    }
}

int main() {
    int y;
    std::cin >> y;
    
    int result = findNextBeautifulYear(y);
    std::cout << result << std::endl;
    
    return 0;
}
