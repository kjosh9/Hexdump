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

	//check if the file exist
	if(inFile.is_open()){

		//then get the contents of the file and 
		//print line by line
		while(!inFile.eof()){

			uint8_t byte[16];
			bool finished = false;
	
			//start with a NULL filled array
			for(int i = 0; i < 16; i++){
				byte[i] = 0;
			}
	
			bool isEmpty = false;
			int byteIndex = 0;
			for(byteIndex = 0; byteIndex < 16; byteIndex++){

				inFile.read(reinterpret_cast<std::fstream::char_type*>(&value1),
										sizeof value1);

				if(!inFile.eof())
					byte[byteIndex] = value1;
				else if(byteIndex == 0){
					finished = true;
					break;
				}	
				else
					break;
				
			}	

			if(finished == false)
				std::cout << std::hex << std::setw(7) << std::setfill('0') << address << ": ";
			
			//print out the hex data for this line
			for(int i = 0; i < 16; i++){
				if(byte[i] != 0 || i < byteIndex)
					std::cout << std::setw(2) << std::setfill('0') << 
					std::hex << (int)byte[i];
				else
					std::cout << "  ";

				if(i%2 == 1)
					std::cout << " ";
			}

			std::cout << ' ';
		
			//print out the text for this line
			for(int i = 0; i < 16; i++){
				if((byte[i] < 32 && byte[i] > 0)||(byte[i] > 127))
					std::cout << ".";
				else if(byte[i] == 0)
					std::cout << " ";
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

