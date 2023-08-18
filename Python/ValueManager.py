# Mini-application made for colleague

############ Data ##############

class clr:
    ERR = "\u001b[31m"
    END = "\x1b[37m"
    FIN = "\x1b[32m"
    INF = "\x1b[33m"

labels = 0

############ Methods ##############

def saveFile(data, name):
    with open('Results/' + name + '.txt', 'w') as file:
        for value in data:
            file.write(value + '\n')
        print(clr.FIN + 'Values saved in '+ name + '.txt\n\n' + clr.END)  

def findIncorrectValues(): 
    totalMatches = 0
    for value in reversed(range(len(RecordedNumbers))):
        if (RecordedNumbers[value] in OfficialNumbers):
            RecordedNumbers.pop(value)
            totalMatches += 1
            continue
        if (len(RecordedNumbers[value]) < 4 or len(RecordedNumbers[value]) == 5): 
            RecordedNumbers.pop(value)

    IncorrectNumbers = RecordedNumbers

    print(clr.END + str(len(RecordedNumbers) - labels) + clr.INF + ' incorrect numbers' + clr.FIN + ' found.' + clr.END)
    print(clr.FIN + 'Total of ' + clr.END + str(totalMatches) + clr.FIN + ' numbers removed.')
    saveFile(IncorrectNumbers, 'IncorrectNumbers')
  

def findMissingValues():
    totalMatches = 0
    RecordedNumbers = RecordedList.split('\n')
    OfficialNumbers = OfficialList.split('\n')

    for value in reversed(range(len(OfficialNumbers))):
        if ('-' in OfficialNumbers[value]): continue
        if (OfficialNumbers[value] in RecordedNumbers):
            OfficialNumbers.pop(value)
            totalMatches += 1
            continue
        if (len(OfficialNumbers[value]) < 4 or len(OfficialNumbers[value]) == 5): 
                OfficialNumbers.pop(value)

    MissingNumbers = OfficialNumbers

    print(clr.END + '\n' + str(len(MissingNumbers)) + clr.INF + ' missing numbers' + clr.FIN + ' found.' + clr.END)
    print(clr.FIN + 'Total of ' + clr.END + str(totalMatches) + clr.FIN + ' numbers removed.')
    saveFile(MissingNumbers, 'MissingNumbers')

def findDuplicateValues():
    RecordedNumbers = RecordedList.split('\n')
    for value in reversed(range(len(RecordedNumbers))):
        if (len(RecordedNumbers[value]) < 4 or len(RecordedNumbers[value]) == 5): 
            RecordedNumbers.pop(value)

    DuplicateNumbers = set([x for x in RecordedNumbers if RecordedNumbers.count(x) > 1])

    print(clr.END + '\n' + str(len(DuplicateNumbers))  + clr.INF + ' duplicates' + clr.FIN + ' found.' + clr.END)
    print(clr.FIN + "Total of " + clr.END + str(len(RecordedNumbers) - len(DuplicateNumbers)) + clr.FIN + ' numbers removed.' + clr.END)
    saveFile(DuplicateNumbers, 'DuplicateNumbers')


############ Main ##############

# Grab user input

OfficialNumbersFile = input(clr.INF + "\nEnter the file storing official values: " + clr.END)
RecordedNumbersFile = input(clr.INF + "Enter the file storing recorded values: " + clr.END)
print(clr.INF + "\n\nWhat would you like to do?" + clr.END)
print(clr.INF + " [1]" + clr.END + " - Find Incorrect Numbers")
print(clr.INF + " [2]" + clr.END + " - Find Duplicate Numbers")
print(clr.INF + " [3]" + clr.END + " - Find Missing Numbers")
Input = input('Input: ')

# Open files and split them into lists

try:
    with open(RecordedNumbersFile, 'r') as file: RecordedList = file.read() 
    with open(OfficialNumbersFile, 'r') as file: OfficialList = file.read()
except:
    print(clr.ERR + '\nERROR: ' + clr.END + 'One or more files are missing.\n'); exit()

RecordedNumbers = RecordedList.split('\n')
OfficialNumbers = OfficialList.split('\n')

# Remove labels from consideration

for value in OfficialNumbers: 
    if ('-' in value): labels += 1

# Run selection

if (Input == '1'): findIncorrectValues(); file.close(); exit()
if (Input == '2'): findDuplicateValues(); file.close(); exit()
if (Input == '3'): findMissingValues(); file.close(); exit()

print(clr.ERR + '\nERROR: ' + clr.END + 'Invalid selection.\n'); exit()