def calculate_wall_area():
    length = float(input("Введите длину комнаты (м): "))
    width = float(input("Введите ширину комнаты (м): "))
    height = float(input("Введите высоту комнаты (м): "))

    wall_area_1 = 2 * length * height
    wall_area_2 = 2 * width * height
    total_wall_area = wall_area_1 + wall_area_2
    
    print(f"Общая площадь стен: {total_wall_area:.2f} кв.м")

    windows_count = int(input("Количество окон: "))
    windows_area = 0
    for i in range(windows_count):
        window_width = float(input(f"Ширина окна {i+1} (м): "))
        window_height = float(input(f"Высота окна {i+1} (м): "))
        windows_area += window_width * window_height
    
    doors_count = int(input("Количество дверей: "))
    doors_area = 0
    for i in range(doors_count):
        door_width = float(input(f"Ширина двери {i+1} (м): "))
        door_height = float(input(f"Высота двери {i+1} (м): "))
        doors_area += door_width * door_height
    
    final_area = total_wall_area - windows_area - doors_area

    print(f"Площадь стен для оклейки обоями: {final_area} кв.м")

calculate_wall_area()