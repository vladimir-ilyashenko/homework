#include <iostream>
#include <time.h>
#include "array_funcrions.cpp"
//???????????????????????????????????????????????????????????????????????????????
using namespace std;



void Function15(int *array17,int array17_size, int *array20, int *array20_size, 
int *array21, int *array21_size, int *array22, int *array22_size ) {

int *positive = new int[*array20_size];
int *negative = new int[*array21_size];
int *zero = new int[*array22_size];

//Print(array17,array17_size);
for (int i = 0; i < array17_size; i++) {
if (array17[i] > 0) {
positive = Add_New_Element(positive, array20_size, array17[i]);
//array20++;
//	cout << array20[i];
}
else if (array17[i] < 0) {
negative = Add_New_Element(negative, array21_size, array17[i]);
}
if (array17[i] == 0) {
zero = Add_New_Element(zero, array22_size, array17[i]);
}
}

for (int i = 0;i < * array20_size;i++) {
array20[i] = positive[i];
}
for (int i = 0;i < *array21_size;i++) {
array21[i] = negative[i];
}
for (int i = 0;i < *array22_size;i++) {
array22[i] = zero[i];
}
delete[]positive;
delete[] negative;
delete[] zero;

/*Print(array20, *array20_size);
Print(array21, *array21_size);
Print(array22, *array22_size);*/
}

int main() {

int array20_size = 0;
//int *p_array20_size = &array20_size;
//int *array20 = nullptr;
int *array20 = new int [array20_size];
//int *array20 = nullptr;

int array21_size = 0;
//int *p_array21_size = &array21_size;
int *array21 = new int[array21_size];
//int *array21 = nullptr;

int array22_size = 0;
//int *p_array22_size = &array22_size;
int *array22 = new int[array22_size];
//int *array22 = nullptr;

const int array17_size = 20;
int array17[array17_size];

//populate(array17, 20);
for (int i = 0; i < array17_size; i++) {
array17[i] = rand() % 51 - 25;
}
Print(array17, 20);

Function15(array17,  array17_size, array20, &array20_size,
array21, &array21_size, array22,  &array22_size);

/*
cout << endl;
for (int i = 0;i<array20_size;i++) {
cout << array20[i] << " ";
}
cout << endl;

for (int i = 0;i<array21_size;i++) {
cout << array21[i] << " ";
}
cout << endl;

for (int i = 0;i<array22_size;i++) {
cout << array22[i] << " ";
}
cout << endl;
*/
cout << "Positive elements: " << endl;
Print(array20, array20_size);
cout << "Zero elements: " << endl;
Print(array22, array22_size);
cout << "Negative  elements: " << endl;
Print(array21, array21_size);


//Print(array20, array20_size);
//Print(array21, array21_size);
//Print(array22, array22_size);
//delete[]array20;
//delete[] array21;
//delete[] array22;
//system("pause");
   return 0;
}

