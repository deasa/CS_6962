import sys
import PyQt5.QtWidgets as qt
import sudokuHelper as helper

# 3 rows of 3 3x3 grids
# with a row between rows 1 & 2 and 2 & 3

class SudokuGUI(qt.QWidget):
    def __init__(self, matrix):
        super().__init__()
        #init title location, and size of widget
        self.title = 'SUDOKU'
        self.left = 100
        self.top = 100
        self.width = 300
        self.height = 250
        self.matrix = []
        self.initUI(matrix)

    def generateComboBox(self, num):
        combo = qt.QComboBox()
        nums = []
        for i in range(0, 10):
            nums.append(str(i))
        
        combo.addItems(nums)
        combo.setCurrentIndex(num)
        return combo

    def generateGrid(self, matrix):
        grid = qt.QGridLayout()
        
        for i in range(81):
            grid.addWidget(self.generateComboBox(matrix[i]), i//9, i%9)

        return grid

    def initUI(self, matrix):
        self.setWindowTitle = self.title
        self.setGeometry(self.left, self.top, self.width, self.height)
        layout = qt.QFormLayout()
        layout.addRow(self.generateGrid(matrix))#, self.generateGrid(), self.generateGrid())
        
        self.setLayout(layout)
        self.show()
        

if __name__ == '__main__':
    app = qt.QApplication(sys.argv)
    path = input("Enter input filepath: ")
    matrix = helper.ReadInFile(path)
    ex = SudokuGUI(matrix)
    sys.exit(app.exec_())