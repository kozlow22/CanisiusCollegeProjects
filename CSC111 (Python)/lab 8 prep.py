#imports

import sys

#functions

def replaceSpace1(inText):
    if (len(repl) != 1):
        return 'invalid length for replacement'
    outText = ''
    for ch in inText:
        if ch.isspace():
            outText = outText + repl
        else:
            outText = outText + ch
    return outText

def replaceSpace2(inText, repl):
    if (len(repl) != 1):
        return 'invalid length for replacement'
    charList = list(inText)
    for index in range(len(charList)):
        if charList[index].isspace():
            charList[index] = repl
    return ''.join(charList)

#main

text = ''

while True:

    choice = input('type q to quit or c to continue: ')

    if choice == 'q':
        break
    elif choice == 'c':
        print('input text - ctrl d to submit')
        text = sys.stdin.read()
        repl = input('replace chr with whitespace')
    else:
        print("invalid")
