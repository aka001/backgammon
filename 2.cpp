/*Author : Akash Agrawall
Institution: IIIT Hyderabad*/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stack>
#include<queue>
using namespace std;
int bearingoffcheck(int arr[]);

int arr[30],brr[30],crr[30],drr[30],err[30],frr[30],grr[30],hrr[30];
void copyit(int a[],int b[])
{
	int i;
	for(i=1;i<=26;i++)
		a[i]=b[i];
}
int evalfunc(int a[30])
{
	int calc,i,pip,my_blot,enemy_blot,enemy_bar,holding,anchor,white_checker=0;
	i=pip=my_blot=enemy_blot=enemy_bar=holding=anchor=0;
	for(i=1;i<=24;i++)
	{
		if(a[i]>0)
		{
			pip+=a[i]*(24-i);
			if(a[i]==1)
				my_blot+=1;
			if(i<=18)
				holding+=a[i]*(18-i);
			if(a[i]>=2)
				anchor++;
			white_checker++;
		}
		else if(a[i]==-1)
		{
			enemy_blot+=1;
		}
	}
	if(a[26]>0)
	{
		enemy_bar+=a[26];
	}
	calc=10*enemy_blot+800*enemy_bar-400*holding+80*anchor-200*pip-50*(my_blot)-1500*white_checker;
	return calc;
}
int checkmove(int err[], int d1, int d2)
{
	int flag=1,pointit,x;
	pointit=1;
	if(err[0]>=1)
	{
		if(!(arr[d1]>=-1 || arr[d2]>=-1))
		{
			return 0;
		}
	}
	else
	{
		while(pointit<=24)
		{
			if(arr[pointit+d1]>=-1 || arr[pointit+d2]>=-1)
			{
				return 1;
			}
			pointit++;
		}
	}
	return 0;
}
int bearmaxit(int arrit[])
{
	int i;
	for(i=19;i<=24;i++)
	{
		if(arr[i]>0)
			return i;
	}
}
int p1[40],p2[40],p3[40],p4[40],p5[40];
int returnmin(int err[],int d1, int d2)
{
	int ans=0,cnt,x,flagit2,pointit=1,max=1000000000,lenit=0,val,pos=-1,i,j,da,dp,flagit3=1,flagit4=1;
	copyit(frr,err);
	if(frr[0]>1)
	{
		if(frr[d1]>=-1 && frr[d2]>=-1)
		{
			copyit(grr,frr);
			if(frr[d1]==-1)
			{
				frr[0]--;
				frr[d1]=1;
				frr[26]++;
			}
			else
			{
				frr[0]--;
				frr[d1]++;
			}
			if(frr[d2]==-1)
			{
				frr[0]--;
				frr[d2]=1;
				frr[26]++;
			}
			else
			{
				frr[0]--;
				frr[d2]++;
			}
			p1[lenit]=0;
			p2[lenit]=d1;
			p3[lenit]=0;
			p4[lenit]=d2;
			val=evalfunc(frr);
			p5[lenit]=val;
			lenit++;
			if(val<max)
			{
				max=val;
				pos=lenit-1;
			}
			copyit(frr,grr);

			/*copyit(brr,arr);
			if(arr[25-d2]==-1)
			{
				arr[25-d2]=1;
				arr[26]++;
			}
			else
			{
				arr[25-d2]++;
			}
			if(arr[25-d1]==-1)
			{
				arr[25-d1]=1;
				arr[26]++;
			}
			else
			{
				arr[25-d1]=1;
				arr[26]++;
			}
			t1[lenit]=25;
			t2[lenit]=25-d1;
			t3[lenit]=25;
			t4[lenit]=25-d2;
			lenit++;
			val=evalfunc(arr);
			if(val>max)
			{
				max=val;
				pos=lenit-1;
			}
			copyit(arr,brr);*/
			
			copyit(grr,frr);
			if(frr[d1+d2]>=-1)
			{
				if(frr[d1+d2]==-1)
				{
					frr[0]--;
					frr[d1+d2]=1;
					frr[26]++;
				}
				else
				{
					frr[0]--;
					frr[d1+d2]++;
				}
				p1[lenit]=0;
				p2[lenit]=d1;
				p3[lenit]=d1;
				p4[lenit]=d2;
				val=evalfunc(frr);
				p5[lenit]=val;
				lenit++;
				if(val<max)
				{
					max=val;
					pos=lenit-1;
				}
			}
			copyit(frr,grr);
			//printf("%d %d\n%d %d\n",t1[pos],t2[pos],t3[pos],t4[pos]);
			//printit(t1[pos],t2[pos],t3[pos],t4[pos],flagit);
			return max;
		}
		else if(frr[d1]>=-1 || frr[d2]>=-1)
		{
			if(frr[d1+d2]>=-1)
			{
				if(frr[d1+d2]==-1)
				{
					frr[0]--;
					frr[d1+d2]=1;
					frr[26]++;
				}
				else
				{
					frr[0]--;
					frr[d1+d2]++;
				}
				p1[lenit]=0;
				p2[lenit]=d2;
				p3[lenit]=d2;
				p4[lenit]=d1+d2;
				p5[lenit]=evalfunc(frr);
				if(frr[d1]>=-1)
				{
					p1[lenit]=0;
					p2[lenit]=d1;
					p3[lenit]=d1;
					p4[lenit]=d1+d2;
				}
				//printf("%d %d\n%d %d\n",t1[lenit],t2[lenit],t3[lenit],t4[lenit]);
				//printit1(t1[lenit],t2[lenit],flagit);
				return p5[lenit];
			}
			if(frr[d1]>=-1)
			{
				p1[lenit]=0;
				p2[lenit]=d1;
				if(frr[d1]==-1)
				{
					frr[0]--;
					frr[d1]=1;
					frr[26]++;
				}
				else
				{
					frr[0]--;
					frr[d1]++;
				}
				//printf("%d %d\npass\n",t1[lenit],t2[lenit]);
				return evalfunc(frr);
			}
			else if(frr[d2]>=-1)
			{
				p1[lenit]=0;
				p2[lenit]=d2;
				if(frr[d2]==-1)
				{
					frr[0]--;
					frr[d2]=1;
					frr[26]++;
				}
				else
				{
					frr[0]--;
					frr[d2]++;
				}
				//printf("%d %d\npass\n",t1[lenit],t2[lenit]);
				return evalfunc(frr);
			}
		}
		else if(frr[d1]<-1 && frr[d2]<-1)
		{
			//printf("pass\npass\n");
			//To be seen
			return 1000000000;
		}
	}
	else if(frr[0]==1)
	{
		if(frr[d1]<-1 && frr[d2]<-1)
		{
			return 1000000000;
		}
		cnt=2;
		while(cnt--)
		{
			copyit(grr,frr);
			da=d1;
			dp=d2;
			if(cnt==0)
			{
				da=d2;
				dp=d1;
			}
			if(frr[da]>=-1)
			{
				flagit2=1;
				if(frr[da]==-1)
				{
					frr[da]=1;
					frr[26]++;
					frr[0]--;
				}
				else
				{
					frr[da]++;
					frr[0]--;
				}
				for(j=1;j<=24;j++)
				{
					copyit(hrr,frr);
					if(frr[j]<=0)
						continue;
					if(frr[j+dp]>=-1 && j+dp<=24)
					{
						flagit2=0;
						if(frr[j+dp]==-1)
						{
							if(j+dp<=24)
								frr[j+dp]=1;
							frr[j]--;
							frr[26]++;
						}
						else
						{
							if(j+dp<=24)
								frr[j+dp]++;
							frr[j]--;
						}
						p1[lenit]=0;
						p2[lenit]=da;
						p3[lenit]=j;
						p4[lenit]=j+dp;
						val=evalfunc(frr);
						p5[lenit]=val;
						//printit(t1[lenit],t2[lenit],t3[lenit],t4[lenit],1);
						if(val<max)
						{
							max=val;
							pos=lenit;
						}
						lenit++;
					}
					copyit(frr,hrr);
				}
				if(flagit2)
				{
					p1[lenit]=0;
					p2[lenit]=da;
					frr[25]=1;
					val=evalfunc(frr);
					p5[lenit]=val;
					if(val<max)
					{
						max=val;
						pos=lenit;
					}
					lenit++;
				}
			}
			copyit(frr,grr);
		}
		//printit(t1[pos],t2[pos],t3[pos],t4[pos],1);
		//printf("%d %d\n%d %d\n",t1[pos],t2[pos],t3[pos],t4[pos]);
		if(pos==-1)
		{
			return 1000000000;
		}
		return p5[pos];
	}
	while(pointit<=24)
	{
		if(frr[pointit]<=0)
		{
			pointit++;
			continue;
		}
		cnt=2;
		if(d1==d2)
			cnt=1;
		x=pointit;
		while(cnt--)
		{
			da=d1;
			dp=d2;
			/*if(cnt==1)
			{
				da=d1;
				dp=d2;
			}*/
			if(cnt==0)
			{
				da=d2;
				dp=d1;
			}
			//printf("cnt=%d da=%d dp=%d\n",cnt,da,dp);
			copyit(grr,frr);
			if((frr[pointit+da]>=-1 && pointit+da<=24)||(bearingoffcheck(frr) && pointit+da>=25 && flagit3==1))
			{
				if(bearingoffcheck(frr) && pointit+da>=25 && flagit3==1)
					flagit3=0;
				flagit2=1;
				if(frr[pointit+da]==-1)
				{
					frr[pointit]--;
					if(pointit+da<=24)
						frr[pointit+da]=1;
					frr[26]+=1;
				}
				else
				{
					frr[pointit]--;
					if(pointit+da<=24)
						frr[pointit+da]++;
				}
				x=pointit;
				while(x<=24)
				{
					copyit(hrr,frr);
					if(frr[x]>0)
					{
						if((frr[x+dp]>=-1 && x+dp<=24) || (bearingoffcheck(frr) && x+dp>=25 && flagit4==1))
						{
							if(bearingoffcheck(frr) && x+dp>=25 && flagit4==1)
								flagit4=0;
							flagit2=0;
							if(frr[x+dp]==-1)
							{
								frr[x]--;
								if(x+dp<=24)
									frr[x+dp]=1;
								frr[26]+=1;
							}
							else
							{
								frr[x]--;
								if(x+dp<=24)
									frr[x+dp]++;
							}
							p1[lenit]=pointit;
							p2[lenit]=pointit+da;
							p3[lenit]=x;
							p4[lenit]=x+dp;
							val=evalfunc(frr);
							p5[lenit]=val;
							lenit++;
							//printit(t1[lenit],t2[lenit],t3[lenit],t4[lenit],flagit);
							//printf("%d %d %d %d %d\n",p1[lenit],p2[lenit],p3[lenit],p4[lenit],val);
							if(val<max)
							{
								//printf("hie\n");
								max=val;
								pos=lenit-1;
							}
							ans++;
						}
					}
					x++;
					copyit(frr,hrr);
				}
				if(flagit2)
				{
					p1[lenit]=pointit;
					p2[lenit]=pointit+da;
					p3[lenit]=-1;
					p4[lenit]=-1;
					frr[25]=1;
					val=evalfunc(frr);
					p5[lenit]=val;
					if(val<max)
					{
						max=val;
						pos=lenit;
					}
					lenit++;
				}
				copyit(frr,grr);
			}
			else
			{
				copyit(frr,grr);
				continue;
			}
		}
		pointit++;
	}
	//printf("ans=%d pos=%d max=%d\n",ans,pos,max);
	//printit(t1[pos],t2[pos],t3[pos],t4[pos],1);
	//printf("%d %d\n%d %d\n",t1[pos],t2[pos],t3[pos],t4[pos]);
	if(pos==-1)
		return 1000000000;
	return p5[pos];
}
int level2(int drr[])
{
	int temp,i,j,sum=0,cnt=0;
	copyit(err,drr);
	for(i=1;i<=12;i++)
	{
		temp=err[i];
		err[i]=err[25-i];
		err[25-i]=temp;
		err[i]*=-1;
		err[25-i]*=-1;
	}
	temp=err[0];
	err[0]=err[26];
	err[26]=temp;
	for(i=1;i<=6;i++)
	{
		for(j=i;j<=6;j++)
		{
			//if(checkmove(err,i,j))
			sum=sum+returnmin(err,i,j);
			cnt++;
		}
	}
	if(err[25]==1)
	{
		sum-=50000;
	}
	return (sum/cnt);
}
void printit(int a,int b,int c,int d, int flagit)
{
	int state1,state2,state3,state4;
	char ch1='A',ch2='B';
	if(flagit==0)
	{
		ch1='B';
		ch2='A';
	}
	if(a>=13 && a<25)
	{
		a-=12;
		state1=1;
	}
	else if(a<13 && a>=1)
	{
		a=12-a;
		state1=2;
	}
	else if(a==25)
		state1=0;
	else
		state1=3;
	if(b>=13 && b<25)
	{
		b-=12;
		state2=1;
	}
	else if(b<13 && b>=1)
	{
		b=12-b;
		state2=2;
	}
	else if(b==25)
		state2=0;
	else
		state2=3;
	if(c>=13 && c<25)
	{
		c-=12;
		state3=1;
	}
	else if(c<13 && c>=1)
	{
		c=12-c;
		state3=2;
	}
	else if(c==25)
		state3=0;
	else
		state3=3;
	if(d>=13 && d<25)
	{
		d-=12;
		state4=1;
	}
	else if(d<13 && d>=1)
	{
		d=12-c;
		state4=2;
	}
	else if(d==25)
		state4=0;
	else
		state4=3;
	
	if(state1==1)
		printf("%c%d ",ch1,a);
	else if(state1==2)
		printf("%c%d ",ch2,a);
	else if(state1==0)
		printf("Z ");
	else
		printf("pass\n");

	if(state2==1)
		printf("%c%d\n",ch1,b);
	else if(state2==2)
		printf("%c%d\n",ch2,b);
	else if(state1!=3)
		printf("pass\n");
	
	if(state3==1)
		printf("%c%d ",ch1,c);
	else if(state3==2)
		printf("%c%d ",ch2,c);
	else if(state3==0)
		printf("Z ");
	else
		printf("pass\n");

	if(state4==1)
		printf("%c%d\n",ch1,d);
	else if(state4==2)
		printf("%c%d\n",ch2,d);
	else if(state3!=3)
		printf("pass\n");
}
void printit1(int a,int b, int flagit)
{
	int state1,state2,state3,state4;
	char ch1='A',ch2='B';
	if(flagit==0)
	{
		ch1='B';
		ch2='A';
	}
	if(a>=13 && a<25)
	{
		a-=12;
		state1=1;
	}
	else if(a<13 && a>=1)
	{
		a=12-a;
		state1=2;
	}
	else if(a==25)
		state1=0;
	else
		state1=3;
	if(b>=13 && b<25)
	{
		b-=12;
		state2=1;
	}
	else if(b<13 && b>=1)
	{
		b=12-b;
		state2=2;
	}
	else if(b==25)
		state2=0;
	else
		state2=3;
	if(state1==1)
		printf("%c%d ",ch1,a);
	else if(state1==2)
		printf("%c%d ",ch2,a);
	else if(state1==0)
		printf("Z ");
	else
		printf("pass\n");

	if(state2==1)
		printf("%c%d\n",ch1,b);
	else if(state2==2)
		printf("%c%d\n",ch2,b);
	else if(state1!=3)
		printf("pass\n");
}
int bearingoffcheck(int brr[])
{
	int i,cnt=0;
	for(i=1;i<=18;i++)
	{
		if(brr[i]>0)
		{
			return 0;
		}
	}
	return 1;
}
int t1[300],t2[300],t3[300],t4[300];
int main()
{
	int flagit4=1,flagit1,counter=0,lengthit,temp,j,i,n=12,calc,cnt=2,x,ans=0,pointit=1,flag,d1,d2,d,val,da,dp,max,pos,lenit=0,flagit=1,flagit3=1;
	char ch;
	max=-1000000000;
	pos=-1;
	for(i=1;i<=24;i++)
	{
		scanf("%d",&arr[i]);
	}
	/*for(i=0;i<12;i++)
	{
		scanf("%d",&arr[12-i]);
	}*/
	ch=getchar();
	ch=getchar();
	arr[26]=0;
	arr[0]=0;
	while(ch!='\n' && ch!=' ')
	{
		if(ch=='a')
			arr[0]++;
		if(ch=='b')
			arr[26]++;
		ch=getchar();
	}
	/*lengthit=strlen(ch);
	for(i=0;i<lengthit;i++)
	{
		if(ch[i]=='a')
		//Alice's bar marker
			arr[0]++;
		else if(ch[i] == 'b')
		//Bob's bar marker
			arr[26]++;
	}*/
	scanf("%d %d",&d1,&d2);
	/*if(ch[0]=='A'||ch[0]=='a')
	{
		flagit=0;
		for(i=1;i<=12;i++)
		{
			temp=arr[i];
			arr[i]=arr[24-i+1];
			arr[24-i+1]=temp;
		}
		arr[i]*=-1;
	}*/
	/*if(bearingoffcheck(arr))
	{
		pointit=19;
		da=d1;
		dp=d2;
		if(d1<d2)
		{
			da=d2;
			dp=d1;
		}
		int flag;
		while(pointit<=24)
		{
			if(arr[pointit]<=0)
			{
				pointit++;
				continue;
			}
			flag=0;
			if(pointit+da>=25)
			{
				x=pointit;
				while(x<=24)
				{
					if(arr[x]<=0)
					{
						x++;
						continue;
					}
					if(x+dp>=25)
					{
						//We are moving from pointit to 25th position
						flag=1;
						printf("%d %d\n%d %d\n",pointit,0,x,0);
					}
				}
			}
			if(flag==0)
			{
				
			}
			pointit++;
		}
	}*/
	if(arr[0]>1)
	{
		if(arr[d1]>=-1 && arr[d2]>=-1)
		{
			copyit(brr,arr);
			if(arr[d1]==-1)
			{
				arr[0]--;
				arr[d1]=1;
				arr[26]++;
			}
			else
			{
				arr[0]--;
				arr[d1]++;
			}
			if(arr[d2]==-1)
			{
				arr[0]--;
				arr[d2]=1;
				arr[26]++;
			}
			else
			{
				arr[0]--;
				arr[d2]++;
			}
			t1[lenit]=0;
			t2[lenit]=d1;
			t3[lenit]=0;
			t4[lenit]=d2;
			lenit++;
			val=level2(arr);
			//val=evalfunc(arr);
			if(val>max)
			{
				max=val;
				pos=lenit-1;
			}
			copyit(arr,brr);

			/*copyit(brr,arr);
			if(arr[25-d2]==-1)
			{
				arr[25-d2]=1;
				arr[26]++;
			}
			else
			{
				arr[25-d2]++;
			}
			if(arr[25-d1]==-1)
			{
				arr[25-d1]=1;
				arr[26]++;
			}
			else
			{
				arr[25-d1]=1;
				arr[26]++;
			}
			t1[lenit]=25;
			t2[lenit]=25-d1;
			t3[lenit]=25;
			t4[lenit]=25-d2;
			lenit++;
			val=evalfunc(arr);
			if(val>max)
			{
				max=val;
				pos=lenit-1;
			}
			copyit(arr,brr);*/
			
			copyit(brr,arr);
			if(arr[d1+d2]>=-1)
			{
				if(arr[d1+d2]==-1)
				{
					arr[0]--;
					arr[d1+d2]=1;
					arr[26]++;
				}
				else
				{
					arr[0]--;
					arr[d1+d2]++;
				}
				t1[lenit]=0;
				t2[lenit]=d1;
				t3[lenit]=d1;
				t4[lenit]=d2;
				lenit++;
				val=level2(arr);
				//val=evalfunc(arr);
				if(val>max)
				{
					max=val;
					pos=lenit-1;
				}
			}
			copyit(arr,brr);
			printf("%d %d\n%d %d\n",t1[pos],t2[pos],t3[pos],t4[pos]);
			//printit(t1[pos],t2[pos],t3[pos],t4[pos],flagit);
			return 0;
		}
		else if(arr[d1]>=-1 || arr[d2]>=-1)
		{
			if(arr[d1+d2]>=-1)
			{
				if(arr[d1+d2]==-1)
				{
					arr[0]--;
					arr[d1+d2]=1;
					arr[26]++;
				}
				else
				{
					arr[0]--;
					arr[d1+d2]++;
				}
				t1[lenit]=0;
				t2[lenit]=d2;
				t3[lenit]=d2;
				t4[lenit]=d1+d2;
				if(arr[d1]>=-1)
				{
					t1[lenit]=0;
					t2[lenit]=d1;
					t3[lenit]=d1;
					t4[lenit]=d1+d2;
				}
				printf("%d %d\n%d %d\n",t1[lenit],t2[lenit],t3[lenit],t4[lenit]);
				//printit1(t1[lenit],t2[lenit],flagit);
				return 0;
			}
			if(arr[d1]>=-1)
			{
				t1[lenit]=0;
				t2[lenit]=d1;
				if(arr[d1]==-1)
				{
					arr[0]--;
					arr[d1]=1;
					arr[26]++;
				}
				else
				{
					arr[0]--;
					arr[d1]++;
				}
				printf("%d %d\npass\n",t1[lenit],t2[lenit]);
				return 0;

			}
			else if(arr[d2]>=-1)
			{
				t1[lenit]=0;
				t2[lenit]=d2;
				if(arr[d2]==-1)
				{
					arr[0]--;
					arr[d2]=1;
					arr[26]++;
				}
				else
				{
					arr[0]--;
					arr[d2]++;
				}
				printf("%d %d\npass\n",t1[lenit],t2[lenit]);
			}
			return 0;
		}
		else if(arr[d1]<-1 && arr[d2]<-1)
		{
			printf("pass\npass\n");
			return 0;
		}
	}
	else if(arr[0]==1)
	{
		if(arr[d1]<-1 && arr[d2]<-1)
		{
			printf("pass\npass\n");
			return 0;
		}
		cnt=2;
		while(cnt--)
		{
			copyit(brr,arr);
			da=d1;
			dp=d2;
			if(cnt==0)
			{
				da=d2;
				dp=d1;
			}
			if(arr[da]>=-1)
			{
				flagit1=1;
				if(arr[da]==-1)
				{
					arr[da]=1;
					arr[26]++;
					arr[0]--;
				}
				else
				{
					arr[da]++;
					arr[0]--;
				}
				for(j=1;j<=24;j++)
				{
					copyit(crr,arr);
					if(arr[j]<=0)
						continue;
					if(arr[j+dp]>=-1 && j+dp<=24)
					{
						flagit1=0;
						if(arr[j+dp]==-1)
						{
							arr[j+dp]=1;
							arr[j]--;
							arr[26]++;
						}
						else
						{
							arr[j+dp]++;
							arr[j]--;
						}
						t1[lenit]=0;
						t2[lenit]=da;
						t3[lenit]=j;
						t4[lenit]=j+dp;
						val=level2(arr);
						//val=evalfunc(arr);
						//printit(t1[lenit],t2[lenit],t3[lenit],t4[lenit],1);
						if(val>max)
						{
							max=val;
							pos=lenit;
						}
						lenit++;
					}
					copyit(arr,crr);
				}
				if(flagit1)
				{
					t1[lenit]=0;
					t2[lenit]=da;
					t3[lenit]=-1;
					t4[lenit]=-1;
					arr[25]=1;
					val=level2(arr);
					if(val>max)
					{
						max=val;
						pos=lenit;
					}
				}
			}
			copyit(arr,brr);
		}
		//printit(t1[pos],t2[pos],t3[pos],t4[pos],1);
		if(pos==-1)
		{
			printf("pass\npass\n");
			return 0;
		}
		if(t3[pos]==-1)
		{
			printf("%d %d\npass\n",t1[pos],t2[pos]);
			return 0;
		}
		printf("%d %d\n%d %d\n",t1[pos],t2[pos],t3[pos],t4[pos]);
		return 0;
	}
	while(pointit<=24)
	{
		if(arr[pointit]<=0)
		{
			pointit++;
			continue;
		}
		cnt=2;
		if(d1==d2)
			cnt=1;
		x=pointit;
		while(cnt--)
		{
			da=d1;
			dp=d2;
			/*if(cnt==1)
			{
				da=d1;
				dp=d2;
			}*/
			if(cnt==0)
			{
				da=d2;
				dp=d1;
			}
			//printf("cnt=%d da=%d dp=%d\n",cnt,da,dp);
			copyit(brr,arr);
			flagit1=1;
			if((arr[pointit+da]>=-1 && pointit+da<=24) || (bearingoffcheck(arr) && pointit+da>=25 && flagit3==1)) 
			{
				if(bearingoffcheck(arr) && pointit+da>=25 && flagit3==1)
					flagit3=0;
				if(arr[pointit+da]==-1)
				{
					arr[pointit]--;
					if(pointit+da<=24)
						arr[pointit+da]=1;
					arr[26]+=1;
				}
				else
				{
					arr[pointit]--;
					if(pointit+da<=24)
						arr[pointit+da]++;
				}
				x=pointit;
				while(x<=24)
				{
					copyit(crr,arr);
					if(arr[x]>0)
					{
						if((arr[x+dp]>=-1 && x+dp<=24) || (bearingoffcheck(arr) && x+dp>=25 && flagit4==1))
						{
							if(bearingoffcheck(arr) && x+dp>=25 && flagit4==1)
								flagit4=0;
							flagit1=0;
							//printf("%d %d \n",arr[18],arr[19]);
							if(arr[x+dp]==-1)
							{
								arr[x]--;
								if(x+dp<=24)//changed
									arr[x+dp]=1;
								arr[26]+=1;
							}
							else
							{
								arr[x]--;
								if(x+dp<=24)//changed
									arr[x+dp]++;
							}
							t1[lenit]=pointit;
							t2[lenit]=pointit+da;
							t3[lenit]=x;
							t4[lenit]=x+dp;
							if(t2[lenit]>24)
								t2[lenit]=0;
							if(t4[lenit]>24)
								t4[lenit]=0;
							val=level2(arr);
							//val=evalfunc(arr);
							//printit(t1[lenit],t2[lenit],t3[lenit],t4[lenit],flagit);
							//printf("here %d %d %d %d %d\n",t1[lenit],t2[lenit],t3[lenit],t4[lenit],val);
							lenit++;
							if(val>max)
							{
								//printf("hie\n");
								max=val;
								pos=lenit-1;
							}
							ans++;
						}
					}
					x++;
					copyit(arr,crr);
				}
				if(flagit1==1)
				{
					t1[lenit]=pointit;
					t2[lenit]=pointit+da;
					t3[lenit]=-1;
					t4[lenit]=-1;
					arr[25]=1;
					val=level2(arr);
					if(val>max)
					{
						max=val;
						pos=lenit;
					}
					lenit++;
				}
				copyit(arr,brr);
			}
			else
			{
				copyit(arr,brr);
				continue;
			}
		}
		pointit++;
	}
	//printf("ans=%d pos=%d max=%d\n",ans,pos,max);
	//printit(t1[pos],t2[pos],t3[pos],t4[pos],1);
	if(pos==-1)
	{
		printf("pass\npass\n");
		return 0;
	}
	if(t3[pos]==-1)
	{
		if(t2[pos]==0)
		printf("%d O\npass\n",t1[pos]);
		return 0;
	}
	if(t2[pos]==0 && t4[pos]==0)
		printf("%d O\n%d O\n",t1[pos],t3[pos]);
	else if(t2[pos]==0)
		printf("%d O\n%d %d\n",t1[pos],t3[pos],t4[pos]);
	else if(t4[pos]==0)
		printf("%d %d\n%d O\n",t1[pos],t2[pos],t3[pos]);
	else
		printf("%d %d\n%d %d\n",t1[pos],t2[pos],t3[pos],t4[pos]);
	//printf("Number of states=%d\n",ans);
	return 0;
}
