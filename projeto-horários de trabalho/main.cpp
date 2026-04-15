#include <iostream>
#include <chrono>
using namespace std;

struct horario{
    int hora;
    int minutos;
};

int transformaHoraMinutos(horario hora){
    return ((hora.hora * 60) + hora.minutos);
}

int main(){
    horario entrada;
    horario saidaParaIntervalo;
    horario voltaDoIntervalo;
    char eliminadorDeDoisPontos;

    cout << "Digite o horário de entrada(hh:mm):";
    cin >> entrada.hora >> eliminadorDeDoisPontos >> entrada.minutos;
    cout << "Digite o horário da primeira saída(hh:mm):";
    cin >> saidaParaIntervalo.hora >> eliminadorDeDoisPontos >> saidaParaIntervalo.minutos;
    cout << "Digite o horário da segunda entrada(hh:mm):";
    cin >> voltaDoIntervalo.hora >> eliminadorDeDoisPontos >> voltaDoIntervalo.minutos;

    int entradaMinutos = transformaHoraMinutos(entrada);
    int saidaParaIntervaloMinutos = transformaHoraMinutos(saidaParaIntervalo);
    int voltaDoIntervaloMinutos =transformaHoraMinutos(voltaDoIntervalo);

    int tempoAntes = saidaParaIntervaloMinutos - entradaMinutos;
    int falta = 360 - tempoAntes;
    int saidaFinal = voltaDoIntervaloMinutos + falta;

    cout << saidaFinal / 60 << ":" << saidaFinal % 60;

    
    
}