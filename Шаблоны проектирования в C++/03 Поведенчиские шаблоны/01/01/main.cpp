#include <iostream>
#include <fstream>
#include <memory>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class ConsoleCommand : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << "ConsoleCommand: " << message << std::endl;
    }
};

class FileLogCommand : public LogCommand {
public:
    FileLogCommand(const std::string& rec) : filename(rec) {}

    void print(const std::string& message) override {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open()) {
            file << "FileLogCommand: " << message << std::endl;
            file.close();
        } else {
            std::cerr << "Error: Unable to open file " << filename << std::endl;
        }
    }

private:
    std::string filename;
};

void print(LogCommand& logCommand, const std::string& message) {
    logCommand.print(message);
}

int main() {

    ConsoleCommand console;
    FileLogCommand fileLog("logs.txt");

    print(console, "Hello from console!");
    print(fileLog, "Hello from file!");

    return 0;
}



