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
        car_manager.clear_cars()    #clear screen after level completion(modified by SG)

        scoreboard.next_level()  #level increment
        scoreboard.level_transition()   #level number display at center(modified by SG)

        screen.update() #refresh screen to show level transition(modified by SG)
        time.sleep(1.2)   # animation pause(modified by SG)

        scoreboard.clear()  
        scoreboard.goto(-240, 280)  
        scoreboard.write(f"Level - {scoreboard.level}", align="center", font=("Courier", 10, "normal")) #modified by SG

        player.refresh()    
        car_manager.increase_speed()    


    for car in car_manager.cars:
        if player.distance(car) < 20:
            game_is_on = False
            scoreboard.game_over()  #game over display:)

screen.exitonclick()