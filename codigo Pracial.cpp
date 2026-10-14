#include <iostream>
#include <string>

using namespace std;

//CREACIONAL: FACTORY METHOD

// Clase base
class Bebida {
public:
	virtual string descripcion() = 0;
	virtual double costo() = 0;
	virtual ~Bebida() {}
};

// Café
class Cafe : public Bebida {
public:
	string descripcion() {
		return "Cafe";
	}
	
	double costo() {
		return 5000;
	}
};

// Té
class Te : public Bebida {
public:
	string descripcion() {
		return "Te";
	}
	
	double costo() {
		return 4000;
	}
};

// Factory Method
class FabricaBebidas {
public:
	static Bebida* crearBebida(int opcion) {
		
		if(opcion == 1)
			return new Cafe();
		
		else if(opcion == 2)
			return new Te();
		
		return NULL;
	}
};


//ESTRUCTURAL: DECORATOR

class DecoradorBebida : public Bebida {
protected:
	Bebida* bebida;
	
public:
	DecoradorBebida(Bebida* b) {
		bebida = b;
	}
};

// Leche
class Leche : public DecoradorBebida {
public:
	Leche(Bebida* b) : DecoradorBebida(b) {}
	
	string descripcion() {
		return bebida->descripcion() + " + Leche";
	}
	
	double costo() {
		return bebida->costo() + 1000;
	}
};

// Crema
class Crema : public DecoradorBebida {
public:
	Crema(Bebida* b) : DecoradorBebida(b) {}
	
	string descripcion() {
		return bebida->descripcion() + " + Crema";
	}
	
	double costo() {
		return bebida->costo() + 1500;
	}
};

// COMPORTAMIENTO: OBSERVER


// Observer
class Cliente {
public:
	void actualizar() {
		cout << "\n[NOTIFICACION]" << endl;
		cout << "Su pedido esta listo." << endl;
	}
};

// Subject
class Pedido {
private:
	Cliente* cliente;
	
public:
	
	Pedido() {
		cliente = NULL;
	}
	
	void suscribir(Cliente* c) {
		cliente = c;
	}
	
	void pedidoListo() {
		if(cliente != NULL) {
			cliente->actualizar();
		}
	}
};

/*==================================================
MAIN
==================================================*/

int main() {
	
	int opcion;
	
	cout << "====================================" << endl;
	cout << " SISTEMA DE PEDIDOS DE CAFETERIA" << endl;
	cout << "====================================" << endl;
	
	cout << "\nSeleccione una bebida:" << endl;
	cout << "1. Cafe" << endl;
	cout << "2. Te" << endl;
	cout << "Opcion: ";
	cin >> opcion;
	
	// Factory Method
	Bebida* bebida = FabricaBebidas::crearBebida(opcion);
	
	if(bebida == NULL) {
		cout << "Opcion no valida." << endl;
		return 0;
	}
	
	int extra;
	
	cout << "\nAgregar leche?" << endl;
	cout << "1. Si" << endl;
	cout << "2. No" << endl;
	cin >> extra;
	
	if(extra == 1) {
		bebida = new Leche(bebida);
	}
	
	cout << "\nAgregar crema?" << endl;
	cout << "1. Si" << endl;
	cout << "2. No" << endl;
	cin >> extra;
	
	if(extra == 1) {
		bebida = new Crema(bebida);
	}
	
	cout << "\n========== RESUMEN ==========" << endl;
	cout << "Pedido: " << bebida->descripcion() << endl;
	cout << "Costo total: $" << bebida->costo() << endl;
	
	// Observer
	Cliente cliente;
	Pedido pedido;
	
	pedido.suscribir(&cliente);
	
	cout << "\nPreparando pedido..." << endl;
	
	pedido.pedidoListo();
	
	return 0;
}
