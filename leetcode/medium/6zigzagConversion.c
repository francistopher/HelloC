#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char * convert(char * s, int numRows){
    // numRow of 1 is basically the arr itself
    if (numRows == 1) return s;
	int slen = strlen(s);
    if (slen == 1 || numRows > slen) return s;
    // 2d arr to map pattern
	char arr[numRows][(slen / 2) + 1];
    // rows, columns
	int x = 0;
	int y = 0;
    // set every cell to a space
	for (x = 0; x < numRows; x++)
	{
		for (y = 0; y < (slen / 2) + 1; y++)
		{
			arr[x][y] = ' ';
		}
	} 

    x = 0;
    y = 0;
    // zig zag through the 2d arr
    bool diagonal = false;
	while (*s != '\0')
	{
        // going diagonal
		if (diagonal)
		{
			if (x >= 0)
			{
				arr[x][y] = *s;
				x--;
				y++;
			}
			else
			{
                // shifting to going vertical
				diagonal = false;
				x+=2;
				y--;
				continue;
			}
		}
        // going vertical
		else
		{
			if (x < numRows)
			{
				arr[x][y] = *s;
				x++;
			}
            // shifting to going diagonal
			else
			{
				diagonal = true;
				x -= 2;
				y++;
				continue;
			}
		}
		*s++;
	}
    // collect row by row
	char* res = malloc(sizeof(char) * slen + 1);
	int resi = 0;
	for (x = 0; x < numRows; x++)
	{
		for (y = 0; y < (slen / 2) + 1; y++)
		{
			if (arr[x][y] != ' ')
			{
				res[resi++] = arr[x][y];
			}
        }
	}
    // to pointer
    res[slen] = '\0';
	return res;
}


int main(void)
{
	char* inp = "whsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqca";
	int rows = 61;
	char* res = convert(inp, rows);
	if (strcmp(res, "whsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfajcmqapfwaxdqrarswbsfoffhsqbvcun") == 0)
	{
		printf("CORRECT!\n");
	}
	else
	{
		printf("WRONG\n");
	}
	return 0;
}
