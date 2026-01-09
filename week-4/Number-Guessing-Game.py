import art
import random

print(art.logo_num)

print("Welcome to the Number Guessing Game!")
print("I'm thinking of a number between 1 and 100.")

level = input("Choose a difficulty. Type 'easy' or 'hard': ")

attempts = 0

if level == "easy":
    attempts = 5
    print(f"You have {attempts} attempts")
elif level == "hard":
    attempts = 10
    print(f"You have {attempts} attempts")
else:
    print("Please choose a difficulty.")

guess = random.randint(1,101)

while attempts > 0:
    ans = int(input("Make a guess: "))
    if ans == guess:
        print("You guessed the number!")
        break
    elif ans > guess + 10:
        attempts = attempts - 1
        if attempts >1:
            print("Too high.")
            print("Guess again.")
            print(f"You've {attempts} attempts remaining to guess the number.")
        elif attempts > 0:
            print("Last chance")
    elif ans < guess - 10:
        attempts = attempts - 1
        if attempts >1:
            print("Too low.")
            print("Guess again.")
            print(f"You've {attempts} attempts remaining to guess the number.")
        elif attempts > 0:
            print("Last chance")
    else:
        attempts = attempts - 1
        if attempts >1:
            print("Very close")
            print("Guess again.")
            print(f"You've {attempts} attempts remaining to guess the number.")
        elif attempts > 0:
            print("Last chance")

if attempts == 0:
    print("You failed to guess the number.")