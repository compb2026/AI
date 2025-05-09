#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Function to calculate GCD (Greatest Common Divisor)
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to find the modular inverse of e modulo phi
// This finds d such that (e * d) % phi == 1
int modInverse(int e, int phi) {
    for (int d = 1; d < phi; d++) {
        if ((e * d) % phi == 1) {
            return d;
        }
    }
    return -1; // If no modular inverse is found
}

// Function to perform fast modular exponentiation: (base^exp) % mod
long long powerMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;  // First reduce base under modulo
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;  // If exponent is odd
        }
        exp = exp >> 1;  // Divide exponent by 2
        base = (base * base) % mod;  // Square the base
    }
    return result;
}

int main() {
    // Step 1: Choose two prime numbers (small ones for demo)
    int p = 61, q = 53;
    int n = p * q;               // Step 2: n = p * q, part of public/private key
    int phi = (p - 1) * (q - 1); // Step 3: Compute Euler's Totient φ(n)

    // Step 4: Choose public exponent e such that 1 < e < phi and gcd(e, phi) == 1
    int e = 17;
    while (gcd(e, phi) != 1) e++; // Ensure e and phi are coprime

    // Step 5: Compute private key exponent d (modular inverse of e modulo phi)
    int d = modInverse(e, phi);

    // Output the keys
    cout << "Public key: (" << e << ", " << n << ")\n";
    cout << "Private key: (" << d << ", " << n << ")\n";

    // Step 6: Input plaintext from user
    string plaintext;
    cout << "Enter plaintext: ";
    cin >> plaintext;

    // Step 7: Encrypt each character of the plaintext using (char^e) % n
    vector<long long> ciphertext;
    for (char c : plaintext) {
        ciphertext.push_back(powerMod(c, e, n)); // RSA encryption formula
    }

    // Display encrypted ciphertext (as numbers)
    cout << "Encrypted ciphertext: ";
    for (long long c : ciphertext) {
        cout << c << " ";
    }
    cout << endl;

    // Step 8: Decrypt the ciphertext using (char^d) % n
    string decrypted = "";
    for (long long c : ciphertext) {
        decrypted += (char)powerMod(c, d, n); // RSA decryption formula
    }

    // Output the decrypted text
    cout << "Decrypted plaintext: " << decrypted << endl;

    return 0;
}


/*
-----------------------------------
📘 THEORY: How RSA Works (Simplified)
-----------------------------------

🔐 RSA is an asymmetric encryption algorithm:
- It uses **two keys**: Public key for encryption, Private key for decryption.
- Based on the mathematical difficulty of factoring large primes.

-----------------------------------
⚙️ Steps in RSA Algorithm:
-----------------------------------
1. **Key Generation**
   - Choose two large prime numbers: `p` and `q`
   - Compute `n = p * q` (used in both keys)
   - Compute Euler's totient: `phi = (p-1)*(q-1)`
   - Choose `e` such that 1 < e < phi and gcd(e, phi) = 1
   - Compute `d` as the modular inverse of e mod phi
   - Public Key: `(e, n)`, Private Key: `(d, n)`

2. **Encryption**
   - Cipher = (Message^e) % n

3. **Decryption**
   - Message = (Cipher^d) % n

-----------------------------------
🧠 Example:
- If plaintext = 'A' (ASCII 65)
- Encrypt with (65^e) % n → Encrypted number
- Decrypt with (Encrypted^d) % n → Back to 65 → 'A'

-----------------------------------
✅ RSA Properties:
- **Secure**: Based on factoring difficulty
- **Asymmetric**: Public key can be shared openly
- **Widely Used**: SSL/TLS, digital signatures, secure email

❗ Note: For real-world applications, use much larger primes (1024+ bits) for security.

*/
