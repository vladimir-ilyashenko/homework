//#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

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
  for (int  i=0;i<*array_size; i++){
    if (i+1 == position) {
      k=1;
    }
    p[i] = array [i+k];
  }
  delete [] array;
  return p;
}
