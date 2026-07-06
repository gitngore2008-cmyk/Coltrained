//  Find the length of a string without using strlen

#include <stdio.h>
int main() {
    char str[100] = "Hello, World!";
    int len = 0;
    while (str[len] != '\0') len++;
    printf("Length: %d\n", len);
    return 0;
}




// 55. Copy one string to another without strcpy


#include <stdio.h>
int main() {
    char src[100] = "Hello, World!";
    char dest[100];
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    printf("Copied string: %s\n", dest);
    return 0;
}




// 56. Concatenate two strings without strcat

#include <stdio.h>
int main() {
    char str1[100] = "Hello, ";
    char str2[100] = "World!";
    int i = 0, j = 0;
    while (str1[i] != '\0') i++;
    while (str2[j] != '\0') {
        str1[i + j] = str2[j];
        j++;
    }
    str1[i + j] = '\0';
    printf("Concatenated: %s\n", str1);
    return 0;
}




// 57. Compare two strings without strcmp
#include <stdio.h>
int main() {
    char str1[100] = "Hello";
    char str2[100] = "World";
    int i = 0, result = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            result = str1[i] - str2[i];
            break;
        }
        i++;
    }
    if (result == 0) printf("Strings are equal\n");
    else if (result < 0) printf("String 1 is less than String 2\n");
    else printf("String 1 is greater than String 2\n");
    return 0;
}




// 58. Reverse a string

#include <stdio.h>
int main() {
    char str[100] = "Hello, World!";
    int len = 0;
    while (str[len] != '\0') len++;
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    printf("Reversed: %s\n", str);
    return 0;
}




// 59. Check if a string is a Palindrome
#include <stdio.h>
#include <ctype.h>
int main() {
    char str[100] = "Madam";
    int len = 0;
    while (str[len] != '\0') len++;
    int isPalindrome = 1;
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (tolower(str[i]) != tolower(str[j])) {
            isPalindrome = 0;
            break;
        }
    }
    printf("String is %s\n", isPalindrome ? "a palindrome" : "not a palindrome");
    return 0;
}




// 60. Count the number of vowels, consonants, digits, and spaces in a string
#include <stdio.h>
#include <ctype.h>
int main() {
    char str[100] = "Hello, World! 123";
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);
        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vowels++;
            else
                consonants++;
        } else if (isdigit(c)) digits++;
        else if (c == ' ') spaces++;
    }
    printf("Vowels: %d, Consonants: %d, Digits: %d, Spaces: %d\n",
           vowels, consonants, digits, spaces);
    return 0;
}




// 61. Convert a string to lowercase/uppercase

#include <stdio.h>
#include <ctype.h>
int main() {
    char str[100] = "Hello, World!";
    // Convert to lowercase
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
    printf("Lowercase: %s\n", str);
    // Convert to uppercase
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
    printf("Uppercase: %s\n", str);
    return 0;
}




// 62. Sort a set of strings in alphabetical order

#include <stdio.h>
#include <string.h>
int main() {
    char str[5][100] = {"banana", "apple", "orange", "grape", "kiwi"};
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                char temp[100];
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
    printf("Sorted strings:\n");
    for (int i = 0; i < 5; i++) printf("%s\n", str[i]);
    return 0;
}




// 63. Remove all characters in a string except alphabets

#include <stdio.h>
#include <ctype.h>
int main() {
    char str[100] = "Hello, World! 123";
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    printf("Only alphabets: %s\n", str);
    return 0;
}




// 64. Find the frequency of characters in a string

#include <stdio.h>
int main() {
    char str[100] = "hello";
    int freq[256] = {0}; // Assuming ASCII
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }
    printf("Character frequencies:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("%c: %d\n", (char)i, freq[i]);
        }
    }
    return 0;
}



