#include "utilities.h"
#include "life.h"
int main()
{
	Life configuration;
	welcome();
	configuration.initialize();
	configuration.print();
	cout << "Continue viewing new generations?" << endl;
	while (userSaysYes())
	{
		configuration.update();
		configuration.print();
		cout << "Continue viewing new generations?" << endl;
	}
	return 0;
}
