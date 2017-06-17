#include "defines.h"
#include "ServerTCP.h"
#include"ClientTCP.h"
#include "ExecutorDeComandos.h"
#include <sys/resource.h>
#include<string>

void sendInformationsToBaseStation()
{
    ClientTCP client(1234, "127.0.0.1");
    int fd = wiringPiI2CSetup(I2CADDR_ARD);;
    while(true)
    {
        int reading = wiringPiI2CRead(fd);
		char velocity = (char)reading;
        sleep(1);
        client.sendMessageToServer("1" , 2);///teste cliente enviando dados ao server
    }
}

void InterruptArduino(ExecutorDeComandos* exec) {
	exec->InterruptArduino();

}

int main()
{
    int processPid = getpid(); ///captura o pid do desse processo
    int which = PRIO_PROCESS;
    int priority = -20;///variável que indica a a prioridade a ser setada para esse processo
    int ret = setpriority(which, processPid, priority);///seto a nova prioridade desse processo para a máxima em sistema unix
    ///Se setpriority retorna 0, então a nova prioridade foi setada
	if (wiringPiISR(INTERRUPT_A, INT_EDGE_FALLING, &InterruptArduino) < 0)
	{
		fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));
	}


    ExecutorDeComandos executorDeComandos_Mov;
	ExecutorDeComandos executorDeComandos_AV;

    thread threadExecutorDeComandos_Mov = executorDeComandos_Mov.getExecutorDeComandosThread();
	thread threadExecutorDeComandos_AV = executorDeComandos_AV.getExecutorDeComandosThread();
    ///inicia o server do raspberry para receber os comandos da estação base
    ServerTCP server(1234, &executorDeComandos_Mov, &executorDeComandos_AV);
    ///captura a thread do server
    thread serverThread = server.getServerThread();

    sleep(1);///dou um tempo só para garantir que o server está ativo na porta antes do cliente mandar alguma coisa
    ///inicia um cliente TCP que enviará os dados de vídeo e áudio para a estação base
    //ClientTCP client(1234, "127.0.0.1");
    
    //thread enviaInformacoesEstacaoBase (sendInformationsToBaseStation());




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


    threadExecutorDeComandos_Mov.join();///espero a thread do executor de comandos terminar
	threadExecutorDeComandos_AV.join();
    serverThread.join();///fica esperando a thread do server finalizar para encerrar o software
}
