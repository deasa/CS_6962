import sudokuHelper as helper

path = input("Enter input filepath: ")
matrix = helper.ReadInFile(path)
helper.Print(matrix)

row = int(input("Enter row: "))
col = int(input("Enter column: "))
num = int(input("Enter number: "))

helper.UpdateGridWithNum(matrix, row, col, num)
helper.Print(matrix)