#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
using namespace std;
struct elemt{ char info;
                elemt *suiv;
            };
struct pile{elemt *sommet;};
bool si_vide(pile *p)
{
    bool out=false;
    if((p==NULL)||(p->sommet==NULL))
        out=true;
    return out;
}
void empiler(pile *&p,char valleur)
{  elemt *nov;
  if(p==NULL)
  {
      p = new pile;
      p->sommet=NULL;
  }
  nov = new elemt;
  nov->info=valleur;
  nov->suiv=p->sommet;
  p->sommet=nov;
}
char depiler(pile *&p)
{
    elemt *q;
    char val='v';
    if(si_vide(p)==false)
    { q=p->sommet;
      val=p->sommet->info;
      p->sommet=p->sommet->suiv;
      delete q;

    }
    return val;
}
bool bien_prantase(char ch[20],pile *&p)
{
    char c;
    /*int l;
   l=strlen(ch);
   for(int i=0;i<l;i++)*/
   int i=0;
   while(ch[i]!='\0')
   {
       switch(ch[i])
       {
           case '{':empiler(p,'{');break;
           case '(':empiler(p,'(');break;
           case '[':empiler(p,'[');break;
           case '}': {c=depiler(p);
                       if(c!='{')
                            return false;
                        };break;
            case ')': {c=depiler(p);
                       if(c!='(')
                            return false;
                        };break;
            case ']': {c=depiler(p);
                       if(c!='[')
                            return false;
                        };break;

       }
       i++;
   }
  return true;
}
int main()
{
  pile *p=NULL;
  char ch[20];
  cout<<"donner votre chiane de caractere: \n";
  gets(ch);
  if(bien_prantase(ch,p) && si_vide(p))
     cout<<"la chiane est bien parantase  \n";
  else
    cout<<"la chiane est male parantase  \n";

    return 0;
}
