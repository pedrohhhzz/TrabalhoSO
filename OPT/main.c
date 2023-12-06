#include <stdio.h>


    #include <windows.h>




int main()
{
    int numeroframes, numeropaginas,  paginas[30],frames[10], temp[10], flag1, flag2, flag3, i, j, k, pos, max, falhas = 0;
    
    
   //inserir o numero de paginas e frames 
    printf("insira um numero de  frames: ");
    scanf("%d", &numeroframes);
    
    printf("insira o numero de paginas: ");
    scanf("%d", &numeropaginas);
    
    printf("insira uma pagina de referencia: ");
    
    
    for(i = 0; i < numeropaginas; ++i){ 
        scanf("%d", &paginas[i]);
    }
    
    
    
    for(i = 0; i < numeroframes; ++i){
        frames[i] = -1;
    }
    
    
    
    for(i = 0; i < numeropaginas; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < numeroframes; ++j){
            if(frames[j] == paginas[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < numeroframes; ++j){
                if(frames[j] == -1){
                    falhas++;
                    frames[j] = paginas[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
         flag3 =0;
        
            for(j = 0; j < numeroframes; ++j){
             temp[j] = -1;
            
             for(k = i + 1; k < numeropaginas; ++k){
             if(frames[j] == paginas[k]){
             temp[j] = k;
             break;
             }
             }
            }
            
            for(j = 0; j < numeroframes; ++j){
             if(temp[j] == -1){
             pos = j;
             flag3 = 1;
             break;
             }
            }
            
            if(flag3 ==0){
             max = temp[0];
             pos = 0;
            // Se não houver frame vazio, procura o frame com a página que será acessada mais tarde no futuro
             for(j = 1; j < numeroframes; ++j){
             if(temp[j] > max){
             max = temp[j];
             pos = j;
             }
             }            
            }
frames[pos] = paginas[i];
falhas++;
        }
        
        printf("\n");
        
        for(j = 0; j < numeroframes; ++j){
            printf("%d\t", frames[j]);
        }
    }
    
    printf("\n\nTotal de falhas de paginas = %d", falhas); //contar numero de falhas
    
    return 0;
}
