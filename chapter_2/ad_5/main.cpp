#include <iostream>
#include <functional>
#include <list>
#include <map>

struct billionaire {
	std::string name;
	double dollars;
	std::string country;
};


int main(void) {
	std::list<billionaire> billionaires {
			{"Bill Gates", 86.0, "USA"},
			{"Warren Buffet", 75.6, "USA"},
			{"Jeff Bezos", 72.8, "USA"},
			{"Amancio Ortega", 71.3, "Spain"},
			{"Mark Zuckerberg", 56.0, "USA"},
			{"Carlos Slim", 54.5, "Mexico"},
			{"Bernard Arnault", 41.5, "France"},
			{"Liliane Bettencourt", 39.5, "France"},
			{"Wang Jianlin", 31.3, "China"},
			{"Li Ka-shing", 31.2, "Hong Kong"}
	};

}