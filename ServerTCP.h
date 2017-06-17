#ifndef SERVERTCP_H
#define SERVERTCP_H
    #include "defines.h"
    #ifndef SERVERTCP_Hversion1_0
        #error “versão antiga da biblioteca. Uma versão mais atual já está disponível no github”
    #endif
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <netdb.h> //sockaddr_in
    #include<thread>
    #include<iostream>
    #include <unistd.h>
    #include <sys/types.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include "ExecutorDeComandos.h"

    using namespace std;
    /*
    *Descricao: Classe que implementa um servidor TCP
    *Versao: 1.0
    */
    class ServerTCP
    {

    private:
            struct sockaddr_in servidor,//estrutura que guarda as configurações de um socket
                                cliente;
            int portNumber; //numero da porta de conexao desse servidor
            int socketfd; //retorna do método de criação de um socket
            string clienteIp; //ip do cliente
            int clientePort; //porta da aplicação no cliente

            ExecutorDeComandos* ptrExecutorDeComandos_Mov;
			ExecutorDeComandos* ptrExecutorDeComandos_AV;

    public:
        /**
        *Descição: Construtor da classe
        */
        ServerTCP();

        /**
        *Descição: sobrecarga do construtor da classe
        *Argumento: port => (int) indica a porta na qual o servidor ficará escutando
        *Argumento: port => (ExecutorDeComandos*) ponteiro com a referência do executor de comandos para poder adicionar comandos à sua lista
        */
        ServerTCP(int port, ExecutorDeComandos *exec);

        /**
        *Descição: Destrutor da classe
        */
        ~ServerTCP();

        /**
        *Descição: Método que será utilizado dentro da thread so servidor. Fica aguardando novas conexões
        */
        void acceptConections();

        /**
        *Descição: método que retorna uma thread com referência para a função acceptConections
        *return: thread=> referenciando a função acceptConections()
        */
        thread getServerThread();
    };

#endif
