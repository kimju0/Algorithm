#include <iostream>
#include <cstdlib>
#include <ctime>

// Define the number of players and rounds
const int NUM_PLAYERS = 5;  // This should be the number of students
const int NUM_ROUNDS = 100;
const int ARRAY_SIZE = 5;

// Function to generate a random array of natural numbers between 1 and 100
void generateArray(int array[]) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        array[i] = (i + 1) * 10;
    }
}

// PlayerFormat is a base class that defines a common interface and data structure for different types of players.
class PlayerFormat {
protected:
    float score; // score is used to keep track of the player's game score.
    int bets[NUM_ROUNDS]; // bets stores the player's bets for each round.

public:
    int AllPlayerBets[NUM_ROUNDS][ARRAY_SIZE]; // A 2D array that records all bets made by all players across rounds.
    long StudentID; // Default StudentID, should be overwritten by derived classes if necessary.

    // Constructor initializes the score and the arrays.
    PlayerFormat() : score(0) {
        // Initialize the bets array with 0, implying no bets made initially.
        for (int i = 0; i < NUM_ROUNDS; ++i) {
            bets[i] = 0;
        }
        // Initialize the AllPlayerBets array with -1, denoting that no bets have been placed.
        for (int i = 0; i < NUM_ROUNDS; ++i) {
            for (int j = 0; j < ARRAY_SIZE; ++j) {
                AllPlayerBets[i][j] = -1;
            }
        }
    }

    // Virtual function to be overridden by derived classes for deciding the bet based on the game state.
    virtual void decideBet(int round, const int numbers[], const int previousBets[]) {};

    // Set a bet for a given round.
    void setID(long id) {
        StudentID = id;
    }

    // Set a bet for a given round.
    void setBet(int round, int bet) {
        bets[round] = bet;
    }

    // Retrieve the bet for a given round.
    int getBet(int round) const {
        return bets[round];
    }

    // Update the score of the player based on the number chosen and the number of bets on that number.
    void updateScore(int round, int number, int numBetsOnNumber, const int AllBets[]) {
        // The score is increased by the number chosen divided by the number of bets on that number.
        score += number / float(numBetsOnNumber);
        // Record the bets for all players in the current round into the AllPlayerBets array.
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            AllPlayerBets[round][i] = AllBets[i];
        }
    }

    // Retrieve the current score of the player.
    int getScore() const {
        return score;
    }
};

class Player_20200000 : public PlayerFormat {
public:
    long StudentID = 20200000;

    Player_20200000() {
        setID(StudentID);
    }

    void decideBet(int round, const int numbers[], const int previousBets[]) {
        int bet = (std::rand() % ARRAY_SIZE); // Random bet
        setBet(round, bet);
    }
};

class Player_20210000 : public PlayerFormat {
public:
    long StudentID = 20210000;

    Player_20210000() {
        setID(StudentID);
    }

    void decideBet(int round, const int numbers[], const int previousBets[]) {
        int bet = (std::rand() % ARRAY_SIZE); // Random bet
        setBet(round, bet);
    }
};

class Player_20220000 : public PlayerFormat {
public:
    long StudentID = 20220000;

    Player_20220000() {
        setID(StudentID);
    }

    void decideBet(int round, const int numbers[], const int previousBets[]) {
        int bet = 3; // Bet on 40
        setBet(round, bet);
    }
};

class Player_20230000 : public PlayerFormat {
public:
    long StudentID = 20230000;

    Player_20230000() {
        setID(StudentID);
    }

    void decideBet(int round, const int numbers[], const int previousBets[]) {
        int bet = 4; // Bet on 50
        setBet(round, bet);
    }
};


/*
YOUR IMPLEMENTATION START
*/

class Player_20223908 : public PlayerFormat { // 이름 바꿔주기 Player_XXXXXXXX -> Player_실제학번
public:
    long StudentID = 20223908; // -------------실제학번을 이 변수에 할당-------------

    Player_20223908() { // 이름 바꿔주기 Player_XXXXXXXX -> Player_실제학번
        setID(StudentID);
    }

    // Function for the player to decide the bet for the current round
    // Here we are just betting randomly, students should replace this logic with their own
    void decideBet(int round, const int numbers[], const int previousBets[]) {
        /*
        round: round index
        numbers[]: 1D arrary of [10, 20, 30, 40, 50]
        previousBets[]: 2D array with a size of NUM_ROUNDS*ARRAY_SIZE. A history data of the number of students for each bet
        */
        // Basic decision making based on previously learned algorithms (e.g., greedy algorithms)
        // For example, a greedy approach might be to always bet on the number that was least bet on in the previous round
        // This is a placeholder, students should implement their own logic

        for (int j = 0; j < ARRAY_SIZE; j++) {
            //std::cout << previousBets[j] << " ";
        }
        //std::cout << std::endl;

        if(ARRAY_SIZE<2){
            setBet(round, 0);
            return;
        }

        int fir = 0, sec = -1;
        for (int j = 1; j < ARRAY_SIZE; j++) {
            double weight= numbers[j] / (double) previousBets[j] + 1;
            if (weight > numbers[fir] / (double) previousBets[fir] + 1) {
                sec = fir;
                fir = j;
            } else if (sec==-1||weight > numbers[sec] / (double) previousBets[sec] + 1) {
                sec = j;
            }
        }

        int bet = sec;
        //std::cout<<bet<<std::endl;
        //int bet = (std::rand() % ARRAY_SIZE); // An Example of Random bet
        setBet(round, bet);
    }
};

/*
YOUR IMPLEMENTATION END
*/

// Function to simulate a round of the game
void playRound(int round, PlayerFormat *players[], const int numbers[], int previousBets[]) {
    int betsCount[ARRAY_SIZE] = {0}; // Counts the number of bets on each number

    // Each player decides their bet
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        players[i]->decideBet(round, numbers, previousBets);
        int bet = players[i]->getBet(round);
        betsCount[bet]++;
    }

    // Output the number of players for each number
    std::cout << "Round " << round + 1 << ":" << " Value(Num. of Players): ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << numbers[i] << "(" << betsCount[i] << ") ";
    }
    std::cout << std::endl;

    // Update scores for each player based on the bets
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        int bet = players[i]->getBet(round);
        players[i]->updateScore(round, numbers[bet], betsCount[bet], betsCount);

        // Output the scores of all players in each round
        std::cout << "Round " << round + 1 << ": Player " << players[i]->StudentID << " score: "
                  << numbers[bet] / float(betsCount[bet]) << std::endl;
    }
    std::cout << std::endl;

    // Update the previousBets array to be used in the next round
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        previousBets[i] = betsCount[i];
    }
}


int main() {
    std::srand(static_cast<unsigned>(std::time(0))); // Seed random number generator

    PlayerFormat *players[NUM_PLAYERS];  // Create an array of Player pointers
    players[0] = new Player_20200000();
    players[1] = new Player_20210000();
    players[2] = new Player_20220000();
    players[3] = new Player_20230000();
    players[4] = new Player_20223908(); // 이름 바꿔주기 Player_XXXXXXXX -> Player_실제학번

    int previousBets[ARRAY_SIZE] = {0}; // Stores the number of bets on each number from the previous round

    for (int round = 0; round < NUM_ROUNDS; ++round) {
        int numbers[ARRAY_SIZE];
        generateArray(numbers); // Generate a new set of numbers for the round

        playRound(round, players, numbers, previousBets);
    }

    // Output the scores of all players
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        std::cout << "Player " << i + 1 << " score: " << players[i]->getScore() << std::endl;
    }

    return 0;
}