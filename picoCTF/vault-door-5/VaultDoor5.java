import java.io.ByteArrayOutputStream;
import java.net.URLDecoder;
import java.nio.charset.StandardCharsets;
import java.util.*;

class VaultDoor5 {
    public static void main(String args[]) {
        VaultDoor5 vaultDoor = new VaultDoor5();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter vault password: ");
        String userInput = scanner.next();
        System.out.println(vaultDoor.urlDecode("%63%30%6e%76%33%72%74%31%6e%67%5f%66%72%30%6d%5f%62%61%35%65%5f%36%34%5f%65%33%31%35%32%62%66%34"));
	String input = userInput.substring("picoCTF{".length(),userInput.length()-1);
	if (vaultDoor.checkPassword(input)) {
	    System.out.println("Access granted.");
	} else {
	    System.out.println("Access denied!");
        }
    }

    public String urlDecode(String input) {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        
        for (int i = 0; i < input.length(); i += 3) {
            if (input.charAt(i) == '%') {
                // Extract the hex value from the substring
                String hex = input.substring(i + 1, i + 3);
                // Convert hex to byte
                byte b = (byte) Integer.parseInt(hex, 16);
                baos.write(b);
                i += 2; // Move i to skip the next two characters (the hex digits)
            } else {
                // This case shouldn't normally occur in strict URL encoding, as % indicates start of hex encoding
                // But to handle malformed or incorrectly encoded strings, you might add error handling here
                // For simplicity, let's assume we are dealing with correctly encoded input.
                // You may add validation or error handling based on your specific requirements.
            }
        }
        
        // Convert ByteArrayOutputStream to String using UTF-8 encoding
        String decodedString = new String(baos.toByteArray(), StandardCharsets.UTF_8);
        
        return decodedString;
    }    

    // URL encoding is meant for web pages, so any double agent spies who steal
    // our source code will think this is a web site or something, defintely not
    // vault door! Oh wait, should I have not said that in a source code
    // comment?
    //
    // -Minion #2415
    public String urlEncode(byte[] input) {
        StringBuffer buf = new StringBuffer();
        for (int i=0; i<input.length; i++) {
            buf.append(String.format("%%%2x", input[i]));
        }
        return buf.toString();
    }

    public boolean checkPassword(String password) {
        System.out.println(password);
        System.out.println(password.getBytes());
        String urlEncoded = urlEncode(password.getBytes());
        System.out.println(urlEncoded);
        System.out.println(urlEncoded.getBytes());
        String base64Encoded = Base64.getEncoder().encodeToString(urlEncoded.getBytes());
        System.out.println(base64Encoded);
        String expected = "JTYzJTMwJTZlJTc2JTMzJTcyJTc0JTMxJTZlJTY3JTVmJTY2JTcyJTMwJTZkJTVmJTYyJTYxJTM1JTY1JTVmJTM2JTM0JTVmJTY1JTMzJTMxJTM1JTMyJTYyJTY2JTM0";
        System.out.println(expected);
        // %63%30%6e%76%33%72%74%31%6e%67%5f%66%72%30%6d%5f%62%61%35%65%5f%36%34%5f%65%33%31%35%32%62%66%34
        return base64Encoded.equals(expected);
    }
}
