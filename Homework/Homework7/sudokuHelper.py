def ReadInFile(strpath):
    file_object = open(strpath, "r")
    l = []
    for line in file_object:
        for c in line:
            if c.isdigit():
                l.append(int(c))
    return l

def Print(matrix):
    i = 1
    for v in matrix:
        print(v, end=" ")
        if i % 9 == 0:
            print("\n")
        i += 1

def Check():
    # do something
    print("Hello")
