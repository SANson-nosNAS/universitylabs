class Smartphone:
    total_smartphones = 0
    brand_models = {
        "Apple": ["iPhone 12", "iPhone 13", "iPhone 14"],
        "Samsung": ["Galaxy S21", "Galaxy S22", "Galaxy S23"],
        "Xiaomi": ["Mi 11", "Mi 12", "Redmi Note"]
    }
    
    def __init__(self, brand, model, price, color):
        self.brand = brand
        self.model = model
        self.price = price
        self.color = color
        self.is_on = False
        self.installed_apps = []
        
        Smartphone.total_smartphones += 1
    
    def turn_on(self):
        if not self.is_on:
            self.is_on = True
            print(f"{self.brand} {self.model}: Телефон включен")
        else:
            print("Телефон уже включен")
    
    def turn_off(self):
        if self.is_on:
            self.is_on = False
            print(f"{self.brand} {self.model}: Телефон выключен")
        else:
            print("Телефон уже выключен")
    
    def install_app(self, app_name):
        if self.is_on:
            self.installed_apps.append(app_name)
            print(f"Приложение '{app_name}' установлено")
        else:
            print("Сначала включите телефон!")

    def show_info(self):
        print(f"Информация о смартфоне:")
        print(f"Бренд: {self.brand}")
        print(f"Модель: {self.model}")
        print(f"Цена: {self.price} руб.")
        print(f"Цвет: {self.color}")
        print(f"Статус: {'Включен' if self.is_on else 'Выключен'}")
        print(f"Установленные приложения: {', '.join(self.installed_apps) if self.installed_apps else 'Нет'}")

    @staticmethod
    def convert_currency(price_rub, currency="USD"):
        rates = {
            "USD": 90,  # 1 USD = 90 RUB
            "EUR": 98,  # 1 EUR = 98 RUB
            "CNY": 12   # 1 CNY = 12 RUB
        }
        
        if currency in rates:
            return round(price_rub / rates[currency], 2)
        else:
            return price_rub
    
    @classmethod
    def create_from_brand(cls, brand, price, color):
        if brand in cls.brand_models and cls.brand_models[brand]:
            model = cls.brand_models[brand][0]  
            return cls(brand, model, price, color)
        else:
            return cls(brand, "Unknown", price, color)
    
    @classmethod
    def get_total_smartphones(cls):
        return f"Всего создано смартфонов: {cls.total_smartphones}"
    
iphone = Smartphone("Apple", "iPhone 14", 90000, "черный")
samsung = Smartphone.create_from_brand("Samsung", 70000, "серебристый")
xiaomi = Smartphone("Xiaomi", "Redmi Note 11", 35000, "синий")

print("Демонстрация методов экземпляра:")
iphone.turn_on()
iphone.install_app("Telegram")
iphone.install_app("YouTube")
iphone.show_info()

print("Демонстрация статического метода:")
price_usd = Smartphone.convert_currency(90000, "USD")
price_eur = Smartphone.convert_currency(90000, "EUR")
print(f"Цена iPhone 14: 90000 RUB = {price_usd} USD = {price_eur} EUR")

print("Демонстрация метода класса:")
print(Smartphone.get_total_smartphones())

print("Работа с другим смартфоном:")
samsung.turn_on()
samsung.install_app("WhatsApp")
samsung.show_info()