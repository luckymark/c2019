#include <bits/stdc++.h>
#include <Windows.h>
using namespace std;

const int nameMaxLength = 20;
const char fileName[] = "warehouse.txt";

struct ProductStruct {
	char name[nameMaxLength];
	int stock;
};

list<ProductStruct> productInfo;

ostream& operator << (ostream& out, list<ProductStruct>& product)
{
	for (list<ProductStruct>::iterator iter = product.begin(); iter != product.end(); iter++)
	{
		out << iter->stock << " " << iter->name << endl;
	}
	return out;
}

int inputNum() //get a positive integer
{
	char str[nameMaxLength];
	cin.getline(str, nameMaxLength);
	if (!isdigit(str[0])) //input is not a number
		return -1;
	return atoi(str);
}

int stockIn()
{
	cout << "Please input the product index you want to stock in, or input 0 to input new product:";
	int i = inputNum();
	if (i == -1)
	{
		cout << "Wrong input.\n";
		system("pause");
		return 0;
	}
	if (i > productInfo.size())
	{
		cout << "Input number too big.\n";
		system("pause");
		return 0;
	}
	if (i == 0)
	{
		ProductStruct tempProduct;
		cout << "Please input the new product name:";
		cin.getline(tempProduct.name, nameMaxLength);
		if (isdigit(tempProduct.name[0]))
		{
			cout << "Name should't start with a digit.";
			return 0;
		}
		cout << "Please input the stock: ";
		tempProduct.stock = inputNum();
		if (tempProduct.stock < 0)
		{
			cout << "Wrong input.\n";
			system("pause");
			return 0;
		}
		productInfo.push_back(tempProduct);

		cout << "Create new product successfully.\n";
		system("pause");
		return 0;
	}
	else
	{
		list<ProductStruct>::iterator iter = productInfo.begin();
		while (i > 1)
		{
			iter++;
			i--;
		}
		int num;
		cout << "Please input the new stock of " << iter->name << " :";
		num = inputNum();
		if (num < 0)
		{
			cout << "Wrong input.\n";
			system("pause");
			return 0;
		}
		iter->stock += num;

		cout << "Now there are " << iter->stock << " of " << iter->name << endl;
		system("pause");
		return 0;
	}
}

int stockOut()
{
	cout << "Please input the product index you want to stock out:";
	int i = inputNum();
	if (i == -1)
	{
		cout << "Wrong input.\n";
		system("pause");
		return 0;
	}
	if (i > productInfo.size())
	{
		cout << "Input number too big.\n";
		system("pause");
		return 0;
	}

	list<ProductStruct>::iterator iter = productInfo.begin();
	while (i > 1)
	{
		iter++;
		i--;
	}
	int num;
	cout << "Please input the moving stock of " << iter->name << " :";
	num = inputNum();
	if (num < 0)
	{
		cout << "Wrong input.\n";
		system("pause");
		return 0;
	}
	if (num > iter -> stock)
	{
		cout << "There aren't enough stock.\n";
		system("pause");
		return 0;
	}
	iter->stock -= num;

	cout << "Now there" << (num==1?" is ":" are ") << iter->stock << " of " << iter->name << endl;
	
	if (iter->stock == 0)
	{
		cout << "Do you mean to remove " << iter->name << " permanently?";
		int choice = system("choice");
		if (choice == 1)
		{
			productInfo.erase(iter);
		}
	}
	system("pause");
	return 0;

}

int stockShow()
{
	if (productInfo.empty())
	{
		cout << "There are no products stocked...\n";
		return 0;
	}
	int i = 1;
	for (list<ProductStruct>::iterator iter = productInfo.begin(); iter != productInfo.end(); iter++)
	{
		cout << i << ".\t" << iter->name;
		for (int i = 0; i < nameMaxLength - strlen(iter->name); i++)
		{
			cout << " "; //to align
		}
		cout << iter->stock << endl;
		i++;
	}
	cout << endl;
	return 0;
}

int loadInfo()
{
	system("cls");

	ifstream fin;
	fin.open(fileName);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			ProductStruct tempProduct;
			if (!(fin >> tempProduct.stock) == 1)
			//stock first and name second so that it can read name with space
			{
				cout << fileName << " seems broken.\n";
				fin.close();
				return 2;
			}
			fin.get(); //to ignore the space.
			fin.getline(tempProduct.name, nameMaxLength);
			productInfo.push_back(tempProduct);
		}
		cout << fileName << " opened correctly.\n";
		Sleep(1000);
		fin.close();
		return 0;
	}
	else
	{
		cout << fileName << " not exists.\n"
			<< "Press any key to create empty warehouse, "
			<<"or close the window to exit.\n";
		system("pause >nul");
		fin.close();
		return 1;
	}
}

int menu()
{
	char choice[nameMaxLength];
	while (true)
	{
		system("cls");
		stockShow();
		cout << "i. Stock in\n"
			<< "o. Stock out\n"
			<< "s. Save and Exit\n";
		cin.getline(choice,nameMaxLength);
		switch (choice[0])
		{
		case 'i': stockIn(); break;
		case 'o': stockOut(); break;
		case 's': return 0;
		default:
			cout << "Wrong input.\n";
			system("pause");
		}
	}
}

int saveInfo()
{
	ofstream fout;
	fout.open(fileName);
	if (!fout.is_open())
	{
		cout << fileName << " write fail.\n"
			<< "Please copy the following text and save to " << fileName << " later.";
		system("pause&cls");
		cout << productInfo;
		getchar();
	}
	else
	{
		fout << productInfo;
		cout << "Data saved to " << fileName << " successfully.\n";
	}
	return 0;
}

int main()
{
	system("title Warehouse");
	loadInfo();

	menu();

	saveInfo();

	cout << "Exiting program...\n";
	system("pause");
}
