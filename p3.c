



// 36. Find the sum and average of array elements

#include <stdio.h>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int sum = 0;
    for (int i = 0; i < 5; i++) sum += arr[i];
    printf("Sum: %d, Average: %.2f\n", sum, (float)sum / 5);
    return 0;
}




// 37. Find the largest and smallest element in an array


#include <stdio.h>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int max = arr[0], min = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    printf("Max: %d, Min: %d\n", max, min);
    return 0;
}




// 38. Reverse an array in place (without a second array)


#include <stdio.h>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    for (int i = 0, j = 4; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    printf("Reversed array: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    return 0;
}




// 39. Insert an element at a specific position in an array
#include <stdio.h>
int main() {
    int arr[6] = {10, 20, 30, 40, 50};
    int pos = 2, val = 25;
    for (int i = 5; i >= pos; i--) arr[i] = arr[i-1];
    arr[pos] = val;
    printf("Array after insertion: ");
    for (int i = 0; i < 6; i++) printf("%d ", arr[i]);
    return 0;
}




// 40. Delete an element from a specific position


#include <stdio.h>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int pos = 2;
    for (int i = pos; i < 4; i++) arr[i] = arr[i+1];
    printf("Array after deletion: ");
    for (int i = 0; i < 4; i++) printf("%d ", arr[i]);
    return 0;
}




// 41. Remove duplicate elements from an array


#include <stdio.h>
int main() {
    int arr[7] = {10, 20, 20, 30, 40, 40, 50};
    int n = 7, j;
    for (int i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n-1; k++) arr[k] = arr[k+1];
                n--;
                j--;
            }
        }
    }
    printf("Array after removing duplicates: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}




// 42. Merge two arrays

#include <stdio.h>
int main() {
    int arr1[3] = {10, 20, 30};
    int arr2[3] = {40, 50, 60};
    int merged[6], i, j;
    for (i = 0; i < 3; i++) merged[i] = arr1[i];
    for (j = 0; j < 3; j++) merged[i+j] = arr2[j];
    printf("Merged array: ");
    for (int k = 0; k < 6; k++) printf("%d ", merged[k]);
    return 0;
}




// 43. Rotate an array left or right by N positions

#include <stdio.h>
void rotateLeft(int arr[], int n, int d) {
    for (int i = 0; i < d; i++) {
        int temp = arr[0];
        for (int j = 0; j < n-1; j++) arr[j] = arr[j+1];
        arr[n-1] = temp;
    }
}
void rotateRight(int arr[], int n, int d) {
    for (int i = 0; i < d; i++) {
        int temp = arr[n-1];
        for (int j = n-1; j > 0; j--) arr[j] = arr[j-1];
        arr[0] = temp;
    }
}
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    rotateLeft(arr, 5, 2);
    printf("Left rotated: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    rotateRight(arr, 5, 1);
    printf("\nRight rotated: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    return 0;
}




// 44. Linear Search: Find an element in an array


#include <stdio.h>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int key = 30, found = 0;
    for (int i = 0; i < 5; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) printf("Element not found\n");
    return 0;
}




// 45. Binary Search: Find an element in a sorted array

#include <stdio.h>
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int key = 30, low = 0, high = 4, mid, found = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        } else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    if (!found) printf("Element not found\n");
    return 0;
}




// 46. Bubble Sort: Sort an array in ascending order

#include <stdio.h>
int main() {
    int arr[5] = {50, 20, 30, 10, 40};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    return 0;
}




// 47. Selection Sort: Sort an array

#include <stdio.h>
int main() {
    int arr[5] = {50, 20, 30, 10, 40};
    for (int i = 0; i < 4; i++) {
        int min_idx = i;
        for (int j = i+1; j < 5; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
    printf("Sorted array: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    return 0;
}




// 2D Arrays (Matrices)

// 48. Add two matrices


#include <stdio.h>
int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int c[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("Sum of matrices:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) printf("%d ", c[i][j]);
        printf("\n");
    }
    return 0;
}




// 49. Multiply two matrices

#include <stdio.h>
int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int c[2][2] = {0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    printf("Product of matrices:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) printf("%d ", c[i][j]);
        printf("\n");
    }
    return 0;
}




// 50. Find the Transpose of a matrix

#include <stdio.h>
int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int t[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            t[j][i] = a[i][j];
        }
    }
    printf("Transpose of matrix:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) printf("%d ", t[i][j]);
        printf("\n");
    }
    return 0;
}




// 51. Check if a matrix is symmetric

#include <stdio.h>
int main() {
    int a[2][2] = {{1, 2}, {2, 1}};
    int isSymmetric = 1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (a[i][j] != a[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
    }
    printf("Matrix is %s\n", isSymmetric ? "symmetric" : "not symmetric");
    return 0;
}




// 52. Calculate the sum of diagonal elements

#include <stdio.h>
int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int sum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (i == j) sum += a[i][j];
        }
    }
    printf("Sum of diagonal elements: %d\n", sum);
    return 0;
}




// 53. Check if two matrices are equal
#include <stdio.h>
int main() {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{1, 2}, {3, 4}};
    int isEqual = 1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (a[i][j] != b[i][j]) {
                isEqual = 0;
                break;
            }
        }
    }
    printf("Matrices are %s\n", isEqual ? "equal" : "not equal");
    return 0;
}








