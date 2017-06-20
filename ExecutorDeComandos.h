#ifndef EXECUTORDECOMANDOS_H
#define EXECUTORDECOMANDOS_H
    #include "defines.h"
    #ifndef EXECUTORDECOMANDOS_Hversion1_0
        #error “versão antiga da biblioteca. Uma versão mais atual já está disponível no github”
    #endif

    #include <stdio.h>
    #include <stdlib.h>
    #include<iostream>
    #include<queue>
    #include <thread>         // std::thread
    #include <mutex>          // std::mutex
    #include <unistd.h>
    #include"Comando.h"
    #include <wiringPi.h>
    #include <wiringPiI2C.h>
    #include "Ultrassom.h"
    #include "Servo.h"
    #include "MotorDC.h"
	#include "AI.h"
    #include"Constantes_&_Pinos.h"
    using namespace std;

    /**
    *Descricao: Classe que analisa e executa os comandos recebidos pelo server
    *Versao: 1.0
    */

	extern float travelledDistance;
    class ExecutorDeComandos
    {
        private:
            queue<Comando> listaDeComandos; ///lista de comandos a serem executados
            std::mutex mutexQueue;///mutex para impedir acesso simultâneo à lista, o que pode gerar inconsistência nos dados
            MotorDC motorDeTracao; ///controlador do motor DC de tração
            Servo servoMotorDirecao;///controlador do servomotor da direcao
			Servo servoCamera;
			Servo servoDireita;
			Servo servoEsquerda;
			bool executando;
			AI brain;
			unsigned fd;			
        public:
            /**
            *Descição: Construtor da classe
            */
            ExecutorDeComandos();

            /**
            *Descição: Destrutor da classe
            */
            ~ExecutorDeComandos();

			void InterruptArduino();


            /**
            *Descição: insere um novo comando na lista
            *Argumento: tipo => (Comando) novo comando a ser inserido na lista
            *return: void
            */
            void insereComandoNaLista(Comando comando);

            /**
            *Descrição: função executada em uma thread que verifica se há comandos a serem executados na lista e executam
            *return: void
            */
            void executarComandos();

            /**
            *Descrição: cria uma thread que executa a função executarComandos()
            *return: referência para uma thread que executa a função executarComandos()
            */
            thread getExecutorDeComandosThread();

        private:

            /**
            *Descrição: função que efetivamente mandará os comandos para os atuadores conectados ao raspberry
            *Argumento: c => (Comando) comando que será avaliado e executado por esse método
            *return: void
            */
            void executaComando(Comando c);
    };

#endif
