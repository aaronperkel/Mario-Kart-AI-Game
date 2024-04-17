//
// Created by aaron perkel on 2/21/24.
//

#include "Track.h"

Track::Track() : name("Standard Track"), laps(3), difficulty(0){}

Track::Track(string& name, int laps, int difficulty) : name(name), laps(laps), difficulty(difficulty) {}

string Track::get_name() const {
    return name;
}

int Track::get_laps() const {
    return laps;
}

int Track::get_difficulty() const {
    return difficulty;
}

void Track::set_name(std::string &name) {
    this->name = name;
}

void Track::set_laps(int laps) {
    this->laps = laps;
}

void Track::set_difficulty(int difficulty) {
    this->difficulty = difficulty;
}

ostream& operator << (ostream& outs, Track t_obj) {
    string difficulty_stars = "";
    for (int i = 0; i < t_obj.get_difficulty(); i++){
        difficulty_stars = difficulty_stars + "*";
    }

    outs << t_obj.get_name() << " | "
         << t_obj.get_laps() << " Laps"
         << " | "
         << "Difficulty: " << difficulty_stars;

    return outs;
}