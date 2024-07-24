
// DTC_DID_RoutineControl.xls
// 53.5 KB
// HCM_DTC_DID1219.rar
// 10.4 MB
// ���ϻؼҰ�DID IO ʣ�µ�����
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
}LNode,*LinkList;//��ͬһ�ṹ��ָ������������������,LinkList���ָ��ָ����ǽṹ��

Status InitList(LinkList *L)//��ʼ��
{
	*L=(struct LNode *)malloc(sizeof(struct LNode)); 
	(*L)->next=NULL;
	return OK;
}

void CreateList(LinkList *L,int n)//����������
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

Status ListInsert(LinkList L,int i,ElemType e)//���������
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

LNode *LocateElem(LinkList L,ElemType e)//查找操作 
{
	LNode *p;
	p=L->next;

	while(p && (p->data!=e))	
	{
		p=p->next;
	}

	return p;
}
Status GetElem(LinkList L,int i,ElemType *e)//取值操�? 
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

Status ListDelete(LinkList L,int i)//删除操作 
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
		printf("%d\n",p->data);//第一次遍历输出的是单链表长度 
		TraverseList(p->next);
	}
}

void menu()
{
	printf("*************\n1,��ʼ��˳���\n2,����������\n3,����\n4,����\n5,����\n6,ɾ��\n7,ȡֵ\n8,�ݹ���������ڵ�\n*************\n");
}

int main()
{
	menu();
	LinkList L;//头指�? 

	int *z;
	int i,k,flag=1,e,n;
	while(flag)
	{
		printf("������ָ��\n");
		scanf("%d",&k);
		switch(k)
		{
			case 1:
				if(InitList(&L)==OK)
					printf("�ڴ����ɹ�\n");
				else
					printf("�ڴ����ʧ��\n");
				break;
			case 2:
				printf("����Ҫ�����ĵ������Ԫ�ظ���\n");
				scanf("%d",&n);
				printf("���������Ԫ�� \n");
				CreateList(&L,n);
				printf("�����ĵ�����ɹ�\n");
				printf("�ڶ���Ԫ��ֵ��%d\n",L->next->next->data);
				break;
			case 3:
				printf("��ֱ���������λ�úͲ��������,����:(2,1000)ע�ⶺ��ΪӢ���ַ�\n\n");
				scanf("%d,%d",&i,&e);
				if(ListInsert(L,i,e)==OK)
					printf("����ɹ�\n");
				else
					 printf("����ʧ��\n");
					 break;
			case 4:
				flag=0;
				break;
			case 5: 
				printf("������Ҫ���ҵ�����:\n");
				scanf("%d",&e);
				if(LocateElem(L,e)==NULL)
					printf("����ʧ��\n");
				else
					printf("��������λ��Ϊ%d\n",LocateElem(L,e));
				break;	
			case 6:
				printf("��Ҫɾ���ڼ�������:\n");
				scanf("%d",&i);
				if(ListDelete(L,i)==OK) 
					printf("ɾ���ɹ�\n");
				else
					printf("ɾ��ʧ��\n");
				break;
			case 7:
				z=&k;
				printf("��Ҫȡ�ڼ�������:\n");
				scanf("%d",&i);
				if(GetElem(L,i,&k)==OK)
					printf("��%d������Ϊ:%d\n",i,k);
				else
					printf("ȡֵʧ��\n");
				break;
			case 8:
				TraverseList(L);
				break;
			default:
				printf("��������\n");
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
// }stu;//����һ�����������ģ��

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