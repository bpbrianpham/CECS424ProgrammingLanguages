import re

value = []
try:
    with open("a2_input.txt") as file:
        value = file.readlines()
except:
    print("Error: a2_input.txt file not found")

regex = re.compile(r'\$(\*)*(\d{0,2}(,\d{3})*|0).\d\d')

print("Starting Python Program Type to Check RegEx\n")

#ToDo: start verifying printing is only temporary
for i in range(len(value)):
    value[i] = value[i].replace('\n', '')
    if regex.match(value[i]):
        print(value[i] + " is a valid money format.")
    else:
        print(value[i] + " is an invalid money format.")