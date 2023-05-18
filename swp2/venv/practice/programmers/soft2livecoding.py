student_tuples = [
    ('john', 'A', 15),
    ('jane', 'B', 12),
    ('dave', 'B', 10),
]
a = sorted(student_tuples, key= lambda x: x[2])
print(student_tuples)
print(a)

a = lambda x,y : x * y
print (a(3,4))

a = [-1, -8, 3, -4, 2, 5, -7]
a.sort( key= lambda x : x*x, reverse=True)
print(a)