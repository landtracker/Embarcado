#include"ExecutorDeComandos.h"



static void ExecutorDeComandos::InterruptArduino()
{
	executando = false;
	motorDeTracao.Stop();
}

ExecutorDeComandos::ExecutorDeComandos()
{
    while (!listaDeComandos.empty()) ///para garantir começar com a lista vazia
    {
        listaDeComandos.pop();
    }
    if(wiringPiSetup()>=0)
    {
		pinMode(SIGPIN_ARD, OUTPUT);
		digitalWrite(SIGPIN_ARD, HIGH);
        motorDeTracao.setup(MOTOR_VEL,MOTOR_DIR);
        servoMotorDirecao.iniciaServo(SERVO_01);
		servoCamera.iniciaServoArduino(1);
		servoDireita.iniciaServoArduino(2);
		servoEsquerda.iniciaServoArduino(3);

    }
	executando = false;

	if (wiringPiISR(INTERRUPT_A, INT_EDGE_FALLING, &InterruptArduino) < 0)
	{
		cout << "Unable to setup ISR: \n" << endl;
	}

}
///------------------------------------------------------------------------------------------------------

ExecutorDeComandos::~ExecutorDeComandos()
{

}
///------------------------------------------------------------------------------------------------------

void ExecutorDeComandos::insereComandoNaLista(Comando comando)
{
    mutexQueue.lock();
        listaDeComandos.push(comando);
    mutexQueue.unlock();
}
///------------------------------------------------------------------------------------------------------

void ExecutorDeComandos::executarComandos()
{

	while (true)
	{
		///verifica se existe algum comando na lista para ser executado

		mutexQueue.lock();

		if (!listaDeComandos.empty())
		{
			Comando c;

			c = listaDeComandos.front();
			listaDeComandos.pop(); ///retira o comando executado da lista
			mutexQueue.unlock();
			///manda executar o comando "c"...
			executaComando(c);
			executando = true;
			while (executando)
			{
				digitalWrite(SIGPIN_ARD, LOW);
				if (brain.VerificaObstaculo())
				{
					motorDeTracao.Stop();
					digitalWrite(SIGPIN_ARD, HIGH);
					brain.DesvioObstaculo();
					executando = false;

				}
			}

		}
		//printf("buscando Comandos Para executor...");
		mutexQueue.unlock();
	}

}
///------------------------------------------------------------------------------------------------------

thread ExecutorDeComandos::getExecutorDeComandosThread()
{
    return thread([=] { executarComandos(); });
}
///------------------------------------------------------------------------------------------------------




void ExecutorDeComandos::executaComando(Comando c)
{
    if(c.getTipoDeComando() == 0) ///comando de parar
    {
        printf("ExecutorDeComandos::executaComando: Comando para parar o rover\n\n");
        sleep((int)c.getDescritorDoComando());///dou um delay nessa thread
    }
    else if(c.getTipoDeComando() == 1) ///comando de ir para frente
    {

        printf("ExecutorDeComandos::executaComando: Comando de ir para frente\n");
        ///setar os pinos e medir o tempo

        printf(" descritor: %d\n\n", (int)c.getDescritorDoComando());
       // sleep((int)c.getDescritorDoComando());///dou um delay nessa thread

        motorDeTracao.Frente((int)c.getDescritorDoComando());
        ///caso o sleep trave o processador do raspberry pi, usar o código comentado abaixo
        /*time_t tempoInicial;
        time_t tempoAgora;
        tempoInicial = time(NULL); ///pega os segundos desde 1970
        tempoAgora = time(NULL); ///pega os segundos desde 1970
        std::cout<<tempoInicial<<endl;

        ///timer que fará a thread não executar o proximo comando até esse ser finalizado
        while((int)(tempoAgora - tempoInicial) <= (int)c.getDescritorDoComando())
        {
            tempoAgora = time(NULL); ///pega os segundos desde 1970
        }
        std::cout<<tempoAgora<<endl;*/


        ///reseta os pinos depois do delay para parar de mover o rover
        printf("Fim do comando de ir para frente...");
    }
    else if(c.getTipoDeComando() == 2) ///comando de ir para tras
    {
        printf("ExecutorDeComandos::executaComando: Comando de ir para tras\n");

        printf(" descritor: %d\n\n", (int)c.getDescritorDoComando());

        motorDeTracao.Tras((int)c.getDescritorDoComando());
        printf("Fim do comando de ir para tras...");

    }
    else if(c.getTipoDeComando() == 3) ///comando de ir para esquerda
    {
        printf("ExecutorDeComandos::executaComando: Comando de ir para esquerda\n");

        printf(" descritor: %d\n\n", (int)c.getDescritorDoComando());

        servoMotorDirecao.Esquerda();
        motorDeTracao.Frente((int)c.getDescritorDoComando());
        servoMotorDirecao.Alinhar();
        printf("Fim do comando de ir para esquerda...");

    }
    else if(c.getTipoDeComando() == 4) ///comando de ir para direita
    {
        printf("ExecutorDeComandos::executaComando: Comando de ir para direita\n");

        printf(" descritor: %d\n\n", (int)c.getDescritorDoComando());

        servoMotorDirecao.Direita();
        motorDeTracao.Frente((int)c.getDescritorDoComando());
        servoMotorDirecao.Alinhar();
        printf("Fim do comando de ir para direita...");

    }
    else if(c.getTipoDeComando() == 5) ///comando para ativar streamming de vídeo
    {
        printf("ExecutorDeComandos::executaComando: Comando para ativar streamming de video\n");

        system("raspivid -vf -n -w 640 -h 480 -o - -t 0 -b 200000 | nc 192.168.43.50 2234 &");
    }
    else if(c.getTipoDeComando() == 6) ///comando para desativar streamming de vídeo
    {
        printf("ExecutorDeComandos::executaComando: Comando para desativar streamming de video\n");

        system("killall activeVideoStream.sh &");
    }
    else if(c.getTipoDeComando() == 7) ///comando para ativar streamming de audio
    {
        printf("ExecutorDeComandos::executaComando: Comando para ativar streamming de audio\n");

       // system("arecord -v -f S16_LE -c 1 -r 192000 -d 0 -Dplug:default | nc 192.168.43.50 7777  2>&1 &");
    	system("arecord -f S16_LE -c 1 -r 192000 -d 0 -Dplug:default | nc 192.168.43.50 7777  2>&1 &");
    }
    else if(c.getTipoDeComando() == 8) ///comando para desativar streamming de audio
    {
        printf("ExecutorDeComandos::executaComando: Comando para desativar streamming de audio\n");

        system("killall activeAudioStream.sh &");
    }
    else if(c.getTipoDeComando() == 9) ///comando para mover a câmera para a esquerda
    {
        printf("ExecutorDeComandos::executaComando: Comando para mover a câmera para a esquerda\n");
        printf(" descritor: %d\n\n", (int)c.getDescritorDoComando());
        unsigned anguloAtual = servoCamera.getAngulo();
        servoCamera.setAngulo(anguloAtual + (unsigned)c.getDescritorDoComando());
    }
    else if(c.getTipoDeComando() == 10) ///comando para mover a câmera para a direita
    {
        printf("ExecutorDeComandos::executaComando: Comando para mover a câmera para a direita\n");
        printf(" descritor: %d\n\n", (int)c.getDescritorDoComando());
        unsigned anguloAtual = servoCamera.getAngulo();
        servoCamera.setAngulo(anguloAtual - (unsigned)c.getDescritorDoComando());
    }
    /**
    .
    .
    .
    */
}
///------------------------------------------------------------------------------------------------------

