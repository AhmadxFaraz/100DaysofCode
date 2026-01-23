import pandas

data = pandas.read_csv("Squirrel_Data.csv")

grey_squirrel = data[data["Primary Fur Color"] == "Gray"]
cinnamon_squirrel = data[data["Primary Fur Color"] == "Cinnamon"]
black_squirrel = data[data["Primary Fur Color"] == "Black"]

grey = len(grey_squirrel)
cinnamon = len(cinnamon_squirrel)
black = len(black_squirrel)

new_data = {
    "Fur Color": ["Grey", "Cinnamon", "Black"],
    "Count": [grey, cinnamon, black]
}

New = pandas.DataFrame(new_data)
print(New)

New.to_csv("Insights.csv")