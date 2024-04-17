//
// Created by aaron perkel on 2/25/24.
//

#include "Game/Track/Track.h"
#include "Game/Game.h"

bool test_play_game(Game& game);
bool test_change_character(Game game);
bool test_change_track(Game game);

int main() {
    Game game;
    string filename = "original_game.txt";
    game.play_game(filename);
    cout << "====== GAME RUN COMPLETE ======" << endl;

    cout << "========== Starting Tests ==========\n" << endl;
    if (test_play_game(game)) {
        cout << "PASSED all play game tests" << endl;
    }
    if (test_change_character(game)) {
        cout << "PASSED all change character tests" << endl;
    }
    if (test_change_track(game)) {
        cout << "PASSED all change track tests" << endl;
    }
    return 0;
}

bool test_play_game(Game& game) {
    bool passed = true;
    if (game.get_tracks()[0].get_name() != "Moo Moo Meadows") {
        passed = false;
        cout << "FAILED moo moo meadows test" << endl;
    }
    if (game.get_tracks().size() != 3) {
        passed = false;
        cout << "FAILED number of tracks test" << endl;
    }
    return passed;
}

bool test_change_character(Game game) {
    bool passed = true;
    Character c;
    game.change_character(c, 0);

    if (game.get_characters()[0].get_name() != "Mario") {
        passed = false;
        cout << "FAILED change character test" << endl;
    }
    return passed;
}

bool test_change_track(Game game) {
    bool passed = true;
    Track t;
    game.change_track(t, 0);

    if (game.get_tracks()[0].get_name() != "Standard Track") {
        passed = false;
        cout << "FAILED change character test" << endl;
    }
    return passed;
}