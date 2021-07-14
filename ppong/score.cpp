#include "score.h"
#include <pthread.h>
	// initialize
	void Score::initialize(){
		int cr = sqlite3_open_v2(("/home/"+ getUserName() + "/score.db").c_str(), &DB, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
		if(cr != SQLITE_OK){
		cout<<"unnable to create the database"<<endl;
		}
		int result = sqlite3_exec(DB,"CREATE TABLE tab(name TEXT,score INTEGER);", NULL, NULL, &error);
		if(result != SQLITE_OK){
		cout<< error<< endl;
		sqlite3_free(error);
		}
	}

	// Add new score
	void Score::AddNewScore(const string& player,int score){
	sprintf(requet, "INSERT INTO tab VALUES('%s' , %d);", player.c_str(), score);
    	int res = sqlite3_exec(DB, requet, NULL, NULL, &error);
	if(res != SQLITE_OK){
	cout<< error<< endl;
	sqlite3_free(error);
	}
	}
	// get machine user
	string Score::getUserName(){
	 struct passwd *tmp = getpwuid (geteuid ());
  	 return tmp ? tmp->pw_name : "onlyGodKnows"; 
	}
	
	//check if user exists
	bool Score::Exists(string name){
	sqlite3_stmt* res;
	sprintf(requet,"SELECT name FROM tab WHERE name='%s';", name.c_str());
	int ret = sqlite3_prepare_v2(DB,requet,-1,&res,0);
	ret = sqlite3_step(res);
	if (ret == SQLITE_ROW){
	return true;
	} else {
	return false;
	}
	sqlite3_finalize(res);
	}
	// load score by username
	int Score::getUserScore(string name){
	sqlite3_stmt* res;
	sprintf(requet,"SELECT score FROM tab WHERE name='%s';", name.c_str());
	int ret_score = sqlite3_prepare_v2(DB,requet,-1,&res,0);
	ret_score = sqlite3_step(res);
	if (ret_score == SQLITE_ROW){
	int id = sqlite3_column_int(res, 0);
	return id;
	}else{
        return 0;
	}
	sqlite3_finalize(res);
	}

	// update score
	void Score::updateScore(string player, int score){
	sprintf(requet, "UPDATE tab set score = %d WHERE name = '%s';", score, player.c_str());
    	int res = sqlite3_exec(DB, requet, NULL, NULL, &error);
	if(res != SQLITE_OK){
	cout<< error<< endl;
	sqlite3_free(error);
	}
	}












