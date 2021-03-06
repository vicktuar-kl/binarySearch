// binarySearch.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int binarySearchInSortedArray(int* a, int size, int key);
int binarySearchInCyclicallyShiftedSortedArray(int* a, int size, int key);

int main() {
    setlocale(LC_ALL, "RU");
    const int arraySize = 11;
    int sortedArray[arraySize] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    int cyclicallyShiftedSortedArray[arraySize] = { 9, 10, 11, 1, 2, 3, 4, 5, 6, 7, 8 };

    std::cout << "Введите искомый элемент: ";
    int searchValue;
    std::cin >> searchValue;
    std::cout << "***** Бинарный поиск в отсортированном массиве *****\n";
    std::cout << "Массив: ";
    for (int i = 0; i < arraySize - 1; ++i) {
        std::cout << sortedArray[i] << " | ";
    }
    std::cout << sortedArray[arraySize - 1] << std::endl;
    std::cout << "Искомый элемент: " << searchValue << std::endl;
    std::cout << "Индекс искомого элемента: " <<
        binarySearchInSortedArray(sortedArray, arraySize, searchValue) << std::endl;

    std::cout << std::endl << std::endl;

    std::cout << "***** Бинарный поиск в отсортированном циклически сдвинутом массиве *****\n";
    std::cout << "Массив: ";
    for (int i = 0; i < arraySize - 1; ++i) {
        std::cout << cyclicallyShiftedSortedArray[i] << " | ";
    }
    std::cout << cyclicallyShiftedSortedArray[arraySize - 1] << std::endl;
    std::cout << "Искомый элемент: " << searchValue << std::endl;
    std::cout << "Индекс искомого элемента: " <<
        binarySearchInCyclicallyShiftedSortedArray(cyclicallyShiftedSortedArray,
                                                   arraySize, searchValue)
        << std::endl;
    system("pause");
    return 0;
}

int binarySearchInSortedArray(int* a, int size, int key) {
    if (a == nullptr || size == 0 || key < a[0] || key > a[size - 1])
        return -1;
    int l = 0;
    int r = size;
    while (l < r - 1) {
        int m = (l + r) / 2;

        if (key < a[m])
            r = m;
        else if (key > a[m])
            l = m;
        else
            return m;

        if (l > r)
            return -1;
    }
}

int binarySearchInCyclicallyShiftedSortedArray(int* a, int size, int key) {
    int l = 0;
    int r = size;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (a[m] == key)
            return m;

        if (a[m] < a[size - 1])
            r = m;
        else if (a[m] >= a[size - 1])
            l = m;
    }
    int x = l;

    if (key > a[0]) {
        l = 0;
        r = x + 1;
    } else {
        l = x + 1;
        r = size;
    }

    return binarySearchInSortedArray(&a[l], r - l, key);
}

