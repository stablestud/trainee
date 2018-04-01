#include <iostream>
#include <string>

int main (void)
{
        std::string sentence;
        std::getline(std::cin,sentence);

        char* csentence = new char[sentence.length()];

        bool mspace = false;
        int slength = 0;

        for (int i = 0; i < sentence.length(); i++,slength++) {
                if (sentence.substr(i,1).compare(" ") == 0) {
                        if (!mspace) {
                                csentence[slength] = sentence[i];
                                mspace = true;
                        } else {
                                slength--;
                        }
                } else {
                        csentence[slength] = sentence[i];
                        mspace = false;
                }
        }

        sentence.clear();

        for (int i = 0; i < slength; i++)
                sentence += csentence[i];

        delete[] csentence;

        std::cout << sentence << std::endl;

        return 0;
}
