#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Queue01.h"

void InitAQueue(AQueue* Q) {
	// ����ռ�
	Q = (AQueue*)malloc(sizeof(AQueue));
	if (NULL == Q){
		printf("Malloc Failed");
	}
	// ��ѭ��
	// (*Q)->front = (*Q)->rear = -1;
	
	// ѭ��
	Q->front = Q->rear = 0;

	return Q;
}


void DestoryAQueue(AQueue* Q) {
	
	if (Q->data)
		free(Q->data);
	*Q->data = NULL;
	Q->front = Q->rear = 0;
}


Status IsFullAQueue(const AQueue* Q) {
	if ((Q->rear + 1) == Q->front) {
		printf("Full Queue");
		return TRUE;
	}
	return FALSE;
}

Status IsEmptyAQueue(const AQueue* Q) {
	if (Q->rear == Q->front) {
		printf("Empty Queue");
		return TRUE;
	}
	return FALSE;
}

Status GetHeadAQueue(AQueue* Q) {
	
	if (IsEmptyAQueue(Q)) {
		printf("Empty Queue");
	}
	
	int temp = (Q->front + 1) % MAXQUEUE;
	int e = Q->data[temp];
	printf("��ͷ���ݣ�%d\n", e);

	return TRUE;
}


int LengthAQueue(AQueue* Q) {

	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;
}


Status EnAQueue(AQueue* Q, int x) {
	if (IsFullAQueue(Q) == TRUE) {
		printf("Full Queue");
	}
	 
	else{
		Q->rear = (Q->rear + 1) % MAXQUEUE;
		Q->data[Q->rear] = x;
	}
	return TRUE;
}


Status DeAQueue(AQueue* Q) {
	if (IsEmptyAQueue(Q) == TRUE) {
		printf("Empty Queue");
	}
	else{
		Q->front = (Q->front + 1) % MAXQUEUE;
	}

	return TRUE;
}

void ClearAQueue(AQueue* Q) {
	Q->front = 0;
	Q->rear = 0;
}


Status TraverseAQueue(const AQueue* Q, void (*foo)(AQueue* q)) {
	
	if (IsEmptyAQueue(Q)) return;
	foo = APrint;
	foo(Q);

	return TRUE;
}


void APrint(AQueue* Q) {

	for (int i = (Q->front + 1) % MAXQUEUE; i != (Q->rear + 1) % MAXQUEUE; i = (i + 1) % MAXQUEUE) {
		printf("%d ", Q->data[i]);
	}
	printf("\n");
}

int main(void) {

	AQueue q;
	InitAQueue(&q);
	int a = 3;

	for (int i = 1; i < 7; i++)
	{
		EnAQueue(&q, i);
	}
	printf("��ǰ����������\n");
	TraverseAQueue(&q, APrint);

	//int front;
	GetHeadAQueue(&q);
	
	// ����
	printf("��������\n");
	DeAQueue(&q);
	DeAQueue(&q);
	
	printf("�ӳ���%d\n", LengthAQueue(&q));
	printf("��ǰ����������\n");
	TraverseAQueue(&q, APrint);

	GetHeadAQueue(&q);

	//��������
	EnAQueue(&q, 7);
	EnAQueue(&q, 8);
	TraverseAQueue(&q, APrint);

	ClearAQueue(&q);
	DestoryAQueue(&q);
	printf("Well Done");
}
