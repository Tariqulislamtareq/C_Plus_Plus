#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<stdlib.h>



struct station{
	sem_t sm;
	int userTrainNumber,userChoice,foodChoice,coachChoice;
	int trainNumbers[10]={231,452,563,674,105,546,327,688,949,100};
};


void *passengar( struct station s);
void *train_on_board( struct station s);

int main()
{
	struct station s;
	sem_init(&s.sm,0,1);
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,passengar,NULL);
	pthread_create(&thread2,NULL,train_on_board,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}
void *passengar(struct station s)
{
	sem_wait(&s.sm);
	int b[5]={123,134,145,156,167};
	int f=1;
	while(f==1)
	{
	printf("IRCTC\n");
	printf("train number:\n");
	scanf("%d",&s.userTrainNumber);
	for(int c=0;c<=s.trainNumbers.size();c++)
	{
		if(s.trainNumbers[c]==s.userTrainNumber)
		{
			printf("YOUR TRAIN IS ON BOARD\n");
			printf("1 FOOD\n2 COACH\n3 PREMIUM CLASS\n:-");
   	        scanf("%d",&s.userChoice);
			switch(s.userChoice)
			{
				case 1:
					printf("1 FOR VEG\n2 NON VEG\n3 CONTINENTAL\n");
					scanf("%d",&s.foodChoice);
					switch(s.foodChoice)
					{
						case 1:
							printf("SELECTED VEG FOOD\n");
							break;
						case 2:
							printf("SELECTED NON VEG FOOD\n");
							break;
						case 3:
							printf("SELECTED CONTINENTAL FOOD\n");
							break;
					}
					break;
				case 2:
					printf("1 S2\n2 S3\n 3 S5\n");
					scanf("%d",&s.coachChoice);
					switch(s.coachChoice)
					{
						case 1:
							printf("SELECTED S2");
							break;
						case 2:
							printf("SELECTED S3");
							break;
						case 3:
							printf("SELECTED S5");
							break;
					}
					break;
			    case 3:
			    	printf("SELECTED PREMIUM");
			    	break;
			
	     	}
	    }
		else
		{
			printf("WRONG TRAIN NUMBER\n");
			break;
		}
	break;
	}
	for(int d=0;d<=b.size();d++)
	{
		if(b[d]==s.userTrainNumber)
		{
			printf("STATION IS NOT ON BOARD");
		    printf("YOU ARE GOING TO REACH TO DESTINATION");
			printf("WAIT FOR YOUR DESTINATION");
			
		}
		
	}
	
}
	sleep(1);
	sem_post(&s.sm);
}

void *train_on_board( struct station s)
{
	sem_wait(&s.sm);
	int b[5]={123,134,145,156,167};
	printf("TRAIN NUMBER:");
	scanf("%d",&s.userTrainNumber);
	for(int c=0;c<=8;c++)
	{
		if(s.trainNumbers[c]==s.userTrainNumber)
		{
			printf("YOU ARE IN YOUR DESTINATION");
			printf("PLEASE DEPART HERE");
		}
	}
	
	sem_post(&s.sm);
}
