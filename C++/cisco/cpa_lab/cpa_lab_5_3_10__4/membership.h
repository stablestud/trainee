#include <string>

class membership
{
private: 
        unsigned id;
        std::string name;
        int months;
public:
        membership ( unsigned id = 0, std::string name = "" );
        void extend ( int months );
        void cancel ( void );
};
