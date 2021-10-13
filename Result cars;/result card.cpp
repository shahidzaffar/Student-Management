//_________________________________________________________
//---------------------------------------------------------
			//Header Files
//---------------------------------------------------------
//_________________________________________________________
#include<iostream> 
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

#define SIZE 50 //  for max number of students in the class.
#define SUB 6//   for max number of subjects\

//_________________________________________________________
//---------------------------------------------------------
//					Function Decleration
//---------------------------------------------------------
//_________________________________________________________

struct student
{
	string nameofsub;
	int regNo;
	int marks[SUB];
	int mobt;
	string name;
	char grad;
	float perc;
	int totalMarks;
};
//_________________________________________________________
//---------------------------------------------------------
//		prototyes of user Defined Function
//---------------------------------------------------------
//_________________________________________________________


void display1();//1:
void display2();//3:
void inputfun(student [], int, int);
void resultPrep(student [], int, int);
int search(student [], int, int);
void insertion(student[], int&, int&);
void update(student [], int, int);
void deletion(student[], int &, int, int);
void mysort(student[], int, int);
void save2file(student[], int, int);
//_____________________________________________________________________________//_____________________________________________________________________________
void displaySearched(student[], int&, int&, int);
void displayFun(student [], int, int);





//_________________________________________________________
//---------------------------------------------------------
//					Let's Started
//---------------------------------------------------------
//_________________________________________________________

int main()
{
	student s[SIZE];
	cout << showpoint << fixed << setprecision(2);
	int noOfStd;//For number of students.
	int noOfSub;//for number of students.
	int n;
	int p;
	int counter = 1;// For controling the menu.
	int num;

	while (true)//For repitition of the whole process
	{

		if (counter == 1)
		{
			display1();

			cout << "Enter your Choice \n";
			cin >> n;// taking choice of the user
			system("cls");

			if (n == 0)//performing operation on the choice.
				break;
			else if (n == 1)
			{

				cout << "\nEnter number of students in the class\t : ";
				cin >> noOfStd;
				while ((noOfStd < 0) || (noOfStd > SIZE))
				{
					cout << "Invalid ! " << "Number should be between 0 and " << SIZE << " Enter Again\n\n";
					cin >> noOfStd;
				}
				cout << endl;
				cout << "\nEnter number of subjects the students are Attending\t: ";
				cin >> noOfSub;
				while ((noOfSub < 0) || (noOfSub > SUB))
				{
					cout << "Invalid ! " << "Number should be between 0 and " << SUB << " Enter Again\n\n";
					cin >> noOfSub;
				}
				cout << endl << endl;
				inputfun(s, noOfStd, noOfSub);
				resultPrep(s, noOfStd, noOfSub);
				counter++;


			}
			else
				cout << "Invalid choice!\n";
		}
		else
		{
			system("cls");
			display2();
			cout << "Enter your choice\t: ";
			cin >> n;
			cout << endl << endl << endl;
			switch (n)
			{
			case 1:
				cout << "\n\nEnter number of students in the class\t: ";
				cin >> noOfStd;
				while ((noOfStd < 0) || (noOfStd > SIZE))
				{
					cout << "Invalid ! " << "Number should be between 0 and " << SIZE << " Enter Again\n\n";
					cin >> noOfStd;
				}
				cout << "\n\nEnter number of subjects the students are Attending\t : ";
				cin >> noOfSub;
				while ((noOfSub < 0) || (noOfSub > SIZE))
				{
					cout << "Invalid ! " << "Number should be between 0 and " << SUB << " Enter Again\n\n";
					cin >> noOfSub;
				}
				inputfun(s, noOfStd, noOfSub);
				resultPrep(s, noOfStd, noOfSub);
				break;
			case 2:
				if (noOfStd == SIZE)
					cout << "Insertion is not Possible\n";
				else
					insertion(s, noOfStd, noOfSub);
				break;
			case 3:
				cout << "Enter the Reg.No of Student for searching :  ";
				cin >> num;
				cout << endl << endl << endl;
				p = search(s, noOfStd, num);
				if (p == -1)
					cout << "The Student in not found in the list\n";
				else
					displaySearched(s, noOfStd, noOfSub, p);
				break;
			case 4:
				update(s, noOfStd, noOfSub);
				break;
			case 5:

				cout << "\n\n\n\n \t\t\tDeletion Precess\n\n";
				cout << "Enter Reg.No of student to be deleted\n";
				cin >> num;
				p = search(s, noOfStd, num);
				if (p == -1)
					cout << "Number is not present in the Array, So Deletion not possible\n";
				else
					deletion(s, noOfStd, noOfSub, p);
				break;
			case 6:
				resultPrep(s, noOfStd, noOfSub);
				break;
			case 7:

				cout << "\n\n\t\t WE WILL SORT IN DESENDING ORDER W.R.T Total Marks Obtained\n\n";
				mysort(s, noOfStd, noOfSub);
				cout << "\n After Sorting\n\n";
				displayFun(s, noOfStd, noOfSub);
				break;
			case 8:

				cout << "\n\n\n\t\t\t\t OverAll Report\n\n";
				displayFun(s, noOfStd, noOfSub);
				cout << endl;
				break;
			case 9:
				save2file(s, noOfStd, noOfSub);
				system("pause");
				break;
		
			case 10:
				system("pause");
				exit(1);
				break;

			default:
			{
				cout << "Invalid Choice ! \t. try Again\n";
				cin >> n;
				break;
			}

			}
			

		}
		
		system("pause");
	}
	system("pause");
	return 0;
}
//_________________________________________________________
//---------------------------------------------------------
//					Displaying menu 1
//---------------------------------------------------------
//_________________________________________________________

 void display1()
{
	cout << "\n\n\t\t\t MENU\n";
	cout << "___________________" << endl;
	cout << "___________________" << endl;
	cout << "0:EXIT\n1:Create DataBase" << endl;
	cout << "___________________" << endl;
	cout << "___________________\n" << endl;
}
 //_________________________________________________________
 //---------------------------------------------------------
 //					Displaying menu 2
 //---------------------------------------------------------
 //_________________________________________________________

void display2()
{

	cout << "\n\n\n\n \t\t\t Main Menu\n\n";
	cout << "____________________________________\n";
	cout << "____________________________________\n";
	cout << " 1: Create DataBase " << endl;
	cout << "____________________________________\n";
	cout << "2: Append New record\n";
	cout << "____________________________________\n";
	cout << "3: Search\n";
	cout << "____________________________________\n";
	cout << "4: Update\n";
	cout << "____________________________________\n";
	cout << "5: Delete      \n";
	cout << "_____________________________________\n";
	cout << "6: Prepare Result\n";
	cout << "____________________________________\n";
	cout << "7: Sort\n";
	cout << "____________________________________\n";
	cout << "8: Report\n";
	cout << "____________________________________\n";
	cout<< "9: SAVE TO FILE\n";
	cout << "____________________________________\n";
	cout << "10: EXIT\n";
	cout << "____________________________________\n";
	cout << "____________________________________\n";


}//________________________________________________________
//---------------------------------------------------------
//				Reading Data from User
//---------------------------------------------------------
//_________________________________________________________

void inputfun(student ss[], int nn, int mm)
{

	for (int k = 0; k < mm; k++)
	{
		cin.ignore(1, '\n');
		cout << "Enter name of subject no " << k + 1 << " : ";
		getline(cin, ss[k].nameofsub);
		cout << endl;
	}
	cout << "______________________________________________________________________________\n";
	cout << "______________________________________________________________________________\n";

	for (int i = 0; i < nn; i++)
	{
		cout << endl;
		cout << "Enter reg no for student no " << i + 1 << "\t : ";
		cin >> ss[i].regNo;
		cout << endl << endl;
		for (int j = i; j >= 0; j--)
			if (ss[i].regNo == ss[j - 1].regNo)
			{
				cout << "Reg no Must be Unique ... Enter Again! : ";
				cin >> ss[i].regNo;
			}


		cout << "Enter name of student having reg no  " << ss[i].regNo << "  : ";
		cin.ignore();
		getline(cin, ss[i].name);
		cout << endl;

		for (int j = 0; j < mm; j++)
		{
			cout << "Enter marks of  " << ss[i].name << " in the  " << ss[j].nameofsub << "\t : ";
			cin >> ss[i].marks[j];
			cout << endl;
			while ((ss[i].marks[j] < 0) || (ss[i].marks[j] > 100))
			{

				cout << "Marks must be in range 0-100 ! try Again : ";
				cin >> ss[i].marks[j];
				cout << endl;
			}
		}
		system("cls");
	}
}
//_________________________________________________________
//---------------------------------------------------------
//					Displaying All Result
//---------------------------------------------------------
//_________________________________________________________


void displayFun(student ss[], int nn, int mm)
{
	cout << right;
	cout << "       \t\t DISPLAYING RESULT\n\n";
	cout << "Sr.No" << setw(10) << "Reg.No" << setw(17) << "Name";
	for (int i = 0; i < mm; i++)
		cout << setw(15) << ss[i].nameofsub[i];
	cout << setw(17) << "M.Obt" << setw(22) << "T.Marks" << setw(20) << "%age" << setw(12) << "  Grade\n" << endl;
	cout << "_______________________________________________________________________________________________________________________________________________" << endl;
	for (int i = 0; i < nn; i++)
	{
		cout << right;
		cout << i + 1 << setw(12);
		cout << ss[i].regNo << setw(19) << ss[i].name;
		for (int j = 0; j < mm; j++)
			cout << setw(15) << ss[i].marks[j];//Geting marks;
		cout << setw(17) << ss[i].mobt << setw(22);
		cout << ss[i].totalMarks << setw(20) << ss[i].perc << "%" << setw(12);
		cout << ss[i].grad;

		cout << endl << endl;
		cout << "_________________________________________________________________________________________________________________________________________\n";
	}
}
//_________________________________________________________
//---------------------------------------------------------
//					Preparation Result
//---------------------------------------------------------
//_________________________________________________________


void resultPrep(student ss[], int nn, int mm)
{
	
	for (int i = 0; i < nn; i++)//for computiong the Total marks obtained by a student.
	{
		ss[i].mobt = { 0 };
		for (int j = 0; j < mm; j++)
			ss[i].mobt += ss[i].marks[j];
	}
	for (int i = 0; i < nn; i++)
	{
		ss[i].totalMarks = 100 * mm;
		
		ss[i].perc = (ss[i].mobt + 0.0) / (ss[i].totalMarks + 0.0) * 100;//For percentage
														   //Computing the grade			
			if (ss[i].perc >= 90)
				ss[i].grad = 'A';
			else if ((ss[i].perc >= 80) && (ss[i].perc <= 90))
				ss[i].grad = 'B';
			else if ((ss[i].perc >= 70) && (ss[i].perc <= 80))
				ss[i].grad = 'C';
			else if ((ss[i].perc >= 60) && (ss[i].perc <= 70))
				ss[i].grad = 'D';
			else
				ss[i].grad = 'F';
	}
}
//_________________________________________________________
//---------------------------------------------------------
//					Inserting a new Record
//---------------------------------------------------------
//_________________________________________________________


void insertion(student ss[], int& nn, int& mm)
{
	if (nn == SIZE)
		cout << "Insertion is not Possible\n";
	else
	{
		cout << "Enter the reg no of student : ";
		cin >> ss[nn].regNo;

		for (int i = 0; i < nn; i++)
			for (int j = i; j >= 0; j--)
				if (ss[nn].regNo == ss[j - 1].regNo)
				{
					cout << "Reg no Must be Unique ... Enter Again! : ";
					cin >> ss[nn].regNo;
				}
		ss[nn].mobt = 0;
		cout << "ENter name of the Student\t : ";
		getline(cin, ss[nn].name);
		cin.ignore('\n');
		for (int j = 0; j < mm; j++)
		{
			cout << "ENter marks of new students for  " << ss[nn].nameofsub[j] << " : ";
			cin >> ss[nn].marks[j];
			ss[nn].mobt += ss[nn].marks[j];
		}
		ss[nn].perc = (ss[nn].mobt + 0.0) / (ss[nn].totalMarks + 0.0) * 100;
		if (ss[nn].perc >= 90)
			ss[nn].grad = 'A';
		else if ((ss[nn].perc >= 80) && (ss[nn].perc <= 90))
			ss[nn].grad = 'B';
		else if ((ss[nn].perc >= 70) && (ss[nn].perc <= 80))
			ss[nn].grad = 'C';
		else if ((ss[nn].perc >= 60) && (ss[nn].perc <= 70))
			ss[nn].grad = 'D';
		else
			ss[nn].grad = 'F';
		nn++;
	}
}
//_________________________________________________________
//---------------------------------------------------------
//					searching a certain Data
//---------------------------------------------------------
//_________________________________________________________

int search(student ss[], int nn, int number)
{
	int p = -1;
	for (int i = 0; i<nn; i++)
		if (number == ss[i].regNo)
		{
			p = i;
			break;
		}
	return p;
}
//_________________________________________________________
//---------------------------------------------------------
//					Displaying searched data
//---------------------------------------------------------
//_________________________________________________________

void displaySearched(student ss[], int& nn, int& mm, int p)
{
	cout << right;
	cout << "       \t\t DISPLAYING SEARCHED DATA\n\n";
	cout << "Reg.No" << setw(15) << "Name ";
	for (int i = 0; i < mm; i++)
		cout << setw(15) << ss[i].nameofsub[i];
	cout << setw(10) << "M.Obt" << setw(15) << "T.Marks" << setw(10) << "%age" << setw(15) << "Grade\t\t\n" << endl;
	cout << "___________________________________________________________________________________________________________________" << endl;
	cout << ss[p].regNo << setw(15) << ss[p].name;
	for (int i = 0; i < mm; i++)
		cout << setw(15) << ss[p].marks[i];
	cout << setw(11) << ss[p].mobt << setw(15) << 100 * mm << setw(12) << ss[p].perc << setw(15) << ss[p].grad << endl;
	cout << "___________________________________________________________________________________________________________________" << endl;
}
//_________________________________________________________
//---------------------------------------------------------
//					Updating Record
//---------------------------------------------------------
//_________________________________________________________

void update(student ss[], int nn, int mm)
{
	int num; //For gatting the Data for 
	cout << "Enter the reg.No whose Data Is to be Updated : ";
	cin >> num;
	int p = search(ss, nn, num);
	if (p == -1)
		cout << "The Student in not found in the list\n";
	else
	{
		ss[p].mobt = 0;
		for (int i = 0; i < mm; i++)
		{
			cout << "Enter New Marks in  " << ss[i].nameofsub[i] << " : ";
			cin >> ss[p].marks[i];
			while ((ss[p].marks[i] < 0) || (ss[p].marks[i] > 100))
			{
				cout << "Invalid Entry ! Marks must be from 0-100\n Enter Again : ";
				cin >> ss[p].marks[i];
			}
			ss[p].mobt += ss[p].marks[i];
		}
		ss[p].perc = (ss[p].mobt + 0.0) / (mm * 100 + 0.0) * 100;
		if (ss[p].perc >= 90)
			ss[p].grad = 'A';
		else if ((ss[p].perc >= 80) && (ss[p].perc <= 90))
			ss[p].grad = 'B';
		else if ((ss[p].perc >= 70) && (ss[p].perc <= 80))
			ss[p].grad = 'C';
		else if ((ss[p].perc >= 60) && (ss[p].perc <= 70))
			ss[p].grad = 'D';
		else
			ss[p].grad = 'F';
	}
}
//_________________________________________________________
//---------------------------------------------------------
//					Deleting record
//---------------------------------------------------------
//_________________________________________________________

void deletion(student ss[], int & nn, int mm, int p)
{
	for (int i = p; i < nn; i++)
		ss[i] = ss[i + 1];
	nn--;
}
//_________________________________________________________
//---------------------------------------------------------
//		Sorting the record in Desending order
//---------------------------------------------------------
//_________________________________________________________

void mysort(student ss[], int nn, int mm)
{
	int noofpass = nn - 1;
	for (int i = 0; i < noofpass; i++)
	{
		for (int j = i; j < nn; j++)
		{
			if (ss[i].mobt < ss[j].mobt)
				swap(ss[i], ss[j]);
		}
	}
}
//_________________________________________________________
//---------------------------------------------------------
//					Save 2 File
//---------------------------------------------------------
//_________________________________________________________

void save2file(student ss[], int nn, int mm)
{
	ofstream outfile("DATA.txt");
	outfile << right;
	outfile << "       \t\t DISPLAYING RESULT\n\n";
	outfile << "Sr.No" << setw(10) << "Reg.No" << setw(17) << "Name";
	for (int i = 0; i < mm; i++)
		outfile << setw(15) << ss[i].nameofsub[i];
	outfile << setw(17) << "M.Obt" << setw(22) << "T.Marks" << setw(20) << "%age" << setw(12) << "  Grade\n" << endl;
	outfile << "_______________________________________________________________________________________________________________________________________________" << endl;
	for (int i = 0; i < nn; i++)
	{
		outfile << right;
		outfile << i + 1 << setw(12);
		outfile << ss[i].regNo << setw(19) << ss[i].name;
		for (int j = 0; j < mm; j++)
			outfile << setw(15) << ss[i].marks[j];//Geting marks;
		outfile << setw(17) << ss[i].mobt << setw(22);
		outfile << ss[i].totalMarks << setw(20) << ss[i].perc << "%" << setw(12);
		outfile << ss[i].grad;

		outfile << endl << endl;
		outfile << "_________________________________________________________________________________________________________________________________________\n";
	}
}
//______________________________________________________________________________________________
//----------------------------------------------------------------------------------------------
//					The End 
//----------------------------------------------------------------------------------------------
//______________________________________________________________________________________________
