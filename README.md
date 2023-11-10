### "Term Contacts" (A Contact Management System Program)

" A contact manager that runs on terminal of your computer "

### Instructions To Run The Program:
Make sure to download the Term Contacts folder before proceeding

### Building 

Compiling: (this assumes that you have mingw as your c++ compiler):
1. First please open you terminal (cmd, powershell, etc.), 
   And make sure you are at the directory where the program folder is located, 
   i.e in the Term Contacts folder that you downloaded. 
   You can check the directory you are in using the command: pwd
2. To move to a directory you can use the command: cd [programDirectory]
3. Compile the files into object using:
``````
g++ -c src/Contact.cpp -I include -o contact.o
``````
4. Then link the object to the main file to create the executable:  
``````
g++ main.cpp contact.o -I include -o termContacts 
``````
### Execution:
5. The run the executable using: 
(or if you change the name of the excutable please use that)   

If you are using powershell:  
``````
./termContacts
``````
If you are using command prompt:
``````
termContacts
``````

If you don't have MINGW installed please refer to this link to download...
``````
https://sourceforge.net/projects/mingw/
