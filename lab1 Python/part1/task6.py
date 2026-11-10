C_1 = (35, 78, 21, 37, 2, 98, 6, 100, 231)
C_2 = (45, 21, 124, 76, 5, 23, 91, 234)

print(f"C_1 = {C_1}")
print(f"C_2 = {C_2}")

sum1 = sum(C_1)
sum2 = sum(C_2)

print(f"Сумма элементов C_1: {sum1}")
print(f"Сумма элементов C_2: {sum2}")

if sum1 > sum2:
    print(f"\nСумма больше в кортеже C_1 ({sum1} > {sum2})")
elif sum2 > sum1:
    print(f"\nСумма больше в кортеже C_2 ({sum2} > {sum1})")
else:
    print(f"\nСуммы элементов равны ({sum1} = {sum2})")

print("\nПОРЯДКОВЫЕ НОМЕРА МИНИМАЛЬНЫХ И МАКСИМАЛЬНЫХ ЭЛЕМЕНТОВ:")

print("Кортеж C_1:")
print(f"Элементы: {C_1}")

min_val1 = min(C_1)
max_val1 = max(C_1)

min_indices1 = []
for i in range(len(C_1)):
    if C_1[i] == min_val1:
        min_indices1.append(i + 1)

max_indices1 = []
for i in range(len(C_1)):
    if C_1[i] == max_val1:
        max_indices1.append(i + 1)

print(f"Минимальный элемент: {min_val1} (порядковые номера: {min_indices1})")
print(f"Максимальный элемент: {max_val1} (порядковые номера: {max_indices1})")

print("Кортеж C_2:")
print(f"Элементы: {C_2}")

min_val2 = min(C_2)
max_val2 = max(C_2)

min_indices2 = []
for i in range(len(C_2)):
    if C_2[i] == min_val2:
        min_indices2.append(i + 1)

max_indices2 = []
for i in range(len(C_2)):
    if C_2[i] == max_val2:
        max_indices2.append(i + 1)

print(f"Минимальный элемент: {min_val2} (порядковые номера: {min_indices2})")
print(f"Максимальный элемент: {max_val2} (порядковые номера: {max_indices2})")