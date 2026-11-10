class Example:
    static_var1 = 10
    static_var2 = 5
    
    def __init__(self):
        self.dynamic_var1 = 2
        self.dynamic_var2 = 3
    
    def first_method(self):
        local_var = 100
        print(f"Локальная переменная: {local_var}")
    
    def second_method(self):
        return Example.static_var1 + Example.static_var2
    
    def third_method(self):
        return self.dynamic_var1 ** self.dynamic_var2

obj = Example()

print("Первый метод:")
obj.first_method()

print(f"Второй метод (сумма статических переменных): {obj.second_method()}")
print(f"Третий метод (2 ** 3): {obj.third_method()}")
print(f"Переменная a (dynamic_var1): {obj.dynamic_var1}")