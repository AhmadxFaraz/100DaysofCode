import art
print(art.logo)
alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

def caesar(direction, text, shift ):
    def encrypt(original_text, shift_amount):
        cipher_text = ""
        for letter in original_text:
            shifted_position = alphabet.index(letter) + shift_amount
            shifted_position %= len(alphabet)
            cipher_text += alphabet[shifted_position]
        print(f"Here is the encoded result: {cipher_text}\n")

    def decrypt(original_text, shift_amount):
        decipher_text = ""
        for letter in original_text:
            shifted_position = alphabet.index(letter) - shift_amount
            if shifted_position < 0:
                shifted_position += len(alphabet)
            decipher_text += alphabet[shifted_position]
        print(f"Here is the decoded result: {decipher_text}\n")
    if direction == 'encode':
        encrypt(text, shift)
    elif direction == 'decode':
        decrypt(text, shift)


ans = "yes"

while ans == "yes":
    Direction = input("Type 'encode' to encrypt, type 'decode' to decrypt:\n").lower()
    Text = input("Type your message:\n").lower()
    Shift = int(input("Type the shift number:\n"))
    caesar(direction = Direction, shift = Shift, text = Text)
    ans = input("Type 'yes' if you want to go again. Otherwise type 'no'.\n")

print("Thank you for using Caesar Cipher")
