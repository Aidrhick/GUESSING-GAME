#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define MAX_FILE_NAME_LENGTH 1000
#define MAX_SPRITE_SIZE 1000

int DIFFICULTY;

void DisplayHomeScreen();
void DisplayTutorialScreen();
void DisplayDifficultyScreen();
void DisplayIntroScreen();
void DisplayCountdown();

void StartGame(int difficulty, int level);

void PlayMusic(const char *filename);
void StopMusic();
void DisplayPokemonSprite(const char *filename, int indentation, int sleepTime);
void ClearLine();
void ClearScreen();

int main()
{
    DisplayHomeScreen();
    return 0;
}

void DisplayHomeScreen() {
    StopMusic();
    PlayMusic("audio/opening.wav");

    char userInput[20];
    printf("\n\n\n\t\t\t\t                                                          :.                                              \n");
    printf("\t\t\t\t                                                         :Y#J:                                            \n");
    printf("\t\t\t\t                                             .. .      .~YJ~.         ....                                \n");
    printf("\t\t\t\t                    .:^7?Y555Y?~.       :!J5G?::Y5~.  .:~!!^:.  .!YYY^~BBJ.      :^..                     \n");
    printf("\t\t\t\t                 .:JGB##########G7.     :~P##Y!B###Y:~5GPY5B#P^.:5###JJ##G:      :YBBGY:.:!^:.            \n");
    printf("\t\t\t\t                  .7#######P~^7B#B^      .?##B###G7:!##! .?BY~..^B###BB###!..^~!~:~####~:Y##B~.           \n");
    printf("\t\t\t\t                   .~!!B###B^ .5#Y:^JJPGP?~G####J^..7##Y7BG?JP?:~B#######P~J5!G#BB?!B##5^B##?.            \n");
    printf("\t\t\t\t                      .!####P7PB?:Y#5:5GYBP^B#B##BPY~?G######BY^7B#PJ#BGB^5#5^~77B#:G##BP##P:             \n");
    printf("\t\t\t\t                       .7####B7:.7##B?!75#G^G#!~?5B##5?7?7!~:..~###7:Y?7B:P##BGG##77#Y####B^              \n");
    printf("\t\t\t\t                        .7###B^  ~G######P^J##!   .^75GBP:     .^~!: :.^#P7YPGGP?~Y#B!####7.              \n");
    printf("\t\t\t\t                         .?###Y:  :!JYJ7^..?5Y^       .:~:             .!JJ!:.  .~GG?~###5:               \n");
    printf("\t\t\t\t                          .?##B~.                                                   .~B#G^                \n");
    printf("\t\t\t\t                           .~~:.                                                      .:^.                \n");
    printf("\t\t\t\t\t        _______  __   __  _______  _______  _______    _______  _______  __   __  _______ \n");
    printf("\t\t\t\t\t       |       ||  | |  ||       ||       ||       |  |       ||   _   ||  |_|  ||       |\n");
    printf("\t\t\t\t\t       |    ___||  | |  ||    ___||  _____||  _____|  |    ___||  |_|  ||       ||    ___|\n");
    printf("\t\t\t\t\t       |   | __ |  |_|  ||   |___ | |_____ | |_____   |   | __ |       ||       ||   |___ \n");
    printf("\t\t\t\t\t       |   ||  ||       ||    ___||_____  ||_____  |  |   ||  ||       ||       ||    ___|\n");
    printf("\t\t\t\t\t       |   |_| ||       ||   |___  _____| | _____| |  |   |_| ||   _   || ||_|| ||   |___ \n");
    printf("\t\t\t\t\t       |_______||_______||_______||_______||_______|  |_______||__| |__||_|   |_||_______|\n");

    printf("\n\n\t\t\t\t\t\t\t\t\t\t   <1> Play\n\n\t\t\t\t\t\t\t\t\t\t   <2> How to play\n\n\t\t\t\t\t\t\t\t\t\t   <3> Exit\n\n\t\t\t\t\t\t\t\t\t\t   Input: ");
    gets(userInput);

    int input = atoi(userInput);

    switch (input) {
        case 1:
            StopMusic();
            PlayMusic("audio/click.mp3");
            printf("\t\t\t\t\t\t\t\t\t\t   ");
            printf("Time to play the game :)");
            Sleep(1000);
            ClearScreen();
            DisplayDifficultyScreen();
            break;
        case 2:
            StopMusic();
            PlayMusic("audio/click.mp3");
            printf("\t\t\t\t\t\t\t\t\t\t   ");
            printf("How to play :)");
            Sleep(1000);
            ClearScreen();
            DisplayTutorialScreen();
            break;
        case 3:
            StopMusic();
            PlayMusic("audio/click.mp3");
            printf("\t\t\t\t\t\t\t\t\t\t   ");
            printf("Exiting the program");
            Sleep(1000);
            ClearScreen();
            exit(0);
            break;
        case 0:
        default:
            printf("\t\t\t\t\t\t\t\t\t\t   ");
            printf("Invalid Input");
            Sleep(1000);
            ClearScreen();
            DisplayHomeScreen();
            break;
    }

}

void DisplayTutorialScreen() {

    printf("\n\n\n\t\t\tWelcome to\n\n\n");
    printf("\t\t\t\033[1;31m.----.  .----. .-. .-..----..-.   .-. .----. .-. .-.   .-.   .----.  .--.   .---. .-. .-..----. \033[0m\n");
    printf("\t\t\t\033[1;31m| {}  }/  {}  \\| |/ / | {_  |  `.'  |/  {}  \\|  `| |   | |   | {_   / {} \\ /   __}| { } || {_   \033[0m\n");
    printf("\t\t\t\033[1;31m| .--' \\      /| |\\ \\ | {__ | |\\ /| |\\      /| |\\  |   | `--.| {__ /  /\\  \\\\  {_ }| {_} || {__  \033[0m\n");
    printf("\t\t\t\033[1;31m`-'     `----' `-' `-'`----'`-' ` `-' `----' `-' `-'   `----'`----'`-'  `-' `---' `-----'`----' \033[0m\n\n\n\n");
    printf("\t\t\tThe premise is that in a battle of Pokemon,\n\t\t\tthe ultimate objective for each trainer to strategically \n\t\t\tengage in battles until only one Pokemon remains on the field.\n");
    printf("\t\t\t(survival of the fittest Pokemon determines the overall outcome of the battle in final round.\n\n");
    printf("\t\t\tThis dynamic emphasizes the importance of careful planning, tactical decisions, and effective \n\t\t\tuse of each Pokemon's abilities)\n\n");
    printf("\t\t\tGuess the correct number to launch your attack.\n");
    printf("\t\t\t""Every time your guess is correct, you're going to attack continuously until the enemy loses health.\n\n");
    printf("\t\t\tAs the player advances through each level, the complexity and difficulty of the challenges increase incrementally. \n");
    printf("\t\t\tIf you are unable to catch the specified number, you have the option to enter 'R' or 'r' to initiate a reset.\n\t\t\tHowever, it's essential to note that you are limited to only three resets throughout the course of each battle.\n\n");
    printf("\t\t\t(So, use them wisely and make sure to guess accurately for a successful outcome in the game)\n\n");
    printf("\t\t\tNOTE:\n");
    printf("\t\t\tIf you take too long, you will lose your turn, and the enemy will attack your pokemon.\n\n\n\n");
    printf("\t\t\tEnjoy your journey!!\n\n\n");

    printf("\t\t\tPress ESC to continue.");

    char ch;
    while (1) {
        if (kbhit) {
            ch = getch();
            if ((int)ch == 27) {
                break;
            }
        }
    }

    StopMusic();
    PlayMusic("audio/click.mp3");
    Sleep(1000);
    ClearScreen();
    DisplayHomeScreen();
}



void DisplayDifficultyScreen() {
    printf("\n\n\t\t\t\t     \033[47m                                                                                                       \033[0m");
    char userInput[20];
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\tChoose your Level\n\n\n");

    printf("\x1b[5;34m\t\t\t\t\t\t\t\t  __    _    __       _____                \n");
    printf("\t\t\t\t\t\t\t\t / /   / |   \\ \\     | ____|__ _ ___ _   _ \n");
    printf("\t\t\t\t\t\t\t\t/ /    | |    \\ \\    |  _| / _` / __| | | |\n");
    printf("\t\t\t\t\t\t\t\t\\ \\    | |    / /    | |__| (_| \\__ \\ |_| |\n");
    printf("\t\t\t\t\t\t\t\t \\_\\   |_|   /_/     |____\\__,_|___/\\__,  |\n");
    printf("\t\t\t\t\t\t\t\t                                      |__/ \n\n\n");
    printf("\x1b[5;32m\t\t\t\t\t\t\t\t  __  ____   __       __  __          _ _                 \n");
    printf("\t\t\t\t\t\t\t\t / / |___ \\  \\ \\     |  \\/  | ___  __| (_)_   _ _ __ ___  \n");
    printf("\t\t\t\t\t\t\t\t/ /    __) |  \\ \\    | |\\/| |/ _ \\/ _` | | | | | '_ ` _ \\ \n");
    printf("\t\t\t\t\t\t\t\t\\ \\   / __/   / /    | |  | |  __/ (_| | | |_| | | | | | |\n");
    printf("\t\t\t\t\t\t\t\t \\_\\ |_____| /_/     |_|  |_|\\___|\\__,_|_|\__,__|_| |_| |_|\n\n\n");
    printf("\x1b[5;31m\t\t\t\t\t\t\t\t  __  _____  __       _   _               _ \n");
    printf("\t\t\t\t\t\t\t\t / / |___ /  \\ \\     | | | | __ _ _ __ __| |\n");
    printf("\t\t\t\t\t\t\t\t/ /    |_ \\   \\ \\    | |_| |/ _` | '__/ _` |\n");
    printf("\t\t\t\t\t\t\t\t\\ \\   ___) |  / /    |  _  | (_| | | | (_| |\n");
    printf("\t\t\t\t\t\t\t\t \\_\\ |____/  /_/     |_| |_|\\__,_|_|  \\__,_|\n");

    printf("\n\n\n\t\t\t\t     \033[47m                                                                                                       \033[0m");

    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t   Input: ");
    gets(userInput);
    int input = atoi(userInput);

    switch (input) {
        case 1:
            StopMusic();
            PlayMusic("audio/click.mp3");
            ClearScreen();
            DIFFICULTY = 1;
            Sleep(1000);
            DisplayIntroScreen();
            break;
        case 2:
            StopMusic();
            PlayMusic("audio/click.mp3");
            ClearScreen();
            DIFFICULTY = 2;
            Sleep(1000);
            DisplayIntroScreen();
            break;
        case 3:
            StopMusic();
            PlayMusic("audio/click.mp3");
            ClearScreen();
            DIFFICULTY = 3;
            Sleep(1000);
            DisplayIntroScreen();
            break;
        case 0:
        default:
            printf("\t\t\t\t\t\t\t\t\t\t   ");
            printf("Invalid Input");
            Sleep(500);
            ClearScreen();
            DisplayDifficultyScreen();
            break;
    }
}

void DisplayIntroScreen() {
    char userInput[10];

    printf("\n\n\n\n\t\t\t\t\tAs a mythical creature, it is your job to ensure the order and harmony of humans and pokemon.");
    printf("\n\n\t\t\t\t\tUse your psychic abilities to restore order within wild pokemon.");
    printf("\n\n\t\t\t\t\tDon't take too long, they won't hesitate to attack as well.");
    printf("\n\n\t\t\t\t\tGood Luck.\n\n\n");

    DisplayPokemonSprite("pokemon/player/mew_front.txt", 50, 0);

    printf("\n\n\n\n\t\t\t\t\tDo you wish to proceed? <1> Yes <2> No\n\t\t\t\t\t");
    gets(userInput);

    int input = atoi(userInput);
    switch (input) {
        case 1:
            StopMusic();
            PlayMusic("audio/click.mp3");
            ClearScreen();
            DisplayCountdown();
            StartGame(DIFFICULTY, 1);
            break;
        case 2:
            StopMusic();
            PlayMusic("audio/click.mp3");
            ClearScreen();
            DisplayHomeScreen();
            break;
        case 0:
        default:
            ClearScreen();
            DisplayIntroScreen();
            break;
    }

}

void DisplayCountdown() {

    void printThree() {
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tBe ready. The game will start in...\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t .----------------. \n");
        printf("\t\t\t\t\t\t\t\t\t\t| .--------------. |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |    ____      | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |   / __ `.    | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |   `'  __) |  | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |   _  |__ '.  | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |  | \\____) |  | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |   \\______.'  | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |              | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| '--------------' |\n");
        printf("\t\t\t\t\t\t\t\t\t\t '----------------' \n\n");
    }

    void printTwo() {
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tBe ready. The game will start in...\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t .----------------. \n");
        printf("\t\t\t\t\t\t\t\t\t\t| .--------------. |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |     ___      | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |    / _ `.    | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |  |_/___) |   | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |   .'__.'     | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |  / /____     | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |  |_______|   | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |              | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| '--------------' |\n");
        printf("\t\t\t\t\t\t\t\t\t\t '----------------' \n\n");
    }

    void printOne() {
        printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tBe ready. The game will start in...\n\n\n\n");
        printf("\t\t\t\t\t\t\t\t\t\t .----------------. \n");
        printf("\t\t\t\t\t\t\t\t\t\t| .--------------. |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |     __       | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |    /  |      | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |    `| |      | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |     | |      | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |     | |      | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |   |_____|    | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| |              | |\n");
        printf("\t\t\t\t\t\t\t\t\t\t| '--------------' |\n");
        printf("\t\t\t\t\t\t\t\t\t\t '----------------' \n\n");
    }

    printThree();
    Sleep(1000);
    ClearScreen();
    printTwo();
    Sleep(1000);
    ClearScreen();
    printOne();
    Sleep(1000);
    ClearScreen();
}


void StartGame(int difficulty, int level) {
    char easyPkmns[][20] = {"Caterpie", "Oddish", "Pidgey", "Rattata", "Weedle"};
    char medPkmns[][20] = {"Bulbasaur", "Charmander", "Pidgeotto", "Pikachu", "Squirtle"};
    char hardPkmns[][20] = {"Charizard", "Blastoise", "Venusaur", "Raichu", "Arcanine"};


    char generatedPkmn[20];
    char pkmnFile[50];
    char playerFile[50] = "pokemon/player/mew_back.txt";

    char battleMusic[20];

    int currDifficulty = difficulty;
    int currLevel = level;
    int numLength;

    int playerBuffLevels[10] = {3,6,9,12,15,18,21,24,27,30};
    int enemyBuffLevels[6] = {5,10,15,20,25,30};

    int currPlayerLives;
    int currEnemyLives;
    int maxPlayerLives;
    int maxEnemyLives;

    int playerDamage = 1;
    int enemyDamage = 1;

    int waitTime;

    // for timers
    time_t startTime = time(NULL);
    double elapsedTime = 0;


    void buffPlayer() {
        currPlayerLives += 2;
        maxPlayerLives += 2;
        playerDamage++;
    }

    void buffEnemy() {
        currEnemyLives += 3;
        maxEnemyLives += 3;
        waitTime -= waitTime / 8;
        enemyDamage++;
    }

    void checkForBuff() {
        for(int i = 0; i < 10; i++) {
            if (currLevel >= playerBuffLevels[i]) {
                buffPlayer();
            }
        }
        for(int i = 0; i < 5; i++) {
            if (currLevel >= enemyBuffLevels[i]) {
                buffEnemy();
            }
        }
    }

    if (currDifficulty == 1) {
        strcpy(battleMusic, "audio/1.mp3");
        strcpy(pkmnFile, "pokemon/easy/");
        numLength = 5;
        currPlayerLives = 3;
        currEnemyLives = 3;
        maxPlayerLives = 3;
        maxEnemyLives = 3;
        waitTime = 2000;
        checkForBuff();
    } else if (currDifficulty == 2) {
        strcpy(battleMusic, "audio/2.mp3");
        strcpy(pkmnFile, "pokemon/medium/");
        numLength = 7;
        currPlayerLives = 3;
        currEnemyLives = 4;
        maxPlayerLives = 3;
        maxEnemyLives = 4;
        waitTime = 1500;
        checkForBuff();
    } else if (currDifficulty == 3) {
        strcpy(battleMusic, "audio/3.mp3");
        strcpy(pkmnFile, "pokemon/hard/");
        numLength = 8;
        currPlayerLives = 3;
        currEnemyLives = 5;
        maxPlayerLives = 3;
        maxEnemyLives = 5;
        waitTime = 1500;
        checkForBuff();
    }

    char generatedNumber[numLength];


    void randomizeNumber() {
        srand((unsigned int)time(NULL));
        strcpy(generatedNumber, "");

        for (int i = 0; i < numLength; i++)
        {
            char randNum = '0' + rand() % 10;
            generatedNumber[i] = randNum;
        }
    }

    void randomizePkmn() {
        srand((unsigned int)time(NULL));
        strcpy(generatedPkmn, "");

        int randNum = 0 + rand() % 5;
        if (currDifficulty == 1) strcpy(generatedPkmn, easyPkmns[randNum]);
        else if (currDifficulty == 2) strcpy(generatedPkmn, medPkmns[randNum]);
        else if (currDifficulty == 3) strcpy(generatedPkmn, hardPkmns[randNum]);
    }

    void displayHealthBar(int currentHealth, int maxHealth, char *pokemon, bool isPlayer) {
        int healthBarLength = 30; // length of characters in the bar

        int numChars = currentHealth * healthBarLength / maxHealth; // calculate how many characters to print based on health

        if (!isPlayer) {
            printf("\n\r\t\t\t\t\t\t\t\t\t\t\t\t\t%s", pokemon);
            printf("\n\r\t\t\t\t\t\t\t\t\t\t\t\t\t");
        } else {
            printf("\n\r\t\t\t%s", pokemon);
            printf("\n\r\t\t\t");
        }
        for (int j = 0; j < numChars; j++) { // print a bar as long as j is less than the characters to print
            printf("\033[42m \033[0m"); // you can use different colors or symbols for the health bar
        }
        for (int j = 0; j < healthBarLength - numChars; j++) { // print the blank spaces to fill the length of the bar
            printf(" ");
        }
        if (currentHealth <= 0) printf(" %d/%d\n\n", 0, maxHealth * 10); // limit value to zero
        else printf(" %d/%d\n\n", currentHealth * 10, maxHealth * 10); // display the current health and max health
    }


    void battleGame() {
        bool isGameRunning = true;

        void reloadBattlefield(int waitT) {
            displayHealthBar(currEnemyLives, maxEnemyLives, generatedPkmn, false);
            DisplayPokemonSprite(pkmnFile, 100, waitT);
            displayHealthBar(currPlayerLives, maxPlayerLives, "Mew", true);
            DisplayPokemonSprite(playerFile, 20, waitT);
        }

        void gameLoop() {
            int reset = 3;


            printf("\n\t\t\tA Wild %s Appeared!", generatedPkmn);
            Sleep(1000);
            ClearLine();

            do {
                bool enemyHitOccurred = false;
                char userInput[20];

                void userHit() {
                    ClearLine();
                    printf("\r\t\t\tYou Guessed Correct!");
                    Sleep(1000);
                    ClearLine();
                    printf("\r\t\t\tMew Used Psychic!");
                    currEnemyLives -= playerDamage;
                    Sleep(1000);
                    ClearScreen();
                    reloadBattlefield(0);
                    randomizeNumber();
                    printf("\n");
                }

                void enemyHit() {
                    ClearLine();
                    printf("\r\t\t\tYou Guessed Incorrect");
                    Sleep(1000);
                    ClearLine();
                    printf("\r\t\t\tThe Wild Pokemon Attacked");
                    currPlayerLives -= enemyDamage;
                    Sleep(1000);
                    ClearScreen();
                    reloadBattlefield(0);
                    randomizeNumber();
                    printf("\n");
                }


                void userVictory() {
                    char userInput[20];

                    StopMusic();
                    PlayMusic("audio/victory.mp3");
                    ClearLine();
                    printf("\r\t\t\t%s is Unable to Battle...", generatedPkmn);
                    Sleep(2000);
                    ClearLine();
                    printf("\r\t\t\tYou Win!");
                    Sleep(2000);
                    ClearLine();

                    while (1) {
                        printf("\r\t\t\tWould you Like to Proceed To The Next Level? <1> Yes <2> No:  ");
                        gets(userInput);

                        int input = atoi(userInput);

                        switch (input) {
                            case 1:
                                StopMusic();
                                PlayMusic("audio/click.mp3");
                                currLevel++;
                                ClearScreen();
                                isGameRunning = true;
                                DisplayCountdown();
                                StartGame(currDifficulty, currLevel);
                                break;
                            case 2:
                                StopMusic();
                                PlayMusic("audio/click.mp3");
                                ClearScreen();
                                isGameRunning = false;
                                DisplayHomeScreen();
                                break;
                            case 0:
                            default:
                                printf("\033[F");
                                ClearLine();
                                printf("\r\t\t\tInvalid Input");
                                Sleep(1000);
                                ClearLine();
                                continue;
                                break;
                        }
                    }

                }

                void enemyVictory() {

                    ClearLine();
                    printf("\r\t\t\t%s is Unable to Battle...", "Mew");
                    Sleep(2000);
                    ClearLine();
                    printf("\r\t\t\tYou Lose!");
                    Sleep(2000);
                    ClearLine();
                    printf("\r\t\t\tDirecting You Back to the Title Screen...");
                    Sleep(2000);
                    ClearScreen();
                    isGameRunning = false;
                    DisplayHomeScreen();
                }



                randomizeNumber();
                printf("\r\t\t\tGet Ready! The Numbers will Appear in 3..2..1..");
                Sleep(3000);
                ClearLine();
                printf("\r\t\t\t");
                for (int j = 0; j < numLength; j++)
                {
                    printf("%c", generatedNumber[j]);
                }
                Sleep(waitTime);
                // start time
                ClearLine();
                printf("\r\t\t\tGuess the Number: ");

                startTime = time(NULL);
                elapsedTime = 0;

                while (elapsedTime <= 10) {
                    if (_kbhit()) {
                        break;
                    }

                    elapsedTime = difftime(time(NULL), startTime);
                    Sleep(100);
                }


                if (elapsedTime >= 10 && !enemyHitOccurred) { // IF HINDI NAG KBHIT WITHIN 10 SEC AATTACK
                    enemyHit();
                    enemyHitOccurred = true;

                        if (currEnemyLives == 0) {
                            userVictory();
                            break;
                        } else if (currPlayerLives == 0) {
                            enemyVictory();
                            break;
                        }
                    continue;

                }

                bool specialCase = false;

                fgets(userInput, sizeof(userInput), stdin);
                userInput[strcspn(userInput, "\n")] = '\0';
                fflush(stdin);

                if (strcmp(userInput, "r") == 0 || strcmp(userInput, "R") == 0) {
                    specialCase = true;
                    reset--;
                    if (reset <= 0){
                        printf("\r\t\t\tOut of Reset!...");
                        Sleep(1000);
                        ClearLine();
                        specialCase = false; // PAG UBOS NA RESET TAS GUMAMIT PA DEN MAG KA-COUNT AS WRONG ANSWER
                    }
                    ClearLine();
                    printf("\r\t\t\tThe Number Was: ");
                    for (int j = 0; j < numLength; j++) {
                        printf("%c", generatedNumber[j]);
                    }
                    Sleep(1000);
                    ClearLine();
                    printf("\033[F\r");
                }

                if (!specialCase){
                    if (strcmp(userInput, generatedNumber) == 0) {
                        userHit();
                    } else {
                        enemyHit();
                    }
                }

                if (currEnemyLives <= 0) {
                    userVictory();
                } else if (currPlayerLives <= 0) {
                    enemyVictory();
                }

            } while (isGameRunning);

        }

        StopMusic();
        PlayMusic(battleMusic);
        strcat(pkmnFile, generatedPkmn);
        strcat(pkmnFile, ".txt");
        reloadBattlefield(100);
        gameLoop();

    }

    randomizePkmn();
    battleGame();
}


void DisplayPokemonSprite(const char *filename, int indentation, int sleepTime) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char sprite[MAX_SPRITE_SIZE];
    while (fgets(sprite, sizeof(sprite), file) != NULL) {
        // Add indentation
        for (int i = 0; i < indentation; i++) {
            printf(" ");
        }
        printf("%s", sprite);
        Sleep(sleepTime);
    }

    fclose(file);
}

void PlayMusic(const char *filename) {
    char command[256];
    snprintf(command, sizeof(command), "open \"%s\" type mpegvideo alias myMusic", filename);
    mciSendStringA(command, NULL, 0, NULL);

    mciSendStringA("play myMusic", NULL, 0, NULL);
}

void StopMusic() {
    mciSendStringA("stop myMusic", NULL, 0, NULL);
    mciSendStringA("close myMusic", NULL, 0, NULL);
}


void ClearScreen(){
    system("cls");
}

void ClearLine() {
    printf("\033[2K");
}
