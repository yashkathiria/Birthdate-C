#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m = 0;
    int z = 1;
    int y = 1;
    char o = '0';
    char t = '1';
    char c[60], ch;
    FILE *fp;
    char input[3];
    char filename[11];
    char extra;
    char firstname[15];
    char lastname[15];
    char number[11];
    char date[3];
    char month[3];
    char year[5];
    int menu1;
mainmenu:
    printf("\n\n");
    printf("1 : Add Profile\n");
    printf("2 : Check Birthday\n");
    printf("3 : Exit\n");
    printf("Enter : ");

    scanf("%d", &menu1);
    switch (menu1)
    {
    case 1:
        printf("Frist Name : ");
        scanf("%s", firstname);
        printf("Last Name : ");
        scanf("%c", &extra);
        scanf("%s", lastname);
        printf("Date : ");
        scanf("%s", date);
        printf("Month : ");
        scanf("%s", month);
        printf("Year : ");
        scanf("%s", year);
        printf("Number : ");
        scanf("%s", number);
        for (int i = 0; i < 11; i++)
        {
            filename[i] = 0;
        }

        strcat(filename, "profile");
        strcat(filename, month);
        // printf("%s",filename);
        fp = fopen(filename, "a");
        if (fp == NULL)
        {
            fp = fopen(filename, "w");
            fprintf(fp, date);
            fprintf(fp, "-");
            fprintf(fp, month);
            fprintf(fp, "-");
            fprintf(fp, year);
            fprintf(fp, "          ");
            fprintf(fp, number);
            fprintf(fp, "          ");
            fprintf(fp, firstname);
            fprintf(fp, " ");
            fprintf(fp, lastname);
            fclose(fp);
            printf("New profile Added......");
        }
        fprintf(fp, "\n");
        fprintf(fp, date);
        fprintf(fp, "-");
        fprintf(fp, month);
        fprintf(fp, "-");
        fprintf(fp, year);
        fprintf(fp, "          ");
        fprintf(fp, number);
        fprintf(fp, "          ");
        fprintf(fp, firstname);
        fprintf(fp, " ");
        fprintf(fp, lastname);
        fclose(fp);
        printf("New profile Added......");
        goto mainmenu;
        break;
    case 2:
        for (int i = 0; i < 11; i++)
        {
            filename[i] = 0;
        }
        printf("Enter Month : ");
        scanf("%s", input);
        strcat(filename, "profile");
        strcat(filename, input);
        fp = fopen(filename, "r");
        fgets(c, sizeof(c), fp);
        while (1)
        {
            ch = fgetc(fp);
            if (ch == EOF)
            {
                break;
            }
            if (ch == '\n')
            {
                m = m + 1;
            }
        }
        fclose(fp);
        // ch = '\0';
        printf("\n\n\n                       DOB              Mobile Number              Name\n");
        while (1)
        {
            y = 0;
            fp = fopen(filename, "r");
            fgets(c, sizeof(c), fp);
            while (1)
            {
                for (int i = 0; i < 1; i++)
                {
                    fgets(c, sizeof(c), fp);
                }
                if (c[0] == o && c[1] == t)
                {
                    printf("                     %s\n", c);
                }
                if (m == y)
                {
                    break;
                }
                y = y + 1;
            }
            fclose(fp);
            if (z == 31)
            {
                break;
            }
            if (t == '9')
            {
                t = '0';
                o = o + 1;
                z = z + 1;
            }
            else
            {
                z = z + 1;
                t = t + 1;
            }
        }
        printf("\n\n\n\n");
    exit:
        return 0;
    }
}