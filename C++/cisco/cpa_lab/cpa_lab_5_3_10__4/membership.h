class membership
{
private: 
        std::string name;
        int months;
public:
        unsigned id;

        membership ( unsigned id, std::string name );
        void extend ( int months );
        void cancel ( void );
        void print ( void );
};
