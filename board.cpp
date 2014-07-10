#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <ncurses.h>

using namespace std;

int square[17] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};


void printDouble(int number)
{
        if (number >= 10)
        {
                cout << " |  ";
        }
        else
        {
                cout << "  |  ";
        }
}

void board()
{
	system("clear");
	cout << "     |     |     |     " << endl;
	cout << "  " <<  square[1];
	printDouble(square[1]); 
	cout << square[2];
	printDouble(square[2]); 
	cout << square[3];  
	printDouble(square[3]); 
	cout << square[4] << endl;

	cout << "_____|_____|_____|_____" << endl;
	cout << "     |     |     |     " << endl;

	cout << "  " << square[5];
	printDouble(square[5]); 
	cout << square[6]; 
	printDouble(square[6]); 
	cout << square[7];
	printDouble(square[7]); 
	cout << square[8] <<endl;

	cout << "_____|_____|_____|_____" << endl;
	cout << "     |     |     |     " << endl;

	cout << "  " << square[9];
	printDouble(square[9]);
	cout  << square[10];
	printDouble(square[10]);
	cout  << square[11];
	printDouble(square[11]);
	cout  << square[12] << endl;
	
	cout << "_____|_____|_____|_____" << endl;
	cout << "     |     |     |     " << endl;
	
	cout << "  " << square[13]; 
	printDouble(square[13]);
	cout  << square [14];
	printDouble(square[14]);
	cout  << square[15];
	printDouble(square[15]);
	cout  << square[16] << endl;

	cout << "     |     |     |     " << endl << endl;
}

vector <int>  random_generate(int level)
{
	srand(time(NULL));
	int arr[17] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
	random_shuffle(&arr[1], &arr[16]);
	vector <int> temp;
	for (int i = 1; i <= level; i++)
	{
		square[arr[i]] = arr[i];
		temp.push_back(arr[i]);
	}	
	return temp; 	
}

void reset()
{
	for (int i = 0; i < 17; i++)
	{
		square[i] = 0;
	}
}

bool right (int arr[], vector <int> vec, int level)
{
	int levelHold = level;
	int temp[levelHold];
	for (int i = 0; i < level; i++)
	{
		temp[i] = arr[i];
	}
	vector <int> vec1 = vec;
	sort(temp, temp + level);
	for (int i = 0; i < level; i++)
	{
		if (temp[i] != vec1[i])
		{
			return false;
		}

	}
	return true;
}

int main ()
{
	int level = 1;
	int life = 5;
	int score = 0;
	int option = 0;
	cout << "Hi friendly user ;), this game is designed to improve your memory" << endl;
	cin >> option;
	// add in option check;
	while (life != 0)
	{	
		vector <int> correctAnswer;
		int answer[level];
		reset();
		correctAnswer = random_generate(level);
		sort (correctAnswer.begin(), correctAnswer.end());
		board();
		usleep(3000000);
		reset();
		board();
		for (int i = 0; i < level; i++)
		{
			cin >> answer[i];
		}
		if (right(answer, correctAnswer, level) == true)
		{
			score += pow(2, level);
			level++;
		}
		else
		{
			life--;
		}
		
	}
	cout << "Your score is: " << score << endl;
	
}
