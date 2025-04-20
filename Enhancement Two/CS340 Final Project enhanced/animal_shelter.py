from pymongo import MongoClient
import pandas as pd
from urllib.parse import quote

# Define your MongoDB connection string
username = 'aacuser'  # Ensure this is correct
password = quote('green7')  # URL encode the password
host = 'nv-desktop-services.apporto.com'  # Your MongoDB server
port = 31116           # Your MongoDB port
database = 'AAC'      # Your actual database name

# Create the connection string
connection_string = f'mongodb://{username}:{password}@{host}:{port}/{database}?authSource={database}'

# Establish the connection
client = MongoClient(connection_string)

# Access the database
db = client[database]

# Example function to fetch animal data
def fetch_animal_data():
    try:
        animals = db["AnimalShelter"].find()  # Use the actual collection name
        return pd.DataFrame(list(animals))
    except Exception as e:
        print(f"Error fetching animal data: {e}")

# Example usage
animal_data = fetch_animal_data()
print(animal_data)