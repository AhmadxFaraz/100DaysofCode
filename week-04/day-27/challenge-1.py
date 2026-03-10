from turtle import Turtle, Screen
import random as r
colors = [
    "red", "blue", "green", "yellow", "purple", "orange", 
    "pink", "cyan", "magenta", "gold", "turquoise", 
    "deep sky blue", "forest green", "crimson", "slate blue", 
    "orchid", "navy", "dark orange", "spring green", "chocolate"
]
timmy = Turtle()
screen = Screen()
i = 3
for _ in range(10):
    for _ in range(i):
        timmy.forward(100)
        timmy.left(360/i)
    i+=1
    timmy.color(r.choice(colors))

screen.exitonclick()