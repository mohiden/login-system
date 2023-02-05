# Simple login system built using C++

A C++ class implementation of a Login System that provides functionalities such as logging in, resetting account, changing password and deleting an account. The Login class implements various private and public methods to provide these functionalities to the users.

## Authors

- [@Mohiden adam](https://www.github.com/mohiden)

## Features

- Login: Allows users to log in to their accounts with a valid email and password.
- Reset Account: Allows users to reset their accounts by providing their email. The system displays the email and password of the user if the account is found.
- Change Password: Allows users to change their password after logging in with a valid email and password.
- Delete Account: Allows users to delete their accounts after logging in with a valid email and password.

## Implementation Details

The Login class implements the following private variables:

```C++
un: String variable to store the username
pw: String variable to store the password
npw: String variable to store the new password
cknpw: String variable to store the confirmed new password
passtr: String variable to store the password as a string
ch: Integer variable to store the character entered by the user
data: A vector of strings to store the username and password
bank: An instance of the Bank class.
```

The Login class implements the following public methods:

```C++
get_data(std::string username,std::string password): This method retrieves the username and password of the user from a text file with the filename as the username provided.
change_pas(std::string username,std::string password): This method allows the user to change their password after logging in with a valid email and password.
reset_account(std::string username): This method allows the user to reset their account by providing their email. The system displays the email and password of the user if the account is found.
del_account(std::string username,std::string password): This method allows the user to delete their account after logging in with a valid email and password.
log(std::string username, std::string password): This method allows the user to log in to their account with a valid email and password.
```

## Note

The class makes use of the getch() method for password input, which is a non-standard function and may not work on all systems. A similar function from the conio.h library can be used as an alternative.

to run this code u need to run it using c++11 , its easy just follow the steps:

Windows : if you are using dev or code block. just go to google and search (how to compile using c++11 on [your program name])
or if you compile using command line (cmd) with g++ or c++ or gnu - use the -std=c++11
for example, g++ [filename.cpp] -std=c++11

MAC : if you are using Xcode go to google and search (how to compile c++11 using xcode)
if you compile using terminal just use the -std=c++11
for example, g++ [filename.cpp] -std=c++11.

## License

[MIT](https://choosealicense.com/licenses/mit/)

## Feedback

If you have any feedback, please reach out to us at mohidenjama@gmail.com
