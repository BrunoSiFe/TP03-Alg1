#include "../include/Stops.h"

Stops::Stops() : Stops(0, 0)
{
}
Stops::Stops(int time, int price)
{
    this->time = time;
    this->price = price;
}

int Stops::getTime()
{
    return this->time;
}

int Stops::getPrice()
{
    return this->price;
}

void Stops::setTime(int time){
    this->time = time;
}

void Stops::setPrice(int price){
    this->price = price;
}

double Stops::getDiscountedPrice(double discount)
{
    double doublePrice = (double)this->price;
    double priceWithDiscount = doublePrice - (doublePrice * discount);

    return priceWithDiscount;
}