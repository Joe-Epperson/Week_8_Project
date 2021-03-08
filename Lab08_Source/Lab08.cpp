// Joe Epperson, IV
// jee4cf@umsystem.edu
// 3/8/2021
// CS201L Lab 08

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include "Lab08Utility.h"
using namespace std;

// Structure for the final values
struct Totals
{
	double Total;
	double Median;
	double Mean;
	string errorTotal ;
	string errorMedian;
	string errorMean;
};

int main() 
{
	vector<double> DVDPrices;
	vector<double> MUSICPrices;
	vector<double> TVPrices;
	Totals DVD;
	Totals MUSIC;
	Totals TV;

	// Getting the values from the input file and storing them in their specified vectors
	GetFile(DVDPrices, MUSICPrices, TVPrices);

	// Using if-else statements to determine whether or not to perform a calculation for total, median, and mean
	if (DVDPrices.size() > 0)
	{
		DVD.Total = GetTotal(DVDPrices);
		DVD.Median = GetMedian(DVDPrices);
		DVD.Mean = GetMean(DVD.Total, DVDPrices);
	}
	else
	{
		DVD.errorTotal = "0";
		DVD.errorMedian = "nan";
		DVD.errorMean = "nan";
	}

	if (MUSICPrices.size() > 0)
	{
		MUSIC.Total = GetTotal(MUSICPrices);
		MUSIC.Median = GetMedian(MUSICPrices);
		MUSIC.Mean = GetMean(MUSIC.Total, MUSICPrices);
	}
	else
	{
		MUSIC.errorTotal = "0";
		MUSIC.errorMedian = "nan";
		MUSIC.errorMean = "nan";
	}

	if (TVPrices.size() > 0)
	{
		TV.Total = GetTotal(TVPrices);
		TV.Median = GetMedian(TVPrices);
		TV.Mean = GetMean(TV.Total, TVPrices);
	}
	else
	{
		TV.errorTotal = "0";
		TV.errorMedian = "nan";
		TV.errorMean = "nan";
	}

	ofstream outputFile;

	outputFile.open("output.txt");
	// Using if-else statements to determine what value to output to the output file
	if (DVDPrices.size() > 0)
	{
		outputFile << left << setw(9) << "DVD" << left << setw(9) << DVD.Total << left << setw(9) << DVD.Median << left << setw(9) << DVD.Mean << endl;
	}
	else
	{
		outputFile << left << setw(9) << "DVD" << left << setw(9) << DVD.errorTotal << left << setw(9) << DVD.errorMedian << left << setw(9) << DVD.errorMean << endl;
	}

	if (MUSICPrices.size() > 0)
	{
		outputFile << left << setw(9) << "MUSIC" << left << setw(9) << MUSIC.Total << left << setw(9) << MUSIC.Median << left << setw(9) << MUSIC.Mean << endl;
	}
	else
	{
		outputFile << left << setw(9) << "MUSIC" << left << setw(9) << MUSIC.errorTotal << left << setw(9) << MUSIC.errorMedian << left << setw(9) << MUSIC.errorMean << endl;
	}

	if (TVPrices.size() > 0)
	{
		outputFile << left << setw(9) << "TV" << left << setw(9) << TV.Total << left << setw(9) << TV.Median << left << setw(9) << TV.Mean << endl;
	}
	else
	{
		outputFile << left << setw(7) << "TV" << left << setw(7) << TV.errorTotal << left << setw(7) << TV.errorMedian << left << setw(7) << TV.errorMean << endl;
	}

	outputFile.close();
	
	return 0;
}