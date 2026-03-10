import pandas

data = pandas.read_csv("nato_phonetic_alphabet.csv")
phonetic_dict = {row.letter:row.code for (index, row) in data.iterrows()}

invalid = True

while invalid:
    word = input("Enter a word: ").upper()

    try:
        new = [phonetic_dict[letter] for letter in word]
    except KeyError:
        invalid = True
        print("Sorry, only letters in the alphabet please.")
    else:
        print(new)
        invalid = False