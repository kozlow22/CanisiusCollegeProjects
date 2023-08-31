# Mike Kozlowski
# Base Conversion - binToDec.py
# 9/23

bin = str(input("Please type in a binary number to convert to decimal: "))
decVal = 0
maxVal = 2 ** (len(bin) - 1)

for digit in bin:    
    posVal = int(digit) * maxVal
    decVal = decVal + posVal
    maxVal = maxVal // 2

print("Your binary value of", bin, "converted into decimal is:", decVal)
