#include <iostream>
#include <map>
using namespace std;

struct Usuario {
    string contrasena;
    double saldo;
};

map<string, Usuario> usuarios;

bool iniciarSesion(string usuario, string contrasena) {
    if (usuarios.find(usuario) != usuarios.end() && usuarios[usuario].contrasena == contrasena) {
        return true;
    }
    return false;
}

void registrarUsuario(string usuario, string contrasena) {
    usuarios[usuario] = {contrasena, 0.0};
}

void consignar(string usuario, double monto) {
    usuarios[usuario].saldo += monto;
}

void retirar(string usuario, double monto) {
    if (usuarios[usuario].saldo >= monto) {
        usuarios[usuario].saldo -= monto;
    } else {
        cout << "Saldo insuficiente" << endl;
    }
}

void pagarServicios(string usuario, double monto) {
    if (usuarios[usuario].saldo >= monto) {
        usuarios[usuario].saldo -= monto;
    } else {
        cout << "Saldo insuficiente" << endl;
    }
}

double consultarSaldo(string usuario) {
    return usuarios[usuario].saldo;
}

void cambiarContrasena(string usuario, string nuevaContrasena) {
    usuarios[usuario].contrasena = nuevaContrasena;
}

int main() {
    int opcion;
    string usuario, contrasena, nuevoUsuario, nuevaContrasena;
    double monto;

    while (true) {
        cout << "1. Iniciar sesion" << endl;
        cout << "2. Registrarse" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Usuario: ";
            cin >> usuario;
            cout << "Contrasena: ";
            cin >> contrasena;

            if (iniciarSesion(usuario, contrasena)) {
                while (true) {
                    cout << "1. Recargar" << endl;
                    cout << "2. Retirar" << endl;
                    cout << "3. Pagar servicios" << endl;
                    cout << "4. Consultar saldo" << endl;
                    cout << "5. Cambiar contrasena" << endl;
                    cout << "6. Cerrar sesion" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> opcion;

                    if (opcion == 1) {
                        cout << "Monto a recargar: ";
                        cin >> monto;
                        consignar(usuario, monto);
                    } else if (opcion == 2) {
                        cout << "Monto a retirar: ";
                        cin >> monto;
                        retirar(usuario, monto);
                    } else if (opcion == 3) {
                        cout << "Monto a pagar: ";
                        cin >> monto;
                        pagarServicios(usuario, monto);
                    } else if (opcion == 4) {
                        cout << "Saldo actual: " << consultarSaldo(usuario) << endl;
                    } else if (opcion == 5) {
                        cout << "Nueva contrasena: ";
                        cin >> nuevaContrasena;
                        cambiarContrasena(usuario, nuevaContrasena);
                    } else if (opcion == 6) {
                        break;
                    }
                }
            } else {
                cout << "Usuario o contrasena incorrectos" << endl;
            }
        } else if (opcion == 2) {
            cout << "Nuevo usuario: ";
            cin >> nuevoUsuario;
            cout << "Contrasena: ";
            cin >> nuevaContrasena;
            registrarUsuario(nuevoUsuario, nuevaContrasena);
            cout << "Usuario registrado exitosamente" << endl;
        } else if (opcion == 3) {
            break;
        }
    }
    return 0;
}
