from turtle import Turtle, Screen
import random


screen = Screen()
screen.screensize(500, 500)

turtle_list = []

color = ["red", "blue", "green", "yellow", "pink"]

y_pos = [80, 40, 0, -40, -80]

for i in range(5):
    turtle = Turtle(shape = "turtle")
    turtle.penup()
    turtle.color(color[i])
    turtle.goto(x = -350, y = y_pos[i])
    turtle_list.append(turtle)

bet = screen.textinput("Turtle Race", "Which color turtle are you betting on? ")

if bet:
    bet_on = True

while bet_on:
    for turtle in turtle_list:
        if turtle.xcor()>330:
            bet_on = False
            win_color = turtle.color()
            if win_color == bet:
                print(f"You've won! The {win_color} turtle is the winner!")
            else:
                print(f"You've lost! The {win_color} turtle is the winner!")
            
        distance = random.randint(0,10)
        turtle.forward(distance)
    
screen.exitonclick()