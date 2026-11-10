class Car:
    def __init__(self, speed, color, name, is_police=False):
        self.speed = speed
        self.color = color
        self.name = name
        self.is_police = is_police
    
    def go(self):
        print(f"{self.name}: Машина поехала")
    
    def stop(self):
        print(f"{self.name}: Машина остановилась")
    
    def turn(self, direction):
        print(f"{self.name}: Машина повернула {direction}")
    
    def show_speed(self):
        print(f"{self.name}: Текущая скорость {self.speed} км/ч")

class TownCar(Car):
    def show_speed(self):
        super().show_speed()
        if self.speed > 60:
            print(f"ВНИМАНИЕ! {self.name}: Превышение скорости! (более 60 км/ч)")

class SportCar(Car):
    pass

class WorkCar(Car):
    def show_speed(self):
        super().show_speed()
        if self.speed > 40:
            print(f"ВНИМАНИЕ! {self.name}: Превышение скорости! (более 40 км/ч)")

class PoliceCar(Car):
    def __init__(self, speed, color, name):
        super().__init__(speed, color, name, is_police=True)

town_car = TownCar(70, "синий", "Toyota")
sport_car = SportCar(120, "красный", "Ferrari")
work_car = WorkCar(45, "белый", "Грузовик")
police_car = PoliceCar(90, "белый", "Ford")

cars = [town_car, sport_car, work_car, police_car]

for car in cars:
    print(f"Автомобиль: {car.name}")
    print(f"Цвет: {car.color}")
    print(f"Полицейская машина: {'Да' if car.is_police else 'Нет'}")
    
    car.go()
    car.show_speed()
    car.turn("налево")
    car.stop()