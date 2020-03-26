int searchEngine(char fileName[50] , char sentence[50] )
{
    char* p;
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    int counter =0 ;

    fp = fopen("test.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);


    while ((read = getline(&line, &len, fp)) != -1)
    {
        p = strstr(line, sentence);
        if (p)
        {
            counter++ ;
            printf("\n%s found in line = %s \nwhere %s\n", sentence, line, p);
            printf("-----------------------------------------------------\n") ;
        }

    }

    printf("number of repeated  = %d", counter);

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
    return counter ;
}

