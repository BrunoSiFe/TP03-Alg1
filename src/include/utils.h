#ifndef UTILS
#define UTILS

#include <vector> 
#include "Stops.h"

class Utils
{
    public:
        Utils();

        void generateRowOfCosts(int stopoverQuantity, int maxStopovers, int discountTime, std::vector<Stops *> stopovers, std::vector<double> discounts, int start, int end, double **costs);
        double findMinimumValueInColumn(double **costsMatrix, int column, int rowsQuantity);
};

#endif