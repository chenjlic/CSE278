
/*
Demo B:
*/

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
 #include<string.h>
using namespace std;

#define MAX_BUF 1024 //Maximum length of the buffer to get the data from the pipe


int main()
{
    // Every code you run is one process. Let's see the process ID
    cout << "current process " << getpid() << endl;
    // We want to creat two process
    /// parent process: collect the user input from current terminal and send via the pipe
    // child process: check the pipe to read the data sent from the other terminal. Display the data in the current terminal
    // pid<0 : create failed
    // pid>0: child process ID, the parent process will have this value
    // Pid=0 the child process has this value
    pid_t pid = fork(); 

    // check if succeeded
    if(pid < 0){
        perror("fork error");
        exit(-1);
    }else if (pid == 0)
    { //child process: collect the recived data from the named pipe and display in the terminal
        char * myfifo = "/tmp/AtoB";  // name the pipe, that is why we call it named pipe, you can access this as long as you have the name
        int fd=-1;  // file descriptor (fd)
        char buf[MAX_BUF];// buffer for collect the input
        /* open, read, and display the message from the FIFO */
        fd = open(myfifo, O_RDONLY);// Open the pipe, with the name:myfifo, mode:O_RDONLY(just read the data) and return file descriptor (fd) return -1 if failed
        while (fd == -1)//(1)// explain (c)// we need to wait the other to create the FIFO, a.k.a., the named pipe. It may have not been created yet if you run this code first.
        {fd = open(myfifo, O_RDONLY);}
        cout<<"fd is: "<<fd<<endl;
        int count=0;
        bool Receiving=true;
        ssize_t lineSize = 0;
        while(Receiving) // let's keep running it. If you want to quit, use ctr+c to terminate this
        {
            count++;
            // read the pipe data.
            // fd indicates the file (pipe, every device is viewed as file in Linux) you need to read
            // buf is the place you store the data you received. "read" will copy what the system get to "buf"
            // MAX_BUF maximum buffer length
            // return the length of the data recieved. return -1 if nothing received.
            lineSize=read(fd, buf, MAX_BUF);
            if(lineSize>0) // explain (b)
            {
                //display what you received
                cout<<"Received: "<<buf<<endl;
            }
            //memset function will set the target buffer (with certain length) with certain values
            // buf: the buffer we want to modify
            // '\0': the value we want to set
            // MAX_BUF: how many elements in the buffer we should modify
            memset(buf,'\0',MAX_BUF); // explain (a)
            
        }
        close(fd);
    }
    else
    {//parent process: collect the user input from the terminal and send via the pipe
        ssize_t nread;
        int fds;
        char * myfifos = "/tmp/BtoA"; //(2)// name the pipe, should be different

        /* create the FIFO (named pipe) */
        mkfifo(myfifos, 0666);

        /* write "Hi" to the FIFO */
        fds = open(myfifos, O_WRONLY);
        
        bool IsSending=true;
        char *line = NULL;
        size_t len = 0;
        ssize_t lineSize = 0;
        while(IsSending)// let's keep running it. If you want to quit, use ctr+c to terminate this
        {
            
            cout<<"Please enter a line:\n";
            // get the input from the terminal. get the entire line. "line" stores the data and will return the length of the input
            lineSize = getline(&line, &len, stdin); 
            // Send what you get to the named pipe, using the file descriptor.
            // fd indicates the file (pipe, every device is viewed as file in Linux) you want to send your data to
            // line is the data buffer, stores the user input
            // lineSize is the length of the data buffer.
            write(fds, line, lineSize);
            
        }
        // close the file
         close(fds);

        /* remove the FIFO */
        unlink(myfifos);

    }
}
