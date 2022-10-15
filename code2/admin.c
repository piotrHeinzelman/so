#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>


int main( int argc, char *argv[] ) {


   key_t key = ftok( "." , 'c' );
   int queueId;

   if (( argc==2 )&&( strcmp( argv[1], "-c" )==0 )) {
      // create
      queueId = msgget( key, 0666|IPC_CREAT  );

      printf( "%i" , key );
      printf( "%i" , queueId );
      exit(0);
      // +++
   }

   if (( argc==2 )&&( strcmp( argv[1], "-d" )==0)) {
     // delete
      printf( "\nRemove queue %i\n", queueId );
      queueId = msgget( key, 0 );

      msgctl( queueId, IPC_RMID, NULL  );
      exit(1);
     // ---
   }

   printf("\n%s","uzycie:\n-c utworzenie kolejki\n-d usuniecie kolejki\n");
   exit(1);
}
