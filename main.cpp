#include "defines.h"
#include "ServerTCP.h"
#include"ClientTCP.h"
#include "ExecutorDeComandos.h"
#include <sys/resource.h>
#include<string>


ExecutorDeComandos executorDeComandos_Mov;
ExecutorDeComandos executorDeComandos_AV;

int contEncoder1 = 0;
int contEncoder2 = 0;
//extern int travelledDistance = 0;

void sendInformationsToBaseStation()
{
   
/* ClientTCP client(2222, "192.168.25.9");
    int fd = wiringPiI2CSetup(I2CADDR_ARD);;
    while(true)
    {
        int reading = wiringPiI2CRead(fd);
		char velocity = (char)reading;
        sleep(1);
        client.sendMessageToServer("1234" , 5);///teste cliente enviando dados ao server
    }*/
}

void InterruptArduino() {
	executorDeComandos_Mov.InterruptArduino();
}

void InterruptEncoder1()
{
  contEncoder1++;
  cout<<"Distance: "<<travelledDistance<<endl;
  travelledDistance += PI/2;
  delay(50);
}

void InterruptEncoder2()
{
  contEncoder2++;
  //cout<<"E2: "<<contEncoder2<<endl;
  delay(50);
}

int main()
{
    int processPid = getpid(); ///captura o pid do desse processo
    int which = PRIO_PROCESS;
    int priority = -20;///variável que indica a a prioridade a ser setada para esse processo
    int ret = setpriority(which, processPid, priority);///seto a nova prioridade desse processo para a máxima em sistema unix
    
    contEncoder1 = 0;
    contEncoder2 = 0;
    
    ///Se setpriority retorna 0, então a nova prioridade foi setada
	/*if (wiringPiISR(INTERRUPT_A, INT_EDGE_RISING, &InterruptArduino) < 0)
	{
		fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));
	}*/

	if (wiringPiISR(INTERRUPT_ENCODER1, INT_EDGE_RISING, &InterruptEncoder1) < 0)
	{
		fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));
	}
	
	if (wiringPiISR(INTERRUPT_ENCODER2, INT_EDGE_RISING, &InterruptEncoder2) < 0)
	{
		fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));
	}



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
