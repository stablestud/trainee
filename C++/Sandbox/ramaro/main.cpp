//#include <iostream>
#include <vector>
//void output ( long long unsigned int size, long long unsigned int& foutput, long long unsigned int& foutput_previous );

int main ( void )
{
        //std::cout << "Hello, world!\n";

        /* Evil Code Begins Here */
        std::vector<unsigned long long> array (16384 );

        //unsigned long long foutput = 1, foutput_previous = 0;

        while ( true ) {
                array.resize ( array.size() + 16384 );
                //output ( array.size(), foutput, foutput_previous );
        }

        return 0;
}
/*
void output ( unsigned long long size, unsigned long long &foutput, unsigned long long &foutput_previous )
{
        size /= 8;

        if ( ( size / 1024 ) >= 1 ) { // KiloBytes
                size /= 1024;
                foutput = size;

                if ( ( size / 1024 ) >= 1 ) { // MegaBytes
                        size /= 1024;
                        foutput = size;

                        if ( ( size / 1024 ) >= 1 ) { // GigaBytes
                                size /= 1024;
                                foutput = size;

                                if ( foutput > foutput_previous )
                                        std::cout << foutput << " GB" << std::endl;

                        } else if ( foutput > foutput_previous )
                                std::cout << foutput << " MB" << std::endl;

                } else if ( foutput > foutput_previous )
                        std::cout << foutput << " KB" << std::endl;

        } else if ( foutput > foutput_previous )
                std::cout << foutput << " B" << std::endl;

        foutput_previous = foutput;

}
*/
