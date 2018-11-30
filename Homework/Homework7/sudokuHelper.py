def ReadInFile(strpath):
    return open(strpath, "r")

def Print(file_object):
    for line in file_object:
        print(line)

def Check():
    # do something
    print("Hello")
