#include <iostream>

int simple_hash_generator(std::string string, int size);

int find_substring_light_rabin_karp(std::string string, std::string sub_string);

int main() {
	std::string user_string, word;
	std::cout << "Hi! Enter a string without spaces and capital letters, if you want to exite - enter the command exite in the console: " << std::endl;
	std::cin >> user_string;

	do {
		std::cout << "Enter the word you want to find: ";
		std::cin >> word;
		int result_index = find_substring_light_rabin_karp(user_string, word);
		if (result_index == -1) {
			std::cout << "Substring \"" << word << "\" not found" << std::endl;
		}
		else {
			std::cout << "Substring \"" << word << "\" index: " << result_index << std::endl;
		}
	} while (word != "exit");

	return 0;
}

int simple_hash_generator(std::string string, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += static_cast<int>(string[i]);
	}
	return sum;
}


int find_substring_light_rabin_karp(std::string string, std::string sub_string) {
	int sub_size = sub_string.length();

	int sub_hash = simple_hash_generator(sub_string, sub_size);
	int hash = 0;
	for (int i = 0; i <= string.length() - sub_size; i++) {
		if (i == 0) {
			hash = simple_hash_generator(string, sub_size);
		}
		else {
			hash -= static_cast<int>(string[i - 1]);
			hash += static_cast<int>(string[i + sub_size - 1]);
		}
		bool corrected = true;
		if (hash != sub_hash) {
			continue;
		}
		else {
			for (int j = 0; j < sub_size; j++) {
				if (static_cast<int>(string[i + j]) != static_cast<int>(sub_string[j])) {
					corrected = false;
					break;
				}
			}
			if (corrected) {
				return i;
			}
			else {
				return -1;
			}
		}
	}
	return -1;
}