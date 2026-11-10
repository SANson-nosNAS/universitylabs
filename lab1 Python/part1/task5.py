flower_shop = {
    'весенний': ['розы, тюльпаны, гиацинты', 2500, 5],
    'романтический': ['розы, альстромерии, гипсофила', 3200, 3],
    'солнечный': ['подсолнухи, герберы, хризантемы', 2800, 4],
    'нежный': ['пионы, розы, сирень', 3500, 2],
    'королевский': ['розы, орхидеи, лилии', 4500, 3],
    'полевой': ['ромашки, васильки, колокольчики', 1800, 6]
}

while True:
    print("ЦВЕТОЧНЫЙ МАГАЗИН")
    print("1. Просмотр описания букетов")
    print("2. Просмотр цены букетов")
    print("3. Просмотр количества букетов")
    print("4. Вся информация о букетах")
    print("5. Покупка букета")
    print("6. До свидания")
    
    choice = input("Выберите пункт меню (1-6): ")
    
    match choice:
        case '1':
            print("\nОПИСАНИЕ БУКЕТОВ")
            for name, info in flower_shop.items():
                print(f"{name.capitalize()}: {info[0]}")
        
        case '2':
            print("\nЦЕНЫ БУКЕТОВ")
            for name, info in flower_shop.items():
                print(f"{name.capitalize()}: {info[1]} руб")
        
        case '3':
            print("\nКОЛИЧЕСТВО БУКЕТОВ В НАЛИЧИИ")
            for name, info in flower_shop.items():
                print(f"{name.capitalize()}: {info[2]} шт")
        
        case '4':
            print("\nПОЛНАЯ ИНФОРМАЦИЯ О БУКЕТАХ")
            for name, info in flower_shop.items():
                print(f"\n{name.capitalize()}:")
                print(f"Состав: {info[0]}")
                print(f"Цена: {info[1]} руб")
                print(f"В наличии: {info[2]} шт")
        
        case '5':
            print("\nПОКУПКА БУКЕТА")
            total_cost = 0
            purchases = []
            
            while True:
                print("\nДоступные букеты:")
                for name in flower_shop.keys():
                    print(f"  - {name.capitalize()}")
                
                product = input("\nВведите название букета (или 'n' для выхода): ").lower()
                
                if product == 'n':
                    break
                
                if product not in flower_shop:
                    print("Такого букета нет в ассортименте!")
                    continue
                
                try:
                    quantity = int(input(f"Введите количество букетов (доступно {flower_shop[product][2]} шт): "))
                    
                    if quantity <= 0:
                        print("Количество должно быть положительным!")
                        continue
                    
                    if quantity > flower_shop[product][2]:
                        print(f"Недостаточно букетов! Доступно только {flower_shop[product][2]} шт")
                        continue
                    
                    cost = flower_shop[product][1] * quantity
                    total_cost += cost
                    
                    flower_shop[product][2] -= quantity
                    
                    purchases.append((product, quantity, cost))
                    
                    print(f"Добавлено: {product} - {quantity} шт, стоимость: {cost} руб")
                    
                except ValueError:
                    print("Пожалуйста, введите целое число!")
            
            if purchases:
                print("ЧЕК")
                for item in purchases:
                    print(f"{item[0].capitalize():15} {item[1]} шт x {flower_shop[item[0]][1]} руб = {item[2]} руб")
                print(f"ИТОГО: {total_cost} руб")
                
                print("\nОСТАТКИ ПОСЛЕ ПОКУПКИ")
                for name, info in flower_shop.items():
                    print(f"{name.capitalize()}: {info[2]} шт")
            else:
                print("Покупок не совершено")
        
        case '6':
            print("\nСпасибо за посещение! Приходите к нам еще!")
            break
        
        case _:
            print("Неверный выбор. Пожалуйста, введите число от 1 до 6.")