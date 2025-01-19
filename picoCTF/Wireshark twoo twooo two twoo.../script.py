import sys
import requests

# Headers for the request, can be copied from your original curl command
headers = {
    'Accept': 'application/json, text/plain, */*',
    'Accept-Language': 'en-GB,en-US;q=0.9,en;q=0.8',
    'Connection': 'keep-alive',
    'Content-Type': 'application/json',
    'Cookie': 'csrftoken=qcTbWmKVtuYXrW9K6tcaa8StBAuJQx4T; sessionid=ovinp47v44z2d0yb5l7431bk7llbfcdq; cf_clearance=I.q3KtdpUrne1mqNlCC.SMeLIkBVkGUSTHz1.Oj0mdo-1737276426-1.2.1.1-eo8MFzwGntqdeLkE.hB8NAf5OKz9lVaNa39PWvrkXZdW6APTMXO37vmrSSeKdg_aDMtTdgWErXInXOqzH00fyrAD8yBzALjWn6ndApThgEWuqoEorGqk7oMdHW6vZHR9yTzhLgI9XmrXbgbciPyT9Pzzuts6PrDUUJPzxHBuOnGSKAIhXlXk1cQcdX5gaH1Booc2wJdO5.8FWLLqPenMK_iZIyxSqkT4P38O0zAzakm0mG5QzNT327y8nF8P4V4TEuNDa_6na59NK_knm8TwXDBY8pSTQktdSsqnPiOQxD4',
    'DNT': '1',
    'Origin': 'https://play.picoctf.org',
    'Referer': 'https://play.picoctf.org/practice/challenge/110?category=4&difficulty=2&page=1&search=&solved=1',
    'Sec-Fetch-Dest': 'empty',
    'Sec-Fetch-Mode': 'cors',
    'Sec-Fetch-Site': 'same-origin',
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/131.0.0.0 Safari/537.36',
    'X-CSRFToken': 'qcTbWmKVtuYXrW9K6tcaa8StBAuJQx4T',
    'sec-ch-ua': '"Chromium";v="131", "Not_A Brand";v="24"',
    'sec-ch-ua-mobile': '?0',
    'sec-ch-ua-platform': '"macOS"',
}

cert_path: str = "/Users/saif.islam/Downloads/Zscaler_Root_Certificate_2048_SHA256.pem"

# Function to send the flag to picoCTF
def send_flag(flag):
    url = 'https://play.picoctf.org/api/submissions/'
    data = {
        "challenge": 110,
        "flag": flag
    }

    try:
        response = requests.post(url, json=data, headers=headers, verify=cert_path)
        response.raise_for_status()
        print(f"Flag: {flag}. Response: {response.json()}")
    except requests.exceptions.RequestException as e:
        print(f"Error submitting flag {flag}: {e}")

# Main function to process the output from tcpdump
def main():
    # Read from stdin (piped input from tcpdump)
    for line in sys.stdin:
        # Check if the line contains a picoCTF flag
        if "picoCTF{" in line:
            flag = line.strip()
            print(f"Found flag: {flag}")
            send_flag(flag)

if __name__ == '__main__':
    main()
