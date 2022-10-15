#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>


int main( int argc, char *argv[] ) {

   key_t key   = ftok( "." , 'c' );
   int queueId = msgget ( key, 0666|IPC_CREAT );

   if ( queueId<0) { printf("\nwywolanie: send [numer kanalu]\n"); exit(1); }
   if ( argc!=2 )  { printf("\nwywolanie: send [numer kanalu]\n"); exit(1); }

   char chars[80]="\0";

   int inum = atoi( argv[1] );

   struct msgbuf{
     long mtype;
     char mtext[80];
   } message ;


   printf("\nkey:%i, queueId:%i, inum:%i\n", key, queueId, inum );

   printf("podaj konunikat:\n" );
   fgets( message.mtext , 80, stdin );
   message.mtype = inum;

   int result = msgsnd ( (int) queueId , &message, 80, 0 );
   exit(0);
}
