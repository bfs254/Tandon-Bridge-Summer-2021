//Author: Briana Singleton
//NYU ID: bfs254
//WK 9 Q3
//takes an array of integers and its logical size and creates a new array with only the positive numbers from the original array
//Last modified: 13 September 2021

#include <iostream>
using namespace std;

int* getPosNums1 (int* arr, int arrSize, int& outPosArrSize);
//returns positive # array's base address
//updates outPosArrSize w/ array's logical size

int* getPosNums2 (int* arr, int arrSize, int* outPosArrSizePtr);
//returns positive # array's base address
//uses pointer outPosArrSizePtr to update array's logical size

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
//updates outPosArr w/ positive # array's address
//updates outPosArrSize w/ logical size

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
//uses outPosArrPtr to update positive # array's address
//uses outPosArrSizePtr to update array's logical size

int main(){
    int* arr1Ptr = NULL;
    int arr1[6] = {3, -1, -3, 0, 6, 4};
    arr1Ptr = arr1;
    int arr1Size = 6;
    int posArr1Size = 0;
    arr1Ptr = getPosNums1(arr1Ptr, arr1Size, posArr1Size);
    cout<< "posArr1Size: " << posArr1Size << "\n";
    for (int i = 0; i < posArr1Size; i++) {
        cout<< arr1Ptr[i] << " ";
    }
    cout<< "\n";
    
    int* arr2Ptr = NULL;
    int* posArr2SizePtr = NULL;
    int arr2[6] = {3, -1, -3, 0, 6, 4};
    arr2Ptr = arr2;
    int arr2Size = 6;
    int posArr2Size = 0;
    posArr2SizePtr = &posArr2Size;
    arr2Ptr = getPosNums2 (arr2Ptr, arr2Size, posArr2SizePtr);
    cout<< "posArr2SizePtr: " << *posArr2SizePtr << "\n";
    for (int i = 0; i < *posArr2SizePtr; i++) {
        cout << *(arr2Ptr + i) << " ";
    }
    cout<< "\n";

    int* arr3Ptr = NULL;
    int* posArr3Ptr = NULL;
    int arr3[6] = {3, -1, -3, 0, 6, 4};
    arr3Ptr = arr3;
    int arr3Size = 6;
    int posArr3Size = 0;
    getPosNums3(arr3Ptr, arr3Size, posArr3Ptr, posArr3Size);
    cout<< "posArr3Size: " << posArr3Size << "\n";
    for (int i = 0; i < posArr3Size; i++) {
        cout<< posArr3Ptr[i] << " ";
    }
    cout<< "\n";

    int* arr4Ptr = NULL;
    int* posArr4Ptr = NULL;
    int** posArr4PPtr = NULL;
    int* posArr4SizePtr = NULL;
    int arr4[6] = {3, -1, -3, 0, 6, 4};
    int arr4Size = 6;
    int posArr4Size = 0;
    arr4Ptr = arr4;
    posArr4Ptr = new int [1];
    posArr4PPtr = &posArr4Ptr;
    posArr4SizePtr = &posArr4Size;
    getPosNums4(arr4Ptr, arr4Size, posArr4PPtr, posArr4SizePtr);
    cout << "posArr4SizePtr: " << *posArr4SizePtr << "\n";
    for (int i = 0; i < *posArr4SizePtr; i++) {
        cout << *(*posArr4PPtr + i) << " ";
    }
    cout<< "\n";

    return 0;
}

int* getPosNums1 (int* arr, int arrSize, int& outPosArrSize) {
    int j = 0;
    int* posArr = NULL;
    posArr = new int [1];
    int posArrSize = 0;
    int posArrPhysSize = 1;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            if (posArrSize == posArrPhysSize) {
                int* tempArr = new int [posArrPhysSize * 2];
                for (int k = 0; k < posArrSize; k++) {
                    tempArr[k] = posArr[k];
                }
                delete [] posArr;
                posArr = tempArr;
                posArrPhysSize *= 2;
            }
            posArr[j] = arr[i];
            posArrSize++;
            j++;
        }
    }
    outPosArrSize = posArrSize;
    arr = posArr;
    return arr;
}

int* getPosNums2 (int* arr, int arrSize, int* outPosArrSizePtr) {
    int j = 0;
    int* posArr = NULL;
    posArr = new int [1];
    int posArrPhysSize = 1;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            if (*outPosArrSizePtr == posArrPhysSize) {
                int* tempArr = new int [posArrPhysSize * 2];
                for (int k = 0; k < *outPosArrSizePtr; k++) {
                    tempArr[k] = posArr[k];
                }
                delete [] posArr;
                posArr = tempArr;
                posArrPhysSize *= 2;
            }
            posArr[j] = arr[i];
            *(outPosArrSizePtr) += 1;
            j++;
        }
    }
    arr = posArr;
    return arr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    int j = 0;
    outPosArr = new int [1];
    int posArrPhysSize = 1;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            if (outPosArrSize == posArrPhysSize) {
                int* tempArr = new int [posArrPhysSize * 2];
                for (int k = 0; k < outPosArrSize; k++){
                    tempArr[k] = outPosArr[k];
                }
                delete [] outPosArr;
                outPosArr = tempArr;
                posArrPhysSize *= 2;
            }
            outPosArr[j] = arr[i];
            outPosArrSize++;
            j++;
        }
    }
    return;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    int j = 0;
    int posArrPhysSize = 1;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            if (*outPosArrSizePtr == posArrPhysSize) {
                int* tempArr = new int [posArrPhysSize * 2];
                for (int k = 0; k < *outPosArrSizePtr; k++) {
                    tempArr[k] = (*(*outPosArrPtr + k));
                }
                delete [] *outPosArrPtr;
                *outPosArrPtr = tempArr;
                posArrPhysSize *= 2;
            }
            (*(*outPosArrPtr + j)) = arr[i];
            *(outPosArrSizePtr) += 1;
            j++;
        }
    }
    return;
}