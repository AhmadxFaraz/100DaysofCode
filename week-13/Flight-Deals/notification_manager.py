class NotificationManager:
    #This class is responsible for sending notifications with the deal flight details.
    def sent_message(self, city, price):
        import requests
        from twilio.rest import Client
        import os
        from dotenv import load_dotenv
        from datetime import datetime, timedelta

        load_dotenv()

        today = datetime.now()
        return_before = today + timedelta(days=180)

        outbound = today.strftime("%Y-%m-%d")
        inbound = return_before.strftime("%Y-%m-%d")

        #Twilio
        account_sid = os.environ["TWILIO_ACCOUNT_SID"]
        auth_token = os.environ["TWILIO_AUTH_TOKEN"]
        my_number = os.environ["MY_NUMBER"]
        twilio_whatsapp_number = os.environ["TWILIO_WHATSAPP_NUMBER"]

        client = Client(account_sid, auth_token)
        message = client.messages.create(
        from_=f"whatsapp:{twilio_whatsapp_number}",
        body=f"Low price alert! Only ₹{price} to fly from DEL to {city}, on {outbound} until {inbound}.",
        to=f"whatsapp:{my_number}"
        )