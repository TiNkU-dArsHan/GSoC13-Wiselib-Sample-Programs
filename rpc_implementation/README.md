rpc_imple
**********************************************************************

this folder contains files rprintmsg.c , msg_proc.c ,msg.x
and file which are genetrated from rpcgen run for msg.x 
which are rpc compiler which msg_clnt.c , msg_proc.c and msg_svc.c


rprintmsg.c
****************************************************************
this file contains client program which should be running 
on local machine.


msg_proc.c
*****************************************************************
this file contains server procedure which should be running 
on remote mechine.



******************************************************* 
running makefile will generate 2 binary executable rprintmsg (client)
and msg_server (server).
