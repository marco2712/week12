# 🧠 Algoritmos Embarazosamente Paralelos con OpenMP

Este proyecto presenta una serie de **ejercicios implementados en C++** que demuestran el uso de **paralelismo embarazosamente paralelo** mediante la biblioteca **OpenMP**.  
Cada programa resuelve un problema independiente en el que las tareas pueden ejecutarse sin necesidad de comunicación entre hilos.

---

## ⚙️ Requisitos

- **Compilador compatible con OpenMP**, por ejemplo:
  - GCC (versión 9.0 o superior)
  - Clang con soporte para OpenMP
- **Sistema operativo:** Linux, macOS o Windows (con MinGW o WSL)
- **Herramientas recomendadas:**  
  - `g++`  
  - `make` (opcional)  
  - Visual Studio Code / CLion / cualquier editor C++

---

## 🧩 Ejercicios Incluidos

### 🖼️ Ejercicio 1: Filtro en múltiples imágenes
Simula la aplicación de un filtro a varias imágenes (representadas como matrices).  
Cada imagen se procesa de forma independiente en un hilo diferente.

### ➕ Ejercicio 2: Suma de elementos en múltiples vectores
Calcula la suma total de cada vector en paralelo.  
Cada hilo procesa un vector completo para mejorar el rendimiento.

### 🔍 Ejercicio 3: Búsqueda en múltiples vectores
Busca un valor determinado en varios vectores grandes.  
Cada hilo realiza la búsqueda en un vector diferente.

### 🪂 Ejercicio 4: Simulación de caída libre
Calcula el tiempo de caída libre para varios objetos desde distintas alturas usando la fórmula `t = sqrt(2h/g)`.  
Cada cálculo se realiza en paralelo.

---

## 🧵 Concepto Clave

Un **algoritmo embarazosamente paralelo** es aquel en el que las tareas son **completamente independientes**, por lo que no se requiere comunicación ni sincronización entre los hilos.  
Esto permite escalar el rendimiento casi linealmente con el número de núcleos del procesador.

---

## 🚀 Compilación y Ejecución

Para compilar un ejercicio (por ejemplo, `ejercicio2.cpp`):

```bash
g++ ejercicio2.cpp -fopenmp -o ejercicio2
