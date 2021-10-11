#include <stdio.h>

enum ENUM_A
{
		X1,
		Y1,
		Z1 = 255,
		A1,
		B1,
};

int main () {
    enum ENUM_A enumA = Y1;
    enum ENUM_A enumB = B1;
    printf("%d %d\n", enumA, enumB);
    return 0;
}