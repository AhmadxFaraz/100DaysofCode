import os
from dotenv import load_dotenv
from datetime import datetime
import requests


today = datetime.now()
date = today.strftime("%Y/%m/%d")
time = today.strftime("%H:%M:%S")

load_dotenv()

X_APP_ID = os.environ["X_APP_ID"]
X_API_KEY = os.environ["X_API_KEY"]
SHEETY_USERNAME = os.environ["SHEETY_USERNAME"]
SHEETY_PASSWORD = os.environ["SHEETY_PASSWORD"]

headers = {
    "Content-Type": "application/json",
    "x-app-id": X_APP_ID,
    "x-app-key": X_API_KEY,
}

url = "https://app.100daysofpython.dev/v1/nutrition/natural/exercise"

exercise = input("What physical activity you did today?\n")
data = {
    "query": exercise,
    "weight_kg": 52,
    "height_cm": 165,
    "age": 18,
    "gender": "male"
}

response = requests.post(url, headers=headers, json=data)
result = response.json()

sheety_endpoint = "https://api.sheety.co/b4b638a156e981328c165485489b7e06/workoutTracking/workouts"

for exercise in result["exercises"]:
    sheet_inputs = {
        "workout": {
            "date": date,
            "time": time,
            "exercise": exercise["name"].title(),
            "duration": exercise["duration_min"],
            "calories": exercise["nf_calories"]
        }
    }

    sheet_response = requests.post(sheety_endpoint, json=sheet_inputs, auth=(SHEETY_USERNAME, SHEETY_PASSWORD))
    print(sheet_response)