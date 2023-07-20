#include<stdio.h>
#include<stdlib.h>
typedef struct candidate_information
{
    char c_name[100];
    int c_id;
    int c_vote;
} Candidate;

typedef struct voter_information
{
    int v_id;
    int v_vote;
} Voter;

Candidate candidatelist[10];
Voter voterlist[100];
int numberofcandidates;
int numberofvoters;

void add_voter()
{
    system("cls");
    printf("\n\t\t\tEnter Number of Voters: ");
    scanf("%d",&numberofvoters);
    for(int i=0; i<numberofvoters; i++)
    {
        printf("\n\t\t\tEnter Voter id: ");
        scanf("%d",&voterlist[i].v_id);
        voterlist[i].v_vote=0;
    }
    create_voterfile();
}

void create_voterfile()
{
    FILE *fc;
    fc=fopen("Voters.txt","w");
    if(fc==NULL)
    {
        printf("ERROR\n");
    }
    else
    {
        for(int i=0; i<numberofvoters; i++)
        {
            fprintf(fc,"\t\t%d\n",voterlist[i].v_id);

        }
    }
    printf("\n\t\t\tVoters have been added successfully.\n");
    fclose(fc);
    int choice;
    printf("\t\t\tPress 1 to go back\n");
    scanf("%d",&choice);
    while(choice!=1)
    {
        printf("\t\t\tPress 1 to go back\n");
        scanf("%d",&choice);
    }
    adminpanel();
}

void user_panel()
{
    system("cls");
    int userid;
    printf("\t\t\t\t\t\t\t------------------------------\n");
    printf("\t\t\t\t\t\t\t------------------------------\n");
    printf("\t\t\t\t\t\t\t|          WELCOME           |\n");
    printf("\t\t\t\t\t\t\t|             TO             |\n");
    printf("\t\t\t\t\t\t\t|          USERPANEL         |\n");
    printf("\t\t\t\t\t\t\t------------------------------\n");
    printf("\t\t\t\t\t\t\t------------------------------\n");
    int opt;
    while(1)
    {
        printf("\n\t\t\t1.View Candidate List\n");
        printf("\t\t\t2.Vote Cast\n");
        printf("\t\t\t0.Exit\n");
        printf("\n\t\t\tEnter your choice : ");
        scanf("%d",&opt);
        if(opt==1)
        {
            voterview_candidate();
        }
        else if(opt==2)
        {
            int count=0;
            printf("\n\t\t\tEnter your userid: ");
            scanf("%d",&userid);
            for(int i=0; i<numberofvoters; i++)
            {
                if(voterlist[i].v_id==userid)
                {
                    if(voterlist[i].v_vote==0)
                    {
                        votecast();
                        voterlist[i].v_vote++;
                        // break;
                    }
                    else
                    {
                        printf("\n\t\t\tYou have already casted a vote.\n");
                        break;
                    }
                }
                else
                {

                    count++;
                }
            }
            if(count==numberofvoters)
            {
                printf("\n\t\t\tUser ID doest not exist\n");
            }
        }

        else if(opt==0)
        {
            main();
        }
    }
}

void user_log()
{
    system("cls");
    char str1[]="Citizen";
    char str2[30];
    char str3[]="1234";
    char str4[30];
    printf("\t\t\tEnter username : ");
    fflush(stdin);
    gets(str2);
    printf("\n\t\t\tEnter password : ");
    gets(str4);


    while((strcmp(str1,str2)!=0)||(strcmp(str3,str4)!=0))
    {
        printf("\n\t\t\tWrong Information!Please try again : \n");
        printf("\t\t\tEnter username : ");
        gets(str2);

        printf("\t\t\tEnter password : ");
        gets(str4);
        strcmp(str1,str2);
        strcmp(str3,str4);

    }
    user_panel();
}

void add_candidate()
{
    system("cls");
    int i;
    printf("\n");
    printf("\t\t\tEnter Number of Candidate : ");
    scanf("%d",&numberofcandidates);
    for(i=0; i<numberofcandidates; i++)
    {
        char ch[500];
        printf("\t\t\tEnter name : ");
        fflush(stdin);
        gets(ch);
        strcpy(candidatelist[i].c_name,ch);
        printf("\t\t\tEnter id : ");
        scanf("%d",&candidatelist[i].c_id);
        candidatelist[i].c_vote = 0;

    }
    create_candidatefile();
}

void create_candidatefile()
{
    FILE *fc;
    fc=fopen("candidates.txt","w");
    if(fc==NULL)
    {
        printf("ERROR\n");
    }
    else
    {
        for(int i=0; i<numberofcandidates; i++)
        {
            fprintf(fc,"\t\t%d %s\n",candidatelist[i].c_id,candidatelist[i].c_name);

        }
    }
    printf("\n\t\t\tCandidate added successfully.\n");
    fclose(fc);
    int choice;
    printf("\t\t\tPress 1 to go back\n");
    scanf("%d",&choice);
    while(choice!=1)
    {
        printf("\t\t\tPress 1 to go back\n");
        scanf("%d",&choice);
    }
    adminpanel();
}

void votecast()
{
    system("cls");
    int candidateid;
    int count2=0;
    while(1)
    {
        printf("\n\t\t\tPlease Enter Serial number of Candidate : ");
        scanf("%d",&candidateid);
        for(int i=0; i<numberofcandidates; i++)
        {
            if(candidateid==candidatelist[i].c_id)
            {
                candidatelist[i].c_vote++;
                count2++;
                break;
            }


        }
        if(count2==0)
        {
            printf("\t\t\t\nEnter Serial number again\n");
        }
        else
        {
            printf("\n\t\t\tVote casted successfully\n");
            break;
        }
    }
}

void view_candidate()
{
    system("cls");
    char ch;
    FILE *fc = fopen("candidates.txt", "r");
    if (fc == NULL)
    {
        printf("No candidates found!\n");
        return 0;
    }
    else
    {
        printf("\n\t\t\t=== Candidate List ===\n");
        while(!feof(fc))
        {
            ch=fgetc(fc);
            printf("%c",ch);

        }
        fclose(fc);
    }
    int choice;
    printf("\t\t\tPress 1 to go back\n");
    scanf("%d",&choice);
    while(choice!=1)
    {
        printf("\t\t\tPress 1 to go back\n");
        scanf("%d",&choice);
    }
    adminpanel();
}

void voterview_candidate()
{
    system("cls");
    char ch;
    FILE *fc = fopen("candidates.txt", "r");
    if (fc == NULL)
    {
        printf("No candidates found!\n");
        return 0;
    }
    else
    {
        printf("\n\t\t\t=== Candidate List ===\n");
        while(!feof(fc))
        {
            ch=fgetc(fc);
            printf("%c",ch);

        }
        fclose(fc);
    }
    int choice;
    printf("\t\t\tPress 1 to go back\n");
    scanf("%d",&choice);
    while(choice!=1)
    {
        printf("\t\t\tPress 1 to go back\n");
        scanf("%d",&choice);
    }
    user_panel();
}

void live_result()
{
    system("cls");
    for(int i=0; i<numberofcandidates; i++)
    {
        printf("\n\t\t\t%d %s  ||Vote: %d\n",candidatelist[i].c_id,candidatelist[i].c_name,candidatelist[i].c_vote);

    }
    printf("\n");

    int choice;
    printf("\t\t\tPress 1 to go back\n");
    scanf("%d",&choice);
    while(choice!=1)
    {
        printf("\t\t\tPress 1 to go back\n");
        scanf("%d",&choice);
    }
    adminpanel();
}

void winner()
{
    system("cls");
    int maxvote=0;
    int id;
    char winnername[100];
    for(int i=0; i<numberofcandidates; i++)
    {
        if(candidatelist[i].c_vote>maxvote)
        {
            id=candidatelist[i].c_id;
            maxvote=candidatelist[i].c_vote;
            strcpy(winnername,candidatelist[i].c_name);
        }

    }
    if(maxvote==0)
    {
        printf("\n\t\t\tNo winner yet.\n");
    }
    else
    {
        printf("\n\t\t\tWinner is %d || %s  || Vote: %d\n",id,winnername,maxvote);
    }
    printf("\n");
    int choice;
    printf("\t\t\tPress 1 to go back\n");
    scanf("%d",&choice);
    while(choice!=1)
    {
        printf("\t\t\tPress 1 to go back\n");
        scanf("%d",&choice);
    }
    adminpanel();
}

void adminpanel()
{

    system("cls");
    printf("\t\t\t\t\t\t\t ------------------------------\n");
    printf("\t\t\t\t\t\t\t ------------------------------\n");
    printf("\t\t\t\t\t\t\t|          WELCOME             |\n");
    printf("\t\t\t\t\t\t\t|             TO               |\n");
    printf("\t\t\t\t\t\t\t|         ADMINPANEL           |\n");
    printf("\t\t\t\t\t\t\t ------------------------------\n");
    printf("\t\t\t\t\t\t\t ------------------------------\n");
    int option;
    while(1)
    {
        printf("\n\t\t\t1.Add Candidates\n");
        printf("\t\t\t2.View Candidate List\n");
        printf("\t\t\t3.Add Voter\n");
        printf("\t\t\t4.Live Result\n");
        printf("\t\t\t5.See the Winner\n");
        printf("\t\t\t0.Exit\n");
        printf("\n\t\t\tEnter your choice : ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            add_candidate();
            break;
        case 2:
            view_candidate();
            break;
        case 3:
            add_voter();
            break;
        case 4:
            live_result();
            break;
        case 5:
            winner();
            break;
        case 0:
            main();
            break;
        default:
            printf("\n\t\t\tTry again.\n");
        }
    }
}

void admin_log()
{
    system("cls");
    char username[15], password[6];

    printf("t\t\t\tEnter username: ");
    fflush(stdin);
    scanf("%[^\n]s",&username);
    printf("\t\t\tEnter Password: ");
    int i=0;
    for(i=0; i<5; i++)
    {
        password[i]=getch();
        printf("%c",'*');
    }
    password[i]='\0';
    while((strcmp(username,"Admin")!=0)||(strcmp(password,"a1234")!=0))
    {
        printf("\n\t\t\tWrong Information!Please try again : \n");
        printf("\t\t\t\tEnter username: ");
        fflush(stdin);
        scanf("%[^\n]s",&username);
        printf("\t\t\tEnter Password: ");
        int i=0;
        for(i=0; i<5; i++)
        {
            password[i]=getch();
            printf("%c",'*');
        }
        password[i]='\0';

    }
    printf("\n");
    adminpanel();

}

void project()
{
    system("cls");
    printf("\n\t\t\t1.In this project these topics are used :\n");
    printf("\n\t\t\t2.File\n");
    printf("\n\t\t\t3.Function\n");
    printf("\n\t\t\t4.Structure\n");
    printf("\n\t\t\t5.Switch-Case\n");
    printf("\n");
    return main();

}

int main()
{
    system("color 0B");
    printf("\t\t\t\t\t\t\t------------------------------\n");
    printf("\t\t\t\t\t\t\t------------------------------\n");
    printf("\t\t\t\t\t\t\t|          WELCOME           |\n");
    printf("\t\t\t\t\t\t\t|             TO             |\n");
    printf("\t\t\t\t\t\t\t|          ELECTION          |\n");
    printf("\t\t\t\t\t\t\t|            2023            |\n");
    printf("\t\t\t\t\t\t\t------------------------------\n");
    printf("\t\t\t\t\t\t\t------------------------------\n");
    printf("\n\t\t\t\t\t\t\t1.Admin\n");
    printf("\t\t\t\t\t\t\t2.User\n");
    printf("\t\t\t\t\t\t\t3.About Project\n");
    printf("\t\t\t\t\t\t\t4.Exit\n");
    while(1)
    {
        int p;
        printf("\n\t\t\tEnter your choice : ");
        scanf("%d",&p);
        if(p==1)
        {
            admin_log();
            break;
        }
        else if(p==2)
        {
            user_log();
            break;
        }
        else if(p==3)
        {
            project();
            break;
        }
        else if(p==4)
        {
            exit(0);
        }
        else
        {
            printf("\n\t\t\tInvalid data input!! Try again.\n");

        }
    }

}
