This folder contains 2 sub folders
  
  1)dps [ Under progress ]
  
  2)dps_test [Under progress ]
  
 please copy 
 
 folder name "dps" to the folder "wiselib.testing/algorithms"
 and
 folder name "dps_test" to the folder "apps/generic_apps"
 
 
 
 
 dps
 ******************************************************************
 this folder contains 3 sub folder 
  dps_client : 
      all required protocol layers for the dps_client protocol stack 
      will be defined in this folder this folder will also contain
      client stub and DPSClient class
      which uses RPC library
  
  dps_server :
      all the requires layers for the dps_server protocol stack 
      will be defined in this folder this folder will also contain
      server stub and DPSServer class
      which uses RPC library
      
  RPC :
      RPC library function and header in Wiselib compatable format.
      
      
 
 dps_test
 ******************************************************************
this folder contains 2 sub folder
  dps_client_test :
     run the Makefile to generate the client node
  
  dps_server_test :
     run the Makefile to generate the server node
