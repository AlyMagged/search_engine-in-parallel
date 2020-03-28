// This example is provided by:
// http://www.codingunit.com Programming Tutorials

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int Search_in_File(char *str, char *fname);

int main(int argc, char *argv[])
{
    char sentence[100] ;
    int counter ;
    printf("Please Enter the sentence: ") ;
    gets(sentence) ;
	counter = Search_in_File("test.txt", sentence);

	printf("\ncounter is : %d", counter) ;
	return(0);
}

int Search_in_File(char *fname, char *str) {
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char temp[512];


	if((fp = fopen(fname, "r")) == NULL) {
		return(-1);
	}


	while(fgets(temp, 512, fp) != NULL)
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
