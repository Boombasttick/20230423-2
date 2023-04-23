//动态版通讯录改造

#include <stdio.h>
#include "contact_c.c"

void menu()
{
    printf("****************************\n");
    printf("*** 1.add       2.del    ***\n");
    printf("*** 3.search    4.modify ***\n");
    printf("*** 5.show      6.sort   ***\n");
    printf("*** 7.save      0.exit   ***\n");
    printf("****************************\n");
}

int main()
{
    int input = 0;
    struct Contact con;
    initcontact(&con);
    do
    {
        menu();
        printf("input:>\n");
        scanf("%d",&input);
        switch (input)
        {
        case add:
            addcontact(&con);
            break;
        case del:
            delcontact(&con);
            break;
        case search:
            searchcontact(&con);
            break;
        case modify:
            modifycontact(&con);
            break;
        case show:
            showcontact(&con);
            break;
        case sort:
            break;
        case save:
            savecontact(&con);
            break;
        case exit1:
            destroy(&con);  //清楚通讯录
            printf("exit!!!\n");
            break;
        default:
            printf("error!!!\n");
            break;
        }
    } while (input);
    
    
    return 0;
}