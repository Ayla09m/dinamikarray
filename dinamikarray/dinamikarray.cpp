#include <iostream>

using namespace std;

void addElementToEnd(int*& arr, int& size, int element) {
    int* newArr = new int[size + 1];  
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];  
    }
    newArr[size] = element;  
    delete[] arr;  
    arr = newArr;  
    size++;  
}
int* fillarr(int arrsize) {
    int* arr = new int[arrsize];
    srand(time(0));
    for (size_t i = 0; i < arrsize; i++)
    {
        arr[i] = rand() % 20;
    }
    return arr;
}

void showarr(int* arr, int arrsize) {
    for (size_t i = 0; i < arrsize; i++)
    {
        cout << arr[i] << ' ';
    }
}

int* append(int* oldarr, int* sizeaddr, int element) {
    int* newarr = new int[*sizeaddr + 1];

    for (size_t i = 0; i < *sizeaddr; i++)
    {
        newarr[i] = oldarr[i];
    }
    newarr[*sizeaddr] = element;
    (*sizeaddr)++;
    delete[] oldarr;
    oldarr = nullptr;

    return newarr;
}
int* yaddasayirma(int size) {
    return new int[size];
}
void delarr(int* arr) {
    delete[] arr;
}
void addelementindex(int*& arr, int& size, int element, int index) {
    if (index < 0 || index > size) {
        return;
    }
    int* newArr = new int[size + 1];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    newArr[index] = element;  
    for (int i = index; i < size; i++) {
        newArr[i + 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size++;
}
void removeelementindex(int*& arr, int& size, int index) {
    if (index < 0 || index >= size) {
        return;
    }
    int* newArr = new int[size - 1];
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    for (int i = index + 1; i < size; i++) {
        newArr[i - 1] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size--;
}
void addblockindex(int*& arr, int& size, int* block, int blockSize) {
    int* newArr = new int[size + blockSize];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    for (int i = 0; i < blockSize; i++) {
        newArr[size + i] = block[i];  
    }
    delete[] arr;
    arr = newArr;
    size += blockSize;
}
void addblockindex(int*& arr, int& size, int* block, int blockSize, int index) {
    if (index < 0 || index >= size) {
        std::cout << "Yanlış indeks!\n";
        return;
    }
    int* newArr = new int[size + blockSize];
    for (int i = 0; i < index + 1; i++) {
        newArr[i] = arr[i];
    }
    for (int i = 0; i < blockSize; i++) {
        newArr[index + 1 + i] = block[i];
    }
    for (int i = index + 1; i < size; i++) {
        newArr[i + blockSize] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    size += blockSize;
}

int main() {
    cout << "\ntask2,3,4" << endl;

    int size;
    cin >> size;

    int* arr = fillarr(size);
    showarr(arr, size);
    cout << endl;

    cout << "\ntask1" << endl;
    int* tempArr = yaddasayirma(size);
    delarr(tempArr);
    cout << endl;

    cout << "\ntask5" << endl;
    addElementToEnd(arr, size, 6);
    showarr(arr, size);
    cout << endl;

    cout << "\ntask6" << endl;
    addelementindex(arr, size, 99, 2); 
    showarr(arr, size);
    cout << endl;

    cout << "\ntask7" << endl;
    removeelementindex(arr, size, 3); 
    showarr(arr, size);
    cout << endl;

    cout << "\ntask8" << endl;
    int block1[] = { 7, 8, 9 };
    addblockindex(arr, size, block1, 3);
    showarr(arr, size);
    cout << endl;

    cout << "\ntask9" << endl;
    int block2[] = { 10, 11 };
    addblockindex(arr, size, block2, 2, 1);
    showarr(arr, size);
    cout << endl;
    delarr(arr);
}