//
// Created by aaron perkel on 2/21/24.
//

#include "Car.h"
#include <math.h>

Car::Car() : Vehicle() {
    name = "Standard Car";
    number_of_wheels = 4;
    handling = 0.6;
}

Car::Car(string& name, Wheel wheel, float handling) : Vehicle() {
    set_name(name);
    set_handling(handling);
    number_of_wheels = 4;
    vector<Wheel> wheels;
    for (int i = 0; i < number_of_wheels; i++) {
        wheels.push_back(wheel);
    }
    set_wheels(wheels);
}

void Car::set_number_of_wheels(int input) {
    number_of_wheels = 4;
}

void Car::set_handling(float input) {
    // only accepts [0.2 - 0.7]
    if (input >= 0.2 && input <= 0.7) {
        this->handling = floor(input * 10) / 10;
    }
}

void Car::set_wheels(vector<Wheel> input) {
    if (input.size() == 4) {
        wheels = input;
    }
}
