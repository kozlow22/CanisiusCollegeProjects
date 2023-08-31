# Mike Kozlowski
# Lab 8 - CSC111

#imports

import sys

#functions

def printMenu():
    
    print('\t1.  Type in your text for analysis.')
    print('\t2.  Change punctuation')
    print('\t3.  Replace a character with a different character')
    print('\t4.  Output number of occurences of a character')
    print('\t5.  Output the total number of characters')
    print('\t6.  Output the total number of words')
    print('\t7.  Squish blanks')
    print('\t8.  Quit')

    choice = int(input('Enter the number for your choice: '))

    return choice

def getText():

    inText = ''
    print("Type in your text for analysis in as many lines as desired, ctrl-d to submit: ")
    inText = sys.stdin.read()

    return inText

def changePunc(text):
    outText = ''
    for ch in text:
        if ch == ';':
            outText = outText + ','
        elif ch == '!':
            outText = outText + '.'
        else:
            outText = outText + ch
    return outText

def replace(text):
    base = input('What character would you like replaced? ')
    repl = input('What character would you like it to be replaced with? ')
    outText = ''
    for ch in text:
        if ch == base:
            outText = outText + repl
        else:
            outText = outText + ch
    return outText

def numChar(text):
    count = 0
    inText = input('What character would you like a count of? ')
    for ch in text:
        if ch == inText:
            count = count + 1
        else:
            count = count
    return count

def totalChar(text):
    count = 0
    for ch in text:
        if ch.isspace():
            count = count
        else:
            count = count + 1
    return count

def totalWords(text):
    count = 1
    for ch in text:
        if ch.isspace():
            count = count + 1
    return count

def squishBlanks(text):
    convert = ''
    for ch in text:
        if ch.isspace():
            convert = convert
        else:
            convert = convert + ch
    return convert


#main

text = ''

while True:

    choice = printMenu()

    if choice == 8:
        break    
    elif choice == 1:
        text = getText()
    elif choice == 2:
        text2 = changePunc(text)
        print()
        print(text2)
    elif choice == 3:
        text3 = replace(text)
        print()
        print(text3)
    elif choice == 4:
        text4 = numChar(text)
        print()
        print(text4)
    elif choice == 5:
        text5 = totalChar(text)
        print()
        print(text5)
    elif choice == 6:
        text6 = totalWords(text)
        print()
        print(text6)
    elif choice == 7:
        text7 = squishBlanks(text)
        print()
        print(text7)
    else:
        print("Sorry, not a valid choice.")
