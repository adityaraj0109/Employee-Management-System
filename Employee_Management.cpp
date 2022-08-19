#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iomanip>
using namespace std;

static int count=10000;

class Employee
{
    int empid;
public:
    void set_id(){
        empid=count++;
    }
    int get_id(){
        return empid;
    }
};

class Database
{
    string first_name_boy[30] = {"Aditya", "Abhishek", "Arun", "Abhinav", "Shubham", "Jeswin", "Pratik", "Suresh", "Bittu","Chirag", "Divyanshu", "Lakshya", "Mohit", "Piyush", "Rohit", "Saurav", "Ujjwal", "Vikas", "Yogesh", "Sameer", "Rahul", "Ankit", "Hritik", "Ayush", "Sanu", "Samarth", "Varun", "Aryan", "Yash", "Pushkar"};
    string first_name_girl[20] = {"Palak", "Akriti", "Riya", "Shreya", "Priyanka", "Komal", "Neelam", "Tanya", "Isha", "Tanisha", "Anamika", "Jyoti", "Shruti", "Rishita", "Surbhi", "Akshita", "Stuti", "Kritika", "Shipra", "Aditi"};
    string last_name[21] = {"Rajput", "Shandilya", "Bhardwaj", "Chauhan", "Rathod", "Dutta", "Jha", "Dubey", "Sinha", "Gupta", "Jaishwal", "Thakur", "Kashyap", "Singh", "Roy", "Chopra", "Kapoor", "Mishra", "Prasad", "Dwivedi", "Sharma"};
    char gender[2] = {'M', 'F'};
    string design[10] = {"Project Manager", "Software Engineer", "Banker", "Web Designer", "Marketing Coordinator", "Cloud Architect", "Data Analyst", "SQL Developer", "Network Administrator", "Android Developer"};
protected:
    char s;
public:
    string get_firstname_male(){
        int num=rand()%30;
        return first_name_boy[num];
    }
    string get_firstname_female(){
        int num=rand()%20;
        return first_name_girl[num];
    }
    string get_lastname(){
        int num=rand()%21;
        return last_name[num];
    }
    string get_dob(){
        string d,m;
        int days;
        int months = 1 + rand() % 12;
        if (months<10)
        {
            m="0"+to_string(months);
        }
        else
        {
            m=to_string(months);
        }
        if (months==2)
        {
            days = 1 + rand() % 28;
        }
        else
        {
            days = 1 + rand() % 30;
        }
        if (days<10)
        {
            d="0"+to_string(days);
        }
        else
        {
            d=to_string(days);
        }
        int year = 1976 + rand() % 28;  // age group between 18-45 as year between [1976,2003]
        string y=to_string(year);
        string date_of_birth = d+"/"+m+"/"+y;
        return date_of_birth;
    }
    char get_gender(){
        int num=rand()%2;
        s=gender[num];
        return s;
    }
    string get_designation(){
        int num=rand()%10;
        return design[num];
    }
    int get_salary(){
        int num=350000+rand()%9650000;  // salary between [3.5 lakh to 1 crore]
        return num;
    }
};

class Personal_Info: virtual public Database
{
protected:
    string dob;
    char sex;
public:
    void set_dob(){
        dob=get_dob();
    }
    void set_sex(){
        sex=get_gender();
    }
    char get_sex(){
        return sex;
    }
    string get_dateofbirth(){
        return dob;
    }
    void updateDOB(string k){
        dob=k;
    }
    void updateSex(char k){
        sex=k;
    }
};

class Name: virtual public Database
{
protected:
    string fname;
    string lname;
    string name;
public:
    void set_firstname(){
        if (s=='M')
        {
            fname=get_firstname_male();
        }
        else
        {
            fname=get_firstname_female();
        }
    }
    void set_lastname(){
        lname=get_lastname();
    }
    void set_name(){
        name=fname+" "+lname;
    }
    string get_name(){
        return name;
    }
    void updateName(string k){
        name=k;
    }
};

class Professional_Info: virtual public Database 
{
protected:
    string designation;
    int salary;
    float income_tax;
public:
    void set_designation(){
        designation=get_designation();
    }
    void set_salary(){
        salary=get_salary();
    }
    void set_incometax(){
        if (salary<=500000)         //If salary is less than 5 lakhs then income tax will be 5%
        {
            income_tax=0.05*salary;
        }
        else if (salary>500000 && salary<=750000)  //If salary is between 5 lakhs and 7.5 lakhs then income tax will be 12500+10% of total income exceeding 5 lakhs
        {
            income_tax=0.1*(salary-500000)+12500;
        }
        else if (salary>750000 && salary<=1000000)  //If salary is between 7.5 lakhs and 10 lakhs then income tax will be 37500+15% of total income exceeding 7.5 lakhs
        {
            income_tax=0.15*(salary-750000)+37500;
        }
        else if (salary>1000000 && salary<=1250000)  //If salary is between 10 lakhs and 12.5 lakhs then income tax will be 75000+20% of total income exceeding 10 lakhs
        {
            income_tax=0.2*(salary-1000000)+75000;
        }
        else if (salary>1250000 && salary<=1500000)  //If salary is between 12.5 lakhs and 15 lakhs then income tax will be 125000+25% of total income exceeding 12.5 lakhs
        {
            income_tax=0.25*(salary-1250000)+125000;
        }
        else  //If salary is between 12.5 lakhs and 15 lakhs then income tax will be 187500+30% of total income exceeding 15 lakhs
        {
            income_tax=0.3*(salary-1500000)+187500;
        }
    }
    float getincometax(){
        return income_tax;
    }
    string get_desig(){
        return designation;
    }
    int get_income(){
        return salary;
    }
    void updateDesignation(string k){
        designation=k;
    }
    void updateSalary(int k){
        salary=k;
    }
    void updateIncomeTax(){
        set_incometax();
    }
};

class Display:public Employee, public Name,public Professional_Info, public Personal_Info
{
public:
    void displayAll(){
        cout<<"|  "<<get_id()<<"   |"<<"\t";
        cout<<setw(18)<<name<<"   |"<<"\t";
        cout<<sex<<"   |"<<"\t";
        cout<<setw(12)<<dob<<"   |"<<"\t";
        cout<<setw(25)<<designation<<"   |"<<"\t";
        cout<<setw(8)<<salary<<"   |"<<"\t";
        cout<<setw(8)<<fixed<<setprecision(2)<<income_tax<<"   |"<<"\t";
        cout<<"\n";
    }
    void displayRecordByName(string key){
        if (key==fname)
        {
            cout<<"|  "<<get_id()<<"   |"<<"\t";
            cout<<setw(18)<<name<<"   |"<<"\t";
            cout<<sex<<"   |"<<"\t";
            cout<<setw(12)<<dob<<"   |"<<"\t";
            cout<<setw(25)<<designation<<"   |"<<"\t";
            cout<<setw(8)<<salary<<"   |"<<"\t";
            cout<<setw(8)<<fixed<<setprecision(2)<<income_tax<<"   |"<<"\t";
            cout<<"\n";
        }
    }
    void displayRecordByID(int key){
        if (key==get_id())
        {
            cout<<"|  "<<get_id()<<"   |"<<"\t";
            cout<<setw(18)<<name<<"   |"<<"\t";
            cout<<sex<<"   |"<<"\t";
            cout<<setw(12)<<dob<<"   |"<<"\t";
            cout<<setw(25)<<designation<<"   |"<<"\t";
            cout<<setw(8)<<salary<<"   |"<<"\t";
            cout<<setw(8)<<fixed<<setprecision(2)<<income_tax<<"   |"<<"\t";
            cout<<"\n";
        }
    }
    void displayRecordByDesignation(string key){
        if (key==designation)
        {
            cout<<"|  "<<get_id()<<"   |"<<"\t";
            cout<<setw(18)<<name<<"   |"<<"\t";
            cout<<sex<<"   |"<<"\t";
            cout<<setw(12)<<dob<<"   |"<<"\t";
            cout<<setw(25)<<designation<<"   |"<<"\t";
            cout<<setw(8)<<salary<<"   |"<<"\t";
            cout<<setw(8)<<fixed<<setprecision(2)<<income_tax<<"   |"<<"\t";
            cout<<"\n";
        }
    }
    void displayRecordBySalary(int key1, int key2){
        if (key1<=salary && key2>=salary)
        {
            cout<<"|  "<<get_id()<<"   |"<<"\t";
            cout<<setw(18)<<name<<"   |"<<"\t";
            cout<<sex<<"   |"<<"\t";
            cout<<setw(12)<<dob<<"   |"<<"\t";
            cout<<setw(25)<<designation<<"   |"<<"\t";
            cout<<setw(8)<<salary<<"   |"<<"\t";
            cout<<setw(8)<<fixed<<setprecision(2)<<income_tax<<"   |"<<"\t";
            cout<<"\n";
        }
    }
    void displayRecordByDOB(string key){
        if (key==dob.substr(6))
        {
            cout<<"|  "<<get_id()<<"   |"<<"\t";
            cout<<setw(18)<<name<<"   |"<<"\t";
            cout<<sex<<"   |"<<"\t";
            cout<<setw(12)<<dob<<"   |"<<"\t";
            cout<<setw(25)<<designation<<"   |"<<"\t";
            cout<<setw(8)<<salary<<"   |"<<"\t";
            cout<<setw(8)<<fixed<<setprecision(2)<<income_tax<<"   |"<<"\t";
            cout<<"\n";
        }
    }
    void displayRecordBySex(char key){
        if (key==sex)
        {
            cout<<"|  "<<get_id()<<"   |"<<"\t";
            cout<<setw(18)<<name<<"   |"<<"\t";
            cout<<sex<<"   |"<<"\t";
            cout<<setw(12)<<dob<<"   |"<<"\t";
            cout<<setw(25)<<designation<<"   |"<<"\t";
            cout<<setw(8)<<salary<<"   |"<<"\t";
            cout<<setw(8)<<fixed<<setprecision(2)<<income_tax<<"   |"<<"\t";
            cout<<"\n";
        }
    }
};

void header(){
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------";
    cout<<"\n";
    cout<<"|  "<<"EmpID"<<"   |"<<"\t";
    cout<<setw(18)<<left<<"Name"<<"   |"<<"\t";
    cout<<"Sex"<<" |"<<"\t";
    cout<<setw(12)<<left<<"DOB"<<"   |"<<"\t";
    cout<<setw(25)<<left<<"Designation"<<"   |"<<"\t";
    cout<<setw(8)<<left<<"Salary"<<"   |"<<"\t";
    cout<<setw(8)<<left<<"Income_tax"<<" |"<<"\t";
    cout<<"\n";
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------";
    cout<<"\n";
}

class SearchEmployee
{
public:
    int searchEmployeeById(int id,Display obj){
        if (id==obj.get_id())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int searchEmployeeByName(string n,Display obj){
        if (n==obj.get_name())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int searchEmployeeByDOB(string date,Display obj){
        if (date==obj.get_dateofbirth())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int searchEmployeeBySex(char gender,Display obj){
        if (gender==obj.get_gender())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int searchEmployeeByDesignation(string desig,Display obj){
        if (desig==obj.get_desig())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int searchEmployeeBySalary(int sal1,int sal2,Display obj){
        if (sal1<=obj.get_income() && sal2>=obj.get_income())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int searchEmployeeBySalary(int sal1,Display obj){
        if (sal1==obj.get_income())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

class UpdateEmployee:public Employee, public Name,public Professional_Info, public Personal_Info
{
public:
    int update_Name(Display *obj,string k){
        obj->updateName(k);
        return obj->get_id();
    }
    int update_DOB(Display *obj,string k){
        obj->updateDOB(k);
        return obj->get_id();
    }
    int update_Designation(Display *obj,string k){
        obj->updateDesignation(k);
        return obj->get_id();
    }
    int update_Sex(Display *obj,char k){
        obj->updateSex(k);
        return obj->get_id();
    }
    int update_Salary(Display *obj,int k){
        obj->updateSalary(k);
        return obj->get_id();
    }
    int update_incometax(Display *obj){
        obj->updateIncomeTax();
        return obj->get_id();
    }
};

class DeleteEmployee{
public:
    void deleteEmployee(Display *obj,int index,int n){
        for (int i =index+1; i < n; i++)
        {
            obj[i-1]=obj[i];
        }
    }
};

int main()
{
    srand(time(0));
    int n=100+rand()%101;
    Display *obj=new Display[n];
    cout<<"\t\t\t\t----------EMPLOYEE MANAGEMENT SYSTEM----------\n\n";
    cout<<"\t\t\t\t----------Printing Employee Details----------\n\n";
    header();
    for (int i = 0; i < n; i++)
    {
        obj[i].set_id();
        obj[i].set_sex();
        obj[i].set_dob();
        obj[i].set_firstname();
        obj[i].set_lastname();
        obj[i].set_name();
        obj[i].set_designation();
        obj[i].set_salary();
        obj[i].set_incometax();
        obj[i].displayAll();
    }
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------\n\n";
    cout<<"\t\t\t\t---------------Demonstration of Search Operation in the database!!----------------\n\n";
    Database object;
    SearchEmployee emp;
    UpdateEmployee update;

    int key_id=10000+rand()%200;   //Generating random key for id to search employee
    string key_name=object.get_firstname_male()+" "+object.get_lastname();   //Generating random key for name to search employee
    char key_sex=object.get_gender();                 //Generating random key for sex to search employee
    string key_dob=object.get_dob();            //Generating random key for dob to search employee
    string key_designation=object.get_designation();          //Generating random key for designation to search employee
    int key_sal1=object.get_salary();          //Generating random keys to search employee if they have salary between the keys
    int key_sal2=object.get_salary();  
    if(key_sal2<key_sal1)
    {
        int temp = key_sal1;
        key_sal1 = key_sal2;
        key_sal2 = temp;
    }
    int result1=0,result2=0,result3=0,result4=0,result5=0,result6=0;
    int temp1=0,temp2=0,temp3=0,temp4=0,temp5=0,temp6=0;
    for (int i = 0; i < n; i++)
    {
        result1=emp.searchEmployeeById(key_id,obj[i]); 
        if (result1==1 && temp1!=1)
        {
            cout<<"EmpID to be searched: "<<key_id<<endl;
            cout<<"Employee with empID "<<key_id<<" is available!!\n"<<endl;
            temp1=1;
        }
        result2=emp.searchEmployeeByName(key_name,obj[i]); 
        if (result2==1 && temp2!=1)
        {
            cout<<"Employee name to be searched: "<<key_name<<endl;
            cout<<"Employee with name "<<key_name<<" is available!!\n"<<endl;
            temp2=1;
        }
        result3=emp.searchEmployeeBySex(key_sex,obj[i]); 
        if (result3==1 && temp3!=1)
        {
            cout<<"Employee sex to be searched: "<<key_sex<<endl;
            cout<<"Employee of sex "<<key_sex<<" is available!!\n"<<endl;
            temp3=1;
        }
        result4=emp.searchEmployeeByDOB(key_dob,obj[i]); 
        if (result4==1 && temp4!=1)
        {
            cout<<"Employee with date of birth to be searched: "<<key_dob<<endl;
            cout<<"Employee with date of birth "<<key_dob<<" is available!!\n"<<endl;
            temp4=1;
        }
        result5=emp.searchEmployeeByDesignation(key_designation,obj[i]); 
        if (result5==1 && temp5!=1)
        {
            cout<<"Employee with designation to be searched: "<<key_designation<<endl;
            cout<<"Employee with designation "<<key_designation<<" is available!!\n"<<endl;
            temp5=1;
        }
        result6=emp.searchEmployeeBySalary(key_sal1,key_sal2,obj[i]); 
        if (result6==1 && temp6!=1)
        {
            cout<<"Employee with salary in between "<<key_sal1<<" and "<<key_sal2<<" to be searched: "<<endl;
            cout<<"Employee with salary in between "<<key_sal1<<" and "<<key_sal2<<" is available!!\n"<<endl;
            temp6=1;
        }
    }
    if (temp1!=1)
    {
        cout<<"EmpID to be searched: "<<key_id<<endl;
        cout<<"Employee with empID "<<key_id<<" not found!!\n"<<endl;
    }
    if (temp2!=1)
    {
        cout<<"Employee name to be searched: "<<key_name<<endl;
        cout<<"Employee with name "<<key_name<<" not found!!\n"<<endl;
    }
    if (temp3!=1)
    {
        cout<<"Employee sex to be searched: "<<key_sex<<endl;
        cout<<"Employee of sex "<<key_sex<<" not found!!\n"<<endl;
    }
    if (temp4!=1)
    {
        cout<<"Employee with date of birth to be searched: "<<key_dob<<endl;
        cout<<"Employee with date of birth "<<key_dob<<" not found!!\n"<<endl;
    }
    if (temp5!=1)
    {
        cout<<"Employee with designation to be searched: "<<key_designation<<endl;
        cout<<"Employee with designation "<<key_designation<<" not found!!\n"<<endl;
    }
    if (temp6!=1)
    {
        cout<<"Employee with salary in between "<<key_sal1<<" and "<<key_sal2<<" to be searched: "<<endl;
        cout<<"Employee with salary in between "<<key_sal1<<" and "<<key_sal2<<" not found!!\n"<<endl;
    }

    cout<<"\t\t\t\t---------------Demonstration of Update Operation in the database!!----------------\n\n";
    int index;
    while (result2!=1)
    {
        key_name=object.get_firstname_male()+" "+object.get_lastname();   //Generating random key for name to search employee
        for (int i = 0; i < n; i++)
        {
            result2=emp.searchEmployeeByName(key_name,obj[i]);
            if (result2==1)
            {
                index=i;
                break;
            }
        }
    }
    cout<<"The name to be updated is: "<<key_name<<endl;
    string new_key=object.get_firstname_male()+" "+object.get_lastname();
    cout<<"The key for name updation is : "<<new_key<<endl;
    int id=update.update_Name(&obj[index],new_key);      //Updating the name of the employee
    header();
    for (int i = 0; i < n; i++)
    {
        obj[i].displayRecordByID(id);
    }
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------\n\n";

    key_sex=obj[index].get_sex();
    cout<<"The sex to be updated is: "<<key_sex<<endl;
    char new_key1;
    if (key_sex=='F')
    {
        new_key1='M';
    }
    else
    {
        new_key1='F';
    }
    cout<<"The key for sex updation is : "<<new_key1<<endl;
    id=update.update_Sex(&obj[index],new_key1);      //Updating the sex of the employee
    header();
    for (int i = 0; i < n; i++)
    {
        obj[i].displayRecordByID(id);
    }
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------\n\n";

    while (result4!=1)
    {
        key_dob=object.get_dob();   //Generating random key for DOB to search employee
        for (int i = 0; i < n; i++)
        {
            result4=emp.searchEmployeeByDOB(key_dob,obj[i]);
            if (result4==1)
            {
                index=i;
                break;
            }
        }
    }
    cout<<"The DOB to be updated is: "<<key_dob<<endl;
    new_key=object.get_dob();
    cout<<"The key for DOB updation is : "<<new_key<<endl;
    id=update.update_DOB(&obj[index],new_key);      //Updating the DOB of the employee
    header();
    for (int i = 0; i < n; i++)
    {
        obj[i].displayRecordByID(id);
    }
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------\n\n";

    key_designation=obj[index].get_desig();
    cout<<"The designation to be updated is: "<<key_designation<<endl;
    new_key=object.get_designation();
    cout<<"The key for designation updation is : "<<new_key<<endl;
    id=update.update_Designation(&obj[index],new_key);      //Updating the designation of the employee
    header();
    for (int i = 0; i < n; i++)
    {
        obj[i].displayRecordByID(id);
    }
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------\n\n";

    result6=0;
    while (result6!=1)
    {
        key_sal1=object.get_salary();   //Generating random key for salary to search employee
        for (int i = 0; i < n; i++)
        {
            result6=emp.searchEmployeeBySalary(key_sal1,obj[i]);
            if (result6==1)
            {
                index=i;
                break;
            }
        }
    }
    cout<<"The salary to be updated is: "<<key_sal1<<endl;
    int new_key2=object.get_salary();
    cout<<"The key for salary updation is : "<<new_key2<<endl;
    id=update.update_Salary(&obj[index],new_key2);      //Updating the salary of the employee
    header();
    for (int i = 0; i < n; i++)
    {
        obj[i].displayRecordByID(id);
    }
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------\n\n";

    float key_tax=obj[index].getincometax();
    cout<<"The income tax to be updated is: "<<key_tax<<endl;
    id=update.update_incometax(&obj[index]);      //Updating the incometax of the employee
    header();
    for (int i = 0; i < n; i++)
    {
        obj[i].displayRecordByID(id);
    }
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------\n\n";

    cout<<"\t\t\t\t---------------Demonstration of Delete Operation in the database!!----------------\n\n";
    DeleteEmployee del;
    key_id=10000+rand()%n;
    index=key_id-10000;
    cout<<"The employee to be removed has id : "<<key_id<<endl;
    del.deleteEmployee(obj,index,n);      //Deleting the employee from the database
    cout<<"The employee details has been deleted successfully!!\n\n";
    header();
    for (int i = 0; i < n-1; i++)
    {
        obj[i].displayAll();
    }
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------\n\n";
    

    cout<<"\t\t\t\t---------------Demonstration of Display Operation in the database!!----------------\n\n";
    cout<<"\t\t\t\t----------Printing Employee Details----------\n\n";
    string key=object.get_firstname_male();    //Random key to search all employees starting with that name
    cout<<"Printing details of all employees starting with the name: "<<key<<endl;
    header();
    for (int i = 0; i < n-1; i++)
    {
        obj[i].displayRecordByName(key);
    }
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------\n\n";

    cout<<"\t\t\t\t----------Printing Employee Details----------\n\n";
    int key1=10000+rand()%200;   //Random key to search all employees with that id
    cout<<"Printing details of employee with empID: "<<key1<<endl;
    header();
    for (int i = 0; i < n-1; i++)
    {
        obj[i].displayRecordByID(key1);
    }
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------\n\n";

    cout<<"\t\t\t\t----------Printing Employee Details----------\n\n";
    key=object.get_designation();    //Random key to search all employees having that designation
    cout<<"Printing details of all employees with designation: "<<key<<endl;
    header();
    for (int i = 0; i < n-1; i++)
    {
        obj[i].displayRecordByDesignation(key);
    }
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------\n\n";

    cout<<"\t\t\t\t----------Printing Employee Details----------\n\n";
    key1=object.get_salary();
    int key3=object.get_salary();  //Random key to search all employees having salary between that range
    while (key1>key3)
    {
        key3=object.get_salary();
    }
    cout<<"Printing details of all employees having salary between that range "<<key1<<" and "<<key3<<endl;
    header();
    for (int i = 0; i < n-1; i++)
    {
        obj[i].displayRecordBySalary(key1,key3);
    }
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------\n\n";

    cout<<"\t\t\t\t----------Printing Employee Details----------\n\n";
    key=object.get_dob(); //Random key to search all employees having that birth year
    string s=key.substr(6);
    cout<<"Printing details of all employees born in year: "<<s<<endl;
    header();
    for (int i = 0; i < n-1; i++)
    {
        obj[i].displayRecordByDOB(s);
    }
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------\n\n";

    cout<<"\t\t\t\t----------Printing Employee Details----------\n\n";
    char key2=object.get_gender();    //Random key to search all employees having that gender
    cout<<"Printing details of all employees having sex: "<<key2<<endl;
    header();
    for (int i = 0; i < n-1; i++)
    {
        obj[i].displayRecordBySex(key2);
    }
    cout<<"---------------------------------------------------------------------";
    cout<<"---------------------------------------------------------------\n\n";
    return 0;
}