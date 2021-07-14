/*
 * TCP.h
 *
 *  Created on: 27 déc. 2020
 *      Author: simon
 */
#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>
#include <thread>
#include <cstdio>
#include "Listeners.h"
#include "Streamer.h"
#include <cstdlib>
#include <vector>
#include <sstream>
#include <cstring>


#ifndef TCP_H_
#define TCP_H_

using namespace std;

float getFloatFromBuffer(uint8_t*);
void getBufferFromFloat(float, uint8_t*);

class TCP{

	TCP();
public :
	class Connexion{
		private :
            Listeners* listener= NULL;
            
			int clientSock;
			float positionBallX,positionBallY ;
			float positionBarX,positionBarY;
            thread *t, *ts;

		public :
			void ListenTo(int);
			void connectTo(string , int);
            static void processReceive(int*, Listeners**);
			static void* processSend(int, string, float, float);
			void sendPositions(string, float, float);
            void close();
			~Connexion();
            void setListener(Listeners* listener_);

	};

};
#endif /* TCP_H_ */
