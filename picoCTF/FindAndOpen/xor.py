# Input string (you can replace this with any string you want to test)
input_string = "bababkjaASKBKSBA CVVAVSDDSSSSDSKJ BJS"

# Function to apply XOR with a given key
def xor_with_key(input_string, key):
    # Convert input string to bytes
    input_bytes = input_string.encode('utf-8')
    result = b""
    # Iterate over each byte of the input
    for byte in input_bytes:
        # XOR each byte with the key and append to result
        xor_byte = byte ^ key
        result += bytes([xor_byte])
    return result

# Loop through keys from 0x01 to 0xFF
for key in range(1, 256):
    print(f"Key: 0x{key:02X}")
    xor_result = xor_with_key(input_string, key)
    print(xor_result.decode('utf-8', errors='ignore'))
    print()
