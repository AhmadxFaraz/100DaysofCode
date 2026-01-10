import art
MENU = {
    "espresso": {
        "ingredients": {
            "water": 50,
            "coffee": 18,
        },
        "cost": 1.5,
    },
    "latte": {
        "ingredients": {
            "water": 200,
            "milk": 150,
            "coffee": 24,
        },
        "cost": 2.5,
    },
    "cappuccino": {
        "ingredients": {
            "water": 250,
            "milk": 100,
            "coffee": 24,
        },
        "cost": 3.0,
    }
}

resources = {
    "water": 5000,
    "milk": 3000,
    "coffee": 2500,
    "profit": 0
}

def valid_order(order):
    return order in ["espresso", "latte", "cappuccino", "report"]
    
def enough_resources(order):
    if order == "espresso":
        if resources["water"] >= MENU["espresso"]["ingredients"]["water"] and resources["coffee"] >= MENU["espresso"]["ingredients"]["coffee"]:
            return True
        else:
            return False
    elif order == "latte":
        if resources["water"] >= MENU["latte"]["ingredients"]["water"] and resources["coffee"] >= MENU["latte"]["ingredients"]["coffee"] and resources["milk"] >= MENU["latte"]["ingredients"]["milk"]:
            return True
        else:
            return False
    elif order == "cappuccino":
        if resources["water"] >= MENU["cappuccino"]["ingredients"]["water"] and resources["coffee"] >= MENU["cappuccino"]["ingredients"]["coffee"] and resources["milk"] >= MENU["cappuccino"]["ingredients"]["milk"]:
            return True
        else:
            return False
    elif order == "report":
        return False
    else:
        if order != "report":
            return False
def enough_money(coins, order):
    if order == "espresso":
        if coins>=MENU["espresso"]["cost"]:
            return True
        else:
            print("Not enough money")
            print("Insert more coins")
            return False
    elif order == "latte":
        if coins>=MENU["latte"]["cost"]:
            return True
        else:
            print("Not enough money")
            print("Insert more coins")
            return False
    elif order == "cappuccino":
        if coins>=MENU["cappuccino"]["cost"]:
            return True
        else:
            print("Not enough money")
            print("Insert more coins")
            return False

print(art.logo_cof)

while True:
    order = input("What would you like? (espresso/latte/cappuccino):").lower()
    if valid_order(order):
        if enough_resources(order):
            print("Please insert coins")
            quarters = int(input("How many quarters?: "))
            dimes = int(input("How many dimes?: "))
            nickels = int(input("How many nickels?: "))
            pennies = int(input("How many pennies?: "))
            coins = round((quarters * 0.25 + dimes * 0.10 + nickels * 0.05 + pennies * 0.01), 2)

            if order == "espresso" and enough_money(coins, order):
                resources["water"] -= MENU["espresso"]["ingredients"]["water"]
                resources["coffee"] -= MENU["espresso"]["ingredients"]["coffee"]
                change = round((coins - MENU["espresso"]["cost"]),2)
                resources["profit"] +=  coins - change
                print(f"Here is ${change} in change.")
                print("Here is your espresso ☕️ Enjoy!")
            elif order == "latte" and enough_money(coins, order):
                resources["water"] -= MENU["latte"]["ingredients"]["water"]
                resources["milk"] -= MENU["latte"]["ingredients"]["milk"]
                resources["coffee"] -= MENU["latte"]["ingredients"]["coffee"]
                change = round((coins - MENU["latte"]["cost"]),2)
                resources["profit"] += coins - change
                print(f"Here is ${change} in change.")
                print("Here is your latte ☕️ Enjoy!")
            elif order == "cappuccino" and enough_money(coins, order):
                resources["water"] -= MENU["cappuccino"]["ingredients"]["water"]
                resources["milk"] -= MENU["cappuccino"]["ingredients"]["milk"]
                resources["coffee"] -= MENU["cappuccino"]["ingredients"]["coffee"]
                change = round((coins - MENU["cappuccino"]["cost"]),2)
                resources["profit"] += coins - change
                print(f"Here is ${change} in change.")
                print("Here is your cappuccino ☕️ Enjoy!")

        elif order == "report":
            print(f"water: {resources['water']}") 
            print(f"milk: {resources['milk']}")
            print(f"coffee: {resources['coffee']}")
            print(f"profit: {resources['profit']}")
        else:
            print("Not enough resources!")
    else:
        print("Sorry, that's an invalid order")

    tell = input("Want to buy anything more? Type 'y' or 'n' :").lower()
    if tell == 'n':
        break