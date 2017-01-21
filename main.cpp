

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

	int address = 0;

	//value to be read at a time from file
	uint8_t value1;
	uint8_t value2;

	//check if the file exist
	if(inFile.is_open()){

		//then get the contents of the file and 
		//print line by line
		while(!inFile.eof()){

			uint8_t byte[16];

			//print address with padding
			std::cout << std::hex << std::setw(7) << std::setfill('0') << address << ": ";
			
			for(int i = 0; i < 8 && !inFile.eof(); i++){
				
				std::string word;

				inFile.read(reinterpret_cast<std::fstream::char_type*>(&value1),
										sizeof value2);
				byte[i*2] = value1;
				
				inFile.read(reinterpret_cast<std::fstream::char_type*>(&value2),
										sizeof value2);
				byte[i*2+1] = value2;

				std::cout << std::setw(2) << std::setfill('0') << (int)value1;
				std::cout << std::setw(2) << std::setfill('0') << (int)value2 << ' ';

			}	
			
			for(int i = 0; i < 16; i++){
				if(byte[i] < 32)
					std::cout << ".";
				else
					std::cout << byte[i];
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

