#include <fstream>
#include <iostream>
#include <string>
#include <vector>


namespace fileIO
{
	std::string line;
	std::ifstream file;
	

	std::vector <std::vector <int>> mat;
	int row;
	int col;
	
}	

 
int main(int argc, char * argv[]) //reading file name to fill matrix into memory
{
	std::cout << argv[1] << std::endl;
	
	//open file
	fileIO::file.open(argv[1]);
	
	//we know that ROW: tag holds the num of rows
	//we know that the COLUMNS: tag holds the num of cols 
	
	if(fileIO::file.is_open())
	{
		while(std::getline(fileIO::file, fileIO::line))
		{
			std::cout << fileIO::line << std::endl;
			std::cout << fileIO::line.length() << std::endl;
			
			std::string sub;
			if (fileIO::line.find("ROWS") != std::string::npos) 
			{
				std::cout << "found!" << '\n';
				char r = fileIO::line[fileIO::line.length()-1];
				std::cout << r << std::endl;
				//this char must be converted to a number now 
			}
		}	
	}
	else
	{
		std::cout << "file open failed...ending" << std::endl;
	}
	
}
