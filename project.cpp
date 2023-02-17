
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>
//#include <regex>
#include <stdio.h>
#include<string>
#include <graphics.h> 
#include <stdio.h> 
#include <windows.h>

  
  using namespace std;
  class Player
{
protected:
    string name;
    int shirtNo;
    float average;
    int icc_ranking_T20;
    int total_runs;
    int matches_played;
    int total_wickets;

public:
    virtual void addPlayer() = 0;
    virtual void removePlayer() = 0;
    virtual void searchPlayer() = 0;
    virtual void updatePlayer() = 0;
};

class Team : public Player {
public:
    string name;
    int ICCRanking;
    int noOfPlayers;
    int matchesWon;
    int matchesLost;
    string teamCaptain;
    string teamCoach;
    string adminUsername;
    string adminPassword;

public:
    Team() {
        adminUsername = "fahad";
        adminPassword = "admin";



    }

    void addPlayer();
    void removePlayer();
    void searchPlayer();
    void updatePlayer();
    void displayMatches();
    void updateCaptain();
    void updateCoach();
    void displayTeam();
};

class Match :public Team {
    string team1;
    string team2;
    string date;
    string venue;
    string match_type;
    string tournament_name;
    string commentators;
    string umpires;
    string matchstatus;
    string score1, score2;
    string out1, out2;
    string points;
    int temp;
public:
    void conductMatch();
    void recentMatch();
    void teamRanking();
    void displayTeamRanking();
    void displayUpcomingMatches();
    void displayRecentMatches();
    void matches();

};


class News : public Match
{
private:
    string news, photos, videos;

public:
    void browseNews();
    void displayRecentMatches();
    void displayICCRanking();
};


class Worldrecord {
    string name;
    string shirt_no;
    int sixes;
    int fours;
    int wickets;
    int runs;
    
    
public:

    int found=0;
    void displaymostsixes();
    void updatemostsixes();
    void entermostsixes();
    void displaymostwickets();
    void updatemostwickets();
    void entermostwickets();
    void displaymostruns();
    void entermostruns();
    void updatemostruns();
    void records();
};

void Team::addPlayer(){
    cleardevice();
    settextstyle(BOLD_FONT,HORIZ_DIR,2); 
    outtextxy(10,10,"Enter player details");
    outtextxy(10,40," (name, shirt number)");
    outtextxy(10,70," average, ICC ranking): ");
    std::cin >> name >> shirtNo >> average >> ICCRanking;
    
    //set font and size
    outtextxy(50,100,"Player Added Successfully"); //display text
    delay(9000); //delay for 3 seconds

    ofstream fout;
    fout.open("team.txt", ios::app);
    fout << name << " " << shirtNo << " " << average << " " << ICCRanking;
    fout << endl;
    cleardevice();
    displayTeam();        
    fout.close();


}
void Team::removePlayer() {
	
    outtextxy(10,10, "Enter the name of player to be removed: ");
    string name;
    std::cin >> name;
    ifstream fin;
    ofstream fout;
    fin.open("team.txt");
    fout.open("temp.txt");
    string line;
    while (getline(fin, line)) {
        string tempName = line.substr(0, line.find(' '));
        if (name != tempName) {
            fout << line << endl;
        }
    }
    fin.close();
    fout.close();
    system("pause");
    std::remove("team.txt");
    std::rename("temp.txt", "team.txt");
    //add graphics
    initwindow(600, 600, "Player Removed");
    outtextxy(200, 250, "Player removed successfully");
    getch();
    cleardevice();
    displayTeam();    
}

void Team::searchPlayer() {
	cleardevice();
    outtextxy(10,10,"Enter the name of player to be searched: ");
    string name;
    std::cin >> name;
    ifstream fin;
    fin.open("team.txt");
    string line;
    while (getline(fin, line)) {
        string tempName = line.substr(0, line.find(' '));
        if (name == tempName) {
            std::cout << line << endl;
            //add graphics
            initwindow(600, 600, "Player Found");
            outtextxy(200, 250, "Player Found");
            getch();
            break;
        }
    }
    fin.close();
    system("pause");
        cleardevice();
 
}
void Team::updatePlayer() {
    outtextxy(100,40,"Enter the name of player to be updated: ");
    string name;
    std::cin >> name;
    ifstream fin;
    ofstream fout;
    fin.open("team.txt");
    fout.open("temp.txt");
    string line;
    while (getline(fin, line)) {
        string tempName = line.substr(0, line.find(' '));
        if (name != tempName) {
            fout << line << endl;
        }
        else {
            int gd = DETECT, gm;
            initgraph(&gd, &gm, "");
            outtextxy(10,10, "Enter new details (name, shirt number, average, ICC ranking): ");
            std::cin >> name >> shirtNo >> average;
            settextstyle(3,0,3);
            outtextxy(100,70,"Name:");
            outtextxy(100,90,"Shirt Number:");
            outtextxy(100,110,"Average:");
            outtextxy(100,130,"ICC Ranking:");
            settextstyle(0,0,0);
                std::cin >> ICCRanking;

            fout << name << " " << shirtNo << " " << average << " " << ICCRanking;
            fout << endl;
        }
    }
    fin.close();
    fout.close();
    system("pause");
    std::remove("team.txt");
    std::rename("temp.txt", "team.txt");
    outtextxy(100,150,"Player updated successfully\n");
        cleardevice();

    displayTeam();


} 

void Team::displayMatches() {
    outtextxy(100,60, "Enter username: ");
    string username;
    std::cin >> username;
    outtextxy(100,80, "Enter password: ");
    string password;
    std::cin >> password;
    if (username == adminUsername && password == adminPassword) {
        int gd = DETECT, gm;
        initgraph(&gd, &gm, "");
        settextstyle(3,0,2);
        outtextxy(50,150,"Matches:");
        settextstyle(0,0,0);
        ifstream fin;
        fin.open("matches.txt");
        string line;
        int i = 1;
        while (getline(fin, line)) {
        	            std::cout << line << endl;
            i++;
        }
        fin.close();
        system("pause");
        closegraph();
    }
    else {
        std::cout << "Invalid credentials\n";
    }
}
void Team::updateCaptain() {
	int gd = DETECT, gm;
    outtextxy(100,60, "Enter username: ");
    string username;
    std::cin >> username;
    outtextxy(100,80, "Enter password: ");
    string password;
    std::cin>>password;
    if (username == adminUsername && password == adminPassword) {
        outtextxy(100,100, "Enter new captain name: ");
        string captain;
        std::cin >> captain;
        teamCaptain = captain;
        outtextxy(100,120,"Captain updated successfully\n");
        initgraph(&gd,&gm,"");
        setbkcolor(BLUE);
        setcolor(RED);
        outtextxy(100,140,"Captain updated successfully");
        delay(2000);
        setbkcolor(BLACK);
        setcolor(WHITE);
        outtextxy(100,160,"Go to main function");
        cleardevice();
        Team t1;
	t1.displayTeam();
       }
    else {
        std::cout << "Invalid credentials\n";
        initgraph(&gd,&gm,"");
        setbkcolor(BLUE);
        setcolor(RED);
        outtextxy(100,100,"Invalid credentials");
        delay(2000);
        Team t1;
        t1.displayTeam();
    }
}

void Team::updateCoach() {
		int gd = DETECT, gm;
    outtextxy(200,100,"\t\t\t-----------------------------");
    outtextxy(200,120,"\t\t\t|         CRIC BUZZ	        |");
    outtextxy(200,140,"\t\t\t-----------------------------");
    outtextxy(200,160,"\n\n");
    outtextxy(200,200, "Enter username: ");
    string username;
    std::cin >> username;
    outtextxy(200,220, "Enter password: ");
        string password;
    std::cin >> password;
    cleardevice();
    
    if (username == adminUsername && password ==adminPassword) {
        outtextxy(200,250,"Enter new coach name: ");
        string coach;
        std::cin >> coach;
        teamCoach = coach;
        std::cout << "Coach updated successfully\n";
        initgraph(&gd,&gm,"");
        setbkcolor(BLUE);
        setcolor(RED);
	    outtextxy(200,100,"\t\t\t-----------------------------");
    	    outtextxy(200,120,"\t\t\t|         CRIC BUZZ	        |");
     	    outtextxy(200,140,"\t\t\t-----------------------------");
    	    outtextxy(200,160,"\n\n");
        outtextxy(200,200,"Coach updated successfully");
        delay(2000);
        cleardevice();
        Team t1;
        t1.displayTeam();

    }
    else {
        std::cout << "Invalid credentials\n";
        initgraph(&gd,&gm,"");
        setbkcolor(BLUE);
        setcolor(RED);
        outtextxy(100,100,"Invalid credentials");
        delay(2000);

        cleardevice();
        Team t1;
	t1.displayTeam();

    }
}
void Team::displayTeam() {

    int choice;
    char x;
    std::system("cls");
    cleardevice();
    outtextxy(200,100,"\t\t\t-----------------------------");
    outtextxy(200,120,"\t\t\t|         CRIC BUZZ	        |");
    outtextxy(200,140,"\t\t\t-----------------------------");
    outtextxy(200,160,"\n\n");
    outtextxy(200,180,"\t\t\t-----------------------------");
    outtextxy(200,200,"\t\t\t|         Teams	        |");
    outtextxy(200,220,"\t\t\t-----------------------------");
   /* void addPlayer();
    void removePlayer();
    void searchPlayer();
    void updatePlayer();
    void displayMatches();
    void updateCaptain();
    void updateCoach();
    void displayTeam();*/
    outtextxy(200,240,"\t\t\t Enter 1 to add player:");
    outtextxy(200,260,"\t\t\t Enter 2 to remove player:");
    outtextxy(200,280,"\t\t\t Enter 3 to search player:");
    outtextxy(200,300,"\t\t\t Enter 4 to update the player:");
    outtextxy(200,320,"\t\t\t Enter 5 to display matches:");
    outtextxy(200,340,"\t\t\t Enter 6 to update captain:");
    outtextxy(200,360,"\t\t\t Enter 7 to update coach");
   
    outtextxy(200,380,"\t\t\t press 8 for exit Exit ");

    outtextxy(200,400,"\t\t\t---------------------------");
    outtextxy(200,420,"\t\t\tChoose Option:[1/2/3/4/5/6/7/8]");
    outtextxy(200,440,"\t\t\t---------------------------");
    outtextxy(200,460,"Enter Your Choose: ");
    std::cin >> choice;
        cleardevice();

    switch (choice)
    {
    case 1:
        addPlayer();
        break;
    case 2:
         removePlayer();
       
        break;
    case 3:
         searchPlayer();
      
        break;
    case 4:
        updatePlayer();

        break;
    case 5:
        displayMatches();
       
        break;
    case 6:
        updateCaptain();
       
        break;
    case 7:
        updateCoach();
        break;
    
    case 8:
        exit(0);
    default:
        outtextxy(200,480,"\n\t\t\t Invalid choice... Please Try Again..");
    }
    Team::displayTeam();

}
void Worldrecord::records()
{
    {
        int gdriver = DETECT, gmode, errorcode;
        initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

        int choice;
        char x;
        std::system("cls");

        setcolor(YELLOW);
        outtextxy(150,50,"CRIC BUZZ");

        setcolor(BLUE);
        outtextxy(50,150,"Records");

        setcolor(CYAN);
        outtextxy(50,200,"1. Enter most sixes");
        outtextxy(50,220,"2. Enter most wickets");
        outtextxy(50,240,"3. Enter most Runs");
        outtextxy(50,260,"4. Display most sixes");
        outtextxy(50,280,"5. Display most wickets");
        outtextxy(50,300,"6. Display most Runs");
        outtextxy(50,320,"7. Update most sixes");
        outtextxy(50,340,"8. Update most wickets");
        outtextxy(50,360,"9. Update most Runs");
        outtextxy(50,380,"10. Exit ");

        setcolor(YELLOW);
        outtextxy(50,400,"Choose Option:[1/2/3/4/5/6/7/8/9/10]");

        setcolor(BLUE);
        outtextxy(50,420,"Enter Your Choice: ");
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            entermostsixes();
            break;
        case 2:
            entermostwickets();
            break;
        case 3:
            entermostruns();
            break;
        case 4:
            displaymostsixes();
            break;
        case 5:
            displaymostwickets();
            break;
        case 6:
            displaymostruns();
            break;
        case 7:
            updatemostsixes();
            break;
        case 8:
            updatemostwickets();
            break;
        case 9:
            updatemostruns();
            break;
        case 10:
            exit(0);
        default:
            setcolor(RED);
            outtextxy(50,440,"Invalid choice... Please Try Again..");
        }
        Worldrecord::records();
    }
    closegraph();
    getch();
}

void Worldrecord::entermostsixes()

{
         cleardevice();
	int gd = DETECT, gm;
	int x=30,y=6;
    std::system("cls");
    fstream worldrecord;
    outtextxy(100,50, "Enter details of mostsixes ");
    rectangle(29, 5, 50, 10);
    outtextxy(100,70, "\t\t\tEnter Name of  player: ");
    std::cin >> name;
    outtextxy(100,90, "\t\t\tEnter shirt no: ");
    std::cin >> shirt_no;
    outtextxy(100,110, " \t\t\tEnter sixes : ");
    std::cin >> sixes;
    worldrecord.open("records1.txt", ios::app | ios::out);
    worldrecord << " " << name << " " << shirt_no << " " << sixes << endl;
    worldrecord.close();
	cleardevice();
        Worldrecord::records();
    std::system("pause");

}
void Worldrecord::updatemostsixes()
{
    std::system("cls");
    cleardevice();
    fstream worldrecord, worldrecord1;
    std::cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cleardevice();
    outtextxy(100,50,"------------------------------ Team Modify Details of most sixes----------------" );
    worldrecord.open("records1.txt", ios::in);
    if (!worldrecord)
    {
        outtextxy(100,70,"\n\t\t\tNo Data is Present..");
    }
    else
    {
        outtextxy(100,70, "\nEnter Shirt No. of player which you want to Modify: ");
        std::cin >> shirt_no;
        worldrecord1.open("records10.txt", ios::app | ios::out);
        worldrecord >> name >> shirt_no >> sixes;
        while (!worldrecord.eof())
        {
            if (shirt_no != shirt_no)

                worldrecord << " " << name << " " << shirt_no << " " << sixes << "\n";
            else
            {
                outtextxy(100,90, "\t\t\tEnter Name of  player: ");
                std::cin >> name;
                outtextxy(100,110, "\t\t\tEnter shirt no: ");
                std::cin >> shirt_no;
                outtextxy(100,130, " \t\t\tEnter sixes : ");
    	        std::cin >> sixes;
                    worldrecord1 << " " << name << " " << shirt_no << " " << sixes << "\n";
                found++;
            }
            worldrecord >> name >> shirt_no >> sixes;
            if (found == 0)
            {
                outtextxy(100,100, "\n\n\t\t\t Player Shirt No. Not Found....");
            }
        }
        worldrecord1.close();
        worldrecord.close();
        std::remove("records1.txt");
        std::rename("records10.txt", "records1.txt");
	cleardevice();
        Worldrecord::records();
    }
}

void Worldrecord::displaymostruns()
{

    system("cls");
    cleardevice();
    int gd = DETECT,gm;  
    initgraph(&gd, &gm, "");
    setcolor(YELLOW);
 
    fstream file44;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    outtextxy(100,100,"---------------------------  Records  ---------------------" );
    file44.open("records3.txt", ios::in);
    if (!file44)
    {
        /* code */
        outtextxy(100,110, "\n\t\t\tNo Data Is Present...");
        file44.close();
    }
    else
    {
        file44 >> name >> shirt_no >> runs;
        while (!file44.eof())
        {
            outtextxy(100,110, "\t\t\t Rank NO : ");
	    cout << total++ << endl << endl;
            outtextxy(100,130, "\t\t\t Name: " );
	    cout<< name << endl << endl;
            outtextxy(100,150, "\t\t\t Shirt NO: ");
	    cout << shirt_no << endl << endl;
            outtextxy(100,170, "\t\t\t Runs : " );
	    cout<< runs << endl << endl;
            cout << endl << endl << endl;
            file44 >> name >> shirt_no >> runs;
        }
        if (total == 0)
        {
            outtextxy(100,170, "\n\t\t\tNo Data Is Present...");
        }
    }
    file44.close();
    //graphics code
    circle(100, 100, 20);
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(90, 80, "R");
    delay(9000);
	cleardevice();
    system("pause");
}

void Worldrecord::displaymostsixes()
{
     
    int gd = DETECT,gm;  
    initgraph(&gd, &gm, "");
    setcolor(YELLOW);
    circle(100, 100, 20);
    settextstyle(4, HORIZ_DIR, 2);
    outtextxy(90, 80, "6");
    system("cls");
    fstream worldrecord;
    int total = 1;
    std::cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    outtextxy(100,110,"---------------------------  Records  ---------------------" );
    worldrecord.open("records1.txt", ios::in);
    if (!worldrecord)
    {
        /* code */
        //sixes
        outtextxy(100,130,"\n\t\t\tNo Data Is Present...");
        worldrecord.close();
    }
    else
    {
        worldrecord >> name >> shirt_no >> sixes;
        while (!worldrecord.eof())
        {
            
            outtextxy(100,130, "\t\t\t Rank NO : ");
	    cout << total++ << endl << endl;
            outtextxy(100,150, "\t\t\t Name: " );
	    cout<< name << endl << endl;
            outtextxy(100,170, "\t\t\t Shirt NO: ");
	    cout << shirt_no << endl << endl;
            outtextxy(100,190, "\t\t\t Runs : " );
	    cout<< sixes << endl << endl;        }
        if (total == 0)
        {
            outtextxy(100,230,"\n\t\t\tNo Data Is Present...");
        }
    }
    worldrecord.close();
    //graphics code
    delay(9000);
	cleardevice();


    system("pause");
}

void Worldrecord::entermostwickets()
{
    system("cls");
    cleardevice();
    
    initwindow(1000,700,"Most Wickets");
    setbkcolor(RED);
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(0,0,RED);
    settextstyle(3,0,3);
    setcolor(WHITE);
    outtextxy(300,50,"Most Wickets");
    settextstyle(4,0,4);
    outtextxy(100,150,"Player Name : ");
    outtextxy(100,200,"Shirt No. : ");
    outtextxy(100,250,"Wickets : ");
    setcolor(YELLOW);

    fstream file42;
    cout << "Enter details of most Wickets " << endl;

    cout << "\t\t\tEnter Name of  player: ";
    cin >> name;
    cout << "\t\t\tEnter shirt no: ";
    cin >> shirt_no;
    cout << " \t\t\tEnter wickets : ";
    cin >> wickets;
    file42.open("records2.txt", ios::app | ios::out);
    file42 << " " << name << " " << shirt_no << " " << wickets << endl;
    file42.close();
    cin>>name>>shirt_no>>wickets;
    	cleardevice();
        Worldrecord::records();

    getch();


    system("pause");

}
void Worldrecord::updatemostwickets()
{
    system("cls");
    cleardevice();

        initwindow(1000,700,"Most Wickets");
        setbkcolor(RED);
        setfillstyle(SOLID_FILL,BLUE);
        floodfill(0,0,RED);
        settextstyle(3,0,3);
        setcolor(WHITE);
        outtextxy(300,50,"Most Wickets");
        settextstyle(4,0,4);
        outtextxy(100,150,"Player Name : ");
        outtextxy(100,200,"Shirt No. : ");
        outtextxy(100,250,"Wickets : ");
        setcolor(YELLOW);

    fstream file42, file43;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout<< "-------------- Team Modify Details of most wickets--------------------";
    file42.open("records2.txt", ios::in);
    if (!file42)
    {
        outtextxy(100,270,"\n\t\t\tNo Data is Present..");
    }
    else
    {
        cout << "\nEnter Shirt No. of player which you want to Modify: ";
        cin >> shirt_no;
        file43.open("records11.txt", ios::app | ios::out);
        file42 >> name >> shirt_no >> wickets;
        while (!file42.eof())
        {
            if (shirt_no != shirt_no)

                file42 << " " << name << " " << shirt_no << " " << wickets << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Shirt No.: ";
                cin >> shirt_no;
                cout << "\t\t\tEnter wickets: ";
                cin >> wickets;
                file43 << " " << name << " " << shirt_no << " " << wickets << "\n";
                found++;
            }
            file42 >> name >> shirt_no >> wickets;
            if (found == 0)
            {
                outtextxy(100,300, "\n\n\t\t\t Player Shirt No. Not Found....");
            }
        }
        file43.close();
        file42.close();
        remove("records2.txt");
        rename("records11.txt", "records2.txt");
            cin>>name>>shirt_no>>wickets;
    	cleardevice();
        Worldrecord::records();

        getch();

    }
}void Worldrecord::displaymostwickets()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");
    system("cls");
    fstream file42;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    outtextxy(50,50,"----------------------  Records  ---------------------" );
    file42.open("records2.txt", ios::in);
    if (!file42)
    {
        /* code */
        cout << "\n\t\t\tNo Data Is Present...";
        file42.close();
    }
    else
    {
        file42 >> name >> shirt_no >> wickets;
        while (!file42.eof())
        {
            int x =100, y =100;
            settextstyle(BOLD_FONT,HORIZ_DIR,2);
            outtextxy(x,y," Rank NO : ");
            total++;
            outtextxy(x,y+40," Name: ");
            cout<<name;
            outtextxy(x,y+80," Shirt NO: ");
	    cout<<shirt_no;
            outtextxy(x,y+120," Wickets : ");
	    cout<<wickets;
            outtextxy(x,y+160,"");
            file42 >> name >> shirt_no >> wickets;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    file42.close();
    system("pause");
        	cleardevice();

}
void Worldrecord::entermostruns()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");
    system("cls");
    fstream file44;
    outtextxy(70,70,"Enter details of most Runs " );

    int x =100, y =100;
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    outtextxy(x,y,"Enter Name of  player: ");
    cin >> name;
    outtextxy(x,y+40,"Enter shirt no: ");
    cin >> shirt_no;
    outtextxy(x,y+80,"Enter Runs : ");
    cin >> wickets;
    file44.open("records3.txt", ios::app | ios::out);
    file44 << " " << name << " " << shirt_no << " " << runs << endl;
    file44.close();
    	cleardevice();
        Worldrecord::records();


    system("pause");
}
void Worldrecord::updatemostruns()
{
	cleardevice();
    fstream file44, file45;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    outtextxy(100,50,"--------------------- Modify Details of Most Runs---------------------");
    file44.open("records3.txt", ios::in);
    if (!file44)
    {
        outtextxy(100,80,"\n\t\t\tNo Data is Present..");
    }
    else
    {
        outtextxy(100,80,"\nEnter Shirt No. of player which you want to Modify: ");
        cin >> shirt_no;
        file45.open("records13.txt", ios::app | ios::out);
        file44 >> name >> shirt_no >> runs;
        //Draw a line using graphics
        while (!file44.eof())
        {
            if (shirt_no != shirt_no)
                file44 << " " << name << " " << shirt_no << " " << sixes << "\n";
            else
            {
                outtextxy(100,100,"\n\t\t\tEnter Name: ");
                cin >> name;
                outtextxy(100,120,"\t\t\tEnter Shirt No.: ");
                cin >> shirt_no;
                outtextxy(100,140,"\t\t\tEnter Total Runs: ");
                cin >> runs;
                file45 << " " << name << " " << shirt_no << " " << wickets << "\n";
                found++;
            }
            file44 >> name >> shirt_no >> wickets;
            if (found == 0)
            {
                outtextxy(100,170,"\n\n\t\t\t Player Shirt No. Not Found....");
            }
        }
        file45.close();
        file44.close();
        remove("records3.txt");
        rename("records3.txt", "records13.txt");
        cleardevice();
        Worldrecord::records();
    }
}
void Match::matches()
{
cleardevice();
    int choice;
    char x;
    system("cls");
    
outtextxy(50,50,"CRIC BUZZ");
rectangle(60,70,270,150);
line(60,110,270,110);
line(140,70,140,150);

settextstyle(6,HORIZ_DIR,2);
setcolor(15);
outtextxy(70,80,"1.Enter upcoming match");
outtextxy(70,100,"2.Enter recent match");
outtextxy(70,120,"3.Display recent matches");
outtextxy(70,140,"4.Display upcoming matches");
outtextxy(70,160,"5.Enter team rankings");
outtextxy(70,180,"6.Display team rankings");
outtextxy(70,200,"7.Exit");
settextstyle(6,HORIZ_DIR,2);
setcolor(GREEN);
outtextxy(70,220,"Choose option:[1/2/3/4/5/6/7]");
setcolor(YELLOW);
rectangle(210,201,300,270);
setfillstyle(SOLID_FILL,BLUE);
floodfill(220,210,YELLOW);
setcolor(WHITE);
settextstyle(6,HORIZ_DIR,2);
outtextxy(70,240,"Enter your choice:");
cin >> choice;
	cleardevice();
    switch (choice)
    {
    case 1:
        conductMatch();
	cleardevice();
        break;
    case 2:
        recentMatch();
        break;
    case 3:
        displayRecentMatches();
        break;
    case 4:
        displayUpcomingMatches();
        break;
    case 5:
        teamRanking();
        break;
    case 6:
        displayTeamRanking();
        break;
    case 7:
        exit(0);
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    Match::matches();

}
void Match::displayTeamRanking()
{
    system("cls");
    cleardevice();

    line(200, 100, 400, 100);
    line(200, 200, 400, 200);
    line(200, 100, 200, 200);
    line(400, 100, 400, 200);
  
    fstream file32;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    outtextxy(100,100, "-----------------------  Rankings  ------------------------------");
    file32.open("ranking.txt", ios::in);
    if (!file32)
    {
        /* code */

        outtextxy(100,130,"\n\t\t\tNo Data Is Present...");
        file32.close();
    }
    else
    {
        file32 >> team1 >> points;
        while (!file32.eof())
        {



            cout << "\t\t\t Rank NO : " << total++ << endl << endl;
        	outtextxy(100,130, "\t\t\t Rank NO : ");
            cout << "\t\t\t Team Name: " << team1 << endl << endl;
        	outtextxy(100,150, "\t\t\t Team Name: ");
            cout << "\t\t\t Points.: " << points << endl << endl;
        	outtextxy(100,170,"\t\t\t Points.: " );
            cout << endl << endl << endl;
            file32 >> team1 >> points;
        }
        if (total == 0)
        {
            outtextxy(100,200,"\n\t\t\tNo Data Is Present...");
        }
    }
delay(9000);
    file32.close();
    cleardevice();

    system("pause");
}
void Match::teamRanking()
{
    system("cls");
    cleardevice();
    fstream file32;
    int count = 10;
    int i = 1;
    cout << "Enter details of top 10 team rankings " << endl;
    while (i <= count)
    {
        cout << "\t\t\tEnter details of Ranking " << i << endl;
        cout << "\t\t\tEnter Name of TEAM 1: ";
        cin >> team1;
        cout << "\t\t\tEnter Points of TEAM: ";
        cin >> points;
        file32.open("ranking.txt", ios::app | ios::out);
        file32 << " " << team1 << " " << points << endl;

        int gd = DETECT, gm;
        initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
        line(200, 100, 400, 100);
        line(200, 200, 400, 200);
        line(200, 100, 200, 200);
        line(400, 100, 400, 200);
        outtextxy(210, 110, "RANK NO");
        outtextxy(310, 110, "TEAM NAME");
        outtextxy(420, 110, "POINTS");
        file32.close();
        i++;
    }
    delay(9000);
    cleardevice();
    Match::matches();

}
void Match::recentMatch()
{

    system("cls");
    fstream file31;
    int count;
    int i = 1;
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    outtextxy(200,50,"Please Enter how many recent match : ");
    cin >> count;
    while (i <= count)
    {
	cleardevice();
        outtextxy(200,90,"Enter details of match ");
        outtextxy(200,120,"Enter Name of TEAM 1: ");
        cin >> team1;
        outtextxy(200,150,"Enter Name of TEAM 2.: ");
        cin >> team2;
        outtextxy(200,180,"Enter DATE of Match: ");
        cin >> date;
        outtextxy(200,210,"Enter Venue: ");
        cin >> venue;
        outtextxy(200,240,"Enter Match Type: ");
        cin >> match_type;
        outtextxy(200,270,"Enter Tornament name: ");
        cin >> tournament_name;
        outtextxy(200,300,"Enter name of umpire: ");
        cin >> umpires;
        outtextxy(200,330,"Enter team 1 score : ");
        cin >> score1;
        outtextxy(200,360,"Enter out of team 1 :");
        cin >> out1;
        outtextxy(200,390,"Enter team 2 score : ");
        cin >> score2;
        outtextxy(200,420,"Enter out of team 2 :");
        cin >> out2;
        outtextxy(200,450,"Which team won the match(press [1][any other] for team1,team2 : ");
        cin >> temp;
        file31.open("recent.txt", ios::app | ios::out);
        file31 << " " << team1 << " " << team2 << " " << date << " " << venue << " " << match_type << " " << tournament_name << " " << umpires << " " << score1 << " " << out1 << " " << score2 << " " << out2 << " " << temp << endl;
        file31.close();
        i++;
    }

    cleardevice();
    Match::matches();

}
void Match::displayRecentMatches()
{
    system("cls");
    fstream file31;
    int total = 1;
    cleardevice();
    settextstyle(BOLD_FONT,HORIZ_DIR,2);
    setcolor(RED);
    outtextxy(200,50,"Deatils of RecentMatches");
    file31.open("recent.txt", ios::in);
    if (!file31)
    {
        /* code */
        outtextxy(200,90,"No Data Is Present...");
        file31.close();
    }
    else
    {
        file31 >> team1 >> team2 >> date >> venue >> match_type >> tournament_name >> umpires >> score1 >> out1 >> out2 >> temp;
        while (!file31.eof())
        {
            outtextxy(200,90," Match number : ");
            outtextxy(200,120," Team 1 Name: ");
	    cout<<team1;
 	    outtextxy(200,150," Team 2 Name.: ");
            cout<<team2;
            outtextxy(200,180," DATE : ");
	    cout<<date;
            outtextxy(200,210," venue : ");
 	    cout<<venue;
            outtextxy(200,240," match type: ");
            cout<<match_type;
            outtextxy(200,270," tournament_name: ");
            cout<<tournament_name;
            outtextxy(200,300," Score of team1: ");
            cout<<score1;
            outtextxy(200,330," out of team1: ");
            cout<<out1;
            outtextxy(200,360," Score of team2: ");
            cout<<score2;
            outtextxy(200,390," out of team2: ");
            cout<<out2;
            if (temp == 1)
            {
	       	     cout<<team1;
                outtextxy(250,420,"WON this match ");
            }
            else
            {
                cout<<team2;
                outtextxy(250,450,"Won this match ");
            }
            file31 >> team1 >> team2 >> date >> venue >> match_type >> tournament_name >> umpires >> score1 >> out1 >> score2 >> out2 >> temp;
        }
        if (total == 0)
        {
            outtextxy(200,90,"No Data Is Present...");
        }
    }
    delay(9000);
    file31.close();
    system("pause");
    
    cleardevice();

}
void Match::conductMatch()
{
    int i=1;
    system("cls");
    fstream file30;
    int count;
    outtextxy(160,80,"\t\tPlease Enter how many match in this tournament: ");
    cin >> count;
    while (i <= count)
    {
        rectangle(30, 5, 70, 20);
        outtextxy(160, 100, "MATCH DETAILS");
        outtextxy(160, 120, "\t\t\tEnter details of match ");
	
        cout << i << endl;
        outtextxy(160,140,"\t\t\tEnter Name of TEAM 1: ");
        
	cin >> team1;
        outtextxy(160,150,"\t\t\tEnter Name of TEAM 2: ");
                cin >> team2;
        outtextxy(160,170,"\t\t\tDATE OF MATCH: ");
        cin >> date;
        outtextxy(160,190,"\t\t\tEnter Venue: ");
        cin >> venue;
        outtextxy(160,210,"\t\t\tEnter Match Type: ");
        cin >> match_type;
        outtextxy(160,230,"\t\t\tEnter Tornament name: ");
        cin >> tournament_name;
        outtextxy(160,250,"\t\t\tEnter name of umpire: ");
        cin >> umpires;
        file30.open("match.txt", ios::app | ios::out);
        file30 << " " << team1 << " " << team2 << " " << date << " " << venue << " " << match_type << " " << tournament_name << " " << umpires << endl;
        file30.close();
        i++;
    }
    system("pause");
    
    cleardevice();
    Match::matches();

}
void Match::displayUpcomingMatches()
{
cleardevice();
    fstream file30;
    int total = 0;
    rectangle(30, 5, 70, 20);
    outtextxy(160, 100, "MATCH DETAILS");
    outtextxy(160,115,"\n-------------------------------------------------------------------------------------------------------");
    cout << endl;
    outtextxy(160,125,"------------------------------------- Deatils of UpcomingMatches--------------------------------------------");
    file30.open("match.txt", ios::in);
    if (!file30)
    {
        /* code */
        outtextxy(160,135,"\n\t\t\tNo Data Is Present...");
        file30.close();
    }
    else
    {
        file30 >> team1 >> team2 >> date >> venue >> match_type >> tournament_name >> umpires;
        while (!file30.eof())
        {
	outtextxy(160,235,"\t\t\t Match number : ");
	cout << total++ << endl << endl;
	outtextxy(160,245,"\t\t\t Team 1 Name: ");
	cout << team1 << endl << endl;
	outtextxy(160,265,"\t\t\t Team 2 Name.: ");
	cout << team2 << endl << endl;
	outtextxy(160,285,"\t\t\t DATE : ");
	cout << date << endl << endl;
	outtextxy(160,305,"\t\t\t venue : ");
	cout << venue << endl << endl;
	outtextxy(160,325,"\t\t\t match type: ");
	cout << match_type << endl << endl;
	outtextxy(160,345,"\t\t\t tournament_name: ");
	cout << tournament_name << endl << endl;
            cout << endl << endl << endl;
            file30 >> team1 >> team2 >> date >> venue >> match_type >> tournament_name >> umpires;
        }
        if (total == 0)
        {
            outtextxy(160,365,"\n\t\t\tNo Data Is Present...");
        }
    }
    file30.close();
    system("pause");
    
    cleardevice();


}

void News::browseNews() {

    int choice;
    char x;
    std::system("cls");
    cleardevice();
    
    setbkcolor(YELLOW);
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(200, 80, "CRIC BUZZ");

    settextstyle(BOLD_FONT, HORIZ_DIR, 2);
    outtextxy(150, 180, "News");

    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    outtextxy(150, 250, "Enter 1 to see Recent matches:");
    outtextxy(150, 300, "Enter 2 to see the team rankings:");

    outtextxy(150, 400, "Choose Option:[1/2]");
    outtextxy(150, 450, "Enter Your Choose: ");

    std::cin >> choice;
    switch (choice)
    {
    case 2:

        Match::displayTeamRanking();
        break;
    case 1:
        Match::displayRecentMatches();

        break;
    }
News::browseNews();
}
void welcome()
{
	int x,y;
	setfillstyle(SOLID_FILL,BLACK);
	bar(300,300,500,400);
	setfillstyle(SOLID_FILL,WHITE);
	bar(310,310,490,390);
	settextstyle(3,0,3);
	outtextxy(320,320,"Welcome to");
	outtextxy(320,350,"Cric Buzz!");
	x=320;
	y=400;
	setfillstyle(SOLID_FILL,RED);
	bar(x,y,x+20,y+20);
	delay(3000);
	cleardevice();
}
void drawCircle(int x, int y, int r) 
{ 
	int gd = DETECT, gm; 
	initgraph(&gd, &gm, NULL);
                setfillstyle(SOLID_FILL, CYAN); 
                bar(0, 0, 800, 800);
	// draw circle 
	circle(x, y, r); 

	// set color to green 

	setcolor(YELLOW);
	// print text inside the circle 
	setbkcolor(CYAN);
	outtextxy(x-20, y-20, "CricBuzz"); 
} 

int main() 
{ 


    int gd = DETECT, gm; 
  
    // Initialize graphics function 
    initgraph(&gd, &gm, ""); 
  
    // Set color for the text 
    setcolor(YELLOW);
  
    // Set font for the text 
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); 
  
    welcome();

    Team t1;
    Match m1;
    Worldrecord w1;
    News n1;
    // Draw the rectangle
    cleardevice(); 
  
  
    // Out the text CRIC BUZZ 
	int x = 70, y = 80, r = 30; 
	drawCircle(x, y, r); 

    outtextxy(50, 120, "1. USER(without password)"); 
    outtextxy(50, 140, "2. Admin"); 
    outtextxy(50, 160, "Press any key to exit "); 
  
    int guess;
    outtextxy(50, 180, "Press [1/2] "); 
    std::cin >> guess; 
        cleardevice(); 
 
    if (guess == 1) 
    { 
        // Draw the rectangle 
        cleardevice();
        setfillstyle(SOLID_FILL, YELLOW); 
        bar(0, 0, 800, 800); 
  
        // Set font for the text 
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); 
  
        // Set color for the text 
        setcolor(RED); 
  setbkcolor(YELLOW);
  
        outtextxy(110, 50, "CRIC BUZZ"); 
	  setbkcolor(YELLOW);
  
        // Print the options 
        outtextxy(50, 120, "Enter 1 to search a player in a team"); 
        outtextxy(50, 140, "Enter 2 TO SEE the upcoming matches"); 
        outtextxy(50, 160, "Enter 3 to see the recent matches"); 
        outtextxy(50, 180, "Enter 4 to see most sixes of a player"); 
        outtextxy(50, 200, "Enter 5 to see the most wickets of a player"); 
        outtextxy(50, 220, "Enter 6 to see the most runs of a player"); 
        outtextxy(50, 240, "ENTER 7 to see the team rankings"); 
        outtextxy(50, 260, "Enter 8 to see the news"); 
        outtextxy(50, 280, "Press any key other key to exit"); 
        int choice; 
        outtextxy(70,320, "PRESS [1/2/3/4/5/6/7/8]"); 
        std::cin >> choice; 
        if (choice == 1) 
        { 
            t1.searchPlayer(); 
        } 
        else if (choice == 2) 
        {
            m1.displayUpcomingMatches();
            
        } 
        else if (choice == 3) 
        {
            m1.displayUpcomingMatches();
        } 
        else if (choice == 4)
        {
            w1.displaymostsixes();
        }
        else if (choice == 5)
        {
            w1.displaymostwickets();
        }
        else if (choice == 6)
        {
            w1.displaymostruns();
        }
        else if (choice == 7)
        {
            m1.displayTeamRanking();
        }
        else if (choice == 8)
        {
            n1.browseNews();
        }
        else
        {
            outtextxy(90,350, "!Incorrect program is terminated ");
            system("pause");
            exit(0);
        }
    } 
    else if (guess == 2) 
    { 
        string userName;
        string userPassword;
        int loginAttempt = 0;
        
        while (loginAttempt < 5) 
        { 
        cleardevice();
    	outtextxy(90, 350, "Please enter your user name: ");            
            cin >> userName; 
        outtextxy(90,370, "Please enter your user password: "); 
            cin >> userPassword; 
            
            if (userName == "BILAL" && userPassword == "admin") 
            {
                system("cls");

                outtextxy(100,400,"Welcome Bilal!\n");
                outtextxy(100,420,"Thank you for logging in.\n");
                system("pause");
                system("cls");

                // Draw the rectangle 
                setfillstyle(SOLID_FILL, YELLOW); 
                bar(0, 0, 800, 800);
		setbkcolor(YELLOW) ;
  
                // Set font for the text 
                settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); 
  
                // Set color for the text 
                setcolor(BLUE); 
  
                // Out the text CRIC BUZZ 
                outtextxy(110, 50, "CRIC BUZZ");
  
                // Print the options 
                outtextxy(50, 120, "1.Information about Teams "); 
                outtextxy(50, 140, "2.information about matches "); 
                outtextxy(50, 160, "3.worldrecords "); 
                outtextxy(50, 180, "Press any key other key to exit"); 
                int choice; 
                outtextxy(60,200,"PRESS [1/2/3]"); 
                cin >> choice; 
                if (choice == 1) 
                { 
                    t1.displayTeam(); 
                    break; 
                } 
                else if (choice == 2) 
                { 
                    m1.matches(); 
                    break; 
                } 
                else if (choice == 3) 
                { 
                    w1.records(); 
                    break; 
                } 
                else 
                { 	
                    outtextxy(50,220, "!Incorrect program is terminated "); 
                    exit(0); 
                } 
                break; 
            } 
            else if (userName == "fahad" && userPassword == "admin") 
            { 
                outtextxy(100,400,"Welcome FAHAD!\n");
                outtextxy(100,420,"Thank you for logging in.\n");
                  system("pause");
                system("cls");
                // Draw the rectangle 
                setfillstyle(SOLID_FILL, YELLOW); 
                bar(0, 0, 800, 800);
		setbkcolor(YELLOW) ;
                // Set font for the text 
                settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2); 
  
                // Set color for the text 
                setcolor(BLUE); 
  
                // Out the text CRIC BUZZ 
                outtextxy(110, 50, "CRIC BUZZ");
  
                // Print the options 
                outtextxy(50, 120, "1.Information about Teams "); 
                outtextxy(50, 140, "2.information about matches "); 
                outtextxy(50, 160, "3.worldrecords "); 
                outtextxy(50, 180, "Press any key other key to exit"); 
                int choice; 
                outtextxy(50,200, "PRESS [1/2/3]"); 
                cleardevice();
                cin >> choice; 
                if (choice == 1) 
                { 
                    Team t1; 
                    t1.displayTeam(); 
                    break; 
                } 
                else if (choice == 2) 
                { 
                    Match m1; 
                    m1.matches(); 
                    break; 
                } 
                else if (choice == 3) 
                { 
                    Worldrecord w1; 
                    w1.records(); 
                    break; 
                } 
                else 
                { 
                    outtextxy(100,440, "!Incorrect program is terminated "); 
                    exit(0); 
                } 
                break; 
            } 
            else 
            { 
                outtextxy(100,440, "Invalid login attempt. Please try again.\n" ); 
                loginAttempt++; 
                
    
            } 
        } 
        if (loginAttempt == 5) 
        { 
            outtextxy(100,460, "Too many login attempts! The program will now terminate."); 
            delay(9000);
                               

	    return 0; 
        } 
    } 
    else
        outtextxy(100,480, " !INCORRECT "); 
    outtextxy(100,500," This program is terminated"); 
    return 0; 
}
