#ifndef CAR_H
#define CAR_H

#include <string>

class Engine {
private:
        float version;
public:
        Engine(float v) : version(v) {};
        void print();
};

class Wheel {
private:
        unsigned size;
public:
        Wheel(unsigned s) : size(s) {};
        void print();
};

class Chassis {
private:
        std::string type;
public:
        Chassis(std::string t) : type(t) {};
        void print();
};

class Light {
private:
        unsigned type;
public:
        Light(unsigned t) : type(t) {};
        void print();
};

class Body {
private:
        std::string colour;
public:
        Body(std::string c) : colour(c) {};
        void print();
};

class Car {
private:
        Engine eng;
        Wheel w1, w2, w3, w4;
        Chassis chas;
        Light l1, l2, l3, l4, l5, l6, l7, l8, l9, l10;
        Body bod;
public:
        Car() : Car(1.f, 16U, 16U, 16U, 16U, "Normal", 1U, 1U, 2U, 2U, 3U, 3U, 4U, 4U, 5U, 5U, "Black") {};
        Car(float eng, unsigned w1, unsigned w2, unsigned w3, unsigned w4,
            std::string chas, unsigned l1, unsigned l2, unsigned l3, unsigned l4,
            unsigned l5, unsigned l6, unsigned l7, unsigned l8, unsigned l9,
            unsigned l10, std::string bod)
            : eng(eng), w1(w1), w2(w2), w3(w3), w4(w4), chas(chas),
            l1(l1), l2(l2), l3(l3), l4(l4), l5(l5), l6(l6), l7(l7),
            l8(l8), l9(l9), l10(l10), bod(bod) {};
        void print();
};


#endif /* CAR_H */
