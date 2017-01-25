#include <fstream>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <iomanip>
#include <cstdio>

int main(int argc, char* argv[]){


	if(argc > 2){
		std::cerr << "Too many arguments!" << std::endl;
		return EXIT_FAILURE;
	}

	//get the file from the arguments and 
	//open the file
	std::string filename = argv[1];
	std::ifstream inFile(argv[1], std::ios::binary);

	std::ofstream outFile("test.txt");

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

			int byteIndex = 0;
			for(byteIndex = 0; byteIndex < 16; byteIndex++){

				inFile.read(reinterpret_cast<std::fstream::char_type*>(&value1),
										sizeof value1);

				if(!inFile.eof())
					byte[byteIndex] = value1;
				else if(byteIndex == 0){
					finished = true;
					inFile.close();
					return EXIT_SUCCESS;
					break;
				}	
				else
					break;
				
			}	


			if(finished == false)
				std::cout /*outFile*/ << std::hex << std::setw(7) << std::setfill('0') << address << ": ";
			
			//print out the hex data for this line
			for(int i = 0; i < 16; i++){
				if(byte[i] != 0 || i < byteIndex)
					std::cout /*outFile*/ << std::setw(2) << std::setfill('0') << 
					std::hex << (int)byte[i];
				else
					std::cout /*outFile*/ << "  ";
				
				if(i%2 == 1)
					std::cout /*outFile*/ << " ";
			}

			std::cout /*outFile*/ << " ";
		
			//print out the text for this line
			for(int i = 0; i < 16; i++){
				if((byte[i] < 32 && byte[i] > 0)||(byte[i] > 127))
					std::cout /*outFile*/ << ".";
				else if(byte[i] == 0)
					std::cout /*outFile*/ << " ";
				else
					std::cout /*outFile*/ << byte[i];
			}

			if(finished == false)
				std::cout /*outFile*/<< std::endl;

			address+=16;
		}
	}
	else{
		std::cerr << "File does not exist" << std::endl;
		return EXIT_FAILURE;
	}
	

	inFile.close();

	return EXIT_SUCCESS;
}

