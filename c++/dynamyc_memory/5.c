//#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

int* allocate(int array_size) {
  return new int[array_size];
}

void populate(int *array, int array_size) {
  for (int i=0; i < array_size; i++) {
    array[i]=rand() % 101;
  }
}

void Print(int *array, int array_size) {
  for (int i=0;i<array_size;i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void Delete(int *array) {
  delete[] array;
}

int* Add_New_Element(int *array,int *array_size,int  element){
  int *p = new int [++*array_size];
  for (int  i =0;i<*array_size-1; i++){
     p[i] = array [i];
  }
  p [*array_size - 1 ] = element;
  delete [] array;
  return p;
}

int* Add_New_Element_At_Position(int *array,int *array_size,int  element, int position) {
  int *p = new int [++*array_size];
  int k=0;
  for (int  i =0;i<*array_size; i++){
    if (i+1 == position) {
      p[i] = element;
      i++;
      k=1;
    }
    p[i] = array [i-k];
  }
  delete [] array;
  return p;
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

int main() {
  int array_size;
  int *array = nullptr;
  srand((int)time(0));
  cout << "Enter size to allocate: ";
  cin >> array_size;
  cout << endl;

  array = allocate(array_size);

  populate(array, array_size);

  Print(array, array_size);
  int element; 
  cout << "enter new element "<< endl;
  cin>> element;

  array = Add_New_Element(array, &array_size,element);
  Print(array, array_size);

  int position = 0;
  cout << "Enter new element: ";
  cin >> element;
  while ((bool)position == false) {
    cout <<  "Enter position for element: ";
    cin >> position;
    if (position > array_size+1 || position < 1) {
      cout << "Please enter valid position between 1 and " << array_size+1 <<endl;
      position = 0;
    }
  }
  array = Add_New_Element_At_Position(array, &array_size, element, position);
  Print(array, array_size);

  position = 0;
  while ((bool)position == false) {
    cout <<  "Enter position of element to delete: ";
    cin >> position;
    if (position > array_size+1 || position < 1) {
      cout << "Please enter valid position between 1 and " << array_size <<endl;
      position = 0;
    }
  }
  array = Delete_Element_At_Position(array, &array_size, position);
  Print(array, array_size);

  Delete(array);
}
