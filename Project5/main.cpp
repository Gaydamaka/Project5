#include <iostream>
#include "Directory.h"

int main() {
    Directory directory("directory.txt");
    int choice;

    do {
        std::cout << "1. Add Entry\n";
        std::cout << "2. Search by Company Name\n";
        std::cout << "3. Search by Owner\n";
        std::cout << "4. Search by Phone\n";
        std::cout << "5. Search by Activity\n";
        std::cout << "6. Display All Entries\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string companyName, owner, phone, address, activity;
            std::cout << "Enter company name: ";
            std::cin.ignore();
            std::getline(std::cin, companyName);
            std::cout << "Enter owner: ";
            std::getline(std::cin, owner);
            std::cout << "Enter phone: ";
            std::getline(std::cin, phone);
            std::cout << "Enter address: ";
            std::getline(std::cin, address);
            std::cout << "Enter activity: ";
            std::getline(std::cin, activity);
            directory.addEntry(companyName, owner, phone, address, activity);
            break;
        }
        case 2: {
            std::string companyName;
            std::cout << "Enter company name to search: ";
            std::cin.ignore();
            std::getline(std::cin, companyName);
            directory.searchByCompanyName(companyName);
            break;
        }
        case 3: {
            std::string owner;
            std::cout << "Enter owner to search: ";
            std::cin.ignore();
            std::getline(std::cin, owner);
            directory.searchByOwner(owner);
            break;
        }
        case 4: {
            std::string phone;
            std::cout << "Enter phone to search: ";
            std::cin.ignore();
            std::getline(std::cin, phone);
            directory.searchByPhone(phone);
            break;
        }
        case 5: {
            std::string activity;
            std::cout << "Enter activity to search: ";
            std::cin.ignore();
            std::getline(std::cin, activity);
            directory.searchByActivity(activity);
            break;
        }
        case 6: {
            directory.displayAllEntries();
            break;
        }
        case 0:
            std::cout << "Exiting the program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}