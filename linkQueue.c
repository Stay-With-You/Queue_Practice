#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LQueue.h"
void InitLQueue(LQueue* Q) {
    
    if (Q == NULL) {
        return;
    }
    memset(Q, 0, sizeof(LQueue));   // 队长等置零
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
    
    Node* pNode = (Node*)malloc(sizeof(Node));  // 创建新节点
    if (NULL == pNode){
        return FALSE;
    }
    pNode->data = data;  // 插入数据
    if (Q->length == 0){
        Q->front = pNode;
        Q->rear = pNode;
        Q->length++;
        return TRUE;
    }
    Q->rear->next = pNode;  // 插入尾节点
    Q->rear = pNode;  // 更新尾节点
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

    printf("队中内容为：\n");
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
        printf("空\n");
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

    // 创建空队列
    LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
    InitLQueue(Q);
    if (NULL == Q) {
        printf("Initial Error!\n");
        return FALSE;
    }

    printf("入队：\n");
    for (int i = 0; i < 5; i++) {
        EnLQueue(Q, i);
    }

    printf("队头：\n");
    int e = 0;
    GetHeadLQueue(Q, e);

    // 判断非空
    int j = IsEmptyLQueue(Q);
    printf("%d\n", j);

    // 队长
    printf("队长：%d\n", LengthLQueue(Q));
    
    // 打印(遍历）
    TraverseLQueue(Q, LPrint);

    printf("出队：\n");
    while (IsEmptyLQueue(Q)) {
        DeLQueue(Q);
    }
    printf("出队成功！\n");

    // 清空队列
    printf("清空：\n");
    ClearLQueue(Q);
    printf("清空成功！\n");

    printf("再次遍历: \n");
    TraverseLQueue(Q, LPrint);

    // 队列的销毁
    printf("销毁：\n");
    DestoryLQueue(Q);
    printf("销毁成功！\n");

    // 检测
    printf("Well Done!");
}
