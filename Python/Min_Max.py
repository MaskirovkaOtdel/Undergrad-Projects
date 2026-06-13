def min_max(x, y, z):
    
    if x >= y and x >= z:
        max_value = x
    elif y >= x and y >= z:
        max_value = y
    else:
        max_value = z

    
    if x <= y and x <= z:
        min_value = x
    elif y <= x and y <= z:
        min_value = y
    else:
        min_value = z

    return min_value, max_value


x = 5
y = 3
z = 8
minimum, maximum = min_max(x, y, z)
print("Minimum Is:", minimum)
print("Maximum Is:", maximum)
