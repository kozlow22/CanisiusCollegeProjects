# CSC111
# Mike Kozlowski
# Final Exam - Lab
# 12/9/2020

def addProd():

    name = input('First, enter the name of the product: ')
    amt = int(input('Next, enter the amount of the product: '))
    dept = input('Finally, enter the department of the product: ')
    prod[name] = [amt, dept]

    return

def printProd(prod):

    for keys, values in prod.items():
        print(keys, end = ' ')
        print(values[0], end = ' ')
        print(values[1])

def totalProd(prod):

    accum = 0
    for values in prod.values():
        accum = accum + values[0]
    print(accum, 'items on hand')

prod = {}

while True:
    
    print('\n\t1.  addProd')
    print('\t2.  printProd')
    print('\t3.  totalProd')
    print('\t4.  quit')

    choice = int(input('Enter the number for your choice: '))

    if choice == 4:
        break
    elif choice == 1:
        addProd()
    elif choice == 2:
        printProd(prod)
    elif choice == 3:
        totalProd(prod)
    else:
        print("Sorry, not a valid choice.")
