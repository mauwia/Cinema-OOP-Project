#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<dos.h>
#include<limits>
#include<windows.h>
#include<process.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<ctime>
using namespace std;
int t(void);
int write_movie(char *);
int count_movies(char *);
int display_movieslist(char *);
bool check_movie_inlist(char *,char *);
int modify_movie(char *);
int delete_movie(char *); 
void main_menu();
int gotoxy(short x, short y)           //definition of gotoxy function//                                               
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
int t(void){
	time_t t;
	time(&t);
	gotoxy(72,2);
	printf("%s",ctime(&t));
}
void print_tickets(int d,char *sh,int st[],int sts,char *movie_name) {
	string n="tickets";
	int i;
	ofstream fout( (n+".txt").c_str() );
	for(i=0;i<sts;i++){
	fout<<"\t\t\t\t\t\t********RATED R CINEMA********\n"<<endl;
	fout<<"\t\t\t\t\tDay: "<<d<<"\t\t\t\t\tSeat No: "<<st[i]<<endl<<"\t\t\t\t\tShowtiming: "<<sh<<"\t\t\tMovie: "<<movie_name<<endl<<"\t\t\t\t\t\t\tTicket Price: Rs 500"<<endl;
    fout<<"------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}
	HWND hwnd = ::CreateWindow("STATIC","dummy",WS_VISIBLE,0,0,50,50,NULL,NULL,NULL,NULL);
	::SetWindowTextA(hwnd,"Check your tickets!");
	ShellExecute(hwnd,"open",(n+".txt").c_str(),NULL,NULL,SW_SHOW);
	fout.close();
}
class project_titles{
	public:
		char saim_name[50],mawia_name[50],saadat_name[50],ahmed_name[50];
		char saim_roll[50],mawia_roll[50],saadat_roll[50],ahmed_roll[50];
		char pro_by[50];
		int i,j,k,l,a,b,c;
		project_titles(){
			strcpy(saim_name,"SAIM AKHTAR");
			strcpy(mawia_name,"MAUVIA ATIF");
			strcpy(saadat_name,"SAADAT HASSAN");
			strcpy(ahmed_name,"AHMED IMRAN");
			strcpy(saim_roll,"CT-059");
			strcpy(mawia_roll,"CT-074");
			strcpy(saadat_roll,"CT-040");
			strcpy(ahmed_roll,"CT-037");
			strcpy(pro_by,"A CINEMA PROJECT BY :");
		}
		void print_name(char *n,int x,int y){
			int len=strlen(n)-1;
			for(j=len;j>=0;j--){
				delay(1);
			for(i=2;i<=x;i++){
				if(n[j] == ' '){
				gotoxy(i,y);
				cout<<n[j];
				}
				gotoxy(i,y);
				cout<<n[j];
				gotoxy(i-1,y);
				cout<<" ";
			}
			x--;
		}
		}
		void print_roll(char *n,int x, int y){
			int len=strlen(n)-1;
			for(j=0;j<=len;j++){
				delay(2);
			for(i=150;i>=x;i--){
				gotoxy(i,y);
				cout<<n[j];
				gotoxy(i+1,y);
				cout<<" ";
			}
			x++;
		}
		}
		void members(){
			print_name(saim_name,80,12);
			print_name(mawia_name,80,14);
			print_name(saadat_name,82,16);
			print_name(ahmed_name,80,18);
			print_roll(saim_roll,90,12);
			print_roll(mawia_roll,90,14);
			print_roll(saadat_roll,90,16);
			print_roll(ahmed_roll,90,18);
		}
		void move_word(char *n,int x, int y){
			int len=strlen(n)-1;
			for(i=1;i<=x;i++){
				delay(10);
				gotoxy(i,y);
				cout<<n;
				gotoxy(i-len-1,y);
				for(a=0;a<=len;a++){
					cout<<" ";
				}
			}
		}
		void project_by(char *pro,int y,int sp){
			int len=strlen(pro)-1;
				for(i=1;i<=y;i++){
					delay(sp);
					gotoxy(75,i);
					cout<<pro;
					gotoxy(75,i-1);
					for(a=0;a<=len;a++){
						cout<<" ";
					}
				}
		}
}titles;
class project_layouts{
	public:
		int x,y,z,a,b,c,i,j;
		void display_box(){
			for(i=5;i<=165;i++){
				gotoxy(i,4);
				cout<<"\xCD";
				gotoxy(i,5);
				cout<<"\xCD";
				gotoxy(i,6);
				cout<<"\xCD";
			}
			for(i=5;i<=165;i++){
				gotoxy(i,43);
				cout<<"\xCD";
				gotoxy(i,44);
				cout<<"\xCD";
				gotoxy(i,45);
				cout<<"\xCD";
			}
			for(j=4;j<=45;j++){
				gotoxy(5,j);
				cout<<"\xCD";
				gotoxy(6,j);
				cout<<"\xCD";
				gotoxy(7,j);
				cout<<"\xCD";
			}
			for(j=4;j<=45;j++){
				gotoxy(163,j);
				cout<<"\xCD";
				gotoxy(164,j);
				cout<<"\xCD";
				gotoxy(165,j);
				cout<<"\xCD";
			}
		}
		void chota_starbox(int xco,int yco){
			for(i=xco;i<=xco+5;i++){
				gotoxy(i,yco);
				cout<<".";
			}
			for(i=xco;i<=xco+5;i++){
				gotoxy(i,yco+2);
				cout<<".";
		    }
		    for(i=yco;i<=yco+2;i++){
		    	gotoxy(xco,i);
		    	cout<<".";
			}
			for(i=yco;i<yco+2;i++){
		    	gotoxy(xco+5,i);
		    	cout<<".";
			}
		}
		void chota_box(int xco,int yco){
			for(i=xco;i<=xco+25;i++){
				gotoxy(i,yco);
				cout<<"_";
			}
			for(i=xco;i<=xco+25;i++){
				gotoxy(i,yco+3);
				cout<<"_";
		    }
		    for(i=yco+1;i<=yco+3;i++){
		    	gotoxy(xco-1,i);
		    	cout<<"|";
			}
			for(i=yco+1;i<yco+4;i++){
		    	gotoxy(xco+26,i);
		    	cout<<"|";
			}
		}
		void box_star(int xco,int yco){
			for(i=xco;i<=xco+35;i++){
				gotoxy(i,yco);
				cout<<"*";
			}
			for(i=xco;i<=xco+35;i++){
				gotoxy(i,yco+3);
				cout<<"*";
		    }
		    for(i=yco;i<=yco+3;i++){
		    	gotoxy(xco,i);
		    	cout<<"*";
			}
			for(i=yco;i<yco+3;i++){
		    	gotoxy(xco+35,i);
		    	cout<<"*";
			}
		}
		void box_get_options(int op){
		i=19;
		for(a=0;a<=op;a++){
		for(x=73;x<103;x++){
		gotoxy(x,i);
		cout<<"_";
	}
	i=i+3;
}
	for(y=20;y<i-2;y++){
		gotoxy(72,y);
		cout<<"|";
		gotoxy(103,y);
		cout<<"|";
	}
		}
		void intro_design(){
			for(x=44;x<=129;x++){
				
				gotoxy(x,4);
				cout<<"*";
			}
			for(x=4;x<=44;x++){
				
				gotoxy(129,x);
				cout<<"*";
			}
			for(x=129;x>=44;x--){
				
				gotoxy(x,45);
				cout<<"*";
			}
			for(x=44;x>=4;x--){
				
				gotoxy(44,x);
				cout<<"*";
			}
			for(i=88,j=5;i<=97,j<=24;i=i+2,j=j+1){
				delay(4);
				gotoxy(i,j);
				cout<<"\\\\\\";
			}
			for(i=84,j=5;i>=34,j<=24;i=i-2,j=j+1){
				delay(4);
				gotoxy(i,j);
				cout<<"///";
			}
			for(i=126,j=25;i>=83,j<=44;i=i-2,j=j+1){
				delay(4);
				gotoxy(i,j);
				cout<<"///";
			}
			for(i=46,j=25;i<=56,j<=44;i=i+2,j=j+1){
				delay(4);
				gotoxy(i,j);
				cout<<"\\\\\\";
			}
			box_star(70,15);
			gotoxy(75,16);
			cout<<">>>CINEMA MAIN MENU<<<";
	        box_get_options(3);
	        chota_starbox(83,31);
		}
		void exiting(){
		gotoxy(50,2);
		cout<<"Returning ";
			for(j=50;j>=0;j--){
			delay(5);
			for(i=0;i<=180;i++){
				gotoxy(i,j);
				cout<<" ";
			}
		}
		}
}lay;
class project_intro{
	public:
		int a,b,c,i,j,k,l,m,n;
		void intro(){
			titles.project_by(titles.pro_by,8,100);
			lay.box_star(67,7);
            titles.members();
		}
		void logo_title(int sp){
			SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x03 );
			for(j=30;j>=14;j--){
				delay(sp);
				gotoxy(56,j);
				cout<<"****";
			}
			for(i=60;i<=73;i++){
				delay(sp);
				gotoxy(i,14);
				cout<<"*";
				gotoxy(i,15);
				cout<<"*";
			}
			for(j=14;j<=21;j++){
				delay(sp);
				gotoxy(74,j);
				cout<<"****";
			}
			for(i=74;i>=58;i--){
				delay(sp);
				gotoxy(i,20);
				cout<<"*";
				gotoxy(i,21);
				cout<<"*";
	        }
	        for(i=58,j=21;i<=74,j<=30;i=i+2,j=j+1){
				delay(sp);
				gotoxy(i,j);
				cout<<"****";
			}
			for(j=30;j>=14;j--){
				delay(sp);
				gotoxy(80,j);
				cout<<"****";
			}
			for(i=84;i<=97;i++){
				delay(sp);
				gotoxy(i,14);
				cout<<"*";
				gotoxy(i,15);
				cout<<"*";
			}
			for(j=14;j<=21;j++){
				delay(sp);
				gotoxy(98,j);
				cout<<"****";
			}
			for(i=98;i>=82;i--){
				delay(sp);
				gotoxy(i,20);
				cout<<"*";
				gotoxy(i,21);
				cout<<"*";
	        }
	        for(i=82,j=21;i<=98,j<=30;i=i+2,j=j+1){
				delay(sp);
				gotoxy(i,j);
				cout<<"****";
			}
	        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
		}
		void title_page(){
			char cn[50],tribute[50];
			strcpy(cn,"RATED R CINEMA");
			titles.move_word(cn,50,10);
			strcpy(tribute,"A TRIBUTE TO SHAHEER GHANI IMAM");
			titles.project_by(tribute,35,20);
			logo_title(10);
		}
		void thanks(){
			char tri[60];
			strcpy(tri,"THANK YOU FOR YOU COOPERATION");
			titles.project_by(tri,15,50);
		}
}intr;
class design{
	private:
		int i,j,a,upp,low,r,l,upy,ly,sy,x,y;
		char des1[10],des2[10];
		char title_seat[50];
	public:
		int display(){
		strcpy(title_seat,":::CINEMA HALL INTERIOR DISPLAY:::");
		strcpy(des1,"^^|||");strcpy(des2,"|||^^");
		x=65;
	for(a=0;a<strlen(title_seat);a++){
		gotoxy(x,2);
		cout<<title_seat[a];
		x++;
		delay(10);
	}
	delay(100);
	for(i=85,j=86;i>=25,j<=145;i--,j++){
		gotoxy(i+1,4);
		printf("<");
		gotoxy(i+1,35);
		printf("<");
		gotoxy(j+1,4);
		printf(">");
		gotoxy(j+1,35);
		printf(">");
		delay(10);
	}
	for(i=85,j=86;i>=25,j<=145;i--,j++){
		gotoxy(i+1,5);
		printf("|");
		gotoxy(i+1,34);
		printf("|");
		gotoxy(j+1,5);
		printf("|");
		gotoxy(j+1,34);
		printf("|");
		delay(10);
	}
	a=5;
	for(i=1;i<=30;i++){
		gotoxy(24,a);
		printf("%s",des1);
		gotoxy(146,a);
		printf("%s",des2);
		a++;
		delay(10);
	}
	
  }
    int book(char *t){
    	display();
    	low=32;
    	i=1;
    	for(y=7;y<=16;y++){
    		for(x=60;x<=110;x++){
    			gotoxy(x,y);
    			cout<<"*";
			}
		}
    	for(upy=17,ly=19,sy=18;upy<=31,ly<=33,sy<=32;upy=upy+3,ly=ly+3,sy=sy+3){
    	for(upp=32,l=31,r=35,a=32;upp<=136,l<=135,r<=139,a<=137;upp=upp+4,l=l+4,r=r+4,a=a+4){
    	gotoxy(upp,upy);
    	cout<<"___";
    	gotoxy(upp,ly);
    	cout<<"___";
    	gotoxy(l,sy);
    	cout<<"|";
    	gotoxy(l,ly);
    	cout<<"|";
    	gotoxy(r,sy);
    	cout<<"|";
    	gotoxy(r,ly);
    	cout<<"|";
    	gotoxy(a,sy);
    	if(t[i-1] == '1'){
    		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0xC7 );
    		cout<<"RES";
    		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 0x07 );
		}
		else{
    	cout<<i;
    }
		i++;}
	}
	}
}hall_des;

class Movie{
	public:
		char title[50];
		char genre[50];
		char category[50];
		char rating[50];
		char mod_movie[50];
		Movie(){
			strcpy(title,"NULL");
			strcpy(genre,"NULL");
		}
		int input_movie(){
			gotoxy(70,14);
			cout<<"Enter the title name of the movie: ";
			gotoxy(70,15);
			cout<<"Enter the Genre of the movie: ";
			gotoxy(70,16);
			cout<<"Enter the Category of the movie: ";
			gotoxy(70,17);
			cout<<"Enter the Ratings of the movie: ";
			gotoxy(110,14);
			fflush(stdin);
			cin.getline(title,50);
			fflush(stdin);
			strupr(title);
			gotoxy(110,15);
			fflush(stdin);
			cin.getline(genre,50);
			fflush(stdin);
			strupr(genre);
			gotoxy(110,16);
			fflush(stdin);
			cin.getline(category,50);
			fflush(stdin);
			strupr(category);
			gotoxy(110,17);
			fflush(stdin);
			cin.getline(rating,50);
			fflush(stdin);
			strupr(rating);
		}
		int display_a_movie(){
			gotoxy(76,24);
			fflush(stdin);
			cout<<"Movie title: "<<title;
			gotoxy(76,25);
			fflush(stdin);
			cout<<"Genre: "<<genre;
			gotoxy(76,26);
			fflush(stdin);
			cout<<"Category: "<<category;
			gotoxy(76,27);
			fflush(stdin);
			cout<<"Rating: "<<rating;
		}
}m;
char stemp[135];
class shows_seats{
	public:
		char seats[7][4][135];
		char t[135];
		int i,j,k,l,available_seats;
		void shows_seats_write(char *seats_file){
			ofstream fl;
			fl.open(seats_file,ios::binary | ios::app);
			for(i=0;i<135;i++){
				stemp[i]='0';
			}
			stemp[135]='\0';
			for(i=0;i<7;i++){
				for(j=0;j<4;j++){
					fflush(stdin);
					strcpy(seats[i][j],stemp);
				}
			}
			fl.write((char*)this,sizeof(*this));
			fl.close();
		}
		int reset_seats(int d,int reset){
			fflush(stdin);
			for(i=0;i<135;i++){
				seats[d-1][reset-1][i]='0';
			}
			seats[d-1][reset-1][135]='\0';
		}
		int assign_seats(int d,int s){
			fflush(stdin);
			strcpy(t,seats[d-1][s-1]);
		}
		int check_seats(int d,int tm){
			available_seats=0;
			for(i=0;i<135;i++){
				if(seats[d-1][tm-1][i] == '0'){
					available_seats++;
				}
			}
			return available_seats;
	}
	    bool check_reservation(int d,int s,int seat){
	    	fflush(stdin);
			if(seats[d-1][s-1][seat-1] == '0'){
				return true;
			}
			return false;
		}
		int book_your_ticket(int d,int s,int st){
			fflush(stdin);
			seats[d-1][s-1][st-1]='1';
		}
		int cancel_your_ticket(int d,int s,int st){
			fflush(stdin);
			seats[d-1][s-1][st-1]='0';
		}
}sts;


class showtime{
	public:
		char shows[4][50];
		char time_movie[50];
		char new_time[50];
		char movies[4][50];
		int Day;
		int seat_no,n,select,i,j,edit_show,k,t[135],no_of_seats,nos,res,available_seats,avail;
		design hall_des;
		showtime_write(char *shows_file,int z){
			ofstream file;
			file.open(shows_file,ios::binary| ios::app);
			Day=z;
			for(i=0;i<4;i++){
				strcpy(movies[i],"NULL");
			}
			strcpy(shows[0],"9AM-12PM");
			strcpy(shows[1],"1PM-4PM");
			strcpy(shows[2],"5PM-8PM");
			strcpy(shows[3],"10PM-1AM");
			file.write((char*)this,sizeof(*this));
			file.close();
		}
		bool check_showsmovies(char *mv){
			for(i=0;i<4;i++){
				fflush(stdin);
				if(strcmpi(mv,movies[i]) == 0){
					return true;
				}
			}
			return false;
		}
		int display_show(int xc,int yc){
			int xm=0;
			gotoxy(xc+56,yc-1);
			fflush(stdin);
			cout<<"::::DAY "<<Day<<"::::"<<endl;
			for(i=0;i<4;i++){
				gotoxy(xc+xm,yc+1);
				fflush(stdin);
				if(strcmpi(movies[i],"NULL") == 0){
				cout<<"("<<i+1<<")"<<shows[i]<<" : -----------";	
				}
				else{
				cout<<"("<<i+1<<")"<<shows[i]<<" : "<<movies[i];
			}
			xm=xm+36;
		}
			cout<<endl;
		}
		int check_bookings(char *shows_file,char *seats_file,int bk){
			char bk_sel[50];
			int sel_bk;
			ifstream stfile;
			ifstream fl;
			stfile.open(seats_file,ios::binary);
			stfile.read((char*)&sts,sizeof(sts));
			fl.open(shows_file,ios::binary);
			while(fl.read((char*)this,sizeof(*this))){
				if(bk == Day){
					lay.display_box();
					display_show(25,14);
					gotoxy(55,18);
					cout<<"Choose the show to check bookings: ";
					gotoxy(90,18);
					fflush(stdin);
					cin.getline(bk_sel,50);
					sel_bk=atoi(bk_sel);
					if(sel_bk == 0){
						if(strcmp(bk_sel,"0") != 0){
						gotoxy(60,20);
						cout<<"Invalid choice"<<endl;
						getch();
						}
						break;
					}
					if(sel_bk > 4 ){
						gotoxy(60,20);
						cout<<"Invalid choice"<<endl;
						getch();
						break;
					}
					if(strcmpi(movies[sel_bk-1],"NULL") == 0){
						gotoxy(60,20);
						cout<<"No movie in this show"<<endl;
						getch();
						break;
					}
					system("cls");
					sts.assign_seats(bk,sel_bk);
					avail=sts.check_seats(bk,sel_bk);
					if(avail == 0){
						gotoxy(10,5);
						cout<<"SHOW HOUSEFULL"<<endl;
					}
					hall_des.book(sts.t);
					getch();
					break;
				}
			}
			stfile.close();
			fl.close();
		}
		int ticket_booking(char *shows_file,char *seats_file,int d){
			char sel_tk[50],seats_no[50],n_seat[50];
			fstream stfile;
			ifstream file;
			stfile.open(seats_file,ios::in | ios::out);
			file.open(shows_file,ios::binary);
			stfile.read((char*)&sts,sizeof(sts));
			while(file.read((char*)this,sizeof(*this))){
			if(d == Day){
			lay.display_box();
			fflush(stdin);
			display_show(25,14);
			gotoxy(55,18);
			cout<<"Choose the Movie To book a ticket: ";
			gotoxy(90,18);
			fflush(stdin);
			cin.getline(sel_tk,50);
			select=atoi(sel_tk);
			if(select == 0){
				if(strcmp(sel_tk,"0") != 0){
				gotoxy(60,20);
				cout<<"Invalid movie choice.. Press any key to return to User Display"<<endl;
				getch();
				}
				stfile.close();
				file.close();
				return 0;
			}
			if(select >4){
				gotoxy(60,20);
				cout<<"Invalid movie choice.. Press any key to return to User Display"<<endl;
				getch();
				stfile.close();
				file.close();
				return 0;
			}
			if(strcmpi(movies[select-1],"NULL") == 0){
				gotoxy(60,20);
				cout<<"Sorry ! There is no movie in this show..."<<endl;
				getch();
				stfile.close();
				file.close();
				return 0;
			}
			system("cls");
			sts.assign_seats(d,select);
			avail=sts.check_seats(d,select);
			if(avail == 0){
				gotoxy(10,5);
				cout<<"SHOW HOUSEFULL"<<endl;
				hall_des.book(sts.t);
				getch();
				stfile.close();
				file.close();
				return 0;
			}
			else{
			hall_des.book(sts.t);
			gotoxy(70,36);
			cout<<"Number of seats available: "<<avail<<endl;
			while(1){
			gotoxy(68,39);
			cout<<"Enter the Number of seats You want to book: ";
			gotoxy(112,39);
			fflush(stdin);
			cin.getline(seats_no,50);
			no_of_seats=atoi(seats_no);
			if(no_of_seats < 1){
				gotoxy(70,41);
				cout<<"Returning to user display in a second";
				delay(1000);
				stfile.close();
				file.close();
				return 0;
			}	
			if(no_of_seats <= avail){
				int printing_seats[no_of_seats],print_var=0;
			for(nos=1;nos<=no_of_seats;nos++){
				fflush(stdin);
				gotoxy(70,41);
				cout<<nos<<". Enter the seat no: ";
				gotoxy(92,41);
				fflush(stdin);
				cin.getline(n_seat,50);
				seat_no=atoi(n_seat);
				if(seat_no > 135 || seat_no < 1){
					gotoxy(68,43);
					cout<<" Seat no "<<seat_no<<" not valid";
					nos--;
				}
				else if(!sts.check_reservation(d,select,seat_no)){
					gotoxy(68,43);
					cout<<"Seat no."<<seat_no<<" is Reserved"<<endl;
					nos--;
				}
				else{
					gotoxy(68,43);
					cout<<"You booked Seat no "<<seat_no;
					sts.book_your_ticket(d,select,seat_no);
					printing_seats[print_var]=seat_no;
					print_var++;
				}
				gotoxy(68,41);
				cout<<"                             ";
			}
			system("cls");
			stfile.seekp(-sizeof(sts),ios::cur);
			stfile.write((char*)&sts,sizeof(sts));
			sts.assign_seats(d,select);
			hall_des.book(sts.t);
			print_tickets(d,shows[select-1],printing_seats,print_var,movies[select-1]);
			getch();
			break;
		}
		else{
			gotoxy(66,41);
			cout<<"Not enough seats available..Press y to book again: ";
			if(getche() != 'y'){
				break;
			}
			gotoxy(68,39);
			cout<<"                                                                 ";
			gotoxy(66,41);
			cout<<"                                                                         ";
		}
	}
		}
	}
	}
	stfile.close();
	file.close();
		}
		int cancel_booking(char *shows_file,char *seats_file,int d){
			char sel_tk[50],seats_no[50],n_seat[50];
			fstream stfile;
			ifstream file;
			stfile.open(seats_file,ios::in | ios::out);
			file.open(shows_file,ios::binary);
			stfile.read((char*)&sts,sizeof(sts));
			while(file.read((char*)this,sizeof(*this))){
			if(d == Day){
			lay.display_box();
			fflush(stdin);
			display_show(25,14);
			gotoxy(55,18);
			cout<<"Choose the Movie To cancel a ticket: ";
			gotoxy(90,18);
			fflush(stdin);
			cin.getline(sel_tk,50);
			select=atoi(sel_tk);
			if(select == 0){
				if(strcmp(sel_tk,"0") != 0){
				gotoxy(60,20);
				cout<<"Invalid movie choice.. Press any key to return to User Display"<<endl;
				getch();
				}
				stfile.close();
				file.close();
				return 0;
			}
			if(select >4){
				gotoxy(60,20);
				cout<<"Invalid movie choice.. Press any key to return to User Display"<<endl;
				getch();
				stfile.close();
				file.close();
				return 0;
			}
			if(strcmpi(movies[select-1],"NULL") == 0){
				gotoxy(60,20);
				cout<<"Sorry ! There is no movie in this show..."<<endl;
				getch();
				stfile.close();
				file.close();
				return 0;
			}
			system("cls");
			sts.assign_seats(d,select);
			avail=sts.check_seats(d,select);
			if(avail == 135){
				gotoxy(10,5);
				cout<<"NO TICKETS BOOKED YET"<<endl;
				hall_des.book(sts.t);
				getch();
				stfile.close();
				file.close();
				return 0;
			}
			else{
			hall_des.book(sts.t);
			while(1){
			gotoxy(68,39);
			cout<<"Enter the Number of seats You want to cancel: ";
			gotoxy(114,39);
			fflush(stdin);
			cin.getline(seats_no,50);
			no_of_seats=atoi(seats_no);
			if(no_of_seats < 1){
				gotoxy(70,41);
				cout<<"Returning to user display in a second";
				delay(1000);
				stfile.close();
				file.close();
				return 0;
			}	
			if(no_of_seats <= 135-avail){
			for(nos=1;nos<=no_of_seats;nos++){
				fflush(stdin);
				gotoxy(70,41);
				cout<<nos<<". Enter the seat no: ";
				gotoxy(92,41);
				fflush(stdin);
				cin.getline(n_seat,50);
				seat_no=atoi(n_seat);
				if(seat_no > 135 || seat_no < 1){
					gotoxy(68,43);
					cout<<" Seat no "<<seat_no<<" not valid";
					nos--;
				}
				else if(sts.check_reservation(d,select,seat_no)){
					gotoxy(68,43);
					cout<<"Seat no."<<seat_no<<" is Not Booked"<<endl;
					nos--;
				}
				else{
					gotoxy(68,43);
					cout<<"You cancelled Seat no "<<seat_no;
					sts.cancel_your_ticket(d,select,seat_no);
				}
				gotoxy(68,41);
				cout<<"                             ";
			}
			system("cls");
			stfile.seekp(-sizeof(sts),ios::cur);
			stfile.write((char*)&sts,sizeof(sts));
			sts.assign_seats(d,select);
			hall_des.book(sts.t);getch();
			break;
		}
		else{
			gotoxy(66,41);
            cout<<"Not enough seats booked yet....Press y to cancel again: ";
			if(getche() != 'y'){
				break;
			}
			gotoxy(68,39);
			cout<<"                                                                 ";
			gotoxy(66,41);
			cout<<"                                                                         ";
		}
	}
		}
	}
	}
	stfile.close();
	file.close();
		}
		int edit_schedule(char *movie_file,char *shows_file,char *seats_file,int d){
			char select_mov[50],k_sel[50],show_edit[50];
			int yc=20;
			system("cls");
			gotoxy(5,2);
			cout<<"AUTHORIZED USER->Update Schedule->DAY "<<d;
			lay.display_box();
			fstream stfile;
			fstream file;
			stfile.open(seats_file,ios::in | ios::out);
			stfile.read((char*)&sts,sizeof(sts));
			file.open(shows_file,ios::in|ios::out);
			while(file.read((char*)this,sizeof(*this))){
				if(d == Day){
			gotoxy(70,18);
			fflush(stdin);
			cout<<"Current Shows In This Showtime"<<endl;
			for(i=0;i<4;i++){
				gotoxy(75,yc+i);
				cout<<"("<<i+1<<") "<<shows[i]<<" : "<<movies[i]<<endl;
			}
			gotoxy(65,25);
			cout<<"1. Edit Show time\t2.Change Movie\t3.Remove movie"<<endl;
			gotoxy(80,26);
			fflush(stdin);
			cin.getline(k_sel,50);
			k=atoi(k_sel);
			if(k == 1){
				gotoxy(5,2);
			cout<<"AUTHORIZED USER->Update Schedule->DAY "<<d<<" -> Edit Shows";
				gotoxy(65,25);
				cout<<"                                                          ";
				gotoxy(80,26);
				cout<<"   ";
				gotoxy(65,25);
				cout<<"Select the show to edit: "<<endl;
				gotoxy(80,26);
				fflush(stdin);
			    cin.getline(show_edit,50);
			    edit_show=atoi(show_edit);
			    if(edit_show <1 || edit_show >4){
			    	gotoxy(65,28);
			    	cout<<"Invalid choice";
			    	getch();
			    	break;
				}
			    system("cls");
			    gotoxy(5,2);
			cout<<"AUTHORIZED USER->Update Schedule->DAY "<<d<<" -> Edit Shows";
			    lay.display_box();
			for(i=0;i<4;i++){
				gotoxy(65,14+i);
				cout<<i+1<<"."<<shows[i]<<endl;
			}
			gotoxy(60,19);
			cout<<"Enter updated show time for "<<shows[edit_show-1];
			gotoxy(76,20);
			fflush(stdin);
			cin.getline(new_time,50);
			fflush(stdin);
			strupr(new_time);
			fflush(stdin);
			strcpy(shows[edit_show-1],new_time);
			gotoxy(73,21);
			cout<<"Show time updated"<<endl;	
			}
			else if(k == 2){
				gotoxy(5,2);
			cout<<"AUTHORIZED USER->Update Schedule->DAY "<<d<<" ->Change Movie ";
				gotoxy(65,25);
				cout<<"                                                          ";
				gotoxy(80,26);
				cout<<"   ";
				gotoxy(65,25);
				cout<<"Select a showtime at which movie is to be updated";
				gotoxy(80,26);
				fflush(stdin);
			    cin.getline(show_edit,50);
			    edit_show=atoi(show_edit);
			    if(edit_show <1 || edit_show >4){
			    	gotoxy(65,28);
			    	cout<<"Invalid choice";
			    	getch();
			    	break;
				}
				system("cls");
				gotoxy(5,2);
			cout<<"AUTHORIZED USER->Update Schedule->DAY "<<d<<" ->Change Movie ";
				lay.display_box();
			display_movieslist(movie_file);
			gotoxy(55,22);
			cout<<"Enter the name of movie to add in the showtime ("<<edit_show<<") "<<shows[edit_show-1]<<endl;
			gotoxy(75,23);
			fflush(stdin);
			cin.getline(select_mov,50);
			fflush(stdin);
			strupr(select_mov);
			if(check_movie_inlist(movie_file,select_mov)){
			fflush(stdin);
			strcpy(movies[edit_show-1],select_mov);
			sts.reset_seats(d,edit_show);
			stfile.seekp(-sizeof(sts),ios::cur);
			stfile.write((char*)&sts,sizeof(sts));
		}
		else{
			gotoxy(55,24);
			cout<<"Movie not in list"<<endl;
		}
			}
			else if(k == 3){
				gotoxy(5,2);
			cout<<"AUTHORIZED USER->Update Schedule->DAY "<<d<<" ->Remove Movie ";
			gotoxy(65,25);
			cout<<"                                                          ";
			gotoxy(80,26);
			cout<<"   ";
			gotoxy(65,25);
			cout<<"Select a showtime at which movie is to be removed";
			gotoxy(80,26);
			fflush(stdin);
			cin.getline(show_edit,50);
		    edit_show=atoi(show_edit);
		    if(edit_show <1 || edit_show >4){
	    	gotoxy(65,28);
		 	cout<<"Invalid choice";
	    	getch();
	    	break;
			}
			if(strcmpi(movies[edit_show-1],"NULL") != 0){
				fflush(stdin);
				strcpy(movies[edit_show-1],"NULL");
				sts.reset_seats(d,edit_show);
				stfile.seekp(-sizeof(sts),ios::cur);
				stfile.write((char*)&sts,sizeof(sts));
			}
			else{
				gotoxy(60,27);
				cout<<"There is already no movie in this show"<<endl;
				getch();
			}
			
	   }
			else{
				cout<<"Invalid choice"<<endl;
			}
			file.seekp(-sizeof(*this),ios::cur);
			file.write((char*)this,sizeof(*this));
		}
	}
			stfile.close();
			file.close();
		}
}st;
int write_movie(char *movie_file){
	ofstream file;
	file.open(movie_file,ios::binary| ios::app);
	m.input_movie();
	file.write((char*)&m,sizeof(m));
	file.close();
	gotoxy(75,19);
	cout<<"Movie successfully added"<<endl;
}
int count_movies(char *movie_file){
	ifstream file;
	file.open(movie_file,ios::binary);
	int i=0;
	while(file.read((char*)&m,sizeof(m))){
		i++;
	}
	file.close();
	return i;
}
int display_movieslist(char *movie_file){
	ifstream file;
	int i=1;
	int yc=15;
	gotoxy(73,12);
	cout<<"~~~~~MOVIES IN CINEMA~~~~~";
	file.open(movie_file,ios::binary);
	while(file.read((char*)&m,sizeof(m))){
		gotoxy(75,yc);
		fflush(stdin);
		cout<<"("<<i<<")"<<m.title<<"  "<<m.category;
		i++;
		yc++;
	}
	file.close();
}
bool check_movie_inlist(char *movie_file,char *n){
	ifstream file;
	file.open(movie_file,ios::binary);
	while(file.read((char*)&m,sizeof(m))){
		if(strcmpi(n,m.title) == 0){
			return true;
		}
	}
	file.close();
	return false;
}
int view_a_movie(char *movie_file,char *n){
	ifstream file;
	file.open(movie_file,ios::binary);
	if(!check_movie_inlist(movie_file,n)){
		gotoxy(80,24);
		cout<<"Movie not in list"<<endl;
		return 0;
	}
	while(file.read((char*)&m,sizeof(m))){
		if(strcmpi(n,m.title) == 0){
			m.display_a_movie();
		}
	}
	file.close();
}
int modify_movie(char *shows_file,char *movie_file){
	char new_mod[50];
	fstream fl;
	fstream file;
	fl.open(shows_file,ios::in| ios::out);
	file.open(movie_file,ios::in| ios::out);
	char mod[50];
	gotoxy(77,22);
	cout<<"Enter the name of the movie to modify: ";
	gotoxy(117,22);
	fflush(stdin);
	gets(mod);
	fflush(stdin);
	strupr(mod);
	if(!check_movie_inlist(movie_file,mod)){
		gotoxy(77,24);
		cout<<"Movie not in the list"<<endl;
		return 0;
	}
	system("cls");
	lay.display_box();
	if(check_movie_inlist(movie_file,mod)){
		while(file.read((char*)&m,sizeof(m))){
			if(strcmpi(mod,m.title) == 0){
				gotoxy(65,23);
				cout<<"Current Details";
				m.display_a_movie();
				gotoxy(65,12);
				cout<<"Enter New Details"<<endl;
				m.input_movie();
				fflush(stdin);
				strcpy(new_mod,m.title);
				file.seekp(-sizeof(m),ios::cur);
				file.write((char*)&m,sizeof(m));
			}
		}
	}
	file.close();
	gotoxy(65,29);
	cout<<"Movie modified"<<endl;
	int i;
	while(fl.read((char*)&st,sizeof(st))){
		if(st.check_showsmovies(mod)){
		for(i=0;i<4;i++){
			if(strcmpi(mod,st.movies[i]) == 0){
				fflush(stdin);
				strcpy(st.movies[i],new_mod);
			}
		}
	    fl.seekp(-sizeof(st),ios::cur);
	    fl.write((char*)&st,sizeof(st));
	}
	}
	fl.close();
}
int delete_movie(char *shows_file,char *movie_file){
	if(count_movies(movie_file) == 0){
		gotoxy(65,20);
		cout<<"No movie in the list"<<endl;
		return 0;
	}
	fstream fl;
	ofstream tmp;
	ifstream file;
	fl.open(shows_file,ios::in| ios::out);
	file.open(movie_file,ios::binary);
	tmp.open("temporary.dat",ios::binary| ios::app);
	char del[50];
	gotoxy(57,22);
	cout<<"Enter the name of the movie to remove from the list: ";
	gotoxy(117,22);
	fflush(stdin);
	gets(del);
	fflush(stdin);
	strupr(del);
	if(!check_movie_inlist(movie_file,del)){
		gotoxy(65,24);
		cout<<"Movie not in the list"<<endl;
		return 0;
	}
	while(file.read((char*)&m,sizeof(m))){
		if(strcmpi(del,m.title) != 0){
			tmp.write((char*)&m,sizeof(m));
		}
	}
	file.close();
	tmp.close();
	remove(movie_file);
	rename("temporary.dat",movie_file);
	int i;
	while(fl.read((char*)&st,sizeof(st))){
		if(st.check_showsmovies(del)){
		for(i=0;i<4;i++){
			if(strcmpi(del,st.movies[i]) == 0){
				fflush(stdin);
				strcpy(st.movies[i],"NULL");
			}
		}
	    fl.seekp(-sizeof(st),ios::cur);
	    fl.write((char*)&st,sizeof(st));
	}
	}
	fl.close();
}
class Schedule{
	public:
		int z;
		int create_schedule(char *shows_file,char *seats_file){
			for(z=1;z<=7;z++){
				st.showtime_write(shows_file,z);
			}
			sts.shows_seats_write(seats_file);
		}
		int destroy_schedule(char *shows_file,char *seats_file){
			remove(shows_file);
			remove(seats_file);
		}
		int display_schedule(char *shows_file){
			int yc=14;
			ifstream file;
			file.open(shows_file,ios::binary);
			while(file.read((char*)&st,sizeof(st))){
				st.display_show(15,yc);
				yc=yc+4;
			}
			file.close();
		}
		int check_schedule(char *shows_file){
			z=0;
			ifstream file;
			file.open(shows_file,ios::binary);
			while(file.read((char*)&st,sizeof(st))){
				z++;
			}
			file.close();
			return z;
		}
}scd;
class Cinema{
	public:
		float ticket_price;
		int no_of_tickets,z,i;
		char password[50],real_id[4][50],secret_code[50],secret_qs[50];
		char mov_file[20],show_file[20],seats_file[20];
		Cinema(){
			ticket_price=500.0;
			strcpy(password,"node786");
			strcpy(real_id[0],"saim59");
			strcpy(real_id[1],"mawia74");
			strcpy(real_id[2],"saadat40");
			strcpy(real_id[3],"ahmed37");
			strcpy(secret_code,"halkyao");
			strcpy(secret_qs,"logic");
			strcpy(mov_file,"removies.dat");
			strcpy(show_file,"reshows.dat");
			strcpy(seats_file,"reseats.dat");
		}
		int show_price(){
			cout<<"Ticket price: "<<ticket_price<<endl;
		}
		int shows_update(int d){
			st.edit_schedule(mov_file,show_file,seats_file,d);
		}
		int shows(){
			scd.display_schedule(show_file);
		}
		int show_bookings(int select_day){
			st.check_bookings(show_file,seats_file,select_day);
		}
		int ticket_bookings(int select_day){
			st.ticket_booking(show_file,seats_file,select_day);
		}
		int cancel_bookings(int select_day){
			st.cancel_booking(show_file,seats_file,select_day);
		}
		bool check_username(char *id){
			fflush(stdin);
			for(i=0;i<4;i++){
				if(strcmp(id,real_id[i]) == 0){
					return true;
				}
			}
			return false;
		}
		bool password_check(char *id,char *guessed){
			if(strcmp(password,guessed) == 0 && check_username(id)){
				return true;
			}
			return false;
		}
}c;


class person{
	protected:
		int number,i;
		char src[50],search;
	public:
		int view_movies(){
			lay.display_box();
			display_movieslist(c.mov_file);
		}
		int info_movie(){
			int xc,yc;
			do{
				view_movies();
				gotoxy(77,22);
				cout<<"Enter the movie name to view info: ";
				gotoxy(117,22);
				fflush(stdin);
				gets(src);
				fflush(stdin);
			    strupr(src);
				view_a_movie(c.mov_file,src);
				gotoxy(75,29);
				cout<<"Press y to search again: ";
				search=getche();
				for(yc=24;yc<=30;yc++){
					for(xc=73;xc<=95;xc++){
					gotoxy(xc,yc);
					cout<<"                             ";
				}
			}
				gotoxy(117,22);
				cout<<"                            ";
			}while(search == 'y');
		}
};
class customer:public person{
	public:
		int n,i,select,no,m_no,choice_user,select_day;
		char user_choice[50],day_select[50];
		int choose(){
			while(1){
				system("cls");
				lay.display_box();
				lay.box_star(70,14);
				gotoxy(78,15);
				cout<<"!!!USER DISPLAY!!!";
				lay.box_get_options(6);
				gotoxy(75,21);
				cout<<"1.Display Movies List";
				gotoxy(75,24);
				cout<<"2.View A Movie Info";
				gotoxy(75,27);
				cout<<"3.Display Show Timings";
				gotoxy(75,30);
				cout<<"4.Book Tickets";
				gotoxy(75,33);
				cout<<"5.Cancel Tickets";
				gotoxy(75,36);
				cout<<"6.Go Back To Main Menu";
				gotoxy(108,25);
				cout<<"Enter Your Choice:";
				lay.chota_starbox(127,24);
				gotoxy(128,25);
				cin.getline(user_choice,50);
				choice_user=atoi(user_choice);
				switch(choice_user){
				case 1:
					system("cls");
					gotoxy(5,2);
					cout<<"USER->Display Movies List";
					person::view_movies();
					getch();
				    break;
				case 2:
					system("cls");
					gotoxy(5,2);
					cout<<"USER->View A Movie Info";
					person::info_movie();
					break;
				case 3:
					while(1){
					system("cls");
					lay.display_box();
					gotoxy(5,2);
					cout<<"USER->Display Show Timings";
					gotoxy(20,7);
					c.show_price();
					c.shows();
					gotoxy(45,10);
					cout<<"Press 0 to go back OR Select the Day to check show bookings:";
					gotoxy(105,10);
					fflush(stdin);
					cin.getline(day_select,50);
					select_day=atoi(day_select);
					if(select_day == 0){
						if(strcmp(day_select,"0") != 0){
							gotoxy(65,11);
						cout<<"Invalid choice"<<endl;
						getch();
						}
						else{
						gotoxy(65,11);
						cout<<"Returning in a second"<<endl;
						delay(1000);
						break;
					}
					}
					if(select_day >7){
						gotoxy(65,11);
						cout<<"Invalid choice"<<endl;
						getch();
					}
					else{
						system("cls");
						gotoxy(5,2);
						cout<<"USER-> Display Show Timings->DAY "<<select_day<<" Shows";
					c.show_bookings(select_day);
				}
			}
					break;
				case 4:
					while(1){
					system("cls");
					lay.display_box();
					gotoxy(5,2);
					cout<<"USER->Book Tickets";
					c.shows();
					gotoxy(50,10);
					cout<<"Select the Day(Press 0 to go back) :";
					gotoxy(90,10);
					fflush(stdin);
					cin.getline(day_select,50);
					select_day=atoi(day_select);
					if(select_day == 0){
						if(strcmp(day_select,"0") != 0){
							gotoxy(50,12);
						cout<<"Invalid choice"<<endl;
						}
						else{
						gotoxy(50,12);
						cout<<"Returning ..";
						delay(1000);
						break;
					}
					}
					if(select_day >7){
						gotoxy(50,12);
						cout<<"Invalid choice"<<endl;
					}
					else{
						system("cls");
						gotoxy(5,2);
						cout<<"USER-> Book Tickets->DAY "<<select_day<<" Shows";
					c.ticket_bookings(select_day);
				}
			}
					break;
				case 5:
					while(1){
					system("cls");
					lay.display_box();
					gotoxy(5,2);
					cout<<"USER->Cancel Tickets";
					c.shows();
					gotoxy(50,10);
					cout<<"Select the Day(Press 0 to go back) :";
					gotoxy(90,10);
					fflush(stdin);
					cin.getline(day_select,50);
					select_day=atoi(day_select);
					if(select_day == 0){
						if(strcmp(day_select,"0") != 0){
							gotoxy(50,12);
						cout<<"Invalid choice"<<endl;
						}
						else{
						gotoxy(50,12);
						cout<<"Returning ..";
						delay(1000);
						break;
					}
					}
					if(select_day >7){
						gotoxy(50,12);
						cout<<"Invalid choice"<<endl;
					}
					else{
						system("cls");
						gotoxy(5,2);
						cout<<"USER-> Cancel Tickets->DAY "<<select_day<<" Shows";
					c.cancel_bookings(select_day);
				}
			}
					break;
				case 6:
					 main_menu();
				default:
					cout<<"Invalid choice"<<endl;
					choose();
					break;
			}
		}
	}
};
class authorized_user:public person{
	public:
		char ch,id_name[50],id[20],id_password[20];
		int attempts,counts,p,choice_user,choice_movies,choice_update_movies,choice_scd;
		bool login(){
			int pwx=105;
			attempts=2;
			counts=0;
			lay.display_box();
			gotoxy(73,10);
			cout<<"Enter your name: ";
			lay.chota_box(56,14);
			gotoxy(45,16);
			cout<<"Enter ID: ";
			lay.chota_box(103,14);
			gotoxy(85,16);
			cout<<"Enter password: ";
			gotoxy(92,10);
			fflush(stdin);
			cin.getline(id_name,50);
			fflush(stdin);
			strupr(id_name);
			do{
			p=0;
			gotoxy(62,16);
			fflush(stdin);
			cin.getline(id,20);
			while((ch=getch()) != '\r'){
				if( ch == 8){
					p--;
					pwx--;
					gotoxy(pwx,16);
					cout<<" ";
				}
				else{
				id_password[p]=ch;
				p++;
				gotoxy(pwx,16);
				cout<<"$";
				pwx++;
			}
			}
			id_password[p]='\0';
			if(c.password_check(id,id_password)){
				return true;
			}
			else{
				gotoxy(67,21);
				cout<<"Wrong id or password.Try again..You have "<<attempts<<" attempts left"<<endl;
				attempts--;
				counts++;
				gotoxy(62,16);
				cout<<"           ";
				gotoxy(105,16);
				cout<<"           ";
			}
		}while(counts <3);
		gotoxy(75,22);
		cout<<"Sorry You are not authorized"<<endl;
		getch();
		main_menu();
		}
		int update_movies(){
			char update_choice[50];
			while(1){
				system("cls");
				lay.display_box();
				gotoxy(5,2);
				cout<<"AUTHORIZED USER->Update Movies List";
				lay.box_star(70,14);
				gotoxy(74,15);
				cout<<"<<<AUTHORITY MOVIE MENU>>>";
				lay.box_get_options(6);
				gotoxy(75,21);
				cout<<"1.Display Movies"<<endl;
				gotoxy(75,24);
				cout<<"2.Add a Movie"<<endl;
				gotoxy(75,27);
				cout<<"3.Modify a Movie"<<endl;
				gotoxy(75,30);
				cout<<"4.View A Movie Details"<<endl;
				gotoxy(75,33);
				cout<<"5.Remove a Movie"<<endl;
				gotoxy(75,36);
				cout<<"6.Go Back"<<endl;
				lay.chota_starbox(80,40);
				gotoxy(81,41);
				fflush(stdin);
				cin.getline(update_choice,50);
				choice_update_movies=atoi(update_choice);
				switch(choice_update_movies){
					case 1:
					system("cls");
					gotoxy(5,2);
					cout<<"AUTHORIZED USER->Update Movies List->Display Movies";
					person::view_movies();
					getch();
				    break;
					case 2:
						system("cls");
						lay.display_box();
						gotoxy(5,2);
					    cout<<"AUTHORIZED USER->Update Movies List->Add A Movie";
						if(count_movies(c.mov_file) <5){
							write_movie(c.mov_file);
							getch();
						}
						else{
							gotoxy(70,20);
							cout<<"Sorry!Maximum movies limit is 5... You are out of range"<<endl;
							getch();
						}
						break;
					case 3:
						system("cls");
						lay.display_box();
						gotoxy(5,2);
						cout<<"AUTHORIZED USER->Update Movies List->Modify A Movie";
						person::view_movies();
						modify_movie(c.show_file,c.mov_file);
						getch();
						break;
					case 4:
						system("cls");
						gotoxy(5,2);
						cout<<"AUTHORIZED USER->Update Movies List->View A Movie Info";
						person::info_movie();
						break;
					case 5:
						system("cls");
						lay.display_box();
						gotoxy(5,2);
						cout<<"AUTHORIZED USER->Update Movies List->Delete A Movie";
						person::view_movies();
						delete_movie(c.show_file,c.mov_file);
						system("cls");
						gotoxy(5,2);
						cout<<"AUTHORIZED USER->Update Movies List->Delete A Movie";
						person::view_movies();
						getch();
						break;
					case 6:
						return 0;
					default:
						break;
				}
			}
		}
		int authority_display(){
			int check_count,select_day;
			char day_select[50],scd_choice[50],user_choice[50];
			char ans;
			char sec_code[20],qs[20];
			system("cls");
			if(login()){
				while(1){
				system("cls");
				lay.display_box();
				lay.box_star(70,14);
				gotoxy(75,15);
				cout<<"!!!AUTHORIZED USER DISPLAY!!!";
				lay.box_get_options(5);
				gotoxy(75,21);
				cout<<"1.Create Schedule"<<endl;
				gotoxy(75,24);
				cout<<"2.Display Schedule"<<endl;
				gotoxy(75,27);
				cout<<"3.Update Movies List"<<endl;
				gotoxy(75,30);
				cout<<"4.Update Schedule"<<endl;
				gotoxy(75,33);
				cout<<"5.Log out"<<endl;
				gotoxy(108,25);
				cout<<"Enter Your Choice:";
				lay.chota_starbox(127,24);
				gotoxy(128,25);
				fflush(stdin);
				cin.getline(user_choice,50);
				choice_user=atoi(user_choice);
				switch(choice_user){
				case 1:
					check_count=scd.check_schedule(c.show_file);
					if(check_count >= 7){
						system("cls");
						lay.display_box();
						gotoxy(5,2);
						cout<<"AUTHORIZED USER->Create Schedule";
						gotoxy(65,17);
						cout<<"Schedule has been already created with "<<check_count<<" days shows"<<endl;
					}
					else{
						scd.create_schedule(c.show_file,c.seats_file);
						system("cls");
						lay.display_box();
						gotoxy(65,17);
						cout<<"Schedule created for cinema for "<<scd.check_schedule(c.show_file)<<" days"<<endl;
					}
					gotoxy(60,20);
					cout<<"Press d to Destroy Schedule otherwise press spacebar: ";
					gotoxy(60,21);
					ans=getche();
					if(ans == 'd' || ans == 'D'){
						system("cls");
						lay.display_box();
						gotoxy(5,2);
						cout<<"AUTHORIZED USER->Create Schedule->Destroying Schedule";
						gotoxy(75,20);
						cout<<"Enter the secret pin code: ";
						gotoxy(105,20);
						fflush(stdin);
						cin.getline(sec_code,20);
						if(strcmp(sec_code,c.secret_code)== 0){
							gotoxy(72,22);
							cout<<"Why deleting schedule(Give one Word right answer): "<<endl;
							gotoxy(122,22);
							fflush(stdin);
							cin.getline(qs,20);
							if(strcmp(qs,c.secret_qs) == 0){
								scd.destroy_schedule(c.show_file,c.seats_file);
								gotoxy(75,25);
								cout<<"Schedule destroyed"<<endl;
								delay(2000);
							}
							else{
								gotoxy(75,25);
								cout<<"Wrong returning in 2 seconds"<<endl;
								delay(2000);
							}
						}
					}
					break;
				case 2:
					while(1){
					system("cls");
					lay.display_box();
					gotoxy(5,2);
					cout<<"AUTHORIZED USER->Display Schedule";
					gotoxy(20,7);
					c.show_price();
					c.shows();
					gotoxy(45,10);
					cout<<"Press 0 to go back OR Select the Day to check show bookings:";
					gotoxy(105,10);
					fflush(stdin);
					cin.getline(day_select,50);
					select_day=atoi(day_select);
					if(select_day == 0){
						if(strcmp(day_select,"0") != 0){
							gotoxy(65,11);
						cout<<"Invalid choice"<<endl;
						getch();
						}
						else{
						gotoxy(65,11);
						cout<<"Returning in a second"<<endl;
						delay(1000);
						break;
					}
					}
					if(select_day >7){
						gotoxy(65,11);
						cout<<"Invalid choice"<<endl;
						getch();
					}
					else{
						system("cls");
						gotoxy(5,2);
						cout<<"AUTHORIZED USER-> Display Schedule->DAY "<<select_day<<" Shows";
					c.show_bookings(select_day);
				}
			}
					break;
				case 3:
					update_movies();
					break;
				case 4:
					while(1){
					system("cls");
					lay.display_box();
					gotoxy(5,2);
					cout<<"AUTHORIZED USER->Update Schedule";
					c.shows();
					gotoxy(45,10);
					cout<<"Press the number for Day at which Schedule is to be changed: ";
					fflush(stdin);
					cin.getline(scd_choice,50);
					choice_scd=atoi(scd_choice);
					if(choice_scd == 0){
						break;
					}
					else if(choice_scd > scd.check_schedule(c.show_file)){
						gotoxy(55,11);
						cout<<"Invalid choice"<<endl;
						getch();
					}
					else{
						c.shows_update(choice_scd);
					}
				}
					break;
				case 5:
					 main_menu();
				default:
					break;
			}
		}
	}
	}//end of function
};

void main_menu(){
	char choice[50],again;
	customer cs;
	authorized_user at;
	int ch;
	while(1){
		system("cls");
	t();
	lay.intro_design();
	gotoxy(75,21);
	cout<<"1. USER DISPLAY";
	gotoxy(75,24);
	cout<<"2.LOGIN AS AUTHORIZED USER";
	gotoxy(75,27);
	cout<<"3.EXIT";
	gotoxy(84,32);
	fflush(stdin);
	cin.getline(choice,50);
	ch=atoi(choice);
	switch(ch){
		case 1:
			cs.choose();
			break;
		case 2:
			at.authority_display();
			break;
		case 3:
			lay.exiting();
			intr.thanks();
			exit(1);
		default:
			gotoxy(80,35);
			cout<<"Invalid choice";
			delay(1000);
	}
}
}
int main(){
	HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd,SW_SHOWMAXIMIZED);
    system("color 1F");
	intr.intro();
	delay(1500);
	system("cls");
	intr.title_page();
	getch();
	system("cls");
	main_menu();
}
