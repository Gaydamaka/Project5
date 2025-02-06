#pragma once
#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Directory {
public:
    Directory(const std::string& filename);
    void addEntry(const std::string& companyName, const std::string& owner, const std::string& phone,
        const std::string& address, const std::string& activity);
    void searchByCompanyName(const std::string& companyName) const;
    void searchByOwner(const std::string& owner) const;
    void searchByPhone(const std::string& phone) const;
    void searchByActivity(const std::string& activity) const;
    void displayAllEntries() const;

private:
    struct Entry {
        std::string companyName;
        std::string owner;
        std::string phone;
        std::string address;
        std::string activity;

        std::string toString() const {
            return "Company: " + companyName + ", Owner: " + owner + ", Phone: " + phone +
                ", Address: " + address + ", Activity: " + activity;
        }
    };

    std::vector<Entry> entries;
    std::string filename;

    void loadEntries();
    void saveEntries() const;
};

#endif