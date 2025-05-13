#Title: Notenberechnung
#Description: Calculates a grade in a questionable manner
#Author: Bunea
#Last Change: 2020/10/11

try:
    grade = float(input("Input Grade (1 - 5): "))
    eyeColor = int(input("Input eye color (1-Dark | 0-Light): "))
    hairLen = int(input("Input hair lenght (1-short | 0-long): "))
    weather = int(input("Input weather (1-good weather | 0-bad weather): "))
except:
    print("")
    print("Something went wrong!")
    print("")

    grade = 0
    eyeColor = 0
    hairLen = 0
    weather = 0

finalGrade = 0

if hairLen == 1 and eyeColor == 1:
    finalGrade = grade + 10/100 * grade
elif hairLen == 0 and eyeColor == 1:
    finalGrade = grade - 10/100 * grade
elif eyeColor == 0 and hairLen == 1:
    finalGrade = grade - 10/100 * grade
elif  eyeColor == 0 and hairLen == 0:
    finalGrade = grade + 10/100 * grade

if weather == 1:
    finalGrade -= 10/100* grade

print("Your final grade is: " + str( round( finalGrade*2) / 2))
print("Exact grade: " + str(finalGrade))  

if finalGrade > 5 or finalGrade < 1:
    print("You may have inserted invalid grades and have gotten weird results.")