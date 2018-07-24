#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string convert_to_input(string _input);

int main() {

  string input;
  string output;

  cout << endl;
  cout << "Enter the text to be converted to the input format" << endl;
  cin >> input;
  cout << endl << endl;

  output = convert_to_input(input);

  cout << "./zokrates compute-witness -a " << output << endl << endl;


  return 0;
}

string convert_to_input(string input) {
  string output;
  string reformatted_output;

  // Convert the input into binary first of all
  for (size_t i = 0; i < input.size(); ++i) {
    bitset<8> b(input.c_str()[i]);
    output += b.to_string();
  }

  // Then pad out to 512 bits
  for (int j = output.size(); j < 512; j++) {
    output += '0';
  }

  // The insert whitespace
  for (int k = 0; k <512; k++) {
    reformatted_output += output[k];
    reformatted_output += " ";
  }

  return reformatted_output;
}
