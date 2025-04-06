#include<iostream>
#include<conio.h>
#include<fstream>

using namespace std;

class User {
private:
    string username;
    string email;
    char password[32];
    char encrypted_password[32];
    char decrypted_password[32];

public:

    void login_menu() {
        cout<<"Login Menu: "<<endl;
        cout<<"1. Login"<<endl;
        cout<<"2. Sign Up"<<endl;
        cout<<"3. Exit"<<endl;
    }

    void registeration() {
        cout<<"Enter email: ";
        cin>>email;
        cout<<"Enter username: ";
        cin>>username;
        getPassword();
    }

    void getPassword() {
        cout<<"Enter password (password must be of atleast 8 characters, include a mix of uppercase and lowercase letters, numbers, and symbols, and avoid easily guessable information like names or common words): ";
        int i=0;
        char a;
        for (int i=0;;) {
            a=getch();
            if ((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9')) {
                password[i]=a;
                i++;
                cout<<"*";
            }
            if (a=='\b' && i>=1) {
                cout<<"\b \b";
                i--;
            }
            if (a=='\r') {
                password[i]='\0';
                break;
            }
        }
        cout<<endl;
    }

    void encrypt()
    {
        int i=0;
        cout<<"Encrypted password: ";
        for (int i=0; password[i] != '\0'; i++)
        {
            encrypted_password[i] = (char)((int) password[i] + i) % 126;
        }
        cout<<endl;
    }

    void decrypt() {
        int i = 0;
        cout<<"Decrypted password: ";
        for (i = 0; encrypted_password[i] != '\0'; i++) {
            decrypted_password[i] = (char)(((int)encrypted_password[i] - i + 126) % 126);
        }
        decrypted_password[i] = '\0';
        cout<<endl;
    }

    void login() {
        cout<<"Enter username: ";
        cin>>username;
        getPassword();
    }

    void logout() {
        cout<<"Logged out successfully!"<<endl;
        login();
    }

};

class Post {
private:
    string title;
    string content;
    User author;

public:
    void createPost() {
        cout<<"Enter title: ";
        cin>>title;
        cout<<"Enter content: ";
        cin>>content;
        // cout<<"Enter author: ";
        // cin>>author;
    }

    void editPost() {
        cout<<"Enter post title: ";
        cin>>title;
        cout<<"Enter new content: ";
        cin>>content;
    }

    void deletePost() {
        cout<<"Enter post title: ";
        cin>>title;
    }

};

class BlogSystem {
public:
    void displayPosts() {
        cout<<"Title: "<<endl;
        cout<<"Content: "<<endl;
        cout<<"Comments: "<<endl;
        cout<<"Tags: "<<endl;

    }

    void searchByTag() {
        cout<<"Enter tag name: ";
    }

    void searchByUser() {
        cout<<"Enter username: ";
        // cin>>User.username;
    }

};

class Admin {
public:
    void deletePost() {

    }

    void manageUsers() {

    }
};

class Comment {
private:
    string content;
    User author;

public:
    void addComment() {

    }

    void deleteComment() {

    }

};

class Tag {
private:
    string tagName;
};

class Database {
public:
    void readData() {

    }

    void writeData() {

    }

};

int main()
{
    User user;
    Post post;
    BlogSystem blogsystem;
    Admin admin;
    Comment comment;
    Tag tag;
    Database database;

    start:
        cout<<"Login Menu: "<<endl;
        cout<<"1. Login"<<endl;
        cout<<"2. Sign Up"<<endl;
        cout<<"3. Exit"<<endl;
        int ch;
        cout<<endl<<"Enter choice: ";
        cin>>ch;

    if (ch==1) {
        user.login();
    }
    else if (ch==2) {
        user.registeration();
        user.encrypt();
        user.decrypt();
    }
    // else if (ch==3) {
    //     break;
    // }
    else {
        cout<<"Invalid choice: "<<endl<<endl;
        goto start;
    }

    main_menu:
        cout<<endl<<"Main Menu: "<<endl;
        cout<<"1. Create new post"<<endl;
        cout<<"2. Edit post"<<endl;
        cout<<"3. Display posts"<<endl;
        cout<<"4. Delete post"<<endl;
        cout<<"5. Search by User"<<endl;
        cout<<"6. Search by Tag"<<endl;
        cout<<"7. Logout"<<endl;
        int ch1;
        cout<<endl<<"Enter choice: ";
        cin>>ch1;

    switch (ch1)
    {
        case 1:
        post.createPost();

        case 2:
        post.editPost();

        case 3:
        blogsystem.displayPosts();

        case 4:
        post.deletePost();

        case 5:
        blogsystem.searchByUser();

        case 6:
        blogsystem.searchByTag();

        case 7:
        user.logout();
        goto start;

        default:
        goto main_menu;
    }
}