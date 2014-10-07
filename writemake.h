#ifndef _WRITEMAKE_H_
#define _WRITEMAKE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <iomanip>
#include <dirent.h>
#include <string>

using namespace std;

class writemake
{
public:
	writemake();
	void setCPPVersion(string);
	void setCompiler(string);
	void write() const;
	getFileList(vector<string> cppFiles,vector<string> headerFiles);
private:
	string programName;
	string compiler;
	string CPPVersion;
	bool cpptype;
};

#endif