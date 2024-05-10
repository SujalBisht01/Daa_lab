#include <iostream>
#include <string>

void findMatchingElements(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();

    int matchCount = 0;
    int matchIndex = -1;
    int cnt = 0;
    // Iterate through the text string
    for (int i = 0; i <= n - m; ++i) {
        bool matchFound = true;
        // Check if the current substring of text matches the pattern
        for (int j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j]) {
                matchFound = false;
                break;
            }
        }
        // If match found, update match count and index
        if (matchFound) {
            matchCount++;
            if(cnt<1){
            matchIndex = i;
            cnt++;
        }
        }
    }

    std::cout << "Number of matching elements: " << matchCount << std::endl;
    if (matchCount > 0) {
        std::cout << "Index of first match: " << matchIndex << std::endl;
    }
}

int main() {
    std::string text = "abcdeabcfghijabc";
    std::string pattern = "abc";

    findMatchingElements(text, pattern);

    return 0;
}
