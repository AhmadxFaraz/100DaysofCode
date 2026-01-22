from turtle import Turtle
import time
import random
COLORS = ["red", "orange", "yellow", "green", "blue", "purple"]
STARTING_MOVE_DISTANCE = 5
MOVE_INCREMENT = 20


class CarManager():

    def __init__(self):
        self.cars = []
        self.move_speed = 0.1
        
    def create_car(self):
        ans = random.choice(['yes', 'no', 'no', 'no', 'no'])
        if ans == 'yes':
            new_car = Turtle()
            new_car.color(random.choice(COLORS))
            new_car.shape("square")
            new_car.shapesize(1,2)
            new_car.penup()
            new_car.goto(-300, random.randint(-280,280))
            new_car.showturtle()
            self.cars.append(new_car)

    def increase_speed(self):
        self.move_speed *= 0.5

    def move(self, car):
        car.forward(MOVE_INCREMENT)

    def start(self):
        for car in self.cars:
            self.move(car)
    
    def refresh(self):
        self.cars.clear()
            