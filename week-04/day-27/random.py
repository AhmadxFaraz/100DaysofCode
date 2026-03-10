from turtle import Turtle, Screen

screen = Screen()

timmy = Turtle()
for _ in range(5):
    for _ in range(4):
        for _ in range(4):
            timmy.forward(3)
            timmy.penup()
            timmy.forward(3)
            timmy.pendown()
        timmy.right(90)
    timmy.left(90)

screen.exitonclick()

