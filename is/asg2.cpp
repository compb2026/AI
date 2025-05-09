#include <iostream>
#include <string>
using namespace std;

// Encrypt: write row-wise, read column-wise
string encrypt(string text, int key) {
    string cipher = "";
    int len = text.length();

    // Read column-wise
    for (int col = 0; col < key; col++) {
        for (int i = col; i < len; i += key) {
            cipher += text[i];
        }
    }

    return cipher;
}

// Decrypt: reverse of encryption
string decrypt(string cipher, int key) {
    int len = cipher.length();
    int rows = (len + key - 1) / key;
    string plain(len, ' ');

    int index = 0;
    for (int col = 0; col < key; col++) {
        for (int i = col; i < len; i += key) {
            if (index < len)
                plain[i] = cipher[index++];
        }
    }

    return plain;
}

int main() {
    string text;
    int key;

    cout << "Enter plain text (no spaces): ";
    cin >> text;
    cout << "Enter key (e.g., 4): ";
    cin >> key;

    string encrypted = encrypt(text, key);
    cout << "Encrypted: " << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
