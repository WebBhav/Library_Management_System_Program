#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

#define ll long long 


void callOnStart(){
    cout<< "*******************LIBRARY PANEL*******************"<<endl<<endl<<endl;
    cout<<"Please Choose Any Option To Login-"<<endl<<endl;


    cout<<"1. Student"<<endl<<"2. Administration"<<endl<<"3. Exit Program"<<endl<<endl;

    cout<<"Enter any of the valid option: ";
        

}

int callStudent(){
    cout<< "***********WELCOME TO THE STUDENT'S SECTION***********"<<endl<<endl<<endl;
    cout<<"Please Choose Any Option-"<<endl<<endl;

    cout<<"1. View Booklist"<<endl<<"2. Search For A Book"<<endl<<"3. Go TO Main Menu"<<endl;

    cout<<"Enter any valid option: ";
    int answerOne;

    cin>>answerOne;
    cout<<endl;
    
    return answerOne;
}

int showBooklist(vector<string>arr){
    

    for (int i=0; i<arr.size(); i++){
        cout<<arr[i]<<endl;
    }

    int showBooklist_int;
    cout << "Enter any digit to reach the main menu: ";
    cin>> showBooklist_int;
    cout<<endl<<endl;

    return showBooklist_int;

}

int searchBook(vector<string>arr, string queryForBook){

    bool flag=0;
    for(int i=0; i<arr.size(); i++){
        if (queryForBook == arr[i]){
            cout<<arr[i]<<endl<<i<<endl;
            flag =1;
            break;
        }
    }

    if (flag==0){
        cout<<"Dear Student, No Such Book Exist In Our Library"<<endl<<endl;
        
    }
    int showBooklist_int;
    cout << "Enter any digit to reach the main menu: ";
    cin>> showBooklist_int;
    cout<<endl<<endl;

    return showBooklist_int;
    
}

bool checkPassword(string password){
    ofstream fout;
    string checkPassword_key;

    ifstream myfile("Password.txt");

    if (myfile.is_open()){
        while(! myfile.eof()){
            getline(myfile, checkPassword_key);
            if (checkPassword_key==password){
                return true;
            }
        }

        myfile.close();
    }
    else{
        return false;
    }
}
string passwordInput(){
    string password ;
    char password_key[32];
    int count_Pass=0;
    char a;
    cout<<"**************Authetication Needed**************"<<endl<<endl;
    cout<<"Enter Password :";
    while(true){
        a = getch();
        if ((a>='a'&&a<='z')  ||  (a>='A'&&a<='Z')  ||  (a>='0'&&a<='9')  ||  (a=='@')  || (a=='_')){
            password_key[count_Pass]=a;
            ++count_Pass;
            cout<<"*";
        }
        if (a=='\b'){
            cout<<"\b \b";
            --count_Pass;
        }
        if (a=='\r'){
            password_key[count_Pass]='\0';
            break;
        }
    }
    password = password_key;
    return password;
}

int callAdmin(){
    cout<< "***********WELCOME TO THE ADMINISTRATION'S SECTION***********"<<endl<<endl<<endl;
    cout<<"Please Choose Any Option-"<<endl<<endl;

    cout<<"1. View Booklist"<<endl<<"2. Search For A Book"<<endl<<"3. Add A Book"<<endl<<"4. Issue Book"<<endl<<"5. Change Password"<<endl<<"6. Go To Main Menu"<<endl<<"7. Close Application"<<endl<<endl;

    cout<<"Enter any valid option: ";
    int answerTwo;

    cin>>answerTwo;
    cout<<endl;
    
    return answerTwo;
}

int callIssueBooks(){
    cout<<endl<<"1. View Issued Books"<<endl<<"2. Issue A Book"<<endl<<"3. Return Book"<<endl<<"4. Reissue Book"<<endl<<"5. Go To Main Menu"<<endl<<endl;
    cout<<"Enter A Valid Option : ";
    int issue;
    cin>>issue;
    cout<<endl<<endl;

    return issue;
}

int showIssuedBooklist(vector<string>vect){

    for (int i=0; i<vect.size(); i++){
        cout<<vect[i]<<endl;
    }

    int showIssuedBooklist_int;
    cout << "Enter any digit to reach the main menu: ";
    cin>> showIssuedBooklist_int;
    cout<<endl<<endl;

    return showIssuedBooklist_int;
}

int main(){
    
    callOnStart();

    int oneOption;
    int secondOption;
    int thirdOption;
    int Enterance;

    cin>>Enterance;
    cout <<endl<<endl;
    

    // Booklist into Array starts here
    ofstream fout;
    vector<string>arr;
    string bookDetail;
    int counter=0;

    ifstream myfile("Booklist.txt");

    if (myfile.is_open()){
        while(! myfile.eof()){
            getline(myfile, bookDetail);
            arr.push_back(bookDetail);
            counter++;
        }

    }
    // Booklist into array ends here

    //Issued Booklist into array starts here
    ofstream fout1;
    vector<string>vect;
    string issuedBookDetail;
    int counter_issue=0;

    ifstream myfile1("IssuedBooklist.txt");

    if (myfile1.is_open()){
        while(! myfile1.eof()){
            getline(myfile1, issuedBookDetail);
            vect.push_back(issuedBookDetail);
            counter_issue++;
        }

    }
    //Issued Booklist into array ends here
    
    if (!(Enterance == 1 || Enterance == 2)){
        return main();
    }

    // Entering in Student Menu
    if (Enterance==1){
        int answerOne = callStudent();
        
        //for Returning Main Menu
        if (!(answerOne==1 || answerOne== 2)){
            return main();
        }
        
        //for Show Booklist
        if (answerOne== 1){
            showBooklist(arr);
            return main();
        }

        //for Search Booklist
        if (answerOne == 2){
            string queryForBook;

            queryForBook.clear();
            cout<<"Enter your query for the book: ";
            getline(cin>>ws, queryForBook);
            searchBook(arr,queryForBook);
            return main();            
        }
        
    }

    //Entering in Librarian Menu
    if (Enterance== 2){
        // Password check

        string password = passwordInput();

        if (checkPassword(password)){
            cout<<endl<<endl<<"Login Successful"<<endl<<endl;
            Admin:

            int answerTwo = callAdmin();
            
            //for Returning Main Menu
            if (!(answerTwo==1 || answerTwo== 2 || answerTwo== 3 || answerTwo== 4 || answerTwo== 5 || answerTwo== 7)){
                return main();
            }
        
            //for Show Booklist
            if (answerTwo== 1){
                showBooklist(arr);
                return main();
            }

            //for Search Booklist
            if (answerTwo == 2){
                string queryForBook;

                queryForBook.clear();
                cout<<"Enter your query for the book: ";
                getline(cin>>ws, queryForBook);
                searchBook(arr,queryForBook);
                return main();            
            }

            //Add A Book
            if (answerTwo == 3){
                cout<<"Enter The Name - Author Of The Book : ";
                fout.open("Booklist.txt", ios::app);
                string temp_AddBook;
                getline(cin>>ws, temp_AddBook);
                if (myfile.is_open()){
                    fout<<temp_AddBook<<endl;
                }
                cout <<endl<<endl<<"Book Added Successfully"<<endl<<endl;
                arr.push_back(temp_AddBook);
                fout.close();
                goto Admin;
            }

            //Issue Books
            if (answerTwo == 4){
                IssuedBooks :
                int issue = callIssueBooks();

                if(!(issue==1 || issue==2 || issue==3 || issue==4 )){
                    return main();
                }

                //View Issued Book
                if(issue==1){
                    showIssuedBooklist(vect);
                    goto IssuedBooks;
                }

                //Issue Book
                if(issue==2){
                    cout<<"Enter The Entry Number - Name Of The Book(DD:MM:YY) : ";
                    fout1.open("IssuedBooklist.txt", ios::app);
                    string temp_IssueBook;
                    getline(cin>>ws, temp_IssueBook);
                    if (myfile1.is_open()){
                        fout1<<temp_IssueBook<<endl;
                    }
                    cout <<endl<<endl<<"Book Issued Successfully"<<endl<<endl;
                
                    fout1.close();
                    vect.push_back(temp_IssueBook);
                    goto IssuedBooks;
                }

                //Return Book
                if(issue==3){
                    fout1.open("IssuedBooklist.txt");
                    string removeIssued;
                    cout<<endl<<"Enter The Details In Same Order (Entry Number - Name Of The Book(DD:MM:YY)) : ";
                    getline(cin>>ws, removeIssued);
                    
                    for (int i=0; i<vect.size(); i++){
                        if (!(vect[i]==removeIssued)){
                            fout1<<vect[i]<<endl;
                        }
                        if (vect[i]==removeIssued){
                            vect.erase(vect.begin()+i);
                        }
                    }

                    cout<<endl<<endl<<"Book Returned Successfully"<<endl<<endl;
                    fout1.close();   
                    goto IssuedBooks;                 
                }

                //Reissue Book
                if (issue==4){
                    fout1.open("IssuedBooklist.txt");
                    string reIssue;
                    cout<<endl<<"Enter The Details In Same Order (Entry Number - Name Of The Book(DD:MM:YY)) : ";
                    getline(cin>>ws, reIssue);
                    
                    for (int i=0; i<vect.size(); i++){
                        if (!(vect[i]==reIssue)){
                            fout1<<vect[i]<<endl;
                        }
                        if (vect[i]==reIssue){
                            vect.erase(vect.begin()+i);
                        }
                    }

                    string newDateReIssue;
                    cout<<endl<<"Enter Details With New Date (Entry Number - Name Of The Book(DD:MM:YY)) : ";
                    getline(cin>>ws, reIssue);
                    if (myfile1.is_open()){
                        fout1<<newDateReIssue<<endl;
                    }
                    cout <<endl<<endl<<"Book Re-Issued Successfully"<<endl<<endl;
                
                    fout1.close();
                    vect.push_back(newDateReIssue);
                    goto IssuedBooks;
                }

            }

            //Change Password
            if (answerTwo == 5){
                NewPass:
                cout<<endl<<endl<<"Enter A Highly Secured New Password\n (must only contain alpha numeric characters or @ or _ and must be greater than 5 characters)\n";
                string newPassword;
                getline(cin>>ws, newPassword);
                cout<<endl;

                if (newPassword.size()<=5){
                    cout<<"Not Acceptable"<<endl;
                    goto NewPass;
                }
                else{
                    fout.open("Password.txt");
                    fout<<newPassword;
                    
                    fout.close();
                    cout<<endl<<"Password Changed Successfully"<<endl<<endl;
                    return main();
                }
            }

            //Close Application
            if (answerTwo == 7){
                return 0;
            }
        }
        else{
            cout<<endl<<endl<<"Access Denied"<<endl<<endl;
            return main();
        }
    }
}