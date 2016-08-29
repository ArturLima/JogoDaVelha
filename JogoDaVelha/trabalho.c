#include <stdio.h> //Biblioteca para manipular entrada e saida
#include <stdlib.h>//Biblioteca com diversas operações, incluindo conversão, geração de números pseudo-aleatórios, alocação de memória, controle de processo, sinais, busca e ordenação.
#include <locale.h> // Biblioteca necessária para usar caracteres especiais
#include <conio.h> 


int vez= 1;
 
int face(void)
{
    printf(" ||====================================================================|| \n");
    printf(" ||                                                                    || \n");
    printf(" ||(@@@)==================|FACULDADE FARIAS BRITO|================(@@@)|| \n");
    printf(" ||                       '------========--------'                     || \n");
    printf(" ||             ~               // ____ \\                              || \n");
    printf(" ||             L              /  //@@) \\                              || \n");
    printf(" ||             P              || <| >\  ||                             || \n");
    printf(" ||             2              ||  |--/ ||                             || \n");
    printf(" ||                            \\   |\_/  //                             || \n");
    printf(" ||                             \\/___\_//                               || \n");
    printf(" ||                       _____/  MANHA   \________                     || \n");
    printf(" ||                     ~| LOGICA DE PROGRAMACAO2 |~                   || \n");
    printf(" ||(@@@)===================    RICARDO WAGNER    =================(@@@)|| \n");
    printf(" ||                                                                    || \n");
    printf(" ||====================================================================|| \n");
}
 
//Cabeçalho do Jogo
void titulo()
{
     
   system("title Projeto de Lógica de Programação II");
      printf("\n\t\t\t Projeto de Lógica de Programação II\t\t\t");
      printf("\n\t\t\t     Kappa Produções Apresenta");
      printf("\n\n\t\t\t\t  O Jogo Da Velha");
   
      printf("\n\n-------------------------------------------------------------------------------");
     
}

//Função para lipar a matriz
void limparjogo(int velha[][3])
{
     int linha, coluna;
     
     for(linha = 0 ; linha < 3 ; linha++)
        for(coluna =0 ; coluna < 3 ; coluna++)
            velha[linha][coluna] = 0;   
}

//Função para exibir a matriz
void exibir(int velha[][3])
{
    int linha, coluna;
    putchar('\n');
 
    for(linha = 0 ; linha < 3 ; linha++)
    {
        for(coluna = 0 ; coluna < 3; coluna++)
        {
            if(velha[linha][coluna] == 0)
            {
                printf("    ");
            }
            else
            {
                if(velha[linha][coluna] == 1)
                {
                    printf("  O ");
                }
                else
                {
                    printf("  X ");
                }
         }
            if(coluna != 2)
            {
                printf("|");
            }
        }
        putchar('\n');
    }
    putchar('\n');
} 
void jogar(int velha[][3], int vez)
{
    
    limparjogo(velha);
 
    do
    {
        exibir(velha);
        jogada(velha);
 
    }while(analisarTermino(velha, vez) != 1);
}


//Função para marcar na matriz
 int jogada(int velha[][3])
{
    int linha, coluna;
    vez= vez +1;

do
    {
        printf("Digita em qual Linha: ");
        scanf("%d", &linha);
        linha--;
 
        printf("Digite em qual Coluna: ");
        scanf("%d", &coluna);
        coluna--;
        
 if(analisarmatriz(velha, linha, coluna) == 0)
 {
            printf("Posicao ocupada ou inexistente, escolha outra.\n");
 } 
   
}while(analisarmatriz(velha, linha, coluna) == 0);

      getch();
      system("cls");
    if(vez%2)
    {
        velha[linha][coluna] = -1;
    }
    else
    {
        velha[linha][coluna] = 1;
    }
    
     }


//Função Para analisar a Matriz
int analisarmatriz(int velha[][3], int linha, int coluna)
{
   
    if(linha < 0 || linha > (3-1) || coluna < 0 || coluna > (3-1) || velha[linha][coluna] != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Função para analisar a linha da matriz 
int analisarlinha(int velha[][3])
{
   int linha,coluna, soma;
   
   for(linha = 0 ; linha < 3 ; linha++)
   {
      soma = 0;
      
      for(coluna = 0 ; coluna < 3 ; coluna++)
      {
         soma = soma + velha[linha][coluna];
         if(soma == 3 || soma == (-3))
         {
            return 1;
           }
        }
   }
   return 0;
}

//Função para analisar a coluna da matriz 
int analisarcoluna(int velha[][3])
{
   int linha,coluna, soma;
   
   for(coluna = 0 ; coluna < 3 ; coluna++)
   {
      soma = 0;
      
      for(linha = 0 ; linha < 3 ; linha++)
      {
         soma = soma + velha[linha][coluna];
         if(soma == 3 || soma == (-3))
         {
            return 1;
           }
        }
   }
   return 0;
}

//Função para analisar a diagonal principal da matriz
int analisarDiagonal(int velha[][3])
{
    int linha,
        diagonalprincipal=0,
        diagonalsecundaria=0;
 
    for(linha = 0 ; linha < 3 ; linha++)
    {
        diagonalprincipal = diagonalprincipal + velha[linha][linha];
        diagonalsecundaria = diagonalsecundaria + velha[linha][3-linha-1];
    }
 
    if(diagonalprincipal == 3 || diagonalprincipal== (-3) ||diagonalsecundaria == 3 || diagonalsecundaria == (-3))
    {
       return 1;
      }
 
    return 0;
}
int analisarEmpate(int velha[][3])
{
    int linha, coluna;
 
    for(linha = 0 ; linha < 3 ; linha++)
    { 
      for(coluna = 0 ; coluna < 3 ; coluna++)
        {
             if(velha[linha][coluna] == 0)
             {
                return 0;
               }
        }
    }
    return 1;
}
int analisarTermino(int velha[][3], int vez)
{
    if(analisarlinha(velha))
    {
        printf("Jogo encerrado. Jogador venceu !\n\n");
        exibir(velha);
        return 1;
    }
 
    if(analisarcoluna(velha))
    {
        printf("Jogo encerrado. Jogador venceu !\n\n");
        exibir(velha);
        return 1;
    }
 
    if(analisarDiagonal(velha))
    {
        printf("Jogo encerrado. Jogador venceu !\n\n");
        exibir(velha);
        return 1;
    }
 
    if(analisarEmpate(velha))
    {
        printf("Jogo encerrado. Ocorreu um empate! !\n\n");
        exibir(velha);
        return 1;
    }
 
    return 0;
}


//Menu de Opções
void menu() 
{
    int escolha,jogador;
    
    
    printf("\n Menu Principal");
      printf("\n\n 01. Play %c",16);
     printf("\n 02. Sair");   
      printf("\n\n Escolha a opção:");
      scanf("%d", &escolha);
   
   switch(escolha)
   {
            case 1:
                 printf("\n 01. 1 - Jogador");
                 printf("\n 02. 2 - Jogadores");
                 printf("\n 03. 3 - Voltar");
                 printf("\n\n Escolha a opção:");
                 scanf("%d", &jogador);
                 
                 
                 switch(jogador)
                 {
                     case 1:
                          
                        printf("\n\t\"Em Breve\".\n Pressione \"Enter\" e Tente Novamente\n");
                        getch();
                        printf("\n\n-------------------------------------------------------------------------------");
                        return menu();
                        break;
                          
                     case 2:
                          
                          printf("\n\n-------------------------------------------------------------------------------\n");
                          //jogada(velha, vez);
                          break;
                          
                          
                     case 3:
                          
                          return menu();
                     default:
                             
                             printf("\n Opção invalida. Pressione \"Enter\" e  Tenta Novamente\n");
                             getch();
                             printf("\n\n-------------------------------------------------------------------------------");
                             return menu();
                 }
                 break;
            case 2:
                 exit(0);
                 
                 break;
            
            default:
                    printf("\n Opção invalida. Pressione \"Enter\" e Tenta Novamente\n");
                    getch();
                    printf("\n\n-------------------------------------------------------------------------------");
                    return menu();
                    
    }    
     
    
 
   
   
   
}
int main ()
{
    setlocale(LC_ALL,"");  
    
    int velha[3][3];
    int vez;
    face();
    titulo();
    menu();
    limparjogo(velha);
    jogar(velha, vez);
    analisarlinha(velha);
    analisarcoluna(velha);
    analisarDiagonal(velha);
    //analisarEmpate(velha);
    analisarTermino(velha, vez);
    jogada(velha);
    
   
   
   getch();
}
