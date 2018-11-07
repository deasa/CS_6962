
# double GetLeibnizTerm(int nthTerm){
#    int signOfTerm;
#    if (nthTerm % 2 == 0) {signOfTerm = 1;}
#    else {signOfTerm = -1;}
#    double denom = 2 * nthTerm + 1;
#    return 1 * signOfTerm / denom;
# }

# void EstimatePi()
# {
# 	int n = GetParameter();
#    double piDiv4 = 0;
#    for(int i = 0; i < n; i++){
#        double termArg = GetLeibnizTerm(i);
#        piDiv4 = piDiv4 + termArg;
#    }
#    double pi = piDiv4 * 4;
#    std::cout << "Pi estimated as: " << std::fixed << std::setprecision(8) << pi << "\n";
# }

def GetLeibnizTerm(nthTerm):
    signOfTerm = False
    if nthTerm % 2 == 0:
        signOfTerm = True
    else:
        signOfTerm = False
    denom = 2 * nthTerm + 1
    return 1 if signOfTerm else -1 / denom

n = int(input())
piDiv4 = 0

for i in range(0, n):
    termArg = GetLeibnizTerm(i)
    piDiv4 += termArg

pi = piDiv4 * 4

print(f'Pi estimated as: {pi}')