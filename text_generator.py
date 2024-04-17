# https://ai.google.dev/tutorials/python_quickstart#generate_text_from_text_inputs
import google.generativeai as genai
from dotenv import dotenv_values

env_vars = dotenv_values(".env")
key = env_vars.get("API_KEY")
genai.configure(api_key=key)
model = genai.GenerativeModel('gemini-pro')

input_text = ''
with open('game.txt') as f:
	for line in f:
		input_text += line + '\n'

request = "briefly describe this game of mario kart as if you were the commentator: " + input_text

response = model.generate_content(request)
file_txt = open('results.txt', 'w')
file_txt.write(response.text)
