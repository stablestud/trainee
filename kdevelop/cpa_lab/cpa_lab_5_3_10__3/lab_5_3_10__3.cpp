#include <iostream>
#include <string>

class FlightBooking
{
private:
        int id;
        int capacity;
        int reservedSeats;
        bool fatalErrorOccured;
public:
        FlightBooking ( int id, int capacity )
        {
                if ( id == 0 ) {
                        std::cout << "id can't be zero!" << std::endl;
                        this->fatalErrorOccured = true;
                } else if ( id < 0 ) {
                        std::cout << "id can't be negative!" << std::endl;
                        this->fatalErrorOccured = true;
                } else
                        this->id = id;
                true;

                if ( capacity < 0 ) {
                        std::cout << "The capacity can't be negative!" << std::endl;
                        this->fatalErrorOccured = true;
                } else if ( capacity == 0 ) {
                        std::cout << "The capacity can't be zero!" << std::endl;
                        this->fatalErrorOccured = true;
                } else if ( !this->fatalErrorOccured ) {
                        this->capacity = capacity;
                        std::cout << "Creating flight [" << this->id << "] with capacity of " << this->capacity << std::endl;
                        std::cout << "Don't forget to book some seats." << std::endl;
                }
        }

        ~FlightBooking ( void )
        {
                capacity = 0;
                reservedSeats = 0;
                std::cout << "Flight [" << this->id << "] deleted" << std::endl;
        }

        void print ( void );
        bool checkFatalError ( void );

        int getReservedSeats ( void );
        int getCapacity ( void );

        void addReservedSeats ( int );
        void cancelReservedSeats ( int );
};

int FlightBooking::getReservedSeats ( void )
{
        return this->reservedSeats;
}

int FlightBooking::getCapacity ( void )
{
        return this->capacity;
}

void FlightBooking::addReservedSeats ( int seats )
{
        if ( this->reservedSeats + seats > this->capacity * 105 / 100 || this->reservedSeats + seats < 0 )
                std::cout << "Can't reserve " << seats << " more seats, airplane has only " << this->capacity << " seats." << std::endl;
        else {
                this->reservedSeats += seats;
                std::cout << "Added " << seats << " seats to flight [" << this->id << "]" << std::endl;
        }
}

void FlightBooking::cancelReservedSeats ( int seats )
{
        if ( this->reservedSeats - seats > this->capacity * 105 / 100 || this->reservedSeats - seats < 0 ) {
                std::cout << "Can't cancel " << seats << " seats, number of reserved seats is " << this->reservedSeats << "." << std::endl;
                if ( this->reservedSeats - seats < 0 )
                        std::cout << "Final number of reserved seats can't be negative!" << std::endl;
        } else {
                this->reservedSeats -= seats;
                std::cout << "Cancelled " << seats << " seats from flight [" << this->id << "]" << std::endl;
        }
}

void FlightBooking::print ( void )
{
        std::cout << "Flight [" << this->id << "] : " << this->reservedSeats << "/" << this->capacity << " (" << static_cast<float> ( this->reservedSeats ) / this->capacity * 100 << "%) seats reserved." << std::endl;
}

bool FlightBooking::checkFatalError()
{
        return this->fatalErrorOccured;
}

int main ( void )
{
        std::cout << "Welcome! This is the flight booking system." << std::endl;

        std::string command;

        int errorCount = 0;

        FlightBooking* flights[10];

        do {
                std::cout << std::endl;
                std::cout << "Please select what you want to do:" << std::endl;
                std::cout << "'create [id] [cap]' - create new [id] flight" << std::endl;
                std::cout << "'delete [id]'       - delete [id] flight" << std::endl;
                std::cout << "'add [id] [n]'      - add [n] of reservations to [id] flight" << std::endl;
                std::cout << "'cancel [id] [n]'   - cancel [n] of reservations to [id] flight" << std::endl;
                std::cout << "'print [id]'        - print flight information for flight [id]" << std::endl;
                std::cout << "'quit', 'q'         - to quit this program" << std::endl;

                std::cin >> command;

                if ( std::cin.fail() ) {
                        std::cin.ignore();
                        std::cin.clear();
                        std::cout << "Error: Invalid input" << std::endl;
                        errorCount++;
                        continue;
                }

                if ( command == "create" ) {
                        int id;
                        int cap;

                        std::cin >> id;

                        if ( std::cin.fail() ) {
                                std::cin.ignore();
                                std::cin.clear();
                                std::cout << "Error: Invalid input id" << std::endl;
                                continue;
                        }

                        std::cin >> cap;

                        if ( std::cin.fail() ) {
                                std::cin.ignore();
                                std::cin.clear();
                                std::cout << "Error: Invalid input cap" << std::endl;
                                continue;
                        }

                        flights[id] = new FlightBooking ( id, cap );

                        if ( flights[id]->checkFatalError() )
                                delete flights[id];
                        else
                                std::cout << "Flight [" << id << "] has been created with a capacity of " << flights[id]->getCapacity() << "." << std::endl;
                } else if ( command == "delete" ) {
                        int id;

                        std::cin >> id;

                        if ( std::cin.fail() ) {
                                std::cin.ignore();
                                std::cin.clear();
                                std::cout << "Error: Invalid input id" << std::endl;
                                continue;
                        }

                        delete flights[id];
                } else if ( command == "add" ) {
                        int id;
                        int seats;

                        std::cin >> id;

                        if ( std::cin.fail() ) {
                                std::cin.ignore();
                                std::cin.clear();
                                std::cout << "Error: Invalid input id" << std::endl;
                                continue;
                        }

                        std::cin >> seats;

                        if ( std::cin.fail() ) {
                                std::cin.ignore();
                                std::cin.clear();
                                std::cout << "Error: Invalid input seats" << std::endl;
                                continue;
                        }

                        flights[id]->addReservedSeats ( seats );
                } else if ( command == "cancel" ) {
                        int id;
                        int seats;

                        std::cin >> id;

                        if ( std::cin.fail() ) {
                                std::cin.ignore();
                                std::cin.clear();
                                std::cout << "Error: Invalid input id" << std::endl;
                                continue;
                        }

                        std::cin >> seats;

                        if ( std::cin.fail() ) {
                                std::cin.ignore();
                                std::cin.clear();
                                std::cout << "Error: Invalid input cap" << std::endl;
                                continue;
                        }

                        flights[id]->cancelReservedSeats ( seats );
                } else if ( command == "print" ) {
                        int id;

                        std::cin >> id;

                        if ( std::cin.fail() ) {
                                std::cin.ignore();
                                std::cin.clear();
                                std::cout << "Error: Invalid input id" << std::endl;
                                continue;
                        }

                        flights[id]->print();
                } else if ( !(command != "quit") && !(command != "q")) {
                        std::cout << "Command '" << command << "' not found." << std::endl;
                        errorCount++;
                }

        } while ( command != "quit" && command != "q" && errorCount <= 5 );
        return 0;
}
// kate: indent-mode cstyle; indent-width 8; replace-tabs on;
