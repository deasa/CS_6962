#include<iostream>
#include<string>
#include<vector>


struct Vec3
{
    double x, y, z;
};


struct Mat3
{
    Vec3 v0, v1, v2;
};

Vec3 read_vec()
{
    //read three doubles from cin, use them to construct a Vec3, then return it
}

Mat3 read_mat()
{
    //read nine doubles from cin, then use it to construct a mat3 and return it (row-major ordering)
}

void print(Vec3 v)
{
    //print the given Vec3 in the format (x, y, z)
}

void print(Mat3 m)
{
    //print the given Mat3 in the format [a,b,c,d,e,f,g,h,i] (row-major ordering)
}

Vec3 add(Vec3 u, Vec3 v)
{
    //add the two and return the resulting Vec3
}

double dot(Vec3 u, Vec3 v)
{
    //return the dot product
}

double length(Vec3 v)
{
    //return the length (or magnitude) of the input vector
}

Mat3 transpose(Mat3 m)
{
    //return the tranpose of m 
}

Vec3 row(Mat3 m, int i)
{
    //return the i-th row of m (index from 0)
}

Vec3 col(Mat3 m, int i)
{
    //return the i-th column of m (index from 0)
}

Vec3 multiply(Mat3 m, Vec3 v)
{
    //multiply a matrix with a vector and return the resulting vec3
}

Mat3 multiply(Mat3 m, Mat3 n)
{
    //multiply a matrix with a matrix in the order given and return the resulting matrix
}

bool IsVectorNext()
{
    // std::cin.peek to see if a vector is coming or if a matrix is coming
}

void MultiplyOperation()
{
    Mat3 m = read_mat();
    Vec3 v;
    Mat3 n;
    bool useVec = false;

    if (IsVectorNext()) {
        v = read_vec();
        useVec = true;
    }
    else
    {
        n = read_mat();
    }
    
    if (useVec) {
        Vec3 resultV = multiply(m, v);
        print(resultV);
    }
    else {
        Mat3 resultM = multiply(m, n);
        print(resultM);
    }
    
}

void ColOperation() 
{
    Mat3 m = read_mat();
    int i = read_int();
    Vec3 v = col(m, i);
    print(v);
}

void RowOperation() 
{
    Mat3 m = read_mat();
    int i = read_int();
    Vec3 v = row(m, i);
    print(v);
}

void TransposeOperation()
{
    Mat3 m = read_mat();
    Mat3 mtranspose = transpose(m);
    print(m);
}

void DotOperation()
{
    Vec3 a = read_vec();
    Vec3 b = read_vec();
    Vec3 c = dot(a, b);
    print(c);
}

void LengthOperation()
{
    Vec3 v = read_vec();
    double len = length(v);
    std::cout << len;
}

void AddOperation()
{
    Vec3 a = read_vec();
    Vec3 b = read_vec();
    Vec3 c = add(a, b);
    print(c);
}

void MatrixVectorOperation()
{
    std::string operation = GetOperationString();
    
    if (operation == "add") {
        AddOperation();
    }
    else if (operation == "length") {
        LengthOperation();
    }
    else if (operation == "dot") {
        DotOperation();
    }
    else if (operation == "transpose") {
        TransposeOperation();
    }
    else if (operation == "multiply") {
        MultiplyOperation();
    }
    else if (operation == "row") {
        RowOperation();
    }
    else if (operation == "col") {
        ColOperation();
    }
}

std::string GetOperationString()
{
    std::string str;
    std::cin >> str;
    return str;
}

int read_int()
{
    int arg;
    std::cin >> arg;
    return arg;
}

int GetNumCases()
{
	int response = 0;
	std::cin >> response;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return response;
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
		MatrixVectorOperation();
	}
}
