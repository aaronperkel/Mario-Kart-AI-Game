//
// Created by aaron perkel on 2/15/24.
//

#include "Game/Game.h"

using namespace std;

int main() {

    Game game;

    // Calls the new game randomizer
    string command = "/opt/python/python-3.10/bin/python3.10 game_generator.py 12";
    system(command.c_str());

    string filename = "new_game.txt";
    game.play_game(filename);

    // Calls the AI text generator
    command = "/opt/python/python-3.10/bin/python3.10 text_generator.py";
    system(command.c_str());

    // Calls the image scraper with the top 3 characters
    string podium_characters;
    vector<Character> all_characters = game.get_characters();
    for (int i = 0 ; i < 3; i++) {
       podium_characters += all_characters[i].get_name() + "::";
    }
    command = "/opt/python/python-3.10/bin/python3.10 google_image_search.py " + podium_characters;
    system(command.c_str());

    return 0;
}
