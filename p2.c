#include <stdio.h>
int main() {
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);
    if (a >= b && a >= c) printf("%d is largest\n", a);
    else if (b >= a && b >= c) printf("%d is largest\n", b);
    else printf("%d is largest\n", c);
    return 0;
}
#include <stdio.h>
int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
        printf("%d is a leap year\n", year);
    else
        printf("%d is not a leap year\n", year);
    return 0;
}
#include <stdio.h>
#include <ctype.h>
int main() {
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        printf("%c is a vowel\n", c);
    else if (isalpha(c))
        printf("%c is a consonant\n", c);
    else
        printf("Not a valid alphabet\n");
    return 0;
}


#include <stdio.h>
#include <math.h>
int main() {
    float a, b, c, d, r1, r2, real, imag;
    printf("Enter coefficients a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);
    d = b*b - 4*a*c;
    if (d > 0) {
        r1 = (-b + sqrt(d)) / (2*a);
        r2 = (-b - sqrt(d)) / (2*a);
        printf("Roots: %.2f, %.2f\n", r1, r2);
    } else if (d == 0) {
        r1 = -b / (2*a);
        printf("Root: %.2f\n", r1);
    } else {
        real = -b / (2*a);
        imag = sqrt(-d) / (2*a);
        printf("Roots: %.2f + %.2fi, %.2f - %.2fi\n", real, imag, real, imag);
    }
    return 0;
}




#include <stdio.h>
int main() {
    char op;
    float a, b;
    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &op);
    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);
    switch(op) {
        case '+': printf("%.2f + %.2f = %.2f\n", a, b, a+b); break;
        case '-': printf("%.2f - %.2f = %.2f\n", a, b, a-b); break;
        case '*': printf("%.2f * %.2f = %.2f\n", a, b, a*b); break;
        case '/': printf("%.2f / %.2f = %.2f\n", a, b, a/b); break;
        default: printf("Invalid operator\n");
    }
    return 0;
}





#include <stdio.h>
#include <ctype.h>
int main() {
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);
    if (isalpha(c)) printf("%c is an alphabet\n", c);
    else if (isdigit(c)) printf("%c is a digit\n", c);
    else printf("%c is a special character\n", c);
    return 0;
}



#include <stdio.h>
int main() {
    int n, fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) fact *= i;
    printf("Factorial of %d: %d\n", n, fact);
    return 0;
}





#include <stdio.h>
int main() {
    int n, a = 0, b = 1, c;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    return 0;
}






#include <stdio.h>
int main() {
    int n, isPrime = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            isPrime = 0;
            break;
        }
    }
    printf("%d is %s\n", n, isPrime ? "prime" : "not prime");
    return 0;
}




#include <stdio.h>
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int isPrime = 1;
        for (int j = 2; j <= i/2; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) printf("%d ", i);
    }
    return 0;
}


#include <stdio.h>
int main() {
    int n, rev = 0, temp;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;
    while (temp != 0) {
        rev = rev * 10 + temp % 10;
        temp /= 10;
    }
    printf("%d is %s\n", n, (n == rev) ? "palindrome" : "not palindrome");
    return 0;
}



#include <stdio.h>
#include <math.h>
int main() {
    int n, sum = 0, temp, digits = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }
    temp = n;
    while (temp != 0) {
        sum += pow(temp % 10, digits);
        temp /= 10;
    }
    printf("%d is %s\n", n, (n == sum) ? "Armstrong" : "not Armstrong");
    return 0;
}






#include <stdio.h>
int fact(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}
int main() {
    int n, sum = 0, temp;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;
    while (temp != 0) {
        sum += fact(temp % 10);
        temp /= 10;
    }
    printf("%d is %s\n", n, (n == sum) ? "Strong" : "not Strong");
    return 0;
}

#include <stdio.h>
int main() {
    int n, rev = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n != 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    printf("Reversed: %d\n", rev);
    return 0;
}




#include <stdio.h>
int main() {
    int n, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    printf("Sum of digits: %d\n", sum);
    return 0;
}




#include <stdio.h>
int main() {
    int a, b, gcd, lcm;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    for (int i = 1; i <= a && i <= b; i++) {
        if (a % i == 0 && b % i == 0) gcd = i;
    }
    lcm = (a * b) / gcd;
    printf("GCD: %d, LCM: %d\n", gcd, lcm);
    return 0;
}
#include <stdio.h>
int main() {
    int n = 5; // Number of rows
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
int main() {
    int n = 5;
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Print stars
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
int main() {
    int n = 5;
    // Upper half
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++) printf("*");
        printf("\n");
    }
    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++) printf("*");
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
int main() {
    int n = 5;
    for (int i = 0; i < n; i++) {
        int num = 1;
        for (int j = 0; j <= i; j++) {
            printf("%d ", num);
            num = num * (i - j) / (j + 1);
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
int main() {
    int n = 5, num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", num++);
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}




