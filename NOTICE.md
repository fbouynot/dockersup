# Dockersup :  usage and program description  

## Set server IP  

Start the program. Select option (1).

You'll be prompted to enter an IP. Said IP will be written to the ip.conf file, located at the root of your current folder.


## List containers   

Start the program. Select option (2).

The program will try to connect to the docker server via a TCP connection  using the IP written in ip.conf file.  

It will then request container list from the API's local unix socket.  

The result will be transfered back to the client via the TCP connection.  

