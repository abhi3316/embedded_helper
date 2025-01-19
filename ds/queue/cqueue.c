#include <stdio.h>


#define SIZE (5)


typedef struct queue {
	int value[SIZE];
	int rear, front;
}_que;

int init_queue(_que *q) {
	if(q == NULL) {
		printf("PTR NULL\n");
		return -1;
	}
	q->rear = SIZE -1;
	q->front = SIZE -1;
	return 0;
};


int enque(_que *q, int val) {
	int pos = 0;
	if(q == NULL) {
		printf("PTR NULL\n");
		return -1;
	}
	pos = (q->rear + 1) % SIZE;
	if(pos == q->front) {
		printf("Queue Overflow\n");
		return -1;
	}
	q->value[pos] = val;
	q->rear = pos;
	return 0;
}

int deque(_que *q) {
	int val = 0;
	if(q == NULL) {
		printf("PTR NULL\n");
		return -1;
	}
	if(q->front == q->rear) {
		printf("Queue underflow\n");
		return -1;
	}
	q->front =  (q->front + 1) % SIZE;
	val = q->value[q->front];
	return val;
} 

int main(void) {
	_que q;
	init_queue(&q);
	for(int i = 0; i< 4; i++) {
		enque(&q, i);
	}
	//printf("dd is %d\n", deque(&q));
	//enque(&q, 9);
	for(int i = 0; i< 4; i++) {
		printf("Val is %d\n", deque(&q));
	}

	return 0;
}



