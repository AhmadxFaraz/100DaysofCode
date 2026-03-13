import os
import requests
from twilio.rest import Client
from dotenv import load_dotenv

load_dotenv()

account_sid = os.environ["TWILIO_ACCOUNT_SID"]
auth_token = os.environ["TWILIO_AUTH_TOKEN"]
my_number = os.environ["MY_NUMBER"]
twilio_number = os.environ["TWILIO_NUMBER"]

OWM_Endpoint = "https://api.openweathermap.org/data/2.5/forecast"
API_KEY = os.environ["TWILIO_API_KEY"]
LAT=27.897321368693245 
LON=78.0841561004687

parameters = {
    "lat":LAT,
    "lon":LON,
    "appid":API_KEY,
    "cnt": 4,
}

response = requests.get(url=OWM_Endpoint, params=parameters)
response.raise_for_status()
data = response.json()

will_rain = False

for hour_data in data["list"]:
    condition_code = hour_data["weather"][0]["id"]
    if int(condition_code) > 700:
        will_rain = True

if will_rain:
    client = Client(account_sid, auth_token)
    message = client.messages.create(
        body="It's going to rain today. Remeber to bring an ☔️",
        from_=twilio_number,
        to=my_number,
    )