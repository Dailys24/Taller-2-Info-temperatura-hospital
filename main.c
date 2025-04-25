//Integrante 1: Angelo 
//Integrante 2: Moisés 
//Integrante 3: Nicolas 
//Integrante 4: Matias 
//Profesor(a): Leonardo Bravo
//Sección: 


#include <math.h>
#include <stdio.h>
#include <string.h>

//Calculo de porcentaje.
float calculo_porcentaje(int cantidadp, int masculino, int femenino){
  float porcentaje;
  porcentaje = ((masculino+femenino) * 100.0) / (cantidadp*1.0);
  return porcentaje;
}

//Funcion void.
void mostrar(float temperatura_mayor, float temperatura_menor, int rut_mayor, int rut_menor, int edad_mayor, int edad_menor, char sexo_mayor, char sexo_menor){
  
  printf("\nEl paciente con mayor temperatura es: %.1f°C, rut: %d, edad: %d, sexo: %d", temperatura_mayor, rut_mayor, edad_mayor, sexo_mayor);
    printf("\nEl paciente con menor temperatura es: %.1f°C, rut: %d, edad: %d, sexo: %d", temperatura_menor, rut_menor, edad_menor, sexo_menor);
  
}

int main(void)
{
  //Variables.
  int rut=1, edad=0, masculino=0, femenino=0, suma_covid, cantidadp=0, aux, sexo, sexo_menor, sexo_mayor; 
  float temperatura, porcentaje_pacientes;
  float temperatura_menor=45.9, temperatura_mayor=23.9, edad_mayor=0, edad_menor=0, rut_mayor=0, rut_menor=0;

  //Titulo taller 2
  printf("\n-----Hospital clinico universidad de chile-----\n");
  
  //Comienzo del ciclo while.
  while(rut != 0){
    
    //Pedir rut al usuario.
    printf("\nIngrese el rut del paciente(sin el numero vereficador y sin puntos, para dar fin al listado ingrese (0)): ");
    scanf("%d", &rut);
    
    //Si rut = 0 fin del listado.
    if(rut == 0){
      printf("\n-----Fin del listado-----\n");
      break;
    }
      //Ciclo de condicion del rut.
      while(rut < 8000000 || rut > 30000000){
      printf("\nERROR, el rut ingresado es invalido, ingrese nuevamente el rut del paciente: ");
      scanf("%d", &rut);
      }
    
      //Contador cantidad de personas.
    cantidadp++;
    
    //Pedir edad al usuario.
    printf("\nIngresar la edad del paciente (entre 1 a 110 años): ");
    scanf("%d", &edad);
    
      //Ciclo de condicion de edad.
      while(edad < 1 || edad > 110){
      printf("\nERROR, la edad fue mal ingresada, vuelva a ingresarla (entre 1 a 110 años): ");
      scanf("%d", &edad);
      }
    
      //Pedir sexo al usuario.
    printf("\nIngresar el sexo del paciente (si el sexo es masculino 1 y si el sexo es femenino 2): ");
    scanf("%d", &sexo);
    
      //Ciclo de condicion sexo.
      while(sexo < 1 || sexo > 2){
      printf("\nERROR, los datos ingresados son incorrectos, vuelva a ingresarlos (masculino 1 o femenino 2: ");
      scanf("%d", &sexo);
      }
    
      //Pedir temperatura al usuario.
    printf("\nIngrese la temperatura del paciente (utilice (.)): ");
    scanf("%f", &temperatura);

      //Ciclo condicion temperatura.
      while(temperatura < 24,0 || temperatura > 46,0){
      printf("\nERROR, la temperatura ingresada es invalida, por favor vuelva a introducirla:");
      scanf("%f", &temperatura);     
      }
    
    //Funcion porcentaje menor.
    if(temperatura < temperatura_menor){
      temperatura_menor = temperatura;
      rut_menor = rut;
      edad_menor = edad;
      sexo_menor = sexo;
    }
    
    //Funcion porcentaje mayor.
    if(temperatura > temperatura_mayor){
      temperatura_mayor = temperatura;
      rut_mayor = rut;
      edad_mayor = edad;
      sexo_mayor = sexo;
    }
    
     //Contador de masculino.
    if(temperatura > 37 && sexo==1){
      masculino++;
    }
    
     //Contalor de femenino.
    if(edad > 40 && temperatura > 37 && sexo==2){
      femenino++;
    }
  }
  
      //Llamado a funcion float para calculo de porcentaje.
      porcentaje_pacientes = calculo_porcentaje(cantidadp,masculino,femenino);
  
    //Imprimir la cantidad de pacientes masculinos con COVID 19, la cantidad de pacientes femeninos con COVID 19, el porcentaje de pacientes con COVID 19.
    printf("\nLa cantidad de pacientes masculinos con COVID 19 son: %d", masculino);
    printf("\nLa cantidad de pacientes femeninos con COVID 19 son: %d", femenino);
    printf("\nEl porcentaje de pacientes con COVID 19 son: %.3f %", porcentaje_pacientes);
  
  //Llamado a funcion void para imprimir paciente con temperatura mayor y temperatura menor.
  mostrar(temperatura_mayor, temperatura_menor, rut_mayor,  rut_menor, edad_mayor, edad_menor, sexo_mayor, sexo_menor);
    
    return 0;
}
