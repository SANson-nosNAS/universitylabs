def check_type(data):
    try:
        if isinstance(data, tuple):
            print('Кол-во элементов: ' + str(len(data)))
        elif isinstance(data, list):
            count = 0
            for item in data:
                if(item == 0):
                    break
                else:
                    count += item
            print("Cумма всех элементов: " + str(count))
        elif isinstance(data, (int, float)):
            n_str = str(data)
            i = len(n_str) - 1
            print('Строка наоборот:', end=' ')
            while i >= 0:
                print(n_str[i], end='')
                i -= 1
            print('')
        elif isinstance(data, str):
            words = data.split()  
            word_count = len(words)
            print("Кол-во слов:", word_count)

            char_count = {}
            for char in data:
                if char in char_count:
                    char_count[char] += 1
                else:
                    char_count[char] = 1

            max_char = ''
            max_count = -1

            for char, count in char_count.items():
                if count > max_count:
                    max_count = count
                    max_char = char

            print(f"Самый частый символ: '{max_char}' (встречается {max_count} раз)")
        else:
            raise TypeError(f"Неподдерживаемый тип данных: {type(data).__name__}")
            
    except TypeError as e:
        print(f"Ошибка типа: {e}")
        
    except ValueError as e:
        print(f"Ошибка значения: {e}")
        
    except Exception as e:
        print(f"Непредвиденная ошибка: {e}")
        
    finally:
        print("Обработка данных завершена")



check_type((3,5,7,6))
check_type([6,7,4,6,8])
check_type(457657)
check_type('bsbsb rdsgerdg redgrredg')