#include <iostream>
#include <string>
#include "Car.h"

void Engine::print()
{
        std::cout << "Engine: " << this->version << std::endl;
}

void Wheel::print()
{
        std::cout << "Wheel: " << this->size << "inches" << std::endl;
}

void Chassis::print()
{
        std::cout << "Chassis: " << this->type << std::endl;
}

void Light::print()
{
        std::cout << "Light: Type " << this->type << std::endl;
}

void Body::print()
{
        std::cout << "Body: " << this-> colour << std::endl;
}

void Car::print()
{
        this->eng.print();
        this->w1.print();
        this->w2.print();
        this->w3.print();
        this->w4.print();
        this->chas.print();
        this->l1.print();
        this->l2.print();
        this->l3.print();
        this->l4.print();
        this->l5.print();
        this->l6.print();
        this->l7.print();
        this->l8.print();
        this->l9.print();
        this->l10.print();
        this->bod.print();
}
