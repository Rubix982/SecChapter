import base64

# Input string
input_string = "bababkjaASKBKSBA CVVAVSDDSSSSDSKJ BJS"

# Base64 Encoding
encoded_string = base64.encode(input_string.encode('utf-8'))
print(f"Encoded (Base64): {encoded_string.decode()}")

# Base64 Decoding
decoded_string = base64.decode(encoded_string).decode('utf-8')
print(f"Decoded (Base64): {decoded_string}")
