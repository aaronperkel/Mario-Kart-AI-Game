//
// Created by aaron perkel on 2/21/24.
//

#ifndef M2OEP_APERKEL_OACOOK_CAR_H
#define M2OEP_APERKEL_OACOOK_CAR_H


#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car();
    Car(string& name, Wheel wheel, float handling);
    void set_number_of_wheels(int input) override;
    void set_handling(float input) override;
    void set_wheels(vector<Wheel> input) override;
};


#endif //M2OEP_APERKEL_OACOOK_CAR_H
