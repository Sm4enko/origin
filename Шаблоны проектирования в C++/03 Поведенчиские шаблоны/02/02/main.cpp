#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
    virtual ~Observer() = default;
};

class O {
private:
    std::vector<Observer*> observers;
public:
    void add(Observer* observer) {
        observers.push_back(observer);
    }

    void remove(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObserversWarning(const std::string& message) const {
        for (const auto& observer : observers) {
            observer->onWarning(message);
        }
    }

    void notifyObserversError(const std::string& message) const {
        for (const auto& observer : observers) {
            observer->onError(message);
        }
    }

    void notifyObserversFatalError(const std::string& message) const {
        for (const auto& observer : observers) {
            observer->onFatalError(message);
        }
    }

    void warning(const std::string& message) const {
        notifyObserversWarning(message);
    }

    void error(const std::string& message) const {
        notifyObserversError(message);
    }

    void fatalError(const std::string& message) const {
        notifyObserversFatalError(message);
    }


};

class ConsoleWarningObserver : public Observer {
public:
    void onWarning(const std::string& message) override {
        std::cout << "ConsoleWarningObserver: " << message << std::endl;
    }
};

class FileErrorObserver : public Observer {
private:
    std::string str;
public:
    FileErrorObserver(const std::string& str) : str(str) {}

    void onError(const std::string& message) override {
        std::ofstream file(str, std::ios::app);
        if (file.is_open()) {
            file << "FileErrorObserver: " << message << std::endl;
            file.close();
        } else {
            std::cerr << "Error: Unable to open file " << str << " for writing" << std::endl;
        }
    }


};

class ConsoleAndFileFatalErrorObserver : public Observer {
private:
    std::string str;
public:
    ConsoleAndFileFatalErrorObserver(const std::string& str) : str(str) {}

    void onFatalError(const std::string& message) override {
        std::cout << "ConsoleAndFileFatalErrorObserver: " << message << std::endl;

        std::ofstream file(str, std::ios::app);
        if (file.is_open()) {
            file << "ConsoleAndFileFatalErrorObserver: " << message << std::endl;
            file.close();
        } else {
            std::cerr << "Error: Unable to open file " << str << " for writing" << std::endl;
        }
    }


};

int main() {
    O o;

    ConsoleWarningObserver consoleWarningObserver;
    FileErrorObserver fileErrorObserver("error_log.txt");
    ConsoleAndFileFatalErrorObserver consoleAndFileFatalErrorObserver("logs.txt");

    o.add(&consoleWarningObserver);
    o.add(&fileErrorObserver);
    o.add(&consoleAndFileFatalErrorObserver);
    o.warning("Warning");
    o.error("Error message.");
    o.fatalError("Fatal error");
    o.remove(&consoleWarningObserver);
    o.remove(&fileErrorObserver);
    o.remove(&consoleAndFileFatalErrorObserver);

    return 0;
}


