//#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

int* allocate(int array_size) {
  return new int[array_size];
}

void populate(int *array, int array_size) {
  for (int i=0; i < array_size; i++) {
    array[i]=rand() % 102 - 51;
  }
}

void Print(int *array, int array_size) {
  for (int i=0;i<array_size;i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int* Delete_Element_At_Position(int *array,int *array_size, int position) {
  int *p = new int [--*array_size];
  int k=0;
  for (int  i =0;i<*array_size; i++){
    if (i+1 == position) {
      k=1;
    }
    p[i] = array [i+k];
  }
  delete [] array;
  return p;
}

// Optimist's function
int* Remove_Negatives(int *array, int *array_size) {
  for (int i=0;i<*array_size; i++) {
    if (array[i]<0) {
      array = Delete_Element_At_Position(array, array_size, i+1);
      i--;
    }
  }
  return array;
}

int main() {
  int array_size;
  int *array = nullptr;
  srand((int)time(0));
  cout << "Enter size to allocate: ";
  cin >> array_size;

  //array = allocate(array_size);
  array = new int[array_size];

  populate(array, array_size);

  Print(array, array_size);

  array = Remove_Negatives(array,&array_size);
  Print(array, array_size);
}
