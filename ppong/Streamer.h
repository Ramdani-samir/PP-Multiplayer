#ifndef STREAMER_H
#define STREAMER_H
#include <string>
#include <cstring>
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;
class Streamer
{
    
public:
    string getLine();
    Streamer(int);
    
private :
    int bitCount;
    int socket;
    char buffer[100];


};

#endif // STREAMER_H
