#include<stdio.h>
#include "StudentData.h"
void launchApp()
{
    struct student data;
    fp=fopen("C:/Training/abc.txt","a+");
    int ch;
    while(1)
    {
        printf("enter choice\n 1.addstudentdetails\n 2.print details\n 3.update\n 4.delete\n 5.Exit");
        scanf("%d",&ch);
        switch(ch)
        {

        case 1: {
            studentinput(&data);
            break;
        }
        case 2:{
            studentdetails(&data);
            break;
        }
        case 3:
        {
            updatedetails(&data);
            break;
        }
        case 4:
        {
            deletedetails(&data);
            break;
        }
        case 5:
            exit(0);
        }

    }
    fclose(fp);
    return 0;
}

void studentinput(struct student *data)
{

    printf("add student details\n");
    printf("enter rollno\n");
    scanf("%d",&data->rollno);
    printf("enter student name\n");
    scanf("%s",&data->name);
    printf("enter gender\n");
    scanf("%s",data->gender);
    printf("enter department\n");
    scanf("%s",data->dept);
    fprintf(fp,"%d %s %s %s\n",data->rollno,data->name,data->gender,data->dept);
   // printf("%d\n",sizeof(data));
    //fclose(fp);
}

void studentdetails(struct student *data)
{
    //FILE *fp;
    //fp=fopen("C:/Training/abc.txt","a+");
    if(fp==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    rewind(fp);
    while(fscanf(fp,"%d %s %s %s\n",&data->rollno,&data->name,&data->gender,&data->dept)!=EOF)
    {
        printf("------------student details-----------\n");
        printf("%d\n",data->rollno);
        printf("%s\n",data->name);
        printf("%s\n",data->gender);
        printf("%s\n",data->dept);
    }
    printf("student record stored sucessfully\n");
    //fclose(fp);

}

void updatedetails(struct student *data)
{
    FILE *fp,*fp1;
    int choice1;
    //struct student temp;
    int id,found=0;
    fp=fopen("C:/Training/abc.txt","r+");
    fp1=fopen("C:/Training/student1.txt","w+");

    printf("enter id to be update\n");
    scanf("%d",&id);
    while(fscanf(fp,"%d %s %s %s",&data->rollno,&data->name,&data->gender,&data->dept)!=EOF)
    {
        printf("inside loop");
        if(data->rollno==id)
        {
            found=1;
            printf("enter choice\n 1.name update\n 2.gender update\n 3.dept update\n");
            scanf("%d",&choice1);
            switch(choice1)
            {
            case 1: {

                printf("enter name to update\n");
                scanf("%s",data->name);
                break;
            }

            case 2:{
                printf("enter the gender\n");
                scanf("%s",data->gender);
                break;
            }

            case 3:{
                printf("enter dept\n");
                scanf("%s",data->dept);
                break;
            }
            }

        }
         fprintf(fp1, "%d %s %s %s\n",data->rollno,data->name,data->gender,data->dept);
    }
    fclose(fp);
    fclose(fp1);
    if(found){
        fp1=fopen("C:/Training/student1.txt","r+");
        fp=fopen("C:/Training/abc.txt","w+");

        while(fscanf(fp1,"%d %s %s %s",&data->rollno,&data->name,&data->gender,&data->dept)!=EOF)
        {
            fprintf(fp, "%d %s %s %s\n",data->rollno,data->name,data->gender,data->dept);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf("record not found\n");
    //fprintf(fp1, "%d %s %s %s\n",data->rollno,data->name,data->gender,data->dept);
    printf("size of id ",sizeof(id));
     printf("size of id ",sizeof(found));
      printf("size of id ",sizeof(choice1));


}


void deletedetails(struct student *data)
{

    FILE *fp,*fp1;
    int id,found=0;
    fp=fopen("C:/Training/abc.txt","r");
    fp1=fopen("C:/Training/student1.txt","w");
    printf("enter id you want to delete\n");
    scanf("%d",&id);

    while(fscanf(fp,"%d %s %s %s",&data->rollno,&data->name,&data->gender,&data->dept)!=EOF)
    {

        printf("innercase\n");
        if(data->rollno==id){
            //printf("id found\n");
            found=1;
        }
        else{
            printf("id not found\n");
            fprintf(fp1, "%d %s %s %s\n",data->rollno,data->name,data->gender,data->dept);

        }
    }
    fclose(fp);
    fclose(fp1);
    if(found){
        fp1=fopen("C:/Training/student1.txt","r");
        fp=fopen("C:/Training/abc.txt","w");

        while(fscanf(fp1,"%d %s %s %s",&data->rollno,&data->name,&data->gender,&data->dept)!=EOF)
        {
            fprintf(fp, "%d %s %s %s\n",data->rollno,data->name,data->gender,data->dept);
        }


        fclose(fp);
        fclose(fp1);
    }

}
