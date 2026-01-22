import time
from turtle import Screen
from player import Player
from car_manager import CarManager
from scoreboard import Scoreboard

screen = Screen()
screen.setup(width=600, height=600)
screen.tracer(0)
screen.title("Turtle Crossing Game")

player = Player()
car_manager = CarManager()
scoreboard = Scoreboard()

screen.listen()
screen.onkey(player.move_up, "Up")
screen.onkey(player.move_down, "Down")

game_is_on = True

while game_is_on:
    time.sleep(car_manager.move_speed)
    screen.update()
    car_manager.create_car()
    car_manager.start()
    if player.finished():
        scoreboard.next_level()
        player.refresh()
        car_manager.increase_speed()
        car_manager.refresh()
    for car in car_manager.cars:
        if player.distance(car) < 30:
            game_is_on = False
            scoreboard.game_over()

screen.exitonclick()