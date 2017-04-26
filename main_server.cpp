#include "defines.h"
#include "ServerTCP.h"
#include"ClientTCP.h"
int main()
{
    ClientTCP client(1234, "192.168.43.50");
    client.sendMessageToServer("envio", 6);
    client.sendMessageToServer("envia", 6);
    client.sendMessageToServer("end", 4);

    //while(1){}
    /*ServerTCP server(1234);
    thread serverThread = server.getServerThread();
    printf("\n depois da thread...");
    printf("\n depois da thread...");
    printf("\n depois da thread...");
    printf("\n depois da thread...");
    printf("\n depois da thread...");
    serverThread.join();*/
}
