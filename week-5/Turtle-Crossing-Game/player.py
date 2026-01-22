from turtle import Turtle

STARTING_POSITION = (0, -280)
MOVE_DISTANCE = 10
FINISH_LINE_Y = 280


class Player:
    
    def __init__(self):
        self.player = Turtle()
        self.player.shape("turtle")
        self.player.left(90)
        self.player.speed("fastest")
        self.player.penup()
        self.player.goto(0,-280)
        self.level = 1

    def move_up(self):
        self.player.forward(10)

    def move_down(self):
        self.player.backward(10)

    def refresh(self):
        self.player.goto(0,-280)

    def finished(self):
        return self.player.ycor() > 280
    
    def distance(self, car):
        return self.player.distance(car)

    
