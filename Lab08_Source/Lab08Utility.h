#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
#pragma once

void GetFile(vector<double>& DVDPrices, vector<double>& MUSICPrices, vector<double>& TVPrices);

double GetTotal(vector<double> PriceVector);

double GetMedian(vector<double> PriceVector);

double GetMean(double itemTotal, vector<double> PriceVector);
