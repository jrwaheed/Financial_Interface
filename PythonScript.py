import requests
import json
import PythonKeys
import finnhub


def callCurrenciesOnUSD():
    url = 'https://v6.exchangerate-api.com/v6/' + PythonKeys.CurrencyAPIKey + \
        '/latest/USD'

    response = requests.get(url)
    data = response.json()
    result = json.dumps(data)

    return result


def callCurrencies(baseCurrency):
    url = 'https://v6.exchangerate-api.com/v6/' + PythonKeys.CurrencyAPIKey + \
        '/latest/' + baseCurrency

    response = requests.get(url)
    data = response.json()
    result = json.dumps(data)

    return result


def callCurrenciesInJson(baseCurrency):
    url = 'https://v6.exchangerate-api.com/v6/' + PythonKeys.CurrencyAPIKey + \
        '/latest/' + baseCurrency

    response = requests.get(url)
    data = response.json()
    return data


def callStockAndOptionsUSD():
    url = "https://stock-and-options-trading-data-provider.p.rapidapi.com \
        /options/aapl"

    headers = {
        "X-RapidAPI-Proxy-Secret": "a755b180-f5a9-11e9-9f69-7bf51e845926",
        "X-RapidAPI-Key": PythonKeys.XRapidAPIKey,
        "X-RapidAPI-Host":
        "stock-and-options-trading-data-provider.p.rapidapi.com"
    }

    response = requests.get(url, headers=headers)

    data = response.json()
    result = json.dumps(data)

    return result


def callFinnHubStockValue(ticker):
    finnhub_client = finnhub.Client(api_key= PythonKeys.FinnHubAPIKey)

    response = finnhub_client.quote(ticker)
    result = json.dumps(response['c'])

    return result
