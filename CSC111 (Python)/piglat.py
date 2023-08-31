# Piglat - Lab 6
# Mike Kozlowski
# Due 10/21 (Late)

import random

pigWord = ''
endings = ['yay', 'way']
sentence = input("Input a sentence to be translated into pig latin:\n")
splitWords = sentence.split()
finalSentence = ''


for word in splitWords:
    
    index = 0
    
    while index < len(word) and word[index] not in 'AEIOUaeiou':
        index = index + 1
        
    if index == 0:
        pigWord = word[1:] + word[:1] + random.choice(endings)
        finalSentence = finalSentence + pigWord + " "
         
    else:
        pigWord = word[index:] + word[:index] + "ay"
        finalSentence = finalSentence + pigWord + " "

print()
print("The sentence:")
print(sentence)
print("in pig latin translates to:")
print(finalSentence)
