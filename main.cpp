#include "defines.h"
#include "ServerTCP.h"
#include"ClientTCP.h"
#include "ExecutorDeComandos.h"
#include <sys/resource.h>
#include<string>


ExecutorDeComandos executorDeComandos_Mov;
ExecutorDeComandos executorDeComandos_AV;

//extern int travelledDistance = 0;
int stateE;
int stateD;
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


void InterruptEncoder1()
{
   usleep(100);
	if(digitalRead(INTERRUPT_ENCODER1) == stateE)
		return;
    TD_E+=(PI/2.0);
    cout << "Distance E: "<< TD_E << endl;
	stateE = digitalRead(INTERRUPT_ENCODER1);
  usleep(100);
}

void InterruptEncoder2()
{
	usleep(100);
	if(digitalRead(INTERRUPT_ENCODER2) == stateD)
		return;
    TD_D+=(PI/2.0);
    cout << "Distance D: "<< TD_D << endl;
	stateD = digitalRead(INTERRUPT_ENCODER2);
	usleep(100);
}

int main()
{
    int processPid = getpid(); ///captura o pid do desse processo
    int which = PRIO_PROCESS;
    int priority = -20;///variável que indica a a prioridade a ser setada para esse processo
    int ret = setpriority(which, processPid, priority);///seto a nova prioridade desse processo para a máxima em sistema unix
    
    
    ///Se setpriority retorna 0, então a nova prioridade foi setada
	/*if (wiringPiISR(INTERRUPT_A, INT_EDGE_RISING, &InterruptArduino) < 0)
	{
		fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));
	}*/

	if (wiringPiISR(INTERRUPT_ENCODER1, INT_EDGE_FALLING, &InterruptEncoder1) < 0)
	{
		cout<<"impossivel iniciar pino de interrupcao\n";
		fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));
	}
	
	if (wiringPiISR(INTERRUPT_ENCODER2, INT_EDGE_FALLING, &InterruptEncoder2) < 0)
	{
		cout<<"impossivel iniciar pino de interrupcao\n";
		fprintf(stderr, "Unable to setup ISR: %s\n", strerror(errno));
	}

	stateD = digitalRead(INTERRUPT_ENCODER2);
	stateE = digitalRead(INTERRUPT_ENCODER1);
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
