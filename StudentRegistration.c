//Ryan Maidment, 040932067

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void registration(int **registrationTable,int *studentId,char *courseId[8], char cId[8], int sId, int numStudent, int numCourse);
void withdraw(int **registrationTable,int *studentId,char *courseId[8], char cId[8], int sId, int numStudent, int numCourse);
void display(int **registrationTable,int *studentId,char *courseId[8], char cId[8],int sId, int numStudent, int numCourse);

int main(void) {

   int *studentId = NULL;
   char **courseId = NULL;
   int **registrationTable = NULL;

   int numCourse, numStudent;
   int choice;
   int i,j;

   int sId;
   char cId[8];

   printf("Enter number of students: ");
   scanf("%d",&numStudent);
   //Allocates memory for studentID array from user input.
   studentId = (int*)malloc(sizeof(int)*numStudent);
   //loops through student array, filling using user input.
       for(i=0; i<numStudent; i++) {

           printf("Enter student ID for student %d: ",i+1);
           scanf("%d",&studentId[i]);
       }
       //Loops through course array, filling using user input
       printf("\nEnter number of courses: ");
       scanf("%d",&numCourse);
       //Allocated memory for courseId array from user input.
       courseId = (char**)malloc(sizeof(char)*numCourse);
           for(i=0;i<numCourse;i++) {

               courseId[i] = (char*)malloc(sizeof(char)*8);
               printf("Enter name of course %d : ",(i+1));
               scanf(" %7c",courseId[i]);
           }
           //Creats a 2D array from sudentId and courseId arrays
           registrationTable = (int**)malloc(numStudent*sizeof(int*));
           for(i=0;i<numStudent;i++) {

               registrationTable[i] = (int*)malloc(numCourse*sizeof(int));
               for(j=0;j<numCourse;j++) {
                   registrationTable[i][j] = 0;
                 }
           }
           //Case switch for menu
           while(choice != 4) {

               printf("\n1 Register student in a course.");
               printf("\n2 Withdraw student from a course.");
               printf("\n3 Display registration table.");
               printf("\n4 Exit.");
               printf("\n >> ");
               scanf(" %d",&choice);

               if(choice == 1) {

                   printf("\nEnter student id: ");
                   scanf(" %d",&sId);
                   printf("Enter course code: ");
                   scanf(" %7c",&cId);
                   registration(registrationTable,studentId,courseId, cId, sId, numStudent, numCourse);

               }
               else if(choice == 2) {

                   printf("\nEnter student id: ");
                   scanf(" %d",&sId);
                   printf("Enter course code: ");
                   scanf(" %7c",&cId);
                   withdraw(registrationTable,studentId,courseId, cId, sId, numStudent, numCourse);

               }
               else if(choice == 3) {
                   display(registrationTable,studentId,courseId, cId, sId, numStudent, numCourse);
      }
   }
 }


void registration( int **registrationTable, int *studentId, char *courseId[8], char cId[8], int sId, int numStudent, int numCourse ) {

   int i;
   int studentIndex = -1, courseIndex = -1;
//Loops through studentId array, looking for match with user input.
   for(i=0;i<numStudent;i++) {

     if(studentId[i] == sId) {

           studentIndex = i;
           break;
       }
   }
//Loops through courseId array, looking for match with user input.
   for(i=0;i<numCourse;i++) {

       if(strcmp(cId,courseId[i]) == 0)
       {
           courseIndex = i;
           break;
       }
   }

   if(studentIndex != -1 && courseIndex != -1) {

       registrationTable[studentIndex][courseIndex] = 1;
   }
}

void withdraw(int **registrationTable,int *studentId,char *courseId[8], char cId[8], int sId, int numStudent, int numCourse ) {

   int studentIndex = -1, courseIndex = -1;
   int i;

   for(i=0;i<numStudent;i++) {
      if(studentId[i] == sId)
       {
           studentIndex = i;
           break;
       }
   }

   for(i=0;i<numCourse;i++) {

       if(strcmp(cId,courseId[i]) == 0) {

           courseIndex = i;
           break;
       }
   }

   if(studentIndex != -1 && courseIndex != -1) {

       registrationTable[studentIndex][courseIndex] = 0;
   }
}

void display(int **registrationTable,int *studentId,char *courseId[8], char cId[8], int sId, int numStudent, int numCourse ) {

   int i,j;

   printf("\n\t%-20s","Student Id");

   for(i=0;i<numCourse;i++) {

       printf("%-10s",courseId[i]);
   }

   for(i=0;i<numStudent;i++) {

       printf("\n\t%-20d",studentId[i]);
       for(j=0;j<numCourse;j++) {

           if(registrationTable[i][j] == 1)
               printf("%-10s","Yes");
           else
               printf("%-10s","No");
       }
   }
}
