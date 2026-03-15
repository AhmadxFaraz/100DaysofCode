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
STOCK_NAME = "TSLA"
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




    ## STEP 1: Use https://www.alphavantage.co/documentation/#daily
# When stock price increase/decreases by 5% between yesterday and the day before yesterday then print("Get News").
#TODO 1. - Get yesterday's closing stock price. Hint: You can perform list comprehensions on Python dictionaries. e.g. [new_value for (key, value) in dictionary.items()]
#TODO 2. - Get the day before yesterday's closing stock price
#TODO 3. - Find the positive difference between 1 and 2. e.g. 20 -420 = -20, but the positive difference is 20. Hint: https://www.w3schools.com/python/ref_func_abs.asp
#TODO 4. - Work out the percentage difference in price between closing price yesterday and closing price the day before yesterday.
#TODO 5. - If TODO4 percentage is greater than 5 then print("Get News").
#TODO 6. - Instead of printing ("Get News"), use the News API to get articles related to the COMPANY_NAME.
#TODO 7. - Use Python slice operator to create a list that contains the first 3 articles. Hint: https://stackoverflow.com/questions/509211/understanding-slice-notation
#TODO 8. - Create a new list of the first 3 article's headline and description using list comprehension.
#TODO 9. - Send each article as a separate message via Twilio. 
#Optional TODO: Format the message like this: 
"""
TSLA: 🔺2%
Headline: Were Hedge Funds Right About Piling Into Tesla Inc. (TSLA)?. 
Brief: We at Insider Monkey have gone over 821 13F filings that hedge funds and prominent investors are required to file by the SEC The 13F filings show the funds' and investors' portfolio positions as of March 31st, near the height of the coronavirus market crash.
or
"TSLA: 🔻2%
Headline: Were Hedge Funds Right About Piling Into Tesla Inc. (TSLA)?. 
Brief: We at Insider Monkey have gone over 821 13F filings that hedge funds and prominent investors are required to file by the SEC The 13F filings show the funds' and investors' portfolio positions as of March 31st, near the height of the coronavirus market crash.
"""
