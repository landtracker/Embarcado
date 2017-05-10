#ifndef COMANDO_H
#define COMANDO_H
    #include "defines.h"
    #ifndef COMANDO_Hversion1_0
        #error “versão antiga da biblioteca. Uma versão mais atual já está disponível no github”
    #endif

    #include <stdio.h>
    #include <stdlib.h>

    /**
    -------------------------------------
    0 - comando de parar o rover
    1 - mover rover para frente
    2 - mover o rover para tras
    3 - mover o rover para a esquerda
    4 - mover o rover para a direita
    */

    /**
    *Descricao: Classe que possui as características necessárias à um comando
    *Versao: 1.0
    */
    class Comando
    {
        private:
            char tipoDeComando; //número de 0 a 255 que indica o tipo desse comando
            char descritorDoComando; //descreve tempo de execução de um comando ou outra característica necessária ao comando

        public:
             /**
            *Descição: Construtor da classe
            */
            Comando();

            /**
            *Descição: Destrutor da classe
            */
            ~Comando();

            /**
            *Descição: seta o tipo desse comando
            *Argumento: tipo => (char) número de 0 a 255 que descreve o tipo desse comando de acordo com padronização da tabela acima
            *return: void
            */
            void setTipoDeComando(char tipo);

            /**
            *Descição: seta o descritor desse comand
            *Argumento: tipo => (char) pode indicar a duração do comando, o ângulo de rotaçao da câmera de acordo com o tipo de comando
            *return: void
            */
            void setDescritorDoComando(char descritor);

            /**
            *Descição: retorna um char indicando o tipo desse comando
            *return: char com o número que indica o tipo desse comando
            */
            char getTipoDeComando();

            /**
            *Descição: retorna um char com o descritor desse comando
            *return: char com o descritor desse comando
            */
            char getDescritorDoComando();
    };
#endif
