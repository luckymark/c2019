#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;

int Table[] = {
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};

string encodedText, decodedText;

void pr(int k)
{
	for (int s=0; s<6; s++) printf("%d", (k>>s)&1);
	printf("\n");
}

void encode(string text)
{
	int len = text.length();
	vector<int> tmp;
	for (int s = 0; s < len; s++)
	{
		for (int t = 7; t >= 0; t--)
			tmp.push_back((text[s] >> t) & 1);
	}
	int size = tmp.size();
	while (size % 24 != 0)
	{
		tmp.push_back(0);
		size++;
	}
	for (int s = 0; s < size; s += 6)
	{
		int val = 0;
		for (int t = 0; t < 6; t++)
			val += tmp[s+t] << (5-t);
		if (val)
			encodedText += Table[val];
		else
			encodedText += '=';
	}
}

void decode(string text)
{
	int len = text.length();
	vector<int> tmp;
	for (int s = 0; s < len; s++)
	{
		if (text[s] == '=') continue;
		int inc;
		for (inc = 0; text[s] != Table[inc]; inc++);
		for (int t = 0; t < 6; t++)
			tmp.push_back((inc >> (5-t)) & 1);
	}
	for (int s = 0; s < tmp.size(); s += 8)
	{
		int val = 0;
		for (int t = 0; t < 8; t++)
			val += tmp[s+t] << (7-t);
		decodedText += val;
	}
}

int main()
{
	string message;
	getline(cin, message);
	encode(message);
	cout << "Encoded:\n" << encodedText << endl;
	decode(encodedText);
	cout << "Decoded:\n" << decodedText << endl;
}

