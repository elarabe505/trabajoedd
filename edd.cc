#include <iostream>
#include <malloc.h>
using namespace std;

struct clientes {
    int num_cuenta;
    int tipo_cuenta;
    int turno = 1;
    clientes *sig;
};

clientes *cabeza = NULL, *aux = NULL, *aux2 = NULL;

void registro();
void ver_fila();
void gestion_filas();
int op;


void registro() {
    cabeza = (clientes *)malloc(sizeof(clientes)); 

    cout << "Ingrese su tipo de cuenta, 1 preferencial y 2 tradicional: " << endl;
    cin >> cabeza->tipo_cuenta;

    if (cabeza->tipo_cuenta == 1) {
        cout << "Su tipo de cuenta es preferencial" << endl << endl;
    } else if (cabeza->tipo_cuenta == 2) {
        cout << "Su tipo de cuenta es tradicional" << endl << endl;
    } else {
        cout << "Tipo de cuenta no válida" << endl;
        return;
    }
    
    cout << "Ingrese su numero de cuenta:" << endl;
    cin >> cabeza->num_cuenta;
    cout << "Turno: " << endl;
    cabeza->turno++;

    cabeza->sig = NULL; 
}

void ver_fila() {
    int numero_cliente = 1; 
    for (aux = cabeza; aux != NULL; aux = aux->sig) {
        cout << "Cliente " << numero_cliente << ":" << endl;
        cout << "Tipo de cuenta: ";
        if (aux->tipo_cuenta == 1) {
            cout << "Preferencial" << endl;
        } else {
            cout << "Tradicional" << endl;
        }
        cout << "Turno: " << aux->turno << endl;
        cout << "Número de cuenta: " << aux->num_cuenta << endl;
        cout << endl;
        numero_cliente++;
    }
}

void gestion_filas() {
    int num_clientes_tradicional = 0;
    int num_clientes_preferencial = 0;

    for (aux = cabeza; aux != NULL; aux = aux->sig) {
        if (aux->tipo_cuenta == 1) {
            num_clientes_preferencial++;
        } else {
            num_clientes_tradicional++;
        }
    }

    if (num_clientes_tradicional >= 5 && num_clientes_preferencial <= 2) {
        int contador = 0;
        for (aux = cabeza; aux != NULL; aux = aux->sig) {
            if (aux->tipo_cuenta == 2) {
                contador++;
                if (contador == 3) {
                    aux->tipo_cuenta = 1;
                }
            }
        }
    }
}

int main() {
    int op = 0;

    do {
        cout << "MENU PRINCIPAL" << endl;
        cout << "1. Registro de cliente: " << endl;
        cout << "2. Ver registro: " << endl;
        cout << "3. Gestionar filas: " << endl;
        cout << "4. Salir" << endl;
        cin >> op;
        switch (op) {
            case 1:
                registro();
                break;

            case 2:
                ver_fila();
                break;
            
            case 3:
                gestion_filas();
                break;
            case 4:
                cout << "Chao vro";
                break;
            default:
                cout << "Opcion no valida vro" << endl;
                break;
        }
    } while (op != 4);

    return 0;
}