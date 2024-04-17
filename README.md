# Mario Kart AI Game
Aaron Perkel and Owen Cook

This is a continuation of our [M2OEP](https://github.com/uvmcs2300s2024/M2OEP-aperkel-oacook). It takes the game output and creates an AI description of the game (as if the AI were a commentator). It also uses a Google Image web scraper to get images of the characters. Also, the game is now created at random with each run, rather than just one sample game.

The program is still run using C++. [main.cpp](main.cpp) now calls a python file that creates a [random game](game_generator.py), and then it plays the game [(play_game())](Game/Game.cpp). After that, the output file is [given to Google Gemini AI](text_generator.py) to describe the game using python. C++ passes the number of characters to the Game Generator, and the top 3 characters at the end of the race to the AI Text Generator. All of this is [on a silk server](https://go.uvm.edu/mariokart) and the C++ file is run using [PHP](index.html).

We plan to implement graphics in M4.

After completing this project, the grade we think is justified is 100/100 because we worked to integrate 5 different languages and 2 new APIs/python libraries to further our project.

# Prerequisites:
* Python 3.9+
* The Python SDK for the Gemini API
  * ```pip install -q -U google-generativeai```
* python-dotenv
  * ```pip install python-dotenv```
* icrawler
  * ```pip install icrawler```
  * this required bs4 and lxml (owen had it, aaron did not)
    * ```pip install bs4```
    * ```pip install lxml```
* Google AI API Key
  * https://aistudio.google.com/app/apikey
  * Place this key in your `.env` file (see `.env.example`)

# Instructions
* Go to https://go.uvm.edu/mariokart
* Click on the `New Game` button
* NOTE: beacause of silk server permissions with installing python packages, the server runs all commands in a virtual environment. (See [run.php line 3](run.php)). Below is how we run [main.cpp](main.cpp) from the command line, but it will not work as the code is currently designed to run on a silk server.
  * Compile with ```g++ -std=c++17 -o main main.cpp Game/Game.cpp Game/Character/Character.cpp Game/Character/Vehicle/Vehicle.cpp Game/Character/Vehicle/Wheel/Wheel.cpp Game/Character/Vehicle/Bike.cpp Game/Character/Vehicle/Car.cpp Game/Track/Track.cpp```
  * Run with ```./main```

# Known Bugs
* Website - Some browsers during testing would cache the website and not update its contents when a new game is run. We could not find a workaround for this. This causes a few bugs:
  * If the text updates but the images do not, try opening the page in an incognito browser.
  * If you run the game and nothing updates, try opening the page in an incognito browser.
* Website - image crawler
  *  If the text updates but one or more images disappear, this means the image crawler did not succeed. Try running a new game.


# Citations

| Issue                                              | Location                         | Source                                                                                                              |
|----------------------------------------------------|----------------------------------|---------------------------------------------------------------------------------------------------------------------|
| Trying to prevent website from caching old results | [index.html line 8](index.html)  | [Stack Overflow](https://stackoverflow.com/questions/16716695/prevent-caching-of-html-page)                         |
| HTML CSS "Alert boxes"                              | [index.html line 12](index.html) | [W3Schools](https://www.w3schools.com/howto/tryit.asp?filename=tryhow_css_danger)                                   |
| Display .txt file in HTML | [index.html line 36](index.html) | [Stack Overflow](https://stackoverflow.com/questions/4642681/simple-way-to-display-data-in-a-txt-file-on-a-webpage) |
| Gemini AI API | [text_generator.py line 1](text_generator.py) | [Gemini API Documentation](https://ai.google.dev/tutorials/python_quickstart#generate_text_from_text_inputs)        |
