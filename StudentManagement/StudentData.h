
#ifndef STUDENTDATA_H
#define STUDENTDATA_H

struct student{

    int rollno;
    char name[100];
    char gender[20];
    char dept[50];

};
void launchApp();
void studentinput(struct student *);
void studentdetails(struct student *);
void updatedetails(struct student *);
FILE *fp;

#endif // STUDENTDATA_H
