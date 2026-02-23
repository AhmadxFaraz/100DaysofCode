BACKGROUND_COLOR = "#B1DDC6"
current_card = {}
flip_timer = None

from tkinter import *
import pandas as pd
import random

# --------------------------------------- Data ---------------------------------------- #

try:
    data = pd.read_csv("/Users/ahmadxfaraz/CodingProjects/100DaysofCode/week-8/flash-card-project-start/data/words_to_learn.csv")
except FileNotFoundError:
    original_data = pd.read_csv("/Users/ahmadxfaraz/CodingProjects/100DaysofCode/week-8/flash-card-project-start/data/french_words.csv")
    to_learn = original_data.to_dict(orient="records")
else:
    to_learn = data.to_dict(orient="records")

# ------------------------------------- UI Setup -------------------------------------- #

window = Tk()
window.title("Flash Card App")
window.config(padx=40, pady=40, bg=BACKGROUND_COLOR)

canvas = Canvas(width=850, height=600, bg=BACKGROUND_COLOR, highlightthickness=0)
canvas.grid(row=0, column=0, columnspan=2)

front = PhotoImage(file="/Users/ahmadxfaraz/CodingProjects/100DaysofCode/week-8/flash-card-project-start/images/card_front.png")
back = PhotoImage(file="/Users/ahmadxfaraz/CodingProjects/100DaysofCode/week-8/flash-card-project-start/images/card_back.png")

card_background = canvas.create_image(430, 300, image=front)
title_text = canvas.create_text(425, 150, text="", font=("Arial", 40, "italic"))
word_text = canvas.create_text(425, 300, text="", font=("Arial", 60, "bold"))

# ------------------------------------- Mechanism -------------------------------------- #

def next_card():
    global current_card, flip_timer

    if flip_timer:
        window.after_cancel(flip_timer)

    current_card = random.choice(to_learn)

    canvas.itemconfig(card_background, image=front)
    canvas.itemconfig(title_text, text="French", fill="black")
    canvas.itemconfig(word_text, text=current_card["French"], fill="black")

    flip_timer = window.after(3000, flip_card)


def flip_card():
    canvas.itemconfig(card_background, image=back)
    canvas.itemconfig(title_text, text="English", fill="white")
    canvas.itemconfig(word_text, text=current_card["English"], fill="white")


def is_known():
    to_learn.remove(current_card)
    data = pd.DataFrame(to_learn)
    data.to_csv("/Users/ahmadxfaraz/CodingProjects/100DaysofCode/week-8/flash-card-project-start/data/words_to_learn.csv", index=False)
    next_card()

# ------------------------------------- Buttons -------------------------------------- #

right_image = PhotoImage(file="/Users/ahmadxfaraz/CodingProjects/100DaysofCode/week-8/flash-card-project-start/images/right.png")
right_button = Button(image=right_image, highlightthickness=0, command=is_known)
right_button.grid(row=1, column=1)

wrong_image = PhotoImage(file="/Users/ahmadxfaraz/CodingProjects/100DaysofCode/week-8/flash-card-project-start/images/wrong.png")
wrong_button = Button(image=wrong_image, highlightthickness=0, command=next_card)
wrong_button.grid(row=1, column=0)

# Start with first card
next_card()

window.mainloop()
