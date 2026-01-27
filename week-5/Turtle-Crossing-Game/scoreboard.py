from turtle import Turtle, Screen

FONT = ("Courier", 10, "normal")


class Scoreboard(Turtle):
    
    def __init__(self):
        super().__init__()
        self.color("black")
        self.penup()
        self.hideturtle()
        self.level = 1
        self.goto(-240,280)
        self.write(f"Level - {self.level}", align="center", font=FONT)

    def next_level(self):
        self.clear()
        self.level += 1
        self.goto(-240,280)
        self.write(f"Level - {self.level}", align="center", font=FONT)

    def game_over(self):
        self.clear()
        self.goto(0,0)
        self.write("Game Over!", align="center", font=(FONT,60,"bold"))#size modified by SG

    def level_transition(self):
        self.clear()
        self.goto(0, 0)
        self.write(                                 #level number display at center(modified by SG)
            f"LEVEL {self.level}",
            align="center",
            font=("Courier", 30, "bold")
        )



