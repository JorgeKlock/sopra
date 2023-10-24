#include <iostream>
#include <vector>
using namespace std;

enum sexos {masculino, femenino};

struct Persona
{
    int edad;
    sexos sexo; // 0 - masculino, 1 - femenino
};

vector<Persona> leerPersonas()
{
    vector<Persona> personas;
    /*Introduce 50 personas en el vector*/
    for (size_t i = 0; i < 50; i++)
    {
        Persona nueva_persona;
        nueva_persona.edad = rand()%100;
        int sexo_aleatorio = rand()%2;
        if(sexo_aleatorio == 0) {nueva_persona.sexo = masculino;}
        else {nueva_persona.sexo = femenino;}
        personas.push_back(nueva_persona);
    }
    return personas;    
}

void clasificacionPersonas(vector<Persona> personas)
{
    int masculino_mayor = 0;
    int masculino_menor = 0;
    int femenino_mayor = 0;
    int femenino_menor = 0;

    // Adquirimos los datos necesarios en un único barrido por el vector
    for (size_t i = 0; i < personas.size(); i++)
    {
        // Empleando el acceso a vector para la edad y una variable temporal para el sexo 
        // minimizamos los accesos al elemento iésimo del vector
        sexos sexo_temp = personas[i].sexo;
        // Persona menor de edad
        if(personas[i].edad < 18)
        {
            if(sexo_temp == masculino) // Menor de edad masculino
            {
                masculino_menor++;
            }
            else{                             // Menor de edad femenino
                femenino_menor++;
            }
        }
        // Persona mayor de edad
        else 
        {
            if(sexo_temp == masculino) // Mayor de edad masculino
            {
                masculino_mayor++;
            }
            else{                             // Mayor de edad femenino
                femenino_mayor++;
            }
        }
    }
    cout << "Personas mayores de edad: " << masculino_mayor + femenino_mayor << endl;
    cout << "Personas menores de edad: " << masculino_menor + femenino_menor << endl;
    cout << "Personas masculinas mayores de edad: " << masculino_mayor << endl;
    cout << "Personas femeninas menores de edad: " << femenino_menor << endl;
    cout << "Porcentaje personas mayores de edad (%): " << (masculino_mayor + femenino_mayor) * 100.0 / personas.size() << endl;
    cout << "Porcentaje de mujeres (%): " << (femenino_mayor + femenino_menor) * 100.0 / personas.size() << endl;
}

int main()
{
    vector<Persona> personas = leerPersonas();
    clasificacionPersonas(personas);
}