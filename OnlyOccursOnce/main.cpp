//    Find the only element in an array that only occurs once.
//	same principles as MostFrequentInt, except this time it's better with the map

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


void onlyOnce(std::vector<int> thing)
{
	std::unordered_map<int, int> counter;		//map<index, number of occurences>
	for (int i = 0; i < thing.size(); i++)		//for each element, map it
	{
		std::unordered_map<int, int>::iterator it = counter.find(thing[i]);		//check if the ith element of the vector is already mapped
		if (it == counter.end())		//if it's not found, add it as a key
		{
			counter.emplace(thing[i], 1);
		}
		else
		{
			it->second++;
		}
	}
	std::vector <int> hits;
	for (auto it = counter.cbegin(); it != counter.cend(); it++)
	{
		if (it->second == 1)
		{
			hits.push_back(it->first);		//if the number of hits is 1, then add the index to the hits vector
		}
	}
	std::cout << "the following elements occur only once: " << std::endl;
	for (int i = 0; i < hits.size(); i++)
	{
		std::cout << hits[i] << " ";
	}
}

int main()
{
	char repeat = 'y';
	do {
		int size;
		std::vector<int> vec;
		std::cout << "enter size of array: " << std::endl;
		std::cin >> size;
		for (int i = 0; i < size; i++)
		{
			int temp;
			std::cout << "enter element number " << i << std::endl;
			std::cin >> temp;
			vec.push_back(temp);
		}
		onlyOnce(vec);
		std::cout << "try again?" << std::endl;
		std::cin >> repeat;
	} while (repeat == 'y' || repeat == 'Y');
}