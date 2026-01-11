from menu import Menu
from coffee_maker import CoffeeMaker
from money_machine import MoneyMachine
menu = Menu()
coffee_maker = CoffeeMaker()
money_machine = MoneyMachine()
while True:
    choice = input("What would you like? ").lower()
    if choice == "report":
        coffee_maker.report()
        money_machine.report()
    elif choice != "report":
        drink = menu.find_drink(choice)

    if choice != "report" and drink:
        print(f"You chose {drink.name}, it costs ${drink.cost}")
        if coffee_maker.is_resource_sufficient(drink):
            money_machine.make_payment(drink.cost)
            coffee_maker.make_coffee(drink)