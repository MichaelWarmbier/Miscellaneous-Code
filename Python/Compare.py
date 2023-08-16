############ Data ##############

DrawioValuesFile = 'PLACE_DRAWIO_VALUES_HERE.txt'
OfficialValuesFile = 'EXTRACTED_VALUES.txt'
totalMatches = 0
labels = 0

class clr:
    ERR = "\u001b[31m"
    END = "\x1b[37m"
    FIN = "\x1b[32m"


############ Main ##############

# Open files and split them into lists

try:
    with open(DrawioValuesFile, 'r') as file: DrawioValuesFile = file.read() 
    with open(OfficialValuesFile, 'r') as file: OfficialValuesFile = file.read()
except:
    print(clr.ERR + 'ERROR: ' + clr.END + 'One or more files are missing'); exit()

DrawioValues = DrawioValuesFile.split('\n')
OfficialValues = OfficialValuesFile.split('\n')

# Remove labels from consideration

for value in OfficialValues: 
    if ('-' in value): labels += 1

# Remove already existing values

for value in reversed(range(len(DrawioValues))):
    if (DrawioValues[value] in OfficialValues):
        DrawioValues.pop(value)
        totalMatches += 1
        
# Save results and notify user 

with open('Results.txt', 'w') as file:
    for value in DrawioValues:
        file.write(value + '\n')

print(clr.FIN + 'Values compared, total of ' + clr.END + str(totalMatches) + clr.FIN + ' values removed.')
print(clr.END + str(len(DrawioValues) - labels) + clr.FIN + ' values remaining.')
print(clr.FIN + 'Values saved in Results.txt' + clr.END)
file.close()