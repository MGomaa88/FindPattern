// FindPatternExamOpgave.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <vector>

using namespace std;

int findPattern(std::string text, std::string word)
{
	int wordL = word.length();
	int textL = text.length();
	int counter = wordL;
	string temp = "";
	vector <std::string> wordsVec;
	string wordRevers;

	vector <bool> boolVec;

	/*for (int i = 0; i < wordL; i++)
	{
		wordRevers += word.at(counter - 1);
		counter--;
	}*/


	for (int i = 0; i < textL; i++)
	{

		if (text[i] != ' ')
		{
			temp += text[i];

		}
		if (text[i] == ' ' || i == textL - 1)
		{

			wordsVec.push_back(temp);
			temp = "";
		}

	}



	for (size_t i = 0; i < wordsVec.size(); i++)
	{
		boolVec.clear();

		if (word == wordsVec[i])
			return 1;

		

		else if (wordsVec[i].length() == wordL)
		{
			for (size_t r = 0; r < wordL; r++)
			{
				for (size_t c = 0; c < wordL; c++)
				{

					if (word.at(r) == wordsVec[i].at(c))
					{

						boolVec.push_back(1);
						if (boolVec.size() == wordL)
						{
							return 2;
						}

					}
				}
			}
		}


		else
		{

			for (size_t r = 0; r < wordL; r++)
			{
				for (size_t c = 0; c < wordsVec[i].length(); c++)
				{

					if (word.at(r) == wordsVec[i].at(c) ) // && boolVec.size()<wordL
					{
						boolVec.push_back(1);	

						if (boolVec.size() == wordL)
						{
							return 3;
						}

					}
				}
			}
			
			
		}
	}



	return 0;


}
int main()
{
	string text = "ostemad";

	string word = "som";

	cout << findPattern(text, word) << endl;



}

