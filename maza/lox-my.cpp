#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <utility>
#include <set>

using namespace std;

int m[10][10] = 
                      { {0,0,0,0,0,0,0,0,0,0},
                        {-1,-1,-1,-1,0,0,-1,-1,-1,0},
                        {-1,-1,-1,-1,0,0,-1,-1,-1,0},
                        {-1,-1,-1,-1,0,0,-1,-1,-1,0},
                        {-1,-1,-1,-1,0,0,-1,-1,-1,0},
                        {0,0,0,0,0,0, -1,-1,-1,0},
                        {0,-1,-1,-1,-1,-1,-1,-1,-1,0},
                        {0,-1,-1,-1,-1,-1,-1,-1,-1,0},
                        {0,-1,-1,-1,-1,-1,-1,-1,-1,0},
                        {0,0,0,0,0,0,0,0,0,0} };
int exitX, exitY, flag=0;

int LegalStep( int x, int y) 
{
  if ((x < 0)||(y < 0)||(x >= 10)||(y >= 10)) 
     return 0;
  return 1;
}

void search(stack<pair<int, int>> stack){
for (int i = 0;i < stack.size();i++)
  {
	  cout << "First:" << stack.top().first << " ";
	  cout << "Index:" << i << " ";
	  cout << "Second:" << stack.top().second << endl;
	  stack.pop();
  }
}


stack<pair<int, int>> cords;

void Step(int x, int y, int k)
{ 


	if((m[x][y]!=0)&&(m[x][y]<k)) return;

   m[x][y]=k; k++;
  
   if(x==exitX && y==exitY)
{
      flag = 1;
	  cout << "==============================" << endl;
	  search(cords);
	  for(int i = 0;i < cords.size();i++) cords.pop();
      return;
      }
   else
   {
      if ((LegalStep(x+1,y)))	  {
		  if(m[x+1][y] == 0) Step (x+1,y,k); else
		  if(m[x+1][y] != -1)
         if(m[x][y]<=m[x+1][y]) 
		  Step (x+1,y,k);
	  }
   
     if ((LegalStep(x,y+1)) )
	 {
		 if(m[x][y+1] == 0) Step (x, y+1,k); else
        if(m[x][y+1] != -1) 
		 if(m[x][y]<=m[x][y+1]) 
         Step (x, y+1,k);
	  }
       if ((LegalStep(x-1,y)))
	 {
		 if(m[x-1][y] == 0) Step (x-1, y,k); else
		 if(m[x-1][y] != -1) 
			 if(m[x][y]<=m[x-1][y])
         Step (x-1, y,k);
	  }
      if ((LegalStep(x,y-1)))	
	  {
		  if(m[x][y-1] == 0)Step (x, y-1,k); else
		  if(m[x][y-1] != -1) 
         if(m[x][y]<=m[x][y-1]) 
		  Step (x, y-1,k);
	  }

	  cords.push(make_pair(x,y));
   }    
}

int main()
{
 
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
			{cout.width(3);
		cout<<m[i][j];}
		cout<<endl;
	}

   int x, y; 
   cout<<"start point:\n";
   cin>>x>>y;
   
   cout<<"end point:\n";
   cin>>exitX>>exitY;

   Step(x, y, 1);
   
   if (flag == 1)
   {
      cout<<"Yes\n";
	
   }
   else
      cout<<"No\n";
   for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
			{cout.width(3);
		cout<<m[i][j];}
		cout<<endl;
	}

	system("pause");
	return 0;
}
