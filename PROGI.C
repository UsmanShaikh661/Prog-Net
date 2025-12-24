#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char currentPlayer = 'X';

// Function Declarations for pattern codes
void calculator();
void guess();
void rps();
void factoeia();
void ascending();
void descending();
void trianglePattern();
void boxPattern();
void lop();
void palindro();
void primenoc();
void soe();
void for_lop();
void while_lop();
void do_while_lop();
void drawBoard();
void switchPlayer();
int checkWin();
int checkDraw();
void playerMove();
int ttt();
void info();
void extracti();
void extracti2();
void displayCandidates();
int checkIfVoted(char voterID[]);
void vote();
void showResults();
int shaib();

void main() {
    int choice;
    // FILE *checkFile;

    // checkFile = fopen("C:\\TurboC++\\Disk\\TurboC3\\BIN\\prognet\\txt.txt", "r");
    // if (checkFile == NULL) {
    //     checkFile = fopen("C:\\TurboC++\\Disk\\TurboC3\\BIN\\prognet\\txt.txt", "w");
    //     fprintf(checkFile, "0");
    //     fclose(checkFile);
    // } else {
    //     fclose(checkFile);
    // }

    printf("\t\t==== Welcom TO Prog-Net ====\n");
    info();
    clrscr();
    while (1) {
        clrscr();

        // printf("==== Prog-Net Menu ====\n");
        // printf("Enter code number (1 to 12) to run specific code\n");
        /*
                    ==== Prog-Net Menu ====
        Enter code number to run specific code...
        ================================================
        1: Calculator           | 9: for_loop e.g.
        2: Guess the Number     | 10: while_loop e.g.
        3: Rock Paper Scissors  | 11: do_while_loop e.g.
        4: Factoeial Finder     | 12: Tic Tac Tow
        5: loop e.g.            | 13: info
        6: Palindrom checker    | 14: extracti
        7: sum of Prime Numbers | 15: extracti2
        8: Sum of Even Numbers  | 16: sohaib
                                
        */

        
	    printf("\t\t==== Prog-Net Menu ====\nEnter code number to run specific code...\n================================================\n1: Calculator           | 9: for_loop e.g.\n2: Guess the Number     | 10: while_loop e.g.\n3: Rock Paper Scissors  | 11: do_while_loop e.g.\n4: Factoeial Finder     | 12: Tic Tac Tow\n5: loop e.g.| 13: info\n6: Palindrom checker    | 14: extracti\n7: sum of Prime Numbers | 15: extracti2\n8: Sum of Even Numbers  | 16: sohaib\n");
        printf("--> Your choice: ");
        scanf("%d", &choice);
        
        clrscr();
        
        switch (choice) {
            case 0: exit(0);
            case 1: calculator(); break;
            case 2: guess(); break;
            case 3: rps(); break;
            case 4: factoeia(); break;
            case 5: lop(); break;
            case 6: palindro(); break;
            case 7: primenoc(); break;
            case 8: soe(); break;
            case 9: for_lop(); break;
            case 10: while_lop(); break;
            case 11: do_while_lop(); break;
            case 12: ttt(); break;
            case 13: info(); break;
	        case 14: extracti(); break;
	        case 15: extracti2(); break;
		    case 16: shaib(); break;
            default: printf("Invalid choice!\n");
        }
        printf("\nPress any key to return to menu...");
        getch();
    }
}

// === All Code Functions ===

void calculator(){
    int a;
    int b;
    // float c;
    
    clrscr();

    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);
    // printf("Enter value of c: ");
    // scanf("%f", &c);
    
    printf("a + b = %d + %d = %d\n", a, b, a + b);
    printf("a - b = %d - %d = %d\n", a, b, a - b);
    printf("b - a = %d - %d = %d\n", b, a, b - a);
    printf("a * b = %d * %d = %d\n", a, b, a * b);
    printf("a / b = %d / %d = %.2f\n", a, b, (float)a / b);
    printf("b / a = %d / %d = %.2f\n", b, a, (float)b / a);
    printf("a ^ 2 = %d ^ 2 = %d\n", a, (a * a));
    printf("b ^ 2 = %d ^ 2 = %d\n", b, (b * b));
    
    // printf("%2.f", exp2(c));
    getch();

}

void guess()
{
  int number_guess_by_user;
  int number_of_guesses = 0;
  int random_number;

  clrscr();

  srand(time(0));
  random_number = (rand() % 101);

  do
  {
    printf("guess the number b/w 1-100: ");
    scanf("%d", &number_guess_by_user);
    number_of_guesses = number_of_guesses + 1;

    if (number_guess_by_user > random_number)
    {
      printf("----smaller\n");
    }
    else if (number_guess_by_user < random_number)
    {
      printf("----larger\n");
    }

  } while (number_guess_by_user != random_number);

  printf("---- you guessed the number ----\n");
  printf("-------------- %d --------------\n", number_of_guesses);


  getche();

}

const char* getChoice(int choice) {
    if (choice == 0) return "Rock";
    else if (choice == 1) return "Paper";
    else return "Scissors";
}

// Function to decide the winner of a round
void checkWinner(int user, int computer) {
    printf("You chose: %s\n", getChoice(user));
    printf("Computer chose: %s\n", getChoice(computer));

    if (user == computer) {
        printf("Result: It's a draw!\n");
    }
    else if ((user == 0 && computer == 2) ||
             (user == 1 && computer == 0) ||
             (user == 2 && computer == 1)) {
        printf("Result: You win this round!\n");
    }
    else {
	printf("Result: Computer wins this round!\n");
    }

    printf("---------------------------\n");
}

void rps() {
    int userChoice, computerChoice;
    int rounds = 7;
    int i;

    clrscr();

    srand(time(NULL)); // seed random

    printf("=== Rock Paper Scissors ===\n");
    printf("0 - Rock | 1 - Paper | 2 - Scissors\n");
    printf("You will play 7 rounds.\n");
    printf("---------------------------\n");

    for (i = 1; i <= rounds; i++) {
	printf("Round %d: Enter your choice (0-2): ", i);
	scanf("%d", &userChoice);

        if (userChoice < 0 || userChoice > 2) {
            printf("Invalid choice. Skipping round.\n");
            printf("---------------------------\n");
            continue;
        }

        computerChoice = rand() % 3;
        checkWinner(userChoice, computerChoice);
    }

    printf("Game Over. Thanks for playing!\n");

    getche();

}

void factoeia()
{
    double f = 1;
    int num, n;

    clrscr(); // in Turbo C++

    printf("Enter the number greater than 0 to find its factorial: ");
    scanf("%d", &num);

    while (num < 0)
    {
        printf("Error! Number is less than 0.\n");
        printf("Please enter the number greater than 0.\n");
        scanf("%d", &num);
    }

    for (n = 1; n <= num; n++)
    {
        f *= n;
    }

    printf("\nThe factorial of %d is %.0lf", num, f);

    getch();
}

void lop() {
    int choice;
    clrscr();

    printf("Select a program to run:\n");
    printf("1. Ascending (1 to 10)\n");
    printf("2. Descending (10 to 1)\n");
    printf("3. Right-Angled Triangle Pattern\n");
    printf("4. Box Pattern (5x5 numbers)\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    clrscr();  // Clears the screen (Turbo C++ specific)

    switch (choice) {
        case 1:
            ascending();
            break;
        case 2:
            descending();
            break;
        case 3:
            trianglePattern();
            break;
        case 4:
            boxPattern();
            break;
        default:
            printf("Invalid choice!\n");
    }

    getch();
}

void ascending() {
    int a;
    printf("Ascending Numbers from 1 to 10:\n");
    for (a = 1; a <= 10; a++) {
        printf("%d\n", a);
    }
}

void descending() {
    int a;
    printf("Descending Numbers from 10 to 1:\n");
    for (a = 10; a >= 1; a--) {
        printf("%d\n", a);
    }
}

void trianglePattern() {
    int row, col;
    printf("Right-Angled Triangle Pattern:\n");
    for (row = 1; row <= 5; row++) {
        for (col = 1; col <= row; col++) {
            printf("%d", col);
        }
        printf("\n");
    }
}

void boxPattern() {
    int row, col;
    printf("5x5 Box Pattern:\n");
    for (row = 1; row <= 5; row++) {
        for (col = 1; col <= 5; col++) {
            printf("%d", col);
        }
        printf("\n");
    }
}

void palindro()
{
    int n, temp, rev = 0, r;
    clrscr();
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;
    while (n > 0)
    {
        r = n % 10;
        rev = rev * 10 + r;
        n = n / 10;
    }
    if (rev == temp)
        printf("Palindrome");
    else
        printf("Not Palindrome");
    getch();
}

void primenoc()
{
    int n, i, count = 0;
    clrscr();
    printf("Enter a number: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
	if (n % i == 0)
	    count++;
    }
    if (count == 2)
	printf("Prime");
    else
	printf("Not Prime");
    getch();
}

void soe()
{
    int n, sum, i;
    clrscr();

    do {
        printf("Enter an even number: ");
        if (scanf("%d", &n) != 1) {
            printf("Invalid input. plz enter a again___\n");
            while (getchar() != '\n'); 
            continue; 
        }

        if (n % 2 != 0) {
            printf("The number %d is not an even number. Try again.\n", n);
        }

    } while (n % 2 != 0); 

    
    sum = 0;
    for (i = 2; i <= n; i += 2) {
        sum += i;
    }

    printf("The sum of even numbers from 2 to %d is %d\n", n, sum);

    getche();

}

void while_lop(){
    int a, b, c;
    b = 1;

    clrscr();

    printf("Enter Table Number: ");
    scanf("%d", &a);

    while (b <= 10)
    {
	c = a * b;
	printf("%d x %d = %d\n", a, b, c);
	b++;
    }
    getche();
}

void for_lop(){
    int a, b, c;
    b = 1;

    clrscr();

    printf("Enter Table Number: ");
    scanf("%d", &a);

    for (b = 1; b <= 12; b++) {
        c = a * b;
        printf("%d x %d = %d\n", a, b, c);
    }
    getche();
}

void do_while_lop(){
    int a, b, c;
    b = 1;

    clrscr();

    printf("Enter the Number: ");
    scanf("%d", &a);

    do
    {
	c = a * b;
	printf("%d x %d = %d\n", a, b, c);
	b++;
    } while (b <= 10);
    getche();
}

void drawBoard()
{
    printf("\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
    printf("\n");
}

void switchPlayer()
{
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

int checkWin()
{
    // Rows
    if ((board[0] == board[1] && board[1] == board[2]) ||
        (board[3] == board[4] && board[4] == board[5]) ||
        (board[6] == board[7] && board[7] == board[8]))
        return 1;

    // Columns
    if ((board[0] == board[3] && board[3] == board[6]) ||
        (board[1] == board[4] && board[4] == board[7]) ||
        (board[2] == board[5] && board[5] == board[8]))
        return 1;

    // Diagonals
    if ((board[0] == board[4] && board[4] == board[8]) ||
        (board[2] == board[4] && board[4] == board[6]))
        return 1;

    return 0;
}

int checkDraw()
{
    int i;
    for (i = 0; i < 9; i++)
    {
	if (board[i] != 'X' && board[i] != 'O')
	    return 0; // still moves left
    }
    return 1; // board full and no winner
}

void playerMove()
{
    int pos;
    printf("Player %c, enter your move (1-9): ", currentPlayer);
    scanf("%d", &pos);
    pos--; // adjust for index 0

    if (pos >= 0 && pos < 9 && board[pos] != 'X' && board[pos] != 'O')
    {
	board[pos] = currentPlayer;
    }
    else
    {
	printf("Invalid move! Try again.\n");
	playerMove(); // retry
    }
}

int ttt()
{
    printf("Welcome to Tic Tac Toe!\n");

    while (1)
    {
	drawBoard();
	playerMove();

	if (checkWin())
	{
	    drawBoard();
	    printf("Player %c wins!\n", currentPlayer);
	    break;
	}

	if (checkDraw())
	{
	    drawBoard();
	    printf("It's a draw!\n");
	    break;
	}

	switchPlayer();
    }

    return 0;
}

void info(){

    char name[125];
    int age;
    char department[40];
    int i = 0;
    FILE *yamlFile;
    FILE *countFile;

    // clrscr();  // Clear screen (optional for Turbo C++)

    // Read current index from txt.txt
    countFile = fopen("txt.txt", "r");
    if (countFile != NULL)
    {
        fscanf(countFile, "%d", &i);
        fclose(countFile);
    }

    // Open yaml-like text file to append
    yamlFile = fopen("Data_of_info.txt", "a");  // use .txt to avoid Turbo C++ errors
    if (yamlFile == NULL)
    {
        printf("Could not open output file.\n");
        getch();
        return;
    }

    // Take input
    i++;
    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Age: ");
    scanf("%d", &age);
    printf("Enter Department: ");
    scanf("%s", department);

    // Write to "YAML-style" format
    fprintf(yamlFile, "\n%d:\n  Name: %s\n  Age: %d\n  Department: %s\n", i, name, age, department);
    fclose(yamlFile);

    // Save the updated index
    countFile = fopen("txt.txt", "w");
    fprintf(countFile, "%d", i);
    fclose(countFile);

    getch();

}

void extracti(){
    
    FILE *yamlFile;
    char line[150];

    clrscr();  // Clear screen for Turbo C++

    yamlFile = fopen("Data_of_info.txt", "r");

    if (yamlFile == NULL)
    {
        printf("Could not open Data_of_info.txt for reading.\n");
        getch();
        return;
    }

    printf("------ Extracted Data ------\n\n");

    while (fgets(line, sizeof(line), yamlFile) != NULL)
    {
        // Print each line directly (already formatted in YAML-style)
        printf("%s", line);
    }

    fclose(yamlFile);

    
    getch();

}

void extracti2(){
    FILE *yamlFile;
    char line[150];
    int searchId, currentId;
    int found = 0;

    clrscr();  // Clear screen for Turbo C

    printf("Enter the ID to search: ");
    scanf("%d", &searchId);

    yamlFile = fopen("Data_of_info.txt", "r");

    if (yamlFile == NULL) {
        printf("Could not open Data_of_info.txt for reading.\n");
        getch();
        return;
    }

    printf("\n------ Extracted Data for ID: %d ------\n\n", searchId);

    while (fgets(line, sizeof(line), yamlFile) != NULL) {
        // Check if the line starts with a number followed by ":"
        if (sscanf(line, "%d:", &currentId) == 1) {
            if (found) break; // Already found the right ID and finished printing
            if (currentId == searchId) {
                found = 1;
                printf("%s", line); // Print the ID line
            }
        } else if (found) {
            // Continue printing the data after ID line
            printf("%s", line);
        }
    }

    if (!found) {
        printf("No entry found for ID: %d\n", searchId);
    }

    fclose(yamlFile);
    getch();  // Wait for key press


}



#define MAX_VOTERS 100
#define MAX_CANDIDATES 3

// Structure for candidates
struct Candidate {
    char name[50];
    int votes;
};

// Array of candidates
struct Candidate candidates[MAX_CANDIDATES] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Charlie", 0}
};

// Array to track voters who have already voted
char votedVoters[MAX_VOTERS][50];
int voterCount = 0;

void displayCandidates() {
    int i;
    printf("\nCandidates:\n");

    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("- %s\n", candidates[i].name);
    }
}

int checkIfVoted(char voterID[]) {
    int i;
    for (i = 0; i < voterCount; i++) {
	if (strcmp(votedVoters[i], voterID) == 0) {
	    return 1; // Voter has already voted
	}
    }
    return 0; // Voter has not voted
}

void vote() {
    char voterID[50], choice[50];
    int i;
    // Check if the candidate is valid
    int validChoice = 0;

    printf("Enter your Voter ID: ");
    scanf("%s", voterID);

    // Check if the voter has already voted
    if (checkIfVoted(voterID)) {
	printf("You have already voted.\n");
	return;
    }

    // Display candidates
    displayCandidates();

    // Get the candidate choice from the user
    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", choice);


    for (i = 0; i < MAX_CANDIDATES; i++) {
	if (strcmp(candidates[i].name, choice) == 0) {
	    candidates[i].votes++;
	    validChoice = 1;
	    break;
        }
    }

    if (validChoice) {
        // Record the voter as having voted
        strcpy(votedVoters[voterCount], voterID);
        voterCount++;
        printf("Your vote for %s has been recorded.\n", choice);
    } else {
        printf("Invalid candidate name.\n");
    }
}

void showResults() {
    int maxVotes = -1;
    int i;
    char winner[50];
    printf("\n--- Voting Results ---\n");

    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d vote(s)\n", candidates[i].name, candidates[i].votes);
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            strcpy(winner, candidates[i].name);
        }
    }

    printf("Winner: %s\n", winner);
}

int shaib() {
    int choice;
    while (1) {
        printf("\n1. Vote\n2. Show Results\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                vote();
                break;
            case 2:
                showResults();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
}