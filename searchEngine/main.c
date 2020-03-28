#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>

int Search_in_File(char *str, char *fname);
char* concat(const char *s1, const char *s2) ;


int main(int argc, char *argv[])
{

    struct dirent *de;
    int counter =0 ;
    char sentence[100] ;
    char *temp ;
    char *fname ;
    char *dir  = "/home/alymaged/Documents/FCI/parallel/assignments/ass2/CS471-Parallel-A2-2020/Aristo-Mini-Corpus";

    DIR *dr = opendir(dir);

    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }

    printf("Please Enter the sentence: ") ;
    gets(sentence) ;


    while ((de = readdir(dr)) != NULL)
    {
        if(de->d_name[0]=='A')
        {
            temp = concat(dir, "/") ;
            fname = concat(temp, de->d_name) ;
//            printf("%s\n", de->d_name);
            counter += Search_in_File(fname, sentence);
        }

    }
//Search_in_File("/Aristo-Mini-Corpus P-1.txt", sentence);

    printf("\ncounter in all files is : %d", counter) ;


    closedir(dr);
    return 0;
}

int Search_in_File(char *fname, char *str) {
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char temp[1000000];

//	printf("%s\n", fname) ;

	if((fp = fopen(fname, "r")) == NULL) {
		return(-1);
	}


	while(fgets(temp, 1000000, fp) != NULL)
	{
//        printf("%s",temp) ;
		if(strstr(temp, str) != NULL)
		{
			printf("A match found on line: %d\n", line_num);
			printf("\n%s\n", temp);
			find_result++;
		}
		line_num++;
	}

	if(find_result == 0) {
		printf("\nSorry, couldn't find a match.\n");
	}

	if(fp) {
		fclose(fp);
	}
   	return find_result;
}

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
