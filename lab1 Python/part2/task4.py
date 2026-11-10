def demo_try_except_finally():
    print("try/except/finally")
    print()
    print("Пример 1 (без ошибок):")
    try:
        print("try: 10 / 2 =", 10 / 2)
    except ZeroDivisionError:
        print("except: Деление на ноль!")
    finally:
        print("finally: Этот блок выполняется всегда")
    print()
    
    print("Пример 2 (с ошибкой):")
    try:
        print("try: 10 / 0 =", 10 / 0)
    except ZeroDivisionError:
        print("except: Деление на ноль!")
    finally:
        print("finally: Этот блок выполняется всегда")
    print()
    
    print("Пример 3 (ошибка преобразования):")
    try:
        число = int("abc")
        print("try:", число)
    except ValueError:
        print("except: Нельзя преобразовать в число!")
    finally:
        print("finally: Блок выполнен")
    print()
    
    print("Пример 4 (несколько except):")
    try:
        список = [1, 2, 3]
        print("try:", список[5])
    except IndexError:
        print("except: Индекс вне диапазона!")
    except Exception as e:
        print("except:", e)
    finally:
        print("finally: Конец")
    print()
    
    print("Пример 5 (ввод пользователя):")
    try:
        число = int(input("  Введите число: "))
        print("try: Вы ввели", число)
    except ValueError:
        print("except: Это не число!")
    finally:
        print("finally: Программа завершена")

demo_try_except_finally()