#include <stdio.h>
#include<stdlib.h>
#include "BigInteger.h"
struct BigInteger  initialize(char *s)
{
    int d,i;
    struct BigInteger  b1;
    b1.l=0;
    b1.sign=0;
    b1.head=NULL;
    if(s[0]=='-')
        b1.sign=1;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
        b1.l+=1;
        d=s[i]-'0';
        b1=insert(b1,d);
        }

    }
    return b1;
}
struct BigInteger truncate(struct BigInteger  b)
{
    if(!b.head)
        return b;
    while(b.head->next!=NULL && b.head->data==0)
    {
                struct node *temp=b.head;
                b.head=b.head->next;
                free(temp);
    }
    return b;
}
void display(struct BigInteger b1)
{
    b1=truncate(b1);
    struct node *itr=b1.head;
    while(itr!=NULL)
    {
        printf("%d",itr->data);
        itr=itr->next;
    }
    printf("\n");
}
struct BigInteger  insert2(struct BigInteger b1,int n)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->data=n;
        temp->next=NULL;
        if(b1.head==NULL)
        {
            b1.head=temp;
        }

        else
        {
            struct node *itr=b1.head;
            while(itr->next!=NULL)
                itr=itr->next;
            itr->next=temp;
        }
        return b1;
}
struct BigInteger  insert(struct BigInteger b1,int n)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->data=n;
        temp->next=NULL;
        if(b1.head==NULL)
        {
            b1.head=temp;
        }
        else
        {
           temp->next=b1.head;
           b1.head=temp;
        }
        return b1;
}
struct BigInteger changesign(struct BigInteger b)
{
    if(!b.head)
        return b;
    struct node *itr=b.head;
    while(itr!=NULL)
    {
        itr->data=-1*itr->data;
        itr=itr->next;
    }
    return b;
}
int compare(struct BigInteger b1,struct BigInteger b2)
{
    if(b1.l>b2.l)
        return 1;
    else if(b1.l<b2.l)
        return -1;
    else{
        int res=0;
        struct node *p1=b1.head,*p2=b2.head;
        while(p1)
        {
            if(p1->data>p2->data)
                res=1;
            else if(p1->data<p2->data)
                res=-1;
            p1=p1->next;
            p2=p2->next;
        }
        return res;
    }
}
struct BigInteger  add(struct BigInteger b1,struct BigInteger b2)
{
    struct BigInteger res;
    res.head=NULL;
    int cin=0,c,sum;
    struct node *p1=b1.head;
    struct node *p2=b2.head;
    if(b1.sign==1 && b2.sign==1)
        res.sign=1;
    if(b1.sign==0 && b2.sign==0)
        res.sign=0;
    if(!p1 && !p2)
        return res;
    while(p1 && p2)
    {
        sum=cin+p1->data+p2->data;
        if(sum/10!=0)
        {
            
            c=sum;
            sum=sum%10;
            cin=c/10;
            res=insert(res,sum);
        }
        else{
            res=insert(res,sum);
            cin=0;
        }
        p1=p1->next;
        p2=p2->next;
    }
    while(p2)
    {
        res=insert(res,p2->data+cin);
        cin=0;
        p2=p2->next;
    }
     while(p1)
    {
        res=insert(res,p1->data+cin);
        cin=0;
        p1=p1->next;
    }
            if(cin!=0)
                res=insert(res,cin);
    if(res.sign==1)
        res.head->data=-1*res.head->data;
            return res;
}
struct BigInteger  add2(struct BigInteger b1,struct BigInteger b2)
{
    struct BigInteger res;
    res.head=NULL;
    int cin=0,c,sum;
    struct node *p1=b1.head;
    struct node *p2=b2.head;
    while(p1 && p2)
    {
        sum=cin+p1->data+p2->data;
        if(sum/10!=0)
        {
            
            c=sum;
            sum=sum%10;
            cin=c/10;
            res=insert2(res,sum);
        }
        else{
            res=insert2(res,sum);
            cin=0;
        }
        p1=p1->next;
        p2=p2->next;
    }
    while(p2)
    {
        res=insert2(res,p2->data+cin);
        cin=0;
        p2=p2->next;
    }
     while(p1)
    {
        res=insert2(res,p1->data+cin);
        cin=0;
        p1=p1->next;
    }
            if(cin!=0)
                res=insert2(res,cin); 
            return res;
}
struct BigInteger  modadd(struct BigInteger b1,struct BigInteger b2)
{
    struct BigInteger res;
    res.head=NULL;
    int cin=0,c,sum;
    struct node *p1=b1.head;
    struct node *p2=b2.head;
    while(p1 && p2)
    {
        sum=cin+p1->data+p2->data;
        if(sum/10!=0)
        {
            
            c=sum;
            sum=sum%10;
            cin=c/10;
            res=insert(res,sum);
        }
        else{
            res=insert(res,sum);
            cin=0;
        }
        p1=p1->next;
        p2=p2->next;
    }
    while(p2)
    {
        res=insert(res,p2->data+cin);
        cin=0;
        p2=p2->next;
    }
     while(p1)
    {
        res=insert(res,p1->data+cin);
        cin=0;
        p1=p1->next;
    }
            if(cin!=0)
                res=insert(res,cin); 
            return res;
}
struct BigInteger  sub(struct BigInteger b1,struct BigInteger b2)
{
    struct BigInteger res;
    res.head=NULL;
    int b=0,diff;
    struct node *p1,*p2,*bor;
    if(b1.sign==0 && b2.sign==1)
    {
        res.sign=0;
        res=modadd(b1,b2);
        return res;
    }
    if(b1.sign==1 && b2.sign==0)
    {
        if(compare(b1,b2)==-1)  
        {
            res=modadd(b1,b2);
            res.head->data=-1*res.head->data;
            return res;
        }
         res=modadd(b1,b2);
            res.head->data=-1*res.head->data;
            return res;
    }
    if(compare(b1,b2)==-1)
    {
        res.sign=1;
        p2=b1.head;
        p1=b2.head;
    }
    else{
        res.sign=0;
        p1=b1.head;
        p2=b2.head;
    }
    if(!p1 && !p2)
        return res;
    while(p1&&p2)
    {
        if(p1->data<p2->data)
        {
            bor=p1;
            b=1;
            while(bor->next->data==0)
            {
                bor->next->data=9;
                bor=bor->next;
            }
            bor->next->data-=1;
            p1->data+=10;
        }
        diff=p1->data-p2->data;
        res=insert(res,diff);
        p1=p1->next;
        p2=p2->next;
    }
   while(p1)
    {
        res=insert(res,p1->data);
        p1=p1->next;
    }
    if(res.sign==1)
        {
        res.head->data=-1*res.head->data; 
        }
        res=truncate(res);
    return res;
}
struct BigInteger mul(struct BigInteger b1,struct BigInteger b2)
{
 int pro,shift=0,cin,i;
     struct BigInteger res,res1,res2;
     res=initialize("0");
     struct node *p1,*p2,*temp;
      if(b1.l>b2.l)
        {
            p1=b1.head;
             p2=b2.head;
              temp=b1.head;
        }
    else{
          p1=b2.head;
         p2=b1.head;
        temp=b2.head;
    }
    while(p2)
    {
         res1=initialize("");
         res2=initialize("0");
         cin=0;
        p1=temp;
        while(p1)
        {
              pro=(p1->data*p2->data)+cin;
              cin=pro/10;
            if(cin!=0)
                    res1=insert(res1,pro%10);
            else
                    res1=insert(res1,pro);
            p1=p1->next;
        }
        for(i=0;i<shift;i++)
            res1=insert2(res1,0);
        if(cin>0)
            {
            res1=insert(res1,cin);
            }
         res2=add(res1,res2);
            res=add2(res2,res);
         p2=p2->next;
          shift++;  
    }
     res=rev(res);
     if((b1.sign==1 && b2.sign==0) || (b1.sign==0 && b2.sign==1))
       res.head->data=-1*res.head->data;
    if(b1.sign==1 && b2.sign==1)
              return res;
   return res;
}
struct BigInteger  div1(struct BigInteger b1,struct BigInteger b2)
{
    struct BigInteger res = initialize("0");
    return res;
    }
       
struct BigInteger rev(struct BigInteger b)
{
    struct node *head=b.head;
    if(!head)
         return b;
    struct node *prev=NULL,*cur=head,*n=head;
    while(n!=NULL)
    {
        n=n->next;
        cur->next=prev;
        prev=cur;
        cur=n;
    }
    b.head=prev;
    return b;
}
