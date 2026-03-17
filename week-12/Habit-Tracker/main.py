import requests
from datetime import datetime
import os
from dotenv import load_dotenv

load_dotenv()
TOKEN = os.getenv("TOKEN")
USERNAME = os.getenv("USERNAME")
GRAPH_ID = "graph1"

pixela_endpoint = "https://pixe.la/v1/users"

user_param = {
    "token":TOKEN,
    "username":USERNAME,
    "agreeTermsOfService":"yes",
    "notMinor":"yes",
}

# user = requests.post(url=pixela_endpoint, json=user_param)
# print(user.text)

graph_endpoint = f"{pixela_endpoint}/{USERNAME}/graphs"

graph_config = {
    "id":GRAPH_ID,
    "name":"Learning Graph",
    "unit":"Minutes",
    "type":"int",
    "color":"momiji",
    "timezone":"Asia/Kolkata"
}

headers = {
    "X-USER-TOKEN":TOKEN
}

# response = requests.post(url=graph_endpoint, json=graph_config, headers=headers)
# print(response1.text)

today = datetime.now()

pixel_creation_endpoint = f"{pixela_endpoint}/{USERNAME}/graphs/{GRAPH_ID}"

pixel_data = {
    "date":today.strftime("%Y%m%d"),
    "quantity":input("How many minutes do you studied today?\n"),
}

response = requests.post(url=pixel_creation_endpoint, json=pixel_data, headers=headers)
print(response.text)

update_endpoint = f"{pixela_endpoint}/{USERNAME}/graphs/{GRAPH_ID}/{today.strftime('%Y%m%d')}"

new_pixel_data = {
    "quantity":"150"
}

# response = requests.put(url=update_endpoint, json=new_pixel_data, headers=headers)
# print(response.text)

delete_endpoint = f"{pixela_endpoint}/{USERNAME}/graphs/{GRAPH_ID}/{today.strftime('%Y%m%d')}"

# response = requests.delete(url=delete_endpoint, headers=headers)
# print(response.text)