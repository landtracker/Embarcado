#include"ExecutorDeComandos.h"

ExecutorDeComandos::ExecutorDeComandos()
{
    while (!listaDeComandos.empty()) ///para garantir começar com a lista vazia
    {
        listaDeComandos.pop();
    }
    if(wiringPiSetup()>=0)
    {
        motorDeTracao.setup(0,2);
        servoMotorDirecao.iniciaServo(SERVO_01, 2);
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

        while(true)
        {
            ///verifica se existe algum comando na lista para ser executado

            mutexQueue.lock();

                if(!listaDeComandos.empty())
                {
                    Comando c;

                    c = listaDeComandos.front();
                    listaDeComandos.pop(); ///retira o comando executado da lista
                    mutexQueue.unlock();
                    ///manda executar o comando "c"...
                    executaComando(c);

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
        servoMotorDirecao.Direita();
        printf("Fim do comando de ir para esquerda...");

    }
    else if(c.getTipoDeComando() == 4) ///comando de ir para direita
    {
        printf("ExecutorDeComandos::executaComando: Comando de ir para direita\n");

        printf(" descritor: %d\n\n", (int)c.getDescritorDoComando());

        servoMotorDirecao.Direita();
        motorDeTracao.Frente((int)c.getDescritorDoComando());
        servoMotorDirecao.Esquerda();
        printf("Fim do comando de ir para direita...");

    }
    /**
    .
    .
    .
    */
}
///------------------------------------------------------------------------------------------------------

