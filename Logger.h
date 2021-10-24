#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum class LOG_LEVEL : int { ERROR, WARNING, INFO, DEBUG };

template<class T>
class Logger
{
    public:
    
    template<class ...Args>
    void log(LOG_LEVEL level, Args ...args);
};

class ConsoleLogger : public Logger<ConsoleLogger>
{
    public:
    template<class ...Args>
    string print(const Args& ...args) { return "Console Logger" + toStr(args ...); }

    template <class T>
    string toStr(T& value) { return to_string(value); }

    template<class T, class ...Args>
    string toStr(T value, Args&&... args) { return to_string(value) + toStr(args ...); }

    template<class ...Args>
    string toStr(string value, Args&&... args) { return value + toStr(args ...); }

    void addMessage(const string& message){ cout << message << endl; }
};

class FileLogger : public Logger<FileLogger>
{
    public:
    template<class ...Args>
    string print(Args ...args) { return "File Logger" + toStr(args ...);}

    template <class T>
    string toStr(T value) { return to_string(value); }

    template<class T, class ...Args>
    string toStr(T value, Args&&... args) { return to_string(value) + toStr(args ...); }

    template<class ...Args>
    string toStr(string value, Args&&... args) { return value + toStr(args ...);}

    void addMessage(const string& message);
};

template <class T>
template<class ...Args>
void Logger<T>::log(LOG_LEVEL level, Args ...args)
{
    string message;
    switch (level) 
    {
        case LOG_LEVEL::ERROR:
            message += "ERROR";
            break;
        case LOG_LEVEL::WARNING:
            message += "WARNING";
            break;
        case LOG_LEVEL::INFO:
            message += "INFO";
            break;
        case LOG_LEVEL::DEBUG:
            message += "DEBUG";
            break;
    }

    time_t currentTime = time(NULL);
    message += ", ";
    message += ctime(&currentTime);
    message.pop_back();
    message += ", [ " + static_cast<T*>(this) -> print(forward<Args>(args)...) + " ]";   
    static_cast<T*>(this) -> addMessage(message);
}