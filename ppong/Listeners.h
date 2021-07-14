#include <string>
#ifndef LISTENERS_H
#define LISTENERS_H

using namespace std;
class Listeners
{
public:
    virtual void onConnected(bool)= 0;
    virtual void onReceiveListener(char*, float, float)= 0;
    virtual void onMessageReceived(string) = 0;
protected :
     ~Listeners(){}

};

#endif // ONCONNEXIONLISTENER_H
