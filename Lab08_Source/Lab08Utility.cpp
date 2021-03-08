#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


struct Totals
{
	string Total;
	string Median;
	string Mean;
};

void GetFile(vector<double>& DVDPrices, vector<double>& MUSICPrices, vector<double>& TVPrices)
{
	ifstream itemInputs;
	string tempName;
	double tempVal;

	itemInputs.open("input.txt");
	// Inputting the values into the correct vectors until the file has nothing more to output
	while (!itemInputs.fail())
	{
		itemInputs >> tempName;
		itemInputs >> tempVal;
		if (tempName == "DVD")
		{
			DVDPrices.push_back(tempVal);
		}
		else if (tempName == "MUSIC")
		{
			MUSICPrices.push_back(tempVal);
		}
		else if (tempName == "TV")
		{
			TVPrices.push_back(tempVal);
		}
	}
	itemInputs.close();
}

double GetTotal(vector<double> PriceVector)
{
	double totalSum = 0;
	// Summing all of the values in the vector
	for (int i = 0; i < PriceVector.size(); ++i)
	{
		totalSum += PriceVector.at(i);
	}
	return totalSum;
}

double GetMedian(vector<double> PriceVector)
{
	double medianVal;
	int smallestVal;
	double tempVal;
	// Sorting the items in the vector
	for (int i = 0; i < (PriceVector.size() - 1); ++i)
	{
		smallestVal = i;
		for (int j = (i + 1); j < PriceVector.size(); ++j)
		{
			if (PriceVector.at(j) < PriceVector.at(smallestVal))
			{
				smallestVal = j;
			}
		}
		tempVal = PriceVector.at(i);
		PriceVector.at(i) = PriceVector.at(smallestVal);
		PriceVector.at(smallestVal) = tempVal;
	}

	// Checking if the size is even so that I know if i have to average two values or just take one
	if (((PriceVector.size()) % 2) == 0)
	{
		int medianSize;
		medianSize = (PriceVector.size()) / 2;
		medianVal = (PriceVector.at(medianSize) + PriceVector.at(medianSize - 1)) / 2;
	}
	else
	{
		int medianSize;
		medianSize = (PriceVector.size()) / 2;
		medianVal = PriceVector.at(medianSize);
	}

	return medianVal;
}

double GetMean(double itemTotal, vector<double> PriceVector)
{
	double meanVal;
	// Calculating the mean value
	meanVal = itemTotal / (PriceVector.size());
	return meanVal;
}