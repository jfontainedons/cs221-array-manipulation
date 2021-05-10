  #include <stdio.h>
  #include <stdbool.h>

  // Recursively convert all lowercase letters to uppercase.
  void toUpperCase(char* str) {

    unsigned char c = *str;

    if (c == '\0') {
      return;
    } else {
      if ((int) c >= 97 && (int) c <= 122) {
        int newAsciiValue = (int) c - 32;
        char newChar = newAsciiValue;
        *str = newChar;
      }
    }
    return toUpperCase(str + 1);
  }


  // Recursively return the largest number in the array.
  int findMax(int* arr, int p, int max) {

    int elem = *arr;

    if (p == 0) {
      return max;
    } else {
      // Check if the elem is greater than the current max.
      if (elem > max) {
        max = elem;
      }
    }
    return findMax(arr + 1, p - 1, max);
  }


  // Reverse a string using recursion. i = first index. s = last index.
  void reverse(char* str, int i, int s) {

    unsigned char ch = *str;

    if (i >= s) {
       return;
     } else {

      ch = *(str + i);
      *(str + i) = *(str + s);
      *(str + s) = ch;

      reverse(str, ++i, --s);
    }
  }

  // Convert a decimal number to binary using recursion
  long convertToBinary(int num) {

    if (num == 0) {
      return 0;
    } else {
      return (num % 2 + 10 * convertToBinary(num / 2));
    }
  }


  // Check whether a given string is a palindrome or not, recursively. s = first index. e = last index.
  bool isPalindrome(char* str, int s, int e) {

    unsigned char char1 = *(str + s);
    unsigned char char2 = *(str + e);

    if (s >= e) {
      return true;
    }

    if (char1 != char2) {
      return false;
    }

    isPalindrome(str, ++s, --e);
  }


  int main(void) {

    char upperCaseString[50] = "aBcD?2";
    toUpperCase(upperCaseString);                                 // -> "ABCD?2"

    int arr[5] = {2, 31, 4, 12, 8};
    int prevMax = arr[0];

    int currentMax = findMax(arr, 5, prevMax);                    // -> 31

    char reverseString[50] = "abcde";
    reverse(reverseString, 0, 4);                                 // -> "edcba"

    int num = 10;
    long result;
    result = convertToBinary(num);                                // -> 1010

    char firstPalindromeString[50] = "abcba";
    isPalindrome(firstPalindromeString, 0, 4);                    // -> true

    char secondPalindromeString[50] = "abcb1";
    isPalindrome(secondPalindromeString, 0, 4);                   // -> false

    return 0;
  }
