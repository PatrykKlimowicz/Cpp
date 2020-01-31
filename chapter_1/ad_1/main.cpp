#include <iostream>
#include <utility>
#include <tuple>
#include <string>
#include <chrono>
#include <vector>
#include <map>

#define ERROR 1
#define SUCCESS 0

/*
 * Function computing result of division and it's reminder.
 */
std::pair<int, int> divide_remainder(int dividend, int divisor) {
	int result = dividend / divisor;
	int reminder = dividend % divisor;

	return std::make_pair(result, reminder);
}

/*
 * Dummy funtion imitating stock quotes.
 */
std::tuple<std::string, std::chrono::system_clock::time_point, unsigned>
stock_quotes(const std::string &name) {
	return std::make_tuple(name, std::chrono::system_clock::now(), 127);
}

/*
 * Structure which describes an employee.
 * Fields cannot be static and all of them 
 * have to be defined in same structure.
 */
struct employee {
	unsigned id;
	std::string name;
	std::string role;
	unsigned salary;
};

int main(void) {
	/* Old vay with pair */
	const auto result (divide_remainder(16, 3));
	std::cout << "16 / 3 is equal to: 3 times " << result.first << " plus " << result.second << "\n";

	/* Structural bounding with pair */
	const auto [fraction, remainder] = divide_remainder(17, 5);
	std::cout << "17 / 5 is equal to: 5 times " << fraction << " plus " << remainder << "\n";

	/* Structural bounding with tuple */
	const auto [name, time, price] = stock_quotes("KLIMKO");
	std::cout << "stock quote: " << name << ", from: " << std::chrono::system_clock::to_time_t(time) << ", for: " << price << "\n";

	/* Structural bounding with structures and vectors */
	std::vector<employee> employees{
		{1, "John", "Junior Software Developer", 5500}, 
		{2, "Adam", "Software Developer", 7500},
		{3, "Patrick", "Lead Software Developer", 10500}
	};
	for (const auto &[id, name, role, salary] : employees) {
		std::cout << id << ". Name: " << name
				  << " position: " << role
				  << " salary: " << salary << "\n";
	}

	/* Structural bounding with map */
	std::map<std::string, size_t> animal_population { 
		{"humans", 8000000000},
		{"chickens", 17863376000},
		{"sheeps", 1086881528}
	};
	for (const auto &[species, count] : animal_population) {
		std::cout << "Number from map: " << count << "\n";
	}

	/* Similar efect to above before C++17 */
	int reminder;
	std::tie(std::ignore, reminder) = divide_remainder(12, 5);
	std::cout << "12 % 5 = " << reminder << "\n";  

	return SUCCESS;
}
