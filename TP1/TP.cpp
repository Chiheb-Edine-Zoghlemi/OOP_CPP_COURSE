#include <iostream>
#include <array> 
#include <string>
using namespace std; 

void EX1 () {
    int var ; 
    int &ref_var=var ;
    int *p = &var; 
    var = 5 ; 
    cout<<" VAR = "<<var<<" &VAR = "<<&var<<endl ;
    cout<<" ref_var = "<<ref_var<<" &ref_var = "<<&ref_var<<endl ;
    cout<<" P = "<<p<<" &p = "<<&p<<" *p = "<<*p<<endl ;
    *p=8;
    cout<<" VAR = "<<var<<" &VAR = "<<&var<<endl ;
    cout<<" ref_var = "<<ref_var<<" &ref_var = "<<&ref_var<<endl ;
    cout<<" P = "<<p<<" &p = "<<&p<<" *p = "<<*p<<endl ;
    ref_var=9;
    cout<<" VAR = "<<var<<" &VAR = "<<&var<<endl ;
    cout<<" ref_var = "<<ref_var<<" &ref_var = "<<&ref_var<<endl ;
    cout<<" P = "<<p<<" &p = "<<&p<<" *p = "<<*p<<endl ;
}

/*
void EX2 () { 
const int var1 = 6 ;  
const int *p = &var1;
*p=7;
int var2 ;
var2= var2;
}
*/

void EX3( int &par1 , int  &par2) {
    int z = par1 ; 
    par1=par2; 
    par2=z;
}

void EX4(int TAB[], int &MIN , int &MAX) {
    MIN=TAB[0];
    MAX=TAB[0];
    for(int i=1 ; i<5 ;i++){
        if (TAB[i]> MAX) {
            MAX=TAB[i];
        }else if (TAB[i]< MIN) {
            MIN=TAB[i];
        }else {
            continue;
        }
    }
}

void display_table(int TAB[]) {
for (int i=0; i < 5; i++) {
    cout<<" | "<<TAB[i];
}
cout<<" | "<<endl;
}

int EX5( string ch ){
int count = 0 ; 
for (int i = 0; i < ch.size(); i++){                    
    if ( ch[i] == 'A') {
        count ++ ; 
    }
}
return count ; 
}



int main(void) {

cout<<" MAIN PROGRAM "<<endl; 

//EX1
cout<<"EX1"<<endl;
EX1();


//EX2
/*
cout<<"EX2"<<endl;
EX2();
TP.cpp:24:3: error: assignment of read-only location ‘* p’
   24 | *p=7;
      | ~~^~
*/

//EX3

cout<<"EX3"<<endl;
int par1=5,par2=10;
cout<<" PAR1 = "<<par1<<" PAR2 = "<<par2<<endl;
EX3(par1, par2);
cout<<" PAR1 = "<<par1<<" PAR2 = "<<par2<<endl;

//EX4
cout<<"EX4"<<endl;
int TAB[5] ={ 5,7,1,9,8} ; 
int MAX,MIN;
cout<<" THE TABLE "<< endl;
display_table(TAB) ; 
EX4(TAB,MIN,MAX);
cout<<" THE MINIUM VALUE IS = "<<MIN << " THE MAXIUM VALUE IS = "<<MAX<<endl;

//EX5
cout<<"EX5"<<endl;
string ch = "AZERATYQSDFGQASZEAFR";
cout<<" THE STRING IS = "<< ch <<endl ; 
int NB=EX5(ch);
cout<<" THE NUMBER OF TIME THE CARACTER A APPREAD IN THE STRING IS ="<<NB<<endl ; 
return 0 ;
}
