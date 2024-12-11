input='mystery'
output='analyze.txt'

def ascii_to_hex(file_path, output_path):
    try:
        with open(file_path, 'r') as infile:
            ascii_content = infile.read()
        
        # Convert ASCII content to hexadecimal
        hex_content = ascii_content.encode('utf-8').hex()

        with open(output_path, 'w') as outfile:
            outfile.write(hex_content)
        
        print(f"Hexadecimal output saved to: {output_path}")
    except Exception as e:
        print(f"An error occurred: {e}")

with open(input,'rb') as f:
    hex_data=f.read()

file_hex=hex_data.hex()
reversed_hex = ""

for i in range(0, len(file_hex), 8):
    reversed_hex += file_hex[i:i+8][::-1]

with open(output,'w') as f:
    f.write(reversed_hex)
    
ascii_to_hex('analyze.txt', 'output.jpg')

