#include <iostream>
#include <string>
using namespace std;
class Pet {
protected:string name;
public:   Pet(string name) { this -> name = name; }
	    void virtual MakeSound(void) { cout << name << " is silent :(" << endl; }
};
class Dog : public Pet {
public:	Dog(string name) : Pet(name) {}
	void MakeSound(void) { cout << name << " says: Woof!" << endl; }
};
class GermanShepherd : public Dog {
        string x = "sekerum";
public:	GermanShepherd(string name) : Dog(name) {}
	void MakeSound(void) { cout << name << " says: Wuff!" << endl; }
        void rasierApparat ( void )
        {
                cout << x << "Meine Name is Gilett abdi!" << endl;
        }
};
class MastinEspanol : public Dog {
        string x = "KAKA";
public:	MastinEspanol(string name) : Dog(name) {}
	void MakeSound(void) { cout << name << " says: Guau!" << endl; }
        void puta ( void )
        {
                cout << "PUTA LA SUCKA" << x << endl;
        }
};
void PlayWithPet(Pet *pet) {
	pet -> MakeSound();
        if ( GermanShepherd* gs = dynamic_cast<GermanShepherd*>(pet) )
                gs -> rasierApparat();
        if ( MastinEspanol* nigga = dynamic_cast<MastinEspanol*>(pet) )
                nigga -> puta();
}
int main(void) {
	Pet *pet = new Pet("creature");
	Dog *dog = new Dog("Dog");
	GermanShepherd *gs = new GermanShepherd("Hund");
	MastinEspanol *mes = new MastinEspanol("Perro");
	PlayWithPet(pet);
	PlayWithPet(dog);
	PlayWithPet(gs);
	PlayWithPet(mes);
	return 0;
}
