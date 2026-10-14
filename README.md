SISTEMA DE PEDIDOS PARA CAFETERIA
MATERIA: Patrones de software
PROFESOR: Felipe Gutiérrez Isaza
LENGUAJE: C++
ENTORNO DE DESARROLLO: zinjal
ARCHIVO PRINCIPAL: main.cpp

INTEGRANTES: Erick Santiago Loaiza Ocampo

DESCRIPCION DEL PROYECTO
El Sistema de Pedidos para Cafetería es una aplicación de consola desarrollada en C++ que permite a los usuarios seleccionar una bebida, personalizarla con ingredientes adicionales y recibir una notificación cuando el pedido se encuentra listo.

Este proyecto fue desarrollado con el objetivo de implementar e integrar tres patrones de diseño pertenecientes a diferentes categorías: creacional, estructural y de comportamien

PROBLEMA A RESOLVER
En una cafetería, los clientes pueden elegir distintos tipos de bebidas y agregar ingredientes adicionales según sus preferencias.

Si el sistema se desarrolla sin patrones de diseño, el código puede crecer rápidamente debido a la cantidad de combinaciones posibles de bebidas e ingredientes, generando duplicación de código y dificultando el mantenimiento.

Además, es necesario informar al cliente cuando su pedido esté listo.

Para solucionar estos problemas se implementaron tres patrones de diseño que trabajan conjuntamente dentro del mismo flujo de la aplicación.

PATRONES DE DISEÑO UTILIZADO
1. Factory Method 
Objetivo
Crear objetos sin depender directamente de las clases concretas.

Clases Involucradas
Bebida
Cafe
Te
FabricaBebidas
Función en la Aplicación
Permite crear bebidas como Café o Té a través de una fábrica especializada, centralizando la lógica de creación y reduciendo el uso de estructuras condicionales en el programa principal.

2. Decorator 
Objetivo
Agregar funcionalidades o características adicionales a una bebida de manera dinámica.

Clases Involucradas
DecoradorBebida
Leche
Crema
Función en la Aplicación
Permite agregar ingredientes adicionales a una bebida sin modificar las clases originales.

Ejemplos:

Café
Café + Leche
Café + Crema
Café + Leche + Crema

3. Observer (Patrón de Comportamiento)
Objetivo
Notificar automáticamente a los clientes cuando ocurra un cambio de estado.

Clases Involucradas
Cliente
Pedido
Función en la Aplicación
Cuando el pedido está listo, el sistema notifica automáticamente al cliente.

Integración de los Patrones
Los tres patrones se encuentran integrados en un mismo flujo de trabajo:

El usuario selecciona una bebida.
Factory Method crea la bebida solicitada.
Decorator añade ingredientes adicionales a la bebida.
Se genera el pedido.
Observer notifica al cliente cuando el pedido está listo.
Flujo General
Cliente
   │
   ▼
Factory Method
   │
   ▼
Creación de Bebida
   │
   ▼
Decorator
   │
   ▼
Personalización de la Bebida
   │
   ▼
Pedido
   │
   ▼
Observer
   │
   ▼
Notificación al Cliente
Diagrama de Relaciones
                 +----------------+
                 |    Bebida      |
                 +----------------+
                        ^
                        |
              ------------------
              |                |
         +--------+      +--------+
         | Cafe   |      |  Te    |
         +--------+      +--------+

                        ^
                        |
               FabricaBebidas
              (Factory Method)

                        |
                        v

              +------------------+
              | DecoradorBebida  |
              +------------------+
                       ^
                       |
            ---------------------
            |                   |
        +--------+         +--------+
        | Leche  |         | Crema  |
        +--------+         +--------+

                       |
                       v

                 +---------+
                 | Pedido  |
                 +---------+
                       |
                       v

                 +---------+
                 | Cliente |
                 +---------+

                   Observer
Ubicación de los Patrones en el Código
Factory Method
// 1. CREACIONAL: FACTORY METHOD
Contiene las clases:

Bebida
Cafe
Te
FabricaBebidas
Decorator
// 2. ESTRUCTURAL: DECORATOR
Contiene las clases:

DecoradorBebida
Leche
Crema
Observer
// 3. COMPORTAMIENTO: OBSERVER
Contiene las clases:

Cliente
Pedido
Compilación y Ejecución
Compilar
g++ main.cpp -o cafeteria
Ejecutar
./cafeteria
En Zinjai
Abrir el archivo main.cpp.
Presionar el botón Compilar.
Presionar el botón Ejecutar.
Salida Esperada
====================================
 SISTEMA DE PEDIDOS DE CAFETERIA
====================================

Seleccione una bebida:
1. Cafe
2. Te

Opcion: 1

Agregar leche?
1. Si
2. No

Agregar crema?
1. Si
2. No

RESUMEN 
Pedido: Cafe + Leche + Crema
Costo total: $7500

Preparando pedido...

[NOTIFICACION]
Su pedido esta listo.
Conclusiones
La implementación de los patrones Factory Method, Decorator y Observer permitió desarrollar una solución organizada, flexible y fácil de mantener.

Cada patrón cumple una función específica dentro del sistema:

Factory Method crea las bebidas.
Decorator personaliza los pedidos.
Observer notifica al cliente cuando el pedido está listo.
La integración de estos tres patrones demuestra cómo diferentes categorías de patrones pueden trabajar conjuntamente para resolver un problema real dentro de una aplicación.










