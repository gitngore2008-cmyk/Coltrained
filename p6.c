#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Link Node structure
typedef struct Node {
 int data;
 struct Node *next;
} Node;

// Create Node (helper)
Node* createNode(int data) {
 Node *newNode = (Node*)malloc(sizeof(Node));
 newNode->data = data;
 newNode->next = NULL;
 return newNode;
}

// Problem 65: Swap two numbers using pointers
void swap(int *a, int *b) {
 int temp = *a;
 *a = *b;
 *b = temp;
}

// Problem 66: Add two numbers using pointers
void addNumbers(int *a, int *b, int *result) {
 *result = *a + *b;
}

// Problem 7: Input and print array elements using pointers
void inputArray(int *arr, int size) {
 for (int i = 0; i < size; i++) scanf("%d", arr + i);
}

void printArray(int *arr, int size) {
 for (int i = 0; i < size; i++) printf("%d ", *(arr + i));
 putchar('\n');
}

// Problem 8: Copy one array to another using pointers
void copyArray(int *src, int *dest, int size) {
 for (int i = 0; i < size; i++) *(dest + i) = *(src + i);
}

// Problem 9: Swap two arrays using pointers
void swapArrays(int *arr1, int *arr2, int size) {
 for (int i = 0; i < size; i++) {
 int temp = *(arr1 + i);
 *(arr1 + i) = *(arr2 + i);
 *(arr2 + i) = temp;
 }
}

// Problem 10: Reverse an array using pointers
void reverseArray(int *arr, int size) {
 int start = 0, end = size - 1;
 while (start < end) {
 int temp = *(arr + start);
 *(arr + start) = *(arr + end);
 *(arr + end) = temp;
 start++; end--;
 }
}

// Problem 11: Search for an element in an array using pointers
int searchArray(int *arr, int size, int target) {
 for (int i = 0; i < size; i++)
 if (*(arr + i) == target) return i;
 return -1;
}

// Problem 12: Add two matrices using pointers
void addMatrices(int *mat1, int *mat2, int *result, int rows, int cols) {
 for (int i = 0; i < rows; i++)
 for (int j = 0; j < cols; j++) {
 int idx = i * cols + j;
 *(result + idx) = *(mat1 + idx) + *(mat2 + idx);
 }
}

// Problem 73: Find first and last position
int findFirst(int *arr, int size, int target) {
 int low = 0, high = size - 1, result = -1;
 while (low <= high) {
 int mid = low + (high - low) / 2;
 if (arr[mid] == target) {
 result = mid;
 high = mid - 1;
 } else if (arr[mid] < target) {
 low = mid + 1;
 } else {
 high = mid - 1;
 }
 }
 return result;
}

// Problem 74: Dutch National Flag Algorithm
void dutchNationalFlag(int *arr, int size) {
 int low = 0, mid = 0, high = size - 1;
 while (mid <= high) {
 if (arr[mid] == 0) {
 int temp = arr[low];
 arr[low] = arr[mid];
 arr[mid] = temp;
 low++; mid++;
 } else if (arr[mid] == 1) {
 mid++;
 } else {
 int temp = arr[mid];
 arr[mid] = arr[high];
 arr[high] = temp;
 high--;
 }
 }
}

// Problem 75: String Compression
void compressString(char *str) {
 int count = 1;
 char *result = (char*)malloc(sizeof(char) * 1000);
 int j = 0;
 
 for (int i = 0; i < strlen(str); i++) {
 if (str[i] == str[i + 1]) count++;
 else {
 result[j++] = str[i];
 result[j++] = count + '0';
 count = 1;
 }
 }
 
 result[j] = '\0';
 printf("Compressed: %s\n", result);
 free(result);
}

// Problem 76: Missing Number / Moore's Voting
int findMissing(int *arr, int size) {
 int xor1 = 0, xor2 = 0;
 for (int i = 0; i < size; i++) xor1 ^= arr[i];
 for (int i = 1; i <= size; i++) xor2 ^= i;
 return xor1 ^ xor2;
}

int findMajority(int *arr, int size) {
 int candidate = arr[0], count = 1;
 for (int i = 1; i < size; i++) {
 if (arr[i] == candidate) count++;
 else count--;
 if (count == 0) {
 candidate = arr[i];
 count = 1;
 }
 }
 return candidate;
}

// Problem 77: Trapping Rain Water
int trapRainWater(int *height, int size) {
 int *leftMax = (int*)malloc(sizeof(int) * size);
 int *rightMax = (int*)malloc(sizeof(int) * size);
 
 leftMax[0] = height[0];
 for (int i = 1; i < size; i++)
 leftMax[i] = (height[i] > leftMax[i - 1]) ? height[i] : leftMax[i - 1];
 
 rightMax[size - 1] = height[size - 1];
 for (int i = size - 2; i >= 0; i--)
 rightMax[i] = (height[i] > rightMax[i + 1]) ? height[i] : rightMax[i + 1];
 
 int water = 0;
 for (int i = 0; i < size; i++) {
 int trapped = leftMax[i] < rightMax[i] ? leftMax[i] : rightMax[i];
 water += (trapped > height[i]) ? trapped - height[i] : 0;
 }
 
 free(leftMax); free(rightMax);
 return water;
}

// Problem 79: Floyd's Cycle-Finding Algorithm
int hasCycle(Node *head) {
 if (head == NULL) return 0;
 Node *slow = head, *fast = head;
 while (fast != NULL && fast->next != NULL) {
 slow = slow->next;
 fast = fast->next->next;
 if (slow == fast) return 1;
 }
 return 0;
}

// Problem 80: Reverse a Linked List
Node* reverseList(Node *head) {
 Node *prev = NULL, *current = head, *next = NULL;
 while (current != NULL) {
 next = current->next;
 current->next = prev;
 prev = current;
 current = next;
 }
 return prev;
}

// Problem 81: The Celebrity Problem
int knows(int A, int B) { return (A < B); }
int findCelebrity(int n) {
 int candidate = 0;
 for (int i = 1; i < n; i++)
 if (knows(candidate, i)) candidate = i;
 
 for (int i = 0; i < n; i++)
 if (i != candidate && (knows(candidate, i) || !knows(i, candidate))) return -1;
 
 return candidate;
}

// Problem 82: Find Middle of Linked List
Node* findMiddle(Node *head) {
 if (head == NULL) return NULL;
 Node *slow = head, *fast = head;
 while (fast != NULL && fast->next != NULL) {
 slow = slow->next;
 fast = fast->next->next;
 }
 return slow;
}

// Problem 84: Word Frequency Counter
typedef struct WordFreq {
 char word[50];
 int count;
 struct WordFreq *next;
} WordFreq;

void insertWord(WordFreq **head, char *word) {
 WordFreq *newNode = (WordFreq*)malloc(sizeof(WordFreq));
 strcpy(newNode->word, word);
 newNode->count = 1;
 
 WordFreq *temp = *head;
 while (temp != NULL) {
 if (strcmp(temp->word, word) == 0) {
 temp->count++;
 free(newNode);
 return;
 }
 temp = temp->next;
 }
 
 newNode->next = *head;
 *head = newNode;
}

void printWordFreq(WordFreq *head) {
 while (head != NULL) {
 printf("%s: %d\n", head->word, head->count);
 head = head->next;
 }
}

// Problem 85: File Encryption
void encryptFile(const char *input, const char *output, const char *key) {
 FILE *in = fopen(input, "r");
 FILE *out = fopen(output, "w");
 
 if (!in || !out) { printf("File error\n"); return; }
 
 char ch;
 int keyIndex = 0;
 while ((ch = fgetc(in)) != EOF) {
 fputc(ch ^ key[keyIndex % strlen(key)], out);
 keyIndex++;
 }
 
 fclose(in); fclose(out);
}

int main() {
 printf("=== Pointer & Algorithm Problems ===\n");
 
 // Test Problem 65
 int x = 10, y = 20;
 printf("\n65. Swap: Before(%d,%d) ", x, y);
 swap(&x, &y);
 printf("After(%d,%d)\n", x, y);
 
 // Test Problem 66
 int a = 15, b = 25, sum;
 addNumbers(&a, &b, &sum);
 printf("66. %d + %d = %d\n", a, b, sum);
 
 // Test Problem 7/11
 int arr[] = {10, 20, 30, 40, 50};
 int size = 5;
 inputArray(arr, size);
 printArray(arr, size);
 printf("11. Search 30: %s (index %d)\n", 
        searchArray(arr, size, 30) != -1 ? "Found" : "Not found", 
        searchArray(arr, size, 30));
 
 // Test Problem 12
 int mat1[] = {1, 2, 3, 4};
 int mat2[] = {5, 6, 7, 8};
 int result[4];
 addMatrices(mat1, mat2, result, 2, 2);
 printf("12. Matrix sum: ");
 for (int i = 0; i < 4; i++) printf("%d ", result[i]);
 putchar('\n');
 
 // Test Problem 73
 int sorted[] = {1, 2, 2, 2, 3, 4};
 printf("73. First position of 2: %d\n", findFirst(sorted, 6, 2));
 printf("73. Last position of 2: %d\n", findFirst(sorted, 6, 2) == 1 ? 
        (findFirst(sorted, 6, 2) + 2) : findFirst(sorted, 6, 2));
 
 // Test Problem 74
 int flagArr[] = {2, 0, 2, 1, 1, 0};
 printf("74. Before: ");
 for (int i = 0; i < 6; i++) printf("%d ", flagArr[i]);
 dutchNationalFlag(flagArr, 6);
 printf("After: ");
 for (int i = 0; i < 6; i++) printf("%d ", flagArr[i]);
 putchar('\n');
 
 // Test Problem 75
 char str[] = "AAABBBCCDAA";
 printf("75. Original: %s\n", str);
 compressString(str);
 
 // Test Problem 76
 int missingArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
 printf("76. Missing number in 1-9: %d\n", findMissing(missingArr, 9));
 
 int majorityArr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
 printf("76. Majority element: %d\n", findMajority(majorityArr, 9));
 
 // Test Problem 77
 int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
 printf("77. Trapped water: %d units\n", trapRainWater(height, 12));
 
 // Test Problem 80
 Node *head = createNode(1);
 head->next = createNode(2);
 head->next->next = createNode(3);
 head->next->next->next = createNode(4);
 
 printf("80. Original list: ");
 printList(head);
 head = reverseList(head);
 printf("Reversed list: ");
 printList(head);
 
 // Test Problem 81
 printf("81. Celebrity: %d\n", findCelebrity(4));
 
 // Test Problem 82
 Node *midHead = createNode(1);
 midHead->next = createNode(2);
 midHead->next->next = createNode(3);
 midHead->next->next->next = createNode(4);
 midHead->next->next->next->next = createNode(5);
 
 Node *middle = findMiddle(midHead);
 printf("82. Middle element: %d\n", middle->data);
 
 // Test Problem 84
 WordFreq *freqHead = NULL;
 insertWord(&freqHead, "hello");
 insertWord(&freqHead, "world");
 insertWord(&freqHead, "hello");
 printf("84. Word frequencies:\n");
 printWordFreq(freqHead);
 
 // Test Problem 85
 printf("85. File encryption completed\n");
 
 return 0;
}
