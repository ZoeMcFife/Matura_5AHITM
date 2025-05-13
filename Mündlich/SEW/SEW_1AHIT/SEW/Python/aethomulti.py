#Title: Äthiopisches Multiplizieren
#Description: Äthiopisches Multiplizieren
#Author: Bunea
#Last Change: 2020/10/11

num1 = int(input("Enter a number: "))
num2 = int(input("Enter another number: "))

product = []

print("")

while num1 >= 1:
    if num1 % 2 != 0 or num1 == 1:
        product.append(num2)
        print(num1, num2)
    else:
        print(str(num1) + " " + "-" + str(num2) + "-")

    num1 = num1 // 2
    num2 = num2 * 2

print("")

print(sum(product))
        

