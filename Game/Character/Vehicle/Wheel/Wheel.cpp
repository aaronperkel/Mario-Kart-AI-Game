//
// Created by aaron perkel on 2/21/24.
//

#include "Wheel.h"
#include <math.h>

Wheel::Wheel() : size(0.5), traction(0.5), name("Standard Wheel") {}

Wheel::Wheel(string& name, float size, float traction) : name(name), size(size), traction(traction) {}

string Wheel::get_name() const {
    return name;
}

float Wheel::get_size() const {
    return size;
}

float Wheel::get_traction() const {
    return traction;
}

void Wheel::set_name(string& name) {
    this->name = name;
}

void Wheel::set_size(float input) {
    // only accepts [0.1, 0.2, 0.3...1.0]
    if (input >= 0.1 && input <= 1.0) {
        this->size = floor((input * 10)) / 10;
    }
}

void Wheel::set_traction(float input) {
    // only accepts [0.1, 0.2, 0.3...1.0]
    if (input >= 0.1 && input <= 1.0) {
        this->traction = floor((input * 10)) / 10;
    }
}

std::ostream& operator << (std::ostream& outs, const Wheel& w_obj) {
    outs << " | " << w_obj.name << ": "
         << "Size: "
         << w_obj.get_size()
         << ", Traction: "
         << w_obj.get_traction();
    return outs;
}