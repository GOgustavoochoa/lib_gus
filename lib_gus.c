#include "lib_gus.h"

int aux,corte,i,j;
void vordshell(float *v, int tam){
    for(corte=tam/2;corte>0;corte/=2){
        for(i=corte;i<tam;i++){
           aux=v[i];
           for(j=i;j>=corte;j=j-corte){
            if(v[j-corte]>aux){
                v[j]=v[j-corte];
            }else{
                break;
            }
           }
        v[j]=aux;
        }
    }
}
void vordbubble(float *v, int tam){
    for(j=tam-1;j>0;j--){
        for(i=0;i<tam;i++){
            if(v[i+1]<v[i]){
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
            }
        }
    }

}
void vbusqueda(float *v,int tam,int num){
    int der=tam, izq=0,x;
    do{
        x=(izq+der)/2;

        if(v[x]>num){
            der=x-1;
        }else if(v[x]<num){
            izq=x+1;
        }

        if(v[x]==num){
            printf("SE ENCONTRO EL ELEMENTO %d EN LA POSICIÓN [%d]\n ",num,x);
            break;
        }
    }while(der>=izq);

}
void vord_busq(float *v,int tam,float num){
    //ordenamos
   vordshell(v,tam);
   //printear
   for(i=0;i<tam;i++){
    printf("[%d]:%f\n",i,v[i]);
   }
   //busqueda
   vbusqueda(v,tam,num);
   
}

//tp profe
float *re_sizefun(float *p , int n0, int nf){
    float *paux;
    paux=malloc(nf*sizeof(float));
    if(nf<n0){
        for(i=0;i<nf;i++){
            paux[i]=p[i];
        }
    }else{
        for(i=0;i<n0;i++){
            paux[i]=p[i];
        }
    }
    free(p); 
    return paux;   
}  
int *removeItem(int *p,int tam,int position_rm){
    if(position_rm >= tam || position_rm < 0){ //error, devuelvo p 
        return p;
    }
    
    int *paux; 
    paux = malloc((tam-1)*sizeof(int));

    for(i=0;i<position_rm;i++){
        paux[i]=p[i];
    }for(i=position_rm;i<tam-1;i++){
        paux[i]=p[i+1];
    }

    free(p);
    return paux;

}
int *insertItem(int *p,int tam,int insert_pos,int insert_value){
    if(insert_pos > tam || insert_pos < 0){
        return p;
    }
    int *paux;
    paux = malloc((tam+1)*sizeof(int));

    for(i=0;i<tam+1;i++){
        if(i==insert_pos){
            paux[i]=insert_value;
        }else{
            paux[i]=p[i];
        }
    }
    free(p);
    return paux;
}
int *concat(int* p1,int p1_size,int* p2,int p2_size){
    int *paux;
    int z=(p1_size+p2_size),j=0;
    paux = malloc(z*sizeof(int));

    for(i=0;i<z;i++){
        if(i>=p1_size){
            paux[i]=p2[j];
            j++;
        }else{
            paux[i]=p1[i];
        }
    }
    free(p1);
    free(p2);
    return paux;

}

//tp profe todo a procedimiento y con re_size_n (tamaño del vect en cuestion)
//mucho mas optimas...

void re_sizepro(int **p,int *n0, int nf){
    int *paux;
    paux=malloc(nf*sizeof(int));
    if(nf<*n0){
        for(i=0;i<nf;i++){
            paux[i]=(*p)[i];      //el (*p)[i] es debido a que se esta indireccionando a la direccion del puntero '**p', es decir al "vector" dinamico, por medio de su direccion enviada por parametro. 
        }
    }else{
        for(i=0;i<*n0;i++){
            paux[i]=(*p)[i];
        }
    }
    *n0 = nf;
    free(*p);
    *p=paux;
}
void removeitempro(int **p, int *tam){
    //[position_rm] Posicion en cuestion a remover (incluyendo su valor)
    int position_rm,flag=0;

    while(flag!=1){
    printf("Ingrese valor a remover:\n");
    scanf("%d",&position_rm);
    if(position_rm > *tam || position_rm < 0){
        printf("POSICION INVALIDA INGRESE OTRO VALOR\n");
    }else{
    flag=1;
    int *paux; 
    paux = malloc((*tam-1)*sizeof(int));

    for(i=0;i<position_rm;i++){
        paux[i]=(*p)[i];
    }for(i=position_rm;i<*tam-1;i++){
        paux[i]=(*p)[i+1];
    }
    *tam = (*tam-1);
    free(*p);
    *p = paux;
    }
}
}
void insertItempro(int **p,int *tam){
    int *paux,flag=0;
    //[insert_pos] Posicion del elemento a insertar
    //[insert_value] Valor a insertar
    int insert_pos, insert_value;
    paux = malloc((*tam+1)*sizeof(int));

    while(flag!=1){
        printf("Ingrese posicion a insertar:\n");
        scanf("%d",&insert_pos);
    if(insert_pos > *tam || insert_pos < 0){
        printf("POSICION INVALIDA INGRESE OTRO VALOR\n");
    }else{
    flag=1;
    printf("Ingrese el valor a insertar:\n");
    scanf("%d",&insert_value);
    for(i=0;i<*tam+1;i++){
        if(i==insert_pos){
            paux[i]=insert_value;
        }else{
            paux[i]=(*p)[i];
        }
    }
    *tam++;
    free(*p);
    *p = paux;
    }
    }
}
void concatpro(int **p1,int p1_size,int **p2,int p2_size){
    int *paux;
    int z=(p1_size+p2_size),j=0;
    paux = malloc(z*sizeof(int));

    for(i=0;i<z;i++){
        if(i>=p1_size){
            paux[i]=(*p2)[j];
            j++;
        }else{
            paux[i]=(*p1)[i];
        }
    }
    free(*p1);
    free(*p2);
    *p1 = paux;
}


//OP. BINARIAS:

void show_bin8(uint8_t n){
uint8_t mask = 1<<7;
int aux=0;
for(int i=7;i>=0;i--){
    if((n&mask)==mask){
        printf("1");
    }else{
        printf("0");
    }
    mask >>=1;
    aux++;
    
    if(aux==4 && i!=0){
        printf("-");
        aux=0;
    }
}
printf("\n");
}
void show_bin16(uint16_t n){
uint16_t mask = 1<<15;
int aux=0;
for(int i=15;i>=0;i--){
    if((n&mask)==mask){
        printf("1");
    }else{
        printf("0");
    }
    mask >>=1;
    aux++;
    
    if(aux==4 && i!=0){
        printf("-");
        aux=0;
    }
}
}
void show_bin32(uint32_t n){
uint32_t mask = 1<<31;
int aux=0;
for(int i=32;i>0;i--){
    if((n&mask)==mask){
        printf("1");
    }else{
        printf("0");
    }
    mask >>=1;
    aux++;
    
    if(aux==4 && i!=1){
        printf("-");
        aux=0;
    }
}
printf("\n");
}
void show_bin64(uint64_t n){
uint64_t mask = 1ULL<<63; //AGREGAR ESTO AL POWER XD 
int aux=0;
for(int i=64;i>0;i--){
    if((n&mask)==mask){
        printf("1");
    }else{
        printf("0");
    }
    mask >>=1;
    aux++;
    
    if(aux==4 && i!=1){
        printf("-");
        aux=0;
    }
}
printf("\n");
}
void show_hex32(uint32_t n) {
    for (int i = 7; i >= 0; i--) {
        uint8_t nibble = (n >> (i * 4)) & 0xF; //0xFF == 15 == 1111
        printf("%X ", nibble);
    }
    printf("\n");
}

uint32_t extraccion(uint32_t n_inside,int starbite, int endbite){
    if(starbite>endbite){
        printf("\nerror al ingresar parametros de extraccion...\n");
        return -1;
    }

    uint32_t suma_bite=0;
    uint32_t mask = 1<<endbite;
    
    for(int i=endbite; i>=starbite;i--){

        if((n_inside & mask) == mask){
            suma_bite |= (1<<(i-starbite));     //va sumando bites sin borrar lo que ya habia por eso va '|='
            printf("1");                        //(1<<(i-starbite)) importante ya que te va dejando los 1 donde corresponden
        }else{
            printf("0");
        }
        mask>>=1;
    }

    return suma_bite;
}

uint16_t inter_segment16(uint16_t n_inside, int nbit_rotate){
    //hay que mover los n bits menos signi. a los mas signi. y viceversa
    //primero leo los n bits menos signi.
    uint16_t MSB = 0;
    uint16_t LSB = 0;
    for(int i=0;i<nbit_rotate; i++){
        if(bin_pos16(n_inside, i)){
            LSB |= (1<<(15-nbit_rotate+1)+i);
        }
        if(bin_pos16(n_inside, (15-nbit_rotate+1)+i)){
            MSB|= (1<<i);
        }
        n_inside &= ~(1<<i);
        n_inside &= ~(1<<(15-nbit_rotate+1)+i);
    }

    n_inside |= MSB;
    n_inside |= LSB;

    return n_inside;
}

uint32_t setear_bit(uint32_t n_inside, int bit_pos, bool flag){
    uint32_t mask= 1<<bit_pos;
    if(flag == true){
        n_inside|=mask;
    }else if(flag == false){
        n_inside &= ~mask;
    }
    return n_inside;
}

uint32_t invert_bit(uint32_t n_inside, int bit_pos){
    uint32_t mask = 1<<bit_pos;
    if((n_inside & mask ) == mask){
        n_inside &= ~mask;
    }else{
        n_inside |= mask;
    }
    return n_inside;
}

uint32_t bin_rotate(uint32_t n_inside, int n_shifteos){
    //ej: 0001 1100 1000 (456)
    uint32_t acarreo;
      
    for(int i=0;i<n_shifteos;i++){
        if(n_shifteos<0){
            acarreo = n_inside & 1;
            n_inside>>=1;
            n_inside |= (acarreo << 31);
        }else{
            acarreo = (n_inside>>31) & 1;
            n_inside<<=1;
            n_inside |= acarreo;
        }
    }
    show_bin32(n_inside);
    return n_inside;
}

bool bin_pos16(uint16_t n_inside, int bit_pos){
    if (bit_pos < 0 || bit_pos > 15) {
        printf("Posición inválida\n");
        return false;
    }
    uint16_t mask = 1<<bit_pos;
    if((n_inside & mask) == mask){
        printf("1\n");
        return true;
    }else{
        printf("0\n");
        return false;
    }
}

bool bin_equality16(uint16_t n1_inside, uint16_t n2_inside, int bit_pose){
     if(bin_pos16(n1_inside, bit_pose) == true && bin_pos16(n2_inside, bit_pose) == true){
        printf("iguales");
        return true;
    }else if(bin_pos16(n1_inside, bit_pose) == false && bin_pos16(n2_inside, bit_pose) == false){
        printf("iguales");
        return true;
    }else{
        printf("naquever");
        return false;
    }
}