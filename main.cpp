

#include <fstream>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <iomanip>

int main(int argc, char* argv[]){


	//get the file from the arguments and 
	//open the file
	std::string filename = argv[1];
	std::ifstream inFile(argv[1], std::ios::binary);

	int16_t address = 0;

	//value to be read at a time from file
	int16_t value;

	//set the output base 
	std::cout << std::hex;

	//check if the file exist
	if(inFile.is_open()){

		//then get the contents of the file and 
		//print line by line
		while(!inFile.eof()){

			//print address with padding
			std::cout << std::setw(7) << std::setfill('0') << address << ": ";
			
			for(int i = 0; i < 8 && !inFile.eof(); i++){
				
				inFile.read(reinterpret_cast<std::fstream::char_type*>(&value), sizeof value);
				//std::cout << value;
				//inFile.read(reinterpret_cast<std::fstream::char_type*>(&value), sizeof value);
				std::cout << std::setw(4) << std::setfill(' ') << value << ' ';
			}

			std::cout << std::endl;

			address+=16;
		}
	}
	else{
		std::cout << "file does not exist" << std::endl;
	}
	

	inFile.close();

	return 0;
}

