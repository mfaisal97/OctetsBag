#include "OctetBag.h"
#include <iostream>
#include <string>

int main() {

	std::string input;
	do
	{
		std::cout << "Please, input the following command to test the corressponding class\n";
		std::cout << "\"OctetBag\" \tTo demonstrate the Octet Bag class\n";
		std::cout << "\"e\" \t\tTo exist\n";
		std::cin >> input;

		if (input == "OctetBag") {
			std::cout << "\n\nYou have chosen Octet Bag.\n";

			OctetBag uut;
			std::cout << "Please, input the following commands.\n";
			std::cout << "\"Insert {element}\" \tTo insert an element.\n";
			std::cout << "\"Remove {element}\" \tTo remove an element if exists.\n";
			std::cout << "\"Check {element}\" \tTo check if an element exists.\n";
			std::cout << "\"Count {element}\" \tTo count an element occurences.\n";
			std::cout << "\"Print\" \tTo print all elements in the bag.\n";
			std::cout << "\"Exit\" \tTo exist this specific test (or enter any other text).\n\n";
			std::cin >> input;

			while (input == "Insert" || input == "Remove" || input == "Check" || input == "Count" || input == "Print") {
				if (input == "Insert") {
					int ele;
					std::cin >> ele;
					uut.Insert(ele);
					std::cout << "Done\n";
				}
				else if (input == "Remove") {
					int ele;
					std::cin >> ele;
					uut.Remove(ele);
					std::cout << "Done\n";
				}
				else if (input == "Check") {
					int ele;
					std::cin >> ele;
					std::cout << ele << " Exists in Bag:\t" << (uut.HasElement(ele) ? "True" : "False") << "\n";
				} else if (input == "Count") {
					int ele;
					std::cin >> ele;
					std::cout << ele << " Exists in Bag:\t" << (int)uut.HasCount(ele) << " times\n";
				} else if (input == "Print") {
					uut.PrintElements();
				}

				std::cout << "\n";
				std::cin >> input;
			}
			std::cout << "\n\n";
		}

	} while (input != "e" && input != "E");

	return 0;
}