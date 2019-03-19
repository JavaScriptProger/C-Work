#include <iostream>
#include <stack>
#include <utility>

using namespace std;
int LegalStep( int x, int y) ;
int m[10][10] = 
                      { {0,0,0,0,0,0,0,0,0,0},
                        {-1,-1,-1,-1,0,0,-1,-1,-1,0},
                        {-1,-1,-1,-1,0,0,-1,-1,-1,0},
                        {-1,-1,-1,-1,0,0,-1,-1,-1,0},
                        {-1,-1,-1,-1,0,0,-1,-1,-1,0},
                        {0,0,0,0,0,0,-1,-1,-1,0},
                        {0,-1,-1,-1,-1,-1,-1,-1,-1,0},
                        {0,-1,-1,-1,-1,-1,-1,-1,-1,0},
                        {0,-1,-1,-1,-1,-1,-1,-1,-1,0},
                        {0,0,0,0,0,0,0,0,0,0} };
int exitX, exitY, flag=0;

void press(int x,int y, int k)
{
	cout<<"x="<<x<<"  y="<<y<<endl;
	if(m[x][y]==1) return;
	if (LegalStep(x+1,y))
	 if(m[x+1][y]==k-1) press(x+1,y,k-1);
	if (LegalStep(x-1,y))
	 if(m[x-1][y]==k-1) press(x-1,y,k-1);
	if (LegalStep(x,y+1))
	 if(m[x][y+1]==k-1) press(x,y+1,k-1);
	if (LegalStep(x,y-1))
	 if(m[x][y-1]==k-1) press(x,y-1,k-1);
}

int LegalStep( int x, int y) 
{
  if ((x < 0)||(y < 0)||(x >= 10)||(y >= 10)) 
     return 0;
  return 1;
} 

void Step(int x, int y, int k)
{ 
	if((m[x][y]!=0)&&(m[x][y]<k)) return;

   m[x][y]=k; k++;
  
   if(x==exitX && y==exitY)
{
      flag = 1;
      return;
      }
   else
   {
      if ((LegalStep(x+1,y)))	  {
		  if(m[x+1][y] >-1) 
		  Step (x+1,y,k);
	  }
   
     if ((LegalStep(x,y+1)) )
	 {
		 if(m[x][y+1] >-1)  
         Step (x, y+1,k);
	  }
       if ((LegalStep(x-1,y)))
	 {
		 if(m[x-1][y] >-1) 
         Step (x-1, y,k);
	  }
      if ((LegalStep(x,y-1)))	
	  {
		  if(m[x][y-1] >-1)  
		  Step (x, y-1,k);
	  }
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
   press(exitX,exitY,m[exitX][exitY]);
   return 0;	
}
