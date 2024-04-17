//
// Created by aaron perkel on 2/21/24.
//

#ifndef M2OEP_APERKEL_OACOOK_VEHICLE_H
#define M2OEP_APERKEL_OACOOK_VEHICLE_H

#include "Wheel/Wheel.h"
#include <vector>

using namespace std;

class Vehicle {
public:
    Vehicle();
    int get_number_of_wheels() const;
    float get_handling() const;
    virtual string get_name() const;
    vector<Wheel> get_wheels() const;
    virtual void set_number_of_wheels(int input);
    virtual void set_handling(float input);
    virtual void set_wheels(vector<Wheel> input);
    void set_name(string name);
    friend std::ostream& operator << (std::ostream& outs, const Vehicle& v_obj);
protected:
    int number_of_wheels;
    float handling;
    vector<Wheel> wheels;
    string name;
};


#endif //M2OEP_APERKEL_OACOOK_VEHICLE_H
