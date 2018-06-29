#include <iostream>
#include <string>

using namespace std;

class ShopItemOrder
{
private:
        string itemName;
        unsigned int itemCount;
        float itemPrice;
        float totalPrice;
        bool newCount;
        void updateOrder ( void );
public:
        ShopItemOrder ( string, unsigned int, float );
        int getItemCount ( void );
        float getTotalPrice ( void );
        float getItemPrice ( void );
        string getItemName ( void );
        void setItemCount ( int );
        void Print ( void );
};

ShopItemOrder::ShopItemOrder ( string itemName, unsigned int itemCount, float itemPrice )
{
        this -> itemName = itemName;
        this -> itemCount = itemCount;
        this -> itemPrice = itemPrice;
        this -> newCount = true;
}

void ShopItemOrder::updateOrder ( void )
{
        std::cout << "Updating Price." << std::endl;
        this -> newCount = false;
        this -> totalPrice = this -> itemPrice * this -> itemCount;
}

int ShopItemOrder::getItemCount ( void )
{
        return this -> itemCount;
}

float ShopItemOrder::getItemPrice ( void )
{
        return this -> itemPrice;
}

string ShopItemOrder::getItemName ( void )
{
        return this -> itemName;
}

void ShopItemOrder::setItemCount ( int itemCount )
{
        this -> itemCount = itemCount;
        this -> newCount = true;
}

float ShopItemOrder::getTotalPrice ( void )
{
        if ( this -> newCount )
                this -> updateOrder();
        return this -> totalPrice;
}

void ShopItemOrder::Print ( void )
{
        std::cout << "You want to buy " << this -> getItemCount() << " " << this -> getItemName() << "'s for " << this -> getTotalPrice() << "€" << std::endl;
}

int main ( void )
{
        ShopItemOrder apple ( "apple", 4, 2.1f );
        apple.Print();
        apple.setItemCount(6);
        apple.Print();
        apple.Print();
        apple.Print();
        apple.Print();
        return 0;
}
