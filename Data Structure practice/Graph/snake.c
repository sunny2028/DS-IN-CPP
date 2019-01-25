#include<stdio.h>
#define r = 20
#define c = 80
using namespace std;
struct node
{
	int x;
	int y;
	char value;
	node *next;
};
node *create(int x,int y)
{
	node *ptr=new node;
	ptr->x=x;
	ptr->y=y;
	ptr->next=NULL;
	ptr->value='*';
}
int main()
{
	node *head=NULL;
	char board [r][c];
	int rmax=19,cmax=79;
	int i,j,r,c;
	for(r=0;r<20;r++)
	{
		for(c=0;c<80;c++)
		{
			if(r==0||r==rmax||c==0||c==cmax)
			board[r][c]='*';
			else
			board[r][c]=' ';
		}
	}
	for(i=15;i<16;i++)
	{
		for(j=15;j<25;j++)
		{
			node *temp;
			temp=create(i,j);
			if(head==NULL)
			head=temp;
			else
			{
				node *t=head;
				while(t->next!=NULL)
				{
					t=t->next;
				}
				t->next=temp;
			}
		}
	}
	node *t=head;
	while(t!=NULL)
	{
		board[t->x][t->y]=t->part;
	}
	for(r=0;r<20;r++)
	{
		for(c=0;c<80;c++)
		{
			printf("%c",board[r][c]);
		}
		printf("\n");
	}
	return 0;
}
