from datetime import datetime
import requests
import smtplib
import time

MY_EMAIL = "anonymous"
MY_PASSWORD = "encrypted"

MY_LAT = 27.91609
MY_LNG = 78.07617

def is_iss_overhead():
    response = requests.get(url="http://api.open-notify.org/iss-now.json")
    response.raise_for_status()

    data = response.json()

    longitude = float(data["iss_position"]["longitude"])
    latitude = float(data["iss_position"]["latitude"])

    if(MY_LAT-2<latitude<MY_LAT+2 and MY_LNG-2<longitude<MY_LNG+2):
        return True

def is_night():
    parameters = {
    "lat":MY_LAT,
    "lng":MY_LNG,
    "tzid":"Asia/Kolkata"
}
    response = requests.get("https://api.sunrise-sunset.org/json", params=parameters)
    response.raise_for_status()
    data = response.json()
    sunrise = int(data["results"]["sunrise"].split(":")[0])
    sunset = int(data["results"]["sunset"].split(":")[0])
    
    time_now =datetime.now()

    if time_now >= sunset or time_now <= sunrise:
        return True

while True:
    time.sleep(60)
    if is_iss_overhead() and is_night():
        connection = smtplib.SMTP("smtp.gmail.com")
        connection.starttls()
        connection.login(MY_EMAIL, MY_PASSWORD)
        connection.sendmail(
            from_addr=MY_EMAIL,
            to_addrs=MY_EMAIL,
            msg="Subject:Look Up!!!\n\nThe ISS is above you in the sky."
        )