#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int check_engage(int engaged[][2],int select_women,int n)
{int i;
 for(i=0;i<n;i++)
 {if(engaged[i][1]==select_women){return engaged[i][0];}}  //return men to whom women is engaged with
 return 0;
}

void engage(int men,int women,int engaged[][2],int n,int replace)
{int i;
 if(replace==0)
 {for(i=0;i<n;i++)
 {if(engaged[i][0]==0)
	{engaged[i][0]=men;
	 engaged[i][1]=women;	
	 return;
	}
 }}
 else
 {for(i=0;i<n;i++)
 {if(engaged[i][0]==replace)
	{engaged[i][0]=men;	
	 return;
	}
 }}
}

int check_priority(int eng_men,int cur_men,int select_women,int women[][3],int n)
{int i;
 for(i=0;i<n;i++)
 {if(women[select_women][i]==eng_men){return 0;}
  if(women[select_women][i]==cur_men){return 1;}
 }
}

int main(int argc, char** argv) {
//Initialization of variable and array
int n=3;
int men[n][n]={{1,3,2},{1,2,3},{1,2,3}};
int women[n][3]={{1,2,3},{3,2,1},{1,3,2}};
int engaged[n][2]={{0,0},{0,0},{0,0}};
int unengaged[n];
int k,i,j,select_men,select_women;
//Unengaged stare list of unengaged men

for(i=0;i<n;i++)
{unengaged[i]=i+1;}
int un_pointer=n-1;

while(un_pointer!=-1)
{select_men=unengaged[un_pointer];
 un_pointer--;
 
 for(i=0;i<n;i++)
 {select_women=men[select_men-1][i];
  int check=check_engage(engaged,select_women,n);
  if(check)
  {int priority=check_priority(check,select_men,select_women-1,women,n);
   if(priority)
   {engage(select_men,select_women,engaged,n,check);
    un_pointer++;
    unengaged[un_pointer]=check;
    break;
   }
  }
  else
  {engage(select_men,select_women,engaged,n,0);
   break;
  }

 }

}
for(i=0;i<n;i++)
{cout<<"men "<<engaged[i][0]<<" engaged with women "<<engaged[i][1]<<endl;}

 return 0;
}

