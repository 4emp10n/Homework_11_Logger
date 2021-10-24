#include <iostream>
#include "Logger.h"

using namespace std;

int main()
{
    Logger<ConsoleLogger> l1;
    string test = " !HELLO WORLD! ";
    l1.log(LOG_LEVEL::INFO, 1,2,test,3,4,5);

    Logger<FileLogger> l2;
    l2.log(LOG_LEVEL::INFO, 1,2,test,3,4,5);
    return 0;
}