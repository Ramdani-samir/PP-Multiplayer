#include "TCP.h"

//client connect
void TCP::Connexion::connectTo(string ip, int port){
	clientSock = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSock == -1) {
		cout << "Failed to create socket. errno: "<<endl;
		exit(EXIT_FAILURE);
	}

	sockaddr_in sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = inet_addr(ip.c_str());
	sockaddr.sin_port = htons(port);

	if(connect(clientSock,(struct sockaddr*)&sockaddr,sizeof(sockaddr)) != 0){
		cout<<"cannot connect to server address /n";
        if(listener != NULL){
            listener->onConnected(false);
        }
        
	}else{
        // notify
        if(listener != NULL){
            listener->onConnected(true);
        }
    }

    
    t = new thread(processReceive,&clientSock, &listener);
    

}

//server listening
void TCP::Connexion::ListenTo(int port){

	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		cout << "Failed to create socket. errno: "<<endl;
		exit(EXIT_FAILURE);
	}

	sockaddr_in sockaddr;
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = INADDR_ANY;
	sockaddr.sin_port = htons(port);

	if (bind(sock, (struct sockaddr*)&sockaddr, sizeof(sockaddr)) < 0) {
		cout << "Failed to bind to port "<<port<<endl;
		exit(EXIT_FAILURE);
	}else{
		cout << "Bind port "<<port<<endl;
	}

	// Start listening. Hold at most 10 connections in the queue
	if (listen(sock, 10) < 0) {
		cout << "Failed to listen on socket." <<endl;
		exit(EXIT_FAILURE);
	}else{
		cout << "Start listening at port" << port <<endl;
	}

	// accept
	int addrlen = sizeof(sockaddr);
	clientSock = accept(sock, (struct sockaddr*)&sockaddr, (socklen_t*)&addrlen);
	if (clientSock < 0) {
		cout << "Failed to grab connection." <<endl;
		exit(EXIT_FAILURE);
	}
	cout << "New client connected:"<< inet_ntoa(sockaddr.sin_addr) <<endl;
    
    // thread create
    t = new thread(processReceive,&clientSock, &listener);
    
}

void TCP::Connexion::sendPositions(string desc, float x, float y){
    
	ts = new thread(processSend, clientSock, desc, x, y);
}
void *TCP::Connexion::processSend(int clientsock, string des_s, float posX_s, float posY_s){

	uint8_t buffer[40];
	strncpy((char*)buffer, des_s.c_str(), des_s.length());
	buffer[des_s.length()] = ':';
	getBufferFromFloat(posX_s, buffer + des_s.length() + 1);
	buffer[des_s.length() + 7] = ':';
	getBufferFromFloat(posY_s, buffer + des_s.length() + 8);

	send(clientsock, buffer, des_s.length() + 15, 0);
	
    return NULL;
}

void TCP::Connexion::processReceive(int* _sock, Listeners** _listener){
   
    int sock = *_sock;
    Listeners* listener = *_listener;
    Streamer streamer(sock);
    string msg;

while(1){
        try{
            msg = streamer.getLine();
            
            cout<< " print :"<<msg.c_str()[msg.length()];
            
            if(strncmp(msg.c_str(), "ball", 4)==0){

                float positionballx = getFloatFromBuffer((uint8_t* )msg.c_str() + 5);
                float positionbally = getFloatFromBuffer((uint8_t* )msg.c_str() + 12);

                if(listener != NULL) {
                    listener->onReceiveListener((char*)"ball", positionballx, positionbally);
                }

            }else if (strncmp(msg.c_str(), "bar", 4)==0) {
			
                float positionbarx = getFloatFromBuffer((uint8_t* )msg.c_str() + 4);
                float positionbary = getFloatFromBuffer((uint8_t* )msg.c_str() + 11);

                if(listener != NULL) {
                    listener->onReceiveListener((char*)"bar", positionbarx, positionbary);
                }
		}else if(strncmp(msg.c_str(), "puz", 4)==0){
            
			float positionbarx = getFloatFromBuffer((uint8_t* )msg.c_str() + 4);
			float positionbary = getFloatFromBuffer((uint8_t* )msg.c_str() + 11);

			if(listener != NULL) {
				listener->onReceiveListener((char*)"puz", positionbarx, positionbary);
			}
        }else if(strncmp(msg.c_str(), "msg", 4)==0){
            if(listener != NULL) {
				listener->onMessageReceived(msg);
			}
        }
            
        }catch(const char* msg){
            if(listener != NULL){
                listener->onConnected(false);
            }
            return;
        }
	}
	
}

TCP::Connexion::~Connexion(){
}

float getFloatFromBuffer(uint8_t *buffer){
	char txt[7];
	strncpy(txt, (char*)buffer, 6);
	txt[6]='\0';
	return atof(txt);
}

void getBufferFromFloat(float pos, uint8_t *buffer){
    
	sprintf((char*)buffer,"%06.2f", pos);
}

void TCP::Connexion::setListener(Listeners* listener_) {
	listener = listener_;
}
void TCP::Connexion::close(){
    t->join();
    ts->join();
}