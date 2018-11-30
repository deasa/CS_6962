import sudokuHelper as helper

path = input("Enter input filepath: ")
matrix = helper.ReadInFile(path)

helper.Print(matrix)