numCases = int(input())

def PrintCaseStatement(i):
    print('Case ' + str(i) + ":")

def FindMinMax():
    results = input().split()
    nums = [int(i) for i in results]
    minimum = nums[0]
    maximum = nums[0]
    for n in nums:
        if n > maximum:
            maximum = n
        elif n < minimum:
            minimum = n
    print('Min: ' + str(minimum))
    print('Max: ' + str(maximum))

for i in range(0, numCases):
    PrintCaseStatement(i)
    FindMinMax()