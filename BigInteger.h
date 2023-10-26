#ifndef BigInteger_h
#define BigInteger_h
struct node 
{
    int data;
    struct node *next;
};
    struct BigInteger
        {
            struct node *head;
            int l,sign;
        };
void display(struct BigInteger );
struct BigInteger truncate(struct BigInteger);
int compare(struct BigInteger,struct  BigInteger);
struct BigInteger  initialize(char *);
struct BigInteger  insert2(struct BigInteger ,int );
struct BigInteger  insert(struct BigInteger ,int );
struct BigInteger add(struct BigInteger,struct BigInteger);
struct BigInteger add2(struct BigInteger,struct BigInteger);
struct BigInteger sub(struct BigInteger ,struct BigInteger);
struct BigInteger mul(struct BigInteger ,struct BigInteger);
struct BigInteger div1(struct BigInteger ,struct BigInteger);
struct BigInteger rev(struct BigInteger );
#endif