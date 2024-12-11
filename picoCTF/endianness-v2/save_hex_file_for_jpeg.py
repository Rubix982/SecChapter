def decode_and_save_file(input_file, output_file):
    """
    Decode a hex-encoded file and save it as a binary file
    
    Args:
    - input_file (str): Path to the input file with hex data
    - output_file (str): Path to save the decoded binary file
    """
    # Read the hex data
    with open(input_file, 'rb') as f:
        hex_data = f.read()
    
    # Convert hex to bytes
    file_hex = hex_data.hex()
    
    # Reverse bytes in 8-character (4-byte) chunks
    reversed_hex = ""
    for i in range(0, len(file_hex), 8):
        chunk = file_hex[i:i+8]
        reversed_hex += chunk[::-1]
    
    # Convert back to bytes
    decoded_bytes = bytes.fromhex(reversed_hex)
    
    # Save as binary file
    with open(output_file, 'wb') as f:
        f.write(decoded_bytes)
    
    print(f"File saved as {output_file}")

def verify_file_type(filename):
    """
    Attempt to verify the file type based on magic numbers
    
    Args:
    - filename (str): Path to the file to check
    
    Returns:
    - str: Detected file type or 'Unknown'
    """
    # Common file type signatures (magic numbers)
    signatures = {
        b'\xFF\xD8\xFF': 'JPEG',
        b'\x89PNG\r\n\x1a\n': 'PNG',
        b'PK\x03\x04': 'ZIP',
        b'GIF87a': 'GIF87',
        b'GIF89a': 'GIF89'
    }
    
    with open(filename, 'rb') as f:
        # Read first few bytes
        header = f.read(10)
        
        for sig, file_type in signatures.items():
            if header.startswith(sig):
                return file_type
    
    return 'Unknown'

def main():
    # Files to process
    input_file = 'mystery'   # Input hex-encoded file
    output_file = 'analyze.jpg'  # Output JPEG file
    
    # Decode and save the file
    decode_and_save_file(input_file, output_file)
    
    # Verify file type
    file_type = verify_file_type(output_file)
    print(f"Detected file type: {file_type}")

if __name__ == '__main__':
    main()