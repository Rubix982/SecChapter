# CET

Control-flow hijacking is a technique used by attackers to divert the normal execution flow of a program to execute malicious code. Control-flow Enforcement Technology (CET) is a security feature introduced by Intel to mitigate such attacks. Let's explore CET and the concept of control-flow hijacking in more detail.

### Control-flow Hijacking

Control-flow hijacking exploits typically involve manipulating the program's control flow to execute arbitrary code. Common methods include:

1. **Buffer Overflow**: Overwriting the return address on the stack to redirect execution to malicious code.
2. **Return-Oriented Programming (ROP)**: Chaining together small code snippets (gadgets) already present in memory to perform arbitrary computations.
3. **Jump-Oriented Programming (JOP)**: Similar to ROP but using indirect jumps instead of returns.
4. **Function Pointer Overwrite**: Overwriting function pointers to redirect execution.

### Control-flow Enforcement Technology (CET)

CET introduces two main features to protect against control-flow hijacking:

1. **Shadow Stack**: A separate stack that stores copies of return addresses to prevent return address corruption.
2. **Indirect Branch Tracking (IBT)**: Ensures that indirect branches (e.g., function pointers, virtual calls) can only target valid locations.

### CET Mechanisms

#### Shadow Stack

- **Purpose**: Protects return addresses from being tampered with.
- **Mechanism**: Maintains a separate stack (shadow stack) that mirrors the normal stack's return addresses. When a function returns, the return address from the normal stack is compared with the shadow stack. If they do not match, an error is raised.

#### Indirect Branch Tracking (IBT)

- **Purpose**: Ensures indirect branches target only valid destinations.
- **Mechanism**: Uses a new instruction (`endbr64` for 64-bit, `endbr32` for 32-bit) at valid branch targets. If an indirect branch does not land on an `endbr` instruction, the CPU raises an error.

### Example: Control-flow Hijacking with and without CET

#### Without CET

Consider a vulnerable program with a buffer overflow:

```c
void vulnerable_function(char *input) {
    char buffer[64];
    strcpy(buffer, input); // No bounds checking
}

void main() {
    char user_input[128];
    gets(user_input); // Dangerous: allows overflow
    vulnerable_function(user_input);
}
```

An attacker can overflow `buffer` and overwrite the return address to point to malicious code.

#### With CET

The same program with CET protection:

1. **Shadow Stack**: The return address is also pushed onto the shadow stack. When `vulnerable_function` returns, the return address on the normal stack is compared with the shadow stack. If an overflow occurred, they would not match, and the program would terminate.

2. **Indirect Branch Tracking**: Any indirect branch (like function pointers) must target an `endbr64` instruction. If an attacker tries to hijack the control flow to a gadget or malicious code without a valid `endbr64`, the CPU raises an error.

### Practical Use of CET

1. **Compiler Support**: Modern compilers like GCC and Clang have options to enable CET features.
2. **Hardware Support**: Requires a CPU that supports CET (e.g., Intel's Tiger Lake and later).
3. **Operating System Support**: The OS must also support CET (e.g., recent versions of Linux and Windows).

### Summary

- **Control-flow Hijacking**: Techniques like buffer overflows and ROP are used to redirect program execution to malicious code.
- **CET**: Introduces Shadow Stack and IBT to protect return addresses and indirect branches.
  - **Shadow Stack**: Stores return addresses separately to prevent tampering.
  - **IBT**: Ensures indirect branches land on valid targets marked by `endbr64`.
- **With and Without CET**: CET mitigates control-flow hijacking by adding hardware-enforced checks, making it significantly harder for attackers to divert the program's execution flow.

By integrating CET into both hardware and software, Intel has provided a robust solution to counteract common exploitation techniques, enhancing the security of modern computing environments.

## Exploits

If an attacker attempts to introduce `endbr64` instructions at the correct places to bypass CET's Indirect Branch Tracking (IBT), there are still several factors that make this approach difficult and significantly reduce the effectiveness of such an attack. Here are the key considerations:

### Challenges for the Attacker

1. **Read-Only Code Sections**: In modern operating systems, code sections are typically marked as read-only. This means an attacker cannot easily modify the binary to insert `endbr64` instructions without exploiting another vulnerability that allows writing to these sections.

2. **Address Space Layout Randomization (ASLR)**: ASLR randomizes the memory addresses used by executable code, making it difficult for an attacker to predict where to place their `endbr64` instructions.

3. **Control Flow Integrity (CFI)**: CET's shadow stack ensures the integrity of return addresses. Even if an attacker can insert `endbr64` instructions, they would still need to manage the shadow stack to align return addresses, which adds complexity.

4. **Inserting Gadgets**: Placing `endbr64` instructions correctly means the attacker must have fine-grained control over the placement of their code, which is highly non-trivial given modern defenses like DEP (Data Execution Prevention) and stack canaries.

### Practical Impact of CET

1. **Indirect Branch Targets**: CET ensures that all valid indirect branch targets (e.g., function pointers, virtual calls) are marked with `endbr64`. This drastically reduces the number of possible gadgets an attacker can use for Return-Oriented Programming (ROP) or Jump-Oriented Programming (JOP).

2. **Increased Complexity**: Even if an attacker could place `endbr64` instructions, they would still need to carefully control the execution flow to avoid detection by other security measures.

### Example Attack Scenario

Let's consider a hypothetical attack where the attacker can write to the code section:

1. **Initial Exploit**: The attacker uses a buffer overflow to gain write access to the code section.
2. **Placing `endbr64`**: The attacker tries to place `endbr64` instructions before their gadgets.
3. **ROP Chain**: The attacker constructs a ROP chain that jumps through the gadgets.

**Mitigations**:
- **Read-Only Protection**: Modern OS protections would need to be bypassed to write to code sections.
- **ASLR**: The attacker would need to know the exact locations of their gadgets, which ASLR makes difficult.
- **Shadow Stack**: Return addresses are checked against the shadow stack, so any tampering would be detected unless the attacker also manages to manipulate the shadow stack.
- **End-to-End Validation**: Even if gadgets are used, they need to lead to meaningful malicious behavior while evading detection mechanisms.

### Conclusion

While theoretically possible, the complexity and number of hurdles make it extremely difficult for an attacker to introduce `endbr64` instructions in a meaningful way. CET, combined with other modern security mechanisms like ASLR, DEP, and CFI, provides robust protection against control-flow hijacking attacks.

In summary, CET significantly raises the bar for attackers. Introducing `endbr64` in the correct places is not a straightforward task due to read-only code sections, ASLR, and the need to manipulate the shadow stack. These combined defenses make it challenging for an attacker to succeed, thereby enhancing the overall security of the system.

