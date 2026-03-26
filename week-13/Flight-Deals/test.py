import os
from pprint import pprint
import dotenv
import datetime
dotenv.load_dotenv()

API_KEY = os.environ["SERP-API-KEY"]

from serpapi import GoogleSearch

params = {
    "engine": "google_flights",
    "departure_id": "DEL",
    "arrival_id": "TRV",
    "currency": "INR",
    "type": "2",
    "outbound_date": "2026-03-30",
    "api_key": API_KEY
}

search = GoogleSearch(params)
results = search.get_json()["price_insights"]

pprint(results)