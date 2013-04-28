The repo contains 3 Floder 

simple_app
***********************************************************
This folder is implementation of Extended shawn tutorial 
in shawn wiki for legacyapp implementation in shawn.
this folder can be copied into legacyapp folder in shawn/src and 
by compiling by making legacyapp_simple_app_module to ON  
we get a processor name "simple_app" registered.


testq_pro
***********************************************************
This folder is implementation of Extended shawn tutorial 
in shawn wiki for legacyapp implementation in shawn.
this folder can be copied into legacyapp folder in shawn/src/  and 
by compiling the legacyapp_testq_pro_module to ON 
we get a processor name "testq_pro" registered.
this processor is modified to answer below the question in a sightly 
modified  way

"Implement a Wiselib algorithm for the following task: Periodically
exchange information with your neighbors to find out if another
(neighboring) node uses the same ID. If that it the case, shut down.
This is not fully specified, you are free to decide missing details by
yourself. For example, "shut down" is no standard operation, we leave
this to your creativity."

it shutdown all node whose node_id are less that the its own node_id

the modification can be found in the "testq_pro_processor.cpp" file


example_app
************************************************************
this folder contains the files which are modified from main wiselib folder
under apps/geniric_app/example_app. this diasable the radio concept
for the same above question.

