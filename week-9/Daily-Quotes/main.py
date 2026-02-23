import datetime as dt
import random as r
import smtplib

now = dt.datetime.now()
weekday = now.weekday()
     
with open("quotes.txt") as quotes:
    all_quotes = quotes.readlines()
    quote = r.choice(all_quotes)
    
# email & password sensitive info... 
my_email = "anonymous@gmail.com"
password = "ambiguous69"

with smtplib.SMTP("smtp.gmail.com", 587) as connection:
    connection.starttls()
    connection.login(user=my_email, password=password)
    connection.sendmail(
        from_addr=my_email, 
        to_addrs="anonymous@gmail.com", 
        msg=f"Subject: Daily Quotes\n\n{quote}")
