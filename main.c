#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"


int main()
{
        const char* filename = "students.txt";
        m* stdlist = NULL;


        FILE* file = fopen(filename, "r");
        if (file == NULL)
        {
                printf("Error opening file %s\n", filename);
                return -1;
        }

        char name[100];

        while (fgets(name, sizeof(name), file) != NULL)
        {
                name[strcspn(name, "\n")] = 0;
                m* current = stdlist;
                int already_exists = 0;
                while (current != NULL)
                {
                        if (strcmp(current->name, name) == 0)
                        {
                                already_exists = 1;
                                break;
                        }
                        current = current->next;
                }
                if (!already_exists)
                {
                        Addstd(&stdlist, name);
                }
        }


        EnterScores(stdlist);

        PrintStdAndScores(stdlist);

        freestd(stdlist);

        return 0;
}


