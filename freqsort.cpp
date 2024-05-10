#include <stdio.h>
#include <string.h>

// Function to sort the string based on the frequency of characters
void sortCharsByFrequency(char str[]) {
    int freq[256] = {0}; // Assuming ASCII characters
    
    // Count frequency of each character
    for (int i = 0; i < strlen(str); i++) {
        freq[str[i]]++;
    }

    // Sort characters based on frequency
    for (int i = 0; i < strlen(str) - 1; i++) {
        for (int j = i + 1; j < strlen(str); j++) {
            if (freq[str[i]] > freq[str[j]] || (freq[str[i]] == freq[str[j]] && str[i] > str[j])) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

// Driver code
int main() {
    char str[] = "hello world";

    sortCharsByFrequency(str);

    printf("Sorted string based on frequency: %s\n", str);

    return 0;
}
