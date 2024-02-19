#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	int randomNum = rand() % 100 + 1;
	int guess;
	int count = 0;
	cout << "I thought of a number between 1 and 100! Try to guess it." << endl;
	cin >> guess;

	while (guess != randomNum)
	{
		if (guess > randomNum)
		{
			cout << "Higher, try again: ";
			cin >> guess;
			count++;
		}
		else if (guess < randomNum)
		{
			cout << "Lower, try again: ";
			cin >> guess;
			count++;
		}
	}
	cout << "You guessed the number in " << count << " tries." << endl;

	return 0;
}