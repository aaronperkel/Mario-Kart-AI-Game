//
// Created by aaron perkel on 2/21/24.
//

#ifndef M2OEP_APERKEL_OACOOK_CHARACHTER_H
#define M2OEP_APERKEL_OACOOK_CHARACHTER_H

#include "Vehicle/Vehicle.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Character {
public:

    // Default constructor
    Character();

    // Constructor with place
    Character(Vehicle vehicle, string& name, float weight, int place);

    // Getters
    string get_name() const;
    Vehicle get_vehicle() const;
    float get_weight() const;
    int get_place() const;
    int get_points() const;

    // Setters
    void set_name(string name);
    void set_vehicle(Vehicle vehicle);
    void set_weight(float weight);
    void set_place(int place);
    void set_points(int input);

    void add_points(int input);

    // Overload print operator
    friend ostream& operator << (ostream& outs, const Character& cObj);
    friend bool operator > (const Character& lhs, const Character& rhs);
    friend bool operator < (const Character& lhs, const Character& rhs);
    friend bool operator >= (const Character& lhs, const Character& rhs);
    friend bool operator <= (const Character& lhs, const Character& rhs);
    friend bool operator == (const Character& lhs, const Character& rhs);
    friend bool operator != (const Character& lhs, const Character& rhs);

private:
    string name;
    Vehicle vehicle;
    float weight;
    int place;
    int points;
};


#endif //M2OEP_APERKEL_OACOOK_CHARACHTER_H
