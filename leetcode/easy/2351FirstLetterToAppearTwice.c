// solved on 2/10/2023

#include <stdio.h>

char repeatedCharacter(char * s){
    char repeats[26] = {0};
    while (*s != '\0')
    {
        repeats[*s - 'a']++;
        if (repeats[*s - 'a'] > 1)
        {
            return *s;
        }
        *s++;
    }
    return 'a';
}

int main(void)
{

	char rc = repeatedCharacter("repeatedCharacter");
	printf("%c\n", rc);
	
}
