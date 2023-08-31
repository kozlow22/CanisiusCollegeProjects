# Mike Kozlowski
# Base Conversion - binToDec.py
# 9/23

userInput = -1
inputSum = 0
while userInput < 0:
    userInput = int(input("Input numbers to get a sum, input positive number to end: "))
    if userInput < 0:
        inputSum = userInput + inputSum
if inputSum == 0:
    print("You ended the input without typing in any negative numbers.")
else:
    print(inputSum)

