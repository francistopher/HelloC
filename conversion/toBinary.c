#include <stdio.h>

int toBinary(int decimal)
{
	int binary = 2;

	while (decimal != 0) {
		binary *= 10;	
		binary += (decimal % 2 == 0) ^ 1;
		decimal = decimal / 2;
	}
	int trueBinary = 0;
	//printf("%d\n", binary);
	while (binary != 2)
	{
		trueBinary *= 10;
		trueBinary += binary % 10;
		//	printf("%d\n", trueBinary);
		binary /= 10;
	}
	return trueBinary;
}

int main(int argc, char** argv)
{
	if (argc == 2)
	{
		int num = 0;
		char* digit = argv[1];
		for (int i = 0; i < sizeof(*digit) / sizeof(digit[0]); i++)
		{
			num += (int)digit[i] - 48;
			num *= 10;
		}
		num /= 10;

		printf("num: %d binary: %d", num , toBinary(num));
	}
	else
	{
		printf("Enter a number as your command argument.\n");
	}
	return 0;
}

