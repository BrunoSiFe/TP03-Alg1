#ifndef UTILS
#define UTILS

#include <vector> 
#include "Stopover.h"

class Utils
{
    public:
        Utils();

        void generateRowOfCosts(int stopoverQuantity, int maxStopovers, int discountTime, std::vector<Stopover *> stopovers, std::vector<double> discounts, int start, int end, double **costs);
        double findMinimumValueInColumn(double **costsMatrix, int column, int rowsQuantity);
};

#endif