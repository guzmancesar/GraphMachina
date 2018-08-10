#ifndef SORTS_H
#define SORTS_H

vector<int> selectionSort (vector<int> sorted)
{
	//implementation of a selection sort
	int ina, inb, min;
	

	
	for(int i = 0; i < sorted.size(); i++)
	{
		min = i;
		for(int g = i + 1; g < sorted.size(); g++)
		{
			if(sorted[min] > sorted[g])
				min = g;
		}
		int temp = sorted[i];
		sorted[i] = sorted[min];
		sorted[min] = temp;
	}
	
	return sorted;
	
};


stack removeZerosandSort(stack alphaStack, vector<int> &betaVector)
{
	vector<int> temp;
	
	for(int k = alphaStack.getsize(); k > 0; k--)
	{
		temp.push_back(alphaStack.pop());
	}
	
	betaVector = selectionSort(temp);
	stack ret;
	
	
	for (int i = 0; i < betaVector.size(); i++)
		if(betaVector[i] == 0)
		{}
		else
		{
			ret.push(node(betaVector[i]));
		}
	
	return ret;
};

#endif

