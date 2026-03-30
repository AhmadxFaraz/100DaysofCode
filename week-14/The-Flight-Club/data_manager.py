class DataManager:
    #This class is responsible for talking to the Google Sheet.

    def __init__(self):
        from pprint import pprint
        import os
        import dotenv
        import requests
        dotenv.load_dotenv()

        SHEETY_USERNAME = os.environ["SHEETY_USERNAME"]
        SHEETY_PASSWORD = os.environ["SHEETY_PASSWORD"]

        sheety_url = "https://api.sheety.co/b4b638a156e981328c165485489b7e06/flightDeals/users"
        url = "https://api.sheety.co/b4b638a156e981328c165485489b7e06/flightDeals/prices"

        response = requests.get(url=url,auth=(SHEETY_USERNAME, SHEETY_PASSWORD))
        self.results = response.json()

        sheety_response = requests.get(url=sheety_url, auth=(SHEETY_USERNAME, SHEETY_PASSWORD))
        self.email_list = sheety_response.json()

    def city_price(self):
        return {
            item["iataCode"]: item["lowestPrice"]
            for item in self.results["prices"]
        }
    def user_emails(self):
        return {
            item["whatIsYourName?"]: item["email"]
            for item in self.email_list["users"]
        }