//#include "stdafx.h"
#include <iostream>
#include <time.h>


using namespace std;
void calculate_array(int array[][10], int array_size, int *even, int * odd,int *mean) {
for (int i=0; i<array_size;i++) {
  for (int j=0; j<array_size;j++) {
    *mean += array[i][j];
    if( array[i][j] % 2 == 0){
      (*even)++;
    }else {
      ++(*odd);
    }
  }
}
*mean = *mean / (array_size*array_size);
}

int main() {
srand((int)time(0));
const int array_size=10;
int array[array_size][array_size];
int even = 0;
int odd  = 0;
int mean = 0;
for (int i=0; i<array_size;i++) {
  for (int j=0; j<array_size;j++) {
    array[i][j] = rand() % 101;
    cout << array[i][j] << " ";
  }
  cout << endl;
}
cout << endl;

calculate_array( array, array_size, &even, &odd , &mean);
cout << "even elements = " << even  << endl << "odd elements  = " << odd << endl<<"mean ="<< mean<< endl;
}

