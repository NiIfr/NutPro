#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

//MainClass
class Nuts
{
	private:
		string Name;
		string Family;
		long int Code;
		long int Father_code;
		long int Mother_code;
		int Age;
		int NumOfChild;
		long int Stock;
		bool Alive;

	public:
		//set and get
		void setName(string name) { Name = name; }
		string getName() { return Name; }

		void setFamily(string family) { Family = family; }
		string getFamily() { return Family; }

		void setCode(long int code) { Code = code; }
		long int getCode() { return Code; }

		void setFather_code(long int Fcode) { Father_code = Fcode; }
		long int getFather_code() { return Father_code; }

		void setMother_code(long int Mcode) { Mother_code = Mcode; }
		long int getMother_code() { return Mother_code; }

		void setAge( int age) { Age = age; }
		int getAge() { return Age; }

		void setNumOfChild(int num) { NumOfChild = num; }
		int getNumOfChild() { return NumOfChild; }

		void setStock(long int stock) { Stock = stock; }
		long int getStock() { return Stock; }

		void setAlive(bool alive) { Alive = alive; }
		bool getAlive() { return Alive; }
};


//Child classes
	class BabyNut : public Nuts
	{
		private:
			long int salery;
			int age;
		public:
			
	};


	class MiddleNut : public Nuts
	{
		private:
			long int salery;
			int age;

		public:
			
	};


	class TowerNut : public Nuts
	{
		private:
			double x, y;

		public:
			void setx(double X) { x = X; }
			double getx() { return x; }

			void sety(double Y) { Y = x; }
			double gety() { return y; }
	};



	string numberToString(int num)
	{
		ostringstream os;
		os << num;
		return os.str();
	}

	int stringToInteger(string str)
	{
		int result;
		istringstream convert(str);
		if (!(convert >> result))
			throw "Can not convert";

		return result;
	}

void Addnut()
{

	// the variations
	Nuts nut;
	string n, f;
	long int mc, fc;
	int age, numofchild;


	//For random Div_code
	long int max = 99999;
	long int min = 10000;
	srand(time(0));


	////// check the number of nut  -The first nut-
	ifstream main("main.txt");
	int num;
	long int rnd;
	main >> num;

		if (num == 0 || num==1)
		{
			//num 0
			if (num == 0)
			{
				// name - family
				system("cls");
				cout << "Adding new nut\n";
				cout << "Please Enter the name:  ";
				cin >> n;
				cout << "\nPlease Enter the family:  ";
				cin >> f;

				nut.setName(n);
				nut.setFamily(f);
				// code - mother - father
				nut.setCode((rand() % (max - min)) + min);
				nut.setMother_code(0);
				nut.setFather_code(0);

				//children
				system("cls");
				cout << "Adding new nut\n";
				cout << "Please Enter the number of children: ";
				cin >> numofchild;
				nut.setNumOfChild(numofchild);

				//age - alive
				system("cls");
				cout << "Adding new nut\n";
				cout << "Please Enter the age between 1 to 16:  ";
				cin >> age;
					while (!(age >= 1 && age <= 16))
					{
						cout << "The age is out of range!!! ENter again\n";
						cout << "Please Enter the age between 1 to 16:  ";
						cin >> age;
					}
				nut.setAge(age);
				nut.setAlive(true);
				nut.setStock(0);

				// add to file
				string filename1 = numberToString(num) + ".txt";
				ofstream nuts(filename1);

				nuts << nut.getName()<<endl;
				nuts << nut.getFamily() << endl;
				nuts << nut.getCode() << endl;
				nuts << nut.getMother_code() << endl;
				nuts << nut.getFather_code() << endl;
				nuts << nut.getNumOfChild() << endl;
				nuts << nut.getAge() << endl;
				nuts << nut.getStock() << endl;
				nuts << nut.getAlive() << endl;
			}

			/// num =1
			else
			{
				// name - family and check
				string filename2 = numberToString(num-1) + ".txt";
				ifstream CKnut(filename2);
				string ckname, ckfamily;
				long int ckrnd;
				CKnut >> ckname;
				CKnut >> ckfamily;

				system("cls");
				cout << "Adding new nut\n";
				cout << "Please Enter the name:  ";
				cin >> n;
				cout << "\nPlease Enter the family:  ";
				cin >> f;
				
					while (n == ckname || f == ckfamily)
					{
						cout << "The name is exist!!! Try again\n";
						cout << "Please Enter the name:  ";
						cin >> n;
						cout << "\nPlease Enter the family:  ";
						cin >> f;
					}
				nut.setName(n);
				nut.setFamily(f);

				//check code - mother - father
				CKnut >> ckrnd;
				rnd = (rand() % (max - min)) + min;

					while (rnd == ckrnd)
						rnd = (rand() % (max - min)) + min;
				nut.setCode(rnd);				

				nut.setMother_code(0);
				nut.setFather_code(0);

				//children
				system("cls");
				cout << "Adding new nut\n";
				cout << "Please Enter the number of children:  DIV_";
				cin >> numofchild;
				nut.setNumOfChild(numofchild);

				//age - alive
				system("cls");
				cout << "Adding new nut\n";
				cout << "Please Enter the age between 1 to 16:  ";
				cin >> age;
					while (!(age >= 1 && age <= 16))
					{
						cout << "The age is out of range!!! ENter again\n";
						cout << "Please Enter the age between 1 to 16:  ";
						cin >> age;
					}
				nut.setAge(age);
				nut.setStock(0);
				nut.setAlive(true);

				///add to file
				string filename3 = numberToString(num) + ".txt";
				ofstream nuts(filename3);

				nuts << nut.getName() << endl;
				nuts << nut.getFamily() << endl;
				nuts << nut.getCode() << endl;
				nuts << nut.getMother_code() << endl;
				nuts << nut.getFather_code() << endl;
				nuts << nut.getNumOfChild() << endl;
				nuts << nut.getAge() << endl;
				nuts << nut.getStock() << endl;
				nuts << nut.getAlive() << endl;
			}

				//num++ new nuts added
				num++;
				ofstream mainf;
				mainf.open("main.txt", ios::trunc);
				mainf << num<<endl;
				cout << "A new nut added";
		}
		else
		{
		
	//add and search the name and family and set code by rand number
		system("cls");
		cout << "Adding new nut\n";
		cout << "Please Enter the name:  ";
		cin >> n;
		cout << "\nPlease Enter the family:  ";
		cin >> f;

			for (int i = 0; i < num; i++)
			{
				string FN = numberToString(i) + ".txt";
				ifstream CKnut(FN);
				string ckname, ckfamily;
				long int ckrnd;
				CKnut >> ckname;
				CKnut >> ckfamily;

					if (n == ckname && f == ckfamily)
					{
						cout << "The name is exist!!! Try again\n";
						cout << "Please Enter the name:  ";
						cin >> n;
						cout << "\nPlease Enter the family:  ";
						cin >> f;
						i = 0;
					}
			}

		nut.setName(n);
		nut.setFamily(f);

	//check code
		for (int i = 0; i < num; i++)
		{
			string FN = numberToString(i) + ".txt";
			ifstream CKnut(FN);
			long int ckrnd;
			CKnut >> ckrnd;
			rnd = (rand() % (max - min)) + min;
				if (rnd == ckrnd)
				{
					rnd = (rand() % (max - min)) + min;
					CKnut.close();
					break;
				}
		}
		nut.setCode(rnd);

	////////add mother
		system("cls");
		cout << "Adding new nut\n";
		cout << "Please Enter mother's code:  DIV_";
		cin >> mc;
		bool flag=false;
		
		while (flag == false)
		{
			for (int i = 0; i < num; i++)
			{
				string FNC = numberToString(i) + ".txt";
				ifstream CKcnut(FNC);
				long ckcode;
				string tempname, tempfamily;
				CKcnut >> tempname;
				CKcnut >> tempfamily;
				CKcnut >> ckcode;

				if (mc == ckcode)
				{
					nut.setMother_code(mc)  ;
					flag = true;
					CKcnut.close();
					break;
				}
			}
			if (flag == true)
				break;
			
			system("cls");
			cout << "The Mother_code not found! Try again\n";
			cout << "Please Enter mother's code:  DIV_";
			cin >> mc;
			}
		


	/////////add father
		system("cls");
		cout << "Adding new nut\n";
		cout << "Please Enter father's code:  DIV_";
		cin >> fc;
		flag=false;

			while (flag ==false)
			{
				for (int i = 0; i < num; i++)
				{
					string FN = numberToString(i) + ".txt";
					ifstream CKcnut(FN);
					long ckcode;
					string tempname, tempfamily;
					CKcnut >> tempname;
					CKcnut >> tempfamily;
					CKcnut >> ckcode;

					if (fc == ckcode && fc!= nut.getMother_code())
					{
						nut.setFather_code(fc) ;
						flag = true;
						CKcnut.close();
						break;
					}
					
				}
				if (flag == true)
					break;
				system("cls");
				cout << "The father_code not found! Try again\n";
				cout << "Please Enter Father's Code:  DIV_";
				cin >> fc;
			}
		

	///////////child
		system("cls");
		cout << "Adding new nut\n";
		cout << "Please Enter the number of children:";
		cin >> numofchild;
		nut.setNumOfChild(numofchild);

	///////// add age
		system("cls");
		cout << "Adding new nut\n";
		cout << "Please Enter the age between 1 to 16:  ";
		cin >> age;
			while (!(age >= 1 && age <= 16))
			{
				cout << "The age is out of range!!! Enter again\n";
				cout << "Please Enter the age between 1 to 16:  ";
				cin >> age;
			}
			nut.setAge(age);
			nut.setStock(0);
			nut.setAlive(true);

	//// add to file
			string Fn = numberToString(num) + ".txt";
			ofstream nuts(Fn);

			nuts << nut.getName() << endl;
			nuts << nut.getFamily() << endl;
			nuts << nut.getCode() << endl;
			nuts << nut.getMother_code() << endl;
			nuts << nut.getFather_code() << endl;
			nuts << nut.getNumOfChild() << endl;
			nuts << nut.getAge() << endl;
			nuts << nut.getStock() << endl;
			nuts << nut.getAlive() << endl;

			// num++ number of nuts
			num++;
			ofstream mainf;
			mainf.open("main.txt", ios::trunc);
			mainf << num << endl;
			system("cls");
			cout << "A new nut added";
		}
		}


	void posiblity()
	{
		// number of nuts
		ifstream main("main.txt");
		int num;
		main >> num;

		long mcode, fcode;
		Nuts nut;
		long code;
		system("cls");
		cout << "Enter the code: DIV_";
		cin >> code;

		bool flag = false;
		bool Hchild =false;
			while (flag == false)
			{
				for (int i = 0; i < num; i++)
				{
					string FNC = numberToString(i) + ".txt";
					ifstream CKcnut(FNC);
					long ckcode;
					string tempname, tempfamily;
					CKcnut >> tempname;
					CKcnut >> tempfamily;
					CKcnut >> ckcode;
					CKcnut >> mcode;
					CKcnut >> fcode;

					if (code == fcode || code== mcode)
					{
						flag = true;
						CKcnut.close();
						break;
					}
				}
				if (flag == true)
				{
					for (int i = 0; i < num; i++)
					{
						string FNC = numberToString(i) + ".txt";
						ifstream CKcnut(FNC);
						long ckcode, stock,fc,mc;
						int noc; // number of child
						int age;
						bool alive;
						string tempname, tempfamily;
						CKcnut >> tempname;
						CKcnut >> tempfamily;
						CKcnut >> ckcode;
						CKcnut >> mc;
						CKcnut >> fc;
						CKcnut >> noc;
						CKcnut >> age;
						CKcnut >> stock;
						CKcnut >> alive;


						if (mcode == ckcode || fcode == ckcode)
						{
							if (alive != false)
							{
								cout << "You can have a child sucsesfully !";
								Hchild = true;
								//addnewchild();
								break;
							}

							else
							{
								cout << "your partner was died. you can not have a child. ";
								Hchild = true;
								break;
							}

						}

					}

				}
				if (Hchild != false)
					break;
				system("cls");
				cout << "The code not found! Try again\n";
				cout << "Please Enter mother's code:  DIV_";
				cin >> code;
			}




	}

	void addnewchild()
	{
	
	
	}



	int main()

	{
		int n;
		int num = NULL;
		ifstream main_I("main.txt");
		long int rnd;
		main_I >> num;

		if (num == NULL)
		{
		int zero = 0;
		ofstream main("main.txt");
		main << zero << endl;
		}

	//Menu
	cout << "* Wellcome to MANAGE OF NUTS Pro * \n";

	cout << "\n1- Add new nut \n";
	cout << "2- Check the possibility of childbearing \n";
	cout << "3- Check the account of Government \n";
	cout << "4- Forecast daily Report \n";
	cout << "5- Exit \n";
	cout << "\nEnter your desired number:  ";

	cin >> n;
	if (n >= 1 && n <= 5)
	{

		switch (n)
		{

		case 1:
		{
			Addnut();

		}
		case 2:
			posiblity();
		case 3:

		case 4:

		case 5:
			break;

		default:
			break;
		}

	}
	else
		cout << "The number that you entered was wrong!!!  Try again \n";

	return 0;
}



