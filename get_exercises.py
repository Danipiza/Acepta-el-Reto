import requests
from bs4 import BeautifulSoup

"""
:type url: string
:rtype: string

Check for a website with an url as parameter.

- If the website exists:
    - Have a Title: returns the title.
    - Otherwise: returns 'No Tittle Found'
- If the website doesnt exists throws an error and returns 'Error'
"""
def get_website_title(url):    
    try:
        response=requests.get(url)
        # Check if the request was successful
            # Otherwise throw an error
        response.raise_for_status()  
        soup=BeautifulSoup(response.content, 'html.parser')

        return soup.title.string.strip() if soup.title else 'No Title Found'
    
    except requests.exceptions.RequestException as e:
        print(f"Error fetching the title from {url}: {e}")
        return 'Error'


"""
:type id: int
:type filename: string
:rtype: None

title calls get_website_title() function.   

Writes, in a given file.txt, a line with the following format:
| <id> | <title> | TODO | [AR_<id>.cpp](<link>) | [AR_<id>.c](<link>) | [AR_<id>.java](<link>) |
"""
def execute_one(id, filename):    
    base_url="https://aceptaelreto.com/problem/statement.php?id="

    with open(filename, 'a') as file:        
        link=f"{base_url}{id}"
        name=get_website_title(link)
        file.write(f"| {id} | [{name[:-19]}]({link}) | TODO | [AR_{id}.cpp](https://github.com/Danipiza/Acepta-el-Reto/tree/main/C%2B%2B/AR_{id}.cpp) | [AR_{id}.c](https://github.com/Danipiza/Acepta-el-Reto/tree/main/C/AR_{id}.c) | [AR_{id}.java](https://github.com/Danipiza/Acepta-el-Reto/tree/main/JAVA/AR_{id}.java) |\n")  
  

def main():     
    exercises_ranges=[100,762]
    filename="output_file.txt"
    for id in range(exercises_ranges[0], exercises_ranges[1]+1):
        execute_one(id, filename)


main()