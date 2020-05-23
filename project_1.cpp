#include<fstream>
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
fstream fp,fp1;
class book
{
 char bno[6];
 char bname[50];
 char aname[20];
 public:
 void create_book()
 {
  cout<<"\nNEW BOOK ENTRY...\n";
  cout<<"\nEnter The book no.";
  cin>>bno;
  cout<<"\n\nEnter The Name of The Book ";
  cin>>bname;
  cout<<"\n\nEnter The Author's Name ";
  cin>>aname;
  cout<<"\n\n\nBook Created..";
 }
 void show_book()
 {
  cout<<"\nBook no. : "<<bno;
  cout<<"\nBook Name : ";
  puts(bname);
  cout<<"Author Name : ";
  puts(aname);
 }
 void modify_book()
 {
  cout<<"\nBook no. : "<<bno;
  cout<<"\nModify Book Name : ";
  cin>>bname;
  cout<<"\nModify Author's Name of Book : ";
  cin>>aname;
 }
 char* retbno()
 {
  return bno;
 }
 void report()
 {cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;}

}bk;


class student
{
 char admno[6];
 char name[20];
 char stbno[6];
public:
 void create_student()
 {

   cout<<"\nNEW STUDENT ENTRY...\n";
  cout<<"\nEnter The admission no. ";
  cin>>admno;
  cout<<"\n\nEnter The Name of The Student ";
  cin>>name;
  cout<<"\n\nStudent Record Created..";
 }
 void show_student()
 {
  cout<<"\nAdmission no. : "<<admno;
  cout<<"\nStudent Name : ";
  cout<<name;
 }
 void modify_student()
 {
  cout<<"\nAdmission no. : "<<admno;
  cout<<"\nModify Student Name : ";
  cin>>name;
 }
 char* retadmno()
 {
  return admno;
 }
 char* retstbno()
 {
  return stbno;
 }
 void getstbno(char t[])
 {
  strcpy(stbno,t);
 }
 void report()
 {cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<endl;}
}st;

void write_book()
{
 char ch;
 fp.open("book.txt",ios::out|ios::app);
 do
 {

  bk.create_book();
  fp.write((char*)&bk,sizeof(book));
  cout<<"\n\nDo you want to add more record..(y/n?)";
  cin>>ch;
 }while(ch=='y'||ch=='Y');
 fp.close();
}
void write_student()
{
 char ch;
 fp.open("student.txt",ios::out|ios::app);
 do
 {
  st.create_student();
  fp.write((char*)&st,sizeof(student));
  cout<<"\n\ndo you want to add more record..(y/n?)";
  cin>>ch;
 }while(ch=='y'||ch=='Y');
 fp.close();
}
void display_spb(char n[])
{
 cout<<"\nBOOK DETAILS\n";
 int flag=0;
 fp.open("book.txt",ios::in);
 while(fp.read((char*)&bk,sizeof(book)))
 {
  if(strcmp(bk.retbno(),n)==0)
  {
   bk.show_book();
    flag=1;
  }
 }

 fp.close();
 if(flag==0)
  cout<<"\n\nBook does not exist";

}
void display_sps(char n[])
{
 cout<<"\nSTUDENT DETAILS\n";
 int flag=0;
 fp.open("student.txt",ios::in);
 while(fp.read((char*)&st,sizeof(student)))
 {
  if((strcmp(st.retadmno(),n)==0))
  {
   st.show_student();
   flag=1;
  }
 }

 fp.close();
 if(flag==0)
      cout<<"\n\nStudent does not exist";

}
void modify_book()
{
 char n[6];
 int found=0;

 cout<<"\n\n\tMODIFY BOOK REOCORD.... ";
 cout<<"\n\n\tEnter The book no. of The book";
 cin>>n;
 fp.open("book.txt",ios::in|ios::out);
 while(fp.read((char*)&bk,sizeof(book)) && found==0)
 {
  if(strcmp(bk.retbno(),n)==0)
  {
   bk.show_book();
   cout<<"\nEnter The New Details of book"<<endl;
   bk.modify_book();
   int pos=-1*sizeof(bk);
   fp.seekp(pos,ios::cur);
   fp.write((char*)&bk,sizeof(book));
   cout<<"\n\n\t Record Updated";
   found=1;
  }
 }
 fp.close();
 if(found==0)
 cout<<"\n\n Record Not Found ";

}

void modify_student()
{
 char n[6];
 int found=0;

 cout<<"\n\n\tMODIFY STUDENT RECORD... ";
 cout<<"\n\n\tEnter The admission no. of The student";
 cin>>n;
 fp.open("student.txt",ios::in|ios::out);
 while(fp.read((char*)&st,sizeof(student)) && found==0)
 {
  if(strcmp(st.retadmno(),n)==0)
  {
   st.show_student();
   cout<<"\nEnter The New Details of student"<<endl;
   st.modify_student();
   int pos=-1*sizeof(st);
   fp.seekp(pos,ios::cur);
   fp.write((char*)&st,sizeof(student));
   cout<<"\n\n\t Record Updated";
   found=1;
  }
 }

 fp.close();
 if(found==0)
  cout<<"\n\n Record Not Found ";

}

void display_alls()
{

      fp.open("student.txt",ios::in);
      if(!fp)
      {
         cout<<"ERROR!!! FILE COULD NOT BE OPEN ";

         return;
      }
 cout<<"\n\n\t\tSTUDENT LIST\n\n";
 cout<<"==================================================================\n";
 cout<<"\tAdmission No."<<setw(10)<<"Name"<<setw(20);
 cout<<"\n==================================================================\n";
 while(fp.read((char*)&st,sizeof(student)))
 {
  st.report();
 }

 fp.close();

}
void display_allb()
{

 fp.open("book.txt",ios::in);
 if(!fp)
 {
  cout<<"ERROR!!! FILE COULD NOT BE OPEN ";

         return;
      }
 cout<<"\n\n\t\tBook LIST\n\n";
 cout<<"=========================================================================\n";
 cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
 cout<<"=========================================================================\n";
 while(fp.read((char*)&bk,sizeof(book)))
 {
  bk.report();
 }
      fp.close();

}

void intro()
{

 cout<<setw(40)<<"**LIBRARY  ";
 cout<<"MANAGEMENT  "<<"SYSTEM**\n";
 cout<<setw(58)<<"-----------------------------";
}
void admin_menu()
{

 int ch2;
 cout<<"\n\n\n"<<setw(40)<<"ADMINISTRATOR MENU\n";
 cout<<setw(40)<<"--------------------";
 cout<<"\n\n"<<setw(42)<<"1.CREATE STUDENT RECORD";
 cout<<"\n\n"<<setw(48)<<"2.DISPLAY ALL STUDENTS RECORD";
 cout<<"\n\n"<<setw(53)<<"3.DISPLAY SPECIFIC STUDENT RECORD ";
 cout<<"\n\n"<<setw(42)<<"4.MODIFY STUDENT RECORD";
 cout<<"\n\n"<<setw(33)<<"5.CREATE BOOK ";
 cout<<"\n\n"<<setw(39)<<"6.DISPLAY ALL BOOKS ";
 cout<<"\n\n"<<setw(43)<<"7.DISPLAY SPECIFIC BOOK ";
 cout<<"\n\n"<<setw(33)<<"8.MODIFY BOOK ";
 cout<<"\n\n"<<setw(38)<<"9.BACK TO MAIN MENU";
 cout<<"\n\n"<<setw(50)<<"Please Enter Your Choice (1-9):";
 cin>>ch2;
 switch(ch2)
 {
      case 1:
            write_student();
            break;
      case 2:display_alls();
            break;
      case 3:char num[6];
             cout<<"\n\n\tPlease Enter The Admission No. ";
             cin>>num;
              display_sps(num);
              break;
        case 4:modify_student();
              break;
        case 5:
                write_book();
                break;
        case 6: display_allb();break;
        case 7: {
                  char num[6];
                  cout<<"\n\n\tPlease Enter The book No. ";
                  cin>>num;
                  display_spb(num);
                  break;
                }
        case 8: modify_book();
                break;
        case 9: return;
        default:cout<<"Invalid Entry";
    }
}
int main()
{
 char ch;
 intro();
 do
 {

    cout<<"\n\n\n"<<setw(45)<<"MAIN MENU";
    cout<<"\n\n"<<setw(50)<<"01. ADMINISTRATOR MENU";
    cout<<"\n\n"<<setw(36)<<"02. EXIT";
    cout<<"\n\n"<<setw(55)<<"Please Select Your Option: ";
    cin>>ch;
    switch(ch)
    {
     case '1':admin_menu();
              break;
     case '2':cout<<endl<<setw(55)<<"!...Sucessfully Exiting...!";
              break;
     default :cout<<"Invalid Entry";
    }
 }while(ch!='2');
}


