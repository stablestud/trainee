#include <iostream>

class FlightBooking
{
public:
        FlightBooking ( int id, int capacity, int reserved );
        void printStatus ( void );
        bool reserveSeats ( int );
        bool cancelReservations ( int );
private:
        int id;
        int capacity;
        int reserved;
};

FlightBooking::FlightBooking ( int id, int capacity, int reserved )
{
        this->id = id;
        if ( reserved <= capacity * 105 / 100 ) {
                this->reserved = reserved;
                this->capacity = capacity;
        } else {
                std::cout << "[" << this->id <<  "] Booking limit reached!" << std::endl;
                this->reserved = 0;
                this->capacity = 0;
                exit ( EXIT_FAILURE );
        }
}

bool FlightBooking::reserveSeats ( int number_of_seats )
{
        if ( this->reserved + number_of_seats <= int ( this->capacity * 105 / 100 ) && this->reserved + number_of_seats >= 0 )
                this->reserved += number_of_seats;
        else {
                std::cout << "Cannot perform this operation!" << std::endl;
                return false;
        }
}

bool FlightBooking::cancelReservations ( int number_of_seats )
{
        if ( this->reserved - number_of_seats <= int ( this->capacity * 105 / 100 ) && this->reserved - number_of_seats >= 0 )
                this->reserved -= number_of_seats;
        else {
                std::cout << "Cannot perform this operation!" << std::endl;
                return false;
        }
}

void FlightBooking::printStatus()
{
        std::cout << "Flight [" << this->id << "] : " << this->reserved << "/" << this->capacity << " (" << static_cast<float> ( this->reserved ) / this->capacity * 100 << "%) seats reserved." << std::endl;
}


int main()
{
        int reserved = 0,
            capacity = 0;

        std::cout << "Provide flight capacity: ";
        std::cin >> capacity;

        if ( std::cin.fail() ) {
                std::cin.ignore();
                std::cin.clear();
                std::cout << "Wrong Input!" << std::endl;
                exit(EXIT_FAILURE);
        }

        std::cout << "Provide number of reserved seats: ";
        std::cin >> reserved;

        if ( std::cin.fail() ) {
                std::cin.ignore();
                std::cin.clear();
                std::cout << "Wrong Input!" << std::endl;
                exit(EXIT_FAILURE);
        }

        FlightBooking booking ( 1, capacity, reserved );

        std::string command = "";

        int errCount = 0;
        while ( command != "quit" ) {
                booking.printStatus();
                std::cout << "What would you like to do?: ";
                std::cin >> command;

                if ( command == "add" ) {
                        int count;
                        std::cin >> count;
                        booking.reserveSeats ( count );
                } else if ( command == "cancel" ) {
                        int count;
                        std::cin >> count;
                        booking.cancelReservations ( count );
                } else if ( command != "quit" ) {
                        std::cout << "Can't perform this operation!" << std::endl;
                        errCount++;
                        if ( errCount >= 5 )
                                command = "quit";
                }
        }

        return 0;
}
// kate: indent-mode cstyle; indent-width 8; replace-tabs on;
