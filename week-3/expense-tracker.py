print("Welcome to your Personal Expense Calculator")

FILENAME = "expenses.txt"

# Ensure file exists with default budget
try:
    with open(FILENAME, "x") as f:
        f.write("Monthly Budget = 2000\n")
except FileExistsError:
    pass


while True:   # do-while simulation starts here
    print("\nWhat do you want to do?")
    print("1. Edit your Monthly Budget")
    print("2. Add an Expense")
    print("3. View Expense History")
    print("4. Exit")

    choice = input("Enter your choice (1-4): ")

    if choice == "1":
        new_budget = input("Enter new Monthly Budget: ")
        with open(FILENAME, "w") as f:
            f.write(f"Monthly Budget = {new_budget}\n")
        print("Monthly budget updated.")

    elif choice == "2":
        description = input("Describe the expense: ")
        amount = input("Amount spent: ")

        with open(FILENAME, "a") as f:
            f.write(f"{description} = {amount}\n")

        print("Expense added successfully.")

    elif choice == "3":
        print("\nExpense History:\n")
        with open(FILENAME, "r") as f:
            print(f.read())

    elif choice == "4":
        print("Exiting. Go do something productive.")
        break   # this is the “while condition becomes false”

    else:
        print("Invalid choice. Try numbers 1 to 4.")
