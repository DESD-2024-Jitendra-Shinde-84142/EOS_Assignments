#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/wait.h>

#define MQ_KEY		0x1234

typedef struct msg {
	long type;
	int num1;
	int num2;
	int sum;
} msg_t;

int main() {
	int mqid, ret, s;
	mqid = msgget(MQ_KEY, IPC_CREAT | 0600);
	printf("MQID = %d\n",mqid);
	if(mqid < 0) {
		perror("msgget() failed");
		_exit(1);
	}

	ret = fork();
	if(ret == 0) {
		msg_t m1;
		m1.type = 1;
		printf("Child: Enter num1 and num2: ");
		scanf("%d %d", &m1.num1,&m1.num2);
		ret = msgsnd(mqid, &m1, 2*sizeof(m1.num1), 0);
		printf("Child: Numbers sent: %d\n", ret);
		
		printf("Child: Waiting for the sum...\n");
		ret = msgrcv(mqid, &m1,3*sizeof(m1.sum), 1, 0);
		printf("SUM : %d\n",m1.sum);
	}
	else {
		msg_t m2;
		printf("Parent: Waiting for the numbers...\n");
		ret = msgrcv(mqid, &m2, sizeof(m2.num1)+sizeof(m2.num2), 1, 0);

		printf("Parent: Numbers received: %d -- %d  %d\n", ret, m2.num1,m2.num2);
		
		m2.sum = m2.num1 + m2.num2;
		
		ret = msgsnd(mqid, &m2,3*sizeof(m2.sum), 0);
		printf("Parent: Sum sent: %d\n", ret);

		wait(&s);

		msgctl(mqid, IPC_RMID, NULL);
	}
	return 0;
}








