#include <stdio.h>
#include <math.h>
#include <string.h>

// Problem 65
int isPrime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return 0;
    return 1;
}

int isArmstrong(int n) {
    int temp = n, sum = 0, digits = 0;
    while (temp > 0) { temp /= 10; digits++; }
    temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        sum += pow(digit, digits);
        temp /= 10;
    }
    return sum == n;
}

int isPerfect(int n) {
    if (n <= 1) return 0;
    int sum = 1;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            sum += i;
            if (i != n / i) sum += n / i;
        }
    return sum == n;
}

// Problem 67
int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

// Problem 68
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// Problem 69
void towerOfHanoi(int n, char source, char dest, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }
    towerOfHanoi(n - 1, source, aux, dest);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    towerOfHanoi(n - 1, aux, dest, source);
}

// Problem 71
double power(double base, int exp) {
    if (exp == 0) return 1;
    if (exp < 0) return 1 / power(base, -exp);
    return base * power(base, exp - 1);
}

// Problem 72
int sumNatural(int n) {
    return (n <= 0) ? 0 : n + sumNatural(n - 1);
}

// Problem 70
void reverseSentence(char *str) {
    int len = strlen(str);
    
    void reverse(char *s, int start, int end){
        if (start >= end) return;
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        reverse(s, start + 1, end - 1);
    }
    
    void reverseWords(char *s, int start, int end) {
        if (start >= end) return;
        
        int wordStart = start;
        while (start < end && s[start] != ' ') start++;
        
        reverse(s, wordStart, start - 1);
        
        while (start < end && s[start] == ' ') start++;
        if (start < end)
            reverseWords(s, start, end);
    }
    
    reverseWords(str, 0, len - 1);
}

int main() {
    printf("=== Problem 65: Number Types ===\n");
    int num = 153;
    printf("%d: Prime=%d, Armstrong=%d, Perfect=%d\n",
           num, isPrime(num), isArmstrong(num), isPerfect(num));
    
    printf("\n=== Problem 67: Factorial ===\n");
    int n = 5;
    printf("Factorial of %d: %d\n", n, factorial(n));
    
    printf("\n=== Problem 68: GCD ===\n");
    int a = 48, b = 18;
    printf("GCD of %d and %d: %d\n", a, b, gcd(a, b));
    
    printf("\n=== Problem 69: Tower of Hanoi ===\n");
    towerOfHanoi(3, 'A', 'C', 'B');
    
    printf("\n=== Problem 71: Power ===\n");
    double base = 2.0;
    int exp = 5;
    printf("%.1f^%d = %.1f\n", base, exp, power(base, exp));
    
    printf("\n=== Problem 72: Sum Natural Numbers ===\n");
    n = 10;
    printf("Sum of first %d natural numbers: %d\n", n, sumNatural(n));
    
    printf("\n=== Problem 70: Reverse Sentence ===\n");
    char str[] = "Hello world this is C";
    printf("Original: %s\n", str);
    reverseSentence(str);
    printf("Reversed: %s\n", str);
    
    return 0;
}
