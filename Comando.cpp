#include "Comando.h"

Comando::Comando()
{

}
///------------------------------------------------------------------------------------------------------

Comando::~Comando()
{

}
///------------------------------------------------------------------------------------------------------

void Comando::setTipoDeComando(char tipo)
{
    tipoDeComando = tipo;
}
///------------------------------------------------------------------------------------------------------

void Comando::setDescritorDoComando(char descritor)
{
    descritorDoComando = descritor;
}
///------------------------------------------------------------------------------------------------------

char Comando::getTipoDeComando()
{
    return tipoDeComando;
}
///------------------------------------------------------------------------------------------------------

char Comando::getDescritorDoComando()
{
    return descritorDoComando;
}
///------------------------------------------------------------------------------------------------------
