#include <iostream>

using namespace std;

int main() {
  int number, number_temp;

  cout << "Input number" << endl;
  cin >> number;
  number_temp=number;
  
  // Get number length
  int number_length=0;
  while (number_temp) {
    number_temp = number_temp/10;
    number_length++;
  }
  
  // Create char array
  char * char_array = new char[number_length];
  
  // Populate char array
  while (number_length) {
    char_array[number_length-1] = (number % 10) + '0';
    number= number/10;

    number_length--;
  }
  
  cout << char_array << endl;
}
