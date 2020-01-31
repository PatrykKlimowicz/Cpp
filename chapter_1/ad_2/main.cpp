#include <iostream>
#include <map>

#define ERROR 1
#define SUCCESS 0

int main(void) {
	/* Map my name's letters to integers */
	std::map<char, int> character_map{
		{'P', 0},
		{'a', 1},
		{'t', 2},
		{'r', 3},
		{'y', 4},
		{'k', 5}
	};

	if (const auto it (character_map.find('r')); it != character_map.end()) {
		std::cout << "Character found on position: " << it->second << ".\n";
	} else {
		std::cout << "There's no such a character.\n";
		return ERROR;
	}
	// std::cout << (*it).first << "\n"; // Error, "it" isn't avaiable here

	switch (char c (getchar()); c) {
		case 'w':
				std::cout << "Move up.\n";
			break;
		case 's':
			std::cout << "Move down.\n";
		break;
		case 'a':
			std::cout << "Move left.\n";
		break;
		case 'd':
			std::cout << "Move right.\n";
		break;

		default:
			std::cout << "Wrong input.\n";
			break;
	}

	return SUCCESS;
}
