#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>

using namespace std;

void mergeArrays(const int arr1[], int size1, const int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;


    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        }
        else {
            result[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        result[k++] = arr1[i++];
    }
    while (j < size2) {
        result[k++] = arr2[j++];
    }
    for (int m = 0; m < size1 + size2 - 1; ++m) {
        for (int n = 0; n < size1 + size2 - m - 1; ++n) {
            if (result[n] > result[n + 1]) {
                int temp = result[n];
                result[n] = result[n + 1];
                result[n + 1] = temp;
            }
        }
    }
}
void findCommonElements(const int arr1[], int size1, const int arr2[], int size2) {
    int i = 0, j = 0;

    cout << "Common Elements: ";

    while (i < size1 && j < size2) {
        if (arr1[i] == arr2[j]) {
            cout << arr1[i] << " ";
            ++i;
            ++j;
        }
        else if (arr1[i] < arr2[j]) {
            ++i;
        }
        else {
            ++j;
        }
    }

    cout << "\n";
}



bool isPalindrome(const string& str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        ++start;
        --end;
    }

    return true;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int array1[5];
    int array2[7];


    cout << "Enter 5 integers for array1: " << endl;
    for (int i = 0; i < 5; ++i) {
        cin >> array1[i];
    }


    cout << "Array2 with random values: " << endl;
    for (int i = 0; i < 7; ++i) {
        array2[i] = rand() % 100;
        cout << array2[i] << " ";
    }
    cout << "\n";

    const int size1 = 5;
    const int size2 = 7;
    int mergedArray[size1 + size2];


    mergeArrays(array1, size1, array2, size2, mergedArray);


    cout << "Merged Array in ascending order: ";
    for (int i = 0; i < size1 + size2; ++i) {
        cout << mergedArray[i] << " ";
    }
    cout << "\n";


    findCommonElements(array1, size1, array2, size2);


    cout << "-----------------------------------------------/Palindrome checker /-------------------------------------------------------" << endl;
    string userSentence;
    cout << "Enter a sentence: ";
    cin.ignore();
    getline(cin, userSentence);

    if (isPalindrome(userSentence)) {
        cout << "The sentence is a palindrome.\n";
    }
    else {
        cout << "The sentence is not a palindrome.\n";
    }

    return 0;
}