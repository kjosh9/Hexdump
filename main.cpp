

#include <fstream>
#include <cstring>
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]){


	std::string filename = argv[1];

	std::fstream theFile(argv[1]);
	
	std::string line;

	if(theFile.is_open()){
		
		while(!theFile.eof()){
			getline(theFile, line);
			std::cout << line << std::endl;
		}
	}
	else{
		std::cout << "file does not exist" << std::endl;
	}
	
	
	
	theFile.close();
	

	return 0;
}

