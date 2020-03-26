#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char* p;
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    char sentence[50] ;

    fp = fopen("test.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    printf("Enter sentence to search : ") ;
    gets(sentence) ;

    while ((read = getline(&line, &len, fp)) != -1)
    {
        p = strstr(line, sentence);
        if (p)
        {
            printf("\n%s found in line = %s \nwhere %s\n", sentence, line, p);
            printf("-----------------------------------------------------\n") ;
        }

    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
    return 0;
}
