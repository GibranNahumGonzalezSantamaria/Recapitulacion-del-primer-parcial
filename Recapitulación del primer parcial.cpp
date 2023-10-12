#include <iostream>
#include <conio.h> // Permite utilizar getch()
#include <cctype>  // Permite utilizar isdigit()
#include <iomanip> // Permite utilizar fixed y setprecision.
#include <cmath>   // Permite utilizar abs()

using namespace std;

// Prototipo de las funciones.
void Agregar();
void MaxMin(char Opcion);
void Moda();
void Sumatoria(char Opcion);

// Declaración de variables globales.
int Cola[10], Pila[10], ActualCola = 0, ActualPila = 0;

int main()
{
    while (true)
    {
        system("Cls");
        cout << "<<< Recapitulacion del primer parcial >>>\n\n";

        // Imprime todos los elementos de la Cola.
        cout << " * Elementos en la Cola:   ";
        for (int i = 0; i < 10; i++)
            if (Cola[i] == 0)
                cout << "[-]  ";
            else
                cout << '[' << Cola[i] << "]  ";

        // Imprime todos los elementos de la Pila.
        cout << "\n * Elementos en la Pila:   ";
        for (int i = 0; i < 10; i++)
            if (Pila[i] == 0)
                cout << "[-]  ";
            else
                cout << '[' << Pila[i] << "]  ";

        // Muestra las opciones disponibles.
        cout << "\n\n 1. Aniadir un elemento." << endl
             << " 2. Encontrar el maximo y minimo." << endl
             << " 3. Encontrar la moda." << endl
             << " 4. Encontrar la sumatoria de los datos." << endl
             << " 5. Encontrar el promedio de los datos." << endl
             << " 6. Desplegar el rango de los datos guardados." << endl
             << " 7. Calcular la desviacion media." << endl
             << " 8. Eliminar elemento en la Cola." << endl
             << " 9. Eliminar elemento en la Pila." << endl
             << " X. Salir del programa.\n\n";

        // Solicita la opción y verifica que sea válida.
        char Opcion;
    IngresarOpcion:
        cout << " * Ingrese la opcion que desea realizar:   ";
        Opcion = getch();
        cout << Opcion << endl;

        // Ejecuta la 1ra opción mientras la Cola o Pila no estén llenas.
        if (Opcion == '1')
            if (Cola[9] != 0 || Pila[9] != 0)
            {
                cout << "   - La Cola o Pila se encuentran llenas.\n\n\n";
                system("Pause");
            }
            else
                Agregar();

        // No ejecuta ninguna acción mientras la Cola o Pila estén vacías.
        else if ((Cola[0] == 0 || Pila[0] == 0) && (Opcion >= '2' && Opcion <= '9'))
        {
            cout << "   - La Cola o Pila no tienen ningun elemento en ella.\n\n\n";
            system("Pause");
        }

        else if (Opcion == '2' || Opcion == '6')
            MaxMin(Opcion);

        else if (Opcion == '3')
            Moda();

        else if (Opcion == '4' || Opcion == '5' || Opcion == '7')
            Sumatoria(Opcion);

        else if (Opcion == '8')
        {
            // FILO.
            Cola[ActualCola + 1] = 0;

            // Recorre los elementos hacia la izquierda.
            for (int i = 0; i < 10; i++)
                Cola[i] = Cola[i + 1];

            // Verifica que el apuntador no pueda ser menor que 0.
            if (ActualCola >= 0)
                ActualCola--;
        }

        else if (Opcion == '9')
        {
            // FIFO.
            Pila[ActualPila] = 0;

            // Verifica que el apuntador no pueda ser menor que 0.
            if (ActualPila >= 0)
                ActualPila--;
        }

        else if (toupper(Opcion) == 'X')
            exit(0);

        else
            goto IngresarOpcion;
    }

    return 0;
}

void Agregar()
{
    system("Cls");
    cout << "<<< Aniadir un elemento >>>\n\n";

    // Solicita el elemento y verifica que sea válido.
    char Elemento;
IngresarElemento:
    cout << " * Ingrese el elemento:   ";
    Elemento = getch();
    cout << Elemento << endl;
    if (!isdigit(Elemento) || Elemento == 0)
        goto IngresarElemento;

    // Solicita la opción y verifica que sea válida.
    char Opcion;
IngresarOpcion:
    cout << " * Desea aniadir el elemento a la Cola (C) o a la Pila (P)?:   ";
    Opcion = getch();
    cout << Opcion << endl;

    // Agrega el elemento a la Cola o Pila según corresponda.
    if (toupper(Opcion) == 'C')
    {
        Cola[ActualCola] = atoi(&Elemento); // Convierte char a int.
        ActualCola++;
    }
    else if (toupper(Opcion) == 'P')
    {
        Pila[ActualPila] = atoi(&Elemento); // Convierte char a int.
        ActualPila++;
    }
    else
        goto IngresarOpcion;
}

void MaxMin(char Opcion)
{
    // Encuentra el máximo y mímino elemento en la Cola.
    int MaximoCola = Cola[0], MinimoCola = Cola[0];
    for (int i = 1; i < 10; i++)
    {
        if (Cola[i] > MaximoCola)
            MaximoCola = Cola[i];
        if (Cola[i] != 0 && Cola[i] < MinimoCola)
            MinimoCola = Cola[i];
    }

    // Encuentra el máximo y mímino elemento en la Pila.
    int MaximoPila = Pila[0], MinimoPila = Pila[0];
    for (int i = 1; i < 10; i++)
    {
        if (Pila[i] > MaximoPila)
            MaximoPila = Pila[i];
        if (Pila[i] != 0 && Pila[i] < MinimoPila)
            MinimoPila = Pila[i];
    }

    system("Cls");

    // Muestra los resultados obtenidos (máximos y mínimos).
    if (Opcion == '2')
        cout << "<<< Encontrar el maximo y minimo >>>\n\n"
             << "   - El maximo en la Cola es:   " << MaximoCola << endl
             << "   - El minimo en la Cola es:   " << MinimoCola << "\n\n"
             << "   - El maximo en la Pila es:   " << MaximoPila << endl
             << "   - El minimo en la Pila es:   " << MinimoPila << "\n\n\n";

    // Calcula y muestra los resultados obtenidos (rangos).
    else
        cout << "<<< Encontrar el rango >>>\n\n"
             << "   - El rango en la Cola es:   " << MaximoCola - MinimoCola << endl
             << "   - El rango en la Pila es:   " << MaximoPila - MinimoPila << "\n\n\n";

    system("Pause");
}

void Moda()
{
    // Determina la moda en la Cola.
    int ModaCola = Cola[0], FrecuenciaCola = 1;
    for (int i = 0; i < 10; i++)
    {
        int ContadorCola = 0;

        // Cuenta repeticiones del elemento actual (excepto si es 0).
        for (int j = 0; j < 10; j++)
            if (Cola[i] != 0 && Cola[j] == Cola[i])
                ContadorCola++;

        // Actualiza la frecuencia y moda si encuentra un elemento con mayor frecuencia.
        if (ContadorCola > FrecuenciaCola)
        {
            FrecuenciaCola = ContadorCola;
            ModaCola = Cola[i];
        }
    }

    // Determina la moda en la Pila.
    int ModaPila = Pila[0], FrecuenciaPila = 1;
    for (int i = 0; i < 10; i++)
    {
        int ContadorPila = 0;

        // Cuenta repeticiones del elemento actual (excepto si es 0).
        for (int j = 0; j < 10; j++)
            if (Pila[i] != 0 && Pila[j] == Pila[i])
                ContadorPila++;

        // Actualiza la frecuencia y moda si encuentra un elemento con mayor frecuencia.
        if (ContadorPila > FrecuenciaPila)
        {
            FrecuenciaPila = ContadorPila;
            ModaPila = Pila[i];
        }
    }

    system("Cls");

    // Muestra los resultados obtenidos (modas).
    cout << "<<< Encontrar la moda >>>\n\n"
         << "   - La moda de la Cola es:   " << ModaCola << endl
         << "   - La moda de la Pila es:   " << ModaPila << "\n\n\n";

    system("Pause");
}

void Sumatoria(char Opcion)
{
    // Calcula la sumatoria en la Cola.
    float SumatoriaCola = 0, ElementosCola = 0;
    for (int i = 0; i < 10; i++)
    {
        SumatoriaCola += Cola[i];
        if (Cola[i] != 0)
            ElementosCola++;
    }
    // Determina el promedio en la Cola.
    float PromedioCola = SumatoriaCola / ElementosCola;

    // Calcula la sumatoria en la Pila.
    float SumatoriaPila = 0, ElementosPila = 0;
    for (int i = 0; i < 10; i++)
    {
        SumatoriaPila += Pila[i];
        if (Pila[i] != 0)
            ElementosPila++;
    }
    // Determina el promedio en la Pila.
    float PromedioPila = SumatoriaPila / ElementosPila;

    // Calcula la desviación media en la Cola.
    float SumatoriaDiferenciasCola = 0;
    for (int i = 0; i < 10; i++)
        SumatoriaDiferenciasCola += abs(Cola[i] - PromedioCola);
    float DesviacionMediaCola = SumatoriaDiferenciasCola / ElementosCola;

    // Calcula la desviación media en la Pila.
    float SumatoriaDiferenciasPila = 0;
    for (int i = 0; i < 10; i++)
        SumatoriaDiferenciasPila += abs(Pila[i] - PromedioPila);
    float DesviacionMediaPila = SumatoriaDiferenciasPila / ElementosPila;

    system("Cls");

    // Muestra los resultados obtenidos (sumatorias).
    if (Opcion == '4')
        cout << "<<< Encontrar la sumatoria de los datos >>>\n\n"
             << "   - Sumatoria en la Cola:   " << SumatoriaCola << endl
             << "   - Sumatoria en la Pila:   " << SumatoriaPila << "\n\n\n";

    // Muestra los resultados obtenidos (promedios) limitando a 2 decimales.
    else if (Opcion == '5')
        cout << "<<< Encontrar el promedio de los datos >>>\n\n"
             << fixed << setprecision(2) << "   - Promedio en la Cola:   " << PromedioCola << endl
             << "   - Promedio en la Pila:   " << PromedioPila << fixed << setprecision(0) << "\n\n\n";

    // Muestra los resultados obtenidos (desviaciones medias) limitando a 2 decimales.
    else
        cout << "<<< Calcular la desviacion media >>>\n\n"
             << fixed << setprecision(2) << "   - Desviacion media en la Cola:   " << DesviacionMediaCola << endl
             << "   - Desviacion media en la Pila:   " << DesviacionMediaPila << fixed << setprecision(0) << "\n\n\n";

    system("Pause");
}
