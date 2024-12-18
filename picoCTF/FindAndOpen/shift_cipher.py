# Function to apply the Caesar cipher shift
def caesar_cipher(text, shift):
    result = []
    
    for char in text:
        # Shift uppercase letters
        if char.isupper():
            result.append(chr((ord(char) - ord('A') + shift) % 26 + ord('A')))
        # Shift lowercase letters
        elif char.islower():
            result.append(chr((ord(char) - ord('a') + shift) % 26 + ord('a')))
        # Non-alphabet characters remain unchanged
        else:
            result.append(char)
    
    return ''.join(result)

# Input text (replace with your string)
input_text = "bababkjaASKBKSBA CVVAVSDDSSSSDSKJ BJS"

# Loop through all possible shifts from 1 to 26
for shift in range(1, 27):
    shifted_text = caesar_cipher(input_text, shift)
    print(f"Shift {shift}: {shifted_text}")