#include<bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define loop(i,a,b) for(int i = a ; i<b ; ++i)
#define X first
#define Y second
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,string> agenda;
typedef  map<ii, vector< string  > > asr;
typedef  map<ii,string>  pro;

struct laboratorios_clase{
    string nombre;
    ii disponibilidad;
};

struct sala_semillero{
    int dis_horario[13];
    map<ii, vector< string  > > agenda_sala_semilleros; // horario y los profesores
};
struct sala_reunion{
    int dis_horario[13];
    map<ii, vector< string  > > agenda_sala_reuniones; // horario y los profesores
    map<ii , string > proposito;
};

struct laboratorios_dispo{
  int cost;
  int cupo;
  string nombre_lab;
  set<string> programas;
  set<string> universidades_ext;
  int dispo_horario[13];
  vector<agenda> resumen_dia; // tiempo de duracion , cupos;
};

vector<laboratorios_clase> LC; // punto 1;
set<int> laboratorios_usados; // Saber cuantos laboratorios se han utlizados
set<string> univer_ex; // Con el set se controla que no hallan universidades repetias
vector<laboratorios_dispo> LD; // horarios de disponibilidad
vector<sala_reunion> SR; // Sala de reuniones;
vector<sala_semillero> SS; // Sala semillero

void LC_LL(){
    /*Primer Punto*/
    laboratorios_clase clase1,clase2,clase3;
    clase1.disponibilidad = mp(8,11);clase1.nombre = "AYPC"; // PB macro definida, MP macro definida
    clase2.disponibilidad = mp(11,13);clase2.nombre = "CALI";
    clase3.disponibilidad = mp(14,17) ;clase3.nombre = "CALD";
    LC.clear(); LC.pb(clase1); LC.pb(clase2);LC.pb(clase3);
}

void hor(){
    puts("Los horarios dispuestos para clases son:");
    for( int i = 0;  i< LC.size() ; ++i){
        printf("La clase %s \n",LC[i].nombre.c_str());
        printf("Su horario es de %d:00hr hasta %d:00hr \n",LC[i].disponibilidad.first , LC[i].disponibilidad.second );
    }
    system("pause");system("cls");
    return;
}

bool ver(int lab , int inf , int sup){
    for(int i = inf  ; i<=sup;++i){
        if(LD[lab].dispo_horario[i]==1)return true;
    }
    return false;
}

bool ver_s(int lab , int inf , int sup){
    for(int i = inf  ; i<=sup;++i){
        if(SR[lab].dis_horario[i]==1)return true;
    }
    return false;
}

bool ver_s2(int lab , int inf , int sup){
    for(int i = inf  ; i<=sup;++i){
        if(SS[lab].dis_horario[i]==2)return true;
    }
    return false;
}

void prestamos_lab(){
    int lab,inf,sup,es;
    string universidad;
    puts("Bienvenido a la parte de prestamos de laboratorios.");
    puts("Hay disponibilidad de laboratorios");
    for(int labo = 0  ; labo< 6 ; labo++){
        printf("Laboratorio %d tiene las siguientes disponibilidades\n",labo);
        int i=0 ,j = i+1;
        while(i<13 && j!=13){
            int flang = LD[labo].dispo_horario[i]; // disponibilidad en la hora i+7 hr
            if(flang==0){
                while(j>i && j<13){
                    int flang2 = LD[labo].dispo_horario[j];
                    if(flang2==0)j++;// Hay disponibilidad de la i+7 hasta j+7;
                    else{
						j++;
						break;
					}
                }
            }else {i++;j++;}
            if(i+7!=j+6)printf("Hay horario de %d:00hr hasta %d:00hr\n",i+7,j+6);
            i = j-1;
        }
        puts("");
    }
	puts("Es estudiante de la escuela si = 1 o no = 0(escribalo)"); scanf("%d",&es);
	if(es){
        do{
            printf("Digite que numero de laboratorio le sirve ");scanf("%d",&lab);
            laboratorios_usados.insert(lab);
            printf("Digite desde que hora a que hora le sirve, en hr : ");scanf("%d %d",&inf,&sup);
            if(ver(lab,inf-7,sup-7)){
                printf("No se puede, no hay horario disponible\n");
            }else break;
        }while(1);
            printf("Digite el programa que pertenece "); cin >> universidad;
            LD[lab].programas.insert(universidad);
		for(int reservar  = inf-7 ; reservar<=sup-7;reservar++) LD[lab].dispo_horario[reservar] = 1;
    }else{

        do{
            printf("Digite que numero de laboratorio le sirve ");scanf("%d",&lab);
            printf("Digite desde que hora a que hora le sirve, en hr : ");scanf("%d %d",&inf,&sup);
            if(ver(lab,inf-7,sup-7)){
                printf("No se puede, no hay horario disponible\n");
            }else{
                if(sup-inf<=4)break;
                else puts("Su horario excede a 4");
            }
        }while(1);
		puts("Digite la universidad que pertenece");
        cin >> universidad;
		LD[lab].universidades_ext.insert(universidad);
		LD[lab].cost = 10000 * (sup-inf);
		for(int reservar  = inf-7 ; reservar<= sup-7;reservar++) LD[lab].dispo_horario[reservar] = 1; // Ya se resverva
		//LD[lab].resumen_dia(mp(mp(inf,sup),universidad));
    }

	system("cls");
	int cup;printf("Digite la cantidad de persona que estaran : ");scanf("%d",&cup);
	while(cup>0 && cup>5){
			printf("La cantidad pasa al total de personas que pueden estar\n");
			system("pause");system("cls");
			printf("Digite la cantidad de persona que estaran : ");scanf("%d",&cup);
	}

	LD[lab].cupo+=cup;
    return;
}

void salas_reuniones(){
     /*Las salas de reuniones se prestarán a una unidad administrativa o un grupo
     de profesores de un programa. Para hacer el préstamo se debe informar el motivo de la reunión y el tiempo que se tomará la reunión*/
    system("cls");
    int desicion,cantidad_profesores,inf,sup,reu_d;
    string profesor;
    puts("Bienvenido a la parte de prestamo de sala para reuniones");
    printf("Es grupo de personas o administrativos, Si es un grupo de personas digite 1 de lo contrario 0 ");scanf("%d",&desicion);

     for(int reu = 0  ; reu< 3 ; reu++){
            printf("La sala de reuniones %d tiene las siguientes disponibilidades\n",reu);
            int i=0 ,j = i+1;
            while(i<13 && j!=13){
                int flang = SR[reu].dis_horario[i]; // disponibilidad en la hora i+7 hr
                if(flang==0){
                    while(j>i && j<13){
                        int flang2 = SR[reu].dis_horario[j];
                        if(flang2==0)j++;// Hay disponibilidad de la i+7 hasta j+7;
                        else{
                            j++;
                            break;
                        }
                    }
                }else {i++;j++;}
                if(i+7!=j+6)printf("Hay horario de %d:00hr hasta %d:00hr\n",i+7,j+6);
                i = j-1;
            }
            puts("");
        }


    do{
            printf("Digite que numero de la sala de reuion  que  le sirve ");scanf("%d",&reu_d);
            printf("Digite desde que hora a que hora le sirve, en hr : ");scanf("%d %d",&inf,&sup);
            if(ver_s(reu_d,inf-7,sup-7)){
                printf("No se puede, no hay horario disponible\n");
            }else break;
    }while(1);

    for(int reservar  = inf-7 ; reservar<= sup-7;reservar++) SR[reu_d].dis_horario[reservar] = 1; // Ya se resverva

    if(desicion){
        printf("Digite la cantidad de profesores que van a estar : ");scanf("%d",&cantidad_profesores);
        puts("Digite los nombres de los profesores");
        for(int i = 0 ; i< cantidad_profesores ; i++){
                cin >> profesor;
                SR[reu_d].agenda_sala_reuniones[mp(inf,sup)].push_back(profesor);
        }
    }else{
        printf("Digite el nombre adiministrativo : ");
        cin >> profesor;
        SR[reu_d].agenda_sala_reuniones[mp(inf,sup)].push_back(profesor);
         }
    puts("Cual es el prosito de su reunion ?");
    cin >> profesor;
    SR[reu_d].proposito[mp(inf,sup)] = profesor;
    puts("Se a partado su sala de reuiones exitosamente");
    system("pause");
    return;
}

void salas_semillero(){
    int ss_d,inf,sup;
    for(int reu = 0  ; reu< 3 ; reu++){
            printf("La sala de semilleros %d tiene las siguientes disponibilidades\n",reu);
            int i=0 ,j = i+1;
            while(i<13 && j!=13){
                int flang = SS[reu].dis_horario[i]; // disponibilidad en la hora i+7 hr
                if(flang==0 || flang ==1){
                    while(j>i && j<13){
                        int flang2 = SS[reu].dis_horario[j];
                        if(flang2==0)j++;// Hay disponibilidad de la i+7 hasta j+7;
                        else{
                            j++;
                            break;
                        }
                    }
                }else {i++;j++;}
                if(i+7!=j+6)printf("Hay horario de %d:00hr hasta %d:00hr\n",i+7,j+6);
                i = j-1;
            }
            puts("");
        }
    do{
            printf("Digite que numero de la sala de semilleros  que  le sirve ");scanf("%d",&ss_d);
            printf("Digite desde que hora a que hora le sirve, en hr : ");scanf("%d %d",&inf,&sup);
            if(ver_s2(ss_d,inf-7,sup-7)){
                printf("No se puede, no hay horario disponible\n");
            }else break;
    }while(1);

    for(int reservar  = inf-7 ; reservar<= sup-7;reservar++) SS[ss_d].dis_horario[reservar] += 1; // Ya se resverva
    puts("Digite el nombre de su semillero");
    string semillero;
    cin >> semillero;
    SS[ss_d].agenda_sala_semilleros[mp(inf,sup)].push_back(semillero);
    return;
}

void reuniones(){
    for (int i = 0; i<3 ; ++i){
        printf("La sala reunion #%d tuve la siguiente agenda\n",i);
        for(asr::iterator it = SR[i].agenda_sala_reuniones.begin() ; it != SR[i].agenda_sala_reuniones.end(); it++){
            ii horario = it-> X ; vector<string>   p = it -> Y ;
            if(p.size()==1){
                printf("El %s estuvo en el horario de %d  hasta %d con un proposito %s\n",p[0].c_str(),horario.X,horario.Y,SR[i].proposito[horario].c_str());
            }else if(p.size()>1){
                printf("Los siguientes profesores estuvieron desde %d hasta %d discutiendo un proposito %s\n",horario.X,horario.Y,SR[i].proposito[horario].c_str());
                for(int ii =0; ii<p.size();ii++){
                    printf("%s ",p[ii].c_str());
                }
                puts("");
            }else{
                puts("No se encontro agenda.\n");
            }
        }
        puts("");
    }
    system("pause");system("cls");
    return;
}

void informe_total(){


    int lab;
    printf("Digite el numero del lab, los laboratorios estan en numero del 0-5 ");scanf("%d",&lab);
    puts("Informacion");
    puts("Estas son las universidades externas que usaron el lab.");
    for(set<string>::iterator i = LD[lab].universidades_ext.begin(); i != LD[lab].universidades_ext.end() ; i++){
        string p = *i;
        printf("%s\n",p.c_str());
    }
    puts("Estas son los diferentes programas que usaron el lab.");
    for(set<string>::iterator i = LD[lab].programas.begin(); i != LD[lab].programas.end() ; i++){
        string p = *i;printf("%s\n",p.c_str());
    }
    printf("El costo recaudado total del lab%d es %d\n",lab,LD[lab].cost);
    system("pause");system("cls");
    int des;
    puts("Desea saber cuantos laboratorios se usaron si=1 o no = 0 "); scanf("%d",&des);
    if(des){
        printf("El total de laboratorios usados son %d\n",laboratorios_usados.size());
        for(set<int>::iterator i = laboratorios_usados.begin(); i != laboratorios_usados.end() ; i++){
            int p = *i;printf("El laboratorio %d\n",p);
        }
    }

    return;
}

void semillero(){
    for (int i = 0; i<3 ; ++i){
        printf("La sala de semillero #%d tuvo la siguiente agenda\n",i);
        for(asr::iterator it = SS[i].agenda_sala_semilleros.begin() ; it != SS[i].agenda_sala_semilleros.end(); it++){
            ii horario = it-> X ; vector<string>   p = it -> Y ;
            for(int ii =0; ii<p.size();ii++){
                    printf("De %d:00hr  hasta %d:00hr estuvo el semillero %s\n",horario.first,horario.second,p[ii].c_str());
            }
            puts("");
        }
        puts("");
    }
    system("pause");system("cls");
    return;
}

bool pos_admin(){
    int opcion;
    puts("Que desea conocer?");
    while(1){
        puts("1) Informe total.");
        puts("2) Reuniones");
        puts("3) Semillero.");
        puts("4) Volver a menu");
        puts("5) Salir");
        printf("Digite su opcion : ");scanf("%d",&opcion);
        switch(opcion){
            case 1:
                informe_total();
                break;
            case 2:
                reuniones();
                break;
            case 3:
                semillero();
                break;
            case 4:
                system("cls");return false;
            case 5:
                system("cls");return true;
            default:
                puts("La opcion que digito no aparece en las propuestas.");
                system("pause");system("cls");
                break;
        }
    }
}

bool admin(){
    puts("Bienvenido a la parte adminitrativa");
    string cuenta,str2("admin");
    // Se va a validar si el verdadero admin, para ello tiene 3 intentos para login
    int intentos=3,clave;
    bool seguridad = false;
    while(intentos!=0){
        puts("Digite cuenta y clave");
        printf("Cuenta : ");cin >> cuenta;
        printf("Clave : ");scanf("%d",&clave);
        system("cls");
         if(!cuenta.compare(str2) && clave == 123)
            break;
        else{ intentos--;
            puts("ERROR CLAVE O CUENTA INCORRECTA");
        }
    }
    system("cls");
    if(intentos>0)return pos_admin();
    else{
        puts("Usted no es el admin se le expulsara del programa");
        seguridad  = true;
        return seguridad;
    }
}

void ini(){
    //SR.clear();
    univer_ex.clear();
    laboratorios_usados.clear();
    LD.clear();
    LD.assign(6,laboratorios_dispo());// 6 laboratorios disponibles
    for(int i = 0 ; i < 6 ; i++){
        LD[i].nombre_lab = "Laboratorio" ;
        LD[i].cost = 0;
		LD[i].cupo = 5;
        LD[i].universidades_ext.clear();

        memset(LD[i].dispo_horario , 0 , sizeof LD[i].dispo_horario);
        LD[i].resumen_dia.clear();
    }

    SR.assign(3,sala_reunion()); // 3 Salas de reuniones disponibles
    SS.assign(3,sala_semillero()); // 3 Salas de reuniones disponibles
    for(int i =  0 ; i < 3 ; i++){
            memset(SR[i].dis_horario , 0 , sizeof SR[i].dis_horario);
            memset(SS[i].dis_horario , 0 , sizeof SR[i].dis_horario);
    }
    return;
}

int main(){
    LC_LL();
    int opcion_inicio;
    bool salir = false;
    string nombre;
    ini();
    while(1){
        system("cls");
        puts("Bienvenido Sistema de informacion para la asignacion de recursos\nComplejo de laboratorios Bloque I");
        printf("Digite su nombre  : ");scanf("%s",&nombre);
        printf("Opciones\n Digita el numeral de la opcion que crea pertinente para usted\n");
        puts("1) Ver horarios de laboratorios dispuestos para clase.");
        puts("2) Préstamo de los laboratorios de práctica libre");
        puts("3) Las salas de semillero.");
        puts("4) Las salas de reuniones.");
        puts("5) Admin");
        puts("6) Salir");
        printf("Digite su opcion %s : ",nombre);scanf("%d",&opcion_inicio);
        switch(opcion_inicio){
            case 1:
                system("cls");
                hor();
                break;
            case 2:
                system("cls");
                prestamos_lab();
                break;
            case 3:
                system("cls");
                salas_semillero();
                break;
            case 4:
                system("cls");
                salas_reuniones();
                break;
            case 5:
                salir  = admin();
                break;
            case 6:
                printf("Gracias por utilizar nuestro sistema de informacion\n");
                salir = true;
                break;
            default:
                puts("La opcion que digito no aparece en las propuestas.");
                system("pause");system("cls");
                break;
        }
        if(salir==true)break;/*Termina el programa*/
    }
    return 0;
}

