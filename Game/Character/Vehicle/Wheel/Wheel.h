//
// Created by aaron perkel on 2/21/24.
//

#ifndef M2OEP_APERKEL_OACOOK_WHEEL_H
#define M2OEP_APERKEL_OACOOK_WHEEL_H

#include <iostream>

using namespace std;

class Wheel {
public:
    Wheel();
    Wheel(string& name, float size, float traction);
    string get_name() const;
    float get_size() const;
    float get_traction() const;
    void set_name(string& name);
    void set_size(float input);
    void set_traction(float input);
    friend std::ostream& operator << (std::ostream& outs, const Wheel& w_obj);
protected:
    string name;
    float size;
    float traction;
};


#endif //M2OEP_APERKEL_OACOOK_WHEEL_H
