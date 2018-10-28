//#include<iostream>
//#include<string>
//#include<vector>
//#include<cmath>
//
//struct Vec3
//{
//    double x, y, z;
//};
//
//
//struct Mat3
//{
//    Vec3 v0, v1, v2;
//};
//
//int read_int()
//{
//    int arg;
//    std::cin >> arg;
//    return arg;
//}
//
//void read_idChar()
//{
//    std::string idChar;
//    std::cin >> idChar;
//}
//
//Vec3 read_vec()
//{
//    read_idChar();
//    Vec3 v;
//    std::cin >> v.x >> v.y >> v.z;
//    return v;
//    //read three doubles from cin, use them to construct a Vec3, then return it
//}
//
//Mat3 read_mat()
//{
//    read_idChar();
//    Mat3 m;
//    Vec3 a, b, c;
//    std::cin >> a.x >> a.y >> a.z >> b.x >> b.y >> b.z >> c.x >> c.y >> c.z;
//    m.v0 = a;
//    m.v1 = b;
//    m.v2 = c;
//    return m;
//    //read nine doubles from cin, then use it to construct a mat3 and return it (row-major ordering)
//}
//
//void print(Vec3 v)
//{
//    std::cout << "( " << v.x << ", " << v.y << ", " << v.z << " )" << "\n";
//    //print the given Vec3 in the format ( x, y, z )
//}
//
//void print(Mat3 m)
//{
//    std::cout << "[ " << m.v0.x << ", " << m.v0.y << ", " << m.v0.z
//     << ", " << m.v1.x << ", " << m.v1.y << ", " << m.v1.z
//      << ", " << m.v2.x << ", " << m.v2.y << ", " << m.v2.z << " ]" << "\n";
//    //print the given Mat3 in the format [ a, b, c, d, e, f, g, h, i ] (row-major ordering)
//}
//
//Vec3 add(Vec3 u, Vec3 v)
//{
//    Vec3 res;
//    res.x = u.x + v.x;
//    res.y = u.y + v.y;
//    res.z = u.z + v.z;
//    return res;
//    //add the two and return the resulting Vec3
//}
//
//double dot(Vec3 u, Vec3 v)
//{
//    double res;
//    res = u.x * v.x;
//    res = res + (u.y * v.y);
//    res = res + (u.z * v.z);
//    return res;
//    //return the dot product
//}
//
//double length(Vec3 v)
//{
//    double sumSquares;
//    sumSquares = pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2);
//    double res = sqrt(sumSquares);
//    return res;
//    //return the length (or magnitude) of the input vector
//}
//
//Mat3 transpose(Mat3 m)
//{
//    Mat3 mtrans;
//    mtrans.v0.x = m.v0.x;
//    mtrans.v0.y = m.v1.x;
//    mtrans.v0.z = m.v2.x;
//    mtrans.v1.x = m.v0.y;
//    mtrans.v1.y = m.v1.y;
//    mtrans.v1.z = m.v2.y;
//    mtrans.v2.x = m.v0.z;
//    mtrans.v2.y = m.v1.z;
//    mtrans.v2.z = m.v2.z;
//    return mtrans;
//    //return the transpose of m 
//}
//
//Vec3 row(Mat3 m, int i)
//{
//    std::vector<Vec3> victor = {m.v0, m.v1, m.v2};
//    return victor[i];
//    //return the i-th row of m (index from 0)
//}
//
//Vec3 col(Mat3 m, int i)
//{
//	Vec3 c = { 0,0,0 };
//    if (i == 0) {
//        c.x = m.v0.x;
//        c.y = m.v1.x;
//        c.z = m.v2.x;
//    }
//    if (i == 1) {
//        c.x = m.v0.y;
//        c.y = m.v1.y;
//        c.z = m.v2.y;
//    }
//    if (i == 2) {
//        c.x = m.v0.z;
//        c.y = m.v1.z;
//        c.z = m.v2.z;
//    }
//    return c;
//    //return the i-th column of m (index from 0)
//}
//
//Vec3 multiply(Mat3 m, Vec3 v)
//{
//    Vec3 res;
//    res.x = v.x * m.v0.x + v.y * m.v0.y + v.z * m.v0.z;
//    res.y = v.x * m.v1.x + v.y * m.v1.y + v.z * m.v1.z;
//    res.z = v.x * m.v2.x + v.y * m.v2.y + v.z * m.v2.z;
//    return res;
//    //multiply a matrix with a vector and return the resulting vec3
//}
//
//Mat3 multiply(Mat3 m, Mat3 n)
//{
//    Mat3 res;
//    res.v0 = Vec3{ dot(m.v0, col(n, 0)), dot(m.v0, col(n, 1)), dot(m.v0, col(n, 2)) };
//    res.v1 = Vec3{ dot(m.v1, col(n, 0)), dot(m.v1, col(n, 1)), dot(m.v1, col(n, 2)) };
//    res.v2 = Vec3{ dot(m.v2, col(n, 0)), dot(m.v2, col(n, 1)), dot(m.v2, col(n, 2)) };
//    return res;
//    //multiply a matrix with a matrix in the order given and return the resulting matrix
//}
//
//bool IsVectorNext()
//{
//	std::cin.get(); // for the newline character
//	auto pk = std::cin.peek();
//	return pk == 'V';
//    // std::cin.peek to see if a vector is coming or if a matrix is coming
//}
//
//void MultiplyOperation()
//{
//    Mat3 m = read_mat();
//	Vec3 v = { 0,0,0 };
//    Mat3 n = { 0,0,0 };
//    bool useVec = false;
//
//    if (IsVectorNext()) {
//        v = read_vec();
//        useVec = true;
//    }
//    else
//    {
//        n = read_mat();
//    }
//    
//    if (useVec) {
//        Vec3 resultV = multiply(m, v);
//        print(resultV);
//    }
//    else {
//        Mat3 resultM = multiply(m, n);
//        print(resultM);
//    }
//    
//}
//
//void ColOperation() 
//{
//    Mat3 m = read_mat();
//    int i = read_int();
//    Vec3 v = col(m, i);
//    print(v);
//}
//
//void RowOperation() 
//{
//    Mat3 m = read_mat();
//    int i = read_int();
//    Vec3 v = row(m, i);
//    print(v);
//}
//
//void TransposeOperation()
//{
//    Mat3 m = read_mat();
//    Mat3 mtranspose = transpose(m);
//    print(mtranspose);
//}
//
//void DotOperation()
//{
//    Vec3 a = read_vec();
//    Vec3 b = read_vec();
//    double c = dot(a, b);
//    std::cout << c << "\n";
//}
//
//void LengthOperation()
//{
//    Vec3 v = read_vec();
//    double len = length(v);
//    std::cout << len << "\n";
//}
//
//void AddOperation()
//{
//    Vec3 a = read_vec();
//    Vec3 b = read_vec();
//    Vec3 c = add(a, b);
//    print(c);
//}
//
//std::string GetOperationString()
//{
//    std::string str;
//    std::cin >> str;
//    return str;
//}
//
//void MatrixVectorOperation()
//{
//    std::string operation = GetOperationString();
//    
//    if (operation == "add") {
//        AddOperation();
//    }
//    else if (operation == "length") {
//        LengthOperation();
//    }
//    else if (operation == "dot") {
//        DotOperation();
//    }
//    else if (operation == "transpose") {
//        TransposeOperation();
//    }
//    else if (operation == "multiply") {
//        MultiplyOperation();
//    }
//    else if (operation == "row") {
//        RowOperation();
//    }
//    else if (operation == "col") {
//        ColOperation();
//    }
//}
//
//int GetNumCases()
//{
//	int response = 0;
//	std::cin >> response;
//	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	return response;
//}
//
//void PrintCaseStatement(int i)
//{
//	std::cout << "Case " << i << ":\n";
//}
//
//int main()
//{
//	int numCases = GetNumCases();
//	for(int i = 0; i < numCases; i++)
//	{
//		PrintCaseStatement(i);
//		MatrixVectorOperation();
//	}
//}
