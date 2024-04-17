//
// Created by aaron perkel on 2/21/24.
//

#ifndef M2OEP_APERKEL_OACOOK_GAME_H
#define M2OEP_APERKEL_OACOOK_GAME_H

#include "Character/Vehicle/Bike.h"
#include "Character/Vehicle/Car.h"
#include "Character/Character.h"
#include "Character/Vehicle/Vehicle.h"
#include "Track/Track.h"
#include <fstream>
#include <iostream>
#include <vector>

class Game {
public:
    Game();
    Game(vector<Track> track, vector<Character> characters);

    // Getters
    vector<Character> get_characters();
    vector<Track> get_tracks() const;

    // Setters
    void set_characters(vector<Character> characters);
    void set_tracks(vector<Track> tracks);

    // Prints list of characters and their current standing
    void print_characters();

    // Changes the character at an index
    bool change_character(Character character, int index);
    bool change_track(Track track, int index);

    void play_game(string& filename);

private:
    void read_game_from_file(string& filename);
    vector<Character> characters;
    vector<Track> tracks;
};


#endif //M2OEP_APERKEL_OACOOK_GAME_H
