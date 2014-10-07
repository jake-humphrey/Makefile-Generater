#include <iostream>
#include <fstream>
#include "writemake.h"
#include <iomanip>
#include <dirent.h>
#include <vector>
#include <regex>
#include <string>


writemake::writemake():compiler("g++"),CPPVersion(""),cpptype(true){}
void writemake::setCPPVersion(string version):CPPVersion(version){}
void writemake::setCompiler(string diffCompiler):compiler(diffCompiler){}
void writemake::write() const
{
	ofstream outfile ("makefile");
	outfile << "CC= " << compiler << endl;
	outfile << "OBJECTS= " << objects << endl;
	outfile << "EXE= " << progamName << endl;
	outfile << "CFLAGS= " << CPPVersion << endl;
	outfile << endl;
	outfile << setw(20) << "$(EXE):" << "$(OBJECTS)" << endl;
	outfile << right << setw(20) << "$(CC) -o $(EXE) $(OBJECTS)" << left << endl;
	
	
	outfile.close();
	
}

vector<string> writemake::convertToObjects(vector<string> cppFiles) const
{
	string filetype;
	vector<string> objectFiles;
	if (cpptype)
		filetype=".cpp";
	else
		filetype=".c";
	for(int i=0;i<cppFiles.size();i++)
	{
		found = cppFiles[i].find_last_of(filetype);
		objectFiles.pushback(cppFiles[i].substr(0,found)+".o");
	}
	return objectFiles;
}

void writemake::getFileList(vector<string> cppFiles,vector<string> headerFiles)
{
	DIR *d;
	struct dirent *dir;
	int i=0;
	d = opendir(".");
	string filetype;
	if (cpptype)
		filetype="(*\.cpp)";
	else
		filetype="(*\.c)";
	
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			i++;
			dirlist[i] = *dir->d_name;
			if (regex_match(*dir->d_name, regex(filetype)))
			{
				cppFiles.pushback(*dir->d_name);
			}else if (regex_match(*dir->d_name, regex("(*\.h)")))
			{
				headerFiles.pushback(*dir->d_name);
			}
		}
		closedir(d);
	}
}

