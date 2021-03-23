#include "../include/Stopover.h"

Stopover::Stopover() : Stopover(0, 0)
{
}
Stopover::Stopover(int time, int price)
{
    this->time = time;
    this->price = price;
}

int Stopover::getTime()
{
    return this->time;
}

int Stopover::getPrice()
{
    return this->price;
}

void Stopover::setTime(int time){
    this->time = time;
}

void Stopover::setPrice(int price){
    this->price = price;
}

double Stopover::getDiscountedPrice(double discount)
{
    double doublePrice = (double)this->price;
    double priceWithDiscount = doublePrice - (doublePrice * discount);

    return priceWithDiscount;
}