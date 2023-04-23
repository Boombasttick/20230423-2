#include <stdio.h>
#include <stdlib.h>

// #define max 1000
#define A 3
#define name_max 20
#define tele_max 12
#define sex_max 5
#define addr_max 30

enum F
{
    exit1,
    add,
    del,
    search,
    modify,
    show,
    sort,
    save
};

struct PeoInfo
{
    char name[name_max];
    int age;
    char sex[sex_max];
    char tele[tele_max];
    char addr[addr_max];
};

struct Contact
{
    struct PeoInfo* data;
    int size;
    int capacity;
};


void initcontact(struct Contact* pa);
void addcontact(struct Contact* pb);
void showcontact(const struct Contact* pc);
void delcontact(struct Contact* pd);
void searchcontact(struct Contact* pe);
void modifycontact(struct Contact* pf);
void destroy(struct Contact* pg);
void savecontact(struct Contact* ph);
void loadcontact(struct Contact* pj);