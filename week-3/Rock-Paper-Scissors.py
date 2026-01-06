import random
rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

scissors = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''
print("What do you choose? Type 0 for Rock, 1 for Paper, 2 for Scissors.")
choice = int(input())
if choice == 0:
    print(rock)
elif choice == 1:
    print(paper)
elif choice == 2:
    print(scissors)
comp = random.randint(0,2)
print("Computer chose: ")
if comp == 0:
    print(rock)
elif comp == 1:
    print(paper)
elif comp == 2:
    print(scissors)
if comp == choice:
    print("It's a tie!")
elif comp == 0 and choice == 1:
    print("You win!")
elif comp == 1 and choice == 0:
    print("You Lose!")
elif comp == 2 and choice == 1:
    print("You Lose!")
elif comp == 2 and choice == 0:
    print("You Win!")
elif comp == 0 and choice == 2:
    print("You Lose!")
elif comp == 1 and choice == 2:
    print("You Win!")
