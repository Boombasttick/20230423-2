#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h> 
#include "contact_c.h"


int Find(struct Contact* p,char NAME[name_max])     //找到返回名字的下标，未找到返回-1；
{
    int i = 0;
    for(i=0;i<p->size;i++)
    {
        if (0 == strcmp(p->data[i].name,NAME))
        {
            return i;
        }
    }
    return -1;
}

void checkcapacity(struct Contact* p);

void loadcontact(struct Contact* pj)
{
    struct PeoInfo tmp = {0};
    FILE* pfread = fopen("contat.dat","rb");
    if(pfread == NULL)
    {
        printf("%s\n",strerror(errno));
        return;
    }
    while(fread(&tmp,sizeof(struct PeoInfo),1,pfread))
    {
        checkcapacity(pj);
        pj->data[pj->size] = tmp;
        pj->size++;
    }
    fclose(pfread);
    pfread = NULL;
}

void initcontact(struct Contact* pa)
{
    pa->data = malloc(A*sizeof(struct PeoInfo));
    if(pa->data==NULL)
    {
        return;
    }
    pa->size = 0;
    pa->capacity = A;
    loadcontact(pa);
}

void checkcapacity(struct Contact* p)
{
    if(p->size == p->capacity)
    {
        struct PeoInfo* ptr = realloc(p->data,(p->capacity+2)*sizeof(struct PeoInfo));
        if(ptr != NULL)
        {
            printf("add success!!\n");
            p ->data=ptr;
            p->capacity +=2;
        }
        else
        {
            printf("error\n");
        }
    }
}

void addcontact(struct Contact* pb)
{
    checkcapacity(pb);
    printf("name:>");
    scanf("%s",pb->data[pb->size].name);
    printf("age:>");
    scanf("%d",&(pb->data[pb->size].age));
    printf("sex:>");
    scanf("%s",pb->data[pb->size].sex);
    printf("tele:>");
    scanf("%s",pb->data[pb->size].tele);
    printf("addr:>");
    scanf("%s",pb->data[pb->size].addr);
        pb->size++;
        printf("success!\n");
}

void showcontact(const struct Contact* pc)
{
    if(pc->size == 0)
    {
        printf("vacant!!");
    }
    else
    {
        int i = 0;
        printf("%8s\t%4s\t%5s\t%12s\t%10s\n","name","age","sex","tele","addr");
        for(i=0 ; i<pc->size ; i++)
        {
            printf("%8s\t%4d\t%5s\t%12s\t%10s\n",
            pc->data[i].name,
            pc->data[i].age,
            pc->data[i].sex,
            pc->data[i].tele,
            pc->data[i].addr);
        }
    }
}




void delcontact(struct Contact* pd)
{
    char NAME[name_max];
    printf("input dele name:>");
    scanf("%s",NAME);
    int ret = Find(pd,NAME);
    if (ret == -1)
    {
        printf("donot find\n");
    }
    else
    {
        int j = 0;
        for (j=ret;j<pd->size-1;j++)
        {
            pd->data[j] = pd->data[j+1];
        }
        pd->size--;
        printf("dele success!!!\n");
    }
}

void searchcontact(struct Contact* pe)
{
    char NAME[name_max];
    printf("input search name:>");
    scanf("%s",NAME);
    int ret = Find(pe,NAME);
    if (-1 == ret)
    {
        printf("dnnot fand!\n");
    }
    else
    {
        printf("%8s\t%4s\t%5s\t%12s\t%10s\n","name","age","sex","tele","addr");
        printf("%8s\t%4d\t%5s\t%12s\t%10s\n",
            pe->data[ret].name,
            pe->data[ret].age,
            pe->data[ret].sex,
            pe->data[ret].tele,
            pe->data[ret].addr);
    }
}

void modifycontact(struct Contact* pf)
{
    char NAME[name_max];
    printf("input modify name:>");
    scanf("%s",NAME);
    int ret = Find(pf,NAME);
    if (-1 == ret)
    {
        printf("dnnot fand!\n");
    }
    else
    {
        printf("name:>");
        scanf("%s",pf->data[ret].name);
        printf("age:>");
        scanf("%d",&(pf->data[ret].age));
        printf("sex:>");
        scanf("%s",pf->data[ret].sex);
        printf("tele:>");
        scanf("%s",pf->data[ret].tele);
        printf("addr:>");
        scanf("%s",pf->data[ret].addr);
        printf("success modify!!\n");
    }
}

void destroy(struct Contact* pg)
{
    free(pg->data);
    pg->data = NULL;
}

void savecontact(struct Contact* ph)
{
    FILE* pfwrite = fopen("contat.dat","wb");
    if(pfwrite == NULL)
    {
        printf("%s\n",strerror(errno));
        return;
    }
    int i = 0;
    for(i=0;i<ph->size;i++)
    {
        fwrite(&(ph->data[i]),sizeof(struct PeoInfo),1,pfwrite);
    }
    fclose(pfwrite);
    pfwrite = NULL;
}