# Vault Door 3

We are provided a `java` file for this.

The below is the key method for the key,

```java
    public boolean checkPassword(String password) {
        if (password.length() != 32) {
            return false;
        }
        char[] buffer = new char[32];
        int i;
        for (i=0; i<8; i++) {

            buffer[i] = password.charAt(i);
        }
        for (; i<16; i++) {
            buffer[i] = password.charAt(23-i);
        }
        for (; i<32; i+=2) {
            buffer[i] = password.charAt(46-i);
        }
        for (i=31; i>=17; i-=2) {
            buffer[i] = password.charAt(i);
        }
        System.out.println(buffer);
        return new String(buffer).equals("jU5t_a_sna_3lpm18g947_u_4_m9r54f");
    }
```

We are comparing to a string scrambled key.

Simply output the buffer, which is `jU5t_a_s1mpl3_an4gr4m_4_u_79958f`, so our flag becomes `picoCTF{jU5t_a_s1mpl3_an4gr4m_4_u_79958f}`.
