#include "Race.h"

Race::Race(double dist) : raceDistance(dist) {}

void Race::addTransport(Transport* vehicle) {
    vehicles.push_back(vehicle);
}

void Race::startRace() {
    std::vector<std::pair<Transport*, int>> results;

    for (auto ts : vehicles) {
        results.emplace_back(ts, ts->CalculateTime(raceDistance));
    }

    std::sort(results.begin(), results.end(), [](const auto& a, const auto& b) {
        return a.second < b.second || (a.second == b.second && a.first->getType() < b.first->getType());
        });

    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||Results|||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
    for (const auto& result : results) {
        if (result.second == 0) {
            std::cout << "Something is wrong! TS speed == 0!" << std::endl;
        }
        else {
            std::cout << result.first->getType() << ": " << result.second << std::endl;
        }
    }
}

void Race::cleaner() {
    vehicles.clear();
}

Race::~Race() = default;
