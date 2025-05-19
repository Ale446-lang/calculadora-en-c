#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 10
// ejercicio 1)

int leer_entero() {
    int numero;
    int ok = 0;

    while(ok!=1){
        if (scanf("%d", &numero) == 1) {
            ok = 1;
        } else {
            printf("No ingreso numeros.\nIngrese un numero.\n");
            while (getchar() != '\n');
        }
    }

    return numero;
}

float leer_float() {
    float numero;
    int ok = 0;

    while(ok!=1){
        if (scanf("%f", &numero) == 1) {
            ok = 1;
        } else {
            printf("No ingreso numeros.\nIngrese un numero.\n");
            while (getchar() != '\n');
        }
    }

    return numero;
}

void sumar() {
    int suma = 0, n1, i;

    printf("Ingrese la cantidad de numeros que desee sumar: ");
    n1 = leer_entero();

    int vector1[n1];

    for (i = 0; i < n1; i++) {
        printf("Ingrese un numero: ");
        vector1[i] = leer_entero();
    }

    for (i = 0; i < n1; i++) {
        suma += vector1[i];
    }

    printf("El resultado de la suma de los elementos es: %d\n", suma);
}

void restar() {
    int n2, i, resta;

    printf("Ingrese la cantidad de numeros que desee restar: ");
    n2 = leer_entero();

    int vector2[n2];

    for (i = 0; i < n2; i++) {
        printf("Ingrese un numero: ");
        vector2[i] = leer_entero();
    }

    resta = vector2[0];
    for (i = 1; i < n2; i++) {
        resta -= vector2[i];
    }

    printf("El resultado de la resta es: %d\n", resta);
}

void multiplicar(){
    int multiplicacion = 1, n5, i;

    printf("Ingrese la cantidad de numeros que desee multiplicar: ");
    n5 = leer_entero();

    int vector5[n5];

    for (i=0;i<n5;i++) {
        printf("Ingrese un numero: ");
        vector5[i] = leer_entero();
    }

    for (i=0;i<n5;i++) {
        multiplicacion*=vector5[i];
    }

    printf("El resultado de la multiplicacion de los elementos es: %d\n", multiplicacion);
}

void dividir(){
	
	float n6, divisor, division;
	
	printf("Ingrese el dividendo: ");
	n6 = leer_float();
	
	
	do{
		
	printf("Ingrese el divisor: ");
	divisor = leer_float();
	
	if(divisor==0){
		printf("No se puede dividir entre 0. Ingrese nuevamente un numero distinto a 0.");
	}
	
	}while(divisor==0);
	
	division = n6 / divisor;
	
	printf("El resultado de la division es: %f", division);
}

void potenciar() {
    int pot, n3, potencia;

    printf("Ingrese un numero: ");
    n3 = leer_entero();

    printf("Ingrese la potencia que desea de ese numero: ");
    pot = leer_entero();

    potencia = pow(n3, pot);

    printf("El resultado de la potencia es: %d\n", potencia);
}

void raiz() {
    float raizz;
    int n4, subind;

    printf("Ingrese un numero: ");
    n4 = leer_entero();

    printf("Ingrese la raiz que desea de ese numero: ");
    subind = leer_entero();

    if (subind <= 0) {
        printf("El indice de la raiz debe ser mayor a 0.\n");
        return;
    }

    raizz = pow(n4, 1.0 / subind);
    printf("El resultado de la raiz de ese numero es: %f\n", raizz);
}

// ejercicio 2)

int ingresarVectorDouble(double *vector, int n) {
    printf("Ingrese los elementos del vector:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        if (scanf("%lf", &vector[i]) != 1) {
            printf("Error: Entrada invalida. Debe ingresar un numero.\n");
            while (getchar() != '\n');
            return 0;
        }
    }
    return 1;
}


void mostrarVectorDouble(const double *vector, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%.2f", vector[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}


double* sumarMultiplesVectoresDouble(double **vectores, int cantidad, int n) {
    double *resultado = (double*)malloc(n * sizeof(double));
    if (resultado == NULL) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        resultado[i] = 0.0;
    }
    for (int i = 0; i < cantidad; i++) {
        for (int j = 0; j < n; j++) {
            resultado[j] += vectores[i][j];
        }
    }
    return resultado;
}


double* restarMultiplesVectoresDouble(double **vectores, int cantidad, int n) {
    if (cantidad < 2) {
        printf("Se necesitan al menos 2 vectores para la resta.\n");
        return NULL;
    }
    double *resultado = (double*)malloc(n * sizeof(double));
    if (resultado == NULL) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
 
    for (int i = 0; i < n; i++) {
        resultado[i] = vectores[0][i];
    }
  
    for (int i = 1; i < cantidad; i++) {
        for (int j = 0; j < n; j++) {
            resultado[j] -= vectores[i][j];
        }
    }
    return resultado;
}


double* multiplicarEscalarVectorDouble(double escalar, double *vector, int n) {
    double *resultado = (double*)malloc(n * sizeof(double));
    if (resultado == NULL) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++) {
        resultado[i] = escalar * vector[i];
    }
    return resultado;
}


double productoEscalarDouble(double *vector1, double *vector2, int n) {
    double resultado = 0.0;
    for (int i = 0; i < n; i++) {
        resultado += vector1[i] * vector2[i];
    }
    return resultado;
}


double* productoVectorialDouble(double *vector1, double *vector2) {
    double *resultado = (double*)malloc(3 * sizeof(double));
    if (resultado == NULL) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    resultado[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    resultado[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    resultado[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];
    return resultado;
}

// ejercicio 3)

void cargarMatriz(int f, int c, int m[MAX][MAX], char nombre) {
    printf("\nCargar matriz %c:\n", nombre);
    for (int i=0;i<f;i++) {
        for (int j=0;j<c;j++) {
            printf("Ingrese [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void imprimirMatriz(int f, int c, float m[MAX][MAX]) {
    for (int i=0;i<f;i++) {
        for (int j=0;j<c;j++) {
            printf("%.2f ", m[i][j]);
        }
        printf("\n");
    }
}

void imprimirMatrizInt(int f, int c, int m[MAX][MAX]) {
    for (int i=0;i<f;i++) {
        for (int j=0;j<c;j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void sumar(int f, int c, int a[MAX][MAX], int b[MAX][MAX], int r[MAX][MAX]) {
    for (int i=0;i<f;i++) {
        for (int j=0;j<c;j++) {
            r[i][j] = a[i][j] + b[i][j];
        }
    }
}

void restar(int f, int c, int a[MAX][MAX], int b[MAX][MAX], int r[MAX][MAX]) {
    for (int i=0;i<f;i++) {
        for (int j=0;j<c;j++) {
            r[i][j] = a[i][j] - b[i][j];
        }
    }
}

void escalar(int f, int c, int m[MAX][MAX], int e, int r[MAX][MAX]) {
    for (int i=0;i<f;i++) {
        for (int j=0;j<c;j++) {
            r[i][j] = m[i][j] * e;
        }
    }
}

int determinante2x2(int m[MAX][MAX]) {
    return m[0][0]*m[1][1] - m[0][1]*m[1][0];
}

int determinante3x3(int m[MAX][MAX]) {
    int a = m[0][0], b = m[0][1], c = m[0][2];
    int d = m[1][0], e = m[1][1], f = m[1][2];
    int g = m[2][0], h = m[2][1], i = m[2][2];
    return a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);
}

int inversa2x2(int m[MAX][MAX], float inv[MAX][MAX]) {
    int det = determinante2x2(m);
    if (det == 0) return 0;

    inv[0][0] = m[1][1]/(float)det;
    inv[0][1] = -m[0][1]/(float)det;
    inv[1][0] = -m[1][0]/(float)det;
    inv[1][1] = m[0][0]/(float)det;
    return 1;
}

void multiplicarMatrices(int f1, int c1, int f2, int c2, int A[MAX][MAX], float B[MAX][MAX], float R[MAX][MAX]) {
    for (int i=0;i<f1;i++) {
        for (int j=0;j<c2;j++) {
            R[i][j] = 0;
            for (int k=0;k<c1;k++) {
                R[i][j] += A[i][k] * B[k][j];
            }      
        }
    }
}

void dividirMatrices(int f, int c, int A[MAX][MAX], int B[MAX][MAX], float R[MAX][MAX]) {
    float inv[MAX][MAX];
    if (!inversa2x2(B, inv)) {
        printf("No se puede dividir (B no tiene inversa).\n");
        return;
    }
    multiplicarMatrices(f, c, f, c, A, inv, R);
}

void multiplicacionEntreMatrices(int f1, int c1, int f2, int c2, int A[MAX][MAX], int B[MAX][MAX], int R[MAX][MAX]) {
    for (int i=0;i<f1;i++) {
        for (int j=0;j<c2;j++) {
            R[i][j] = 0;
            for (int k=0;k<c1;k++) {
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// ejercicio 4)

void sustitucion_2x2(){
    float a1, b1, d1;
    float a2, b2, d2;
    float x, y;

    printf("\nmetodo de sustitucion (2x2)\n");
    printf("Ecuacion 1: a1x + b1y = d1\n");
    printf("Ingrese a1, b1, d1: ");
    scanf("%f %f %f", &a1, &b1, &d1);

    printf("Ecuación 2: a2x + b2y = d2\n");
    printf("Ingrese a2, b2, d2: ");
    scanf("%f %f %f", &a2, &b2, &d2);

    float numerador = a2*d1 - a2*b1*y;
    float denominador = a1;
    
    y = (d2*a1-a2*d1) / (b2*a1-a2*b1);
    x = (d1-b1*y) / a1;

    printf("x = %.2f\n",x);
    printf("y = %.2f\n",y);
}

void eliminacion_2x2(){
    float a1, b1, d1;
    float a2, b2, d2;
    float x, y;

    printf("Ingrese los valores de la primera ecuacion (a1 b1 d1): ");
    scanf("%f %f %f", &a1, &b1, &d1);

    printf("Ingrese los valores de la segunda ecuacion (a2 b2 d2): ");
    scanf("%f %f %f", &a2, &b2, &d2);

    float divisor = a1;
    if (divisor == 0) {
        printf("Error: division por cero.\n");
        return;
    }
    a1 /= divisor;
    b1 /= divisor;
    d1 /= divisor;

    float f2 = a2;
    
    a2 -= f2 * a1;
    b2 -= f2 * b1;
    d2 -= f2 * d1;
 
    divisor = b2;
    if (divisor == 0) {
        printf("Error: division por cero.\n");
        return;
    }
    b2 /= divisor;
    d2 /= divisor;

    f2 = b1;
    
    b1 -= f2 * b2;
    d1 -= f2 * d2;

	x = d1;
	y = d2;

    printf("x = %.2f\n",x);
    printf("y = %.2f\n",y);
}

void eliminacion_3x3() {
    float a1, b1, c1, d1;
    float a2, b2, c2, d2;
    float a3, b3, c3, d3;
    float x, y, z;

    printf("Ingrese los valores de la primera ecuacion (a1 b1 c1 d1): ");
    scanf("%f %f %f %f", &a1, &b1, &c1, &d1);

    printf("Ingrese los valores de la segunda ecuacion (a2 b2 c2 d2): ");
    scanf("%f %f %f %f", &a2, &b2, &c2, &d2);

    printf("Ingrese los valores de la tercera ecuacion (a3 b3 c3 d3): ");
    scanf("%f %f %f %f", &a3, &b3, &c3, &d3);

    float divisor = a1;
    if (divisor == 0){
	printf("Error: division por cero.\n");
	return;
	}
    a1 /= divisor;
	b1 /= divisor;
	c1 /= divisor;
	d1 /= divisor;

    float f2 = a2;
    
    a2 -= f2 * a1;
	b2 -= f2 * b1;
	c2 -= f2 * c1;
	d2 -= f2 * d1;

    float f3 = a3;
    
	a3 -= f3 * a1;
	b3 -= f3 * b1;
	c3 -= f3 * c1;
	d3 -= f3 * d1;

    divisor = b2;
    if (divisor == 0){
	printf("Error: division por cero.\n");
	return;
	}
	b2 /= divisor;
	c2 /= divisor;
	d2 /= divisor;
	
    float f31 = b3;
    
    a3 -= f31 * a2;
	b3 -= f31 * b2;
	c3 -= f31 * c2;
	d3 -= f31 * d2;

	divisor = c3;
    if(divisor == 0){
	printf("Error: division por cero.\n");
	return;
	}
	c3 /= divisor;
	d3 /= divisor;

    z = d3;
    y = d2 - c2*z;
	x = d1 - b1*y - c1*z;

    printf("x = %.2f\n",x);
    printf("y = %.2f\n",y);
    printf("z = %.2f\n",z);
}

int main() {
	int opcion;
	int opc;
	do{
		printf("\n-----------------CALCULADORA-----------------\n\n");
		printf("1. Realizar operaciones aritmeticas.\n");
        printf("2. operaciones con vectores.\n");
        printf("3. operaciones con matrices.\n");
        printf("4. sistemas de ecuaciones de 2x2 y 3x3.\n");
        printf("5. salir.\n");
        printf("ingrese una opcion:\n");
        scanf("%d",&opcion);
        
		switch(opcion){
			case 1:
			    do {
			    	printf("\n-------------------------------------------\n\n");
			        printf("1. Realizar suma de numeros.\n");
			        printf("2. Realizar resta de numeros.\n");
			        printf("3. Realizar multiplicacion de numeros.\n");
			        printf("4. Realizar division de numeros.\n");
			        printf("5. Realizar potencia de numeros.\n");
			        printf("6. Realizar raiz de numeros.\n");
			        printf("7. atras.\n");
			
			        printf("Ingrese una opcion del menu: ");
			        opc = leer_entero();
			
			        switch (opc) {
			            case 1:
			                sumar();
			                break;
			
			            case 2:
			                restar();
			                break;
			
			            case 3:
			                multiplicar(); 
			                break;
			
			            case 4:
			                dividir();
			                break;
			                
			            case 5:
			            	potenciar();
			            	break;
			            
			            case 6:
			            	raiz();
			            	break;
			
			            case 7:
			                printf("\n");
			                break;
			
			            default:
			                printf("Opcion no valida.\nIngrese nuevamente una opcion:\n");
			                break;
			        }
			
			    } while (opc != 7);
			    break;
			case 2: {
				int n;
			    int cantidad_vectores;
			    int opcion2;
			    double **vectores = NULL; 
			    double *resultado_vector = NULL;
			    double escalar;
			    double resultado_escalar;
			
			    printf("Ingrese la dimension de los vectores: ");
			    if (scanf("%d", &n) != 1 || n <= 0) {
			        printf("Error: Dimension invalida. Debe ingresar un numero entero positivo.\n");
			        return 1;
			    }
			    while (getchar() != '\n');
			
			    printf("Ingrese la cantidad de vectores con los que desea operar: ");
			    if (scanf("%d", &cantidad_vectores) != 1 || cantidad_vectores <= 0) {
			        printf("Error: Cantidad de vectores invalida. Debe ingresar un numero entero positivo.\n");
			        return 1;
			    }
			    while (getchar() != '\n');
			
			  
			    vectores = (double**)malloc(cantidad_vectores * sizeof(double*));
			    if (vectores == NULL) {
			        perror("Error al asignar memoria");
			        return 1;
			    }
			
			    
			    for (int i = 0; i < cantidad_vectores; i++) {
			        vectores[i] = (double*)malloc(n * sizeof(double));
			        if (vectores[i] == NULL) {
			            perror("Error al asignar memoria");
			            for (int j = 0; j < i; j++) {
			                free(vectores[j]);
			            }
			            free(vectores);
			            return 1;
			        }
			        printf("\nIngrese los datos del vector %d:\n", i + 1);
			        if (!ingresarVectorDouble(vectores[i], n)) {
			            for (int j = 0; j <= i; j++) {
			                free(vectores[j]);
			            }
			            free(vectores);
			            return 1;
			        }
			    }
			
			    printf("\nVectores ingresados:\n");
			    for (int i = 0; i < cantidad_vectores; i++) {
			        printf("Vector %d: ", i + 1);
			        mostrarVectorDouble(vectores[i], n);
			    }
			
			    do {
			    	printf("\n-------------------------------------------\n\n");
			        printf("\nSeleccione la operacion a realizar:\n");
			        printf("1. Suma de los vectores\n");
			        printf("2. Resta de los vectores \n");
			        printf("3. Multiplicacion de escalar por un vector (seleccionar vector)\n");
			        printf("4. Producto escalar del primer vector con el segundo\n");
			        if (n == 3 && cantidad_vectores >= 2) {
			            printf("5. Producto vectorial del primer vector con el segundo\n");
			        }
			        printf("0. atras\n");
			        printf("Ingrese su opcion: ");
			        if (scanf("%d", &opcion2) != 1) {
			            printf("Error: Entrada invalida. Debe ingresar un numero entero.\n");
			            while (getchar() != '\n');
			            opcion2 = -1;
			            continue;
			        }
			        while (getchar() != '\n');
			
			        switch (opcion2) {
			            case 1:
			                resultado_vector = sumarMultiplesVectoresDouble(vectores, cantidad_vectores, n);
			                printf("Suma de los vectores: ");
			                mostrarVectorDouble(resultado_vector, n);
			                free(resultado_vector);
			                break;
			            case 2:
			                if (cantidad_vectores >= 2) {
			                    resultado_vector = restarMultiplesVectoresDouble(vectores, cantidad_vectores, n);
			                    if (resultado_vector != NULL) {
			                        printf("Resta secuencial de los vectores: ");
			                        mostrarVectorDouble(resultado_vector, n);
			                        free(resultado_vector);
			                    }
			                } else {
			                    printf("Se necesitan al menos 2 vectores para la resta.\n");
			                }
			                break;
			            case 3:
			                int indice_vector;
			                printf("Ingrese el indice del vector (1 a %d): ", cantidad_vectores);
			                if (scanf("%d", &indice_vector) != 1 || indice_vector < 1 || indice_vector > cantidad_vectores) {
			                    printf("Error: Indice de vector invalido.\n");
			                    while (getchar() != '\n');
			                    break;
			                }
			                while (getchar() != '\n');
			                printf("Ingrese el escalar para multiplicar: ");
			                if (scanf("%lf", &escalar) != 1) {
			                    printf("Error: Entrada invalida. Debe ingresar un numero.\n");
			                    while (getchar() != '\n');
			                    break;
			                }
			                while (getchar() != '\n');
			                resultado_vector = multiplicarEscalarVectorDouble(escalar, vectores[indice_vector - 1], n);
			                printf("Producto del escalar %.2f por el Vector %d: ", escalar, indice_vector);
			                mostrarVectorDouble(resultado_vector, n);
			                free(resultado_vector);
			                break;
			            case 4:
			                if (cantidad_vectores >= 2) {
			                    resultado_escalar = productoEscalarDouble(vectores[0], vectores[1], n);
			                    printf("Producto escalar del Vector 1 y Vector 2: %.2f\n", resultado_escalar);
			                } else {
			                    printf("Se necesitan al menos 2 vectores para el producto escalar.\n");
			                }
			                break;
			            case 5:
			                if (n == 3 && cantidad_vectores >= 2) {
			                    resultado_vector = productoVectorialDouble(vectores[0], vectores[1]);
			                    printf("Producto vectorial del Vector 1 y Vector 2: ");
			                    mostrarVectorDouble(resultado_vector, 3);
			                    free(resultado_vector);
			                } else {
			                    printf("El producto vectorial solo se calcula para vectores de 3 dimensiones y se necesitan al menos 2 vectores.\n");
			                }
			                break;
			            case 0:
			            	printf("\n");
			                break;
			            default:
			                printf("Opcion invalida. Por favor, intente de nuevo.\n");
			        }
			    } while (opcion2 != 0);
			
			    
			    for (int i = 0; i < cantidad_vectores; i++) {
			        free(vectores[i]);
			    }
			    free(vectores);
				break;
				}
			case 3: {
				int op, f, c, esc;
			    int A[MAX][MAX], B[MAX][MAX], R[MAX][MAX];
			    float invB[MAX][MAX], resDiv[MAX][MAX];
			
			    do {
			    	printf("\n-------------------------------------------\n\n");
			        printf("0 - atras\n");
			        printf("1 - Suma\n2 - Resta\n3 - Multiplicacion por escalar\n");
			        printf("4 - Determinante (2x2 o 3x3)\n");
			        printf("5 - Inversa (solo 2x2)\n");
			        printf("6 - Division de matrices (A * inv(B), solo 2x2)\n");
			        printf("7 - Multiplicacion entre matrices\n\n");
			        printf("Elegi una opcion: \n");
			        scanf("%d", &op);
			
			        switch (op) {
			            case 0:
			                printf("\n");
			                break;
			
			            case 1:
			                printf("Filas (max %d): ", MAX);
			                scanf("%d", &f);
			                printf("Columnas (max %d): ", MAX);
			                scanf("%d", &c);
			                if (f<=0 || c<=0 || f>MAX || c>MAX) {
			                    printf("Tamaño invalido.\n");
			                    break;
			                }
			                cargarMatriz(f, c, A, 'A');
			                cargarMatriz(f, c, B, 'B');
			                sumar(f, c, A, B, R);
			                printf("\nResultado (A + B):\n");
			                imprimirMatrizInt(f, c, R);
			                break;
			
			            case 2:
			                printf("Filas (max %d): ", MAX);
			                scanf("%d", &f);
			                printf("Columnas (max %d): ", MAX);
			                scanf("%d", &c);
			                if (f<=0 || c<=0 || f>MAX || c>MAX) {
			                    printf("Tamaño inválido.\n");
			                    break;
			                }
			                cargarMatriz(f, c, A, 'A');
			                cargarMatriz(f, c, B, 'B');
			                restar(f, c, A, B, R);
			                printf("\nResultado (A - B):\n");
			                imprimirMatrizInt(f, c, R);
			                break;
			
			            case 3:
			                printf("Filas (max %d): ", MAX);
			                scanf("%d", &f);
			                printf("Columnas (max %d): ", MAX);
			                scanf("%d", &c);
			                if (f<=0 || c<=0 || f>MAX || c>MAX) {
			                    printf("Tamaño invalido.\n");
			                    break;
			                }
			                cargarMatriz(f, c, A, 'A');
			                printf("Escalar: ");
			                scanf("%d", &esc);
			                escalar(f, c, A, esc, R);
			                printf("\nResultado (A * %d):\n", esc);
			                imprimirMatrizInt(f, c, R);
			                break;
			
			            case 4:
			                printf("Tamaño (solo 2 o 3): ");
			                scanf("%d", &f);
			                c = f;
			                if (f != 2 && f != 3) {
			                    printf("Solo funciona con matrices 2x2 o 3x3.\n");
			                    break;
			                }
			                cargarMatriz(f, c, A, 'A');
			                if (f == 2)
			                    printf("\nDeterminante: %d\n", determinante2x2(A));
			                else
			                    printf("\nDeterminante: %d\n", determinante3x3(A));
			                break;
			
			            case 5:
			                printf("Tamaño (solo 2x2): ");
			                scanf("%d", &f);
			                c = f;
			                if (f != 2) {
			                    printf("Solo se puede con 2x2.\n");
			                    break;
			                }
			                cargarMatriz(2, 2, A, 'A');
			                if (inversa2x2(A, invB)) {
			                    printf("\nInversa de A:\n");
			                    imprimirMatriz(2, 2, invB);
			                } else {
			                    printf("No tiene inversa (det=0).\n");
			                }
			                break;
			
			            case 6:
			                printf("Tamaño (solo 2x2): ");
			                scanf("%d", &f);
			                c = f;
			                if (f != 2) {
			                    printf("Solo se puede con 2x2.\n");
			                    break;
			                }
			                cargarMatriz(2, 2, A, 'A');
			                cargarMatriz(2, 2, B, 'B');
			                dividirMatrices(2, 2, A, B, resDiv);
			                printf("\nResultado (A * inv(B)):\n");
			                imprimirMatriz(2, 2, resDiv);
			                break;
			
			            case 7: {
			                int f2, c2;
			                printf("Filas de A: ");
			                scanf("%d", &f);
			                printf("Columnas de A (y filas de B): ");
			                scanf("%d", &c);
			                printf("Columnas de B: ");
			                scanf("%d", &c2);
			                if (f <= 0 || c <= 0 || c2 <= 0 || f > MAX || c > MAX || c2 > MAX) {
			                    printf("Tamaño invalido.\n");
			                    break;
			                }
			                cargarMatriz(f, c, A, 'A');
			                cargarMatriz(c, c2, B, 'B');
			                multiplicacionEntreMatrices(f, c, c, c2, A, B, R);
			                printf("\nResultado (A * B):\n");
			                imprimirMatrizInt(f, c2, R);
			                break;
			            }
			
			            default:
			                printf("Opcion invalida.\n");
			        }
			
			    } while (op != 0);
				break;
			}
			case 4: {
				int opcion4;
				
			    do {
			        printf("\nSeleccione el metodo:\n");
			        printf("1. Sustitucion (2x2)\n");
			        printf("2. Eliminacion (2x2 o 3x3)\n");
			        printf("3. atras\n");
			        printf("Opcion: ");
			        scanf("%d", &opcion4);
			
			        switch (opcion4) {
			            case 1:
			                sustitucion_2x2();
			                break;
			
			            case 2: {
			                int n;
			                printf("Ingrese numero de incognitas (2 o 3): ");
			                scanf("%d", &n);
			
			                switch (n) {
			                    case 2:
			                        eliminacion_2x2();
			                        break;
			                    case 3:
			                        eliminacion_3x3();
			                        break;
			                    default:
			                        printf("numero invalido.\n");
			                        break;
			                }
			                break;
			            }
			            case 3:
			                printf("\n");
			                break;
			
			            default:
			                printf("Opcion invalida.\n");
			                break;
			        }
			
			    } while (opcion4 != 3);
				break;
			}
			case 5:
				printf("saliendo del programa...");
				break;
		}
	}while(opcion != 5);
	return 0;			
}				
				