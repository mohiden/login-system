#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#include <stdio.h>

class Bank
{

  std::string choice;
  public:
  void login(){
    
    system("cls");
    std::cout<<"\n1.Check balance \n2.Send money \n3.Back to menu \n\nChoose: ";
    std::cin>>choice;


    if (choice == "1")
    {
      std::cout<<"\nBalance\n";
    }

    if (choice == "2")
    {
      std::cout<<"\nSend money\n";
    }

    if (choice == "3")
    {
      std::cout<<"\nBack\n";

    }else{
      std::cout<<"Please choose from the menu.";
    }
  }
  
};

class Login
{
  // function variables are all private
  std::string un,pw,npw,cknpw,passtr;
  int ch;
  std::vector<std::string> data;
  Bank bank;

public:
std::vector<std::string> get_data(std::string username,std::string password){
std::ifstream infile;
std::string un,pw,check;
infile.open(username +".txt");
infile>>un;
infile>>pw;
infile.close();
data.push_back(un);
data.push_back(pw);
return data;
//data[0] = un;
//data[1] = pw;
}


void change_pas(std::string username,std::string password){   //Change password
  data = get_data(username,password);
  if (username == data[0] && password == data[1]) 
  {
    A :
     std::cout<<"\nEnter your new passowrd : ";
     ch=0;
     while(ch = getch()) {
      if (ch == 8 ) 
      {
        std::cout<<"\b \b";
        npw.erase(npw.length() - 1);
      }else if (ch == 13) {
        break;
        
      }else{
        std::cout<<"*";
        npw.push_back(ch);
      }
    }
     std::cout<<"\nEnter again : ";
     while(ch = getch()) {
      if (ch == 8 ) 
      {
        std::cout<<"\b \b";
        cknpw.erase(cknpw.length() - 1);
      }else if (ch == 13) {
        break;
        
      }else{
        std::cout<<"*";
        cknpw.push_back(ch);
      }
    }
    if (npw == cknpw)
    {
     std::ofstream outfile;
     outfile.open(username + ".txt");
     outfile<<data[0];
     outfile<<std::endl;
     outfile<<npw;
     outfile.close();
     std::cout<<"\nPassword changed successfully!\n";
    }else if (npw != cknpw)
    {
      std::cout<<"\nPassword didn't match - try again \n";
      goto A;
    }
    
  }else if(username == data[0] && password != data[1]){
    std::cout<<"\nPlease Enter valid password\n";
  }else if(username != data[0] && password != data[1]) {
    std::cout<<"\nPlease enter valid email,password\n";
  }
}


  



void reset_account(std::string username){   //reset Account
  std::ifstream infile(username + ".txt");
  infile>>un;
  infile>>pw;
  if (username == un)
  {
    std::cout<<"\n\nAccount found!\n";
    std::cout<<"Your email is : "<<un<<std::endl;
    std::cout<<"Your password is : "<<pw<<std::endl;
  }else if(username != un){
    std::cout<<"\n\nCan't find your account , Please make sure the email is correct\n";
 
    
  }
}




int del_account(std::string username,std::string password){   //Delete Account
  data = get_data(username,password);
  un = data[0];
  pw = data[1];
  if (username == un && password == pw) 
  {
    std::cout<<"\n\nAccount found!\n";
    std::cout<<"\nAre sure to delete ? (y/n) : ";
    if (getch() == 'y')
  {
    username.append(".txt");
    if(!remove(username.c_str())){
      std::cout<<"\nFile removed successfully\n";
    }else {
      std::cout<<"\n\nCan't remove the file!\n\n";
    }
  }else{
  return 1;
  }
  }else {
    std::cout<<"\nPlease enter valid email,password\n";
}
}


void log(std::string username, std::string password){   //Login Account
  data = get_data(username,password);
  un = data[0];
  pw = data[1];
  // std::cout<<data[0]<<std::endl<<data[1];
    if (username == un && password == pw) {
    bank.login();
  }else if(username == un && password != pw){
    std::cout<<"\nplese enter valid password"<<"\n";
}else if(username != un && password == pw){
  std::cout<<"\nPlease enter valid password\n";
}else if(username != un && password != pw) {
  std::cout<<"\nemail and password are wrong !!\n";
}

}





void reg(std::string username, std::string password){   //Register account
    std::ofstream outfile;
    int get;
    outfile.open(username + ".txt");

    {
    }
    outfile<<username<<std::endl<<password;
    std::cout<<"\nAccount created successfully\n";
    outfile.close();
}




std::string getpas(){    //Makes password appear as ******
passtr.erase();
while(ch = getch()) {
      if (ch == 8 ) 
      {
        while(passtr.length() < 0){
        std::cout<<"\b \b";
        }if(passtr.length() > 0){
          std::cout<<"\b \b";
        passtr.erase(passtr.length() - 1);
        }
      }else if (ch == 13) {
        break;

        
      }else{
        std::cout<<"*";
        passtr.push_back(ch);
      }
    }
    return passtr;
}
  
};






int main () {
Login login;
int ch;
std::string username,password,choice;

do {

  std::cout<<"\n1. Login\n2. Register\n3. Delete Account\n4. Reset Account \n5. Change password\n6. Exit  \n\nChoose: ";
  std::cin>>choice;

  
    
    if(choice == "1"){
    system("cls");
    std::cout<<"Enter your email: ";
    std::cin>>username;
    std::cout<<"Enter your password: ";
   password = login.getpas();
    // std::cout<<"\n"<<password<<std::endl;

    login.log(username,password);
    }

    else if( choice == "2"){
    system("cls");
    R:
    username="";
    password="";
    std::cout<<"Enter new email: ";
    std::cin>>username;
    std::cout<<"New password : ";
    password = login.getpas();
    if(password.length() <= 3) {
      system("cls");
      std::cout<<"\n\nPlease use strong password!\n\n";
      goto R;
    }else{
      login.reg(username,password);
    }

  }
    else if(choice == "3"){
    system("cls");
    std::cout<<"Enter account email :";
    std::cin>>username;
    std::cout<<"Enter account password :";
    password = login.getpas();
    login.del_account(username,password);

    }

    else if(choice == "4") {
    system("cls");
    std::cout<<"Enter your email: ";
    std::cin>>username;
    login.reset_account(username);

    }

    else if(choice == "5"){
    system("cls");
    std::cout<<"Enter email : ";
    std::cin>>username;
    std::cout<<"Enter password: ";
    password = login.getpas();
    login.change_pas(username,password);
    }

   else if(choice == "6"){
    system("cls");
    std::cout<<"Good Bye! -";
    return 1;
   }
    else {
      system("cls");
    std::cout<<"\n Please choose from the menu.\n";
    }
} while(true);
}







