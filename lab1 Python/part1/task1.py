count = 1  
number = 3
result = 2

while count < 1001:
    is_target= True
    if number > 2:
        if number % 2 == 0:
            is_target = False
        else:
            i = 3
            while i * i <= number:
                if number % i == 0:
                    is_target = False
                    break
                i += 2
    
    if is_target:
        count += 1
        result = number
    
    number += 2

print(f"1001-е простое число: {result}")