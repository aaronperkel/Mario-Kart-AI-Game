//
// Created by aaron perkel on 2/21/24.
//

#include "Bike.h"
#include <math.h>

Bike::Bike() : Vehicle() {
    name = "Standard Bike";
    number_of_wheels = 2;
    handling = 0.85;
}

Bike::Bike(string& name, Wheel wheel, float handling) : Vehicle() {
    set_name(name);
    set_handling(handling);
    number_of_wheels = 2;
    vector<Wheel> wheels;
    for (int i = 0; i < number_of_wheels; i++) {
        wheels.push_back(wheel);
    }
    set_wheels(wheels);
}

void Bike::set_number_of_wheels(int input) {
    number_of_wheels = 2;
}

void Bike::set_handling(float input) {
    // only accepts [0.5 - 1.0]
    if (input >= 0.5 && input <= 1.0) {
        this->handling = floor(input * 10) / 10;
    }
}

void Bike::set_wheels(vector<Wheel> input) {
    if (input.size() == 2) {
        wheels = input;
    }
}