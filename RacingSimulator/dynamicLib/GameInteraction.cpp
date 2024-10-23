#include "GameInteraction.h"

int RaceTypes() {
	int raceType;
	std::cout << "1. Race for ground transport" << std::endl;
	std::cout << "2. Race for air transport" << std::endl;
	std::cout << "3. Race for ground and air transport" << std::endl;
	std::cout << "Set race type: ";
	std::cin >> raceType;
	std::cout << std::endl;
	return raceType;
}

double distanceLog() {
	double dist;
	std::cout << "Set race distance: ";
	std::cin >> dist;
	std::cout << std::endl;
	return dist;
}

int regMenu(Race& some, std::vector<std::string> tsList) {
	int usAnsw;
	if (tsList.size() < 2) {
		std::cout << "Need registrate min 2 vehicles" << std::endl;
		std::cout << "1. Registration" << std::endl;
		std::cout << "Choose: ";
		std::cin >> usAnsw;
		std::cout << std::endl;
		return usAnsw;
	}
	else {
		std::cout << "1. Registration" << std::endl;
		std::cout << "2. Start race" << std::endl;
		std::cout << "Choose: ";
		std::cin >> usAnsw;
		std::cout << std::endl;
		return usAnsw;
	}
}

int subRegMenu(int raceType, int dist, Race& ts, std::vector<std::string> regList) {
	int userAnsw;
	std::vector<std::string> tsList = regList;
	switch (raceType)
	{
	case(1):
		std::cout << "Race for ground transport. ";
		break;
	case(2):
		std::cout << "Race for air transport. ";
		break;
	case(3):
		std::cout << "Race for ground and air transport. ";
		break;
	default:
		break;
	}
	std::cout << "Distance: " << dist << std::endl;
	std::cout << "Registred transport: ";
	for (int i = 0; i < regList.size(); i++) {
		std::cout << regList[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "1. Boots" << std::endl;
	std::cout << "2. Broom" << std::endl;
	std::cout << "3. Camel" << std::endl;
	std::cout << "4. Kentaur" << std::endl;
	std::cout << "5. Eagle" << std::endl;
	std::cout << "6. FastestCamel" << std::endl;
	std::cout << "7. Carpet" << std::endl;
	std::cout << "0. End registration" << std::endl;
	std::cout << "Set transport or 0 for end registration: ";
	std::cin >> userAnsw;
	std::cout << std::endl;
	return userAnsw;
}

int regBlock(int answ, int raceType, int dist, Race& race, std::vector<std::string>& regList, Boots& boots, Broom& broom, Camel& camel,
	Kentaur& kentaur,
	Eagle& eagle,
	FastestCamel& fastestCamel,
	Carpet& carpet) {
	answ = subRegMenu(raceType, dist, race, regList);
	while (answ != 0) {

		if (raceType == 1) {
			switch (answ)
			{
			case(0):
				break;
			case(1): {
				race.addTransport(&boots);
				std::cout << boots.getType() << " succsess registr!" << std::endl;
				regList.push_back("Boots");
				break;
			}
			case(3): {
				race.addTransport(&camel);
				std::cout << camel.getType() << " succsess registr!" << std::endl;
				regList.push_back("Camel");
				break;
			}
			case(4): {
				race.addTransport(&kentaur);
				std::cout << kentaur.getType() << " succsess registr!" << std::endl;
				regList.push_back("Kentaur");
				break;
			}
			case(6): {
				race.addTransport(&fastestCamel);
				std::cout << fastestCamel.getType() << " succsess registr!" << std::endl;
				regList.push_back("FastestCamel");

				break;
			}
			default:
				std::cout << "Can't register this vehicle type!" << std::endl;
				break;
			}
		}
		else if (raceType == 2) {
			switch (answ)
			{
			case(0):
				break;
			case(2): {
				race.addTransport(&broom);
				std::cout << broom.getType() << " succsess registr!" << std::endl;
				regList.push_back("Broom");
				break;
			}
			case(5): {
				race.addTransport(&eagle);
				std::cout << eagle.getType() << " succsess registr!" << std::endl;
				regList.push_back("Eagle");
				break;
			}
			case(7): {
				race.addTransport(&carpet);
				std::cout << carpet.getType() << " succsess registr!" << std::endl;
				regList.push_back("Carpet");
				break;
			}
			default:
				std::cout << "Can't registr this venchicle type!" << std::endl;
				break;
			}
		}
		else {
			switch (answ)
			{
			case(1): {
				race.addTransport(&boots);
				std::cout << boots.getType() << " succsess registr!" << std::endl;
				regList.push_back("Boots");
				break;
			}
			case(2): {
				race.addTransport(&broom);
				std::cout << broom.getType() << " succsess registr!" << std::endl;
				regList.push_back("Broom");
				break;
			}
			case(3): {
				race.addTransport(&camel);
				std::cout << camel.getType() << " succsess registr!" << std::endl;
				regList.push_back("Camel");
				break;
			}
			case(4): {
				race.addTransport(&kentaur);
				std::cout << kentaur.getType() << " succsess registr!" << std::endl;
				regList.push_back("Kentaur");
				break;
			}
			case(5): {
				race.addTransport(&eagle);
				std::cout << eagle.getType() << " succsess registr!" << std::endl;
				regList.push_back("Eagle");

				break;
			}
			case(6): {
				race.addTransport(&fastestCamel);
				std::cout << fastestCamel.getType() << " succsess registr!" << std::endl;
				regList.push_back("FastestCamel");

				break;
			}
			case(7): {
				race.addTransport(&carpet);
				std::cout << carpet.getType() << " succsess registr!" << std::endl;
				regList.push_back("Carpet");
				break;
			}
			case(0):
				break;
			default:
				std::cout << "Can't registr this venchicle type!" << std::endl;
				break;
			}
		}
		answ = subRegMenu(raceType, dist, race, regList);

	}
	return 0;
}

