#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

struct student
{
	int num;
	char name[20];
	char sex[3];
	int age;
	int score;
	char subject[5];
	char health[5];
	int index = 0;
}stud[100];

void LuRu(); void LiuLan(); void ChaXun(); void ShanChu(); void XiuGai(); void BaoCun(); void Du();

int main()
{
	SetConsoleTitle("ѧ�����ݿ����ϵͳv1.2 by DarthCY");
	int choose;
	printf("                                =========ѧ����Ϣ����ϵͳ=========\n");
	printf("                                         1.¼��ѧ����Ϣ           \n");
	printf("                                         2.���ѧ����Ϣ           \n");
	printf("                                         3.��ѯѧ����Ϣ           \n");
	printf("                                         4.ɾ��ѧ����Ϣ           \n");
	printf("                                         5.���ѧ����Ϣ(��δ����) \n");
	printf("                                         6.�޸�ѧ����Ϣ           \n");
	printf("                                         7.����ѧ����Ϣ           \n");
	printf("                                         8.͸����Ϣϵͳ           \n");
	printf("                                ==================================\n");
	printf("��ѡ��˵���1-8����\n");
	scanf_s("%d", &choose);
	switch (choose)
	{
		case 1:LuRu();break;
		case 2:LiuLan();break;
		case 3:ChaXun();break;
		case 4:ShanChu();break;
		case 6:XiuGai();break;
		case 7:BaoCun();break;
		case 8:printf("������ֹ\n");system("pause");exit(0);
	}
	system("pause");		//����˵��getchar()����std::cin.get������
}

void LuRu()		//¼�뺯��ģ��
{
	int i=0,n;char yn;	//stud[0].index = 1;����ģ��δ����
ReLuRu:if (stud[i].index != 0)	//ReLuRu��ʶ�� ���ԭ�ȿ��ܴ��������еĸ�д����
	{		//printf("\n���ּ�¼��%d�Ѵ��ڼ�¼��",i);
		i++;	//printf("����ת���%d�м�������\n",i);
		Sleep(300);
		goto ReLuRu;
	}
	Du();
	printf("\n������Ҫ����ѧ����Ϣ��ѧ��<8λ>��");
	scanf_s("%d", &stud[i].num);
	printf("\n������Ҫ����ѧ����Ϣ��������");
	scanf_s("%s",&stud[i].name,20);
	printf("\n������Ҫ����ѧ����Ϣ���Ա�<�л�Ů>��");
	scanf_s("%s",&stud[i].sex,3);
	printf("\n������Ҫ����ѧ����Ϣ�����䣺");
	scanf_s("%d", &stud[i].age);
	printf("\n������Ҫ����ѧ����Ϣ��C���Գɼ���");
	scanf_s("%d", &stud[i].score);
	printf("\n������Ҫ����ѧ����Ϣ��רҵ(�ƿ�/�Ź�/����)��");
	scanf_s("%s",&stud[i].subject,5);
	printf("\n������Ҫ����ѧ����Ϣ�Ľ���״��(����/һ��/��)��");
	scanf_s("%s",&stud[i].health,5);
	stud[i].index++;	//indexֵ����1�����ڴ������Լ�
	printf("\n��Ϣ�Ѿ�¼��ϵͳ���Ƿ����¼��ѧ����Ϣ<y/n>��");
	scanf_s("%s",&yn,2);
	if (yn == 'y')
	{
		i++;	//������һ�м�¼������1
		goto ReLuRu;
	}
	else
	{	
		printf("\n�����������˵�\n");
		Sleep(1000);
		main();
	}
}

void LiuLan()
{
	Du();
	printf("========================================================\nѧ��\t\t����\t�Ա�\t����\t�ɼ�\tרҵ\t����״��\n");
	for (int i = 0; stud[i].index == 1; i++)
	{
		printf("%ld\t", stud[i].num);
		printf("%s\t", stud[i].name);
		printf("%s\t", stud[i].sex);
		printf("%d\t", stud[i].age);
		printf("%d\t", stud[i].score);
		printf("%s\t", stud[i].subject);
		printf("%s\n", stud[i].health);
	}
	printf("\n�����������˵�\n");
	Sleep(1000);
	main();
}

void ChaXun()
{
	Du();
	int c_num, CXresult = 0;
	char CXyn;
ReChaXun:printf("��������Ҫ��ѯ��ѧ�ţ�");
	scanf_s("%d", &c_num);
	printf("========================================================\nѧ��\t\t����\t�Ա�\t����\t�ɼ�\tרҵ\t����״��\n");
	for (int i = 0; stud[i].index == 1; i++)
	{
		if (stud[i].num == c_num)
		{
			printf("%ld\t", stud[i].num);
			printf("%s\t", stud[i].name);
			printf("%s\t", stud[i].sex);
			printf("%d\t", stud[i].age);
			printf("%d\t", stud[i].score);
			printf("%s\t", stud[i].subject);
			printf("%s\n", stud[i].health);
			CXresult = 1;
		}
	}
	if (CXresult == 0)
		printf("\nû�в�ѯ����ѧ��%d�������Ϣ", c_num);
	printf("\n��ѯ��ϣ��Ƿ���Ҫ�ٴβ�ѯ<y/n>��");
	scanf_s("%s", &CXyn,2);
	if (CXyn == 'y')
		goto ReChaXun;
	else
	{
		printf("\n�����������˵�\n");
		Sleep(1000);
		main();
	}
}

void ShanChu()
{
	Du();
	int SC_num, i=0;
	printf("��������Ҫɾ����ѧ�ţ�");
	scanf_s("%d", &SC_num);
	for (i = 0;i<100; i++)
	{
		if (stud[i].num==SC_num)
			break;
	}
	if (i < 100)
	{
		for (;i <100; i++)
		{
			stud[i] = stud[i + 1];
		}
	}
	printf("ɾ�����,�����������˵�\n");
	Sleep(1000);
	main();
}

void XiuGai()
{
	Du();
	int CXresult = 0, c_num;
	printf("��������Ҫ�޸ĵ�ѧ�ţ�");
	scanf_s("%d", &c_num);
	for (int i = 0; stud[i].index == 1; i++)
	{
		if (stud[i].num == c_num)
		{
			printf("\n������Ҫ�޸�ѧ����Ϣ��ѧ��<8λ>��");
			scanf_s("%d", &stud[i].num);
			printf("\n������Ҫ�޸�ѧ����Ϣ��������");
			scanf_s("%s", &stud[i].name, 20);
			printf("\n������Ҫ�޸�ѧ����Ϣ���Ա�<�л�Ů>��");
			scanf_s("%s", &stud[i].sex, 3);
			printf("\n������Ҫ�޸�ѧ����Ϣ�����䣺");
			scanf_s("%d", &stud[i].age);
			printf("\n������Ҫ�޸�ѧ����Ϣ��C���Գɼ���");
			scanf_s("%d", &stud[i].score);
			printf("\n������Ҫ�޸�ѧ����Ϣ��רҵ(�ƿ�/�Ź�/����)��");
			scanf_s("%s", &stud[i].subject, 5);
			printf("\n������Ҫ�޸�ѧ����Ϣ�Ľ���״��(����/һ��/��)��");
			scanf_s("%s", &stud[i].health, 5);
			CXresult = 1;
		}
	}
	if (CXresult == 0)
		printf("\nû�в�ѯ����ѧ��%d�������Ϣ", c_num);
	printf("�����������˵�\n");
	Sleep(1000);
	main();
}

void BaoCun()
{
	FILE *fp;
	if (fopen_s(&fp, "StuInf.darthcy", "rt+"))
	{
		printf("can not open the file");
		exit(0);
	}
	for (int i = 0; i < 100; i++)
	{
		fwrite(&stud[i], 51, 1, fp);
	}
	fclose(fp);
	printf("ѧ����Ϣ����ɹ��������������˵�\n");
	Sleep(1000);
	main();
}

void Du()
{
	FILE *fp;
ReDu:if (fopen_s(&fp, "StuInf.darthcy", "r"))
	{
		printf("can not open the file\n");
		if (fopen_s(&fp, "StuInf.darthcy", "w"))
		{
			printf("can not open the file\n");
			exit(0);
		}
		fclose(fp);
		goto ReDu;
	}
	for (int i = 0; i < 100; i++)
	{
		fread(&stud[i], 51, 1, fp);
	}
	fclose(fp);
}