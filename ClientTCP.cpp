#include"ClientTCP.h"

ClientTCP::ClientTCP()
{

}
///------------------------------------------------------------------------------------------------------

ClientTCP::ClientTCP(int port, string ip)
{
    serverPortNumber = port;
    ipServer = ip;

    ///inicia o socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        ///verifica se a criação do socket deu certo
        printf("ERROR opening socket");
    }

    ///tenta pegar o servidor pelo IP
    ptrServer = gethostbyname(ipServer.c_str());

    ///Se não conseguiu encontrar o server, finaliza o software
    //TODO: mudar esse exit para uma saída parão de logs
    if (ptrServer == NULL)
    {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    ///por segurança zera todos os campos da variável que representa o servidor
    bzero((char *) &servAddr, sizeof(servAddr));
    ///indica que o tipo de endereço do server é IPV4
    servAddr.sin_family = AF_INET;
    ///copia o endereço obtido do server para a variável que representa o server
    bcopy((char *)ptrServer->h_addr, (char *)&servAddr.sin_addr.s_addr, ptrServer->h_length);
    ///atribui o número da porta de conexao do server
    servAddr.sin_port = htons(serverPortNumber);

    ///tenta efetivar a conexão com o server
    if (connect(sockfd,(struct sockaddr *) &servAddr,sizeof(servAddr)) < 0)
    {
        printf("Erro ao conectar com o servidor");
    }
    else
    {
        printf("Conexão estabelecida com o servidor");
    }

}
///------------------------------------------------------------------------------------------------------

ClientTCP::~ClientTCP()
{

}
///------------------------------------------------------------------------------------------------------

void ClientTCP::setServerPortNumber(int portN)
{
    serverPortNumber = portN;
}
///------------------------------------------------------------------------------------------------------

bool ClientTCP::sendMessageToServer(char *ptrMesage, int messageSize)
{
    int n = write(sockfd,ptrMesage,messageSize);
    if (n < 0)
    {
         printf("ClientTCP::sendMessageToServer = Erro ao escrever no socket");
         return false;
    }
    usleep(10000);///preciso dar um tempo para não saturar o server
    return true;
}
///------------------------------------------------------------------------------------------------------
