/* printmsg.c: print a message on the console 
* msg_proc.c implementation od the remote
*procedure "printmessage"
*/
#include <stdio.h>
#include <stdlib.h>
#include "msg.h"

int * printmessage_1_svc ( char **message , struct svc_req *request )
{
	static int result;	
	FILE *fileid;
	
	fileid = fopen("/dev/console", "w");
	
	if ( fileid == (FILE *)NULL ) 
	{
	result = 0;
	return (&result);
	}

	fprintf(fileid, "%s\n", *message);
	fclose(fileid);

result = 1;
return(&result);

}

