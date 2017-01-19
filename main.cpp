

#include <fstream>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdint>

int main(int argc, char* argv[]){


	//get the file from the arguments and 
	//open the file
	std::string filename = argv[1];
	std::fstream theFile(argv[1]);

	std::string line;
	int16_t linecount = 0;

	//check if the file exist
	if(theFile.is_open()){

		//then get the contents of the file and 
		//print line by line
		while(!theFile.eof()){
			getline(theFile, line);
			std::cout << linecount << "\t" << line << std::endl;
			linecount++;
		}
	}
	else{
		std::cout << "file does not exist" << std::endl;
	}
	


	theFile.close();

	return 0;
}

