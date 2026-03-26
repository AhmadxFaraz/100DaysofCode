class FlightSearch:
    
    def __init__(self):
        import os
        import dotenv
        dotenv.load_dotenv()

        self.API_KEY = os.environ["SERP-API-KEY"]

    def search(self, iataCode):
        from serpapi import GoogleSearch
        from datetime import datetime, timedelta
        from pprint import pprint
        today = datetime.now()
        return_before = today + timedelta(days=180)
        date = today.strftime("%Y-%m-%d")
        inbound = return_before.strftime("%Y-%m-%d")
        params = {
            "engine": "google_flights",
            "departure_id": "DEL",
            "arrival_id": iataCode,
            "currency": "INR",
            "type": "1",
            "outbound_date": date,
            "return_date": inbound,
            "api_key": self.API_KEY
        }

        price_info = 1000000
        search = GoogleSearch(params)
        data = search.get_json()

        try:
            price_info = data["other_flights"][0]["price"]
        except KeyError:
            return None
        finally:
            # print(price_info)
            return {
                "city":iataCode,
                "lowest_price": price_info
            }