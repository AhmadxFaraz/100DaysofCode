num = 11
result = True
i = 0
print("Welcome to the Number Guessing Game...\nHints - 1. Number is between 1-20, 2. Number is integer(no decimals)\nRemember you got only 3 trials.\n")
while(i<3):
    guess = int(input("Enter you guess : "))
    if(guess == 11):
        print("correct guess, you win")
        break
    else:
        if(i<=1):
            print("Incorrect guess, try again!!!")
            if(guess<9): print("Too low")
            elif(guess>13): print("Too high")
            else:print("very close to the number")
        elif(i==2):
            print(f"Number was {num}")
        if(i==1):
            print("Last Chance")
        i += 1
print("Game Over!!!")