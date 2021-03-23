#include "../include/utils.h"

Utils::Utils(){};

double Utils::findMinimumValueInColumn(double **costsMatrix, int column, int rowsQuantity)
{
  if (column < 0)
    return 0;

  double min = costsMatrix[0][column];
  for (int row = 1; row < rowsQuantity; row++)
  {
    double cost = costsMatrix[row][column];
    if (cost < min && cost > 0)
    {
      min = cost;
    }
  }

  return min;
}

void Utils::generateRowOfCosts(int stopoverQuantity, int maxStopovers, int discountTime, std::vector<Stopover *> stopovers, std::vector<double> discounts, int start, int end, double **costs)
{
  Utils *utilityFunctions = new Utils();
  int timeElapsed = 0;
  double currentDiscount = 0;
  int quantityStops = 0;
  double previousCost = utilityFunctions->findMinimumValueInColumn(costs, start - 1, stopoverQuantity);

  for (int j = start; j < end; j++)
  {
    Stopover *stopover = stopovers.at(j);

    if (quantityStops < maxStopovers)
    {
      currentDiscount += discounts.at(quantityStops);
    }
    else
    {
      currentDiscount = 0;
    }

    costs[start][j] = previousCost + stopover->getDiscountedPrice(currentDiscount / 100);
    previousCost = costs[start][j];
    quantityStops++;
    timeElapsed += stopover->getTime();

    if (timeElapsed >= discountTime)
    {
      currentDiscount = 0;
      timeElapsed = 0;
      quantityStops = 0;
    }
  }
}
