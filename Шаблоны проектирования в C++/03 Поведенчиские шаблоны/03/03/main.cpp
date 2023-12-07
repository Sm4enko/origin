
#include <iostream>
#include <fstream>
#include <stdexcept>

enum class Logs {
    Warning,
    Error,
    FatalError,
    Unknown
};

class LogMessage {
private:
    Logs messageType;
    std::string logMessage;
public:
    LogMessage(Logs type, const std::string& message) : messageType(type), logMessage(message) {}

    Logs type() const {
        return messageType;
    }

    const std::string& message() const {
        return logMessage;
    }

};

class Rec {
protected:
    Rec* nextHandler = nullptr;
public:
    virtual ~Rec() = default;
    virtual void handle(const LogMessage& logMessage) = 0;
    virtual void setNextHandler(Rec* handler) {
        nextHandler = handler;
    }


};

class FatalErrorHandler : public Rec {
public:
    void handle(const LogMessage& logMessage) override {
        if (logMessage.type() == Logs::FatalError) {
            throw std::runtime_error(logMessage.message());
        } else if (nextHandler != nullptr) {
            nextHandler->handle(logMessage);
        }
    }
};

class ErrorHandler : public Rec {
private:
    std::string str;
public:
    ErrorHandler(const std::string& str) : str(str) {}

    void handle(const LogMessage& logMessage) override {
        if (logMessage.type() == Logs::Error) {
            std::ofstream file(str, std::ios::app);
            if (file.is_open()) {
                file << "Error: " << logMessage.message() << std::endl;
                file.close();
            } else {
                std::cerr << "Error: No possible to open file " << str << " for writing" << std::endl;
            }
        } else if (nextHandler != nullptr) {
            nextHandler->handle(logMessage);
        }
    }


};


class WarningHandler : public Rec {
public:
    void handle(const LogMessage& logMessage) override {
        if (logMessage.type() == Logs::Warning) {
            std::cout << "Error : Warning" << logMessage.message() << std::endl;
        } else if (nextHandler != nullptr) {
            nextHandler->handle(logMessage);
        }
    }
};

class UnknownHandler : public Rec {
public:
    void handle(const LogMessage& logMessage) override {
        if (logMessage.type() == Logs::Unknown) {
            throw std::runtime_error("Unknown log message type: " + logMessage.message());
        } else if (nextHandler != nullptr) {
            nextHandler->handle(logMessage);
        }
    }
};

int main() {

    FatalErrorHandler fatalErrorHandler;
    ErrorHandler errorHandler("logs.txt");
    WarningHandler warningHandler;
    UnknownHandler unknownHandler;

    fatalErrorHandler.setNextHandler(&errorHandler);
    errorHandler.setNextHandler(&warningHandler);
    warningHandler.setNextHandler(&unknownHandler);

    LogMessage logMessage(Logs::FatalError, "It is a fatal error.");
    
    try {
        fatalErrorHandler.handle(logMessage);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    LogMessage unknownLogMessage(Logs::Unknown, "Unknown log.");
    
    try {
        fatalErrorHandler.handle(unknownLogMessage);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

