/* printmsg.c: print a message on the console 
* msg_proc.c implementation od the remote
*procedure "printmessage"
*/
#include <stdio.h>
#include <stdlib.h>
#include "msg.h"

int *
printmessage_1_svc(msg,req)
	char **msg;
	struct svc_req *req;

{
	static int result;	
	FILE *f;
	
	f = fopen("/dev/console", "w");
	if (f == (FILE *)NULL) {
	result = 0;
	return (&result);
	}

	fprintf(f, "%s\n", *msg);
	fclose(f);

result = 1;
return(&result);
}

