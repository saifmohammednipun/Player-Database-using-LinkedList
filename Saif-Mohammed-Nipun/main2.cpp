#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

struct Player // Player Structure
{
    // values
    int player_id; 
    string country;
    string player_name;
    string date_of_birth;
    int age;
    string role;
    string batting_style;
    string bowling_style;
    int matches_played;
    int runs_scored;
    int wickets_taken;
    int catches_taken;
    float batting_average;
    float bowling_average;
    int strike_rate;

    Player* next; // Pointer to the next Player
};

Player* head = NULL;  // Pointer to the first Player
Player* tail = NULL;  // Pointer to the last Player

// Create New player data
Player* createPlayerData();

// Initally read player data from file
void readPlayerDataFromFile();

// clear file before writing
void clearFileBeforWriting(string filename);

// Write updated player data in to file 
void writePlayerToCSV(Player* player, string filename);

//  1. Show Cricketer List
void showAllPlayerData(Player* head);
void showIndividualPlayerData(Player* head,int playerID);

// 2. Search Cricketer Information
void searchPlayerDataByPlayerID(int targetPlayerID);
void searchPlayerDataByCountry(string targetCountry);
void searchPlayerDataByPlayerName(string targetPlayerName);
void searchPlayerDataByDateOfBirth(string targetDateOfBirth);
void searchPlayerDataByAge(int targetAge);
void searchPlayerDataByRole(string targetRole);
void searchPlayerDataByBattingStyle(string targetBattingStyle);
void searchPlayerDataByBowlingStyle(string targetBowlingStyle);
void searchPlayerDataByMatchesPlayed(int targetMatchesPlayed);
void searchPlayerDataByRunsScored(int targetRunsScored);
void searchPlayerDataByWicketsTaken(int targetWicketsTaken);
void searchPlayerDataByCatchesTaken(int targetCatchesTaken);
void searchPlayerDataByBattingAverage(float targetBattingAverage);
void searchPlayerDataByBowlingAverage(float targetBowlingAverage);
void searchPlayerDataByStrikeRate(int targetStrikeRate);

// 3. Add Cricketer Information (Insertion)
void addNewPlayerDataAtFront(Player* player, Player*& head);
void addNewPlayerDataAtEnd(Player* player, Player* tail);
void addNewPlayerDataAtPosition(Player* player, int position);

// 4. Update Cricketer Information
void updatePlayerInformation(Player* player, int targetPlayerID);

// 5. Delete Cricketer Information
void deletePlayerDatabase();
void deletePlayerDataByPlayerID(int targetPlayerID);
void deletePlayerDataByPlayerName(string targetPlayerName);
void deletePlayerDataByCountry(string targetCountry);

void deletePlayerDataFromFront(Player* head);
void deletePlayerDataFromEnd(Player* tail);
void deletePlayerDataFromPosition(Player* player, int position);

// 6. Sort Cricketer Information
void sortPlayerDataByPlayerID();
void sortPlayerDataByCountry();
void sortPlayerDataByAge();
void sortPlayerDataByMatchesPlayed();
void sortPlayerDataByRunsScored();
void sortPlayerDataByWicketsTaken();
void sortPlayerDataByCatchesTaken();
void sortPlayerDataByStrikeRate();

// 7. Generate Report
void generateIndividualReport(int targetPlayerID);
void generateTeamReport(string targetCountry);


int main()
{
    readPlayerDataFromFile();

    while (true)
    {
        cout << "\tPlayer Database For ICC Men's Cricket World Cup 2023" << endl << endl;

        cout << "\tMain Menu" << endl;
        cout << "\t1. Show Cricketer List" << endl;
        cout << "\t2. Search Cricketer Information" << endl;
        cout << "\t3. Add Cricketer Information" << endl;
        cout << "\t4. Update Cricketer Information" << endl;
        cout << "\t5. Delete Cricketer Information" << endl;
        cout << "\t6. Sort Cricketer List"<<endl;
        cout << "\t7. Generate Report "<< endl;
        cout << "\t0. Exit" << endl << endl;

        cout << "\tEnter Instruction: ";
        int input;
        cin >> input;

        switch (input)
        {
        case 1: 
        { 
            while(true)
            {
                cout<<"\t\t Show Cricketer Information"<<endl<<endl;
                cout<<"\t1. Show All Cricketers List"<<endl;
                cout<<"\t2. Show Individual Information"<<endl;
                cout<<"\t0. Return Main Menu"<<endl<<endl;
                
                cout<<"\tEnter Instruction: ";
                cin>>input;
                switch(input)
                {
                    case 1:
                    {
                        clearFileBeforWriting("/Users/saifmohammed/Desktop/Player-Database/Modified-Player-Database-CWC-2023.csv");
                        showAllPlayerData(head);
                        break;
                    }
                    case 2:
                    {
                        int id;
                        cout<<"\tEnter Player ID: ";
                        cin>>id;
                        showIndividualPlayerData(head,id);
                        break;
                    }
                    case 0: break;
                    default: cout << "\tInvalid input. Please try again." << endl;
                }
                if(input==0)
                break;
            }
        }
        break;
        case 2:
        {
            while(true)
            {
                cout << "\t\tSearch Cricketer Information" << endl<<endl;
                cout << "\t1. Search by Player ID" << endl;
                cout << "\t2. Search by Country" << endl;
                cout << "\t3. Search by Player Name" << endl;
                cout << "\t4. Search by Date of Birth" << endl;
                cout << "\t5. Search by Age" << endl;
                cout << "\t6. Search by Role" << endl;
                cout << "\t7. Search by Batting Style" << endl;
                cout << "\t8. Search by Bowling Style" << endl;
                cout << "\t9. Search by Matches Played" << endl;
                cout << "\t10. Search by Runs Scored" << endl;
                cout << "\t11. Search by Wickets Taken" << endl;
                cout << "\t12. Search by Catches Taken" << endl;
                cout << "\t13. Search by Batting Average" << endl;
                cout << "\t14. Search by Bowling Average" << endl;
                cout << "\t15. Search by Strike Rate" << endl << endl;
                cout << "\t0. Return Main Menu" << endl << endl;

                cout << "\tEnter Instruction: ";
                int input;
                cin >> input;

                switch (input)
                {
                    case 1:
                    {
                        cout << "\tEnter Player ID: ";
                        int playerID;
                        cin >> playerID;
                        searchPlayerDataByPlayerID(playerID);
                        break;
                    }
                   
                    case 2:
                    {
                        cout << "\tEnter Country: ";
                        string country;
                        cin.ignore();
                        getline(cin, country);
                        searchPlayerDataByCountry(country);
                        break;
                    }
                    case 3:
                    {
                        cout << "\tEnter Player Name: ";
                        string playerName;
                        cin.ignore();
                        getline(cin, playerName);
                        searchPlayerDataByPlayerName(playerName);
                        break;
                    }
                    case 4:
                    {
                        cout << "\tEnter Date of Birth: ";
                        string dateOfBirth;
                        cin.ignore();
                        getline(cin, dateOfBirth);
                        searchPlayerDataByDateOfBirth(dateOfBirth);
                        break;
                    }
                    case 5:
                    { 
                        cout << "\tEnter Age: ";
                        int age;
                        cin >> age;
                        searchPlayerDataByAge(age);
                        break;
                    }
                    case 6:
                    {
                        cout << "\tEnter Role: ";
                        string role;
                        cin.ignore();
                        getline(cin, role);
                        searchPlayerDataByRole(role);
                        break;
                    }
                    case 7:
                    {
                        cout << "\tEnter Batting Style: ";
                        string battingStyle;
                        cin.ignore();
                        getline(cin, battingStyle);
                        searchPlayerDataByBattingStyle(battingStyle);
                        break;
                    }
                    case 8:
                    {
                        cout << "\tEnter Bowling Style: ";
                        string bowlingStyle;
                        cin.ignore();
                        getline(cin, bowlingStyle);
                        searchPlayerDataByBowlingStyle(bowlingStyle);
                        break;
                    }
                    case 9:
                    {
                        cout << "\tEnter Matches Played: ";
                        int matchesPlayed;
                        cin >> matchesPlayed;
                        searchPlayerDataByMatchesPlayed(matchesPlayed);
                        break;
                    }
                    case 10:
                    {
                        cout << "\tEnter Runs Scored: ";
                        int runsScored;
                        cin >> runsScored;
                        searchPlayerDataByRunsScored(runsScored);
                        break;
                    }
                    case 11:
                    {
                        cout << "\tEnter Wickets Taken: ";
                        int wicketsTaken;
                        cin >> wicketsTaken;
                        searchPlayerDataByWicketsTaken(wicketsTaken);
                        break;
                    }
                    case 12:
                    {
                        cout << "\tEnter Catches Taken: ";
                        int catchesTaken;
                        cin >> catchesTaken;
                        searchPlayerDataByCatchesTaken(catchesTaken);
                        break;
                    }
                    case 13:
                    {
                        cout << "\tEnter Batting Average: ";
                        float battingAverage;
                        cin >> battingAverage;
                        searchPlayerDataByBattingAverage(battingAverage);
                        break;
                    }
                    case 14:
                    {
                        cout << "\tEnter Bowling Average: ";
                        float bowlingAverage;
                        cin >> bowlingAverage;
                        searchPlayerDataByBowlingAverage(bowlingAverage);
                        break;
                    }
                    case 15:
                    {
                        cout << "\tEnter Strike Rate: ";
                        int strikeRate;
                        cin >> strikeRate;
                        searchPlayerDataByStrikeRate(strikeRate);
                        break;
                    } 
                    case 0 : break;
                    default: cout << "\tInvalid input. Please try again." << endl;
            }
            if(input==0)
            break;
          }

        } 
        break;  
        case 3:
        {   
            while(true)
            {
                cout<<"\t\tAdd Cricketer Information"<<endl<<endl;
                cout<<"\t1. Add New Player Data at Front"<<endl;
                cout<<"\t2. Add New Player Data at End"<<endl;
                cout<<"\t3. Add New Player Data at Position"<<endl;
                cout<<"\t0. Return Main Menu"<<endl<<endl;
                
                cout<<"\tEnter Instruction: ";
                cin>>input;
                switch(input)
                {
                    case 1:
                    {
                        Player* newPlayer = createPlayerData();
                        if (newPlayer != NULL)
                        {
                            addNewPlayerDataAtFront(newPlayer, head);
                            clearFileBeforWriting("/Users/saifmohammed/Desktop/Player-Database/Modified-Player-Database-CWC-2023.csv");
                            showAllPlayerData(head);
                            cout<<"New Player Data Added Successfully at the Front"<<endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        Player* newPlayer = createPlayerData();
                        if (newPlayer != NULL)
                        {
                            addNewPlayerDataAtEnd(newPlayer, tail);
                            clearFileBeforWriting("/Users/saifmohammed/Desktop/Player-Database/Modified-Player-Database-CWC-2023.csv");
                            showAllPlayerData(head);
                            cout<<"New Player Data Added Successfully at the End"<<endl;
                        }
                        break;
                    }
                    case 3:
                    {
                        Player* newPlayer = createPlayerData();
                        if (newPlayer != NULL)
                        {
                            cout << "Enter position: ";
                            int position;
                            cin >> position;
                            addNewPlayerDataAtPosition(newPlayer, position);
                            clearFileBeforWriting("/Users/saifmohammed/Desktop/Player-Database/Modified-Player-Database-CWC-2023.csv");
                            showAllPlayerData(head);
                            cout<<"Player Data Added Successfully at "<<position<<" Position"<<endl;
                        }
                        break;
                    }
                    case 0: break;
                    default: cout << "\tInvalid input. Please try again." << endl;
                }
                if(input==0)
                break;
            }
        }
        break;
        case 4: 
        {
            int targetPlayerID;
            cout << "Enter Player ID you want to update: ";
            cin >> targetPlayerID;

            updatePlayerInformation(head,targetPlayerID); 

            break;
        }
        case 5:
        {
            while(true)
            {
                cout<< "Player Data Deletion"<<endl<<endl;
                cout<<"\t1. Delete Player Data by Player ID"<<endl;
                cout<<"\t2. Delete Player Data by Player Name"<<endl;
                cout<<"\t3. Delete Player Data by Country"<<endl;
                
                cout<< "\t4. Delete Plater Data From Front"<<endl;
                cout<< "\t5. Delete Player Data From End"<<endl;
                cout<< "\t6. Delete Player Data From Any Position"<<endl;
                cout<< "\t7. Delete Whole Player Database"<<endl;
                cout<<"\t0. Return Main Menu"<<endl<<endl;

                cout << "\tEnter Instruction: ";
                cin>>input;
                switch(input)
                {
                    case 1: 
                    {
                        cout << "Enter Player ID: ";
                        int playerID;
                        cin >> playerID;
                        deletePlayerDataByPlayerID(playerID);
                        cout<<"Player Data Deleted Successfully By Player ID"<<endl;
                        break;
                    }
                    case 2:
                    {
                        cout << "Enter Player Name: ";
                        string playerName;
                        cin.ignore();
                        getline(cin, playerName);
                        deletePlayerDataByPlayerName(playerName);
                        cout<<"Player Data Deleted Successfully By Player Name"<<endl;
                        break;
                    }
                    case 3:
                    {
                        cout << "Enter Country: ";
                        string country;
                        cin.ignore();
                        getline(cin, country);
                        deletePlayerDataByCountry(country);
                        cout<<"Player Data Deleted Successfully By Country"<<endl;
                        break;
                    }
                    case 4:
                    {
                        deletePlayerDataFromFront(head);
                        cout<<"Player Data Deleted Successfully From Front"<<endl;
                        break;
                    }
                    case 5:
                    {
                        deletePlayerDataFromEnd(tail);
                        cout<<"Player Data Deleted Successfully From End"<<endl;
                        break;
                    }
                    case 6:
                    {
                        cout << "Enter position: ";
                        int position;
                        cin >> position;
                        deletePlayerDataFromPosition(head, position);
                        cout<<"Player Data Deleted Successfully From "<<position<<" Position"<<endl;
                        break;
                    }
                    case 7:
                    {
                        deletePlayerDatabase();
                        cout<<"Player Database Deleted Successfully"<<endl;
                        break;
                    }

                    case 0: break;
                    default: cout << "\tInvalid input. Please try again." << endl;
                }
            
             if(input==0)
             break;
            }
        }
           
            break;
        case 6:
        {   
            while(true)
            {
                cout<<"\tSort Player Information"<<endl<<endl;  
                cout<<"\t1. Sort Cricketers by PlayerID" <<endl;
                cout<<"\t2. Sort Cricketers by Country" <<endl;
                cout<<"\t3. Sort Cricketer by Age " <<endl;
                cout<<"\t4. Sort Cricketer by Match Played " <<endl;
                cout<<"\t5. Sort Cricketer by Run Scored"<<endl;
                cout<<"\t6. Sort Cricketer by Wickets Taken" <<endl;
                cout<<"\t7. Sort Cricketer by Catches Taken" <<endl;
                cout<<"\t8. Sort Cricketer by Strike Rate" <<endl <<endl;
            
                
                cout<<"\tEnter Instruction: ";
                cin>>input;
                switch(input)
                {
                    case 1:
                    {
                        
                        sortPlayerDataByPlayerID();
                        cout<<"Sorted Cricketers by PlayerID Successfully."<<endl;
                        
                    }break;
                    case 2:
                    {
                        sortPlayerDataByCountry();
                        cout<<"Sorted Cricketers by Country Successfully."<<endl;
                        break;
                    }
                    case 3:
                    {
                        sortPlayerDataByAge();
                        cout<<"Sorted Cricketers by Age Successfully."<<endl;
                        break;
                    }
                    case 4:
                    {
                        sortPlayerDataByMatchesPlayed();
                        cout<<"Sorted Cricketers by Matches Played Successfully."<<endl;
                        break;
                    }
                    case 5:
                    {
                        sortPlayerDataByRunsScored();
                        cout<<"Sorted Cricketers by Runs Scored Successfully."<<endl;
                        break;
                    }
                    case 6:
                    {
                        sortPlayerDataByWicketsTaken();
                        cout<<"Sorted Cricketers by Wickets Taken Successfully."<<endl;
                        break;
                    }
                    case 7:
                    {
                        sortPlayerDataByCatchesTaken();
                        cout<<"Sorted Cricketers by Catches Taken Successfully."<<endl;
                        break;
                    }
                    case 8:
                    {
                        sortPlayerDataByStrikeRate();
                        cout<<"Sorted Cricketers by Strike Rate Successfully."<<endl;
                        break;
                    }
                    case 0: break;
                    default: cout << "\tInvalid input. Please try again." << endl;
                }
                if(input==0)
                break;
            }
        }
        break;
        case 7: 
        {
            while(true)
            {
                cout<<"\t\tGenerate Report"<<endl<<endl;
                cout<<"\t1. Generate Individual Report"<<endl;
                cout<<"\t2. Generate Team Report"<<endl;
                cout<<"\t0. Return Main Menu"<<endl<<endl;
                
                cout<<"\tEnter Instruction: ";
                cin>>input;
                switch(input)
                {
                    case 1:
                    {
                        int playerID;
                        cout<<"\tEnter Player ID: ";
                        cin>>playerID;
                        clearFileBeforWriting("/Users/saifmohammed/Desktop/Player-Database/Player-Report.txt");
                        generateIndividualReport(playerID);
                        break;
                    }
                    case 2:
                    {
                        string country;
                        cout<<"\tEnter Country: ";
                        cin.ignore();
                        getline(cin, country);
                        clearFileBeforWriting("/Users/saifmohammed/Desktop/Player-Database/Player-Report.txt");
                        generateTeamReport(country);
                        break;
                    }
                    case 0: break;
                    default: cout << "\tInvalid input. Please try again." << endl;
                }
                if(input==0)
                break;
            }
           
        } break;
        case 0:
            cout << "\tPlayer Database System Exited Successfully";
            exit(0);
        }
    }

    return 0;
}

// Function to create a new Player
Player* createPlayerData()
{
    Player* newPlayer = new Player; // Create a new dynamic Player object

    cout << "Enter Player ID: ";
    cin >> newPlayer->player_id;

    // Check if a player with the same ID already exists
    Player* current = head;
    bool isDuplicate = false;
    while (current != NULL)
    {
        if (current->player_id == newPlayer->player_id && current->player_id<=0)
        {
            isDuplicate = true;
            cout << "A player with the same ID already exists, or Player id is less than 0" << endl;
            break;
        }
        current = current->next;
    }

    if (!isDuplicate)
    {
        cout << "Enter Country: ";
        cin.ignore(); 
        getline(cin, newPlayer->country);

        cout << "Enter Player Name: ";
        getline(cin, newPlayer->player_name);

        cout << "Enter Date of Birth: ";
        getline(cin, newPlayer->date_of_birth);

        cout << "Enter Age: ";
        cin >> newPlayer->age;

        cout << "Enter Role: ";
        cin.ignore();
        getline(cin, newPlayer->role);

        cout << "Enter Batting Style: ";
        getline(cin, newPlayer->batting_style);

        cout << "Enter Bowling Style: ";
        getline(cin, newPlayer->bowling_style);

        cout << "Enter Matches Played: ";
        cin >> newPlayer->matches_played;

        cout << "Enter Runs Scored: ";
        cin >> newPlayer->runs_scored;

        cout << "Enter Wickets Taken: ";
        cin >> newPlayer->wickets_taken;

        cout << "Enter Catches Taken: ";
        cin >> newPlayer->catches_taken;

        cout << "Player Batting Average: ";
        newPlayer->batting_average = newPlayer->runs_scored / newPlayer->matches_played;
        cout<< newPlayer->batting_average<<endl;

        cout << "Player Bowling Average: ";
        newPlayer->bowling_average = newPlayer->matches_played / newPlayer->wickets_taken;
        cout<< newPlayer->bowling_average<<endl;

        cout << "Enter Strike Rate: ";
        cin >> newPlayer->strike_rate;

        newPlayer->next = NULL;
    }
    else
    {
        // If a player with the same ID exists, don't add the new player.
        delete newPlayer;
        newPlayer = NULL; // Set the pointer to NULL to avoid dangling pointer
    }

    return newPlayer;
}

// read player data from file
void readPlayerDataFromFile()
{
    ifstream inputFile;
    inputFile.open("/Users/saifmohammed/Desktop/Player-Database/Player-Database-CWC-2023.csv");

    if (inputFile.fail())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }

    string line;
    int count = 0;

    while (getline(inputFile, line)) // Read a line from the file
    {
        if (count >= 1)
        {
            Player* player = new Player;
            stringstream ss(line); // Convert the line to a stringstream

            ss >> player->player_id;
            ss.ignore(); // Ignore the comma
            getline(ss, player->country, ',');
            getline(ss, player->player_name, ',');
            getline(ss, player->date_of_birth, ',');
            ss >> player->age;
            ss.ignore();
            getline(ss, player->role, ',');
            getline(ss, player->batting_style, ',');
            getline(ss, player->bowling_style, ',');
            ss >> player->matches_played;
            ss.ignore();
            ss >> player->runs_scored;
            ss.ignore();
            ss >> player->wickets_taken;
            ss.ignore();
            ss >> player->catches_taken;
            ss.ignore();
            ss >> player->batting_average;
            ss.ignore();
            ss >> player->bowling_average;
            ss.ignore();
            ss >> player->strike_rate;

            player->next = NULL;

            if (head == NULL) // If the list is empty
            {
                head = player;
                tail = player;
            }
            else // If the list is not empty
            {
                tail->next = player;
                tail = player;
            }
        }
        count++;
    }
    inputFile.close();
}

void printPlayerData(Player* player)
{
    cout << player->player_id << setw(15)
            << player->country << setw(22)
            << player->player_name << setw(13)
            << player->date_of_birth << setw(8)
            << player->age << setw(23)
            << player->role << setw(20)
            << player->batting_style << setw(24)
            << player->bowling_style << setw(10)
            << player->matches_played << setw(10)
            << player->runs_scored << setw(10)
            << player->wickets_taken << setw(10)
            << player->catches_taken << setw(10);
    cout << fixed << setprecision(2);
    cout << player->batting_average << setw(10)
            << player->bowling_average << setw(10)
            << player->strike_rate << endl;
}

void clearFileBeforWriting(string filename)
{
    // Open the file with ios::trunc to clear existing content
    ofstream clearFile(filename, ios::trunc);

    if (!clearFile.is_open())
    {
        cout << "Error opening file for clearing." << endl;
        return;
    }

    clearFile.close();
}

 // Function to write a Player to a .csv file
void writePlayerToCSV(Player* player, string filename)
{
    
    // Open the output file in append mode
   ofstream outputFile(filename, ios::app);

    if (!outputFile.is_open()) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    // Write the Player data to the .csv file
    outputFile << player->player_id << ","
               << player->player_name << ","
               << player->country << ","
               << player->date_of_birth << ","
               << player->age << ","
               << player->role << ","
               << player->batting_style << ","
               << player->bowling_style << ","
               << player->matches_played << ","
               << player->runs_scored << ","
               << player->wickets_taken << ","
               << player->catches_taken << ","
               << player->batting_average << ","
               << player->bowling_average << ","
               << player->strike_rate << "\n";

    // Close the output file
    outputFile.close();
}


void writePlayerToTxT(Player* player, string filename)
{
    
    // Open the output file in append mode
   ofstream outputFile(filename, ios::app);

    if (!outputFile.is_open()) {
        cout << "Error opening file for writing." << endl;
        return;
    }

    // Write the Player data to the .txt file
             outputFile<< "Player ID " << "\t\t : " << player->player_id << "\n";
             outputFile<< "Country " << "\t\t : " << player->country << "\n";
             outputFile<< "Player Name " << "\t : " << player->player_name << "\n";
             outputFile<< "Date of Birth " << "\t : " << player->date_of_birth << "\n";
             outputFile<< "Player Age " << "\t\t : " << player->age << "\n";
             outputFile<< "Player Role " << "\t : " << player->role << "\n";
             outputFile<< "Batting Style " << "\t : " << player->batting_style << "\n";
             outputFile<< "Bowling Style " << "\t : " << player->bowling_style << "\n";
             outputFile<< "Matches Played " << "\t : " << player->matches_played << "\n";
             outputFile<< "Runs Scored " << "\t : " << player->runs_scored << "\n";
             outputFile<< "Wickets Taken " << "\t : " << player->wickets_taken << "\n";
             outputFile<< "Catches Taken " << "\t : " << player->catches_taken << "\n";
             outputFile<< "Batting Average" << "\t : " << player->batting_average << "\n";
             outputFile<< "Bowling Average" << "\t : "<< player->bowling_average << "\n";
             outputFile<< "Strike Rate " << "\t : " << player->strike_rate << "\n\n\n";;  

    // Close the output file
    outputFile.close();
}

void showAllPlayerData(Player* head)
{
    Player* current = head;

    cout << "Player Data:" << endl;
    cout<<"ID"<<setw(15)<< "Country"<<setw(22)<<"Player Name"<<setw(16)<<"Date of Birth"<<setw(6)<<"Age"<<setw(22)<<"Role"<<setw(20)<<"Batting Style"<<setw(20)<<"Bowling Style"<<setw(15)<<"M.P."<<setw(9)<<"Runs"<<setw(10)<<"Wickets"<<setw(10)<<"Catches"<<setw(10)<<"Bat Avg"<<setw(10)<<"Bowl Avg"<<setw(10)<<"SR"<<endl;
    
    while (current != NULL) // Traverse the list Big O(n)
    {
        printPlayerData(current);
        writePlayerToCSV(current, "/Users/saifmohammed/Desktop/Player-Database/Modified-Player-Database-CWC-2023.csv");
        
        current = current->next; 
    }
}

void showIndividualPlayerData(Player* head, int targetPlayerID)
{
    Player* current = head;
    bool found = false;

    while (current != NULL)
    {
        if (current->player_id == targetPlayerID)
        {
            found = true;

            cout<<"Individual Player Data:"<<endl<<endl;
            cout<< "Player ID " << "\t\t : " << current->player_id << endl;
            cout<< "Country " << "\t\t : " << current->country << endl;
            cout<< "Player Name " << "\t : " << current->player_name << endl;
            cout<< "Date of Birth " << "\t : " << current->date_of_birth << endl;
            cout<< "Player Age " << "\t\t : " << current->age << endl;
            cout<< "Player Role " << "\t : " << current->role << endl;
            cout<< "Batting Style " << "\t : " << current->batting_style << endl;
            cout<< "Bowling Style " << "\t : " << current->bowling_style << endl;
            cout<< "Matches Played " << "\t : " << current->matches_played << endl;
            cout<< "Runs Scored " << "\t : " << current->runs_scored << endl;
            cout<< "Wickets Taken " << "\t : " << current->wickets_taken << endl;
            cout<< "Catches Taken " << "\t : " << current->catches_taken << endl;
            cout<< "Batting Average" << "\t : " << current->batting_average << endl;
            cout<< "Bowling Average" << "\t : "<< current->bowling_average << endl;
            cout<< "Strike Rate " << "\t : " << current->strike_rate << endl;                

        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with ID " << targetPlayerID << endl;
    }

}

void searchPlayerDataByPlayerID(int targetPlayerID)
{
    Player* current = head;
    bool found = false;

    while (current != NULL)
    {
        if (current->player_id == targetPlayerID)
        {
            found = true;
            printPlayerData(current);
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with ID " << targetPlayerID << endl;
    }
}

void searchPlayerDataByCountry(string targetCountry)
{
    Player* current = head;
    bool found = false;

    cout << "Players from " << targetCountry << ":" << endl;

    while (current != NULL)
    {
        if (current->country == targetCountry)
        {
            found = true;
            printPlayerData(current);
           
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found from " << targetCountry << endl;
    }
}

void searchPlayerDataByPlayerName(string targetPlayerName)
{
    Player* current = head;
    bool found = false;

    cout << "Players with name " << targetPlayerName << ":" << endl;

    while (current != NULL)
    {
        if (current->player_name == targetPlayerName)
        {
            found = true;
            printPlayerData(current);
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with name " << targetPlayerName << endl;
    }
}

void searchPlayerDataByDateOfBirth(string targetDateOfBirth)
{
    Player* current = head;
    bool found = false;

    cout << "Players with date of birth " << targetDateOfBirth << ":" << endl;

    while (current != NULL)
    {
        if (current->date_of_birth == targetDateOfBirth)
        {
            found = true;
            printPlayerData(current);
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with date of birth " << targetDateOfBirth << endl;
    }
}

void searchPlayerDataByAge(int targetAge)
{
    Player* current = head;
    bool found = false;

    cout << "Players with age " << targetAge << ":" << endl;

    while (current != NULL)
    {
        if (current->age == targetAge)
        {
            found = true;
            printPlayerData(current);
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with age " << targetAge << endl;
    }
}


void searchPlayerDataByRole(string targetRole)
{
    Player* current = head;
    bool found = false;

    cout << "Players with role " << targetRole << ":" << endl;

    while (current != NULL)
    {
        if (current->role == targetRole)
        {
            found = true;
            printPlayerData(current);
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with role " << targetRole << endl;
    }
}


void searchPlayerDataByBattingStyle(string targetBattingStyle)
{
    Player* current = head;
    bool found = false;

    cout << "Players with batting style " << targetBattingStyle << ":" << endl;

    while (current != NULL)
    {
        if (current->batting_style == targetBattingStyle)
        {
            found = true;
            printPlayerData(current);
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with batting style " << targetBattingStyle << endl;
    }
}


void searchPlayerDataByBowlingStyle(string targetBowlingStyle)
{
    Player* current = head;
    bool found = false;

    cout << "Players with bowling style " << targetBowlingStyle << ":" << endl;

    while (current != NULL)
    {
        if (current->bowling_style == targetBowlingStyle)
        {
            found = true;
            printPlayerData(current);
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with bowling style " << targetBowlingStyle << endl;
    }
}


void searchPlayerDataByMatchesPlayed(int targetMatchesPlayed)
{
    Player* current = head;
    bool found = false;

    cout << "Players with matches played " << targetMatchesPlayed << ":" << endl;

    while (current != NULL)
    {
        if (current->matches_played >= targetMatchesPlayed)
        {
            found = true;
            printPlayerData(current);

        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with matches played " << targetMatchesPlayed << endl;
    }
}

void searchPlayerDataByRunsScored(int targetRunsScored)
{
    Player* current = head;
    bool found = false;

    cout << "Players with runs scored " << targetRunsScored << ":" << endl;

    while (current != NULL)
    {
        if (current->runs_scored >= targetRunsScored)
        {
            found = true;
           printPlayerData(current);
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with runs scored " << targetRunsScored << endl;
    }
}


void searchPlayerDataByWicketsTaken(int targetWicketsTaken)
{
    Player* current = head;
    bool found = false;

    cout << "Players with wickets taken " << targetWicketsTaken << ":" << endl;

    while (current != NULL)
    {
        if (current->wickets_taken >= targetWicketsTaken)
        {
            found = true;
            printPlayerData(current);
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with wickets taken " << targetWicketsTaken << endl;
    }
}


void searchPlayerDataByCatchesTaken(int targetCatchesTaken)
{
    Player* current = head;
    bool found = false;

    cout << "Players with catches taken " << targetCatchesTaken << ":" << endl;

    while (current != NULL)
    {
        if (current->catches_taken >= targetCatchesTaken)
        {
            found = true;
            printPlayerData(current);
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with catches taken " << targetCatchesTaken << endl;
    }
}


void searchPlayerDataByBattingAverage(float targetBattingAverage)
{
    Player* current = head;
    bool found = false;

    cout << "Players with batting average " << targetBattingAverage << ":" << endl;

    while (current != NULL)
    {
        if (current->batting_average >= targetBattingAverage)
        {
            found = true;
            printPlayerData(current);
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with batting average " << targetBattingAverage << endl;
    }
}

void searchPlayerDataByBowlingAverage(float targetBowlingAverage)
{
    Player* current = head;
    bool found = false;

    cout << "Players with bowling average " << targetBowlingAverage << ":" << endl;

    while (current != NULL)
    {
        if (current->bowling_average <= targetBowlingAverage)
        {
            found = true;
            printPlayerData(current);
        }
        current = current->next;
    }
    if (!found)
    {
        cout << "No players found with bowling average " << targetBowlingAverage << endl;
    }
}



void searchPlayerDataByStrikeRate(int targetStrikeRate)
{
    Player* current = head;
    bool found = false;

    cout << "Players with strike rate " << targetStrikeRate << ":" << endl;

    while (current != NULL)
    {
        if (current->strike_rate >= targetStrikeRate)
        {
            found = true;
            printPlayerData(current);
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with strike rate " << targetStrikeRate << endl;
    }
}



//Add New Player Data at front
void addNewPlayerDataAtFront(Player* player, Player*& head)
{
    player->next = head; // Make the new player point to the current head
    head = player; // Update the head to the new player
}


void addNewPlayerDataAtEnd(Player* player, Player* tail)
{
    if (tail == NULL)
    {
        head = player;
        tail = player;
    }
    else
    {
        // Time Complexity - Big O(1) 
        tail->next = player; // Make the current tail point to the new player
        tail = player; // Make the new player the new tail
    }
}


// Add New Player Data at any Position
void addNewPlayerDataAtPosition(Player* player, int position)
{
    if (position == 1)
    {
        addNewPlayerDataAtFront(player, head);
    }

    else
    {
        Player* current = head;
        int count = 1;

        // Time Complexity - Big O(n)
        while (current != NULL && count < position - 1) // Stop at the node before the position
        {
            current = current->next; // Move to the next node
            count++; 
        }

        if (current != NULL) // If the position is valid
        {
            player->next = current->next; // Make the new player point to the node at the position
            current->next = player; // Make the node before the position point to the new player
        }
        else
        {
            cout << "Invalid position" << endl;
        }
    }
}

//Update Player Information
void updatePlayerInformation(Player* head, int targetPlayerID)
{
    Player* current = head;
    bool found = false;

    while (current != NULL) // Time Complexity Big O(N) // Linear Sarch 
    {
        if (current->player_id == targetPlayerID)
        {
            found = true;
            cout<<endl;
            cout<<"Player Data: "<<endl;
            printPlayerData(current);

                cout<<"\t1. Update Player ID"<<endl;
                cout<<"\t2. Update Player Name"<<endl;
                cout<<"\t3. Update Country"<<endl;
                cout<<"\t4. Update Date of Birth"<<endl;
                cout<<"\t5. Update Age"<<endl;
                cout<<"\t6. Update Role"<<endl;
                cout<<"\t7. Update Batting Style"<<endl;
                cout<<"\t8. Update Bowling Style"<<endl;
                cout<<"\t9. Update Matches Played"<<endl;
                cout<<"\t10. Update Runs Scored"<<endl;
                cout<<"\t11. Update Wickets Taken"<<endl;
                cout<<"\t12. Update Catches Taken"<<endl;
                cout<<"\t13. Update Batting Average"<<endl;
                cout<<"\t14. Update Bowling Average"<<endl;
                cout<<"\t15. Update Strike Rate"<<endl;
                cout<<"\t0. Return Main Menu"<<endl<<endl;

            while(true)
            {
               cout<< "\tDo you want to update any information?";
               cout<<"\tYes - (1-15)";
               cout<<"\tNo - (0)"<<endl;

                cout<<"\tEnter Instruction: ";
                int input;
                cin>>input;

                current->batting_average = current->runs_scored / (2*current->matches_played);
                switch(input)
                {
                    // You can't directly change the Player ID as it's unique.
                    case 1: cout << "Player ID cannot be updated." << endl;
                    break;
                    case 2:
                    {
                        cout << "Enter Player Name: ";
                        string playerName;
                        cin.ignore();
                        getline(cin, playerName);
                        current->player_name=playerName;
                        cout << "Player Name " << playerName << " updated successfully." << endl;
                        break;
                    }
                    case 3:
                    {
                        cout << "Enter Country: ";
                        string country;
                        cin.ignore();
                        getline(cin, country);
                        current->country = country; 
                        cout << "Country " << country << " updated successfully." << endl;
                        break;
                    }
                    case 4:
                    {
                        cout << "Enter Date of Birth: ";
                        string dateOfBirth;
                        cin.ignore();
                        getline(cin, dateOfBirth);
                        current->date_of_birth=dateOfBirth;
                        cout<<"Date of Birth "<<dateOfBirth<<" updated successfully."<<endl;
                        break;
                    }
                    case 5:
                    { 
                        cout << "Enter Age: ";
                        int age;
                        cin >> age;
                        current->age=age;
                        cout<<"Age "<<age<<" updated successfully."<<endl;
                        break;
                    }
                    case 6:
                    {
                        cout << "Enter Role: ";
                        string role;
                        cin.ignore();
                        getline(cin, role);
                        current->role=role;
                        cout<<"Role "<<role<<" updated successfully."<<endl;
                        break;
                    }
                    case 7:
                    {
                        cout << "Enter Batting Style: ";
                        string battingStyle;
                        cin.ignore();
                        getline(cin, battingStyle);
                        current->batting_style=battingStyle;
                        cout<<"Batting Style "<<battingStyle<<" updated successfully."<<endl;
                        break;
                    }
                    case 8:
                    {
                        cout << "Enter Bowling Style: ";
                        string bowlingStyle;
                        cin.ignore();
                        getline(cin, bowlingStyle);
                        current->bowling_style=bowlingStyle;
                        cout<<"Bowling Style "<<bowlingStyle<<" updated successfully."<<endl;
                        break;
                    }
                    case 9:
                    {
                        cout << "Enter Matches Played: ";
                        int matchesPlayed;
                        cin >> matchesPlayed;
                        current->matches_played = matchesPlayed;
                        cout<<"Matches Played "<<matchesPlayed<<" updated successfully."<<endl;
                        break;
                    }
                    case 10:
                    {
                        cout << "Enter Runs Scored: ";
                        int runsScored;
                        cin >> runsScored;
                        current->runs_scored=runsScored;
                        cout<<"Runs Scored "<<runsScored<<" updated successfully."<<endl;
                        break;
                    }
                    case 11:
                    {
                        cout << "Enter Wickets Taken: ";
                        int wicketsTaken;
                        cin >> wicketsTaken;
                        current->wickets_taken=wicketsTaken;
                        cout<<"Wickets Taken "<<wicketsTaken<<" updated successfully."<<endl;
                        break;
                    }

                    case 12:
                    {
                        cout << "Enter Catches Taken: ";
                        int catchesTaken;
                        cin >> catchesTaken;
                        current->catches_taken=catchesTaken;
                        cout<<"Catches Taken "<<catchesTaken<<" updated successfully."<<endl;
                        break;
                    }
                    case 13:
                    {
                        cout << "Player Batting Average: ";
                        current->batting_average = current->runs_scored / (2*current->matches_played);
                        cout<< current->batting_average <<endl<<"Updated successfully."<<endl;
                        break;
                    }
                    case 14:
                    {
                        cout << "Enter Bowling Average: ";
                        int bowlingAverage;
                        cin >> bowlingAverage;
                        current->bowling_average=bowlingAverage;
                        cout<<current->bowling_average<<endl<<"Updated successfully."<<endl;
                        break;
                    }
                    case 15:
                    {
                        cout << "Enter Strike Rate: ";
                        int strikeRate;
                        cin >> strikeRate;
                        current->strike_rate=strikeRate;
                        
                        break;
                    
                    case 0 : break;
                    default: cout << "\tInvalid input. Please try again." << endl;
                    }
                }
                if(input==0)
                {
                    cout<<endl;
                cout<<"Updated Player Data:"<<endl;
                printPlayerData(current);
                cout<<endl;
                break;
                }
            }
        }
        current = current->next; // Move to the next node
    }

    if (!found)
    {
        cout << "No players found with ID " << targetPlayerID << endl;
    }
 }



// Delete Player Information
void deletePlayerDatabase()
{
    Player* current = head;
    Player* next;

    while (current != NULL)
    {
        next = current->next; // Store the next node
        delete current; // Delete the current node
        current = next; // Move to the next node
    }

    head = NULL;
    tail = NULL;
}


void deletePlayerDataByPlayerID(int targetPlayerID)
{
    Player* current = head;
    Player* previous = NULL;
    bool found = false;

    while (current != NULL)
    {
        if (current->player_id == targetPlayerID)
        {
            found = true;
            if (previous == NULL) // If the node to be deleted is the head
            {
                head = current->next; // Make the next node the new head
                delete current; // Delete the current node
                current = head; // Move to the new head
            }
            else
            {
                previous->next = current->next; // Make the previous node point to the node after the current node
                delete current; 
                current = previous->next;
            }
        }
        else
        {
            previous = current;
            current = current->next; // Move to the next node
        } 
    }

    if (!found)
    {
        cout << "No players found with ID " << targetPlayerID << endl;
    }
}

void deletePlayerDataByPlayerName(string targetPlayerName)
{
    Player* current = head;
    Player* previous = NULL;
    bool found = false;

    while (current != NULL)
    {
        if (current->player_name == targetPlayerName)
        {
            found = true;
            if (previous == NULL)
            {
                head = current->next;
                delete current;
                current = head;
            }
            else
            {
                previous->next = current->next;
                delete current;
                current = previous->next;
            }
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    if (!found)
    {
        cout << "No players found with name " << targetPlayerName << endl;
    }
}

void deletePlayerDataByCountry(string targetCountry)
{
    Player* current = head;
    Player* previous = NULL;
    bool found = false;

    while (current != NULL)
    {
        if (current->country == targetCountry)
        {
            found = true;
            if (previous == NULL)
            {
                head = current->next;
                delete current;
                current = head;
            }
            else
            {
                previous->next = current->next;
                delete current;
                current = previous->next;
            }
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    if (!found)
    {
        cout << "No players found from " << targetCountry << endl;
    }
}

void deletePlayerDataFromFront(Player* head)
{
    if (head == nullptr) {
        cout << "List is empty. Cannot delete from the front." << endl;
        return;
    }

    Player* temp = head;
    head = head->next; // Make the next node the new head
    delete temp; // Delete the current head
}

void deletePlayerDataFromEnd(Player* head)
{
    if (head == nullptr) {
        cout << "List is empty. Cannot delete from the end." << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Player* current = head;
    Player* previous = nullptr;

    while (current->next != nullptr) {
        previous = current;
        current = current->next;
    }

    delete current; 
    previous->next = nullptr;
}


void deletePlayerDataFromPosition(Player* head, int position)
{
    if (position <= 0) {
        cout << "Invalid position. Position should be a positive integer." << endl;
        return;
    }

    if (position == 1) {
        deletePlayerDataFromFront(head);
        return;
    }

    Player* current = head;
    Player* previous = nullptr;
    int count = 1;

    while (current != nullptr && count < position) {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Invalid position. Position exceeds the number of elements in the list." << endl;
        return;
    }

    previous->next = current->next;  
    delete current;
}

//Sort Player Data by Player ID
void sortPlayerDataByPlayerID() {
    if (head == NULL) {
        // Empty list, nothing to sort
        return;
    }

    Player* sortedList = NULL; // Initialize a new list to store sorted players

    while (head != NULL) {
        Player* current = head;
        head = head->next;

        if (sortedList == NULL || current->player_id < sortedList->player_id) {
            // Insert the current player at the beginning of the sorted list
            current->next = sortedList;
            sortedList = current;
        } else {
            // Find the appropriate position to insert the current player
            Player* temp = sortedList;
            while (temp->next != NULL && temp->next->player_id < current->player_id) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    // Update the head and tail pointers to the sorted list
    head = sortedList;
    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
}

//Sort Player Data by Country
void sortPlayerDataByCountry()
{
    if (head == NULL) {
        // Empty list, nothing to sort
        return;
    }

    Player* sortedList = NULL; // Initialize a new list to store sorted players

    while (head != NULL) {
        Player* current = head;
        head = head->next;

        if (sortedList == NULL || current->country < sortedList->country) {
            // Insert the current player at the beginning of the sorted list
            current->next = sortedList;
            sortedList = current;
        } else {
            // Find the appropriate position to insert the current player
            Player* temp = sortedList;
            while (temp->next != NULL && temp->next->country < current->country) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    // Update the head and tail pointers to the sorted list
    head = sortedList;
    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
}

//Sort Player Data by Age
void sortPlayerDataByAge()
{
    if (head == NULL) {
        // Empty list, nothing to sort
        return;
    }

    Player* sortedList = NULL; // Initialize a new list to store sorted players

    while (head != NULL) {
        Player* current = head;
        head = head->next;

        if (sortedList == NULL || current->age < sortedList->age) {
            // Insert the current player at the beginning of the sorted list
            current->next = sortedList;
            sortedList = current;
        } else {
            // Find the appropriate position to insert the current player
            Player* temp = sortedList;
            while (temp->next != NULL && temp->next->age < current->age) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    // Update the head and tail pointers to the sorted list
    head = sortedList;
    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
}


//Sort Player Data by Matches Played
void sortPlayerDataByMatchesPlayed()
{   
    if (head == NULL) {
        // Empty list, nothing to sort
        return;
    }

    Player* sortedList = NULL; // Initialize a new list to store sorted players

    while (head != NULL) {
        Player* current = head;
        head = head->next;

        if (sortedList == NULL || current->matches_played < sortedList->matches_played) {
            // Insert the current player at the beginning of the sorted list
            current->next = sortedList;
            sortedList = current;
        } else {
            // Find the appropriate position to insert the current player
            Player* temp = sortedList;
            while (temp->next != NULL && temp->next->matches_played < current->matches_played) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    // Update the head and tail pointers to the sorted list
    head = sortedList;
    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
}

//Sort Player Data by Runs Scored
void sortPlayerDataByRunsScored()
{
    if (head == NULL) {
        // Empty list, nothing to sort
        return;
    }

    Player* sortedList = NULL; // Initialize a new list to store sorted players

    while (head != NULL) {
        Player* current = head;
        head = head->next;

        if (sortedList == NULL || current->runs_scored < sortedList->runs_scored) {
            // Insert the current player at the beginning of the sorted list
            current->next = sortedList;
            sortedList = current;
        } else {
            // Find the appropriate position to insert the current player
            Player* temp = sortedList;
            while (temp->next != NULL && temp->next->runs_scored < current->runs_scored) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    // Update the head and tail pointers to the sorted list
    head = sortedList;
    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
}

//Sort Player Data by Wickets Taken
void sortPlayerDataByWicketsTaken()
{
    if (head == NULL) {
        // Empty list, nothing to sort
        return;
    }

    Player* sortedList = NULL; // Initialize a new list to store sorted players

    while (head != NULL) {
        Player* current = head;
        head = head->next;

        if (sortedList == NULL || current->wickets_taken < sortedList->wickets_taken) {
            // Insert the current player at the beginning of the sorted list
            current->next = sortedList;
            sortedList = current;
        } else {
            // Find the appropriate position to insert the current player
            Player* temp = sortedList;
            while (temp->next != NULL && temp->next->wickets_taken < current->wickets_taken) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    // Update the head and tail pointers to the sorted list
    head = sortedList;
    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
}

//Sort Player Data by Catches Taken
void sortPlayerDataByCatchesTaken()
{
    if (head == NULL) {
        // Empty list, nothing to sort
        return;
    }

    Player* sortedList = NULL; // Initialize a new list to store sorted players

    while (head != NULL) {
        Player* current = head;
        head = head->next;

        if (sortedList == NULL || current->catches_taken < sortedList->catches_taken) {
            // Insert the current player at the beginning of the sorted list
            current->next = sortedList;
            sortedList = current;
        } else {
            // Find the appropriate position to insert the current player
            Player* temp = sortedList;
            while (temp->next != NULL && temp->next->catches_taken < current->catches_taken) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    // Update the head and tail pointers to the sorted list
    head = sortedList;
    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
}

//Sort Player Data by Batting Average
void sortPlayerDataByBattingAverage()
{
    if (head == NULL) {
        // Empty list, nothing to sort
        return;
    }

    Player* sortedList = NULL; // Initialize a new list to store sorted players

    while (head != NULL) {
        Player* current = head;
        head = head->next;

        if (sortedList == NULL || current->batting_average < sortedList->batting_average) {
            // Insert the current player at the beginning of the sorted list
            current->next = sortedList;
            sortedList = current;
        } else {
            // Find the appropriate position to insert the current player
            Player* temp = sortedList;
            while (temp->next != NULL && temp->next->batting_average < current->batting_average) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    // Update the head and tail pointers to the sorted list
    head = sortedList;
    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
}

//Sort Player Data by Bowling Average
void sortPlayerDataByBowlingAverage()
{
    if (head == NULL) {
        // Empty list, nothing to sort
        return;
    }

    Player* sortedList = NULL; // Initialize a new list to store sorted players

    while (head != NULL) {
        Player* current = head;
        head = head->next;

        if (sortedList == NULL || current->bowling_average < sortedList->bowling_average) {
            // Insert the current player at the beginning of the sorted list
            current->next = sortedList;
            sortedList = current;
        } else {
            // Find the appropriate position to insert the current player
            Player* temp = sortedList;
            while (temp->next != NULL && temp->next->bowling_average < current->bowling_average) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    // Update the head and tail pointers to the sorted list
    head = sortedList;
    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
}

//Sort Player Data by Strike Rate
void sortPlayerDataByStrikeRate()
{
    if (head == NULL) {
        // Empty list, nothing to sort
        return;
    }

    Player* sortedList = NULL; // Initialize a new list to store sorted players

    while (head != NULL) {
        Player* current = head;
        head = head->next;

        if (sortedList == NULL || current->strike_rate < sortedList->strike_rate) {
            // Insert the current player at the beginning of the sorted list
            current->next = sortedList;
            sortedList = current;
        } else {
            // Find the appropriate position to insert the current player
            Player* temp = sortedList;
            while (temp->next != NULL && temp->next->strike_rate < current->strike_rate) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }

    // Update the head and tail pointers to the sorted list
    head = sortedList;
    tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
}


void generateIndividualReport(int targetPlayerID)
{
    Player* current = head;
    bool found = false;

    while (current != NULL)
    {
        if (current->player_id == targetPlayerID)
        {
            found = true;
            showIndividualPlayerData(current, targetPlayerID);
            writePlayerToTxT(current, "/Users/saifmohammed/Desktop/Player-Database/Player-Report.txt");
            
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found with ID " << targetPlayerID << endl;
    }
}


void generateTeamReport(string targetCountry)
{
    Player* current = head;
    bool found = false;
    
    sortPlayerDataByPlayerID();

    while (current != NULL)
    {
        if (current->country == targetCountry)
        {
            found = true;
            writePlayerToTxT(current, "/Users/saifmohammed/Desktop/Player-Database/Player-Report.txt");
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No players found from " << targetCountry << endl;
    }
}

