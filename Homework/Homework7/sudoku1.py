import sudokuHelper as helper

path = input("Enter input filepath: ")
file_object = helper.ReadInFile(path)

helper.Print(file_object)