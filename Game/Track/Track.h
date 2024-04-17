//
// Created by aaron perkel on 2/21/24.
//

#ifndef M2OEP_APERKEL_OACOOK_TRACK_H
#define M2OEP_APERKEL_OACOOK_TRACK_H

#include <ostream>
#include <string>
using namespace std;

class Track {
public:
    Track();
    Track(string& name, int laps, int difficulty);

    // Getters
    string get_name() const;
    int get_laps() const;
    int get_difficulty() const;

    // Setters
    void set_name(string& name);
    void set_laps(int laps);
    void set_difficulty(int difficulty);

    friend ostream& operator << (ostream& outs, Track t_obj);
private:
    string name;
    int laps;
    int difficulty;
};


#endif //M2OEP_APERKEL_OACOOK_TRACK_H
