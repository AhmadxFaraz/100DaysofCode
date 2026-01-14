from turtle import Turtle, Screen, colormode
import random

def random_color():
    r = random.randint(0,255)
    g = random.randint(0,255)
    b = random.randint(0,255)
    color = (r, g, b)
    return color

screen = Screen()

tim = Turtle()
tim.speed("fastest")
colormode(255)

for _ in range(120):
    tim.color(random_color())
    tim.circle(200)
    tim.left(3)

screen.exitonclick()