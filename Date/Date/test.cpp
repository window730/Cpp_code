#include "Date.h"

int main()
{
	Date d1(2025, 7, 22);
	Date d2 (2025, 7, 10);

	d1.Print();
	d2.Print();

	cin >> d1 >> d2;

	int i = d2 - d1;
	cout << i << endl;

	cout << d1 << d2;


	//cout << d1.Get_mouth_days() << endl;
	////if (d1 <= d2)
	////	cout << "d1" << endl;
	////else
	////	cout << "d2" << endl;
	return 0;
}