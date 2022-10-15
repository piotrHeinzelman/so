#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>


int main( int argc, char *argv[] ) {

   key_t key   = ftok( "." , 'c' );
   int queueId = msgget ( key, 0666|IPC_CREAT );

   if (( queueId<0) || ( argc!=3 )) { printf("\nuzycie: read [numer kanalu] [ilosc komunikatow]\n"); exit(0); }

   char chars[80]="\0";

   int inum = atoi( argv[1] );
   int msgnum=atoi( argv[2] );


   struct msgbuf{
     long mtype;
     char mtext[80];
   } message ;


   printf("\nkey:%i, queueId:%i, msgnum: %i\n", key, queueId, msgnum );

   message.mtype = inum;

   while ( inum>0 ) {
      int result = msgrcv ( (int) queueId , (struct msgbuf*) &message, 80, inum, 0 );
      if (result < 0) { exit(0); }
      printf("\nKomunikat: %s", message.mtext );
      inum--;
   }
   exit(0);
}
