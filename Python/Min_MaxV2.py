def min_max(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z):
    
    min_value = min(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z)
    max_value = max(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z)
    
    return min_value, max_value


a = 4
b = 2
c = 3
d = 6
e = 7
f = 1
g = 2
h = 16
i = 22
j = 1
k = 2.9
l = 4
m = 15.6
n = 21
o = 2.8
p = 0.8
q = 3
r = 7
s = 5
t = 17
u = 11
v = 12
w = 11
x = 5
y = 3
z = 8

minimum, maximum = min_max(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z)


print("Minimum Is:", minimum)
print("Maximum Is:", maximum)
