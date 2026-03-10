from turtle import Turtle as t, Screen as s
import random as r

colors = [
    "red", "blue", "green", "yellow", "purple", "orange", 
    "pink", "cyan", "magenta", "gold", "turquoise", 
    "deep sky blue", "forest green", "crimson", "slate blue", 
    "orchid", "navy", "dark orange", "spring green", "chocolate"
]
tim = t()
tim.pensize(10)
tim.speed(0)
screen = s()
def random_walk():
    tim.color(r.choice(colors))
    m = [1,2,3,4]
    move = r.choice(m)
    if move == 1:
        tim.forward(50)
    elif move == 2:
        tim.right(90)
        tim.forward(50)
    elif move == 3:
        tim.left(90)
        tim.forward(50)
    else:
        tim.backward(50)

for _ in range(200):
    random_walk()
screen.exitonclick()
    