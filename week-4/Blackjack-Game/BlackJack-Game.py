import random as r
import asciiart as art
import os

def clear_screen():
    os.system("cls" if os.name == "nt" else "clear")

cards = [11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10]

def printcard(cardart):
    for l in cardart:
        print(l+" ", end="")
    print("")

print(art.logo)

ans = input("Do you want to play a game of BlackJack? Type 'y' or 'n' : ")
winner = "none"
while ans == 'y':

    dealer_cards = []
    dealer_cards = r.choices(cards, k=2)
    indexd = []
    indexd.append(cards.index(dealer_cards[0]))
    indexd.append(cards.index(dealer_cards[1]))
    card_art_d = []
    card_art_d.append(art.card[indexd[0]])
    card_art_d.append(art.card[indexd[1]])
    print(card_art_d[0], art.CARD_HIDDEN)
    dealer_sum = 0
    for num in dealer_cards:
        dealer_sum += num
    print(f"First card of Dealer is [{dealer_cards[0]}]")

    my_cards = []
    my_cards = r.choices(cards, k=2)
    index = []
    index.append(cards.index(my_cards[0]))
    index.append(cards.index(my_cards[1]))
    card_art = []
    card_art.append(art.card[index[0]])
    card_art.append(art.card[index[1]])
    printcard(card_art)
    my_sum = 0
    for num in my_cards:
        my_sum += num
    print(f"Your cards: {my_cards}, current score: {my_sum}")
    i = 2
    ans1 = 'y'
    while ans1=='y':
        if my_sum <= 21:
            if my_sum == 21:
                if len(my_cards)==2:
                    ans1 ='n'
                    winner = "you"
                else:
                    ans1 = 'n'
            else:
                ans1 = input("Type 'y' to get another card, type 'n' to pass: ")
                if ans1 == 'y':
                    my_cards.append(r.choice(cards))
                    index.append(cards.index(my_cards[i]))
                    card_art.append(art.card[index[i]])
                    printcard(card_art)
                    my_sum += my_cards[i]
                    while my_sum > 21:
                        if my_cards.count(11) > 0:
                            ind = my_cards.index(11)
                            my_cards[ind] = 1
                            my_sum -= 10
                        else:
                            break

                    i += 1
                    print(f"Your cards: {my_cards}, current score: {my_sum}")
                else:
                    ans1 = 'n'
        else:
            ans1 = 'n'

    ans2 = 'y'
    j = 2
    while ans2=='y':
        if dealer_sum <= 21:
            if dealer_sum == 21:
                if len(dealer_cards)==2:
                    ans2 ='n'
                    winner = "dealer"
                else:
                    ans2 = 'n'
            elif dealer_sum < 17:
                dealer_cards.append(r.choice(cards))
                indexd.append(cards.index(dealer_cards[j]))
                card_art_d.append(art.card[indexd[j]])
                dealer_sum += dealer_cards[j]
                if dealer_sum > 17:
                    ans2 = 'n'
                j += 1
            else:
                ans2 = 'n'
        elif dealer_sum > 21:
            while dealer_sum > 21:
                    if dealer_cards.count(11) > 0:
                        ind = dealer_cards.index(11)
                        dealer_cards[ind] = 1
                        dealer_sum -= 10
                    else:
                        break
            if dealer_sum>17:
                ans2 = 'n'
            else:
                ans2 = 'y'
    
    print("Your cards are: ")
    printcard(card_art)
    print("Dealer's card are: ")
    printcard(card_art_d)

    if winner == "none":
        print(f"Your final hand: {my_cards}, final score: {my_sum}")
        print(f"Dealer's final hand: {dealer_cards}, final score: {dealer_sum}")
        if my_sum<=21 and dealer_sum<=21:
            if my_sum > dealer_sum:
                print("You won! 🏆")
            elif my_sum == dealer_sum:
                print("Draw!")
            else:
                print("You lose! ☹️")
        elif my_sum > 21 and dealer_sum < 21:
            print("You went out of bound! Dealer wins 🫠")
        elif my_sum < 21 and dealer_sum > 21:
            print("Dealer went out of bound! You win! 🏅")
        else:
            print("You both went out of bound! 😭")
            print("So, its a draw!")
    elif my_sum == 21 and dealer_sum == 21 and len(my_cards) == 2 and len(dealer_cards) == 2:
        print("Dealer got Blackjack and so do you 🫠")
        print("So, its a draw!")
    elif winner == "you":
        print("It's a Blackjack! ", end="")
        print("You won! 🏆")
    elif winner == "dealer":
        print("Dealer got Blackjack!")
        print("Dealer won!")
    else:
        print("some technical error...")
    winner = "none"
    print("Game ends here!")
    input("Hit enter to clear...")
    clear_screen()
    print(art.logo)
    ans = input("Do you want to play a game of BlackJack? Type 'y' or 'n' : ")
print("Sayonara, see you again!")