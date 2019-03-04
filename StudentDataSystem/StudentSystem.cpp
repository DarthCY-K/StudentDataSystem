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
	SetConsoleTitle("学生数据库管理系统v1.2 by DarthCY");
	int choose;
	printf("                                =========学生信息管理系统=========\n");
	printf("                                         1.录入学生信息           \n");
	printf("                                         2.浏览学生信息           \n");
	printf("                                         3.查询学生信息           \n");
	printf("                                         4.删除学生信息           \n");
	printf("                                         5.添加学生信息(暂未启用) \n");
	printf("                                         6.修改学生信息           \n");
	printf("                                         7.保存学生信息           \n");
	printf("                                         8.透出信息系统           \n");
	printf("                                ==================================\n");
	printf("请选择菜单（1-8）：\n");
	scanf_s("%d", &choose);
	switch (choose)
	{
		case 1:LuRu();break;
		case 2:LiuLan();break;
		case 3:ChaXun();break;
		case 4:ShanChu();break;
		case 6:XiuGai();break;
		case 7:BaoCun();break;
		case 8:printf("程序终止\n");system("pause");exit(0);
	}
	system("pause");		//大佬说用getchar()或者std::cin.get来代替
}

void LuRu()		//录入函数模块
{
	int i=0,n;char yn;	//stud[0].index = 1;测试模块未启用
ReLuRu:if (stud[i].index != 0)	//ReLuRu标识符 针对原先可能存在数据行的覆写保护
	{		//printf("\n发现记录行%d已存在记录，",i);
		i++;	//printf("即将转入第%d行继续检索\n",i);
		Sleep(300);
		goto ReLuRu;
	}
	Du();
	printf("\n请输入要插入学生信息的学号<8位>：");
	scanf_s("%d", &stud[i].num);
	printf("\n请输入要插入学生信息的姓名：");
	scanf_s("%s",&stud[i].name,20);
	printf("\n请输入要插入学生信息的性别<男或女>：");
	scanf_s("%s",&stud[i].sex,3);
	printf("\n请输入要插入学生信息的年龄：");
	scanf_s("%d", &stud[i].age);
	printf("\n请输入要插入学生信息的C语言成绩：");
	scanf_s("%d", &stud[i].score);
	printf("\n请输入要插入学生信息的专业(计科/信管/电信)：");
	scanf_s("%s",&stud[i].subject,5);
	printf("\n请输入要插入学生信息的健康状况(良好/一般/差)：");
	scanf_s("%s",&stud[i].health,5);
	stud[i].index++;	//index值自增1，用于存在性自检
	printf("\n信息已经录入系统！是否继续录入学生信息<y/n>：");
	scanf_s("%s",&yn,2);
	if (yn == 'y')
	{
		i++;	//进行下一行记录，自增1
		goto ReLuRu;
	}
	else
	{	
		printf("\n即将返回主菜单\n");
		Sleep(1000);
		main();
	}
}

void LiuLan()
{
	Du();
	printf("========================================================\n学号\t\t姓名\t性别\t年龄\t成绩\t专业\t健康状况\n");
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
	printf("\n即将返回主菜单\n");
	Sleep(1000);
	main();
}

void ChaXun()
{
	Du();
	int c_num, CXresult = 0;
	char CXyn;
ReChaXun:printf("请输入需要查询的学号：");
	scanf_s("%d", &c_num);
	printf("========================================================\n学号\t\t姓名\t性别\t年龄\t成绩\t专业\t健康状况\n");
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
		printf("\n没有查询到与学号%d的相关信息", c_num);
	printf("\n查询完毕，是否需要再次查询<y/n>：");
	scanf_s("%s", &CXyn,2);
	if (CXyn == 'y')
		goto ReChaXun;
	else
	{
		printf("\n即将返回主菜单\n");
		Sleep(1000);
		main();
	}
}

void ShanChu()
{
	Du();
	int SC_num, i=0;
	printf("请输入需要删除的学号：");
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
	printf("删除完毕,即将返回主菜单\n");
	Sleep(1000);
	main();
}

void XiuGai()
{
	Du();
	int CXresult = 0, c_num;
	printf("请输入需要修改的学号：");
	scanf_s("%d", &c_num);
	for (int i = 0; stud[i].index == 1; i++)
	{
		if (stud[i].num == c_num)
		{
			printf("\n请输入要修改学生信息的学号<8位>：");
			scanf_s("%d", &stud[i].num);
			printf("\n请输入要修改学生信息的姓名：");
			scanf_s("%s", &stud[i].name, 20);
			printf("\n请输入要修改学生信息的性别<男或女>：");
			scanf_s("%s", &stud[i].sex, 3);
			printf("\n请输入要修改学生信息的年龄：");
			scanf_s("%d", &stud[i].age);
			printf("\n请输入要修改学生信息的C语言成绩：");
			scanf_s("%d", &stud[i].score);
			printf("\n请输入要修改学生信息的专业(计科/信管/电信)：");
			scanf_s("%s", &stud[i].subject, 5);
			printf("\n请输入要修改学生信息的健康状况(良好/一般/差)：");
			scanf_s("%s", &stud[i].health, 5);
			CXresult = 1;
		}
	}
	if (CXresult == 0)
		printf("\n没有查询到与学号%d的相关信息", c_num);
	printf("即将返回主菜单\n");
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
	printf("学生信息保存成功！即将返回主菜单\n");
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