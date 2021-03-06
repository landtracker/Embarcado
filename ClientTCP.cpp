#include"ClientTCP.h"

ClientTCP::ClientTCP()
{
	connected = false;
}
///------------------------------------------------------------------------------------------------------

ClientTCP::ClientTCP(int port, string ip)
{
    connected = false;
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
    while (connect(sockfd,(struct sockaddr *) &servAddr,sizeof(servAddr)) < 0)
    {
       // printf("Erro ao conectar com o servidor");
    }
    //else
    {
        printf("Conexão estabelecida com o servidor");
	connected = true;
    }

}
///------------------------------------------------------------------------------------------------------

ClientTCP::~ClientTCP()
{
	connected = false;
}
///------------------------------------------------------------------------------------------------------

void ClientTCP::setServerPortNumber(int portN)
{
    serverPortNumber = portN;
}
///------------------------------------------------------------------------------------------------------

bool ClientTCP::sendMessageToServer(char *ptrMesage, int messageSize)
{
//    int err = 0;
  //  socklen_t size = sizeof (err);
   // int check = getsockopt (sockfd, SOL_SOCKET, SO_ERROR, &err, &size);
   
    //if(check == 0)
    //{
	//return 
//	connected = false;
//	return true;
 //   }




//    char buf;
//    int err = recv(sockfd, &buf, 1, MSG_PEEK);
//    if(err == 0)
  //  {
       //  if(WSAGetLastError() != WSAEWOULDBLOCK)
        // {
//	      return connected = false;
	 //}
  //  }
    // return true;


    int n = write(sockfd,ptrMesage,messageSize);
    if (n < 0)
    {
         printf("ClientTCP::sendMessageToServer = Erro ao escrever no socket");
         
         return connected = false;
    }
    usleep(10000);///preciso dar um tempo para não saturar o server
    return true;
}
///------------------------------------------------------------------------------------------------------
bool ClientTCP::getConnected()
{
	return connected;
}
