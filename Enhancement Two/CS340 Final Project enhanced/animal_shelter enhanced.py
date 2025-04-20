from pymongo import MongoClient
import pandas as pd
from urllib.parse import quote_plus
import logging

# Enable logging for debugging and auditability
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

# Configuration (Best practice: externalize this in a config file or environment variables in production)
username = 'aacuser'
password = quote_plus('green7')
host = 'nv-desktop-services.apporto.com'
port = 31116
database = 'AAC'
collection_name = 'AnimalShelter'

def get_database_connection():
    """
    Establishes a secure connection to the MongoDB database.
    Returns a MongoClient instance connected to the specified database.
    """
    try:
        connection_string = f'mongodb://{username}:{password}@{host}:{port}/{database}?authSource={database}'
        client = MongoClient(connection_string)
        logging.info("Database connection established successfully.")
        return client[database]
    except Exception as e:
        logging.error(f"Database connection failed: {e}")
        return None

def fetch_animal_data():
    """
    Retrieves all animal records from the AnimalShelter collection and returns them as a DataFrame.
    """
    db = get_database_connection()
    if db is None:
        return pd.DataFrame()

    try:
        animals_cursor = db[collection_name].find()
        animals_list = list(animals_cursor)
        logging.info(f"Fetched {len(animals_list)} animal records.")
        return pd.DataFrame(animals_list)
    except Exception as e:
        logging.error(f"Error fetching animal data: {e}")
        return pd.DataFrame()

# Example usage
if __name__ == "__main__":
    df = fetch_animal_data()
    if not df.empty:
        print(df.head())
    else:
        print("No data retrieved or an error occurred.")