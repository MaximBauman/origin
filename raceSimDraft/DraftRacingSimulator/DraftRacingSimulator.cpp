#include <iostream>
#include <vector>
#include <algorithm>

class Transport {
public:
	virtual ~Transport(){};
	virtual double CalculateTime(double distance) const = 0;
	virtual std::string getType() const = 0;
private:
	int speed;
	std::string type;
	std::string name;
};

class GroundTransport : public Transport {
public:
	GroundTransport(int speed, double timetorelax, double relaxtime, double relaxtime2, double relaxtime3) : speed(speed), timeToRelax(timetorelax), relaxTime(relaxtime), relaxTime_2(relaxtime2), relaxTime_3(relaxtime3) {};
	double CalculateTime(double distance) const override {
		double travelTime = distance / speed;
		int relaxPeriods = travelTime / timeToRelax;
		if (relaxPeriods == 0) {
			return travelTime;
		}
		else if (relaxPeriods == 1) {
			return travelTime += relaxTime;
		}
		else if (relaxPeriods == 2) {
			return travelTime += relaxTime + relaxTime_2;
		}
		else {
			return travelTime += relaxTime + relaxTime_2 + relaxTime_3 * (relaxPeriods - 2);
		}
	}
private:
	int speed;
	double timeToRelax;
	double relaxTime;
	double relaxTime_2;
	double relaxTime_3;
};

class AirTransport : public Transport {
public: 
	AirTransport(int speed) : speed(speed) {};
	double CalculateTime(double distance) const override{
		double flyTime = this->AirReduce(distance) / speed;
		return flyTime;
		//return this->AirReduce(distance);
	}
	virtual double AirReduce(double dist) const = 0;
private:
	int speed;
};

class Carpet : public AirTransport {
public:
	Carpet() : AirTransport(10) {};
	double AirReduce(double dist) const override {
		if (dist < 1000) {
			return dist;
		}
		else if (1000 <= dist < 5000) {
			return dist * 0.97;
		}
		else if (5000 <= dist < 10000) {
			return dist * 0.9;
		}
		else {
			return dist * 0.95;
		}
	}
	std::string getType() const override {
		return "Carpet";
	}
};

class Eagle : public AirTransport {
public:
	Eagle() : AirTransport(8) {};
	double AirReduce(double dist) const override {
		return dist * 0.94;
	}
	std::string getType() const override {
		return "Eagle";
	}
};

class Broom : public AirTransport {
public:
	Broom() : AirTransport(20) {};
	double AirReduce(double dist) const override{
		int coeff = dist / 1000;
		return dist - ((dist / 100) * coeff);
	}
	std::string getType() const override {
		return "Broom";
	}
	~Broom(){};
};

class Camel : public GroundTransport {
public: 
	Camel() : GroundTransport(10, 30, 5, 8, 8){}
	std::string getType() const override {
		return "Camel";
	}
};

class FastestCamel : public GroundTransport {
public:
	FastestCamel() : GroundTransport(40, 10, 5, 6.5, 8) {};
	std::string getType() const override {
		return "FastestCamel";
	}
};
class Kentaur : public GroundTransport {
public:
	Kentaur() :GroundTransport(15, 8, 2, 2, 2) { };
	std::string getType() const override {
		return "Kentaur";
	}
};
class Boots : public GroundTransport {
public:
	Boots() : GroundTransport(6, 60, 10, 5, 5) {};
	std::string getType() const override {
		return "Boots";
	}
};


class Race {
public:
	Race(double dist) : raceDistance(dist) {};
	void addTransport(Transport* vehicle) {
		vehicles.push_back(vehicle);
	} 
	void startRace() {
		std::vector<std::pair<Transport*, int>> results;

		for (auto ts : vehicles) {
			results.emplace_back(ts, ts->CalculateTime(raceDistance));
		}

		std::sort(results.begin(), results.end(), [](const auto& a, const auto& b) {
			return a.second < b.second || (a.second == b.second && a.first->getType() < b.first->getType());
			});

		std::cout << "Results: " << std::endl;
		for (const auto& result : results) {
			std::cout << result.first->getType() << ": " << result.second << std::endl;
		}
	}
	void cleaner() {
		vehicles.clear();
	}
private:
	double raceDistance;
	std::vector<Transport*> vehicles;
};


void print_time(Transport* transport, double distance) {
	double time = transport->CalculateTime(distance);
	std::string name = transport->getType();
	std::cout << name << time << std::endl;
}

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

int regMenu(Race &some, std::vector<std::string> tsList) {
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

int subRegMenu(int raceType, int dist, Race &ts, std::vector<std::string> regList) {
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

int regBlock(int answ, int raceType, int dist, Race &race, std::vector<std::string> &regList, Boots &boots, Broom &broom, Camel &camel,
Kentaur &kentaur,
Eagle &eagle,
FastestCamel &fastestCamel,
Carpet &carpet) {
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

	while (true) {
		std::vector<std::string> regList;

		racingType = RaceTypes();
		distance = distanceLog();

		Race race(distance);

		userAnswer = regMenu(race, regList);
		while (userAnswer != 3) {
			switch (userAnswer) {
			case(1):{
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
				if(userAnswer == 2) {
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
	}