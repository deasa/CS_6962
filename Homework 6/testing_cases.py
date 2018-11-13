numCases = int(input())

def PrintCaseStatement(i):
    print('Case: ' + str(i))

def Echo():
    print("Echo: " + input())

for i in range(0, numCases):
    PrintCaseStatement(i)
    Echo()