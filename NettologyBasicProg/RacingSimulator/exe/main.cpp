#include "../dynamicLib/GameInteraction.h"

int main() {
	std::cout << "Welcome to the racing simulator!" << std::endl;
	int racingType, distance, userAnswer;
	Boots boots;
	Broom broom;
	Camel camel;
	Kentaur kentaur;
	Eagle eagle;
	FastestCamel fastestCamel;
	Carpet carpet;

	for (;;) {
		std::vector<std::string> regList;

		racingType = RaceTypes();
		distance = distanceLog();

		Race race(distance);

		userAnswer = regMenu(race, regList);
		while (userAnswer != 3) {
			switch (userAnswer) {
			case(1): {
				while (userAnswer != 0) {
					userAnswer = regBlock(userAnswer, racingType, distance, race, regList, boots, broom, camel, kentaur, eagle, fastestCamel, carpet);
				}
				userAnswer = regMenu(race, regList);

				break;
			}
			case(2):
				race.startRace();
				std::cout << std::endl;
				std::cout << "1.One more race" << std::endl;
				std::cout << "2. Exit" << std::endl;
				std::cout << "Choose: ";
				std::cin >> userAnswer;
				std::cout << std::endl;

				regList.clear();
				race.cleaner();
				if (userAnswer == 2) {
					return userAnswer = 3;
				}
				else {
					racingType = RaceTypes();
					distance = distanceLog();
					userAnswer = regMenu(race, regList);

				}
				break;
			case(3):
			default:
				std::cout << "Something is wrong!";
				break;
			}
		}

	}
	return 0;
}