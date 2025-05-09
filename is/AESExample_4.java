import java.util.Base64;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;

// These are the necessary **imports**:
// - `Base64`: To convert encrypted binary data into a readable string.
// - `Cipher`: Provides encryption and decryption functionalities.
// - `KeyGenerator`: Used to generate a random AES key.
// - `SecretKey`: Represents the symmetric key.

// ---

// ### ```java
// String plainText = "HelloWorld123";

public class AESExample_4 {
    public static void main(String[] args) throws Exception {
        String plainText = "HelloWorld123";

        // Generate AES key
        KeyGenerator keyGen = KeyGenerator.getInstance("AES");
        keyGen.init(128); // 128-bit AES
        SecretKey secretKey = keyGen.generateKey();

        // KeyGenerator.getInstance("AES"): Creates a key generator for the AES algorithm.
        // keyGen.init(128): Sets the key size to 128 bits (you can also use 192 or 256 if supported).
        // generateKey(): Generates a random secret key to use for both encryption and decryption.

        // Create Cipher instance and initialize it
        Cipher aesCipher = Cipher.getInstance("AES");
        // This creates a Cipher object for AES encryption. It uses the default mode: "AES/ECB/PKCS5Padding".

        // Encryption
        aesCipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encryptedBytes = aesCipher.doFinal(plainText.getBytes());
        String encryptedText = Base64.getEncoder().encodeToString(encryptedBytes);
        System.out.println("Encrypted Text (AES): " + encryptedText);
        // init(Cipher.ENCRYPT_MODE, secretKey): Prepares the cipher to encrypt using the generated secret key.
        // doFinal(plainText.getBytes()): Encrypts the plaintext bytes.
        // Base64.getEncoder()...: Converts the encrypted byte array into a readable Base64 string.
        // The encrypted output is printed.

        // Decryption
        aesCipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] decryptedBytes = aesCipher.doFinal(encryptedBytes);
        String decryptedText = new String(decryptedBytes);
        System.out.println("Decrypted Text (AES): " + decryptedText);
        // init(Cipher.DECRYPT_MODE, secretKey): Re-initializes the cipher for decryption.
        // doFinal(encryptedBytes): Decrypts the encrypted byte array back into plaintext.
        // The decrypted output is printed.
    }
}

// How AES Works – In Simple Steps
// AES encrypts data in blocks of 128 bits (16 bytes). Think of it like encrypting a 4x4 grid of bytes.

// 1. Key Expansion
// AES generates round keys from the original key using a key schedule.

// 2. Initial Round
// AddRoundKey: XOR the input data with the first round key.

// 3. Main Rounds (repeated 9, 11, or 13 times depending on key size)
// Each round has 4 steps:

// Step	Description
// SubBytes	Each byte is replaced using a fixed S-box (a substitution table) for confusion.
// ShiftRows	Rows of the grid are shifted left by different amounts to mix data.
// MixColumns	Each column is transformed mathematically for diffusion (mixes data within columns).
// AddRoundKey	The round key is XORed with the current state (grid).

// 4. Final Round
// Same as a main round but without MixColumns.
