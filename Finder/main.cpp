#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <boost/locale.hpp>
#include <fstream>
#include <stdexcept>
#include <unordered_map>
#include "Table.h"
#include "Spider.h"
#include "INIReader.h"

std::unordered_map<std::string, std::string> readConfig(const std::string& filename) {
    std::unordered_map<std::string, std::string> settings;
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open " + filename);
    }
    std::string line;
    while (std::getline(file, line)) {
        size_t delimiterPos = line.find('=');
        if (delimiterPos != std::string::npos) {
            std::string key = line.substr(0, delimiterPos);
            std::string value = line.substr(delimiterPos + 1);
            key.erase(0, key.find_first_not_of(' '));
            key.erase(key.find_last_not_of(' ') + 1);
            value.erase(0, value.find_first_not_of(' '));
            value.erase(value.find_last_not_of(' ') + 1);
            settings[key] = value;
        }
    }
    file.close();
    if (settings.empty()) {
        throw std::runtime_error("Error (NOT READ) " + filename + " or file is empty.");
    }
    return settings;
}

bool isValidWordCount(const std::vector<std::string>& words) {
    return words.size() >= 3 && words.size() <= 32;
}

int main() {
    std::string Page;
    int Deep;
    try {
        std::unordered_map<std::string, std::string> settings = readConfig("D:/Finder/config.ini");
        std::string host = settings["Host"];
        int port = std::stoi(settings["Port"]);
        std::string database = settings["Database"];
        std::string username = settings["Username"];
        std::string password = settings["Password"];
        Page = settings["StartPage"];
        Deep = std::stoi(settings["RecursionDepth"]);
        std::cout << "Settings loaded successfully:" << std::endl;
        std::cout << "Host: " << host << std::endl;
        std::cout << "Port: " << port << std::endl;
        std::cout << "Database: " << database << std::endl;
        std::cout << "Username: " << username << std::endl;
        std::cout << "StartPage: " << Page << std::endl;
        std::cout << "RecursionDepth: " << Deep << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    boost::locale::generator gen;
    std::locale::global(gen("en_US.UTF-8"));

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    std::ios_base::sync_with_stdio(false);

    create_table();

    std::vector<std::string> searchWords;
    std::string inputSentence;
    std::cout << "Enter search words (e.g., 'white bread', 'red hat', etc.): ";
    std::getline(std::cin, inputSentence);

    std::istringstream iss(inputSentence);
    std::string word;
    while (iss >> word) {
        searchWords.push_back(word);
    }

    if (!isValidWordCount(searchWords)) {
        std::cout << "Only 3 to 32 words." << std::endl;
        return 1;
    }

    crawl_page(Page, searchWords, Deep);

    retrieve_data();

    return 0;
}
