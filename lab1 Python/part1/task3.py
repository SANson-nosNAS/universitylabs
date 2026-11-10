list = [5, -3, 12, -8, 7, 0, -15, 4, 9]

print(f"Исходный список: {list}")
    
odd_numbers = [x for x in list if x % 2 != 0]
    
if odd_numbers:
    max_odd = max(odd_numbers)
    print(f"\n1. Наибольший нечетный элемент: {max_odd}")
    print(f"Все нечетные элементы: {odd_numbers}")
else:
    print("\n1. Нечетных элементов нет в списке")

min_abs_element = min(list, key=abs)
min_abs_value = abs(min_abs_element)

print(f"\n2. Минимальный по модулю элемент: {min_abs_element}")
print(f"Его модуль: {min_abs_value}")

print("\nВсе элементы и их модули:")
for num in list:
    print(f"|{num}| = {abs(num)}")