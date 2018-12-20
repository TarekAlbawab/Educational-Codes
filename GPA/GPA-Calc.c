/******************************************************************************

                            Program: GPA Calculator
                  
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

 struct Subject
    {
        char Name[50];
        char Code[50];
        int CreditHour;
        int Score;
        //int PointerScore;
        float GradeScore[50];
    };

  float pointerCalc(int score);
  gradeCalc(int score);
  // void export();

  struct Subject subject[50];

int main()
{
   
    //First part of the Question
    int SubjectNumber;
    int i;
    int j;
    float qualitypoints[50];
    float PointerAccumulate;
    float TotalCredit;
    float GPA;
   printf("========================================================= \n");
   printf("\t Program: GPA CALCULATOR \n");
   printf("========================================================= \n");
   printf("Number of subjects this semester: ");
   scanf("%d",&SubjectNumber);
   printf("\n");
  //SubjectNumber+=1;

  for(i=0;i<SubjectNumber;i++){
    printf("Enter Subject Name: ");
    scanf("%s",&subject[i].Name);

    printf("Enter Subject Code: ");
    scanf("%s",&subject[i].Code);

    printf("Enter Subject Credit Hour: ");
    scanf("%d",&subject[i].CreditHour);

    printf("Enter Subject Score: ");
    scanf("%d",&subject[i].Score);


  //Third part of the Question
    printf("Pointer: %f, ",pointerCalc(subject[i].Score));
    gradeCalc(subject[i].Score);
    printf("\n\n");
    
    qualitypoints[i] = pointerCalc(subject[i].Score)*subject[i].CreditHour;
    //printf("Quality Points: %f\n",qualitypoints[i]);
    PointerAccumulate += qualitypoints[i];
    TotalCredit += subject[i].CreditHour; 
    //printf("\n");
    //subject.GradeScore[i] = pointerCalc(subject[i].Score);
    //    printf("Score:\t%.2f\n",subject.GradeScore[i]);
   }

    printf("\n\n===========================================\n");
    printf("INDEX\tSUBJECT\tCREDIT\tSCORE\tGRADE\tPOINT\n");
    printf("===========================================\n");

   for(i=0;i<SubjectNumber;i++){
     j = i+1;
    printf("%d\t%s\t%d\t",j,subject[i].Name,subject[i].CreditHour);
    printf("%d\t",subject[i].Score);
    gradeCalc(subject[i].Score);
    printf("\t%f\n",pointerCalc(subject[i].Score));
    }
    
    GPA = PointerAccumulate/TotalCredit;
    printf("\n===========================================\n");
    printf("Your GPA for this semester: %f\n",GPA);
    printf("===========================================\n");

   return 0;
}

//Third part of the Question

float pointerCalc(int score){
        float Point;
    if(score>=80 && score <= 100) Point = 4.0;
    else if(score>=75 && score <= 79) Point = 3.7;
    else if(score>=70 && score <= 74) Point = 3.3;
    else if(score>=65 && score <= 69) Point = 3.0;
    else if(score>=60 && score <= 64) Point = 2.7;
    else if(score>=55 && score <= 59) Point = 2.3;
    else if(score>=50 && score <= 54) Point = 2.0;
    else if(score>=47 && score <= 49) Point = 1.7;
    else if(score>=44 && score <= 46) Point = 1.3;
    else if(score>=40 && score <= 43) Point = 1.0;
    else if(score>=0 && score <= 39) Point = 0.0;
    return Point;
    }

      gradeCalc(int score){
      //static  char grade[3];
    if(score>=80 && score <= 100) printf("A");
    else if(score>=75 && score <= 79) printf("A-");
    else if(score>=70 && score <= 74) printf("B+");
    else if(score>=65 && score <= 69) printf("B");
    else if(score>=60 && score <= 64) printf("B-");
    else if(score>=55 && score <= 59) printf("C+");
    else if(score>=50 && score <= 54) printf("C");
    else if(score>=47 && score <= 49) printf("C-");
    else if(score>=44 && score <= 46) printf("D+");
    else if(score>=40 && score <= 43) printf("D");
    else if(score>=0 && score <= 39) printf("E");


    }

  // void export(){
  //   FILE *fp;
  //   struct Staff staff;
  //   FILE *fptr;
  //   fptr=fopen("output.txt","w");
  //   fp=fopen("database.dat","rb");
  //   fprintf(fptr,"ID\tName\tGender\tPhone\tEmail\n\n");

  //   while(1)
  //   {
  //     fread(&staff,sizeof(struct Staff),1,fp);

  //     if(feof(fp))
  //     {
  //       break;
  //     }
  //   fprintf(fptr,"%d\t",staff.id);
  //   fprintf(fptr,"%s\t",staff.name);
  //   fprintf(fptr,"%s\t",staff.gender);
  //   fprintf(fptr,"%d\t",staff.phone);
  //   fprintf(fptr,"%s\t\n\n",staff.email);
  //   }
  // fclose(fp);
  // fclose(fptr);
  // }
