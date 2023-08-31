# Caesar Cipher - Lab 9
# Mike Kozlowski
# Due 11/11/20

def shiftLetter(letter,shift): 
        shiftedLetter = chr(((ord(letter)-65) + shift)% 26+65)
        return shiftedLetter

def encode(msg, shift):
    ciphertext = ''
    for letter in msg:
        if letter != ' ':
            shiftedLetter = shiftLetter(letter, shift)
            ciphertext += shiftedLetter
        else:
            ciphertext += ' '
    return ciphertext

def decode(cipher, shift):
    deciphertext = ''
    reverseShift = shift * -1
    for letter in cipher:
        if letter != ' ':
            shiftedLetter = shiftLetter(letter, reverseShift)
            deciphertext += shiftedLetter
        else:
            deciphertext += ' '
    return deciphertext

def menu():
    print('\n\t1.  Encode a message.')
    print('\t2.  Decode a message.')
    print('\t3.  Quit.')
    
# main

cipher = ''
message = ''
while True:
    menu()
    choice = int(input())
    print()
    
    if choice == 3:
        break
    
    elif choice == 1:
        message = input("Insert the message (all caps + spaces) you wish to encode: ")
        shift = int(input("Insert an integer to shift your message by (positive or negative): "))
        print("The encoded message is: ", encode(message, shift))

    elif choice == 2:
        cipher = input("Insert the message (all caps + spaces) you wish to decode: ")
        shift = int(input("Insert the integer used to decode your message: "))
        print("The decoded message is: ", decode(cipher, shift))

    else:
        print('You have inserted an invalid choice. Try again.')
