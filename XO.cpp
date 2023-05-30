#include <iostream>
#include <string> 
#include <unistd.h>

using namespace std;
void pBlue(string str){
  cout << "\033[1;34m"<<str<<"\033[0m";
}
void pGreen(string str){
  cout << "\033[1;32m"<<str<<"\033[0m";
}
void pRed(string str){
  cout << "\033[1;31m"<<str<<"\033[0m";
}
char table[9] = {'1','2','3','4','5','6','7','8','9'};
string nplayer1;
string nplayer2;
int nobat = 1;
void getNameOfPlayer(){
	cout<<"Enter player 1 name: ";
	getline(cin,nplayer1);
	cout<<"Enter player 2 name: ";
	getline(cin,nplayer2);
}
char getCharOfRound(){
	if(nobat%2==0){
		return 'X';
	}else{
		return 'O';
	}
}
string getNameOfRound(){
	if(getCharOfRound()=='X'){
		return nplayer1;
	}else{
		return nplayer2;
	}
}
void printTable(){
	system("cls");	
	cout<<"\n\n\n\n\n";
	cout<<"                ";
	pBlue("Player1: ");
	cout<<nplayer1<<"               ";
	pBlue("player2: ");
	cout<<nplayer2<<endl;
	pRed("                *****************************************");
	cout<<endl;
	pRed("                *                                       *");
	cout<<endl;
	pRed("                *                                       *");
	cout<<endl;
	pRed("                *            ");
	cout<<table[0];
	pRed("   |   ");
	cout<<table[1];
	pRed("   |   ");
	cout<<table[2];
	pRed("          *");
	cout<<endl;
	pRed("                *         -------|-------|-------       *");
	cout<<endl;
	pRed("                *            ");
	cout<<table[3];
	pRed("   |   ");
	cout<<table[4];
	pRed("   |   ");
	cout<<table[5];
	pRed("          *");
	cout<<endl;
	pRed("                *         -------|-------|-------       *");
	cout<<endl;
	pRed("                *            ");
	cout<<table[6];
	pRed("   |   ");
	cout<<table[7];
	pRed("   |   ");
	cout<<table[8];
	pRed("          *");
	cout<<endl;
	pRed("                *         -------|-------|-------       *");
	cout<<endl;
	pRed("                *                                       *");
	cout<<endl;
	pRed("                *                                       *");
	cout<<endl;
	pRed("                *                                       *");
	cout<<endl;
	pRed("                *****************************************");
	cout<<endl;
}
bool isTableFull(char input){
	int x = (int)input - 48 - 1;
	if(table[x]=='X'|| table[x]=='O'){
		return true;
	}else{
		return false;
	}
}
void getUserInput(){
	nobat++;
	pGreen("                  Enter 1-9 player( ");
	cout<<getNameOfRound();
	pGreen(" -> ");
	cout<<getCharOfRound();
	pGreen(" ): ");
	char input;
	cin>>input;
	while(isTableFull(input)){
		printTable();
		pGreen("                  warning table is not available");
		cout<<endl;
		pGreen("                  Enter 1-9 player( ");
		cout<<getNameOfRound();
		pGreen(" -> ");
		cout<<getCharOfRound();
		pGreen(" ): ");
		cin>>input;
	}
	switch(input){
		case '1':
			table[0]=getCharOfRound();
			break;
		case '2':
			table[1]=getCharOfRound();
			break;
		case '3':
			table[2]=getCharOfRound();
			break;
		case '4':
			table[3]=getCharOfRound();
			break;
		case '5':
			table[4]=getCharOfRound();
			break;
		case '6':
			table[5]=getCharOfRound();
			break;
		case '7':
			table[6]=getCharOfRound();
			break;		
		case '8':
			table[7]=getCharOfRound();
			break;
		case '9':
			table[8]=getCharOfRound();
			break;
		default:
			pRed("                  Error just 1-9 doctor!");
			cout<<endl;
			sleep(2);
			break;
	}
}
bool isFull(){
	for(int i=0;i<9;i++){
		if(table[i] != 'X' && table[i] != 'O'){
			return false;
		}
	}
	return true;
}
bool isWin(){
	if(table[0]==table[1] && table[1]==table[2]){
		return true;
	}else if(table[3]==table[4] && table[4]==table[5]){
		return true;
	}else if(table[6]==table[7] && table[7]==table[8]){
		return true;
	}else if(table[0]==table[3] && table[3]==table[6]){
		return true;
	}else if(table[1]==table[4] && table[4]==table[7]){
		return true;
	}else if(table[2]==table[5] && table[5]==table[8]){
		return true;
	}else if(table[0]==table[4] && table[4]==table[8]){
		return true;
	}else if(table[2]==table[4] && table[4]==table[6]){
		return true;
	}else{
		return false;
	}
}
bool isNotEnd(){
	if( isWin() || isFull()){
		return false;
	}else{
		return true;
	}
}
string whoIsWinner(){
	if(isFull()){
		return "The game equalised, play again!";
	}else{
		return "                  wooohaaa player "+ getNameOfRound()+" is the winner! ";
	}
}

int main() {
getNameOfPlayer();

	while(isNotEnd()){
		printTable();
		getUserInput();
	}
	printTable();
	cout<<whoIsWinner();
	
}
//Erfan Shafiee
