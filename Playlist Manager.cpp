#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
struct playlist
{
  char song[20];
  int time;
  struct playlist* next;
  struct playlist* prev;
}*p;
void menu_play()
{
	printf("1. Continue/Next\n2. Previous\n3. Skip Forward\n4. Skip Backward\n5. Skip To\n6. Stop/Exit\n");
}
void menu_insert()
{
	printf("1.Insert song at the beginning\n2.Insert song at a position\n3.Insert song at the end\n");
}
void menu_delete()
{
	printf("1.Delete song at the beginning\n2.Delete song at a position\n3.Delete song at the end\n");
}
void menu()
{
	printf("1.Insert\n2.Delete\n3.Display the list\n4.Play\n5.Save\n6.Exit\n");
	printf("Enter number according to your choice: ");
}
void insertAtBeginning(struct playlist** p,char ele[],int t)
{
  struct playlist* q = (struct playlist*)malloc(sizeof(struct playlist));
  strcpy(q->song,ele);
  q->time = t;
  if(*p == NULL)
  {
  	*p = q;
	q->next = *p;
  	q->prev = *p;
  	return;
  }
  else
  {
  q->next = *p;
  q->next->prev = q;
  struct playlist* temp = *p;
    while (temp->next != *p)
  		temp = temp->next;
    q->prev = temp;
    temp->next = q;
  *p = q;
  return;
  }
}
void insertAt(struct playlist** p,char ele[],int t)
{
  int i=0;
  printf("Enter the song after which you want to insert the new song: ");
  char s[20];
  scanf("%s",s);
  struct playlist* q = *p;
  while(strcmp(q->song,s) != 0)
  {
  	q=q->next;
  	if(q == *p)
	{
  		i = 1;
		break;		
	}
  }
  if(i == 1)
  {
  	printf("Entered song is not present in the playlist\n");
  	return;
  }
  else
  {
  	struct playlist* temp = (struct playlist*)malloc(sizeof(struct playlist));
  	strcpy(temp->song,ele);
  	temp->time = t;
  	temp->prev = q;
  	temp->next = q->next;
  	q->next = temp;
  	return;
  }
}
void insertAtEnd(struct playlist** p, char ele[],int t) 
{
  struct playlist* q = (struct playlist*)malloc(sizeof(struct playlist));
  struct playlist* last = *p;
  strcpy(q->song,ele);
  q->time = t;
  q->next = *p;

  if (*p == NULL) {
    *p = q;
    return;
  }
  else
  {
  	while (last->next != *p)
    	last = last->next;
  	q->prev = last;
  	last->next = q;
  	q->next->prev = q;
  	return;
  }
}
void deleteAtBeginning(struct playlist** p)
{
  struct playlist* q = *p;
  if (*p == NULL)
  {
    printf("No song to delete\n");
    return;
  }
  else
  {
  	if(q->next == *p)
	{
		*p = NULL;
		free(q); 
	}
	else
	{
  		q = q->next;
		struct playlist* temp = *p;
    	while (temp->next != *p)
  			temp = temp->next;
  		q->prev = temp;
  		temp->next = q;
  		free(*p);
  		*p = q;
  		return;
  	}
  }
}
void deleteAtEnd(struct playlist** p)
{
	struct playlist* q = *p;
	struct playlist*temp = NULL;
  if (*p == NULL)
  {
    printf("No song to delete\n");
    return;
  }
  else
	{
	if(q->next == *p)
	{
		*p = NULL;
		free(q); 
	}
	else
	{
  	 while(q->next->next != *p)
	   q=q->next;
	 temp = q->next;
	 q->next = *p;
	 free(temp);	
	return;
	}
   }
}
void deleteAt(struct playlist** p)
{
  int i=0;
  char pos[20];
  printf("Enter the song which you want to delete: ");
  scanf("%s",pos);
  struct playlist* q = *p,*temp;
  if (*p == NULL)
  {
    printf("No song to delete\n");
    return;
  }
  else
	{
  	 while(strcmp(q->song,pos) != 0)
	  {
	    q=q->next;
	    if(q == *p)
	    {
	    	i = 1;
	    	break;
		}
	  }
	  if(i = 1)
	  {
	  	printf("Entered song is not present in the playlist\n");
	  	return;
	  }
	 temp = q;
	 q->prev->next = temp->next;
	 q->next->prev = q->prev;
	 free(temp);	
	}
	return;
}
void insert()
{
	int choice;
	int m,s,t;
	menu_insert();
	scanf("%d",&choice);
	switch(choice)
  	{
		case 1:
  			{
  				printf("Insert song at beginning\n");
  				char ele[20];
  				printf("Enter song: ");
  				scanf("%s",ele);
  				printf("Enter song duration\n");
  				printf("Min: ");
  				scanf("%d",&m);
  				printf("Sec: ");
  				scanf("%d",&s);
  				t = m*60+s;
				insertAtBeginning(&p,ele,t);
  				break;			
			}	
		case 2:
			{
				printf("Insert song in between\n");
				char ele[20];
  				printf("Enter new song: ");
  				scanf("%s",ele);
  				printf("Enter song duration\n");
  				printf("Min: ");
  				scanf("%d",&m);
  				printf("Sec: ");
  				scanf("%d",&s);
  				t = m*60+s;
				insertAt(&p,ele,t);
				break;
			}
		case 3:
			{
				printf("Insert song at end\n");
				char ele[20];
  				printf("Enter song: ");
  				scanf("%s",ele);
  				printf("Enter song duration\n");
  				printf("Min: ");
  				scanf("%d",&m);
  				printf("Sec: ");
  				scanf("%d",&s);
  				t = m*60+s;
				insertAtEnd(&p,ele,t);
				break;	
			}
	}
}
void delete_()
{
	int choice;
	menu_delete();
	scanf("%d",&choice);
	switch(choice)
  	{
		case 1:
			{
				printf("Delete song at beginning\n");
				deleteAtBeginning(&p);
				break;
			}
		case 2:
			{
				printf("Delete song in between\n");
				deleteAt(&p);
				break;
			}
		case 3:
			{
				printf("Delete song at end\n");
				deleteAtEnd(&p);
				break;
			}
	}
}
void display(struct playlist** p)
{
  struct playlist *q = *p;
  if(q == NULL)
  {
  	printf("No songs in the playlist\n");
  	return;
  }
  else
  {
  	while (q->next != *p)
  	{
    	printf("%s....%2dm %2dsec\n", q->song,q->time/60,q->time%60);
    	q = q->next;
  	}
  	printf("%s....%2dm %2dsec\n", q->song,q->time/60,q->time%60);
  	printf("\n");
  	return;
  }
}
void create(char s[],int t)
{
	if(p == NULL)
	{
		insertAtBeginning(&p,s,t);
	}
	else
	{
		insertAtEnd(&p,s,t);
	}
}
void append(char name[])
{
	FILE *fr;
	fr = fopen(name,"r");
	char c,s[20];
	int i = 0;
	int f = 0;
	int t = 0;
	while((c = fgetc(fr)) != EOF)
	{
		
		if(c == '\n')
		{
			create(s,t);
			strncpy(s,"",strlen(s));
			i = 0;
			t = 0;f = 0;
		}
		else
		{
			if(c == ':')
				f = 1;
			if(f == 0&&isalpha(c))
				s[i++] = c;
				
			else if(f == 1&&c != ':'&&c!=' ')
				t = t*10 + (c-'0');
		}
	}
	fclose(fr);
}
void play(struct playlist** p)
{
	struct playlist* q = *p,*temp;
	int choice = 0,i=0,pos,k=0,r=0;
	char s[20];
	do
	{
		switch(choice)
		{
			case 0:
				{
					break;
				}
			case 1:
				{
					q = q->next;
					break;
				}
			case 2:
				{
					q = q->prev;
					break;
				}
			case 3:
				{
					k = 0;
					printf("Enter no of positions you want to skip: ");
					scanf("%d",&pos);
					while(k < pos)
					{
						q = q->next;
						k++;
					}
					break;
				}
			case 4:
				{
					k = 0;
					printf("Enter no of positions you want to skip: ");
					scanf("%d",&pos);
					while(k < pos-1)
					{
						q = q->prev;
						k++;
					}
					break;
				}
			case 5:
				{
					printf("Enter Song you want to skip to: ");
					scanf("%s",s);
					r = 0;
					if(strcmp(q->song,s) == 0)
					{
						break;
					}
					else
					{
						do
						{
							temp = q->next;
							i = 0;
							while(strcmp(temp->song,s) != 0)
							{
								temp = temp->next;
								if(strcmp(temp->song,s) == 0)
									r = 1;
							}
							if(temp == q->next && r == 0)
							{
								printf("Entered song is not present in the playlist");
								i = 1;
								printf("Enter Song you want to skip to: ");
								scanf("%s",s);
							}
							q = temp;
						}while(i != 0);
					}
					break;
				}
			default:
				{
					printf("Input Invalid!!!\n");
					break;	
				}	
		}
		printf("Now Playing.....%s...%2dm %2dsec\n",q->song,q->time/60,q->time%60);
		menu_play();
		scanf("%d",&choice);
	}while(choice != 6);
	return;
}
int main()
{
  p = NULL;
  int exists;
  char name[20];
  printf("Enter name of playlist: ");
  scanf("%s",name);
  strcat(name,".txt");
  printf("Is this a new Playlist\n1. Yes 2. No: ");
  scanf("%d",&exists);
  if(exists == 2)
  {
  	append(name);
  }
  int choice;
  menu();
  scanf("%d",&choice);
  do
  {
  	switch(choice)
  		{
		case 1:
  			{
  				insert();
  				break;			
			}	
		case 2:
			{
				delete_();
				break;
			}
		case 3:
			{
				display(&p);
				break;
			}
		case 4:
			{
				play(&p);
				break;
			}
		case 5:
			{
				FILE *fp;
  				fp = fopen(name,"w");
				struct playlist *q = p;
				while(q->next != p)
				{
					fprintf(fp,"%s:%d \n",q->song,q->time);
					q = q->next;
				}
				fprintf(fp,"%s:%d\n",q->song,q->time);
				fclose(fp);
				break;
			}
		default:
			{
				printf("ERROR");
				break;
			}
		}
	menu();
    scanf("%d",&choice);
	}while(choice != 6);
	printf("\t\t----Thank You-----\n");
}
