#include <iostream>
#include "score.h"
#include "TCP.h"
#include "Player.h"
#include <thread>
#include <string>
#include <cstring>
#include "Listeners.h"

using namespace std;

class cls : public Listeners{
    public :
      void onConnected(bool connected){
          if(connected){
              cout<<"client connected to server."<<endl;
          }else{
              cout<<"Ooops ! client disconnected from server."<<endl;
          }
      }
      
      void onReceiveListener(char* desc, float x, float y){
          
          string des = string(desc);
          if(des.compare("ball") == 0){
                 cout<<desc <<" "<<x<<" "<<y <<endl;
          }else if(des.compare("bar") == 0){
                 cout<<desc <<" "<<x<<" "<<y <<endl;
          }else if( des.compare("puz") ==0){
                  cout<<desc <<" "<<x<<" "<<y <<endl;
          }
      }
      
      void onMessageReceived(string msg){
          cout<<"message received : "<<msg<<endl;
      }
};


int main(){
    cls onListener;
    

	TCP::Connexion server;
	server.ListenTo(1025);
	server.setListener(&onListener);
/*

	TCP::Connexion client;
	client.setListener(&onListener);
    client.connectTo("127.0.0.1",1025);
 */ 
    string des;
    float x, y;
    while(1){
        cout<<"your desc :";
        cin>>des;
        cout<<"your x :";
        cin>>x;
        cout<<"your x :";
        cin>>y;
        server.sendPositions(des, x, y);
        
    }
    server.close();
	return 0;
}
