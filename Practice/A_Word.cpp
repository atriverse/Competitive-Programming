#include <iostream>
#include <string>
#include <algorithm>

std::string correctWordCase(const std::string& word) {
    int uppercaseCount = 0;
    int lowercaseCount = 0;

    // Count uppercase and lowercase letters
    for (char c : word) {
        if (std::isupper(c)) {
            uppercaseCount++;
        } else {
            lowercaseCount++;
        }
    }

    std::string result = word;

    // Convert to appropriate case
    if (uppercaseCount > lowercaseCount) {
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    } else {
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    }

    return result;
}

int main() {
    std::string word;
    std::cin >> word;

    std::string correctedWord = correctWordCase(word);
    std::cout << correctedWord << std::endl;

    return 0;
}
