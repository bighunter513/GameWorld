#include "game_app.h"
#include "error_code.h"
#include <iostream>

using namespace std;

int main()
{
	int ret = get_app()->init();
	
	if (ret != EC_SUCCESS)
	{
		cout << "GameApp init failed. error: " << ret << endl;
		system("pause");
		exit(ret);
	}

	ret = get_app()->run();

	if (ret != EC_SUCCESS)
	{
		cout << "GameApp run return error: " << ret << endl;
	}
	else 
	{
		get_app()->fini();
	}

	system("pause");
	return 0;
}


