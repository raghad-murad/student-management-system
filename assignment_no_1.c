#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

//NAME&ID Raghad Murad 1212214
//lecture section 4 & lab section 8L

void displayMainMenu();
void addStudent(int ids[], double avgs[], int *size);
void removeStudent(int ids[], double avgs[], int *size);
void searchForStudent(int ids[], double avgs[], int *size);
void uploadDataFile(int ids[], double avgs[], int *size);
void updateDataFile(int ids[], double avgs[], int *size);
void PrintStudents(int ids[], double avgs[], int *size);
void exitsystem();

int main()
{
    int ids[MAXSIZE];
    double avgs[MAXSIZE];
    int size=0;
    printf("Welcome to My Student Management System :\n\n");
    int Operation;
    uploadDataFile(ids,avgs,&size);
    displayMainMenu();
    scanf("%d",&Operation);
    while(Operation!=5)
    {
        switch(Operation)
        {
        case 1:
            addStudent(ids,avgs,&size);
            break;
        case 2:
            removeStudent(ids,avgs,&size);
            break;
        case 3:
            searchForStudent(ids,avgs,&size);
            break;
        case 4:
            PrintStudents(ids,avgs,&size);
            break;
        default:
            printf("No such operation! Please try again.\n\n");
        }
        displayMainMenu();
        scanf("%d",&Operation);
    }
    updateDataFile(ids,avgs,&size);
    exitsystem();
    return 0;
}
void displayMainMenu()
{
    printf("Please Select an Operation (1-4):\n");
    printf("1- Add a Student:\n");
    printf("2- Remove a Student:\n");
    printf("3- Search for a Student:\n");
    printf("4- Print Student List:\n");
    printf("5- Exit System:\n\n");
}
void uploadDataFile(int ids[],double avgs[],int *size)
{
    printf("Uploading data file ...\n");
    FILE *fpt_in;
    fpt_in=fopen("students.txt","r");
    int status = fscanf(fpt_in,"%d%lf",&ids[0],&avgs[0]);
    int i=1;
    while(status != EOF)
    {
        status=fscanf(fpt_in,"%d%lf",&ids[i],&avgs[i]);
        (*size)++;
        i++;
    }
    printf("Data File uploaded\n\n\n");
    fclose(fpt_in);
}
void addStudent(int ids[],double avgs[],int *size)
{
    int id,idinlist=0;
    double avg;
    if(*size<MAXSIZE)
    {
        printf("Enter id number for Student\n");
        scanf("%d",&id);
        for(int i=0; i<*size; i++)
        {
            if(ids[i]==id)
                idinlist=1;
        }
        if(idinlist==1)
            printf("Student with id %d does exist\n\n",id);
        else
        {
            (*size)++;
            printf("Enter avg of Student\n");
            scanf("%lf",&avg);
            for(int j=*size-1; j>=0; j--)
            {
                ids[j+1]=ids[j];
                avgs[j+1]=avgs[j];
            }
            ids[0]=id;
            avgs[0]=avg;
            for(int i=0; i<*size-1; i++)
            {
                for(int j=i+1; j<*size; j++)
                {
                    if(ids[i]>ids[j])
                    {
                        int temp=ids[i];
                        ids[i]=ids[j];
                        ids[j]=temp;
                        double temp2=avgs[i] ;
                        avgs[i]=avgs[j];
                        avgs[j]=temp2;
                    }
                }
            }
            printf("Student with id %d has been added\n\n",id);
        }
    }

}
void removeStudent(int ids[],double avgs[],int *size)
{
    int id,idinlist=0,index;
    if(*size>0)
    {
        printf("Enter id number for Student to remove\n");
        scanf("%d",&id);
        for(int i=0; i<*size; i++)
        {
            if(ids[i]==id)
            {
                idinlist=1;
                index=i;
            }
        }
        if(idinlist==0)
            printf("Student with id %d does not exist\n\n",id);
        else
        {
            for(int i=index; i<*size-1; i++)
            {
                ids[i]=ids[i+1];
                avgs[i]=avgs[i+1];
            }
            (*size)--;
            printf("Student with id %d has been removed \n\n",id);
        }
    }
}
void searchForStudent(int ids[],double avgs[],int *size)
{
    int id,index,idinlist=0;
    if(*size>0)
    {
        printf("Enter id number for Student to search for\n");
        scanf("%d",&id);
        for(int i=0; i<*size; i++)
        {
            if(ids[i]==id)
            {
                idinlist=1;
                index=i;
            }
        }
        if(idinlist==0)
            printf("Student with id %d does not exist\n\n",id);
        else
        {
            printf(" id# = %d     avg = %0.2f \n\n",ids[index],avgs[index]);
        }
    }
}
void PrintStudents(int ids[], double avgs[], int *size)
{
    for(int i=0; i<*size; i++)
    {
        printf(" id# = %d     avg = %0.2f\n",ids[i],avgs[i]);
    }
    printf("\n");
}
void updateDataFile(int ids[],double avgs[],int *size)
{
    printf("\nUpdating data file ...\n");
    FILE *fpt_out;
    fpt_out=fopen("students.txt","w");
    for(int i=0; i<*size; i++)
    {
        fprintf(fpt_out,"%d  %0.2f\n",ids[i],avgs[i]);
    }
    printf("Data File updated\n");
    fclose(fpt_out);
}
void exitsystem()
{
    printf("Thank you for using My Student Management System. GoodBye.\n\n");
}