# Evening Lab 2 Exercise 3 - Mike Kozlowski - CSC111
# loop.py - print each character and its ord value on a new line

typed = str(input("Type in some characters: "))

for ch in typed:
    print(ch)

name = str(input("Now, type in your name: "))

for ch in name:
    print(ch, ord(ch))
