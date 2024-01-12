#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  // Open an output filestream binary mode
  ofstream file("info.dat", ios::binary);

  ////Write out cstring to binary file
  char words[] = "Hello world";

  // Write out cstring + terminating null
  file.write(words, strlen(words) + 1);

  ////Write out two ints to a binary file
  int x = 15;
  // Get address of int
  int* xPointer = &x;
  // Pretend it is a pointer to a char
  char* dataPointer = reinterpret_cast<char*>(xPointer);
  // Write out starting from that address, number of bytes x requires
  file.write(dataPointer, sizeof(x));

  // One line version
  int y = 258;
  file.write(reinterpret_cast<char*>(&y), sizeof(y));

  file.close(); // make sure it is closed and written before we read it

  ////----------------------------------------------------------
  ////Read back in
  ////We know there is a string and two ints

  // Open filestream setting binary mode and limiting to input
  fstream inFile("info.dat", ios::binary | ios::in);

  // Read characters one by one into a string
  string input;
  char c;
  // Get first char
  inFile.read(&c, 1);
  // Continue until we see null char
  while (c != '\0') {
    // add to string, get next char
    input += c;
    inFile.read(&c, 1);
  }
  // See what we got
  cout << input << endl;

  //    //--------------------------------------------
  //    //Read into c-string instead of a string

  //    //Read characters for string into a cstring
  //    char buffer[100];
  //    int i = 0;
  //    char c;
  //    do {
  //        //read one char
  //        inFile.read(&c, 1);
  //        //put in array and increment counter
  //        buffer[i] = c;
  //        i++;
  //    } while(c != '\0' && i < 100); //stop at null or full buffer
  //    if(i == 100) {
  //        cout << "Error - too long a string!!!";
  //        exit(0);
  //    }
  //    //See what we got
  //    cout << buffer << endl;

  // Read in the ints
  int num1, num2;
  inFile.read(reinterpret_cast<char*>(&num1), sizeof(num1));
  inFile.read(reinterpret_cast<char*>(&num2), sizeof(num2));

  cout << num1 << endl;
  cout << num2 << endl;
}
