/**A Banking System with normal transaction**/
#include<iostream>
#include<fstream>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<dos.h>
#include<iomanip>

using namespace std;

class Menus
{
public:
    void showmenu(void);
private:
    void closemenu(void);
};

class dispRecords
{
public:
    void addDetails(int, char name[30], char address[60], float);
    void displayCustomers(void);
    void deleteAccount(int);
    void updateBalance(int, float);
    void updateCustomer(void);
    int lastAccount(void);
    int accountExists(int);
    char *getName(int);
    char *getAddress(int);
    float getBalance(int);
    int getRecord(int);
    int getdate(int);
    void display(int);
    void displayList(void);
    int AccountNumber;
    char name[50],address[50];
    float intBalance;
};

class accountTransactions
{
public:
    void new_account(void);
    void closeAccount(void);
    void display_account(void);
    void transaction(void);
    void addDetails(int,int,int,int,char,char typeTransaction[15],float,float,float);
    void deleteAccount(int);
    int dateDiffer(int,int,int,int,int,int);
    float getInterest(int,float);
    void display(int);
    void showAccount(int);
    int AccountNumber;
    char trantype[10];
    int dday,mmonth,yyear;
    char transactions;
    float intInterest,intAmount,intBalance;
    static float calcInterest;
    void showInterest(void);
};

void Menus::showmenu(void)
{
    char choice;
    while(1)
    {
        system("cls");
        cout<<"\n    --Welcome to Banking System Applications--    \n";
        cout<<"**************************************************\n\n";
        cout<<"    Choose from Options    \n";
        cout<<"___________________________\n";
        cout<<"    1: Open an Account\n";
        cout<<"    2: View an Account\n";
        cout<<"    3: Show all Accounts\n";
        cout<<"    4: Make a Transaction\n";
        cout<<"    5: Calculate Interest\n";
        cout<<"    6: Close an Account\n";
        cout<<"    7: Exit\n\n";
        cout<<"    please select a choice : ";
        choice=getche();

        if(choice=='1')
        {
            accountTransactions objAT;
            objAT.new_account();
        }
        else
        if(choice=='2')
        {
            accountTransactions objAT;
            objAT.display_account();
        }
        else
        if(choice=='3')
        {
            dispRecords newRec;
            newRec.displayCustomers();
        }
        else
        if(choice=='4')
        {
            accountTransactions objAT;
            objAT.transaction();
        }
        else
        if(choice=='5')
        {
            accountTransactions objAT;
            objAT.showInterest();
        }
        else
        if(choice=='6')
        {
            closemenu();
        }
        else
        if(choice=='7')
        {
            cout<<"\n    Thanks for using this application. Please press any key to exit.\n";
            getch();
            break;
        }
    }
}

void Menus::closemenu(void)
{
    char choice;
    while(1)
    {
        system("cls");
        cout<<"    --Close Menu-- \n";
        cout<<"    ************** \n";
        cout<<"    1: Close/Delete an Account\n";
        cout<<"    0: Exit from this menu\n\n";
        cout<<"    Select a Choice : ";
        choice=getche();

        if(choice=='1')
        {
            accountTransactions AT;
            AT.closeAccount();
            break;
        }
        else
        if(choice=='0')
        {
            cout<<"\n    You have entered 0 to go back to the previous Menu. \n";
            getch();
            break;
        }
    }
}

int dispRecords::lastAccount(void)
{
    fstream filename;
    filename.open("newrecords.dat",ios::in);
    filename.seekg(0,ios::beg);
    int count=0;
    while(filename.read((char *)this, sizeof(dispRecords)))
        count=AccountNumber;
    filename.close();
    return count;
}

int dispRecords::getRecord(int retrieve_AccNo)
{
    fstream filename;
    filename.open("newrecords.dat",ios::in);
    filename.seekg(0,ios::beg);
    int count=0;
    while(filename.read((char *)this, sizeof(dispRecords)))
    {
        count++;
        if(retrieve_AccNo==AccountNumber)
            break;
    }
    filename.close();
    return count;
}

void dispRecords::display(int retrieve_AccNo)
{
    int record;
    record=getRecord(retrieve_AccNo);
    fstream filename;
    filename.open("newrecords.dat",ios::in);
    filename.seekg(0,ios::end);
    int location;
    location=(record) * sizeof(dispRecords);
    filename.seekp(location);
    while(filename.read((char *)this, sizeof(dispRecords)))
    {
        if(retrieve_AccNo==AccountNumber)
        {
            cout<<"\n    ACCOUNT NO. : "<<AccountNumber;
            cout<<"\n    Name    : "<<name;
            cout<<"\n    Address : "<<address;
            cout<<"\n    Balance : "<<intBalance;
            break;
        }
    }
    filename.close();
}

char *dispRecords::getName(int retrieve_AccNo)
{
    fstream filename;
    filename.open("newrecords.dat",ios::in);
    filename.seekg(0,ios::beg);
    char retrieve_CustName[30];
    while(filename.read((char *)this, sizeof(dispRecords)))
    {
        if(AccountNumber==retrieve_AccNo)
        {
            strcpy(retrieve_CustName,name);
        }
    }
    filename.close();
    return retrieve_CustName;
}

char *dispRecords::getAddress(int retrieve_AccNo)
{
    fstream filename;
    filename.open("newrecords.dat",ios::in);
    filename.seekg(0,ios::beg);
    char retrieve_Address[60];
    while(filename.read((char *)this, sizeof(dispRecords)))
    {
        if(AccountNumber==retrieve_AccNo)
        {
            strcpy(retrieve_Address,address);
        }
    }
    filename.close();
    return retrieve_Address;
}

float dispRecords::getBalance(int retrieve_AccNo)
{
    fstream filename;
    filename.open("newrecords.dat",ios::in);
    filename.seekg(0,ios::beg);
    float iBalance;
    while(filename.read((char *)this, sizeof(dispRecords)))
    {
        if(AccountNumber==retrieve_AccNo)
        {
            iBalance=intBalance;
        }
    }
    filename.close();
    return iBalance;
}

int dispRecords::accountExists(int retrieve_AccNo)
{
    fstream filename;
    filename.open("newrecords.dat",ios::in);
    filename.seekg(0,ios::beg);
    int count=0;
    while(filename.read((char *)this, sizeof(dispRecords)))
    {
        if(AccountNumber==retrieve_AccNo)
        {
            count=1;
            break;
        }
    }
    filename.close();
    return count;
}

void dispRecords::displayList()
{
    cout<<"        \n\n";
    int day1,month1,year1;
    struct date dateval;
    getdate(&dateval);
    day1=dateval.da_day;
    month1=dateval.da_mon;
    year1=dateval.da_year;
    cout<<"\n Date: "<<day1<<"/"<<month1<<"/"<<year1<<"\n";
    cout<<setw(80)<<"______________________________\n";
    cout<<setw(23)<<" ACCOUNT NO.";
    cout<<setw(23)<<" NAME OF PERSON";
    cout<<setw(23)<<" BALANCE\n";
    cout<<setw(80)<<"______________________________\n";
}

void dispRecords::displayCustomers(void)
{
    system("cls");
    int len1;
    int row=8, check;
    fstream filename;
    FILE *pFile;
    pFile=fopen("newrecords.dat","r");
    if(pFile==NULL)
    {
        cout<<"\n  No Account exists. Please go back to the previous menu. \n";
        getch();
        return ;
    }
    else
    {
        displayList();
        filename.open("newrecords.dat",ios::in);
        filename.seekg(0,ios::beg);
        while(filename.read((char *)this, sizeof(dispRecords)))
        {
            check=0;
            cout.fill(' ');
            cout<<setw(20);
            cout.setf(ios::right,ios::adjustfield);
            cout<<AccountNumber;
            cout.fill(' ');
            cout<<setw(25);
            cout.setf(ios::internal,ios::adjustfield);
            cout<<name;
            cout<<setw(23);
            cout.setf(ios::right,ios::adjustfield);
            cout<<intBalance<<"\n";
            row++;
            if(row==23)
            {
                check=1;
                row=8;
                cout<<"\n\n Continue the application... \n";
                getch();
                system("cls");
                displayList();
            }
        }
    }
    filename.close();
    if(!check)
    {
        cout<<"\n\n Continue the application... \n";
        getch();
    }
}

void dispRecords::addDetails(int retrieve_AccNo,char retrieve_CustName[30],char retrieve_Address[60],float iBalance)
{
    AccountNumber=retrieve_AccNo;
    strcpy(name,retrieve_CustName);
    strcpy(address,retrieve_Address);
    intBalance=iBalance;
    fstream filename;
    filename.open("newrecords.dat",ios::out|ios::app);
    filename.write((char *)this, sizeof(dispRecords));
    filename.close();
}

void dispRecords::deleteAccount(int retrieve_AccNo)
{
    fstream filename;
    filename.open("newrecords.dat",ios::in);
    fstream temp;
    temp.open("calculations.txt",ios::out);
    filename.seekg(0,ios::beg);
    while(!filename.eof())
    {
        filename.read((char *)this, sizeof(dispRecords));
        if(filename.eof())
            break;
        if(AccountNumber!=retrieve_AccNo)
            temp.write((char *)this, sizeof(dispRecords));
    }
    filename.close();
    temp.close();
    filename.open("newrecords.dat",ios::out);
    temp.open("calculations.txt",ios::in);
    temp.seekg(0,ios::beg);
    while(!temp.eof())
    {
        temp.read((char *)this, sizeof(dispRecords));
        if(temp.eof())
            break;
        filename.write((char *)this, sizeof(dispRecords));
    }
    filename.close();
    temp.close();
}

void dispRecords::updateBalance(int retrieve_AccNo,float iBalance)
{
    int record;
    record=getRecord(retrieve_AccNo);
    fstream filename;
    filename.open("newrecords.dat",ios::out|ios::ate);
    intBalance=iBalance;
    int location;
    location=(record-1)*sizeof(dispRecords);
    filename.seekp(location);
    filename.write((char *)this, sizeof(dispRecords));
    filename.close();
}

void accountTransactions::addDetails(int retrieve_AccNo,int day1,int month1,int year1,char t_tran,char typeTransaction[10],
                                     float interest_accrued,float t_amount,float iBalance)
{
    fstream filename;
    filename.open("transactions.dat",ios::app);
    AccountNumber=retrieve_AccNo;
    dday=day1;
    mmonth=month1;
    yyear=year1;
    transactions=t_tran;
    strcpy(trantype,typeTransaction);
    intInterest=interest_accrued;
    intAmount=t_amount;
    intBalance=iBalance;
    filename.write((char *)this, sizeof(accountTransactions));
    filename.close();
}

void accountTransactions::deleteAccount(int retrieve_AccNo)
{
    fstream filename;
    filename.open("transactions.dat",ios::in);
    fstream temp;
    temp.open("calculations.txt",ios::out);
    filename.seekg(0,ios::beg);
    while(!filename.eof())
    {
        filename.read((char *)this, sizeof(accountTransactions));
        if(filename.eof())
            break;
        if(AccountNumber!=retrieve_AccNo)
            temp.write((char *)this, sizeof(accountTransactions));
    }
    filename.close();
    temp.close();
    filename.open("transactions.dat",ios::out);
    temp.open("calculations.txt",ios::in);
    temp.seekg(0,ios::beg);
    while(temp.eof())
    {
        temp.read((char *)this, sizeof(accountTransactions));
        if(temp.eof())
            break;
        filename.write((char *)this, sizeof(accountTransactions));
    }
    filename.close();
    temp.close();
}

void accountTransactions::new_account(void)
{
    char choice;
    int i,check;
    system("cls");
    dispRecords newRec;
    cout<<"    Please press 0 to go back to the previous menu. \n";
    cout<<"                                   \n";
    cout<<"    --Open a New Bank Account--    \n";
    cout<<"    ***************************    \n";
    int day1,month1,year1;
    struct date dateval;
    getdate(&dateval);
    day1=dateval.da_day;
    month1=dateval.da_mon;
    year1=dateval.da_year;
    int retrieve_AccNo;
    retrieve_AccNo=newRec.lastAccount();
    retrieve_AccNo++;
    if(retrieve_AccNo==1)
    {
        newRec.addDetails(retrieve_AccNo,"Ravi","Delhi",1.1);
        newRec.deleteAccount(retrieve_AccNo);
        addDetails(retrieve_AccNo,1,1,1997,'D',"Default value",1.1,1.1,1.1);
        deleteAccount(retrieve_AccNo);
    }
    char retrieve_CustName[30],tran_acc[10],retrieve_Address[60];
    float t_bal,iBalance;
    cout<<"    Date : "<<day1<<"/"<<month1<<"/"<<year1<<"\n";
    cout<<"    Account no. # "<<retrieve_AccNo;
    do
    {
        cout<<"\n\n    Please enter the Name of the Account Holder  : ";
        check=1;
        gets(retrieve_CustName);
        if(retrieve_CustName[0]=='0')
        {
            cout<<"\n\t    Invalid Customer Name. ";
            getch();
            return;
        }
        strupr(retrieve_CustName);
        if(strlen(retrieve_CustName)==0||strlen(retrieve_CustName)>30)
        {
            check=0;
            cout<<"\t\n    Customer Name is either blank or its length is greater than 30 characters.\n";
            getch();
        }
    }while(!check);
    do
    {
        cout<<"\n    Please enter the Account Holder's Address : ";
        check=1;
        gets(retrieve_Address);
        if(retrieve_Address[0]=='0')
        {
            cout<<"\n\t    Invalid Customer Address.";
            getch();
            return;
        }
        strupr(retrieve_Address);
        if(strlen(retrieve_Address)<1||strlen(retrieve_Address)>60)
        {
            check=0;
            cout<<"\t\n    Customer Address is either blank or its length is greater than 60 characters.\n";
            getch();
        }
    }while(!check);
    do
    {
        char chr_VerifyingPerson[30];
        cout<<"\n    Please enter the Name of the Verifying Person of the Account Holder : ";
        check=1;
        gets(chr_VerifyingPerson);
        if(chr_VerifyingPerson[0]=='0')
        {
            cout<<"\n\t    Invalid Verifying Person Name.";
            getch();
            return;
        }
        strupr(chr_VerifyingPerson);
        if(strlen(chr_VerifyingPerson)<1||strlen(chr_VerifyingPerson)>30)
        {
            check=0;
            cout<<"\t\n    The Verifying Person's Name is either blank or greater than 60 characters. Please try again.\n";
            getch();
        }
    }while(!check);
    do
    {
        cout<<"\n    Please enter the Deposit Amount while opening a New Account : ";
        check=1;
        gets(tran_acc);
        t_bal=atof(tran_acc);
        iBalance=t_bal;
        if(strlen(tran_acc)<1)
        {
            cout<<"\n    Invalid Transaction value. Exiting from the current Menu.\n";
            getch();
            return;
        }
        if(iBalance<1000)
        {
            check=0;
            cout<<"\t\n    The Minimum Deposit Amount should be Rs.1000. Please try again.\n";
            getch();
        }
    }while(!check);
    do
    {
        cout<<"\n    Do you want to save the record? (y/n) : ";
        choice=getche();
        choice=toupper(choice);
    }while(choice!='N'&&choice!='Y');
    if(choice=='N'||choice=='n')
    {
        cout<<"\n    The Customer Account is not created.\nPlease continue with the application.\n";
        getch();
        return;
    }
    float t_amount,interest_accrued;
    t_amount=iBalance;
    interest_accrued=0.0;
    char t_tran,typeTransaction[10];
    t_tran='D';
    strcpy(typeTransaction," ");
    newRec.addDetails(retrieve_AccNo,retrieve_CustName,retrieve_Address,iBalance);
    addDetails(retrieve_AccNo,day1,month1,year1,t_tran,typeTransaction,interest_accrued,t_amount,iBalance);
    cout<<"\n\n    The New Account is successfully created.\n    Please continue with the application.\n";
    getch();
}

void accountTransactions::showAccount(int retrieve_AccNo)
{
    cout<<"    \n";
    int day1,month1,year1;
    struct date dateval;
    getdate(&dateval);
    day1=dateval.da_day;
    month1=dateval.da_mon;
    year1=dateval.da_year;
    cout<<"Date: "<<day1<<"/"<<month1<<"/"<<year1<<"\n";
    cout<<"Account no. "<<retrieve_AccNo;
    dispRecords newRec;
    char retrieve_CustName[30];
    strcpy(retrieve_CustName,newRec.getName(retrieve_AccNo));
    char retrieve_Address[60];
    strcpy(retrieve_Address,newRec.getAddress(retrieve_AccNo));
    cout<<setw(25)<<"\n    Account Holder's Name : "<<retrieve_CustName;
    cout<<"\n    Address          :      "<<retrieve_Address<<"\n";
    cout<<setw(80)<<"\n____________________________\n";
    cout<<setw(10)<<"Dated";
    cout<<setw(12)<<"Details";
    cout<<setw(12)<<"Deposited";
    cout<<setw(15)<<"Withdrawn";
    cout<<setw(12)<<"        ";
    cout<<setw(10)<<"Balance";
    cout<<setw(80)<<"\n____________________________\n";
}

void accountTransactions::display_account(void)
{
    system("cls");
    char t_acc[10];
    int tran_acc,retrieve_AccNo;
    dispRecords obj2;
    cout<<"    Press 0 to go back to previous menu.\n";
    cout<<"    Please enter Account No. you want to view : ";
    gets(t_acc);
    tran_acc=atoi(t_acc);
    retrieve_AccNo=tran_acc;
    if(retrieve_AccNo==0)
    {
        cout<<"\n    You have pressed 0 to exit. \n";
        getch();
        return;
    }
    system("cls");
    dispRecords newRec;
    accountTransactions aa;
    int row=8,check;
    fstream filename;
    FILE *pFile;
    pFile=fopen("newrecords.dat","r");
    if(pFile==NULL)
    {
        cout<<"\n    No such Account Exists. Please create a New Account. \n";
        getch();
        return;
    }
    else if(!newRec.accountExists(retrieve_AccNo))
    {
        cout<<"\t\n    Account does not exist.\n";
        getch();
        return;
    }
    else
    {
        showAccount(retrieve_AccNo);
        filename.open("transactions.dat",ios::in);
        while(filename.read((char *)this, sizeof(accountTransactions)))
        {
            if(AccountNumber==retrieve_AccNo)
            {
                check=0;
                cout<<setw(3)<<dday<<"/"<<mmonth<<"/"<<yyear;
                cout<<setw(10)<<trantype;
                if(transactions=='D')
                {
                    cout.setf(ios::right,ios::adjustfield);
                    cout<<setw(15);
                    cout<<intAmount;
                    cout<<setw(20);
                    cout<<" ";
                }
                else
                {
                    cout.setf(ios::right,ios::adjustfield);
                    cout<<setw(25);
                    cout<<intAmount;
                    cout<<setw(10);
                    cout<<" ";
                }
                cout<<setw(15);
                cout.setf(ios::right,ios::adjustfield);
                cout<<intBalance<<"\n";
                row++;
                if(row==23)
                {
                    check=1;
                    row=8;
                    cout<<"\n\n    Please continue with the application. \n";
                    getch();
                    system("cls");
                    showAccount(retrieve_AccNo);
                }
            }
        }
    }
    filename.close();
    if(!check)
    {
        cout<<"\n\n    Press any key to continue with the application. \n";
        getch();
    }
}

int accountTransactions::dateDiffer(int day1,int month1,int year1,int day2,int month2,int year2)
{
    static int monthArr[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int days=0;
    while(day1!=day2||month1!=month2||year1!=year2)
    {
        days++;
        day1++;
        if(day1>monthArr[month1-1])
        {
            day1=1;
            month1++;
        }
        if(month1>12)
        {
            month1=1;
            year1++;
        }
    }
    return days;
}

float accountTransactions::getInterest(int retrieve_AccNo,float iBalance)
{
    fstream filename;
    filename.open("transactions.dat",ios::in);
    dispRecords newRec;
    filename.seekg(0,ios::beg);
    int day1,month1,year1,month_day;
    while(filename.read((char *)this, sizeof(accountTransactions)))
    {
        if(AccountNumber==retrieve_AccNo)
        {
            day1=dday;
            month1=mmonth;
            year1=yyear;
            iBalance=newRec.getBalance(retrieve_AccNo);
            break;
        }
    }
    int day2,month2,year2;
    struct date dateval;
    getdate(&dateval);
    day2=dateval.da_day;
    month2=dateval.da_mon;
    year2=dateval.da_year;
    float interest_accrued=0.0;
    int yeardiff=year2-year1;
    if((year2<year1)||(year2==year1&&month2<month1)||(year2==year1&&month2==month1&&day2<day1))
    {
        return interest_accrued;
    }
    month_day=dateDiffer(day1,month1,year1,day2,month2,year2);
    int months;
    if(month_day>=30)
    {
        months=month_day/30;
    }
    else
    {
        months=month_day/30;
    }
    if(interest_accrued==0&&yeardiff==1)
    {
        interest_accrued=((iBalance*0.5)/100)*(months);
    }
    else if(yeardiff>1&&yeardiff<25&&interest_accrued==0)
    {
        interest_accrued=((iBalance*0.5)/100)*(months);
    }
    else
    {
        interest_accrued=0;
    }
    filename.close();
    return interest_accrued;
}

void accountTransactions::showInterest(void)
{
    system("cls");
    char t_acc[10];
    int tran_acc,retrieve_AccNo,check;
    cout<<strupr("\n    Important Information: Interest should be generated only\n once in a Year.\n\n\t If you have already generated interest for an Account,\n\tplease ignore that Account.\n\t Thank you.\n");
    cout<<"\n    Press 0 to go back to previous menu.\n";
    cout<<"\n    To view the transaction of the Account, please enter it: ";
    gets(t_acc);
    tran_acc=atoi(t_acc);
    retrieve_AccNo=tran_acc;
    if(retrieve_AccNo==0)
        return;
    system("cls");
    dispRecords newRec;
    if(!newRec.accountExists(retrieve_AccNo))
    {
        cout<<"\t\n    Account does not exist.\n";
        getch();
        return;
    }
    cout<<"    Press 0 to go back to previous menu.\n";
    cout<<"                                        \n";
    cout<<"\n    -Please enter the Account no. to generate interest-  \n";
    cout<<"***********************************************************\n";
    int day1,month1,year1;
    struct date dateval;
    getdate(&dateval);
    day1=dateval.da_day;
    month1=dateval.da_mon;
    year1=dateval.da_year;
    cout<<"    Date: "<<day1<<"/"<<month1<<"/"<<year1<<"\n";
    cout<<"    Account no. "<<retrieve_AccNo<<"\n";
    char retrieve_CustName[30];
    char retrieve_Address[60];
    float iBalance;
    strcpy(retrieve_CustName,newRec.getName(retrieve_AccNo));
    strcpy(retrieve_Address,newRec.getAddress(retrieve_AccNo));
    iBalance=newRec.getBalance(retrieve_AccNo);
    cout<<"    Customer Name    :    "<<retrieve_CustName;
    cout<<"\n    Customer Address :    "<<retrieve_Address;
    cout<<"\n    Bank Balance     :    "<<iBalance;
    float interest_accrued;
    interest_accrued=getInterest(retrieve_AccNo,iBalance);
    cout<<"\n\t Interest generated:    "<<interest_accrued;
    getch();
    iBalance=iBalance+interest_accrued;
    dispRecords obj2;
    obj2.updateBalance(retrieve_AccNo,iBalance);
    addDetails(retrieve_AccNo,day1,month1,year1,'D',"Interest",interest_accrued,interest_accrued,iBalance);
}

void accountTransactions::transaction(void)
{
    system("cls");
    char t_acc[10];
    int tran_acc,retrieve_AccNo,check;
    cout<<"    Press 0 to go back to the previous menu.\n";
    cout<<"    To view the transactions of the Account, Please enter it: ";
    gets(t_acc);
    tran_acc=atoi(t_acc);
    retrieve_AccNo=tran_acc;
    if(retrieve_AccNo==0)
        return;
    system("cls");
    dispRecords newRec;
    if(!newRec.accountExists(retrieve_AccNo))
    {
        cout<<"\t\n    Account does not exist.\n";
        getch();
        return;
    }
    cout<<"    Press 0 to go back to the previous menu.\n";
    cout<<"                                            \n";
    cout<<"    -Make correct entry for the Transaction below- \n";
    cout<<"******************************************************\n";
    int day1,month1,year1;
    struct date dateval;
    getdate(&dateval);
    day1=dateval.da_day;
    month1=dateval.da_mon;
    year1=dateval.da_year;
    cout<<"    Date: "<<day1<<"/"<<month1<<"/"<<year1<<"\n";
    cout<<"    Account no. "<<retrieve_AccNo<<"\n";
    char retrieve_CustName[30];
    char retrieve_Address[60];
    float iBalance;
    float interest_accrued=0.0;
    strcpy(retrieve_CustName,newRec.getName(retrieve_AccNo));
    strcpy(retrieve_Address,newRec.getAddress(retrieve_AccNo));
    iBalance=newRec.getBalance(retrieve_AccNo);
    cout<<"    Customer Name    :    "<<retrieve_CustName;
    cout<<"\n    Customer Address :    "<<retrieve_Address;
    cout<<"\n    Bank Balance     :    "<<iBalance;
    char tranDetails,typeTransaction[10],tm[10];
    float t_amount,t_amt;
    do
    {
        cout<<"\n    Please enter D for Deposit or W for Withdrawal of Amount: ";
        tranDetails=getche();
        if(tranDetails=='0')
        {
            cout<<"\n\n    You have pressed 0 to Exit.";
            getch();
            return;
        }
        tranDetails=toupper(tranDetails);
    }while(tranDetails!='W'&&tranDetails!='D');
    do
    {
        cout<<"\n    The Transaction type is either Cash or Cheque..\n";
        check=1;
        cout<<"    (Cash/Cheque) : ";
        gets(typeTransaction);
        strupr(typeTransaction);
        if(typeTransaction[0]=='0')
        {
            cout<<"\n\n    You have pressed 0 to Exit.";
            getch();
            return;
        }
        if(strlen(typeTransaction)<1||(strcmp(typeTransaction,"CASH")&&strcmp(typeTransaction,"CHEQUE")))
        {
            check=0;
            cout<<"\n    The Transaction is invalid. Please enter either Cash or Cheque.\n";
            getch();
        }
    }while(!check);
    do
    {
        cout<<"\n    Please enter the Transaction Amount :\n";
        check=1;
        cout<<"    Amount : Rs. ";
        gets(tm);
        t_amt=atoi(tm);
        t_amount=t_amt;
        if(t_amount<1||(tranDetails=='W'&&t_amount>iBalance))
        {
            check=0;
            cout<<"\n    Either Amount is not a numeric value or\n it is blank or\n you are trying to withdraw amount more than in the Account....\n";
            getch();
        }
    }while(!check);
    char choice;
    do
    {
        cout<<"\n    Save the changes made in the transaction details?(y/n):";
        choice=getche();
        choice=toupper(choice);
    }while(choice!='N'&&choice!='Y');
    if(choice=='N'||choice=='n')
    {
        cout<<"\n    The Transaction is not saved. \n";
        getch();
        return;
    }
    if(tranDetails=='D')
    {
        cout<<"\n    The Amount is Deposited in the Bank.\n";
        getch();
        iBalance=iBalance+t_amount;
    }
    else
    {
        cout<<"\n    The Amount is Withdrawn from the Bank.\n";
        getch();
        iBalance=iBalance-t_amount;
    }
    newRec.updateBalance(retrieve_AccNo,iBalance);
    addDetails(retrieve_AccNo,day1,month1,year1,tranDetails,typeTransaction,interest_accrued,t_amount,iBalance);
}

void accountTransactions::closeAccount(void)
{
    system("cls");
    char t_acc[10];
    int tran_acc,retrieve_AccNo;
    cout<<"    Press 0 to go back to previous menu.\n";
    cout<<"    Please enter the Account you want to close : ";
    gets(t_acc);
    tran_acc=atoi(t_acc);
    retrieve_AccNo=tran_acc;
    system("cls");
    dispRecords newRec;
    if(!newRec.accountExists(retrieve_AccNo))
    {
        cout<<"\t\n    You have entered an invalid Account or it does not exist.\n";
        cout<<"    Please try again.\n";
        getch();
        return;
    }
    cout<<"\n    Press 0 to go back to previous menu.\n";
    cout<<"\n    Closing this Account.\n";
    cout<<"*****************************\n\n";
    int day1,month1,year1;
    struct date dateval;
    getdate(&dateval);
    day1=dateval.da_day;
    month1=dateval.da_mon;
    year1=dateval.da_year;
    cout<<"    Date: "<<day1<<"/"<<month1<<"/"<<year1<<"\n";
    char choice;
    newRec.display(retrieve_AccNo);
    do
    {
        cout<<"\n    Are you sure you want to close this Account?(y/n): ";
        choice=getche();
        choice=toupper(choice);
    }while(choice!='N'&&choice!='Y');
    if(choice=='N'||choice=='n')
    {
        cout<<"\n    The Account is not closed.";
        getch();
        return;
    }
    newRec.deleteAccount(retrieve_AccNo);
    deleteAccount(retrieve_AccNo);
    cout<<"\t\n\n    Record Deleted Successfully.\n";
    cout<<"    Please continue with the application....\n";
    getch();
}

int login(void)
{
    char username[9],ch;
    char username1[]="banking";
    int i=0;
    char a,b[9],pass[]="tatahill";
    cout<<"\n\n";
    cout<<"\n\t    Login to the Banking Application.\n";
    cout<<"\t    *********************************\n";
    cout<<"\n\n\tPlease enter Username  :  ";
    cin>>username;
    cout<<"\n\n\tPlease enter Password to authenticate yourself  :  ";
    fflush(stdin);
        do
        {
            ch=getch();
            if(isalnum(ch))
            {
                b[i]==ch;
                cout<<"*";
                i++;
            }
            else
            {
                if(ch=='\r')
                {
                    b[i]=='\0';
                }
                else if(ch=='\b')
                {
                    i--;
                    cout<<"\b\b";
                }
            }
        }while(ch!='\r');
    b[i]='\0';
    fflush(stdin);
    if((strcmp(b,pass)==0)&&(strcmp(username1,username)==0))
    {
        cout<<"\n\n\t    You have entered successfully\n\n";
        return(1);
    }
    else
    {
        cout<<"\t\n\n    Incorrect Username or Password.";
        cout<<"\n";
        return(0);
    }
}

int main(void)
{
    system("cls");
    int val,ch;
    a: val=login();
    if(val==0)
    {
        cout<<"\n\t    Want to try again?\n";
        cout<<"\t    1. TRY AGAIN ";
        cout<<"\n\t    2. EXIT ";
        cout<<"\n\n\t    Enter your choice and press enter: ";
        cin>>ch;
        if(ch==1)
        {
            system("cls");
            goto a;
        }
        else
        {
            exit(0);
        }
    }
    Menus obj1;
    obj1.showmenu();
    return 0;
}
