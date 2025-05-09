import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class MD5Example_7 {

    // Method to compute MD5 hash of a given input string
    public static String getMD5Hash(String input) throws NoSuchAlgorithmException {
        // Step 1: Get a MessageDigest instance configured for MD5
        MessageDigest md = MessageDigest.getInstance("MD5");

        // Step 2: Feed the input string's bytes into the digest
        md.update(input.getBytes());

        // Step 3: Perform the hashing operation (digest) and get the byte array
        byte[] digest = md.digest();

        // Step 4: Convert the byte array into a hexadecimal string
        StringBuilder hexString = new StringBuilder();
        for (byte b : digest) {
            // Convert each byte to a two-digit hexadecimal string and append
            hexString.append(String.format("%02x", b));
        }

        // Step 5: Return the final hex string (the MD5 hash)
        return hexString.toString();
    }

    public static void main(String[] args) throws NoSuchAlgorithmException {
        String input = "HelloWorld"; // Example input string
        String md5Hash = getMD5Hash(input); // Compute the MD5 hash of the input

        // Print the result
        System.out.println("MD5 Hash of \"" + input + "\" is: " + md5Hash);
    }
}


/*
-------------------------------
Theory: What is MD5?
-------------------------------

🔐 MD5 (Message Digest Algorithm 5) is a cryptographic hash function:
- Input: Any length of data (e.g., a string like "HelloWorld")
- Output: A 128-bit (16-byte) hash value, usually represented as a 32-character hexadecimal number

-------------------------------
⚙️ How MD5 Works:
-------------------------------
1. **Padding**: The input message is padded so its length is a multiple of 512 bits.
2. **Appending Length**: The original length of the message is added to the end of the padded data.
3. **Divide into Blocks**: The padded message is split into 512-bit blocks.
4. **Processing**: Each block is processed by a compression function involving bitwise operations and modulo additions.
5. **Output**: A 128-bit (32 hex characters) digest is produced.

-------------------------------
✅ Properties of MD5:
-------------------------------
- **Deterministic**: Same input → Same output
- **Fast**: Efficient and quick to compute
- **Fixed-size output**: Always 128-bit (32 hex characters)
- **Non-reversible**: Cannot get the original input from the hash

❌ **Note**: MD5 is not considered secure for modern cryptographic purposes like password storage or digital signatures due to vulnerabilities (e.g., collision attacks). It's still used for checksums and non-security-critical applications.

*/
