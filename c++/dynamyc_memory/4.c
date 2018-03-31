//#include "stdafx.h"
#include <iostream>
#include <time.h>


using namespace std;
bool calculate_array(int array1[], int array1_size, int array2[], int array2_size, int *beggin_of_subset) {
for (int i=0; i<array1_size;i++) {
  for (int j=0; j<array2_size; j++) {
    if (array1[i+j] != array2[j]) {
      break;
    }
    if (j == 2) {
      *beggin_of_subset = i;
      return true;
    }
  }
}
return false;
}

int main() {
srand((int)time(0));
const int array1_size=100;
const int array2_size=3;
int array1[array1_size];
int array2[array2_size];
int beggin_of_subset = -1;
for (int i=0; i<array1_size;i++) {
    array1[i] = rand() % 11;
    cout << array1[i] << " ";
}
cout << endl;
for (int i=0; i<array2_size;i++) {
    array2[i] = rand() % 11;
    cout << array2[i] << " ";
}
cout << endl;

bool is_subset = calculate_array( array1, array1_size, array2, array2_size, &beggin_of_subset);
if (is_subset) {
  cout << "Second array is a subset of first one" << endl;
  cout << "Subset starts at element " << beggin_of_subset +1 << endl;
} else {
  cout << "Second array is not a subset of first one" << endl;
}
}

