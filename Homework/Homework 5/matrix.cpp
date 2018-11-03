#include<iostream>
#include<string>
#include<limits>
#include<vector>
#include<cmath>

class Matrix
{
	private:
        unsigned int numRows;
        unsigned int numCols;
        std::vector<std::vector<double>> _matrix;

	public:
		Matrix(int r, int c)
		{
            numRows = r;
            numCols = c;
            _matrix.resize(numRows);
            for (int i = 0; i < _matrix.size(); i++)
            {
                _matrix[i].resize(numCols, 0);
            }
            //create r x c matrix
		}

		Matrix()
		{
            numRows = 0;
            numCols = 0;
            _matrix.resize(0);
            _matrix[0].resize(0, 0);
            //create 0x0 matrix
		}

		~Matrix()
        {
            //deallocate the memory which holds matrix elements
            //delete[] data;
        }

        Matrix& operator=(const Matrix &m)
        {
            //delete data
            //set new size equal to m's sizes
            //initialize new matrix
            //loop and copy data elements
            return *this;
        }

        Matrix operator*(const Matrix &n)
        {
            Matrix prodMatrix(numRows, numCols);
            std::vector<double> mRow, nCol;
            
            for(int i = 0; i < this->numCols; i++)
            {
                for(int j = 0; j < numCols; j++)
                {
                    mRow[j] = _matrix[j][i];
                }
                nCol = n._matrix[i];
                for(int k = 0; k < numCols; k++)
                {
                    prodMatrix._matrix[i][k] = mRow[k] * nCol[k];
                }
            }
            
            return prodMatrix;
            //multiplies two matrices and returns new matrix
        }

        Matrix operator+(const Matrix &m)
        {
            Matrix resultMatrix(numRows, numCols);
            
            for(int i = 0; i < numRows; i++)
            {
                
                for(int j = 0; j < numCols; j++)
                {
                    resultMatrix._matrix(i, j) = this->_matrix[i][j] + m._matrix(i,j);
                }
            }
            return resultMatrix;
            //adds two matrices and returns new matrix
        }

        double operator[](int &i)
        {
            int cRow, cCol, index;
            if (i > numCols){
                cRow = std::floor(i/numCols);
            }
            else
            {
                cRow = 1;
            }
            cCol = i % numCols;
            return this->_matrix(cRow, cCol);
            //return the ith element of the matrix, reading L-R then Top-Bottom
        }

        double operator()(int &i, int &j)
        {
            return _matrix[i][j];
            //return the i,jth element of the matrix. i is the row, j is the column
        }

        std::ostream& operator<<(std::ostream& stream, const Matrix& matrix) {
            for(int i = 0; i < numCols; i++)
            {
                for(int j = 0; j < numRows; j++)
                {
                    stream << _matrix(i, j);
                }
            }
            return stream;
        }

        void operator>>()
        {
            //reads a matrix
        }
};

int GetNumCases()
{
	int response = 0;
	std::cin >> response;
	return response;
}

std::string GetStringArgument()
{
    std::string arg;
    std::cin >> arg;
    return arg;
}

int GetIntArgument()
{
    int arg;
    std::cin >> arg;
    return arg;
}

void MatrixOperation()
{
    std::string operation = GetStringArgument();
    m1Rows = GetIntArgument();
    m1Cols = GetIntArgument();
    Matrix m1 = Matrix(m1Rows, m1Cols);
    
    for(int i = 0; i < m1Cols; i++)
    {
        for(int j = 0; j < m1Rows; j++)
        {
            m1(i, j) = GetIntArgument();
        }   
    }
    
    m2Rows = GetIntArgument();
    m2Cols = GetIntArgument();
    Matrix m2 = Matrix(m2Rows, m2Cols);

    for(int i = 0; i < m2Cols; i++)
    {
        for(int j = 0; j < m2Rows; j++)
        {
            m2(i, j) = GetIntArgument();
        }   
    }
    
    if (operation == "multiply") {
        std::cout << m1 * m2;
    }
    else if (operation = "add") {
        std::cout << m1 + m2;
    }
}

void PrintCaseStatement(int i)
{
	std::cout << "Case " << i << ":\n";
}

int main()
{
	int numCases = GetNumCases();
	for(int i = 0; i < numCases; i++)
	{
		PrintCaseStatement(i);
        MatrixOperation();
	}
}