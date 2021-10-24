#include "Logger.h"

void FileLogger::addMessage(const string& message)
{
    ofstream oFile("log.txt");
    oFile<<message<<endl;
    cout<<message<<endl;
    oFile.close();
}