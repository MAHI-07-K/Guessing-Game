#include<iostream>
#include<fstream>
#include<chrono>
#include<cstdlib>
using namespace std;
void info()
{
    ifstream gamerules("gamerules.txt");
    if(gamerules.is_open())
    {
        string line;
        while(getline(gamerules,line))
        {
            cout<<line<<endl;
        }
    }
}
void savedata(string name,int hits,int num)
{
    ofstream winnerdata;
    winnerdata.open("gamedata.txt",ios::app);
    winnerdata<<name<<" had the guessed the number "<<num<<" with "<<hits<<" hits\n";
}
int main()
{
    using namespace std::chrono;
    info();
    srand(time(NULL));
    int num=(rand()%1000)+1;
    cout<<"Enter your name"<<endl;
    string name;cin>>name;
    auto start=high_resolution_clock::now();
    cout<<"Guess your Number"<<endl;
    bool won=false;
    int hits=0;
    while(!won){
        int guess;
        cin>>guess;
        hits++;
        if(guess==num){cout<<"That's Correct !!"<<endl; won=true;}
        else if(guess<num){cout<<"Your guess is LOW"<<endl;}
        else{cout<<"Your guess is High"<<endl;}
    }
    auto finish=high_resolution_clock::now();
    cout<<"Congrates you Won with hits:-"<<hits<<"with time"<<finish-start<<endl;
    savedata(name,hits,num);

}
