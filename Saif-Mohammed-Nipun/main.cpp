#include <bits/stdc++.h>
using namespace std;

class Player
{
public:
    int player_id;
    string country;
    string payer_name;
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
    
    Player *next;
   
 
    Player( int player_id,
            string country,
            string payer_name,
            string date_of_birth,
            int age,
            string role,
            string batting_style,
            string bowling_style,
            int matches_played,
            int runs_scored,
            int wickets_taken,
            int catches_taken,
            float batting_average,
            float bowling_average,
            int strike_rate )
    {
        this->player_id = player_id;
        this->country = country;
        this->payer_name = payer_name;
        this->date_of_birth = date_of_birth;
        this->age = age;
        this->role = role;
        this->batting_style = batting_style;
        this->bowling_style = bowling_style;
        this->matches_played = matches_played;
        this->runs_scored = runs_scored;
        this->wickets_taken = wickets_taken;
        this->catches_taken = catches_taken;
        this->batting_average = batting_average;
        this->bowling_average = bowling_average;
        this->strike_rate = strike_rate;

        this->next = NULL;

    }
};
Player *head = NULL;
Player *tail = NULL;

void showPlayerData()
{

   ifstream inputFile;
   inputFile.open("/Users/saifmohammed/Desktop/Player-Database/Player-Database-CWC-2023.csv");

   if(inputFile.fail())
   {
       cout << "Error opening file" << endl;
        exit(1);
   }

    int player_id;
    string country;
    string payer_name;
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

    string myString;
    string line;

    int count = 0;
    while(getline(inputFile, line))
    {

     try
        {
            stringstream ss(line);

            getline(ss, myString, ',');
            player_id = stoi(myString);

            getline(ss, country, ',');
            getline(ss, payer_name, ',');
            getline(ss, date_of_birth, ',');

            getline(ss, myString, ',');
            age = stoi(myString);

            getline(ss, role, ',');
            getline(ss, batting_style, ',');
            getline(ss, bowling_style, ',');

            getline(ss, myString, ',');
            matches_played = stoi(myString);

            getline(ss, myString, ',');
            runs_scored = stoi(myString);

            getline(ss, myString, ',');
            wickets_taken = stoi(myString);

            getline(ss, myString, ',');
            catches_taken = stoi(myString);

            getline(ss, myString, ',');
            batting_average = (stof(myString));

            getline(ss, myString, ',');
            bowling_average =  stof((myString));

            getline(ss, myString, ',');
            strike_rate = stoi(myString);
    }
    catch (exception e){}

            if(count >= 1)
            {
             cout << player_id << "\t"
                  << country << "\t"
                  << payer_name << "\t"
                  << date_of_birth << "\t"
                  << age << "\t"
                  << role << "\t"
                  << batting_style << "\t"
                  << bowling_style << "\t"
                  << matches_played << "\t"
                  << runs_scored << "\t"
                  << wickets_taken << "\t"
                  << catches_taken << "\t";

            cout << fixed << setprecision(2);
            cout << batting_average << "\t" 
                 << bowling_average << "\t" 
                 << strike_rate << endl;
            }
            
        count++;
    }
}

void readFromFile(){
   ifstream inputFile;
   inputFile.open("/Users/saifmohammed/Desktop/Player-Database/Player-Database-CWC-2023.csv");

   if(inputFile.fail())
   {
       cout << "Error opening file" << endl;
        exit(1);
   }

    int player_id;
    string country;
    string payer_name;
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

    string myString;
    string line;

    int count = 0;
    while(getline(inputFile, line))
    {

     try
        {
            stringstream ss(line);

            getline(ss, myString, ',');
            player_id = stoi(myString);

            getline(ss, country, ',');
            getline(ss, payer_name, ',');
            getline(ss, date_of_birth, ',');

            getline(ss, myString, ',');
            age = stoi(myString);

            getline(ss, role, ',');
            getline(ss, batting_style, ',');
            getline(ss, bowling_style, ',');

            getline(ss, myString, ',');
            matches_played = stoi(myString);

            getline(ss, myString, ',');
            runs_scored = stoi(myString);

            getline(ss, myString, ',');
            wickets_taken = stoi(myString);

            getline(ss, myString, ',');
            catches_taken = stoi(myString);

            getline(ss, myString, ',');
            batting_average = (stof(myString));

            getline(ss, myString, ',');
            bowling_average =  stof((myString));

            getline(ss, myString, ',');
            strike_rate = stoi(myString);
    }
    catch (exception e){}

 }
}
  void searchPlayerData(){}
  void updatePlayerData(){}
  void addPlayerData(){}
  void editPlayerData(){}
  void deletePlayerData(){}


int main()
{
        
    while(true)
    {
       
        cout << "\tPlayer Database For ICC Men's Cricket World Cup 2023"<<endl<<endl;
        
        cout << "\tMain Menu"<<endl;
        cout << "\t1. Show Cricketer List"<<endl;
        cout << "\t2. Add Crickter Information"<<endl;
        cout << "\t3. Update Crickter Information"<<endl;
        cout << "\t4. Delete Crickter Information"<<endl;
        cout << "\t5. Search Crickter Information"<<endl;
        cout << "\t0. Exit"<<endl<<endl;

        cout << "\tEnter Instruction: ";
        int input; 
        cin >> input; 

        switch(input)
        {
            case 1: showPlayerData(); break;
            case 2: searchPlayerData(); break;
            case 3: updatePlayerData(); break;
            case 4: addPlayerData(); break;
            case 5: editPlayerData(); break;
            case 6: deletePlayerData(); break;
            case 0: cout<<"\tSystem Exited Successfully"; exit(0);

        }

    }
    
    return 0;
}
