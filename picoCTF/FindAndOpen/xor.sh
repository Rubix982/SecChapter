#!/bin/bash

# Input string (you can replace this with any string you want to test)
input="bababkjaASKBKSBA CVVAVSDDSSSSDSKJ BJS"

# Convert input string to hexadecimal
input_hex=$(echo -n "$input" | xxd -p)

# Function to apply XOR with a given key
xor_with_key() {
    local hex_string=$1
    local key=$2
    result=""
    # Iterate over each byte of the input hex string
    for (( i=0; i<${#hex_string}; i+=2 )); do
        byte="${hex_string:i:2}"
        # Convert the hex byte to decimal, then XOR it with the key
        byte_dec=$((16#${byte}))  # Convert hex byte to decimal
        key=$((byte_dec ^ key))    # XOR operation
        xor_result=$(printf "%02x" "$key")  # Convert the result back to hex
        result+="$xor_result"
    done
    # Convert the resulting hex back to ASCII
    echo "$result" | xxd -r -p
}

# Loop through keys from 0x01 to 0xFF
for key in $(seq 1 255); do
    echo "Key: 0x$(printf '%02X' $key)"
    xor_with_key "$input_hex" $key
    echo
done
