class NotificationManager:
    def sent_message(self, city, price):
        import os
        from dotenv import load_dotenv
        from datetime import datetime, timedelta
        import smtplib

        load_dotenv()

        today = datetime.now()
        return_before = today + timedelta(days=180)

        outbound = today.strftime("%Y-%m-%d")
        inbound = return_before.strftime("%Y-%m-%d")

        EMAIL = os.environ.get("EMAIL_ADDRESS")
        PASSWORD = os.environ.get("EMAIL_PASSWORD")

        with smtplib.SMTP("smtp.gmail.com", 587) as connection:
            connection.starttls()
            connection.login(EMAIL, PASSWORD)
            connection.sendmail(
                from_addr=EMAIL, 
                to_addrs="ahmadxfaraz@gmail.com", 
                msg=f"Subject: Flight Deal Alert!!!\n\nLow price alert! Only Rs.{price} to fly from DEL to {city}, on {outbound} until {inbound}.")