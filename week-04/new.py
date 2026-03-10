word  = ['s', 'o', 'r', 'r','y']
statement = []
for letter in word:
    statement.append(letter)
statement = ''.join(statement)
while True:
    print(statement)
    reply = input("Apology accepted? ")
    if reply == "yes":
        break
print("Nakhre to dekho inke")