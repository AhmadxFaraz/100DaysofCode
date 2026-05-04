import os
from dotenv import load_dotenv
from datetime import date, timedelta
import requests 
from twilio.rest import Client

load_dotenv()

#Twilio
account_sid = os.environ["TWILIO_ACCOUNT_SID"]
auth_token = os.environ["TWILIO_AUTH_TOKEN"]
my_number = os.environ["MY_NUMBER"]
twilio_whatsapp_number = os.environ["TWILIO_WHATSAPP_NUMBER"]

#Stocks
COMPANY_NAME = "Tesla Inc"
STOCK_API_KEY = os.environ["STOCK_API_KEY"]
NEWS_API_KEY = os.environ["NEWS_API_KEY"]

#EndPoints
STOCK_ENDPOINT = "https://www.alphavantage.co/query"
NEWS_ENDPOINT = "https://api.marketaux.com/v1/news/all"

today = date.today()
yesterday = today - timedelta(days=1)

parameters = {
    "function":"TIME_SERIES_DAILY",
    "symbol":"TSLA",
    "apikey":STOCK_API_KEY
}

response = requests.get(url=STOCK_ENDPOINT, params=parameters)
data = response.json()

time_series = data["Time Series (Daily)"]
closing_prices = [value["4. close"] for (key, value) in time_series.items()]
YSP = float(closing_prices[0])

DBYSP = float(closing_prices[1])

if (YSP-DBYSP)>0:
    dir="🔺"
elif (YSP-DBYSP)<=0:
    dir="🔻"

diff = abs(YSP-DBYSP)

percent_diff = (diff/DBYSP)*100

Get_News = False
if percent_diff>1:
    Get_News = True

news_params = {
    "api_token":NEWS_API_KEY,
    "symbols":"TSLA"
} 

news = requests.get(url=NEWS_ENDPOINT, params=news_params)
news_data = news.json()["data"]

titles = [article["title"] for article in news_data]
descriptions = [article["description"] for article in news_data]
urls = [article["url"] for article in news_data]

if Get_News:
    for i in range(0,3):
        client = Client(account_sid, auth_token)
        message = client.messages.create(
        from_=f"whatsapp:{twilio_whatsapp_number}",
        body=f"TSLA: {dir}{percent_diff:.2f}%\nHeadline: {titles[i]}\nBrief: {descriptions[i]}\nURL: {urls[i]}",
        to=f"whatsapp:{my_number}"
        )
#comment