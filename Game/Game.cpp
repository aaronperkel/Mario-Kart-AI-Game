//
// Created by aaron perkel on 2/21/24.
//

#include "Game.h"
#include <random>
#include <algorithm>
#include <string>

void Game::read_game_from_file(std::string &filename) {
    characters.clear();
    tracks.clear();
    ifstream in_file("GameFiles/" + filename);

    // Number of tracks
    int num_tracks;
    string new_line_char;
    if(in_file) {
        in_file >> num_tracks;
        getline(in_file, new_line_char);
    }


    // Loop number of tracks times getting:
    // Name, laps, and difficulty
    for (int i = 0; i < num_tracks; i++) {
        string name;
        int laps, difficulty;

        getline(in_file, name);
        in_file >> laps;
        getline(in_file, new_line_char);
        in_file >> difficulty;
        getline(in_file, new_line_char);

        Track new_track(name, laps, difficulty);
        tracks.push_back(new_track);
    }

    // Number of characters
    int num_racers;
    if(in_file) {
        in_file >> num_racers;
        getline(in_file, new_line_char);
    }

    // Loop num characters times (assign place in order of read)
    // Name, weight
    for (int i = 0; i < num_racers; i++) {

        // Getting character name and weight (place is just order read in)
        string character_name;
        double weight;
        getline(in_file, character_name);
        in_file >> weight;
        getline(in_file, new_line_char);

        // Getting character vehicle
        // Type of vehicle
        string vehicle_type;
        getline(in_file, vehicle_type);
        // Converting vehicle type to lowercase for comparing later
        for (char& c : vehicle_type) {
            c = (char)tolower(c);
        }

        // Getting name of vehicle and handling
        string vehicle_name;
        float handling;
        getline(in_file, vehicle_name);
        in_file >> handling;
        getline(in_file, new_line_char);

        // Getting Wheels
        string wheel_name;
        float wheel_size, wheel_traction;
        getline(in_file, wheel_name);
        in_file >> wheel_size;
        getline(in_file, new_line_char);
        in_file >> wheel_traction;
        getline(in_file, new_line_char);

        // Load variables into wheel
        Wheel new_wheel(wheel_name, wheel_size, wheel_traction);

        // Checks for vehicle type and adds the character to the game
        if (vehicle_type == "bike") {
            Bike new_bike(vehicle_name, new_wheel, handling);
            Character new_character(new_bike, character_name, weight, i + 1);
            characters.push_back(new_character);
        } else if (vehicle_type == "car") {
            Car new_car(vehicle_name, new_wheel, handling);
            Character new_character(new_car, character_name, weight, i + 1);
            characters.push_back(new_character);
        }
    }
}

Game::Game() {}

Game::Game(vector<Track> tracks, vector<Character> characters) : characters(characters), tracks(tracks) {}

// Returns characters in order of highest to lowest points
vector<Character> Game::get_characters() {
    // https://www.geeksforgeeks.org/bubble-sort/
    int i, j;
    for (i = 0; i < characters.size() - 1; i++) {
        for (j = 0; j < characters.size() - i - 1; j++) {
            if (characters[j] < characters[j + 1]) {
                swap(characters[j], characters[j + 1]);
            }
        }
    }
    return characters;
}

vector<Track> Game::get_tracks() const{
    return tracks;
}

void Game::set_characters(vector<Character> characters) {
    this->characters = characters;
}

void Game::set_tracks(vector<Track> tracks) {
    this->tracks = tracks;
}

void Game::print_characters() {
    for (Character c : characters) {
        cout << c << endl;
    }
}

bool Game::change_character(Character character, int index) {
    if (index >= 0 && index < characters.size()) {
        characters[index] = character;
        return true;
    } else {
        return false;
    }
}

bool Game::change_track(Track track, int index) {
    if (index >= 0 && index < tracks.size()) {
        tracks[index] = track;
        return true;
    } else {
        return false;
    }
}

void Game::play_game(string& filename) {
    read_game_from_file(filename);
    int round = 1;
    ofstream file;
    file.open("game.txt");
    file << "=================== MARIO KART ===================" << endl << endl;

    for (Track& t : tracks) {
        file << "Round " << round << ": " << t << endl;
        vector<Character> temp_vec;

        // https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
        auto rd = random_device {};
        auto rng = default_random_engine {rd()};
        shuffle(begin(characters), end(characters), rng);

        // changes the players place based on where they are in the vector
        // after shuffle
        for (int i = 0; i < characters.size(); i++) {
            characters[i].set_place(i + 1);
        }

        int points_earned;
        for (Character& c : characters) {
            if (c.get_place() == 1) {
                points_earned = 15;
            } else if (c.get_place() == 2) {
                points_earned = 12;
            } else if (c.get_place() == 3) {
                points_earned = 10;
            } else if (c.get_place() == 4) {
                points_earned = 9;
            } else if (c.get_place() == 5) {
                points_earned = 8;
            } else if (c.get_place() == 6) {
                points_earned = 7;
            } else if (c.get_place() == 7) {
                points_earned = 6;
            } else if (c.get_place() == 8) {
                points_earned = 5;
            } else if (c.get_place() == 9) {
                points_earned = 4;
            } else if (c.get_place() == 10) {
                points_earned = 3;
            } else if (c.get_place() == 11) {
                points_earned = 2;
            } else if (c.get_place() == 12) {
                points_earned = 1;
            }
            c.add_points(points_earned);

            file << c.get_place() << ". "
                 << c.get_name()
                 << " | " << c.get_vehicle().get_name()
                 << " | " << c.get_vehicle().get_wheels()[0].get_name()
                 << " | POINTS EARNED: " << to_string(points_earned)
                 << " | TOTAL POINTS: " << c.get_points()
                 << endl;
        }
        round++;
        file << endl;
    }

    Character highest_points = characters[0];
    for (int i = 0; i < characters.size(); i++) {
        if (characters[i + 1] > highest_points) {
            highest_points = characters[i + 1];
        }
    }

    file << "============ RESULTS ============" << endl;
    file << highest_points.get_name() << " WINS!!!" << endl << endl;


    for (Character c : this->get_characters()) {
        file << c.get_name() << " - " << c.get_points() << " points" << endl;
    }
    file.close();
}
