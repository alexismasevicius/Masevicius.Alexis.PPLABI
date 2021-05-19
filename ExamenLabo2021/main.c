#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "menu.h"
#include "mascotas.h"
#include "trabajos.h"
#include "tipos.h"
#include "color.h"
#include "servicios.h"

#define TAMTIPOS 5
#define TAMCOLOR 5
#define TAMSERV 3
#define TAMMAS 20
#define TAMTRA 100




int main()
{
    int opcion;
    int opcionSecundaria;
    eTipos listatipos[TAMTIPOS]={{1000,"Ave",0},{1001,"Perro",0},{1002,"Gato",0},{1003,"Roedor",0},{1004,"Pez",0}};
    eColores listacolores[TAMCOLOR]={{5000,"Negro",0},{5001,"Blanco",0},{5002,"Gris",0},{5003,"Rojo",0},{5004,"Azul",0}};
    eServicio listaservicio[TAMSERV]={{20000,"Corte",100,0},{20001,"Desparasitado",200,0},{20002,"Castrado",500,0}};
    eMascota listaMascotas[TAMMAS];
    eTrabajo listaTrabajos[TAMTRA];


    int codigoMascota=1000;
    int codigoTrabajo=10000;

    inicializarMascota(listaMascotas,TAMMAS);
    inicializarTrabajos(listaTrabajos,TAMTRA);




    do{

        printf("\n");

        menuPrincipal();
        utn_getNumero(&opcion,"Ingrese una opcion: \n", "Error. Ingrese una opcion valida.\n",1,5,100);

        switch(opcion)
        {
            case 1:
                system("cls");
                menuAlta();
                utn_getNumero(&opcionSecundaria,"Ingrese una opcion: \n", "Error. Ingrese una opcion valida.\n",1,2,100);
                switch(opcionSecundaria)
                {
                    case 1:
                        system("cls");
                        if(altaMascota(listaMascotas,TAMMAS,&codigoMascota,listatipos,TAMTIPOS,listacolores,TAMCOLOR)==1)
                        {

                            printf("\nAlta completa.\n");
                        }
                        else
                        {
                            printf("\nNo se pudo realizar la carga del empleado.\n");
                        }
                        break;

                    case 2:
                         system("cls");
                        if(altaTrabajo(listaTrabajos,TAMTRA,&codigoTrabajo,listaMascotas,TAMMAS,listaservicio,TAMSERV,listatipos,TAMTIPOS,listacolores,TAMCOLOR))
                        {
                              printf("\nAlta completa.\n");
                        }
                        else
                        {
                            printf("\nNo se pudo realizar la carga del trabajo. Error.\n");
                        }
                }

                break;
            case 2:
                   system("cls");
                    if(bajaMascota(listaMascotas,TAMMAS,listatipos,TAMTIPOS,listacolores,TAMCOLOR))
                    {
                        printf("\nBaja exitosa.\n");
                    }
                    else
                    {
                        printf("\nNo se pudo completar la baja.\n");
                    }

                break;
            case 3:
                    system("cls");
                   if(modificarMascotas(listaMascotas,TAMMAS,listatipos,TAMTIPOS,listacolores,TAMCOLOR)==1)
                    {
                        printf("\nModificacion exitosa.\n");
                    }
                    else
                    {
                        printf("\nNo se pudo completar la modificacion.\n");
                    }
                    break;
            case 4:
                system("cls");
                menuListar();
                utn_getNumero(&opcionSecundaria,"Ingrese una opcion: \n", "Error. Ingrese una opcion valida.\n",1,5,100);
                switch(opcionSecundaria)
                {
                    case 1:
                        system("cls");
                        if(mostrarMascotas(listaMascotas,TAMMAS,listatipos,TAMTIPOS,listacolores,TAMCOLOR)==0)
                        {
                            printf("\nNo hay mascotas cargadas.\n");
                        }
                        break;
                    case 2:
                        system("cls");
                        if(mostarTipos(listatipos,TAMTIPOS)==0)
                        {
                            printf("\nNo hay tipos cargados.\n");
                        }
                        break;
                    case 3:
                        system("cls");
                        if(mostarColores(listacolores,TAMCOLOR)==0)
                        {
                            printf("\nNo hay colores cargados.\n");
                        }
                        break;
                    case 4:
                        system("cls");
                        if(mostarServicios(listaservicio,TAMSERV)==0)
                        {
                            printf("\nNo hay servicios cargados.\n");
                        }
                        break;
                    case 5:
                        system("cls");
                        if(mostrarTrabajos(listaTrabajos,TAMTRA,listaMascotas,TAMMAS,listaservicio,TAMSERV)==0)
                        {
                            printf("\nNo hay trabajos cargados.\n");
                        }
                        break;

                }
                break;

        }


    }while(opcion!=5);

    return 0;
}
