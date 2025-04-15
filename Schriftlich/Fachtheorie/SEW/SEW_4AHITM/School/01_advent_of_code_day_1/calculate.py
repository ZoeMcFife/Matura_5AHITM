def calculate_number(str):
    numArray = []

    print(str)
    str = find_numbers(str)
    print(str)

    for c in str:
        if c.isnumeric():
            numArray.append(int(c))
    
    print(numArray)

    if numArray.count == 1:
        return numArray[0] * 10 + numArray[0]

    return numArray[0] * 10 + numArray[-1]

def find_numbers(str):
    str = str.replace("zero", "0")
    str = str.replace("one", "1")
    str = str.replace("two", "2")
    str = str.replace("three", "3")
    str = str.replace("four", "4")
    str = str.replace("five", "5")
    str = str.replace("six", "6")
    str = str.replace("seven", "7")
    str = str.replace("eight", "8")
    str = str.replace("nine", "9")

    return str

file = open("data.txt", "r")
arr = []
sum = 0
test = 0

for i in file.readlines():
    arr.append(i)

#print(arr)

for str in arr:
    temp = calculate_number(str)

    print(temp)

    sum = sum + temp
    print(sum)


print(sum)