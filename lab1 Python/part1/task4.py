text = ' Enjoy every moment'

result = {}

for item in text:
    if item in result:
        result[item] += 1
    else:
        result[item] = 1

print(f"Исходная строка: '{text}'")
print(f"Результат: {result}")