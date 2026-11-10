string = input()
temp = ''
for item in string:
    if(item == '1' or item == '2' or item == '3' or item == '4' or item == '5' or item == '6' or item == '7' or item == '8' or item == '9'):
        temp += item
    else:
        print(temp, end = '')
        temp = ''
