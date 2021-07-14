#include "Streamer.h"

Streamer::Streamer(int socket)
{
    this->socket = socket;
    //memset(buffer, 1, sizeof(buffer));
}
string Streamer::getLine(){
    while(1) {
        int recvLen = recv(socket,(uint8_t*)buffer + bitCount, 100, 0);
        cout<<"last buffer : "<<(uint8_t)buffer[recvLen]<<endl;
        cout <<"recvlen : "<<recvLen<<endl;
        if (recvLen <= 0){
            throw "connexion corrupted !";
        }
        bitCount += recvLen;
        if(strlen(buffer)>=100) {
            continue;
            
        } else {
            string msg = string(buffer);
            
            int positionDelimiter = strlen(buffer);
            for(int i=positionDelimiter; i<bitCount; i++) {
                buffer[i-positionDelimiter] = buffer[i+1];
            }
            
            bitCount = bitCount - positionDelimiter - 1;
            memset(buffer+bitCount, 1, 100 - bitCount);
            
            return msg;
        }
    }
    
}
