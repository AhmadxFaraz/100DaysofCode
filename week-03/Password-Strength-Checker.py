print("Welcome to Password Strength Checker")
password = input("Enter you password: ")
p_l = len(password)
if(p_l<6):
    print("Weak password")
elif(p_l<10):
    print("Medium password")
else :
    print("Strong password")
    