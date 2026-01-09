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
    "water": 300,
    "milk": 200,
    "coffee": 100,
    "money": 0
}
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
    else:
        if order != "report":
            print("Sorry, that's not a valid order")
        return False
def enough_money(coins, order):
    if order == "espresso":
        if coins>MENU["espresso"]["cost"]:
            return True
        else:
            return False
    elif order == "latte":
        if coins>MENU["latte"]["cost"]:
            return True
        else:
            return False
    elif order == "cappuccino":
        if coins>MENU["cappuccino"]["cost"]:
            return True
        else:
            return False

order = input("What would you like? (espresso/latte/cappuccino):").lower()

while True:
    if enough_resources(order):
        print("Please insert coins")
        quarters = int(input("How many quarters?: "))
        dimes = int(input("How many dimes?: "))
        nickels = int(input("How many nickels?: "))
        pennies = int(input("How many pennies?: "))
        coins = round((quarters * 0.25 + dimes * 0.10 + nickels * 0.05 + pennies * 0.01), 5)

        if order == "espresso" and enough_money(coins, order):
            resources["water"] -= MENU["espresso"]["ingredients"]["water"]
            resources["coffee"] -= MENU["espresso"]["ingredients"]["coffee"]
            change = coins - MENU["espresso"]["cost"]
            print(f"Here is ${change} in change.")
            print("Here is your espresso ☕️ Enjoy!")
        elif order == "latte" and enough_money(coins, order):
            resources["water"] -= MENU["latte"]["ingredients"]["water"]
            resources["milk"] -= MENU["latte"]["ingredients"]["milk"]
            resources["coffee"] -= MENU["latte"]["ingredients"]["coffee"]
            change = coins - MENU["latte"]["cost"]
            print(f"Here is ${change} in change.")
            print("Here is your latte ☕️ Enjoy!")
        elif order == "cappuccino" and enough_money(coins, order):
            resources["water"] -= MENU["cappuccino"]["ingredients"]["water"]
            resources["milk"] -= MENU["cappuccino"]["ingredients"]["milk"]
            resources["coffee"] -= MENU["cappuccino"]["ingredients"]["coffee"]
            change = coins - MENU["cappuccino"]["cost"]
            print(f"Here is ${change} in change.")
            print("Here is your cappuccino ☕️ Enjoy!")
    elif order == "report":
        print(resources)
    else:
        print("Sorry, that's not a valid order")

    order = input("What would you like? (espresso/latte/cappuccino):").lower()