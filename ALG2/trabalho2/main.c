#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// defines para a BoxDraw
#define upleft "\u256D"
#define upright "\u256E"
#define botleft "\u2570"
#define botright "\u256F"
#define hline "\u2500"
#define vline "\u2502"
#define MAX 200
// defines para o MenuLogic
#define baixo 80
#define cima 72
#define esc 27
#define enter 13
#define f1 59

typedef struct
{
  int id;
  char nome[30];
  char tipo[20];
  char regiao[20];
  int geracao;
  int evolucao;
  float peso;
  int excluido;
} pokemon;

void BoxDraw(int xI, int xF, int yI, int yF, int color);

// posiciona o cursor em uma coord
void gotoxy(int x, int y)
{
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// seleciona uma cor para o console
int SetColor(char color)
{
  HANDLE h;
  h = GetStdHandle(STD_OUTPUT_HANDLE);
  return SetConsoleTextAttribute(h, color);
}

// Retorna o tamanho atual do console
void getConsoleSize(int *width, int *height)
{
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

  *width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  *height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

// Redimensiona o console
void resizeConsole(int width, int height)
{
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  COORD bufferSize = {width, height};
  SetConsoleScreenBufferSize(hConsole, bufferSize);

  SMALL_RECT windowSize = {0, 0, width - 1, height - 1};
  SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

// Insere o texto com coord e cores especificas
void DisplayText(int x, int y, char text[], int color)
{
  SetColor(color);
  gotoxy(y, x);
  printf("%s", text);
}

// tela de ajuda ao apertar f1 ou selecionar no menu
void descript(char *v)
{
  int len = strlen(v);

  for (int i = 0; i < len; i++)
  {

    if (v[i] == ' ' || v[i] == '\n')
    {
      continue;
    }
    else if (v[i] == '/')
    {
      v[i] = 'x';
    }
    else if (v[i] == '%')
    {
      v[i] = 'v';
    }
    else
    {
      v[i] -= 9;
    }
  }
}

void HelpScreen()
{

  FILE *arq = fopen("ajuda.txt", "r");

  char linha[100];

  if (arq == NULL)
  {
    printf("Erro ao abrir o arquivo ajuda");
    return;
  }

  int x, y;

  getConsoleSize(&x, &y);

  x = x / 2;

  int i = 0;

  DisplayText(3, x + 20, "ARQUIVO AJUDA", 7);
  BoxDraw(2, 4, x + 16, x + 18 + 18, 9);

  while (fgets(linha, sizeof(linha), arq))
  {
    i++;

    descript(linha);

    DisplayText(5 + i, x, linha, 7);
  }

  int ch;

  ch = getch();

  while (ch != esc)
  {
    ch = getch();
  }

  if (ch == esc)
  {
    char space[] = "                                                                         ";

    for (int i = 0; i < 25; i++)
    {
      DisplayText(i, x, space, 7);
    }
  }

  gotoxy(0, 30);
}

// desenha uma caixa com as coord passadas
void BoxDraw(int xI, int xF, int yI, int yF, int color)
{
  int i;

  gotoxy(yI, xI);
  printf("%s", upleft);
  for (i = 1; i < (yF - yI); i++)
  {
    printf("%s", hline);
  }
  printf("%s", upright);

  for (i = xI + 1; i < xF; i++)
  {
    gotoxy(yI, i);
    printf("%s", vline);
    gotoxy(yF, i);
    printf("%s", vline);
  }

  gotoxy(yI, xF);
  printf("%s", botleft);
  for (i = 1; i < (yF - yI); i++)
  {
    printf("%s", hline);
  }
  printf("%s", botright);
}

// Impressao do menu
void MenuDisplay(int op)
{
  char v[][30] = {"Inserir", "Alterar", "Remover", "Consultar", "Ajuda(F1)", "Sair(Esc)"};
  int i;

  for (i = 0; i < 6; i++)
  {
    int len = strlen(v[i]) + 4;

    if (i == op - 1)
    {
      int co = (op == 6 ? 4 : 1);

      DisplayText(8 + (i * 3), 4, v[i], co);
      BoxDraw(7 + (i * 3), 9 + (i * 3), 2, 2 + len, co);
    }
    else
    {
      DisplayText(8 + (i * 3), 4, v[i], 7);
      BoxDraw(7 + (i * 3), 9 + (i * 3), 2, 2 + len, 7);
    }
  }

  gotoxy(0, 29);
}

// funcionamento do menu
int MenuLogic()
{
  int op = 1;
  char t;

  DisplayText(3, 20, "PROJETO POKEDEX", 7);
  BoxDraw(1, 27, 0, 50, 9);

  MenuDisplay(op);

  do
  {
    t = getch();

    if (t == baixo)
    {
      if (op < 6)
        op++;
      else
        op = 1;
      MenuDisplay(op);
    }
    else if (t == cima)
    {
      if (op > 1)
        op--;
      else
        op = 6;
      MenuDisplay(op);
    }
    else if (t == f1)
    {
      return op = 11;
    }
    else if (t == enter)
    {
      return op;
    }
    else if (t == esc)
    {
      system("cls");
      return 13;
    }
  } while (t != esc);

  return 13;
}

void saveChanges(FILE *arq, pokemon p);

// Funcao para inserir pokemons no arquivo binario
void insertPokemon(FILE *arq, int qt)
{
  pokemon p;
  long posicao;
  int ultimoID = 0; // Variável para armazenar o último ID

  fseek(arq, 0, SEEK_END);
  posicao = ftell(arq);

  if (posicao > 0)
  {
    fseek(arq, -sizeof(pokemon), SEEK_END);
    fread(&p, sizeof(pokemon), 1, arq);
    ultimoID = p.id;
  }

  printf("Deseja inserir quantos novos pokemons? ");
  scanf("%d", &qt);
  printf("\n");

  for (int k = 1; k <= qt; k++)
  {
    p.id = ultimoID + k;

    getchar();

    printf("ID: %d\n", p.id);

    printf("Nome: ");
    scanf("%s", p.nome);

    printf("Tipo: ");
    scanf("%s", p.tipo);

    printf("Regiao: ");
    scanf("%s", p.regiao);

    printf("Geracao: ");
    scanf("%d", &p.geracao);

    printf("Estagio de evolucao: ");
    scanf("%d", &p.evolucao);

    printf("Peso (em Kg): ");
    scanf("%f", &p.peso);

    p.excluido = 0; // Define o campo de exclusão como 0

    // Grava cada Pokémon no arquivo
    fseek(arq, 0, SEEK_END);
    fwrite(&p, sizeof(pokemon), 1, arq);
    fflush(arq);
  }

  printf("%d Pokémon(s) inserido(s) com sucesso!\n", qt);
}

// Funcao para consultar todos os pokemons cadastrados
void listPokemon(FILE *arq)
{
  pokemon p;

  rewind(arq);

  system("cls");
  DisplayText(3, 30, "CONSULTA", 7);
  BoxDraw(2, 4, 26, 41, 9);
  // Cabeçalho da tabela
  printf("\n\n\n|  ID  |    NOME    |    TIPO    |   REGIAO   | GERACAO | EVOLUCAO |   PESO   |\n");
  printf("-------------------------------------------------------------------------------\n");

  // Leitura do arquivo e impressão dos dados
  while (fread(&p, sizeof(pokemon), 1, arq) == 1)
  {
    if (p.excluido == 0)
    {
      printf("| %2d  | %-10s | %-10s | %-8s   |    %1d     |    %1d     | %6.2f Kg |\n",
             p.id, p.nome, p.tipo, p.regiao, p.geracao, p.evolucao, p.peso);
    }
  }

  printf("--------------------------------------------------------------------------------\n");
}

// Funcao para mudar alguma caracteristica de um determinado pokemon
void changePokemon(FILE *arq)
{
  pokemon p;
  char changeName[30];
  int opcao;

  rewind(arq);

  printf("Digite o nome do pokemon que deseja alterar: ");
  scanf("%s", changeName);

  while (fread(&p, sizeof(pokemon), 1, arq) == 1)
  {
    if (strcmp(changeName, p.nome) == 0)
    {
      printf("O que deseja alterar?\n");
      printf("1. ID\n");
      printf("2. Nome\n");
      printf("3. Tipo\n");
      printf("4. Regiao\n");
      printf("5. Geracao\n");
      printf("6. Estagio de evolucao\n");
      printf("7. Peso (em Kg)\n");

      scanf("%d", &opcao);

      switch (opcao)
      {
      case 1:
        printf("Digite o novo ID: ");
        scanf("%d", &p.id);
        break;

      case 2:
        printf("Digite o novo nome: ");
        scanf("%s", p.nome);
        break;

      case 3:
        printf("Digite o novo tipo: ");
        scanf("%s", p.tipo);
        break;

      case 4:
        printf("Digite a nova regiao: ");
        scanf("%s", p.regiao);
        break;

      case 5:
        printf("Digite a nova geracao: ");
        scanf("%d", &p.geracao);
        break;

      case 6:
        printf("Digite o novo estagio de evolucao: ");
        scanf("%d", &p.evolucao);
        break;

      case 7:
        printf("Digite o novo peso (em Kg): ");
        scanf("%f", &p.peso);
        break;

      default:
        printf("Escolha invalida!\n");
      }

      saveChanges(arq, p);
    }
  }
}

// Funcao para salvar as caracteristicas alteradas de um pokemon
void saveChanges(FILE *arq, pokemon p)
{
  int alterar;

  fseek(arq, -sizeof(pokemon), SEEK_CUR);
  fwrite(&p, sizeof(pokemon), 1, arq);

  printf("Deseja alterar mais alguma caracteristica desse Pokemon? (1- Sim | 2- Nao): ");
  scanf("%d", &alterar);

  if (alterar == 1)
  {
    changePokemon(arq);
  }
  else
    printf("Alteracao salva com sucesso!\n");
}

// Funcao para excluir momentaneamente o pokemon
void logicalDeletePokemon(FILE *arq)
{
  pokemon p;
  char deletedPokemon[30];

  rewind(arq);

  printf("Qual pokemon deseja excluir?\n");

  printf("DIGITE: ");
  scanf("%s", deletedPokemon);

  while (fread(&p, sizeof(pokemon), 1, arq) == 1)
  {
    if (strcmp(deletedPokemon, p.nome) == 0)
    {
      p.excluido = 1;
      fseek(arq, -sizeof(pokemon), SEEK_CUR);
      fwrite(&p, sizeof(pokemon), 1, arq);
      break;
    }
  }

  printf("Pokemon excluido com sucesso!\n");
}

// Funcao para excluir o pokemon definitivamente (na saida do arquivo)
void physicalDeletePokemon(FILE *arq)
{
  pokemon p;
  
  FILE *temp;
  rewind(arq);

  temp = fopen("temp.bin", "w+b");
  if (!temp)
  {
    printf("Houve um erro ao abrir o arquivo auxiliar\n");
    fclose(arq);
    exit(1);
  }

  while (fread(&p, sizeof(pokemon), 1, arq) == 1)
  {
    if (p.excluido == 0)
    {
      fwrite(&p, sizeof(pokemon), 1, temp);
    }
  }

  fclose(temp);
  fclose(arq);

  if (remove("pokemons.bin") == 0)
  {
    rename("temp.bin", "pokemons.bin");
  }
  else
  {
    printf("Erro ao remover o arquivo original\n");
  }
}

// Funcao para consultar os pokemons de uma determinada regiao
void consulteRegionPokemon(FILE *arq)
{
  pokemon p;
  char regionConsulte[20];

  rewind(arq);

  printf("Digite o nome da regiao que deseja consultar os pokemons: ");
  scanf("%s", regionConsulte);

  system("cls");
  DisplayText(3, 30, "CONSULTA", 7);
  BoxDraw(2, 4, 26, 41, 9);
  // Cabeçalho da tabela
  printf("\n\n\n|  ID  |    NOME    |    TIPO    |   REGIAO   | GERACAO | EVOLUCAO |   PESO   |\n");
  printf("-------------------------------------------------------------------------------\n");

  // Leitura do arquivo e impressão dos dados
  while (fread(&p, sizeof(pokemon), 1, arq) == 1)
  {
    if (strcmp(regionConsulte, p.regiao) == 0 && p.excluido == 0)
    {
      printf("| %2d  | %-10s | %-10s | %-8s   |    %1d     |    %1d     | %6.2f Kg |\n",
             p.id, p.nome, p.tipo, p.regiao, p.geracao, p.evolucao, p.peso);
    }
  }

  printf("--------------------------------------------------------------------------------\n");
}

// Funcao para consultar os pokemons de uma determinada geracao
void consulteGenerationPokemon(FILE *arq)
{
  pokemon p;
  int generationConsulte;

  rewind(arq);

  printf("Digite a geracao de pokemons que deseja consultar: ");
  scanf("%d", &generationConsulte);

  system("cls");
  DisplayText(3, 30, "CONSULTA", 7);
  BoxDraw(2, 4, 26, 41, 9);
  // Cabeçalho da tabela
  printf("\n\n\n|  ID  |    NOME    |    TIPO    |   REGIAO   | GERACAO | EVOLUCAO |   PESO   |\n");
  printf("-------------------------------------------------------------------------------\n");

  // Leitura do arquivo e impressão dos dados
  while (fread(&p, sizeof(pokemon), 1, arq) == 1)
  {
    if (generationConsulte == p.geracao && p.excluido == 0)
    {
      printf("| %2d  | %-10s | %-10s | %-8s   |    %1d     |    %1d     | %6.2f Kg |\n",
             p.id, p.nome, p.tipo, p.regiao, p.geracao, p.evolucao, p.peso);
    }
  }

  printf("--------------------------------------------------------------------------------\n");
}

// Funcao para consultar os pokemons de um determinado estagio de evolucao
void consulteEvolutionPokemon(FILE *arq)
{
  pokemon p;
  int evolutionConsulte;

  rewind(arq);

  printf("Digite o estagio de evolucao de pokemons que deseja consultar: ");
  scanf("%d", &evolutionConsulte);

  if (evolutionConsulte > 3 && evolutionConsulte < 1)
  {
    printf("Nao constam pokemons dessa geração no nosso arquivo");
    system("cls");
    return;
  }

  system("cls");
  DisplayText(3, 30, "CONSULTA", 7);
  BoxDraw(2, 4, 26, 41, 9);
  // Cabeçalho da tabela
  printf("\n\n\n|  ID  |    NOME    |    TIPO    |   REGIAO   | GERACAO | EVOLUCAO |   PESO   |\n");
  printf("-------------------------------------------------------------------------------\n");

  // Leitura do arquivo e impressão dos dados
  while (fread(&p, sizeof(pokemon), 1, arq) == 1)
  {
    if (evolutionConsulte == p.evolucao && p.excluido == 0)
    {
      printf("| %2d  | %-10s | %-10s | %-8s   |    %1d     |    %1d     | %6.2f Kg |\n",
             p.id, p.nome, p.tipo, p.regiao, p.geracao, p.evolucao, p.peso);
    }
  }

  printf("--------------------------------------------------------------------------------\n");
}

// main
int main()
{
  SetConsoleOutputCP(CP_UTF8);
  system("cls");

  resizeConsole(155, 30);
  system("mode con: cols=150 lines=40");

  int continuar = 1;
  int b, consultar;
  FILE *arq;

  // Abertura do arquivo
  arq = fopen("pokemons.bin", "r+b");
  if (!arq)
  {
    arq = fopen("pokemons.bin", "w+b");
    if (!arq)
    {
      printf("Houve um erro ao abrir o arquivo!\n");
      exit(1);
    }
  }

  
  do
  {
    // Exibe o menu e recebe a opção selecionada
    b = MenuLogic();
    int qt = 0;

    switch (b)
    {
    case 1:
      insertPokemon(arq, qt); // Inserir Pokémon
      break;
    case 2:
      changePokemon(arq); // Alterar Pokémon
      break;
    case 3:
      logicalDeletePokemon(arq); // Remover Pokémon (lógica)
      break;
    case 4:
      printf("\nO que deseja consultar?\n");
      printf("1- Pokemons por regiao\n");
      printf("2- Pokemons por geracao\n");
      printf("3- Pokemons por estagio de evolucao\n");
      printf("4- Todos os Pokemons\n\n");

      printf("DIGITE: ");
      scanf("%d", &consultar);

      switch (consultar)
      {
      case 1:
        consulteRegionPokemon(arq);
        break;
      case 2:
        consulteGenerationPokemon(arq);
        break;
      case 3:
        consulteEvolutionPokemon(arq);
        break;
      case 4:
        listPokemon(arq);
        break;
      }
      break;
    case 5:
      HelpScreen(); 
      break;
    case 6: 
    case 13:
      system("cls");
      printf("SAINDO DO PROGRAMA VALEUU FIO\n\n");
      continuar = 0;
      break;
    case 11:
      HelpScreen(); // Exibir tela de ajuda
      break;
    default:
      printf("Opcao invalida!\n");
    }

    if (b != 6 && b != 13)
    {
      printf("\nPressione qualquer tecla para voltar ao menu...");
      getch();
      system("cls");
    }

  } while (continuar);

  physicalDeletePokemon(arq);
  
  
  SetColor(7);
  return 0;
}
