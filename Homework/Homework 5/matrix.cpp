#include<iostream>
#include<string>
#include<limits>
#include<vector>
#include<cmath>

int GetIntArgument()
{
	int arg;
	std::cin >> arg;
	return arg;
}

class Matrix
{
	public:
		int numRows;
        int numCols;
        std::vector<std::vector<double>> _matrix;

		Matrix(int r, int c)
		{
            this->numRows = r;
            this->numCols = c;
            _matrix.resize(this->numRows);
            for (int i = 0; i < _matrix.size(); i++)
            {
                _matrix[i].resize(this->numCols, 0);
            }
            //create r x c matrix
		}

		Matrix()
		{
            this->numRows = 0;
            this->numCols = 0;
            _matrix.resize(0);
            _matrix[0].resize(0, 0);
            //create 0x0 matrix
		}

		~Matrix()
        {
			//for (int i = 0; i < this->numRows; i++)
			//{
			//	delete[] & this->_matrix[i];
			//}
            //deallocate the memory which holds matrix elements
            //delete[] data;
        }

        inline Matrix& operator=(Matrix &m)
        {
            delete[] &this->_matrix;
            this->numRows = m.numRows;
            this->numCols = m.numCols;
            Matrix(this->numRows, this->numCols);
            
			this->_matrix = m._matrix;

            return *this;
        }

        inline Matrix operator*(Matrix &n)
        {
            Matrix prodMatrix(this->numRows, n.numCols);

			for (int k = 0; k < this->numRows; k++)
			{
				int l = 0;
				for (int i = 0; i < n.numCols; i++)
				{
					double res = 0;
					for (int j = 0; j < this->numCols; j++)
					{
						res += this->_matrix[k][j] * n._matrix[j][l];
					}
					prodMatrix._matrix[k][i] = res;
					l += 1;
				}
			}
            
            return prodMatrix;
            //multiplies two matrices and returns new matrix
        }

        inline Matrix operator+(Matrix &m)
        {
            Matrix resultMatrix(this->numRows, this->numCols);
            
			for (int i = 0; i < resultMatrix.numRows; i++)
			{
				for (int j = 0; j < resultMatrix.numCols; j++)
				{
					resultMatrix._matrix[i][j] = this->_matrix[i][j] + m._matrix[i][j];
				}
			}
            return resultMatrix;
            //adds two matrices and returns new matrix
        }

        inline double operator[](int &i)
        {
            int cRow, cCol;
            if (i > this->numCols - 1){
                cRow = static_cast<int>(std::floor(i/this->numCols));
            }
            else
            {
                cRow = 0;
            }
			cCol = i - (cRow * this->numCols);
			return operator()(cRow, cCol);
            //return the ith element of the matrix, reading L-R then Top-Bottom
        }

        inline double operator()(int i, int j)
        {
            return this->_matrix[i][j];
            //return the i,jth element of the matrix. i is the row, j is the column
        }

        friend std::ostream& operator<<(std::ostream& stream, Matrix& matrix) {
			for (int i = 0; i < matrix.numCols * matrix.numRows; i++)
			{
				if (((i + 1) % matrix.numCols == 0) && i != matrix.numCols * matrix.numRows) {
					stream << matrix[i] << "\n";
				}
				else {
					stream << matrix[i] << " ";
				}
			}
            return stream;
        }

        friend std::istream& operator>>(std::istream& stream, Matrix& matrix)
        {	
			for (int i = 0; i < matrix.numRows; i++)
			{
				for (int j = 0; j < matrix.numCols; j++)
				{
					matrix._matrix[i][j] = GetIntArgument();
				}
			}
			return stream;
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

void MatrixOperation()
{
	int m1Rows, m1Cols, m2Rows, m2Cols;
    std::string operation = GetStringArgument();
    m1Rows = GetIntArgument();
    m1Cols = GetIntArgument();
    Matrix m1 = Matrix(m1Rows, m1Cols);
	std::cin >> m1;
    
    m2Rows = GetIntArgument();
    m2Cols = GetIntArgument();
    Matrix m2 = Matrix(m2Rows, m2Cols);
	std::cin >> m2;

    if (operation == "multiply") {
		Matrix m3 = m1 * m2;
        std::cout << m3;
    }
    else if (operation == "add") {
		Matrix m4 = m1 + m2;
        std::cout << m4;
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