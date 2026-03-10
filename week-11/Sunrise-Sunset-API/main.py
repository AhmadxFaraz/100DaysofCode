import requests

parameters = {
    "lat":27.91609,
    "lng":78.07617,
    "tzid":"Asia/Kolkata"
}
response = requests.get("https://api.sunrise-sunset.org/json", params=parameters)
response.raise_for_status()
data = response.json()
print(data["results"])