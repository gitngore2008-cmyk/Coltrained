#include <stdio.h>
int main() {
    int i;
    float f;
    char c;
    printf("Enter an integer: ");
    scanf("%d", &i);
    printf("Enter a float: ");
    scanf("%f", &f);
    printf("Enter a character: ");
    scanf(" %c", &c); // Space to consume newline
    printf("Integer: %d, Float: %f, Character: %c\n", i, f, c);
    return 0;
}