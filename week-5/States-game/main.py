import pandas
import turtle
import time

screen = turtle.Screen()
screen.title("U.S States Game")
image = "Blank_states_image.gif"
screen.addshape(image)

turtle.shape(image)

data = pandas.read_csv("50_States.csv")
all_states = data.State.to_list()

guessed_states = []

while len(guessed_states) < 50:
    time.sleep(0.2)
    answer_state = screen.textinput(title=f"{len(guessed_states)}/50 States Correct", prompt="What's another state's name?").title()
    if answer_state == "Exit":
        missing_states = [state for state in all_states if state not in guessed_states]
        # for state in all_states:
        #     if state not in guessed_states:
        #         missing_states.append(state)
        new_data = pandas.DataFrame(missing_states)
        new_data.to_csv("States-to-Learn.csv")
        break
    if answer_state in all_states:
        guessed_states.append(answer_state)
        t = turtle.Turtle()
        t.hideturtle()
        t.penup()
        state_data = data[data.State == answer_state]
        t.goto(state_data.x.item(), state_data.y.item())
        t.write(answer_state)
