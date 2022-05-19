#include "Date.h"
#include "String.h"

int main()
{
	Date d1(24,2,2000), d2(12,6,2008);
	Date d3 = d2.CalcDiff(d1);
	d3.PrintDate();

}