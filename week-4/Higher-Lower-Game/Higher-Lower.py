import random
import art
import game_data
import os
def clear_screen():
    os.system("cls" if os.name == "nt" else "clear")
def compare(A, B):
    if A['follower_count'] > B['follower_count']:
        winner = A
    else:
        winner = B
    return winner
print(art.logo)
data = game_data.data
game_over = False
Score = 0
A = {}
while not game_over:
    if not A:
        A = random.choice(data)
    while True:
        B = random.choice(data)
        if B != A:
            break
    print(f"Compare A: {A['name']}, a {A['description']}, from {A['country']}.")
    print(art.vs)
    print(f"Against B: {B['name']}, a {B['description']}, from {B['country']}.")
    answer = input("Who has more followers? Type 'A' or 'B': ").upper()
    lead = compare(A, B)
    if lead == A and answer == "A":
        Score +=1
    elif lead == B and answer == "B":
        Score +=1
    elif lead == "tie":
        Score += 0
    else:
        game_over = True
    clear_screen()
    if not game_over:
        print(art.logo)
        print("You're right! Current Score: ", Score)
        A = lead

print("Sorry, that's wrong. Final Score: ", Score)
