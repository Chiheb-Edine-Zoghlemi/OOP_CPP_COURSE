#include <iostream>
using namespace std;
bool mystery_number(){
const int CORRECT_NUMBER = rand() % 100 + 1; 
cout<<"Welcome to Mystery Number"<<endl ; 
cout <<"--Rules--\n*) Guess a number between 1 -- 100 \n*) You have 6 attempts \n*) With each attempt u will be indicated if the correct number is lower or higher"<<endl;
int choice ; 
int i ;
//cout<<CORRECT_NUMBER<<endl;
for ( i=0 ; i<6; i++) {
cout<<"-- Attemp "<< i+1 << " --"<<endl;
cin>>choice;
if (choice == CORRECT_NUMBER) {
    cout<<"You Guessed it !"<<endl;
    return true;
} else if ( choice < CORRECT_NUMBER) {
    cout<<"The correct number is higher "<<endl;
}else { 
    cout<<"The correct number is lower"<<endl;
}

}
return false ; 
}

int main() {
  mystery_number()? cout<<"You Won !"<<endl : cout<<"You Lost :( "<<endl ;
  return 0;
}