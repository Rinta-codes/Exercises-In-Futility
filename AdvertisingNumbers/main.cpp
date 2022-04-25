// Declare an advertising struct that keeps track of how many ads you’ve shown to readers, 
// what percentage of ads were clicked on by users, and how much you earned on average from each ad that was clicked.

// Read in values for each of these fields from the user.

// Pass the advertising struct to a function that prints each of the values, and then calculates how much you made for that day(multiply all 3 fields together).

#include <iostream>

struct AdsData
{
	long adsDisplayed = 0;
	float adsPercentageClicked = 0.0;
	float avgMoneyPerClick = 0.0;
};

AdsData readAdsData()
{
	AdsData values{0, 0.0, 0.0};
	
	std::cout << "Number of ads displayed today (int): ";
	std::cin >> values.adsDisplayed;

	std::cout << "Percentage of ads clicked (float, between 0 and 100): ";
	std::cin >> values.adsPercentageClicked;

	std::cout << "Average earnings per click (float): ";
	std::cin >> values.avgMoneyPerClick;

	return values;
};

void printAdsData(AdsData values)
{
	std::cout << "Today " << values.adsDisplayed << " ads were displayed, with " << values.adsPercentageClicked
		<< "% of them clicked by users. Average earnings per click are: " << values.avgMoneyPerClick << '\n';

	std::cout.precision(17);
	std::cout << "Your total earnings today are: " << static_cast<double>(values.adsDisplayed) * (values.adsPercentageClicked / 100) * values.avgMoneyPerClick << '\n';
	std::cout << "Your total earnings today are: " << static_cast<double>(static_cast<double>(values.adsDisplayed)
		* static_cast<double>(values.adsPercentageClicked / 100) * static_cast<double>(values.avgMoneyPerClick)) << '\n';
};

int main()
{
	AdsData userValues{ readAdsData() };
	printAdsData(userValues);

	return 0;
};