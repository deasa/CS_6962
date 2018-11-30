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

def UpdateGridWithNum(matrix, row, column, num):
    index = GetIndex(row, column)

    if PassesAllSudokuRules(matrix, row, column, num):
        matrix[index] = num

def GetIndex(row, col):
    return int(row) * 9 + int(col)

def PassesRowRule(matrix, row, num):
    startIndex = row * 9
    endIndex = row * 9 + 8

    for i in range(startIndex, endIndex):
        if num == matrix[i]:
            return False
    
    return True

def PassesColumnRule(matrix, column, num):
    for i in range(column, (column + (9 * 8)), 9):
        if num == matrix[i]:
            return False
        
    return True

def PassesSubgridRule(matrix, row, column, num):
    subGridFirstRow = (row - (row % 3)) if row > 0 else 0
    subGridLastRow = (row + (3 - (row % 3))) if row < 8 else 8
    subGridFirstCol = (column - (column % 3)) if column > 0 else 0
    subGridLastCol = (column + (3 - (column % 3))) if column < 8 else 0

    for i in range(subGridFirstRow, subGridLastRow):
        for j in range(subGridFirstCol, subGridLastCol):
            index = GetIndex(i, j)
            if matrix[index] == num:
                return False
    
    return True

def PassesAllSudokuRules(matrix, row, column, num):
    if not PassesRowRule(matrix, row, num):
        print("Number " + str(num) + " twice in row")
        return False
    elif not PassesColumnRule(matrix, column, num):
        print("Number " + str(num) + " twice in column")
        return False
    elif not PassesSubgridRule(matrix, row, column, num):
        print("Number " + str(num) + " twice in subgrid")
        return False

    return True
