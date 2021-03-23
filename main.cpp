#include <iostream>
#include <vector>
#include <iomanip>

#include "include/Stopover.h"
#include "include/utils.h"


std::vector<Stopover *> createStopoverVector(int stopoverQuantity)
{

  std::vector<Stopover *> stopovers;

  for (int i = 0; i < stopoverQuantity; i++)
  {

    int time;
    int price;

    std::cin >> time >> price;

    stopovers.push_back(new Stopover(time, price));
  }

  return stopovers;
}

std::vector<double> createDiscountsVector(int maxStopovers)
{

  std::vector<double> discounts;
  for (int i = 0; i < maxStopovers; i++)
  {
    int discount;
    std::cin >> discount;

    discounts.push_back(discount);
  }
  return discounts;  
}

int main()
{
  Utils *utilityFunctions = new Utils();


  int stopoverQuantity = 0;
  int maxStopovers = 0;
  int discountTime = 0;

  std::cin >> stopoverQuantity >> maxStopovers >> discountTime;

  std::vector<double> discounts = createDiscountsVector(maxStopovers);

  std::vector<Stopover *> stopovers = createStopoverVector(stopoverQuantity);

  double **costs = (double **)malloc(stopoverQuantity * sizeof(double));
  for (int i = 0; i < stopoverQuantity; i++)
  {
    costs[i] = (double *)malloc(stopoverQuantity * sizeof(double));
  }

  for (int i = 0; i < stopoverQuantity; i++)
  {
    utilityFunctions->generateRowOfCosts(stopoverQuantity, maxStopovers, discountTime, stopovers, discounts, i, stopoverQuantity, costs);
  }

  double minimumCost = utilityFunctions->findMinimumValueInColumn(costs, stopoverQuantity - 1, stopoverQuantity);

  std::cout << std::fixed << std::setprecision(2) << minimumCost << std::endl;

  return 0;
}