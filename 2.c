
// DTC_DID_RoutineControl.xls
// 53.5 KB
// HCM_DTC_DID1219.rar
// 10.4 MB
// 晚上回家把DID IO 剩下的做了
// HCM_DIDIO1220.zip
// 1.5 MB
// HCM_DTC.7z
// 11.9 MB
// HCM_DIDIO.7z
// 1.3 MB
// x86_64-8.1.0-release-win32-sjlj-rt_v6-rev0.7z
// 50.4 MB
#include<stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType ;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;//对同一结构体指针类型起了两个名字,LinkList这个指针指向的是结构体

Status InitList(LinkList *L)//初始化
{
	*L=(struct LNode *)malloc(sizeof(struct LNode)); 
	(*L)->next=NULL;
	return OK;
}

void CreateList(LinkList *L,int n)//创建单链表
{	
	int i;
	LNode *r,*p;
	*L=(struct LNode *)malloc(sizeof(struct LNode)); 
	(*L)->data=n;
	(*L)->next=NULL;

	r=*L;
	for(i=0;i<n;++i)
	{
		p=(struct LNode *)malloc(sizeof(struct LNode)); 
		scanf("%d",&(p->data));
		p->next=NULL;r->next=p;
		r=p;
	} 

}

Status ListInsert(LinkList L,int i,ElemType e)//单链表插入
{
	LNode *p;
	LNode *s;
	p=L;
	int j=0;
	while(p&&(j<i-1))
	{
		p=p->next;
		++j; 
	}
	if(!p||j>i-1) return ERROR;
	s=(struct LNode *)malloc(sizeof(struct LNode)); 
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

LNode *LocateElem(LinkList L,ElemType e)//鏌ユ壘鎿嶄綔 
{
	LNode *p;
	p=L->next;

	while(p && (p->data!=e))	
	{
		p=p->next;
	}

	return p;
}
Status GetElem(LinkList L,int i,ElemType *e)//鍙栧�兼搷浣? 
{
	LNode *p;
	p=L->next;
	int j=1;
	while(p&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i) return ERROR;
	*e=p->data;
	return OK;
}

Status ListDelete(LinkList L,int i)//鍒犻櫎鎿嶄綔 
{
	LNode *p,*q;
	p=L;
	int j=0;
	while((p->next)&&(j<i-1))
	{
		p=p->next;
		++j;
	}
	if(!(p->next)||(j>i-1)) return ERROR;
	q=p->next;
	p->next=q->next;
	free (q);
	return OK;
}

void TraverseList(LinkList p)
{
	if(p)
	{
		printf("%d\n",p->data);//绗竴娆￠亶鍘嗚緭鍑虹殑鏄崟閾捐〃闀垮害 
		TraverseList(p->next);
	}
}

void menu()
{
	printf("*************\n1,初始化顺序表\n2,创建单链表\n3,插入\n4,结束\n5,查找\n6,删除\n7,取值\n8,递归输出各个节点\n*************\n");
}

int main()
{
	menu();
	LinkList L;//澶存寚閽? 

	int *z;
	int i,k,flag=1,e,n;
	while(flag)
	{
		printf("请输入指令\n");
		scanf("%d",&k);
		switch(k)
		{
			case 1:
				if(InitList(&L)==OK)
					printf("内存分配成功\n");
				else
					printf("内存分配失败\n");
				break;
			case 2:
				printf("输入要创建的单链表的元素个数\n");
				scanf("%d",&n);
				printf("请输入各个元素 \n");
				CreateList(&L,n);
				printf("创建的单链表成功\n");
				printf("第二个元素值：%d\n",L->next->next->data);
				break;
			case 3:
				printf("请分别而输入插入位置和插入的数据,例如:(2,1000)注意逗号为英文字符\n\n");
				scanf("%d,%d",&i,&e);
				if(ListInsert(L,i,e)==OK)
					printf("插入成功\n");
				else
					 printf("插入失败\n");
					 break;
			case 4:
				flag=0;
				break;
			case 5: 
				printf("请输入要查找的数据:\n");
				scanf("%d",&e);
				if(LocateElem(L,e)==NULL)
					printf("查找失败\n");
				else
					printf("数据所在位置为%d\n",LocateElem(L,e));
				break;	
			case 6:
				printf("您要删除第几个数据:\n");
				scanf("%d",&i);
				if(ListDelete(L,i)==OK) 
					printf("删除成功\n");
				else
					printf("删除失败\n");
				break;
			case 7:
				z=&k;
				printf("您要取第几个数据:\n");
				scanf("%d",&i);
				if(GetElem(L,i,&k)==OK)
					printf("第%d个数据为:%d\n",i,k);
				else
					printf("取值失败\n");
				break;
			case 8:
				TraverseList(L);
				break;
			default:
				printf("输入有误\n");
				break;
		}
	}
}
// #include<stdio.h>
// #include<malloc.h>

// typedef struct student
// {
//     int data;
//     struct student *next;
// }stu;//建立一个链表的数据模板

// int InitList(stu *L)
// {
//     L = (struct student*)malloc(sizeof(struct student));
//     L->next=NULL;
// 	return 1;
// }

// void CreatList(stu** L,int n)
// {
//     int i;
//     stu *r,*p;
//     *L = (struct student *)malloc(sizeof(struct student));
//     (*L)->data=n;
// 	(*L)->next=NULL;

//     r=*L;
//     for(i=0;i<n;++i)
// 	{
// 		p=(struct student *)malloc(sizeof(struct student)); 
// 		scanf("%d",&(p->data));
// 		p->next=NULL;r->next=p;
// 		r=p;
// 	} 
// }