def hex_to_char(hex_str):
    # Remove '0x' prefix if present
    if hex_str.startswith('0x'):
        hex_str = hex_str[2:]
    # Convert hex to integer
    integer_value = int(hex_str, 16)
    # Convert integer to character
    return chr(integer_value)

i = "0x70 0x69 0x63 0x6f 0x43 0x54 0x46 0x7b 0x37 0x68 0x31 0x35 0x5f 0x31 0x35 0x5f 0x77 0x68 0x34 0x37 0x5f 0x77 0x33 0x5f 0x67 0x33 0x37 0x5f 0x77 0x31 0x37 0x68 0x5f 0x75 0x35 0x33 0x72 0x35 0x5f 0x31 0x6e 0x5f 0x63 0x68 0x34 0x72 0x67 0x33 0x5f 0x32 0x32 0x36 0x64 0x64 0x32 0x38 0x35 0x7d"
hex_vals = i.split(' ')
for val in hex_vals:
  print(hex_to_char(val), end="")
