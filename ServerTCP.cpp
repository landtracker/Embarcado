#include "ServerTCP.h"

ServerTCP::ServerTCP()
{
    portNumber = 1234;
    socketfd = socket(AF_INET, SOCK_STREAM, 0); //obtém o socket do sistema
    ///AF_INET = socket que aceita endereços ipv4
    if (socketfd == -1) {
        printf("Nao foi possivel criar o socket\n");
        //return -1;
    }

    //Preparando a struct do socket
    servidor.sin_family = AF_INET;//AF_INET = socket que aceita endereços ipv4
    servidor.sin_addr.s_addr = INADDR_ANY; // Obtem IP do S.O.
    servidor.sin_port = htons(portNumber);//associa esse socket com a porta

    //Associando o socket a porta e endereco
    if (bind(socketfd, (struct sockaddr *) &servidor, sizeof (servidor)) < 0) {
        puts("Erro ao fazer bind Tente outra porta\n");
        //return -1;
    }
    puts("Bind efetuado com sucesso\n");

    // Ouvindo por conexoes
    listen(socketfd, 1); //marco esse socket como passivo, que só excuta conexões e aceita no máximo 1 conexao pendentes em sua fila
    acceptConections();
}
///------------------------------------------------------------------------------------------------------

ServerTCP::ServerTCP(int port)
{
    portNumber = port;
    socketfd = socket(AF_INET, SOCK_STREAM, 0); //obtém o socket do sistema
    ///AF_INET = socket que aceita endereços ipv4
    if (socketfd == -1) {
        printf("Nao foi possivel criar o socket\n");
        //return -1;
    }

    //Preparando a struct do socket
    servidor.sin_family = AF_INET;//AF_INET = socket que aceita endereços ipv4
    servidor.sin_addr.s_addr = INADDR_ANY; // Obtem IP do S.O.
    servidor.sin_port = htons(portNumber);//associa esse socket com a porta

    //Associando o socket a porta e endereco
    if (bind(socketfd, (struct sockaddr *) &servidor, sizeof (servidor)) < 0) {
        puts("Erro ao fazer bind Tente outra porta\n");
        //return -1;
    }
    puts("Bind efetuado com sucesso\n");

    // Ouvindo por conexoes
    listen(socketfd, 5); //marco esse socket como passivo, que só excuta conexões e aceita no máximo 1 conexao pendentes em sua fila
}
///------------------------------------------------------------------------------------------------------

ServerTCP::~ServerTCP()
{

}
///------------------------------------------------------------------------------------------------------

void ServerTCP::acceptConections()
{
    printf("Aguardando por conexoes...");
    int c = sizeof (struct sockaddr_in);
    int conexao;
    while ((conexao = accept(socketfd, (struct sockaddr *) &cliente, (socklen_t*) & c)))
    {
        clienteIp = inet_ntoa(cliente.sin_addr);
        clientePort = ntohs(cliente.sin_port);
//        printf("cliente conectou: %s : [ %d ]\n", clienteIp, clientePort);
        if (conexao < 0)
        {
            perror("Erro ao receber conexao\n");
            return;
        }
        puts("Handler assigned");

        int tamanho = 1;
        char resposta[256];
        while(tamanho>0)
        {
            if ((tamanho = read(conexao, resposta, 256)) < 0)
            {
                perror("Erro ao receber dados do cliente: ");

            }
            else
            {
                resposta[tamanho] = '\0';
                printf("O cliente falou: %s\n", resposta);
            }

            if (strcmp(resposta, "end") == 0) {
                close(conexao);
                printf("Servidor finalizado...\n");
                return;
            }
        }
    }
}
///------------------------------------------------------------------------------------------------------

thread ServerTCP::getServerThread()
{
  return thread([=] { acceptConections(); });
}
///------------------------------------------------------------------------------------------------------

