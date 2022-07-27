#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
    char fname[100], lname[100], id[100], num[20];
    int sem;
    double cg[100];
};
int menu()
{
    int count;
    printf("\n\n----------Select an Option---------\n");
    printf("1. Show Student Information\n");
    printf("2. Add Student Information\n");
    printf("3. Delete Student Information\n");
    printf("4. Update Student CGPA\n");
    printf("5. Find Best Student's CGPA\n");
    printf("6. PG Numbers\n");
    printf("7. Exit\n");
    scanf("%d", &count);
    return count;
}
void pm(char *nts)
{
    if(nts == 'ss')
        printf("\nSaved Successfully\n\n");
    else if(nts == 'fe')
        printf("\nFile Not Found\n\n");
    else if(nts == 'tc')
        printf("Task Completed Successfully\n\n");
    else if(nts == 'em')
        printf("\n----------Ended----------\n");
}
void showinfo()
{
    struct student s[100];
    int i, j, n;
    FILE *fl;
    fl = fopen("file.txt", "r");
    if(!fl)
    {
        pm('fe');
        exit(1);
    }
    else
    {
        j = 0;
        while(fscanf(fl, "%s", &s[j].fname)==1)
        {
            fscanf(fl, "%s\n", &s[j].lname);
            fscanf(fl, "%s\n", &s[j].id);
            fscanf(fl, "%s", &s[j].num);
            fscanf(fl, "%d\n", &s[j].sem);
            for(i=0; i<s[j].sem; i++)
            {
                fscanf(fl, "%lf ", &s[j].cg[i]);
            }
            j++;
        }
        fclose(fl);
        n = j;
        for(j =0; j<n; j++)
        {
            printf("%s\n", s[j].fname);
            printf("%s\n", s[j].lname);
            printf("%s\n", s[j].id);
            printf("%s\n", s[j].num);
            printf("%d\n", s[j].sem);
            for(i=0; i<s[j].sem; i++)
            {
                printf("%.2lf ", s[j].cg[i]);
            }
            printf("\n\n");
        }
        pm('tc');
    }
}
void addinfo()
{
    struct student s;
    int i;
    FILE *fl;
    fl=fopen("file.txt", "a");

    if(!fl)
    {
        pm('fe');
        exit(1);
    }
    else
    {
        printf("Enter First Name : ");
        scanf("%s",s.fname);
        printf("Enter Last Name : ");
        scanf("%s",s.lname);
        printf("Enter Matric ID : ");
        scanf("%s",s.id);
        printf("Enter Mobile Number : ");
        scanf("%s",s.num);
        printf("Enter Number of semester completed : ");
        scanf("%d",&s.sem);
        printf("Enter CGPA : ");
        for(i=0; i<s.sem; i++)
            scanf("%lf",&s.cg[i]);


        fprintf(fl,"%s\n",s.fname);
        fprintf(fl,"%s\n",s.lname);
        fprintf(fl,"%s\n",s.id);
        fprintf(fl,"%s\n",s.num);
        fprintf(fl,"%d\n",s.sem);
        for(i=0; i<s.sem; i++)
            fprintf(fl,"%.2lf ",s.cg[i]);
        fprintf(fl,"\n");
        fclose(fl);
        pm('ss');
    }
}
void delinfo()
{
    struct student s[100];
    int i, j, n, result;
    char mrid[100];
    double avg, cgp=0;
    FILE *fl;
    fl = fopen("file.txt", "r");
    if(!fl)
    {
        pm('fe');
        exit(1);
    }
    else
    {
        j = 0;
        while(fscanf(fl, "%s\n", s[j].fname)==1)
        {
            fscanf(fl, "%s\n", s[j].lname);
            fscanf(fl, "%s\n", s[j].id);
            fscanf(fl, "%s\n", s[j].num);
            fscanf(fl, "%d\n", &s[j].sem);
            for(i=0; i<s[j].sem; i++)
            {
                fscanf(fl, "%lf ", &s[j].cg[i]);
            }
            j++;
        }
        n = j;
        fclose(fl);
        fl = fopen("file.txt", "w");
        if(!fl)
        {
            pm('fe');
            exit(1);
        }
        printf("Enter Metric ID: ");
        scanf("%s", mrid);
        for(i=0; i<n; i++)
        {
            result = strcmp(mrid, s[i].id);
            if(result != 0)
            {
                for(i = 0; i < s[i].sem; i++)
                {
                    if(strcmp(s[i].id,mrid))
                    {

                        fprintf(fl, "%s\n%s\n", s[i].fname,s[i].lname);
                        fprintf(fl, "%s\n%s", s[i].id,s[i].num);
                        fprintf(fl, "\n%d\n", s[i].sem);
                        for(j=0; j<s[i].sem; j++)
                            fprintf(fl,"%0.2lf ",s[i].cg[j]);
                        printf("\n\n");
                    }
                }
            }
            else
            {
                for(j=0; j<s[i].sem; j++)
                {
                    cgp+=s[i].cg[j];
                }
                avg = cgp/s[i].sem;
                printf("This Student's CGPA : %.2lf\n",avg);
            }
        }
        fclose(fl);
        pm('tc');

    }
}
void upinfo()
{
    struct student s[100];
    int i, j, k, n, result;
    char nid[100];
    double ncg;
    FILE *fl;
    fl = fopen("file.txt", "r");
    if(!fl)
    {
        pm('fe');
        exit(1);
    }
    else
    {
        j = 0;
        while(fscanf(fl, "%s", &s[j].fname)==1)
        {
            fscanf(fl, "%s\n", &s[j].lname);
            fscanf(fl, "%s\n", &s[j].id);
            fscanf(fl, "%s", &s[j].num);
            fscanf(fl, "%d\n", &s[j].sem);
            for(i=0; i<s[j].sem; i++)
            {
                fscanf(fl, "%lf ", &s[j].cg[i]);
            }
            j++;
        }
        fclose(fl);
        n = j;
        printf("Enter Metric ID:");
        scanf("%s", nid);
        printf("Enter New Semester CGPA:");
        scanf("%d", &ncg);
        fl = fopen("file.txt", "w");
        if(!fl)
        {
            pm('fe');
            exit(1);
        }
        for(i=0; i<n; i++);
        {
            result=strcmp(nid, s[i].id);
            if(result==0)
            {
                k=s[i].sem;
                s[i].cg[k]=ncg;
                s[i].sem = s[i].sem++;
            }
        }
        for(i=0; i<n; i++)
        {
            fprintf(fl,"%s\n",s[i].fname);
            fprintf(fl,"%s\n",s[i].lname);
            fprintf(fl,"%s\n",s[i].id);
            fprintf(fl,"%s\n",s[i].num);
            fprintf(fl,"%d\n",s[i].sem);
            for(j=0; j<s[i].sem; j++)
                fprintf(fl,"%.2lf ",s[i].cg[j]);
            fprintf(fl,"\n");
        }
        fclose(fl);
        pm('tc');
    }
}
void bestcg()
{
    struct student s[100];
    int i, pos, max, n, result, avg, j;
    char nid[100];
    double ncg;
    FILE *fl;
    fl = fopen("file.txt", "r");
    if(!fl)
    {
        pm('fe');
        exit(1);
    }
    else
    {
        j = 0;
        while(fscanf(fl, "%s", &s[j].fname)==1)
        {
            fscanf(fl, "%s\n", &s[j].lname);
            fscanf(fl, "%s\n", &s[j].id);
            fscanf(fl, "%s\n", &s[j].num);
            fscanf(fl, "%d\n", &s[j].sem);
            for(i=0; i<s[j].sem; i++)
            {
                fscanf(fl, "%lf ", &s[j].cg[i]);
            }
            j++;
        }
    }
    fclose(fl);
    n = j;
    for(i=0; i<n; i++)
    {
        for(j=0,avg=0; j<s[i].sem; j++)
        {
            avg+=s[i].cg[j];
        }
        if(avg/s[i].sem>max)
        {
            max=avg/s[i].sem;
            pos=i;
        }
    }
    printf("Highest CGPA : %.2lf\n",max);
    printf("Student's Name : %s %s\n",s[pos].fname,s[pos].lname);
}
void pgnum()
{
    struct student s[100];
    int i=0,j=0,k=0, n;
    int pg[100][15];
    FILE *fl;
    fl = fopen("file.txt", "r");
    if(!fl)
    {
        pm('fe');
        exit(1);
    }
    else
    {
        j = 0;
        while(fscanf(fl, "%s", s[j].fname)==1)
        {
            fscanf(fl, "%s\n", s[j].lname);
            fscanf(fl, "%s\n", s[j].id);
            fscanf(fl, "%s\n", s[j].num);
            fscanf(fl, "%d\n", s[j].sem);
            for(i=0; i<s[j].sem; i++)
            {
                fscanf(fl, "%lf ", &s[j].cg[i]);
            }
            j++;
        }
        fclose(fl);
        n = j;
        for(int j=0; j<n; j++)
        {
            if(s[j].num[0]=='0' && s[j].num[1]=='1' && (s[j].num[2]=='3' || s[j].num[2]=='7'))
            {
                strcpy(pg[k++],s[j].num);
            }
        }
        for(i=0; i<k; i++)
        {
            printf("%s\n",pg[i]);
        }
    }
}

int main()
{
    int count;
    do
    {
        count = menu();
        switch(count)
        {
        case 1:
            showinfo();
            break;
        case 2:
            addinfo();
            break;
        case 3:
            delinfo();
            break;
        case 4:
            upinfo();
            break;
        case 5:
            bestcg();
            break;
        case 6:
            pgnum();
            break;
        }
    }
    while(count !=7);
    pm('em');
}
