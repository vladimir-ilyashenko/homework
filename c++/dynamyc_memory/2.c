//#include "stdafx.h"
#include <iostream>
#include <time.h>


using namespace std;
void calculate_array_size(int *array, int array_size, int *positive, int * negative,int *zero) {
for (int i=0; i<array_size;i++) {
  if( array[i] >0){
	(*positive)++;
	}else if ( array [i]<0) {
		++(*negative);
		}else {
	(*zero)++;
}


}
}

int main() {
srand((int)time(0));
const int array_size=10;
int array[array_size];
int positive = 0;
int negative  = 0;
int zero = 0;
for (int i=0; i<array_size;i++) {
  array[i] = rand() % 102 - 51;
  cout << array[i] << " ";
}
cout << endl;

calculate_array_size( array, array_size, &positive, &negative , &zero);
cout << "positive elements = " << positive  << endl << "negative elements  = " << negative << endl<<"zero ="<< zero<< endl;
}

