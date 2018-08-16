#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define HS 25
#define LS 60
#define XB '*'//cell
#define KB '-'//blank
#define CH 2//存活条件
#define FZ 3//复制条件

//void xsj(char);//打印新世界并循环 

char sj[HS][LS];

int main(int argc, char *argv[]) 
{
	printf("程序介绍：这是一个二维矩形世界，这个世界中的每个方格居住着一个活着的或死了的细胞。一个细胞在下一个时刻生死取决于相邻八个方格中活着的或死了的细胞的数量。如果相邻方格活着的细胞数量过多，这个细胞会因为资源匮乏而在下一个时刻死去；相反，如果周围活细胞过少，这个细胞会因太孤单而死去。\n本程序会根据输入值给出一个随机的初始世界，然后便可以开始观察细胞们的变化了。"); 
	int BL;
	printf("\n\n\n\n\n               您希望细胞与空格的数目比为 1：");
	scanf("%d",&BL);
	srand(time(0));
	int i,j;
	for(i=0;i<HS;i++)
	{
		for(j=0;j<LS;j++)
		{
			sj[i][j]=rand()%(BL+1);
			if(sj[i][j]==0)
			sj[i][j]=XB;
			else
			sj[i][j]=KB;
		}	
	}//生成时间随机矩阵作为初始世界 
	for(i=0;i<HS;i++)
	{
		for(j=0;j<LS;j++)
		{
			printf("%c",sj[i][j]);
		}
		printf("\n");
	}//打印初始世界 
	printf("\n          敲下回车继续 输入其它键退出");
	do{
	xsj();//得到新世界矩阵 
	}while(getchar()=='\n'?1:0);
	return 0;
}

void xsj(void)
{
	char pdjz[HS][LS];//判断矩阵
	int i,j,p,q;
	int sm;//周围细胞数目 
	for(i=0;i<HS;i++)//生成判断矩阵 
	{
		for(j=0;j<LS;j++)
		{
			sm=0;
			for(p=i-1;p<=i+1;p++)
			{
				for(q=j-1;q<=j+1;q++)
				{
					if(p<0||p>=HS)continue;
					if(q<0||q>=LS)continue;
					if(p==i&&q==j)continue;
					if(sj[p][q]==XB)sm++;
				}
			pdjz[i][j]=sm;	
			}
		}
	 } 
	system("cls");
	for(i=0;i<HS;i++)
	{
		for(j=0;j<LS;j++)
		{
			if(pdjz[i][j]==3)
			sj[i][j]=XB;
			if(pdjz[i][j]!=2&&pdjz[i][j]!=3)
			sj[i][j]=KB;
		}
	}
	for(i=0;i<HS;i++)
	{
		for(j=0;j<LS;j++)
		{
			printf("%c",sj[i][j]);
		}
		printf("\n");
	}//打印世界 
	printf("\n          敲下回车继续 输入其它键退出");
 	return;
}
