#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Map of Hot Bar Starbucks drinks and their abbreviations
    map<string, string> hotBar = {
        {"Caramel Macchiato", "CM"},
        {"Vanilla Latte", "VL"},
        {"Mocha Frappuccino", "MF"},
        {"Iced Green Tea Latte", "IGTL"},
        {"Cappuccino", "C"},
        {"White Chocolate Mocha", "WCM"},
        {"Cafe Americano", "CA"},
        {"Chai Tea Latte", "CTL"},
        {"Java Chip Frappuccino", "JC"},
        {"Caramel Frappuccino", "CF"}
    };

    int score = 0;
    vector<string> askedDrinks;

    cout << "Welcome to the Starbucks Drink Abbreviation Quiz!" << endl;

    for (int i = 0; i < 10; ++i) {
        // Randomly select a drink that hasn't been asked before
        string drink;
        string abbreviation;
        do {
            auto it = hotBar.begin();
            advance(it, rand() % hotBar.size());
            drink = it->first;
            abbreviation = it->second;
        } while (find(askedDrinks.begin(), askedDrinks.end(), drink) != askedDrinks.end());

        askedDrinks.push_back(drink);

        cout << "Q" << (i + 1) << ": Abbreviate \"" << drink << "\": ";
        string userAbbreviation;
        cin >> userAbbreviation;

        if (userAbbreviation == abbreviation) {
            cout << "Correct!" << endl;
            ++score;
        } else {
            cout << "Incorrect. The correct abbreviation is \"" << abbreviation << "\"." << endl;
        }
    }

    cout << "Quiz complete! Your score is: " << score << " out of 10." << endl;

    return 0;
}

