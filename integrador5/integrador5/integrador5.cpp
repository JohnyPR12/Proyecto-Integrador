// integrador5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
//lista de estudiantes y acistencia
void lista()
{
    //Esteban
    int Cant;
    cout << "Ingrese la cantidad de nombres: ";
    cin >> Cant;
    vector<string> Nom(Cant);
    cout << "Ingrese los nombres:\n";
    for (int i = 0; i < Cant; ++i) {
        cout << "Nombre " << i + 1 << ": ";
        cin >> Nom[i];
    }
    vector<string> Pre;
    vector<string> Aus;
    cout << "Coloque quien estuvo presente y quien estuvo ausente:\n";
    for (int i = 0; i < Cant; ++i) {
        string Nombre;
        char Asi;

        cout << Nom[i] << " (P/A): ";
        cin >> Asi;

        if (Asi == 'P' || Asi == 'p') {
            Pre.push_back(Nom[i]);
        }
        else if (Asi == 'A' || Asi == 'a') {
            Aus.push_back(Nom[i]);
        }
        else {
            cout << "Entrada invalida. Por favor ingrese 'P' para presente o 'A' para ausente\n";
            --i;
        }
    }
    cout << "Estuvieron presentes:\n";
    for (const string& Nombre : Pre) {
        cout << Nombre << endl;
    }
    cout << "Estuvieron ausentes:\n";
    for (const string& Nombre : Aus) {
        cout << Nombre << endl;
    }


}
//se encarga de calcular un promedio basado en los examenes tomados
void calculadoraP()
{
    //Oyola

    //valor de los exam
    int val1, val2, val3, val4, total;

    //le pregunta al usuaria la nota de los examenes
    cout << "Entre la puntuacion del primer examen.\n";
    cin >> val1;
    cout << "Entre la puntuacion del segundo examen.\n";
    cin >> val2;
    cout << "Entre la puntuacion del tercer examen. \n";
    cin >> val3;
    cout << "Entre la puntuacion del cuarto examen. \n";
    cin >> val4;

    //calcula la nota sumada de los examenes
    total = val1 + val2 + val3 + val4;
    total = total / 4;

    //verifica la nota para clasificarla y entregarla
    if (total >= 90)
    {
        cout << "Su nota final es A " << total << "%";
    }
    else if (total <= 89 && total >= 80)
    {
        cout << "Su nota final es B " << total << "%";
    }
    else if (total <= 79 && total >= 70)
    {
        cout << "Su nota final es C " << total << "%";
    }
    else if (total <= 69 && total >= 60)
    {
        cout << "Su nota final es D " << total << "%";
    }
    else
    {
        cout << "Su nota final es F " << total << "%";
    }

}
//inicio de sesion
void inicio()
{
    //Oyola
    /*Para inicias sesion
    Nombre del usuario: Profesor
    codigo de cuenta: Inter*/
inicio:
    system("cls");
    string input1, input2;
    cout << "Para iniciar sesion entre nombre de usuario y codigo \n";
    cout << "\n";
    cout << "Nombre de usuario: ";
    cin >> input1;
    cout << "codigo de cuenta: ";
    cin >> input2;
    if (input1 == "Profesor" & input2 == "Inter") {}
    else
    {
        cout << "Error \n";
        system("pause");
        goto inicio;
    }
}
//lista que mantiene registro de quienes participaron en la clase
void listaParticipacion()
{
    //Esteban 
    const int MAX = 10;
    string participantes[MAX];
    bool participacion[MAX] = { false };

    int numP;
    cout << "Ingrese el numero de participantes (maximo " << MAX << "): ";
    cin >> numP;

    if (numP > MAX || numP < 1) {
        cout << "Número de participantes inválido." << endl;
        
    }

    cout << "Ingrese los nombres de los participantes:" << endl;
    for (int i = 0; i < numP; ++i) {
        cout << "Participante " << i + 1 << ": ";
        cin >> participantes[i];
    }

    string pName;
    cout << "Ingrese el nombre del participante que participo ('fin' para terminar): ";
    cin >> pName;

    while (pName != "fin") {
        bool found = false;
        for (int i = 0; i < numP; ++i) {
            if (participantes[i] == pName) {
                participacion[i] = true;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "¡Participante no encontrado!" << endl;
        }

        cout << "Ingrese el nombre del siguiente participante ('fin' para terminar): ";
        cin >> pName;
    }

    cout << "\nRegistro de participacion:" << endl;
    for (int i = 0; i < numP; ++i) {
        cout << participantes[i];
        if (participacion[i]) {
            cout << " - Participo" << endl;
        }
        else {
            cout << " - No participo" << endl;
        }
    }
}

int main()
{
    //Oyola
    string user, user1;
    //recibir usuario
    inicio();
menu:
    system("cls");
    cout << "Asistente de Profesores\n";
    cout << "\n";
    cout << "       Menu \n";
    cout << "\n";
    cout << "Opciones: 1. registro de estudiantes y asistencia \n";
    cout << "          2. calculadora de promedio basado en examenes \n";
    cout << "          3. Registro de participacion \n";
    cout << "\n";
    cout << "Entre el numero de la opcion seleccionada: ";
    //lee la respuesta entrada y regresa lo solicitado
    cin >> user;

    if (user == "1")
    {
    lista:
        system("cls");
        lista();
        cout << "Para regresar al menu entre (b) para repetir el proseso entre (r): ";
        cin >> user1;
        if (user1 == "b" || user1 == "B")
        {
            goto menu;
        }
        else if (user1 == "r" || user1 == "R")
        {
            goto lista;
        }
    }
    else if (user == "2")
    {
    calcu:
        system("cls");
        calculadoraP();
        cout << "Para regresar al menu entre (b) para repetir el proseso entre (r): ";
        cin >> user1;
        if (user1 == "b" || user1 == "B")
        {
            goto menu;
        }
        else if (user1 == "r" || user1 == "R")
        {
            goto calcu;
        }
    }
    else if (user == "3")
    {
        listaParticipacion();
        if (user1 == "b" || user1 == "B")
        {
            goto menu;
        }
        else if (user1 == "r" || user1 == "R")
        {
            goto calcu;
        }

    }


    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
