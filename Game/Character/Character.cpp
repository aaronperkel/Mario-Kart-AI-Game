//
// Created by aaron perkel on 2/21/24.
//

#include "Character.h"

Character::Character() : vehicle(), name("Mario"), place(1), points(0) {}

Character::Character(Vehicle vehicle, string& name, float weight, int place) : vehicle(vehicle), name(name), weight(weight), place(place), points(0){}

string Character::get_name() const {
    return name;
}

Vehicle Character::get_vehicle() const {
    return vehicle;
}

float Character::get_weight() const {
    return weight;
}

int Character::get_place() const {
    return place;
}

int Character::get_points() const {
    return points;
}

void Character::set_name(string name) {
    this->name = name;
}

void Character::set_vehicle(Vehicle vehicle) {
    this->vehicle = vehicle;
}

void Character::set_weight(float weight) {
    this->weight = weight;
}

void Character::set_place(int place) {
    this->place = place;
}

void Character::set_points(int input) {
    this->points = input;
}

void Character::add_points(int input) {
    this->points += input;
}

ostream& operator << (ostream& outs, const Character& c_obj) {
    outs << c_obj.place << ". "
         << c_obj.name << " | " << c_obj.vehicle;

    return outs;

}

bool operator > (const Character& lhs, const Character& rhs) {
    if (lhs.get_points() > rhs.get_points()) {
        return true;
    }
    return false;
}

bool operator < (const Character& lhs, const Character& rhs) {
    if (lhs.get_points() < rhs.get_points()) {
        return true;
    }
    return false;
}

bool operator >= (const Character& lhs, const Character& rhs) {
    if (lhs.get_points() >= rhs.get_points()) {
        return true;
    }
    return false;
}

bool operator <= (const Character& lhs, const Character& rhs) {
    if (lhs.get_points() <= rhs.get_points()) {
        return true;
    }
    return false;
}

bool operator == (const Character& lhs, const Character& rhs) {
    if (lhs.get_points() == rhs.get_points()) {
        return true;
    }
    return false;
}

bool operator != (const Character& lhs, const Character& rhs) {
    if (lhs.get_points() != rhs.get_points()) {
        return true;
    }
    return false;
}

