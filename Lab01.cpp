// Lab01.cpp
// Thomas Wise
// COSC 2030
// Lab Assignment 01
// 9/23/2018

#include<fstream>
#include<iostream>
#include <string>

using std::ifstream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

string getFileName();
void getData(int& count, int& last, int& secondToLast, int& first, int& second, ifstream& inputFile);
void showResults(int count, int last, int secondToLast, int first, int second);

int main()
{
	ifstream inputFile;
	string inputFileName;
	int count = 0;
	int last;
	int secondToLast;
	int first;
	int second;
	inputFileName = getFileName();
	inputFile.open(inputFileName);
	if (!inputFile)
	{
		cerr << "File: \"" << inputFileName << "\" cannot be opened." << endl;
		inputFile.close();
		system("pause");
		return 0;
	}
	getData(count, last, secondToLast, first, second, inputFile);
	inputFile.close();
	showResults(count, last, secondToLast, first, second);
	system("pause");
	return 0;
}

string getFileName()
{
	string inputFileName;
	cout << "Please insert a file name: " << endl;
	cin >> inputFileName;
	return inputFileName;
}

void getData(int& count, int& last, int& secondToLast, int& first, int& second, ifstream& inputFile)
{
	int temp;
	while (!inputFile.eof())
	{
		if (!(inputFile >> temp))
		{
			inputFile.clear();
			inputFile.ignore();
		}
		else
		{
			count++;
			if (count == 1)
			{
				first = temp;
				last = temp;
			}
			else if(count == 2)
			{
				second = temp;
				secondToLast = last;
				last = temp;
			}
			else
			{
				secondToLast = last;
				last = temp;
			}
		}
	}
}

void showResults(int count, int last, int secondToLast, int first, int second)
{
	if (count == 0)
	{
		cout << "Sorry, there were no numbers in this file." << endl;
	}
	else if (count == 1)
	{
		cout << "There was one number in this file, that number was: " << first << endl;
	}
	else
	{
		cout << "There were " << count << " numbers in this file." << endl;
		cout << "First: " << first << endl;
		cout << "Second: " << second << endl;
		cout << "Last: " << last << endl;
		cout << "Second to Last: " << secondToLast << endl;
	}
}