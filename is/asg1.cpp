#include <iostream>
using namespace std;

int main() {
    const char* str = "Hello\nWorld";

    cout << "Original String: " << str << endl;

    cout << "\nAfter AND with 127:\n";
    for (int i = 0; str[i] != '\0'; ++i) {
        cout << (char)(str[i] & 127);
    }

    cout << "\n\nAfter XOR with 127:\n";
    for (int i = 0; str[i] != '\0'; ++i) {
        cout << (char)(str[i] ^ 127);
    }

    cout << endl;
    return 0;
}


// | Char | ASCII | Binary        | XOR with 127                   | Result ASCII | Output Char       |
// | ---- | ----- | ------------- | ------------------------------ | ------------ | ----------------- |
// | H    | 72    | 01001000      | 01001000 ^ 01111111 = 00110111 | 55           | `7`               |
// | e    | 101   | 01100101      | 01100101 ^ 01111111 = 00011010 | 26           | ␚ (non-printable) |
// | l    | 108   | 01101100      | 01101100 ^ 01111111 = 00010011 | 19           | ␓ (non-printable) |
// | l    | 108   | same as above | same                           | 19           | ␓                 |
// | o    | 111   | 01101111      | 01101111 ^ 01111111 = 00010000 | 16           | ␐                 |
// | \n   | 10    | 00001010      | 00001010 ^ 01111111 = 01110101 | 117          | `u`               |
// | W    | 87    | 01010111      | 01010111 ^ 01111111 = 00101000 | 40           | `(`               |
// | o    | 111   | same as above | same                           | 16           | ␐                 |
// | r    | 114   | 01110010      | 01110010 ^ 01111111 = 00001101 | 13           | ␍                 |
// | l    | 108   | same as above | 19                             | ␓            |                   |
// | d    | 100   | 01100100      | 01100100 ^ 01111111 = 00011011 | 27           | ␛                 |
