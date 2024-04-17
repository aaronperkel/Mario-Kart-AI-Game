//
// Created by aaron perkel on 2/21/24.
//

#include "Vehicle.h"
#include <math.h>

using namespace std;

Vehicle::Vehicle() : number_of_wheels(4), handling(0.75), name("Standard Vehicle") {
    for (int i = 0; i < number_of_wheels; i++) {
        wheels.push_back(Wheel());
    }
}

int Vehicle::get_number_of_wheels() const {
    return number_of_wheels;
}

float Vehicle::get_handling() const {
    return handling;
}

vector<Wheel> Vehicle::get_wheels() const {
    return wheels;
}

string Vehicle::get_name() const {
    return name;
}

void Vehicle::set_number_of_wheels(int input) {
    if (input == 2 || input == 4) {
        wheels.clear();
        for (int i = 0; i < input; i++) {
            wheels.push_back(Wheel());
        }
    }
}

void Vehicle::set_handling(float input) {
    // only accepts [0.1, 0.2, 0.3...1.0]
    if (input >= 0.1 && input <= 1.0) {
        this->handling = floor(input * 10) / 10;
    }
}

void Vehicle::set_wheels(vector<Wheel> input) {
    if (input.size() == number_of_wheels) {
        this->wheels = input;
    }
}

void Vehicle::set_name(std::string name) {
    this->name = name;
}

std::ostream& operator << (std::ostream& outs, const Vehicle& v_obj) {
    outs << v_obj.name
         << ": Number of Wheels: "
         << v_obj.get_number_of_wheels()
         << v_obj.wheels[0]
         << ", Maneuverability: "
         << v_obj.get_handling();
    return outs;
}