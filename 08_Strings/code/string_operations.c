#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to count the number of words in a sentence
int countWords(char *sentence) {
    int count = 0;
    int inWord = 0; // Flag to track if we are inside a word
    int len = strlen(sentence);
    
    for (int i = 0; i < len; i++) {
        if (isalpha(sentence[i])) {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }
    
    return count;
}

// Function to count the number of vowels in a sentence
int countVowels(char *sentence) {
    int count = 0;
    int len = strlen(sentence);
    
    for (int i = 0; i < len; i++) {
        char ch = tolower(sentence[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    
    return count;
}

// Function to count the number of consonants in a sentence
int countConsonants(char *sentence) {
    int count = 0;
    int len = strlen(sentence);
    
    for (int i = 0; i < len; i++) {
        char ch = tolower(sentence[i]);
        if (isalpha(ch) && ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            count++;
        }
    }
    
    return count;
}

// Function to reverse a string
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main() {
    char sentence[100];
    
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    // Removing the newline character from fgets
    sentence[strcspn(sentence, "\n")] = '\0';
    
    printf("Number of words: %d\n", countWords(sentence));
    printf("Number of vowels: %d\n", countVowels(sentence));
    printf("Number of consonants: %d\n", countConsonants(sentence));
    
    printf("Reversed sentence: ");
    reverseString(sentence);
    printf("%s\n", sentence);
    
    printf("Uppercase sentence: ");
    for (int i = 0; sentence[i] != '\0'; i++) {
        putchar(toupper(sentence[i]));
    }
    printf("\n");
    
    return 0;
}
