#include <iostream>
using namespace std;


float leerHorasTrabajadas()
{
    float horas_trabajadas;
    cout << "Cuantas horas ha trabajado el empleado: ";
    cin >> horas_trabajadas;
    return horas_trabajadas;
}
float leerTarifa()
{
    float tarifa;
    cout << "Cual es el sueldo por hora del empleado: ";
    cin >> tarifa;
    return tarifa;
}

float calcularSalario(float horas_trabajadas, float tarifa)
{
    // Se paga cada hora según el precio mínimo (tarifa)
    float salario = horas_trabajadas * tarifa;
    float horas_extra = horas_trabajadas - 40;
    // A ese salario se le suma un bonus del 50% a la tarifa por las horas extra
    if(horas_extra > 0)
    {
        salario += horas_extra*tarifa*0.5;
    }
    cout << "Se ha calculado un salario de: " << salario << " €" << endl;
    return salario;
}

int main()
{
    // Se asume que tanto las horas trabajadas como la tarifa pueden ser números decimales (p.ej: 42.5 horas = 42 horas y media, 4.9€/hora = 4€ 90c la hora)
    float horas_trabajadas = leerHorasTrabajadas();
    float tarifa = leerTarifa();

    float sueldo = calcularSalario(horas_trabajadas, tarifa);
}