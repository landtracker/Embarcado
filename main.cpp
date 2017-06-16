#include "defines.h"
#include "ServerTCP.h"
#include"ClientTCP.h"
#include "ExecutorDeComandos.h"
#include <sys/resource.h>
#include<string>

void sendInformationsToBaseStation()
{
    ClientTCP client(1234, "127.0.0.1");
    const unsigned i2c = 0x04;
    int fd = wiringPiI2CSetup(i2c);
    while(true)
    {
        int reading = wiringPiI2CRead(fd);
        char* velocity = reading;
        sleep(1);
        client.sendMessageToServer("12" , 3);///teste cliente enviando dados ao server
    }
}

int main()
{
    int processPid = getpid(); ///captura o pid do desse processo
    int which = PRIO_PROCESS;
    int priority = -20;///variável que indica a a prioridade a ser setada para esse processo
    int ret = setpriority(which, processPid, priority);///seto a nova prioridade desse processo para a máxima em sistema unix
    ///Se setpriority retorna 0, então a nova prioridade foi setada
    


    ExecutorDeComandos executorDeComandos;

    thread threadExecutorDeComandos = executorDeComandos.getExecutorDeComandosThread();
    ///inicia o server do raspberry para receber os comandos da estação base
    ServerTCP server(1234, &executorDeComandos);
    ///captura a thread do server
    thread serverThread = server.getServerThread();

    sleep(1);///dou um tempo só para garantir que o server está ativo na porta antes do cliente mandar alguma coisa
    ///inicia um cliente TCP que enviará os dados de vídeo e áudio para a estação base
    //ClientTCP client(1234, "127.0.0.1");
    
    thread enviaInformacoesEstacaoBase = sendInformationsToBaseStation();




    ///teste
    /*char comando[3]; ///teste
    comando[0] = 1; ///teste
    comando[1] = 1; ///teste
    comando[2] = 10; ///teste

    client.sendMessageToServer(comando , 3);///teste cliente enviando dados ao server

    comando[0] = 1; ///teste
    comando[1] = 0; ///teste
    comando[2] = 3; ///teste

    client.sendMessageToServer(comando , 3);///teste cliente enviando dados ao server
    //client.sendMessageToServer("end", 4);///teste cliente enviando dados ao server
    printf("\n depois da thread...");///teste
    printf("\n depois da thread...");///teste
    printf("\n depois da thread...");///teste
    printf("\n depois da thread...");///teste
    printf("\n depois da thread...");///teste*/


    threadExecutorDeComandos.join();///espero a thread do executor de comandos terminar
    serverThread.join();///fica esperando a thread do server finalizar para encerrar o software
}
