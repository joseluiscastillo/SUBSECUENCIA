#include <cstdlib>
#include <iostream>

using namespace std;
#include<stdio.h>
#include<string.h>
 
int i,j,m,n,c[20][20];
char x[20],y[20],b[20][20];
 
void print(int i,int j)
{//Esta es una funcion recursiva que controla su funcionamiento a traves de los valores de i y j
                if(i==0 || j==0) //Si i o j igual a 0, entoces termina la ejecución recursiva de la función.
                                return;
                if(b[i][j]=='c')
                {//si la casilla de la matriz b en la posiciòn i,j es igual a cero, entonces
                                print(i-1,j-1);//Esta funcion se llama de forma recursiva a si misma, restándole 1 a i y 1 a j para que estas variables lleguen a cero y termine la ejecución del proceso recursivo.
                                printf("%c",x[i-1]);//Imprime el valor del vector x en la fila i-1
                }
                else if(b[i][j]=='u') //Sino, si la casilla de la fila i, columna j es igual al caràcter 'u' entonces
                                print(i-1,j);//Se llama a si mism y le resta 1 al valor de i
                else//Sino
                                print(i,j-1);//Se llama a si misma y le resta 1 al valor de j
}
 
void lcs()
{
                m=strlen(x);//Calcula la longitud de x
                n=strlen(y);//Calcula la longitud de y
                for(i=0;i<=m;i++) //hace un ciclo desde 0 hasta la longitud m de la cadena x 
                                c[i][0]=0;//llena de ceros las filas de la columna 0 de la matriz c
                for(i=0;i<=n;i++)//hace un ciclo desde 0 hasta la longitud n de la cadena y 
                                c[0][i]=0;//llena de ceros las filas de la columna 1 de la matriz c
                                
                //c, u and l denotes cross, upward and downward directions respectively
                for(i=1;i<=m;i++)//hace un ciclo desde 1 hasta la longitud m de la cadena x 
                                for(j=1;j<=n;j++)//hace un ciclo desde 0 hasta la longitud n de la cadena y 
                                {
                                                if(x[i-1]==y[j-1])
                                                {//Si la posicion i-esima posición anterior (i-1) del 
                                                //vector x es igual a la j-esima posición anterior del 
                                                //vector y, entonces 
                                                
                                                                c[i][j]=c[i-1][j-1]+1; //el contenido de la casilla de la matriz c 
                                                                //en la fila i columna j, se hace igual al contenido de la fila y columna anterior + 1, 
                                                                //es decir, se van en reversa en diagonal de abajo derecha hacia arriba izquierda.
                                                                
                                                                b[i][j]='c';//La casilla de la matriz b, en la posicion fila i, columna j se hace igual al carater 'c'
                                                                
                                                }
                                                else if(c[i-1][j]>=c[i][j-1])
                                                {//Sino son iguales, evalua si la casilla de la matriz c en fila anterior (i-1) columna actual j, es igual a la casilla 
                                                //de la fila actual (i) columna anterior (j-1)

                                                                c[i][j]=c[i-1][j];//La casilla actual i,j, se hace igual al contenido de la casilla de la fila anterior (i-1) con la columna actual (j).
                                                                b[i][j]='u';//La matriz b en la fila y columna actual i,j la hace igual al carácter 'u'
                                                }
                                                else
                                                {//Sino 
                                                                c[i][j]=c[i][j-1];//La casilla de la posición actual de la matriz c , fila i, columna j, se hace igual a la posiciòn de la casilla ubicada en
                                                                                 //la posición fila i, columna anterior j-1 
                                                                b[i][j]='l';//La casilla de la matriz b en la posiciòn actual se hace igual al caràcter 'l'
                                                }//Fin else
                                }//fin ciclo
}
 
int main()
{
                printf("POR FAVOR INGRESE LA PRIMERA SECUENCIA:");
                scanf("%s",x);//Le la primera secuencia de caracteres. Valores de prueba: ACFGHD
                printf("POR FAVOR INGRESE LA SEGUNDA SECUENCIA:");
                scanf("%s",y);//Lee la secunda secuencia de caracteres. Valores de prueba: ABFHD
                printf("\nLA SUBSECUENCIA COMUN MAS LARGA ES: ");
                lcs();//llama la funcion de que calcula la subsecuencia comun
                print(m,n);//Llama la funcion recursiva. 
                //Con los valores ingresados, da como resultado AFHD
                cout<<"\n\n";
                system("PAUSE");//Hace una pausa.
                return EXIT_SUCCESS;
                
        return 0;
}

