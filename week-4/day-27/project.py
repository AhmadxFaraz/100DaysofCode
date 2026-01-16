import colorgram
from turtle import Turtle, Screen, colormode
import random

colors = colorgram.extract('photo.png', 25)
color_list = [c.rgb for c in colors]

screen = Screen()
colormode(255)

tim = Turtle()
tim.penup()
tim.hideturtle()
tim.speed("fastest")

for row in range(10):
    for col in range(10):
        colour = random.choice(color_list)
        tim.color(colour)
        tim.begin_fill()
        tim.circle(10)
        tim.end_fill()
        tim.forward(30)
    tim.backward(300)
    tim.right(90)
    tim.forward(30)
    tim.left(90)

screen.exitonclick()