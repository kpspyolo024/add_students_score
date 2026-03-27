#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "header.h"

n* CreateScore(int score)
{
       n* temp = (n*)malloc(sizeof(n));
        temp->score = score;
        temp->next = NULL;
        return temp;
}

m* CreateStd(const char* name)
{
        m* newstd = (m*)malloc(sizeof(m));
        strcpy(newstd->name, name);
        newstd->scores = NULL;
        newstd->next = NULL;
        return newstd;
}

void Addstd(m** head, const char* name)
{
        m* newstd = CreateStd(name);
        if (*head == NULL)
        {
                *head = newstd;
        }
        else
        {
                m* temp = *head;
                while (temp->next != NULL)
                {
                        temp = temp->next;
                }
                temp->next = newstd;
        }
}

void AddScore(m* student, int score)
{
        n* newscore = CreateScore(score);
        if (student->scores == NULL)
                student->scores = newscore;
        else
        {
                n* temp = student->scores;
                while (temp->next != NULL)
                        temp = temp->next;
                temp->next = newscore;
        }
}


void EnterScores(m* stdlist)
{
        int max = 4;
        m* currentstd = stdlist;
        while (currentstd != NULL)
        {
                printf("Enter up to 4 scores for %s (enter -1 to stop):\n", currentstd->name);
                for (int i = 0; i < 4; i++)
                {
                        int score;
                        printf("Enter score %d: ", i + 1);
                        scanf("%d", &score);
                        if (score == -1)
                                break;
                        else if(score > 100)
                                score = 0;
                        else
                                AddScore(currentstd, score);
                }
                currentstd = currentstd->next;
        }
}
void PrintStdAndScores(m* stdlist)
{
        m* currentstd = stdlist;
        while (currentstd != NULL)
        {
                printf("\nStudent: %s\n", currentstd->name);
                n* currentscore = currentstd->scores;
                
                int total = 0, count = 0;
                printf("Scores: ");
                while (currentscore != NULL)
                {
                        printf("%d ", currentscore->score);
                        total += currentscore->score;
                        count++;
                        currentscore = currentscore->next;
                }

                if (count > 0)
                {
                        double average = (double)total / count;
                        printf("\nTotal: %d, Average: %.2f\n", total, average);
                }
                else
                        printf("No scores available.\n");

                currentstd = currentstd->next;
        }
}


void freestd(m* stdlist)
{
        while (stdlist != NULL)
        {
                m* temp_student = stdlist;
                stdlist = stdlist->next;


                n* score_list = temp_student->scores;
                while (score_list != NULL)
                {
                        n* temp_score = score_list;
                        score_list = score_list->next;
                        free(temp_score);
                }

           
                free(temp_student);
        }
}
