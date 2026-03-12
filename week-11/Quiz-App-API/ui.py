from tkinter import *

THEME_COLOR = "#375362"

class QuizInterface:

    def __init__(self):
        self.window = Tk()
        self.window.title("Quizzler")
        self.window.config(padx=20, pady=20, bg=THEME_COLOR)

        self.canvas = Canvas(width=300, height=250,bg="#FFFFFF", highlightthickness=0)
        self.canvas.grid(row=1, column=0, columnspan=2)

        self.true_img = PhotoImage(file="/images/true.png")
        self.false_img = PhotoImage(file="/images/false.png")


        self.window.mainloop()