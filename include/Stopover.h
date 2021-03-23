#ifndef STOPOVER
#define STOPOVER

class Stopover
{
    private:
        int time;
        int price;

    public:

        Stopover();
        Stopover(int time, int price);

        int getTime();
        int getPrice();

        void setTime(int time);
        void setPrice(int price);

        double getDiscountedPrice(double discount);
};

#endif