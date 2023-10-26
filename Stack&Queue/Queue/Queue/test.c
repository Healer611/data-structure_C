#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	//while (!QueueEmpty(&q)) {
	//	printf("%d", QueueFront(&q));
	//	QueuePop(&q);
	//}
	//printf("\n");
	printf("%d\n", QueueBack(&q));
	QueueDestroy(&q);
}

int main()
{
	TestQueue();

	return 0;
}
