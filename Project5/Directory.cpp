#include "Directory.h"

Directory::Directory(const std::string& filename) : filename(filename) {
    loadEntries();
}

void Directory::loadEntries() {
    std::ifstream file(filename);
    if (file.is_open()) {
        Entry entry;
        while (std::getline(file, entry.companyName, ',') &&
            std::getline(file, entry.owner, ',') &&
            std::getline(file, entry.phone, ',') &&
            std::getline(file, entry.address, ',') &&
            std::getline(file, entry.activity)) {
            entries.push_back(entry);
        }
        file.close();
    }
}

void Directory::saveEntries() const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : entries) {
            file << entry.companyName << "," << entry.owner << "," << entry.phone << ","
                << entry.address << "," << entry.activity << "\n";
        }
        file.close();
    }
}

void Directory::addEntry(const std::string& companyName, const std::string& owner, const std::string& phone,
    const std::string& address, const std::string& activity) {
    Entry newEntry = { companyName, owner, phone, address, activity };
    entries.push_back(newEntry);
    saveEntries();
}

void Directory::searchByCompanyName(const std::string& companyName) const {
    for (const auto& entry : entries) {
        if (entry.companyName == companyName) {
            std::cout << entry.toString() << std::endl;
        }
    }
}

void Directory::searchByOwner(const std::string& owner) const {
    for (const auto& entry : entries) {
        if (entry.owner == owner) {
            std::cout << entry.toString() << std::endl;
        }
    }
}

void Directory::searchByPhone(const std::string& phone) const {
    for (const auto& entry : entries) {
        if (entry.phone == phone) {
            std::cout << entry.toString() << std::endl;
        }
    }
}

void Directory::searchByActivity(const std::string& activity) const {
    for (const auto& entry : entries) {
        if (entry.activity == activity) {
            std::cout << entry.toString() << std::endl;
        }
    }
}

void Directory::displayAllEntries() const {
    for (const auto& entry : entries) {
        std::cout << entry.toString() << std::endl;
    }
}