import string

#Title: Prüfziffer
#Description: Validates Bank Notes
#Author: Bunea
#Last Change: 2020/11/21

alphabet = string.ascii_uppercase
alphabetLowerCase = string.ascii_lowercase 

def countryCodeConverter(bankNoteSerialNum):    #converts the country code to the position in the alphabet
    try:
        countryCode = alphabet.index((bankNoteSerialNum[0]))
    except:
        try:
            countryCode = alphabetLowerCase.index((bankNoteSerialNum[0]))
        except:
            countryCode = 0
            print("Invalid Serial")
            exit(0)
    return countryCode

def validityCheck(serialnumber):    #validates serialnumber
    temp = []

    for i in serialnumber:      #converts serial to a list and calculates the sum
        temp.append(int(i))
    sumSerialNum = sum(temp) - int(temp[-1])
    rest = sumSerialNum % 9
    
    if (8 - rest) == 0 and int(temp[-1]) == 9:  #validates serial
        return True
    if 8 - rest == int(temp[-1]):
        return True
    else:
        return False

#main

bankNoteSerialNum = input("Enter Serialnumber:  ")

if len(bankNoteSerialNum) < 12:    #Serial must be 12 characters long
    print("Invalid Serial")
    exit(0)

countryCode = bankNoteSerialNum[0]
newBankNoteSerialNum = (str(countryCodeConverter(bankNoteSerialNum) + 1) + bankNoteSerialNum.replace(countryCode, ""))
validity = validityCheck(newBankNoteSerialNum)

if validity == True:
    print("Serial '" + bankNoteSerialNum + "' is valid")
elif validity == False:
    print("Serial '" + bankNoteSerialNum + "' is invalid")













