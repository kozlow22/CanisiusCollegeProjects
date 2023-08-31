# Functions - Lab 7
# Mike Kozlowski
# Due 10/27/20 (Late)


#functions

def letterStart(word):
    
    check = word.isdigit()
    retLet = ''
    num = ord(word[0])

    if word.isdigit() == True:
        return
    elif num < 65:
        return
    elif num > 122:
        return
    else:
        if num < 97:
            retLet = retLet + word[0] + chr(num + 32)
            return retLet
        else:
            retLet = retLet + word[0] + chr(num - 32)
            return retLet

def smallest(aList):

#If you send a blank list, it will return an error stating
#the list index is out of range.

    retSmallest = aList[0]
    count = 0
    for i in aList:
        if retSmallest < aList[count]:
            retSmallest = aList[count]
            count = count + 1
    return retSmallest

def smaller(num1, num2):

    if num1 < num2:
        return num1
    else:
        return num2

def numbers(myString):

    num = ''
    retList = []
    
    for i in myString:
        if i.isdigit() == True:
            num = num + i
        elif num == '':
            num = num
        else:
            retList.append(num)
            num = ''
    return retList

def uppercase(myString):

    retString = ''

    for i in myString:
        if ord(i) < 65:
            retString = retString + i
        elif ord(i) > 122:
            retString = retString + i
        elif ord(i) > 96:
            retString = retString + chr(ord(i) - 32)
        else:
            retString = retString + i
    return retString

#main

upperTest = "This is ok, right?"
numTest = "I have 18 cats and 742 friends, one is named B3n."
smallTest1 = 100
smallTest2 = 4
smallTest3 = 0
smallTest4 = 15
smallestTest1 = [9, 2, 0, 3]
smallestTest2 = [100]
smallestTest3 = [5, 5, 5]
letterTest1 = "823"
letterTest2 = "This"
letterTest3 = "and"

print("Here is the test of the functions:")
print("letterStart function:")
print("Input: ", letterTest1)
print("Output: ", letterStart(letterTest1))
print("Input: ", letterTest2)
print("Output: ", letterStart(letterTest2))
print("Input: ", letterTest3)
print("Output: ", letterStart(letterTest3))
print()
print("smallest function:")
print("Input: ", smallestTest1)
print("Output: ", smallest(smallestTest1))
print("Input: ", smallestTest2)
print("Output: ", smallest(smallestTest2))
print("Input: ", smallestTest3)
print("Output: ", smallest(smallestTest3))
print()
print("smaller function:")
print("Input:", smallTest1, "and", smallTest2)
print("Output:", smaller(smallTest1, smallTest2))
print("Input:", smallTest3, "and", smallTest4)
print("Output:", smaller(smallTest3, smallTest4))
print()
print("numbers function:")
print("Input: ", numTest)
print("Output: ", numbers(numTest))
print()
print("uppercase function:")
print("Input: ", upperTest)
print("Output: ", uppercase(upperTest))
