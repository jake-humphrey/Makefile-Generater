#include <iostream>


int main (int argc, char * argv[])
{
   /* Method:	main
	* Description:	contains the getopt parameter handler and function calls  
	* Input:	args: -a -s -d -c -h -y -v
	* Output:	creates a file
	* Pre-conditions:	<none>
	* Post-conditions:	file created
	*/

   const char* cppVersion[] = {"C++98","C++03","C++TR1","C++11","C++14"};

	
	//getopt argument handler
	while ( (opt = getopt(argc, argv, ":s: :e: :c :h :f:")) != EOF ){
		switch (opt) {
			case 's':
				//deletes variables from file
				options=1;
				realCommand=true;
				Dval=optarg;
				parseFile(fn, array);
				break;
			case 'e':
				//clears all variables from file
				options=2;
				realCommand=true;
				break;
			case 'c':
				//creates a new variable in file
				Sval=optarg;
				options=3;
				realCommand=true;
				parseFile(fn, array);
				break;
			case 'f':
				//lists all variables in file
				options=4;
				realCommand=true;
				parseFile(fn, array);
				break;
			case 'h':
				//displays help
				helpMsg(true);
				realCommand=true;
				break;
			case '?':
			default:
				//incorrect arguments displays minimal help
				helpMsg();
				return 1;
		}
	}