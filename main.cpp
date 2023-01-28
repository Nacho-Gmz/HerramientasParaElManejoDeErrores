#include <iostream>
using namespace std;

/*
Función 'divide' que se encarga de dividir dos números, 
pero antes de realizar la división revisa si el divisor 
es igual a cero; si este es igual a cero, en lugar de 
realizar la división arroja un error de ejecución que
describe el porque no se puede realizar la división
*/ 
int divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Error: división por cero");
    }
    return a / b;
}

int main() {
    int a = 5, b = 2, result;

    /*
    Primer try-catch donde se divide a(5) entre b(2); al ser una
    operacion válida, la fución 'divide' no arroja un 'runtime_error'
    por lo que la sección catch no fue necesitada y por ello no solo
    se muestra el resultado de la división
    */
    try {
        result = divide(a, b);
        cout << "Resultado: " << result << endl; // Resultado: 2
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }

    /*
    Segundo try-catch donde se divide a(5) entre 0; al ser una 
    operación inválida, la función 'divide' arroja el 'runtime_error'
    de división entre cero y esto hace que el catch sea necesitado y 
    en lugar de mostrar el resultado de la operación, el bloque catch
    se encarga de mostrar la razón del error en pantalla 
    */
    try {
        result = divide(a, 0);
        cout << "Resultado: " << result << endl;
    } catch (runtime_error& e) {
        cout << e.what() << endl; // Error: división por cero
    }
    
    return 0;
}
