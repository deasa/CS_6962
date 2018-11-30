import sudokuHelper as helper

path = input("Enter input filepath: ")
command = 'y'

while command == 'y':
    matrix = helper.ReadInFile(path)
    helper.Print(matrix)

    row = int(input("Enter row: "))
    col = int(input("Enter column: "))
    num = int(input("Enter number: "))

    helper.UpdateGridWithNum(matrix, row, col, num)
    helper.Print(matrix)
    command = input("Continue? y/n: ")