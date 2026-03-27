from data_manager import DataManager
from flight_data import FlightData
from flight_search import FlightSearch
from notification_manager import NotificationManager

datamanager = DataManager()
flightdata = FlightData()
flightsearch = FlightSearch()
notification = NotificationManager()

city_price = datamanager.city_price()
latestflightdata = flightdata.plan_trip()

for item in latestflightdata:
    if item["city"] in city_price:
        if int(item["lowest_price"])>=int(city_price[item["city"]]):
            notification.sent_message(item["city"], int(item["lowest_price"]))