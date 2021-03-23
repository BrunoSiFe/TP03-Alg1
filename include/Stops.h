#ifndef STOPOVER
#define STOPOVER

class Stops
{
    private:
        int time;
        int price;

    public:

        Stops();
        Stops(int time, int price);

        int getTime();
        int getPrice();

        void setTime(int time);
        void setPrice(int price);

        double getDiscountedPrice(double discount);
};

#endif