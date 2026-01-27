from turtle import Turtle
import time
import random
COLORS = ["red", "orange", "yellow", "green", "blue", "purple"]
STARTING_MOVE_DISTANCE = 5
MOVE_INCREMENT = 10


class CarManager():

    def __init__(self):
        self.cars = []
        self.move_speed = 0.1
        
    def create_car(self):
        ans = random.choice(['yes', 'no', 'no', 'no', 'no', 'no'])
        if ans == 'yes':
            new_car = Turtle()
            new_car.color(random.choice(COLORS))
            new_car.shape("square")
            new_car.shapesize(1,2)
            new_car.penup()
            new_car.goto(300, random.randint(-280,280))
            new_car.showturtle()
            self.cars.append(new_car)

    def increase_speed(self):
        if self.move_speed > 0.02:
            self.move_speed -= 0.01 #increase car speed on level up(modified by SG)

    def move(self, car):
        car.backward(MOVE_INCREMENT)

    def start(self):
        for car in self.cars:
            self.move(car)
        self.cars = [car for car in self.cars if car.xcor() > -320]
    
    def clear_cars(self):
        for car in self.cars:
            car.hideturtle()
        self.cars.clear()#clears car list after level completion(modified by SG)

