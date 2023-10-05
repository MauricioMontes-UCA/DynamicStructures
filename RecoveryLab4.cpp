#include <iostream>

using namespace std;

struct Competidor
{
    string nombre;
    int posicion;
    int monedas;
    string objeto;
};

struct Nodo
{
    Competidor participante;
    Nodo *next;
};

Nodo *lista = nullptr;

void AgregarCompetidor();
void ImprimirCompetidores();
void UtilizarObjetos(int);
void ControlMonedas(int, int);
void ActualizarPosicion(int, int);
int ContarParticipantes();

int main()
{
    int opcion;
    int posicion;
    int posicionNueva;
    int monedas;

    while (true)
    {
        cout << "MENU PRINCIPAL" << endl;
        cout << "[1] Agregar competidor" << endl;
        cout << "[2] Ver informacion competidores" << endl;
        cout << "[3] Utilizar objetos" << endl;
        cout << "[4] Actualizar monedas" << endl;
        cout << "[5] Actualizar posicion competidor" << endl;
        cout << "[6] Cerrar programa" << endl;

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            AgregarCompetidor();
            break;

        case 2:
            ImprimirCompetidores();
            break;

        case 3:
            cout << "Ingrese la posicion del competidor: ";
            cin >> posicion;
            UtilizarObjetos(posicion);
            break;

        case 4:
            cout << "Ingrese la posicion del competidor:  \n";
            cin >> posicion;

            cout << "Ingrese si el competidor ha ganado o perdido monedas \n"
                 << "[1] Ganado \n"
                 << "[2] Perdido \n";
            cin >> opcion;

            if (opcion == 1)
            {
                cout << "Cuantas ha ganado? \n";
                cin >> monedas;
                ControlMonedas(posicion, monedas);
            }
            else
            {
                cout << "Cuantas ha perdido? \n";
                cin >> monedas;
                ControlMonedas(posicion, -monedas);
            }

            cout << "Contador de monedas actualizado." << endl;
            break;

        case 5:
            cout << "Posicion original del competidor: ";
            cin >> posicion;
            cout << "Posicion actual del competidor: ";
            cin >> posicionNueva;

            ActualizarPosicion(posicion, posicionNueva);
            break;

        case 6:
            return 0;

        default:
            break;
        }
    }
}

void AgregarCompetidor()
{
    Nodo *nuevoCompetidor = new Nodo;
    Nodo *temp = lista;

    // Información da cada uno de los participantes/competidores:
    cout << "Ingrese los atributos del competidor:" << endl;
    cout << "Nombre: ";
    cin >> nuevoCompetidor->participante.nombre;
    cout << "Monedas: ";
    cin >> nuevoCompetidor->participante.monedas;
    cout << "Objeto: ";
    cin >> nuevoCompetidor->participante.objeto;

    nuevoCompetidor->participante.posicion = ContarParticipantes() + 1;

    // Ubicación de posición de cada nuevo participante al final de la lista
    nuevoCompetidor->next = nullptr;

    if (lista == nullptr)
    { // Si la lista está vacía...
        lista = nuevoCompetidor;
    }
    else
    { // Si la lista no está vacía...
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = nuevoCompetidor;
    }
}

void ActualizarPosicion(int viejaPosicion, int nuevaPosicion) //Funciona para adelantar posiciones, pero no para retroceder
{
    int competidores = ContarParticipantes();
    int posicion = 1;

    Nodo *participante = lista;
    Nodo *temp = lista;
    Nodo *aux;

    if (nuevaPosicion > 0 || nuevaPosicion <= competidores)
    {
        while (viejaPosicion != 1)
        {
            viejaPosicion--;
            aux = participante;
            participante = participante->next;
        }
        aux->next = participante->next;

        if ((nuevaPosicion =! 1)){
            nuevaPosicion--;
            while (nuevaPosicion > 1)
            {
                temp = temp->next;
                nuevaPosicion--;
            }
            participante->next = temp->next;
            temp->next = participante;
        }
        else{
            participante->next = lista;
            lista = participante;
        }
        
        temp = lista;
        while (temp->next != nullptr)
        {
            temp->participante.posicion = posicion;
            posicion++;
            temp = temp->next;
        }
        temp->participante.posicion = posicion;
    }
}

void ImprimirCompetidores()
{
    Nodo *temp = lista;

    if (lista != nullptr)
    {
        while (temp != nullptr)
        {
            cout << "Posicion: " << temp->participante.posicion << endl;
            cout << "Nombre: " << temp->participante.nombre << endl;
            cout << "Monedas: " << temp->participante.monedas << endl;
            cout << "Objeto: " << temp->participante.objeto << endl;
            cout << endl;

            temp = temp->next;
        }
    }
    else
    {
        cout << "No hay ningún competidor agregado." << endl;
    }
}

void UtilizarObjetos(int posicion)
{
    Nodo *temp = lista;

    while (posicion != 1)
    {
        temp = temp->next;
        posicion--;
    }
    if (temp->participante.objeto == "ninguno")
    {
        cout << "El competidor no posee objetos." << endl;
    }
    else
    {
        temp->participante.objeto = "ninguno";
        cout << "Se ha utilizado un objeto." << endl;
    }
}

void ControlMonedas(int posicion, int monedas)
{
    Nodo *temp = lista;

    while (posicion != 1)
    {
        temp = temp->next;
        posicion--;
    }
    temp->participante.monedas += monedas;
}

int ContarParticipantes()
{
    int contadorPosicion = 1;

    if (lista == nullptr)
    {
        return 0;
    }
    else
    {
        Nodo *temp = lista;

        while (temp->next != nullptr)
        {
            temp = temp->next;
            contadorPosicion++;
        }

        return contadorPosicion;
    }
}