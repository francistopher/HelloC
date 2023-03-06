#include <string.h>
#include <stdio.h>

int strStr(char* haystack, char*needle)
{
	int nlen = strlen(needle);
	int hlen = strlen(haystack);
	if (hlen < nlen)
		return -1;
	int nchi = 0;
	int hchi = 0;
	while (hchi < hlen)
	{
		while ((nchi < nlen) && (nchi + hchi < hlen) && needle[nchi] == haystack[nchi + hchi])
		{
			nchi += 1;
		}
		if (nchi == nlen)
			return hchi;
		nchi = 0;
		hchi += 1;
	}
	return -1;
}

int main(void)
{	
	char* h = "christopherfrancisco";
	char* n = "christ";
	printf("%d\n", strStr(h, n));
	n = "francis";	
	printf("%d\n", strStr(h, n));
}
