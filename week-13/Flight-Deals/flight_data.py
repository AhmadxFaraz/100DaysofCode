class FlightData:
    #This class is responsible for structuring the flight data.
    def plan_trip(self):
        from datetime import datetime, timedelta
        from flight_search import FlightSearch
        from data_manager import DataManager

        today = datetime.now()

        datamanager = DataManager()
        flightsearch = FlightSearch()

        sheet_data = datamanager.city_price()
        flight_data = []

        for iataCode in sheet_data:
            try:
                flight_data.append(flightsearch.search(iataCode))
            except AttributeError:
                continue
        return flight_data