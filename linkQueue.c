#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"
void InitLQueue(LQueue* Q) {
    
    if (Q == NULL) {
        return;
    }
    memset(Q, 0, sizeof(LQueue));   // �ӳ�������
    Q->front = NULL;
    Q->rear = NULL;
}
void DestoryLQueue(LQueue* Q) {
    if (IsEmptyLQueue(Q)) {
        return;
    }
    Node* temp = Q->front;
    while (NULL != temp) {
        Q->front = temp->next;
        free(temp);
        temp = Q->front;
    }
    free(Q);
    Q = NULL;
}
Status EnLQueue(LQueue* Q, int data) {
    
    Node* pNode = (Node*)malloc(sizeof(Node));  // �����½ڵ�
    if (NULL == pNode){
        return FALSE;
    }
    pNode->data = data;  // ��������
    if (Q->length == 0){
        Q->front = pNode;
        Q->rear = pNode;
        Q->length++;
        return TRUE;
    }
    Q->rear->next = pNode;  // ����β�ڵ�
    Q->rear = pNode;  // ����β�ڵ�
    Q->length++;
    return TRUE;
}
Status DeLQueue(LQueue* Q) {
   
    if (Q == NULL || Q->length == 0) {
        return FALSE;
    }
    Node* temp = Q->front;
    Q->front = temp->next;
    free(temp);
    Q->length--;
    return TRUE;
}
Status IsEmptyLQueue(const LQueue* Q) {
    if (Q->front == Q->rear) {
        return TRUE;
    }
    return FALSE;
}
void ClearLQueue(LQueue* Q) {
    Q->front = Q->rear;
    Q->length = 0;
}
void LPrint(LQueue* Q) {

    printf("��������Ϊ��\n");
    /*
    while (Q->front) {
        //Q->rear->next = NULL;
        printf("%d ", Q->front->data);
        Q->rear = Q->front->next;
        Q->front = Q->rear;
    }*/
    Node* temp = Q->front;
    while (temp != Q->rear) {
        temp = temp->next;
        printf("%d  ", temp->data);
    }
    printf("\n");
}

Status TraverseLQueue(const LQueue* Q, void (*foo)(LQueue* Q)) {

    if (IsEmptyLQueue(Q)) {
        printf("��\n");
        return FALSE;
    }
    foo = LPrint;
    foo(Q);
    return TRUE;
}
int LengthLQueue(LQueue* Q) {
    return Q->length;
}
Status GetHeadLQueue(LQueue* Q, int e) {
    if (IsEmptyLQueue(Q)) {
        return FALSE;
    }
    printf("%d\n", e);
    return TRUE;
}
int main(void) {

    // �����ն���
    LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
    InitLQueue(Q);
    if (NULL == Q) {
        printf("Initial Error!\n");
        return FALSE;
    }

    printf("��ӣ�\n");
    for (int i = 0; i < 5; i++) {
        EnLQueue(Q, i);
    }

    printf("��ͷ��\n");
    int e = 0;
    GetHeadLQueue(Q, e);

    // �жϷǿ�
    int j = IsEmptyLQueue(Q);
    printf("%d\n", j);

    // �ӳ�
    printf("�ӳ���%d\n", LengthLQueue(Q));
    
    // ��ӡ(������
    TraverseLQueue(Q, LPrint);

    printf("���ӣ�\n");
    while (IsEmptyLQueue(Q)) {
        DeLQueue(Q);
    }
    printf("���ӳɹ���\n");

    // ��ն���
    printf("��գ�\n");
    ClearLQueue(Q);
    printf("��ճɹ���\n");

    printf("�ٴα���: \n");
    TraverseLQueue(Q, LPrint);

    // ���е�����
    printf("���٣�\n");
    DestoryLQueue(Q);
    printf("���ٳɹ���\n");

    // ���
    printf("Well Done!");
}
