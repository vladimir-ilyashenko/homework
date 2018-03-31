//#include "stdafx.h"
#include <iostream>
#include <time.h>


using namespace std;
void calculate_array_size(int *array, int array_size, int *summ, int *multiplication) {
for (int i=0; i<array_size;i++) {
  *multiplication *= array[i];
  *summ += array[i];
}
}

int main() {
srand((int)time(0));
const int array_size=5;
int array[array_size];
int * array_pointer = array; 
int summ = 0;
int multiplication = 1;
for (int i=0; i<array_size;i++) {
  array[i] = rand() % 101;
  cout << array[i] << " ";
}
cout << endl;

calculate_array_size( array, array_size, &summ, &multiplication );
cout << "summ = " << summ << endl << "multiplication = " << multiplication << endl;
}

