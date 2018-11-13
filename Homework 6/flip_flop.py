numCases = int(input())

def PrintCaseStatement(i):
    print('Case ' + str(i) + ":")

def FlipFlop():
    results = input().split()
    nums = [int(i) for i in results]
    start = nums[0]
    stop = nums[1]
    a = nums[-2]
    b = nums[-1]
    for i in range(start, stop):
        if i % a == 0:
            if i % b == 0:
                print('flipflop')
            else:
                print('flip')
        elif i % b == 0:
            print('flop')
        else:
            print(i)

for i in range(0, numCases):
    PrintCaseStatement(i)
    FlipFlop()