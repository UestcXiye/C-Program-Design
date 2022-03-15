#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define N 10
#define D 10
#define H 10
//#define PASSWORD 123
#define ASK (ORDER*)malloc(sizeof(ORDER))
#define MaxCapacity 4
//定义订单结构体
typedef struct Order
{
	int Table_ID;//记录餐桌号
	int Dish_ID[N];//记录菜的编号
	struct Order * next;
}ORDER;

//定义餐桌结构体
typedef struct Table
{
	int Table_ID;//餐桌编号
	int Capacity;//餐桌最多能容纳的人数
	int Table_State;//1 有人在用，0 没人用
}TABLE;

//定义菜的结构体
typedef struct Dish
{
	int Dish_ID;//菜的编号
	char Dish_Name[10];//菜名
	float Dish_Price;//价格
}DISH;
TABLE tb[H];//餐厅结构体数组
DISH dish[D];//菜的结构体数组
int PASSWORD = 123;//密码设置
//函数定义
void Load_Dish(void);//从文件中读取菜谱
ORDER*CreateOne(int);//创建一个订单节点
void Dish_Menu(void);//显示菜谱
void Table_Init(void);//餐厅信息初始化
int search(void);//查找匹配的餐桌
ORDER* Dish_Order(ORDER *, ORDER *);//将节点添加到主链
void Display(int);//显示菜的信息
void saveInList(float);//将客户消费额写入账单
void Save_Inform(ORDER *, int);//将已结账订单信息写入历史记录
ORDER *Payment(ORDER *);//结账
void ModifyPW(void);//密码修改
int Pass_Word(void);//密码验证
void Observe(void);//账目查询
void ListMenu(void);//账单管理菜单
void List_Management(void);//账单管理
void Main_Menu(void);//主菜单
void Get_Rank(void);//统计
void Menu_select(void);//选择功能
//主函数
int main()
{
	Table_Init();
	Menu_select();
}
//系统主菜单
void Main_Menu()
{
	printf("\n*********************\n");
	printf("餐厅服务系统\n");
	printf("*********************\n");
	printf("1.点菜\n");
	printf("2.客户结账\n");
	printf("3.账目管理\n");
	printf("4.餐厅统计\n");
	printf("5.退出系统\n");
}
//选择功能
void Menu_select(void)
{
	ORDER* head;
	int choose;
	int result;
	head = NULL;
	system("cls");
	do {
		Load_Dish();
		Main_Menu();
		printf("请选择：\n");
		fflush(stdin);
		scanf_s("%d", &choose);
		//system("cls");
		switch (choose)
		{
		case 1:result = search();
			if (result == 1)
				printf("您可以到%d号餐桌就餐\n", result);
			else 
				printf("您和您的朋友可以到%d号餐桌就餐\n", result);
			Dish_Menu();
			head = Dish_Order(head, CreateOne(result));
			//system("cls");
			break;
		case 2:head = Payment(head);
			break;
		case 3:List_Management();
			break;
		case 4:Get_Rank();
			break;
		case 5:exit(1);
			break;
		}
	} while (1);
}
//从文件中读取菜谱
void Load_Dish(void)
{
	FILE *fp;
	int i;
	fp = fopen("dish_name.txt", "r");
	for (i = 0; i < D; i++)
	{
		fscanf(fp, "%d\t%s\t%f\n", &dish[i].Dish_ID, dish[i].Dish_Name,
			&dish[i].Dish_Price);
	}
}
//餐桌初始化
void Table_Init(void)
{
	tb[0].Capacity =1; tb[0].Table_ID =1;
	tb[1].Capacity =1; tb[1].Table_ID =2;
	tb[2].Capacity =2; tb[2].Table_ID =3;
	tb[3].Capacity =2; tb[3].Table_ID =4;
	tb[4].Capacity =2; tb[4].Table_ID =5;
	tb[5].Capacity =3; tb[5].Table_ID =6;
	tb[6].Capacity =4; tb[6].Table_ID =7;
	tb[7].Capacity =4; tb[7].Table_ID =8;
	tb[8].Capacity =4; tb[8].Table_ID =9;
	tb[9].Capacity =4; tb[9].Table_ID =10;
}
//显示菜谱
void Dish_Menu(void)
{
	int i;
	printf("*********欢迎选购本店菜*********\n");
	printf("菜编号\t菜名\t菜单价\n");
	for (i = 0; i < D; i++)
	{
		printf("%d\t%s\t%f\n", dish[i].Dish_ID, dish[i].Dish_Name,
			dish[i].Dish_Price);
	}
}
//查找有没有匹配的餐桌
int search(void)
{
	int Cust_Num;
	int i;
	printf("请输入来客数量:\n");
	scanf_s("%d", &Cust_Num);
	if (MaxCapacity < Cust_Num)
	{
		printf("抱歉，本店没有容纳%d的餐桌！", Cust_Num);
		return -1;
	}
	while (MaxCapacity >= Cust_Num)
	{
		for (i = 0; i < H; i++)
		{
			if (tb[i].Table_State == 0)
			{
				if (tb[i].Capacity == Cust_Num)
					return (tb[i].Table_ID);
			}
		}
		printf("抱歉，现在没有%d人桌", Cust_Num);
		Cust_Num += 1;
	}
	printf("餐厅已满，请客人稍等一会。");
}
//创建一份订单
ORDER*CreateOne(int result)
{
	ORDER*p;
	int i;
	p = ASK;
	if (result != -1)
	{
		p->Table_ID = result;
		for (i = 0; i < D; i++)
		{
			printf("请输入菜的编号，按0结束输入：");
			scanf("%d", &p->Dish_ID[i]);
			if (p->Dish_ID[i] < 0 || p->Dish_ID[i]>10)
			{
				printf("超出菜谱范围，请重新输入\n");
				i--;
			}
			else if (p->Dish_ID[i] == 0)
				break;
			else
				p->Dish_ID[i] = 0;
		}
		tb[result - 1].Table_State = 1;
	}
	p->next = NULL;
	return p;
}
//添加到主链
ORDER* Dish_Order(ORDER *head, ORDER *p)
{
	ORDER *p1;
	p1 = head;
	if (p1 != NULL)
	{
		if (p != NULL)
		{
			while (p1->next != NULL)
			{
				p1 = p1->next;
			}
			p1->next = p;
			printf("订单创建成功\n");
		}
		else 
			printf("订单创建失败\n");
	}
	else
	{
		if (head == NULL && p != NULL)
			head = p;
	}
	return head;
}
//根据菜的编号打印一道菜的信息
void Display(int ID)
{
	int i = 0;
	for (i = 0; i < D; i++)
	{
		if (dish[i].Dish_ID == ID)
		{
			printf("%d\t%s\t%f\n", dish[i].Dish_ID, dish[i].Dish_Name,
				dish[i].Dish_Price);
			break;
		}
	}
}
//将消费额写入账单
void saveInList(float pay)
{
	FILE *fp;
	time_t timer;
	timer = time(NULL);
	if ((fp = fopen("账本.txt", "a")) == NULL)
	{
		printf("操作失败\n");
		exit(1);
	}
	fprintf(fp, "%f\t%s\n", pay, ctime(&timer));//系统时间有问题
	printf("账本保存成功\n");
	fclose(fp);
}
//将已结账客户写入历史记录
void Save_Inform(ORDER *p, int m)
{
	FILE *fp;
	time_t timer;
	int i = 0;
	timer = time(NULL);
	if ((fp = fopen("历史记录.txt", "a")) == NULL)
	{
		printf("操作失败\n");
		exit(1);
	}
	fprintf(fp, "%d\n", m);
	while (p->Dish_ID[i] > 0)
	{
		fprintf(fp, "%d\t%s\t%f\n",dish[p->Dish_ID[i]-1].Dish_ID,
			dish[p->Dish_ID[i] - 1].Dish_Name,
			dish[p->Dish_ID[i] - 1].Dish_Price);
		i++;
	}
	fprintf(fp, "%s", ctime(&timer));
	printf("历史记录保存成功\n");
	fclose(fp);
}
//结账
ORDER *Payment(ORDER *head)
{
	int i = 0;
	int count = 0;
	float pay = 0.0;
	float Pay;
	int ID;
	ORDER *p, *p1;
	p = head;
	printf("请输入您的餐桌号\n");
	fflush(stdin);
	scanf("%d", &ID);
	while (p != NULL)
	{
		if (p->Table_ID == ID)
		{
			printf("您点餐的情况如下:\n");
			printf("编号\t菜名\t价格\n");
			while (p->Dish_ID[i] != 0)
			{
				Display(p->Dish_ID[i]);
				pay += dish[p->Dish_ID[i] - 1].Dish_Price;
				i++;
				count++;
			}
			printf("您一共点了%d个菜\n", count);
			printf("您本次的消费额为%f元\n", pay);
			printf("您实际的付款:\n");
			scanf("%f", &Pay);
			if (Pay > pay)
			{
				printf("找您%f元\n", Pay - pay);
			}
			printf("谢谢您的惠顾，欢迎下次光临\n");
			if (count > 0)
			{
				saveInList(pay);
				Save_Inform(p, count);
			}
			tb[p->Table_ID].Table_State = 0;
			break;
		}
		else
		{
			p1 = p;
			p = p->next;
		}
		if (p == head)
			head = head->next;
		else
			p1->next = p->next;
		free(p);
		return head;
	}
}
//修改密码
void ModifyPW()
{
	int password;
	printf("请输入新的密码\n");
	scanf("%d", &password);
	PASSWORD = password;
	printf("密码修改成功\n");
}

//查看账目
void Observe()
{
	FILE *fp;
	float pay;
	char str[25];
	int i = 0;
	int j = 0;
	if ((fp = fopen("账本.txt", "r")) == NULL) {
		printf("操作失败\n");
		exit(1);
	}
	printf("消费金额\t消费时间\n");
	while (!feof(fp)) {
		i = 0;
		j = 0;
		fscanf(fp, "%c", &str[j]);
		j++;
		if (str[j] == ' ')
			i++;
	}
	fscanf(fp, "\n\n");
	i = 0;
	j = 0;
	printf("%f\t", pay);
	while (i <= 5 && j < 25)
	{
		printf("%c", str[j]);
		j++;
		if (str[j] == ' ')
			i++;
	}
	printf("\n");

	fclose(fp);
}
//账单管理菜单
void ListMenu()
{
	int choice;
	printf("1.修改密码\n");
	printf("2.查看账本\n");
	printf("3.返回\n");
	do {
		printf("请选择:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:ModifyPW(); 
			break;
		case 2:Observe(); 
			break;
		case 3:Menu_select();
			break;
		default:printf("没有该功能项\n");
			break;
		}
	} while (1);
}
//账单管理
void List_Management()
{
	FILE *fp;
	if ((fp = fopen("账本.txt", "r")) == NULL)
	{
		printf("操作失败\n");
		exit(1);
	}
	if (Pass_Word())
		ListMenu();
}
//获得近期各菜的受欢迎程度
void Get_Rank(void) {
	FILE *fp;
	int n, i, m = 0, j;
	int count[10] = { 0 }, t = 0;
	char s[16] = "", a[10];
	fp = fopen("历史记录.txt", "r");
	while (!feof(fp))
	{
		fscanf(fp, "%d\n", &n);
		i = 0;
		while (i != n)
		{
			fscanf(fp, "%d%*s%*s", &m, s, s);
			for (j = 0; j < 10; j++)
			{
				if (m == dish[j].Dish_ID) {
					count[j]++;
					break;
				}
			}
			i++;
			if (i == n)
				fscanf(fp, "%*s%*s%*s%*s%*s\n", s, s, s, s, s);
		}
	}
	printf("菜的受欢迎程度如下:\n");
	for (i = 0; i < 10; i++)
	{
		printf("\n%d菜:", i + 1);
		for (j = 0; j < count[i]; j++)
			printf(" * ");
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9 - i; j++)
		{
			if (count[j] < count[j + 1])
			{
				t = count[j];
				strcpy(a, dish[j].Dish_Name);
				count[j] = count[j + 1];
				strcpy(dish[j].Dish_Name, dish[j + 1].Dish_Name);
				count[j + 1] = t;
				strcpy( dish[j+1].Dish_Name,a);
			}
		}
	}
	printf("\n比较受顾客欢迎的四个菜是:\n");
	for (i = 0; i < 4; i++)
	{
		printf("%s\n", dish[i].Dish_Name);
	}
}
//密码验证
int Pass_Word() {
	int password;
	do {
		printf("请输入密码\n");
		scanf("%d", &password);
		if (PASSWORD == password)
		{
			printf("**********************************\n");
			printf("    欢迎进入账目管理系统\n");
			printf("**********************************\n");
			return 1;
		}
		else
		{
			printf("密码输入有误，请重新输入\n");
			printf("是否重新输入\n");
		}
	} while (getchar() == 'y' || getchar() == 'Y');
	return 0;
}











