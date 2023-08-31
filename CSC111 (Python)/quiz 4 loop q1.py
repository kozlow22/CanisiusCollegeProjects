smallest = 0
x = 200
y = 4000
z = 3

if x < y:

    if x < z:
        smallest = x

    elif z < y:
        smallest = z

    else:
        smallest = y

elif y < z:
    smallest = y
    
else:
    smallest = z

print(smallest)

