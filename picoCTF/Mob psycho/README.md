# Mob psycho

## Description

Can you handle APKs? Download the android apk [here](https://artifacts.picoctf.net/c_titan/142/mobpsycho.apk).

## Solution

The actual solution is simple enough.

Unzip the APK,

```sh
unzip "Mob Psycho.apk"
```

Find possible files named flag,

```sh
find . -type f -name "*flag*"
```

We get an output for "./res/color/flag.txt".

The flag is stored as a hexadecimal dump. We can use the `xxd` command on here. Here is a bit more on the below `xxd` command we are going to use,

- `xxd -r -p`:
  • `xxd` is a utility for creating and reversing hexadecimal dumps of binary data.
  • `-r`: Reverses the operation of xxd, converting the hexadecimal back into binary.
  • `-p`: Enables “plain hexdump” mode, where the input is expected to be a continuous string of hexadecimal characters without address or ASCII annotations.

For now, we can get the flag like so,

```sh
➜  Mob psycho git:(main) ✗ cat res/color/flag.txt | xxd -r -p
picoCTF{ax8mC0RU6ve_NX85l4ax8mCl_746dfa39}
```

Where `picoCTF{ax8mC0RU6ve_NX85l4ax8mCl_746dfa39}` is the required flag.

## Misc

I went off the rails and started reading more deeply about Android Malware Analysis. I am saving the below here for future references.

## Quick Commands

### Search for Encoded or Obfuscated Flags

Flags in CTFs are often encoded or obfuscated. If grepping didn't work, try these steps:

- **Check Common Encodings**:
  - Search for Base64-encoded strings:

  ```bash
  grep -E '([A-Za-z0-9+/]{20,})' decompiled_apk/smali/ -r
  ```

  - Look for hexadecimal patterns:

    ```bash
    grep -E '0x[0-9a-fA-F]+' decompiled_apk/smali/ -r
    ```

- Search for ROT13, XOR, or other simple transformations (you may need to write scripts).
- **Analyze Cryptographic Functions**:
- Search for cryptographic APIs:

    ```bash
    grep -E 'AES|DES|RC4|Cipher|getInstance|SecretKey' -r decompiled_apk/smali/
    ```

- Decrypt hardcoded values in `smali` files using known algorithms.

### Analyze `AndroidManifest.xml`

- Focus on:
  - **Entry Points**: Activities with `android.intent.action.MAIN` or `LAUNCHER`.
  - **Permissions**: These might reveal the app's functionality.
  - **Exported Components**: Activities, services, or receivers marked `android:exported="true"` could indicate accessible functionality.

### **Inspect Decompiled Code**

- **Search for Functions Handling Data**:
  - Look for methods like `onCreate`, `onClick`, or suspicious handlers.
  - Check for conditions where flags might be returned:

    ```bash
    grep -i "if" decompiled_apk/smali/ -r
    ```

  - Search for log statements (e.g., `Log.d` or `System.out.println`).  - **Analyze User Input or Interaction**:
  - Look for methods that parse input (e.g., `getText`, `setOnClickListener`).
  - Sometimes, entering specific inputs or solving puzzles in code leads to the flag.

### **Analyze Resources**

- Check `res/values/strings.xml` for hardcoded secrets.
- Look at `res/raw/` and `res/assets/` for hidden files.
- Inspect images and media files in `res/drawable/`:
  - Hidden data might be encoded using steganography. Tools like **stegsolve** can help.

### **Investigate Smali Code**

- If the APK uses obfuscation, Java decompilers like JADX might not be enough. Use Smali for deeper insights:
  - Decompile with APKTool and review the `smali` files.
  - Look for suspiciously short or repetitive method and class names.

### **Analyze Dex Files**

- Use `strings` on the `.dex` files to find hidden content:

    ```bash
    strings decompiled_apk/classes.dex | grep "flag"
    ```

- Disassemble the `.dex` files with **smali** or **baksmali**:Inspect the disassembled code for flag-related logic.

    ```bash
    baksmali disassemble classes.dex -o dex_output/
    ```

### **Examine Native Libraries**

- If the APK contains `.so` files (native libraries):
  - Extract them from `lib/` or `jni/`.
  - Analyze with `strings`:

    ```bash
    strings lib/arm64-v8a/libnative.so | grep "flag"
    ```

- Disassemble with tools like Ghidra or Radare2.

### **Check for Hidden Data in APK Structure**

- Sometimes, flags are hidden in non-standard locations:
  - Open the APK as a ZIP archive and inspect all files.
  - Search for hidden files or directories (e.g., `.hidden` or unusual extensions).

### **Simulate Execution with Tools**

- Use **Taint Analysis**:
  - Tools like **FlowDroid** or **Androguard** can simulate execution paths without running the app.
  - Trace the flow of data, especially sensitive strings.
- Use **Static Instrumentation**:
  - Modify the APK's smali code to reveal hidden strings or log key variables.

### **Analyze External Communication**

- Inspect hardcoded URLs or API endpoints:

    ```bash
    grep -E 'http|https' decompiled_apk/ -r
    ```

- Analyze requests made by the app:
  - Simulate network calls using tools like **Postman** or **cURL**.

### **Obfuscation Handling**

- Check if the code is obfuscated:
  - Look for unusual class/method names (`a.a.a` or `abc123`).
- Use **Procyon** or **Fernflower** to attempt better decompilation.
- Tools like **Androguard** can help automate some static analysis tasks.

### **Dynamic Testing**

- Use **Frida** for dynamic hooking:

    ```bash
    frida -U -n <package-name>
    ```

- Use **Objection** to explore running APKs:

    ```bash
    objection explore
    ```

### **Preliminary Inspection**

- **Identify the APK**: Rename it to `target.apk` if needed.  - **Inspect metadata**:

    ```bash
    file target.apk
    strings target.apk | less
    ```

- **Verify the APK's signature**:

    ```bash
    keytool -printcert -jarfile target.apk
    ```

- **Extract the APK contents**:

    ```bash
    unzip target.apk -d extracted/
    ```

---

### **3. Decompile the APK**

- Use **APKTool** to decompile resources:

    ```bash
    bash
    Copy code
    apktool d target.apk -o decompiled_apk
    
    ```

- Use **JADX** to decompile the Java classes:Open `classes.dex` files to view the code.

    ```bash
    bash
    Copy code
    jadx-gui target.apk
    
    ```

---

### **4. Analyze the Manifest**

- Check `AndroidManifest.xml` (using APKTool):
  - Look for **permissions** (e.g., `INTERNET`, `READ_SMS`).
  - Examine declared activities, services, and broadcast receivers.
  - Check for entry points (`android.intent.action.MAIN`).

---

### **5. Analyze Code**

- **Static analysis**:
  - Look for hardcoded credentials, keys, or URLs.
  - Search for methods like `onCreate()`, `onClick()`, or custom cryptography.
  - Use search keywords like `getSharedPreferences`, `execute`, `base64`, `AES`, etc.  - **Dynamic analysis**:
  - Install on an emulator or device with logging enabled.
  - Use **Frida** or **Objection** to hook and inspect the app's behavior.

---

### **6. Inspect Native Libraries**

- If the APK contains native code (`.so` files):
  - Use **`strings`** on `.so` files to find interesting functions or text.
  - Disassemble using `ghidra` or `IDA Pro`.

---

### **7. Analyze Network Traffic**

- Install the APK on an emulator or a test device.
- Use **Burp Suite** or **mitmproxy** to intercept and analyze network traffic:
  - Set up a proxy and configure the device.
  - Analyze HTTPS traffic (may require installing a custom CA).
