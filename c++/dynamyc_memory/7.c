//#include "stdafx.h"
#include <iostream>
#include <time.h>
#include "array_funcrions.cpp"

using namespace std;

void populate(int *array, int array_size) {
  for (int i=0; i < array_size; i++) {
    array[i]=rand() % 21;
  }
}

int* Merge_Arrays(int *array1, int *array1_size, int *array2, int *array2_size) {
  for (int i = 0;i < *array1_size; i++ ) {
    for (int j = 0;j<*array1_size; j++ ) {
      if (i==j) {
        continue;
      }
      if (array1[i] == array1[j]) {
        array1 = Delete_Element_At_Position(array1, array1_size, j+1);
      }
    }
  }
  for (int i=0; i<*array2_size;i++) {
    bool match = false;
    for (int j=0; j<*array1_size;j++) {
      if (array2[i]==array1[j]) {
        match = true;
        break;
      }
    }
    if (!match) {
      array1 = Add_New_Element(array1,array1_size,array2[i]);
    }
  }
  return array1;
}

int main() {
  int array1_size;
  int *array1 = nullptr;
  int array2_size;
  int *array2 = nullptr;
  srand((int)time(0));

  cout << "Enter size to allocate for first array: ";
  cin >> array1_size;
  array1 = new int[array1_size];
  populate(array1, array1_size);
  Print(array1, array1_size);

  cout << "Enter size to allocate for second array: ";
  cin >> array2_size;
  array2 = new int[array2_size];
  populate(array2, array2_size);
  Print(array2, array2_size);

  array1 = Merge_Arrays(array1,&array1_size, array2, &array2_size);
  Print(array1, array1_size);
}
