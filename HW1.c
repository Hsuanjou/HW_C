#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct key
{
    char keyword[50];
    int count;
};

int main(int argc, char **argv)
{
    struct key *arr = malloc((argc - 1) * sizeof(struct key));
    int i = 0;
    for (i = 1; i < argc; i++)
    {
        strcpy(arr[i - 1].keyword, argv[i]);
        arr[i - 1].count = 0;
    }
    char *line = NULL;
    size_t maxlen = 0;
    ssize_t n;
    char *token;
    const char s[2] = " \n";
    /* read till end of file (type Control-D to stop) */
    while ((n = getline(&line, &maxlen, stdin)) > 0)
    {
        //printf("Line read:\n[%s]\n", line);
        token = strtok(line, s);
        while (token != NULL)
        {

            for (i = 0; i < argc - 1; i++)
            {
                if (strcmp(arr[i].keyword, token) == 0)
                {
                    arr[i].count++;
                }
            }

            //printf("%s\n",token);
            token = strtok(NULL, s);
        }
    }
    for (i = 0; i < argc - 1; i++)
    {
        printf("Key word:%s\n", arr[i].keyword);
        printf("Count:%d\n", arr[i].count);
        //arr[i].count=0;
    }

    free(line);
    return 0;
}
