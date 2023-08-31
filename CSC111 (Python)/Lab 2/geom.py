# Evening Lab 2 Exercise 1 - Mike Kozlowski - CSC111
# geom.py - get info about a circle with given input radius

import math

radius = float(input("Type a value for the radius: "))
diameter = radius * 2
circ = 2 * math.pi * radius
area = math.pi * radius ** 2
volume = (4/3) * math.pi * radius ** 3

print('For given radius', radius, "the following is true:")
print("The diameter is:", diameter)
print("The circumference is:", circ)
print("The area is:", area)
print("The volume is:", volume)
