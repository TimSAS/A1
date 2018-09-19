#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//working with files:
void openFile(string fileName, ifstream * ourFile);
void closeFile(ifstream * ourFile);

//working with vector
void populateVector(ifstream * ourFile, vector<vector<string>> * ourData);
void displayVector(vector<vector<string>> * ourData);

int main()
{
	//opening our file
	ifstream ourFile;
	string fileName = "chicagocrime_2_items.csv";
	openFile(fileName, &ourFile);

	//getting the data into a 2-dimentional vector:
	vector< vector<string> > crimeData;
	populateVector(&ourFile, &crimeData);
	displayVector(&crimeData);

	//figuring out the support for items

	//figuring out frequent itemsets

	std::cin.get();
	return 0;
}

void openFile(string fileName, ifstream * ourFile)
{
	ourFile->open(fileName);
	if (ourFile->is_open())
	{
		cout << fileName << " is successfully opened!" << endl;
	}
	else
	{
		cout << "Unable to open file!" << endl;
	}
	return;
}
void closeFile(ifstream * ourFile)
{
	ourFile->close();
	return;
}

void populateVector(ifstream * ourFile, vector<vector<string>> * ourData)
{
	if (ourFile->is_open())
	{
		string row;
		while (getline(*ourFile, row))
		{
			vector<string> rowItems;
			string tempStr;
			int commaFound = 0;
			for (int i = 0; i < row.size(); i++)
			{
				if (row[i] == ' ' && commaFound) { tempStr += row[i]; }
				else if (row[i] == ',')
				{
					if (!commaFound)
					{
						rowItems.push_back(tempStr);
						tempStr = "";
						commaFound = 1;
					}
					else tempStr += row[i];
				}
				else if (row[i] == '\"') { continue; }
				else { tempStr += row[i]; }

			}
			rowItems.push_back(tempStr);
			ourData->push_back(rowItems);
			//cout << rowItems[0] << " <> " << rowItems[1] << endl;
			//cout << row << endl;
		}
	}
}
void displayVector(vector<vector<string>> * ourData)
{
	for (int y = 0; y < (*ourData).size(); y++)
	{
		for (int x = 0; x < (*ourData)[y].size(); x++)
		{
			cout << (*ourData)[y][x] << "    ";
		}
		cout << endl;
	}
}