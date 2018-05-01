class membership
{
private: 
        unsigned id;
        std::string name;
        int months = 0;
public:
        membership ( unsigned id, std::string name );
        void extend ( int months );
        void cancel ( void );
};
