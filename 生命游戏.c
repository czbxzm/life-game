#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define HS 25
#define LS 60
#define XB '*'//cell
#define KB '-'//blank
#define CH 2//�������
#define FZ 3//��������

//void xsj(char);//��ӡ�����粢ѭ�� 

char sj[HS][LS];

int main(int argc, char *argv[]) 
{
	printf("������ܣ�����һ����ά�������磬��������е�ÿ�������ס��һ�����ŵĻ����˵�ϸ����һ��ϸ������һ��ʱ������ȡ�������ڰ˸������л��ŵĻ����˵�ϸ����������������ڷ�����ŵ�ϸ���������࣬���ϸ������Ϊ��Դ�ѷ�������һ��ʱ����ȥ���෴�������Χ��ϸ�����٣����ϸ������̫�µ�����ȥ��\n��������������ֵ����һ������ĳ�ʼ���磬Ȼ�����Կ�ʼ�۲�ϸ���ǵı仯�ˡ�"); 
	int BL;
	printf("\n\n\n\n\n               ��ϣ��ϸ����ո����Ŀ��Ϊ 1��");
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
	}//����ʱ�����������Ϊ��ʼ���� 
	for(i=0;i<HS;i++)
	{
		for(j=0;j<LS;j++)
		{
			printf("%c",sj[i][j]);
		}
		printf("\n");
	}//��ӡ��ʼ���� 
	printf("\n          ���»س����� �����������˳�");
	do{
	xsj();//�õ���������� 
	}while(getchar()=='\n'?1:0);
	return 0;
}

void xsj(void)
{
	char pdjz[HS][LS];//�жϾ���
	int i,j,p,q;
	int sm;//��Χϸ����Ŀ 
	for(i=0;i<HS;i++)//�����жϾ��� 
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
	}//��ӡ���� 
	printf("\n          ���»س����� �����������˳�");
 	return;
}
