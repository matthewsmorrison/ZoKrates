#include<iostream>
#include<cstdlib>
#include<string>
#include<bitset>

using namespace std;

string convert_to_input(string input);
string hex_to_binary(string input);
string worgl_encode(string input);
string first_four_bytes(string input);
string put_spaces_in(string input);

int main() {

  string input;
  string output;

  cout << endl;
  cout << "Enter the input" << endl;
  cin >> input;
  cout << endl << endl;

  output = first_four_bytes(input);

  cout << "The output is: " << output << endl;
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

string hex_to_binary(string input) {
  string output;

  for (size_t i=0; i < input.size(); i++) {
    bitset<4> b(input.c_str()[i]);
    output += b.to_string();
  }

  return output;
}

string worgl_encode(string input) {
  string output;
  int temporary_sum;
  int size = 32;

  // Check that the input has 256 bits
  if (input.size() != 256) {
    return "Input is not 256 bits";
  }

  else {
    for (int i = 0; i < (256/size); i++) {
      temporary_sum = 0;
      for (int j=0; j < size; j++) {
        temporary_sum += (input[j+i] - 48);
      }
      output += to_string(temporary_sum);
      output += " ";
    }

    return output;
  }
}

string first_four_bytes(string input) {
  string output;

  for (int i=0; i<32; i++) {
    output += input[i];
    output += " ";
  }

  return output;
}

string put_spaces_in(string input) {
  string output;

  

}

// Input (ASCII): MatthewMorrison
// In Binary: 010011010110000101110100011101000110100001100101011101110100110101101111011100100111001001101001011100110110111101101110
// In Binary (Padded to 512): 01001101011000010111010001110100011010000110010101110111010011010110111101110010011100100110100101110011011011110110111000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
// SHA256 Compression: 0101010001010110110111010100100100000101010000000101001110111101001011111111011111010111111010101010111011000011101000000110010111001011001010110011100010111111111111010011001011010000101111111011100100110101011111101100101111111101101010111010101110100011
