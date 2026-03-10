import datetime as dt
import random as r
import smtplib
import os
from dotenv import load_dotenv

load_dotenv()

now = dt.datetime.now()
weekday = now.weekday()
     
with open("week-09/Quotes-Mailing-Automation/quotes.txt") as quotes:
    all_quotes = quotes.readlines()
    quote = r.choice(all_quotes)
    
# email & password sensitive info... 
EMAIL = os.environ.get("EMAIL_ADDRESS")
PASSWORD = os.environ.get("EMAIL_PASSWORD")

with smtplib.SMTP("smtp.gmail.com", 587) as connection:
    connection.starttls()
    connection.login(EMAIL, PASSWORD)
    connection.sendmail(
        from_addr=EMAIL, 
        to_addrs="ahmadxfaraz@gmail.com", 
        msg=f"Subject: Daily Quotes\n\n{quote}")
