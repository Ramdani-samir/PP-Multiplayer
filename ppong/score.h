/*
 * score.h
 *
 *  Created on: 27 déc. 2020
 *      Author: simon
 */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sqlite3.h>
#include <cstdio>

#ifndef SCORE_H_
#define SCORE_H_

uid_t getuid(void);
uid_t geteuid(void);


using namespace std;
#define _PROGRAM_NAME "whoami"

class Score
{

	private :
	ostringstream ss;
	sqlite3* DB = NULL;
	char* error = NULL;
	char requet[100];

	// initialize
	void initialize();

	// constructor
	public :
	Score(){  initialize(); };

	// Add new score
	void AddNewScore(const string&,int);
	// get machine user
	string getUserName();

	//check if user exists
	bool Exists(string);
	// load score by username
	int getUserScore(string);
	// update score
	void updateScore(string, int);
};

#endif /* SCORE_H_ */
