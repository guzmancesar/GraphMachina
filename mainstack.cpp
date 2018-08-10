#include "stack.h" 
#include "sorts.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[])
{
	//put a try catch here
	string filename = argv[1];
	cout << filename << endl;
	ifstream filein;
	
	//if statement, return 0 if the file doesnt open 
	filein.open(filename);
	stack primero;
	
	
	int tempint;
	vector <int> tempvector, containerVector;
	
	while (filein >> tempint)
	{
		//cout << tempint << endl;
		tempvector.push_back(tempint);
	}
	
	for(int i = 0; i < tempvector.size(); i++)
	{
		node temp(tempvector[i]);
		primero.push(temp);
	}
	
	int k = tempvector.size();
	
	//get time 
	high_resolution_clock::time_point startT = high_resolution_clock::now();
	stack fin = removeZerosandSort(primero, containerVector);
	high_resolution_clock::time_point endT = high_resolution_clock::now();
	//get time 
	
	int duration = duration_cast<milliseconds>(endT - startT).count();
	
	ofstream results;
	string ofname;
	if(filename == "1000.txt")
		ofname = "1000 integer file results.txt";
	else 
		ofname = "10000 integer file results.txt";
	
	cout << "your result file is" << ofname << endl;
	results.open(ofname);
	
	//blocks of seven so easier to read
	int blockmaker = 7;
	bool done = false;
	
	while(fin.getsize() != 0 and done == false)
	{	
		if(fin.getsize() == 1)
		{
			results << fin.pop() << " ";
			results << endl;
			results << "TIME ELAPSED = ";
			results << duration;
			done = true;
		}
		results << fin.pop() << " ";
		if(blockmaker == 7)
		{
			results << endl;
			blockmaker = 0;
		}
		blockmaker++;
	}
	
	results.close();
	cout << "TIME: " << duration << " milliseconds" << endl; 
	
	return 0;
}