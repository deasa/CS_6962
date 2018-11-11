numCases = int(input())

def PrintCaseStatement(i):
    print('Case: ' + str(i))

def GetLeibnizTerm(n):
    num = 1
    sign = (n % 2 == 0)
    denom = 2 * n + 1
    term = num / denom
    if sign:
        return term
    else:
        return 0 - term

def EstimatePi():
    nTerms = int(input())
    estimate = 0
    for i in range(0, nTerms):
        estimate += GetLeibnizTerm(i)
    
    estimate *= 4
    print('Pi estimated as: ' + '{:.8f}'.format(estimate))

for i in range(0, numCases):
    PrintCaseStatement(i)
    EstimatePi()