import java.util.Base64;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;

// These are import statements:
// Base64 is used for encoding/decoding the encrypted bytes into a readable string.
// Cipher provides encryption and decryption functionality.
// KeyGenerator and SecretKey are used to generate a DES key.



public class DESExample_3 {
    public static void main(String[] args) throws Exception {
        String plainText = "HelloWorld";

        // This is the input plaintext to be encrypted using DES.

        // Generate DES key
        KeyGenerator keyGen = KeyGenerator.getInstance("DES");
        SecretKey secretKey = keyGen.generateKey();

//  KeyGenerator.getInstance("DES") creates a DES key generator.
// generateKey() generates a random 56-bit secret key for DES.

        // Create Cipher instance and initialize it
        Cipher desCipher = Cipher.getInstance("DES");

// This creates a Cipher object for the DES algorithm.
// Internally, it defaults to using ECB mode with PKCS5 padding, i.e., "DES/ECB/PKCS5Padding".

        // Encryption
        desCipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encryptedBytes = desCipher.doFinal(plainText.getBytes());
        String encryptedText = Base64.getEncoder().encodeToString(encryptedBytes);
        System.out.println("Encrypted Text (DES): " + encryptedText);

//  init() initializes the cipher in encryption mode using the secret key.
// doFinal() performs the actual encryption on the plaintext bytes.
// The encrypted byte array is converted into a Base64 string to make it printable.

        // Decryption
        desCipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] decryptedBytes = desCipher.doFinal(encryptedBytes);
        String decryptedText = new String(decryptedBytes);
        System.out.println("Decrypted Text (DES): " + decryptedText);
    }
}

// The cipher is re-initialized in decryption mode using the same key.
// The encrypted bytes are decrypted back to plaintext.
// The resulting byte array is converted back into a string.


// How DES Works – In Simple Steps
// Initial Permutation (IP):
// The 64-bit plaintext is permuted (rearranged) according to a fixed table.
// 16 Rounds of Encryption (Feistel Structure):
// The block is split into left and right halves.
// In each round:
// A complex function f() is applied using a round key (derived from the main key).
// The right half and the output of f() are XORed and swapped.
// Final Permutation (IP⁻¹):
