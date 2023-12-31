#include "keyboard.h"
#include "screen.h"
#include "timer.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#define True 1
#define False 0

typedef struct {
  char name[20];
  char type[10];
  int health;
  int attack1;
  char attack1name[15];
  int attack2;
  char attack2name[15];
  int attack3;
  char attack3name[15];
  int attack4;
  char attack4name[15];
  int criticalattack;
  char criticaltype[10];
} Pokemon;

typedef struct {
    char playerName[20];
    int victories;
} PlayerStats;

typedef struct Node {
    PlayerStats data;
    struct Node* next;
} Node;

Node* createNode(PlayerStats stats) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = stats;
        newNode->next = NULL;
    }
    return newNode;
}

void insertNode(Node** head, PlayerStats stats) {
    Node* newNode = createNode(stats);
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nó.\n");
        screenClear();
        exit(0);
    }

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}



void pr_pikachu(int x,int y) {
    screenGotoxy(x, y);
    printf(";-.          ___,\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("  `.`\\_...._/`.-\"`\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("    \\       /      ,\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("    /()   () \\    .' `-._\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("   |)  .    ()\\  /   _.'\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("   \\  -'-     ,; '. <\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("    ;.__     ,;|   > \\\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("   / ,    / ,  |.-'.-'\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("  (_/    (_/ ,;|.<`\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("    \\    ,     ;-`\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("     >   \\    /\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("    (_,-'`> .'\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("      (_,'\n");
}
void pr_charmander(int x, int y) {
    screenGotoxy(x, y);
    printf("⠀⠀⣀⠔⠒⠒⠂⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠀⢰⢅⠀⠀⢀⣤⢄⢂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠀⣾⡆⠀⠀⠀⢸⠼⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⢀⢗⠂⠀⠀⡀⠈⢉⠅⠇⠀⠀⠀⠀⠀⠀⢠⣄⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠈⠢⣓⠔⣲⠖⡫⠊⡘⠀⠀⠀⠀⠀⠀⠲⡟⠙⡆\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⢀⢀⠠⠘⣇⠖⢄⠀⠉⠐⠠⢄⣀⡀⠀⠜⠀⠀⣁\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠘⣏⣀⣀⣀⠃⠀⠀⠑⣀⣀⣀⣰⠼⠇⠈⠄⠀⠈⡻\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠁⠀⠀⢰⠀⠀⠀⠀⠠⠀⠡⡀⠀⠀⠀⠈⡖⠚⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠀⠀⡠⠘⠀⠀⠀⠀⢀⠆⠀⠐⡀⠀⡠⠊⣠⠀⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠀⢐⠀⠀⠁⡀⠀⠀⢀⠀⠀⠀⢨⠀⡠⡴⠂⠀⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⢀⣨⣤⠀⠀⠐⠃⠐⠚⠢⠀⠀⠈⠑⠊⠀⠀⠀⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠘⠓⠋⠉⠁⠀⠀⠀⠀⠀⠓⢶⡾⠗⠀⠀⠀⠀⠀\n");
}

void pr_squirtle(int x, int y) {
    screenGotoxy(x, y);
    printf("⠀⠀⠀⠀⠀⣀⠤⠤⠤⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠀⡰⠋⠀⠀⠀⠀⠀⠀⠡⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⢠⠁⢰⣴⠀⠀⠀⠀⣿⡇⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⢀⣸⠀⠈⠙⠃⣀⣀⡀⣤⡄⢸⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⢰⠃⠉⠁⠂⢦⣀⢀⡀⠤⠤⣥⣌⡀⠀⠈⠱⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠘⠦⡀⠀⠀⠀⠈⡄⠂⠉⠀⣀⠵⢵⡒⠠⢴⡋⠉⢑⠖⠦⢄⠀⠀⠀⠀⠀⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠀⠈⠲⢤⣤⣴⡥⢄⡨⠋⠀⠒⢄⡑⣄⠀⠈⠄⠀⠀⠀⠈⡝⢀⣀⠀⠀⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠀⠀⠀⠈⢿⣿⣿⣆⡇⠀⠀⠊⠉⠉⡆⠈⠢⣶⣀⡀⢀⡰⠋⠀⠀⠉⠑⡄\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠀⠀⠀⠀⠀⢿⣿⣿⣔⠀⠠⡀⠀⢀⡇⠀⠀⠠⣇⠈⢹⠀⠀⡀⠀⠀⠀⠘⡄\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠀⠀⠀⠀⠀⠀⠙⠛⢿⣿⣿⣿⣿⣶⣶⢆⠀⠀⠈⠉⠈⢄⠀⠀⠀⠂⠀⢀⠇\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠁⠀⠀⠑⠦⣄⠀⠀⠀⠁⠀⠈⠀⢀⠎⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠓⠒⠲⠖⠒⠊⠁⠀⠀\n");
}

void pr_bulbasour(int x, int y) {
    screenGotoxy(x, y);
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣀⡀⠈⡖⡤⠄⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠀⢀⡀⠀⠀⠀⡐⠁⠀⠀⠠⠐⠂⠀⠁⠀⠀⠀⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠰⡁⠐⢉⣉⣭⡍⠁⠂⠉⠘⡀⠀⠀⠀⠀⠂⠡⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⢀⣊⠀⡄⠻⠿⠋⠀⠀⠀⠀⠀⢃⠀⠀⠀⠀⠀⠀⢀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⡎⣾⠀⠁⣴⡆⠀⠡⢺⣿⣆⠀⢠⢱⣄⠀⠀⠀⠀⠈\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⡑⠟⠀⠀⠀⠀⠀⢀⣸⡿⠟⠀⠀⠈⢿⣿⡦⡀⠀⡰\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠙⠔⠦⣤⣥⣤⣤⣤⡤⠆⠀⠀⠀⠀⢀⢀⠀⠈⠎⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠀⠈⣰⡋⢉⠉⠁⠒⠂⢇⢠⡆⠀⠸⢴⣿⠀⠘⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠀⠘⡿⠃⠀⠨⠒⢆⣸⣿⠁⠀⡠⡇⠈⠋⠀⠰⠀\n");
    y = y + 1;
    screenGotoxy(x, y);
    printf("⠀⠀⠀⠛⠒⠒⠁⠀⠈⠷⡤⠤⠐⠀⠘⠒⠒⠖⠁⠀\n");
}

Pokemon choice1 = {"Charmander", "Fire", 100, 15,"Fire Spin", 20,"Slash", 10,"Flamethrower", 10,"Tackle", 25, "Grass"};
Pokemon choice2 = {"Squirtle", "Water", 100, 15,"Water Gun", 20,"Bite", 10,"Water Pulse", 10,"Tackle", 25, "Fire"};
Pokemon choice3 = {"Bulbasaur", "Grass", 100, 15,"Vine Whip", 20,"False Swipe", 10,"Razor Leaf", 10,"Tackle", 25, "Water"};
Pokemon choice4 = {"Pikachu", "Electric", 100, 15,"ThunderBolt", 20,"Quick Attack", 10," ElectroBall", 10,"Tackle", 20, "Water"};

typedef struct {
  char playerName[20];
  Pokemon pokemon;
} Player;

Player player1; 
Player player2; 

void savePlayerStats(PlayerStats *winner) {
  FILE *file = fopen("player_stats.dat", "a");

  if (file == NULL) {

    file = fopen("player_stats.dat", "w");
    if (file == NULL) {
      fprintf(stderr, "Erro ao criar o arquivo de estatísticas.\n");
      screenClear();
      exit(0);
    }
  }

  fwrite(winner, sizeof(PlayerStats), 1, file);
  fclose(file);
}

void updatePlayerStats(PlayerStats *winner) {
  FILE *file = fopen("player_stats.dat", "r+");

  if (file == NULL) {
    fprintf(stderr, "Erro ao abrir o arquivo de estatísticas.\n");
    screenClear();
    exit(0);
  }

  PlayerStats playerStats;
  int found = 0;

  while (fread(&playerStats, sizeof(playerStats), 1, file) == 1) {
    if (strcmp(playerStats.playerName, winner->playerName) == 0) {
      playerStats.victories++;
      found = 1;
      fseek(file, -sizeof(playerStats), SEEK_CUR);
      fwrite(&playerStats, sizeof(playerStats), 1, file);
      break;
    }
  }

  fclose(file);

  if (!found) {
  
    playerStats.victories = 1;
    strncpy(playerStats.playerName, winner->playerName,
            sizeof(playerStats.playerName));


    file = fopen("player_stats.dat", "a");
    if (file == NULL) {
      fprintf(stderr, "Erro ao abrir o arquivo de estatísticas.\n");
      screenClear();
      exit(0);
    }

    fwrite(&playerStats, sizeof(playerStats), 1, file);
    fclose(file);
  }
}


void loadPlayerStats() {
    char escolha;
    screenSetColor(RED, BLACK);
    screenInit(0);

    FILE* file = fopen("player_stats.dat", "r");  
    if (file == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo de estatísticas.\n");
        screenClear();
        exit(0);
        
    }

    Node* statsList = NULL; 

    PlayerStats playerStats;
    while (fread(&playerStats, sizeof(PlayerStats), 1, file) == 1) {
        if (playerStats.victories > 0) {
            insertNode(&statsList, playerStats);
        }
    }

    fclose(file);

    // Ordenando a lista de estatísticas por número de vitórias (bubble sort)
    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = statsList;

        while (ptr1->next != lptr) {
            if (ptr1->data.victories < ptr1->next->data.victories) {
                // Troca as posições dos nodes se necessário
                PlayerStats temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    int i = 6;
    screenGotoxy(12, 4);
    printf("\n\tMelhores treinadores Pokemon:\n");

    Node* current = statsList;
    while (current != NULL) {
        screenGotoxy(6, i);
        printf("Jogador: %-11s | Vitórias: %d\n", current->data.playerName, current->data.victories);
        i += 1;
        current = current->next;
    }

    freeList(statsList);

    printf("\n\tPressione (S) para sair\n");
    scanf(" %c", &escolha);

    if (escolha != 's' && escolha != 'S') {
        screenClear();
        exit(0);  
    }
}
void getPlayerName(char *name, int playerNumber) {
  screenSetColor(WHITE, BLACK);
  screenClear();
  screenInit(0);

  screenGotoxy(5, 5);
  printf("Digite o nome do Player %d: ", playerNumber);
  screenUpdate();

  int index = 0;
  char inputChar;


  while (1) {
    inputChar = getchar();
    if (inputChar == '\n' || index >= 19) {
      break;
    }
    name[index++] = inputChar;
    name[index] = '\0'; 
    screenGotoxy(5, 7);
    printf("Nome: %s               ", name);
    screenGotoxy(5, 7);
    screenUpdate();
  }

  fflush(stdin);
}

int choosePokemon(Player *player) {
  // Drawing the Pokémon selection screen
  screenSetColor(WHITE, BLACK);
  screenClear();
  screenInit(0);

  screenGotoxy(5, 5);
  printf("Vez do %s escolher o POKÉMON", player->playerName);

  screenGotoxy(5, 8);
  printf("[1] %s", choice1.name);
  screenGotoxy(5, 9);
  printf("[2] %s", choice2.name);
  screenGotoxy(5, 10);
  printf("[3] %s", choice3.name);
  screenGotoxy(5, 11);
  printf("[4] %s", choice4.name);

  screenUpdate();


  while (1) {
    if (keyhit()) {
      int key = readch();
      switch (key) {
      case '1':
        player->pokemon = choice1;
        return 1;
      case '2':
        player->pokemon = choice2;
        return 1;
      case '3':
        player->pokemon = choice3;
        return 1;
      case '4':
        player->pokemon = choice4;
        return 1;
      default:
        break;
      }
    }
  }
}

void processPlayerInput(int key, Player *attacker, Player *defender) {
  
  switch (key) {
  case '1':
    if (strcmp(attacker->pokemon.criticaltype, defender->pokemon.type) == 0) {
      defender->pokemon.health -= attacker->pokemon.attack3;
    } else {
      defender->pokemon.health -= attacker->pokemon.criticalattack;
    }
    break;

  case '2':
    defender->pokemon.health -= attacker->pokemon.attack2;
    break;

  case '3':
    if (strcmp(attacker->pokemon.criticaltype, defender->pokemon.type) != 0) {
      defender->pokemon.health -= attacker->pokemon.attack3;
    } else {
      defender->pokemon.health -= attacker->pokemon.criticalattack;
    }
    break;

  case '4':
    defender->pokemon.health -= attacker->pokemon.attack4;
    break;
  default:
    break;
  }
}

void drawGameOverScreen(Player *currentPlayer, Player *opponent,
                        int *playAgain) {
  screenSetColor(RED, BLACK);
  screenClear();

  screenInit(0);

  screenGotoxy(5, 6);
  printf("GAME OVER");
  screenGotoxy(5, 8);
  printf("O GANHADOR FOI: %s", currentPlayer->playerName);

  screenGotoxy(5, 10);
  printf("Deseja jogar novamente? (S/N)");
  screenUpdate();

  screenGotoxy(5, 12);
  printf("Pressione 'V' para ver o placar");
  screenUpdate();

  char playAgainResponse;
  do {
    if (keyhit()) {
      playAgainResponse = readch();
    }
  } while (playAgainResponse != 'S' && playAgainResponse != 's' &&
           playAgainResponse != 'N' && playAgainResponse != 'n' &&
          playAgainResponse != 'V' && playAgainResponse != 'v');

  if (playAgainResponse == 'S' || playAgainResponse == 's') {
    *playAgain = 1;
  } else if (playAgainResponse == 'N' || playAgainResponse == 'n') {
    screenClear();
    exit(0);
  }else{
    loadPlayerStats(&playAgain);
  }
}

void drawBattleScreen(Player *currentPlayer, Player *opponent,bool hit) {

  screenSetColor(WHITE, BLACK);


  screenInit(2);
  if (strcmp(currentPlayer->pokemon.name, "Pikachu") == 0) {

    if(hit){
      screenGotoxy(6, 6);
      pr_pikachu(6, 6);
    }else{
      screenGotoxy(5, 5);
      pr_pikachu(5, 5);
    }
  }

  if (strcmp(currentPlayer->pokemon.name, "Charmander") == 0){

    if(hit){
      screenGotoxy(6, 6);
      pr_charmander(6, 6);
    }else{
      screenGotoxy(5, 5);
      pr_charmander(5, 5);
    }
  }

  if(strcmp(currentPlayer->pokemon.name,"Bulbasaur") == 0){

    if(hit){
      screenGotoxy(6, 6);
      pr_bulbasour(6, 6);
    }else{
      screenGotoxy(5, 5);
      pr_bulbasour(5, 5);
    }
  }

  if(strcmp(currentPlayer->pokemon.name,"Squirtle") == 0){

    if(hit){
      screenGotoxy(6, 6);
      pr_squirtle(6, 6);
    }else{
      screenGotoxy(5, 5);
      pr_squirtle(5, 5);

    }
  }

  screenGotoxy(40, 5);
  printf("BATALHA POKÉMON");

  screenGotoxy(40, 8);
  printf("%s: %s - Vida: %d/100", currentPlayer->playerName,
         currentPlayer->pokemon.name, currentPlayer->pokemon.health);


  screenGotoxy(40, 10);
  printf("%s: %s - Vida: %d/100", opponent->playerName, opponent->pokemon.name,
         opponent->pokemon.health);


  screenGotoxy(40, 15);
  printf("Escolha um ataque %s:", currentPlayer->playerName);
  screenGotoxy(40, 17);
  printf("[1] %s ", currentPlayer->pokemon.attack1name);
  screenGotoxy(40, 18);
  printf("[2] %s ", currentPlayer->pokemon.attack2name);
  screenGotoxy(40, 19);
  printf("[3] %s ", currentPlayer->pokemon.attack3name);
  screenGotoxy(40, 20);
  printf("[4] %s ", currentPlayer->pokemon.attack4name);

  screenUpdate();
}



int main() {
  int playAgain = 1;

  while (playAgain) {
    keyboardInit();
    screenInit(0);
    timerInit(1000);

    memset(&player1, 0, sizeof(Player));
    memset(&player2, 0, sizeof(Player));

    getPlayerName(player1.playerName, 1);
    getPlayerName(player2.playerName, 2);

    while (!choosePokemon(&player1)) {

    }

    while (!choosePokemon(&player2)) {

    }

    int gameOver = 0;
    Player *currentPlayer = &player1;
    Player *opponent = &player2;

    while (!gameOver) {
      drawBattleScreen(currentPlayer, opponent, False);

      int keyPressed = 0;
      int animationkey = 0;
      while (!keyPressed) {
        if (keyhit()) {
          int key = readch();
          processPlayerInput(key, currentPlayer, opponent);
          animationkey = 1;
          if(animationkey){
            drawBattleScreen(currentPlayer, opponent, True);
            usleep(0700000);
            drawBattleScreen(currentPlayer, opponent, False);
            usleep(0700000);
            keyPressed = 1;
          }
        }

        if (timerTimeOver()) {

          screenUpdate();
        }
      }

      if (currentPlayer == &player1) {
        currentPlayer = &player2;
        opponent = &player1;
      } else {
        currentPlayer = &player1;
        opponent = &player2;
      }

      if (player1.pokemon.health <= 0 || player2.pokemon.health <= 0) {
        gameOver = 1;

        Player *winner;
        if (player1.pokemon.health <= 0) {
          winner = &player2;
        } else {
          winner = &player1;
        }


        savePlayerStats(
            &(PlayerStats){.playerName = winner->playerName, .victories = 0});
        updatePlayerStats(winner);


        drawGameOverScreen(winner, opponent, &playAgain);

      }
    }

    keyboardDestroy();
    screenDestroy();
    timerDestroy();

  }
  return 0;
}
