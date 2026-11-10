try:
    r = int(input("Введите количетсво строк в матрице: "))

    matrix = []

    for i in range(r):
        row = input(f"Введите {i + 1} ряд матрицы через пробел: ").split()
        for i in range(len(row)):
            row[i] = int(row[i])
        matrix.append(row)

    print("Матрица:")
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            print(matrix[i][j], end=' ')
        print()

    temp = 0
    temp_i = 0
    temp_j = 0
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            if matrix[i][j] > temp:
                temp = matrix[i][j]
                temp_i = i
                temp_j = j

    print(f"Наибольший элемент в массиве находится на позиции: {temp_i + 1} строка {temp_j + 1} столбец")

except ValueError:
    print("Ошибка: введите корректное целое число!")
except NameError:
    print("Ошибка: переменная не определена.")
except TypeError:
    print("Ошибка: неверный тип данных.")
except KeyboardInterrupt:
    print("\nПрограмма прервана пользователем.")
except Exception as e:
    print(f"Непредвиденная ошибка: {e}")
finally:
    print("Программа завершена.")