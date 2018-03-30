#include <iostream>

class FlightBooking
{
public:
        FlightBooking ( int id, int capacity, int reserved );
        void printStatus();
private:
        int id, capacity, reserved;
};

void FlightBooking::printStatus()
{
        std::cout << "Flight [" << this->id << "] : " << this->reserved << "/" << this->capacity << "(" << static_cast<float> (this->reserved) / this->capacity * 100 << "%) seats taken" << std::endl;
}

FlightBooking::FlightBooking ( int id, int capacity, int reserved )
{
        this->id = id;
        this->capacity = capacity;
        this->reserved = reserved;
}

int main()
{
        int reserved = 0,
            capacity = 0;
        std::cout << "Provide flight capacity: ";
        std::cin >> capacity;
        std::cout << "Provide number of reserved seats: ";
        std::cin >> reserved;
        FlightBooking booking ( 1, capacity, reserved );
        booking.printStatus();
        return 0;
}
// kate: indent-mode cstyle; indent-width 8; replace-tabs on;
