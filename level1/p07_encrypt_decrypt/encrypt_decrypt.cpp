// HuffmanCompress.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include <windows.h>
#include <memory.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "Huffman.h"
#include <errno.h>
using namespace std;
size_t WR_SIZE = 1024*1024 ;  //每次读写的大小,此处为0.01M
const char displayLoading = 1; //编码进度显示
const int chFreqSize = 256;
unsigned long long chFreq[chFreqSize];

long long getFileSize(const char *FileName)
{

	FILE *stream_rd;
	if (0 == fopen_s(&stream_rd, FileName, "rb"))
	{
		_fseeki64(stream_rd, 0L, SEEK_SET);
		long long begin = _ftelli64(stream_rd);
		_fseeki64(stream_rd, 0L, SEEK_END);
		long long end = _ftelli64(stream_rd);
		fclose(stream_rd);
		return (end - begin);
	}
	else
	{
		fclose(stream_rd);
		return -1;
	}
}
void read_count_bitFile(const char *FILE_RD)
{
	FILE *stream_rd;
	size_t num_read;
	int rw_cnt = 0;
	long long offset = 0;

	unsigned char *buf = new unsigned char[WR_SIZE];
	long long fileSize = getFileSize(FILE_RD);
	if (0 == fopen_s(&stream_rd, FILE_RD, "rb"))
	{

		while (!feof(stream_rd))
		{
			//读
			num_read = fread(buf, sizeof(char), WR_SIZE, stream_rd);
			if (displayLoading == 1 && 0 != num_read)
			{
				system("cls");
				long long curpoision = _ftelli64(stream_rd); //得到当前加载位置
				double percent = (double)curpoision / (double)fileSize * 100;
				cout << "Loading " << percent << "% " << endl;
			}
			//统计二进制信息
			unsigned long i = num_read;
			//long long count = 0;
			while (i--)
			{
				chFreq[buf[i]]++;
			}
			if (0 == num_read)
				break;
			offset = num_read;						//文件偏移
			//_fseeki64(stream_rd, offset, SEEK_CUR); //注意，这样做不能随意更改文件流位置
		}
	}
	//资源释放
	delete[] buf;
	fclose(stream_rd);
}
//将一个字符转化为二进制串存入数组
void b2char(unsigned char a,unsigned char code[], int k)
{

	for (int i = k; i < k + 8; i++)
		code[i] = 0;
	

	int c = (int)a;
	int n = k+7;
	while (c)
	{
		code[n--] = c % 2;
		c = c / 2;
	}
}

//以8为单位，将字符数组a转换为acsii
void char2b(unsigned char a[], unsigned char b[])
{

	int j, m;
	int k = 0;
	for (; a[8 * k] != '\0'; k++)
	{
		unsigned char c = 0;
		for (int i = 8 * k; i < 8 * k + 8; i++)
		{
			if (a[i] != 0)
			{
				m = 7 - i + 8 * k;
				j = 1 << m;
				c = c + (int)(a[i] - '0') * j;
			}
		}
		b[k] = c;
	}
}

void write_bitFile(const char *FILE_RD, const char *FILE_WR, HNode *HT, HCode *HC, const int n)
{
	FILE *stream_rd, *stream_wr, *stream_wr_miyao;
	size_t num_read, num_written;
	long long offsetRD = 0;
	long long offsetWR = 0;
	unsigned char *bufRD = new unsigned char[WR_SIZE];
	unsigned char *bufWR = new unsigned char[WR_SIZE];
	unsigned char *buf = new unsigned char[8 * WR_SIZE + 1];
	long long fileSize = getFileSize(FILE_RD);
	long long k = 0;
	//先处理加密区
	unsigned long long *buff = new unsigned long long[chFreqSize];
	fopen_s(&stream_wr_miyao, "miyao.b", "wb");
	for (int ll = 0; ll < chFreqSize; ll++)
	{
		buff[ll] = chFreq[ll];
	}
	fwrite(buff, sizeof(unsigned long long), chFreqSize, stream_wr_miyao);
	delete[] buff;
	fclose(stream_wr_miyao);
	//打开要写的文件
	errno_t errNum = 0;
	try
	{
		errNum = fopen_s(&stream_wr, FILE_WR, "wb");
	}
	catch (...)
	{
		cout << errNum << endl;
	}
	//正式文件处理
	if (0 == fopen_s(&stream_rd, FILE_RD, "rb"))
	{

		while (!feof(stream_rd))
		{
			//读
			num_read = fread(bufRD, sizeof(char), WR_SIZE, stream_rd);
			long long debugRD = _ftelli64(stream_rd);
			if (displayLoading == 1 && 0 != num_read)
			{
				system("cls");
				long long curpoision = _ftelli64(stream_rd); //得到当前加载位置
				double percent = (double)curpoision / (double)fileSize * 100;
				cout << "Encoding perccent: " << percent << "% " << endl;
			}
			if (0 == num_read)
				break;
			offsetRD = num_read;					  //文件偏移
			//_fseeki64(stream_rd, offsetRD, SEEK_CUR); //注意，这样做不能随意更改文件流位置
			//文件读出后放入新buf区
			long long maxn = num_read;
			for (int i = 0; i < maxn; i++) //内存字段扫描，每次1B
			{
				for (int j = HC[bufRD[i]].start; j < n; j++) //编码扫描
				{
					//得到char串
					unsigned char tempchar1bit = (unsigned char)(HC[bufRD[i]].bit[j] + '0');
					buf[k++] = tempchar1bit;

					if (k == 8 * WR_SIZE) //装满了，但是可能j还有信息
					{
						buf[k] = '\0';
						char2b(buf, bufWR); //把char串转换成ascii
						
						num_written = fwrite(bufWR, sizeof(char), WR_SIZE, stream_wr);
						offsetWR = num_written;
						//_fseeki64(stream_wr, offsetWR, SEEK_CUR);
						long long debug1 = _ftelli64(stream_wr);
						k = 0;

					//	buf[0] = '\0';
					}
				}
			}
			
		}
		if (num_read != WR_SIZE && k != 0) //说明读完了但是buf区还有东西
		{
			int tempi = ((k - 1) % 8 + 1);
			if (tempi != 8)
			{
				for (int kk = 0; kk < 8 - tempi; kk++)
					buf[k++] = 0;
			}
			buf[k] = '\0';
			char2b(buf, bufWR); //把信息转换后存到bufWR

			size_t write_size = k / 8;
			k = 0;
			num_written = fwrite(bufWR, sizeof(char), write_size, stream_wr);
			
			offsetWR = num_written;
//			_fseeki64(stream_wr, offsetWR, SEEK_CUR);
			long long debug1 = _ftelli64(stream_wr);
			//	buf[0] = '\0';
		}
	}

	//资源释放
	delete[] bufRD;
	delete[] bufWR;
	delete[] buf;
	fclose(stream_rd);
	fclose(stream_wr);
}
void HuffmanDecoding(const char *FILE_RD, const char *FILE_WR)
{
	FILE *stream_rd_miyao;

	/*
	if (0 != fopen_s(&stream_wr, FILE_WR, "wb"))
	{ //获取待写入文件的句柄
		errNum = errno;
		printf("open fail errno = %d reason = %s \n", errNum, (errNum));
		return;
	}
	*/

	//先处理加密区,得到哈夫曼树和哈夫曼编码
	unsigned long long *buff = new unsigned long long[chFreqSize];
	fopen_s(&stream_rd_miyao, "miyao.b", "rb");
	unsigned long long *REchFreqSize = new unsigned long long[chFreqSize];
	fread(REchFreqSize, sizeof(unsigned long long), chFreqSize, stream_rd_miyao);
	HNode *HT = new HNode[2 * chFreqSize - 1];
	HCode *HC = new HCode[chFreqSize];
	HuffmanCoding(HT, HC, REchFreqSize, chFreqSize);
	fclose(stream_rd_miyao);
	delete[] REchFreqSize;
	//找到树的根
	int root[2];
	for (int i = 0, j = 0; i < 2 * chFreqSize - 1; i++)
	{
		if (HT[i].parent == -1)
			root[j++] = i;
	}
	//读入加密文件
	FILE *stream_rd, *stream_wr;
	size_t num_read, num_written;

	errno_t errNum = 0;
	try
	{
		errNum = fopen_s(&stream_wr, FILE_WR, "wb");
	}
	catch (...)
	{
		cout << errNum << endl;
	}

	/*
	if (0 != fopen_s(&stream_wr, FILE_WR, "wb"))
	{ //获取待写入文件的句柄
		errNum = errno;
		printf("open fail errno = %d reason = %s \n", errNum, (errNum));
		return;
	}
	*/
	unsigned char *bufRD = new unsigned char[WR_SIZE];
	unsigned char *bufWR = new unsigned char[8 * WR_SIZE];
	unsigned char *buf = new unsigned char[8 * WR_SIZE ];
	long long fileSize = getFileSize(FILE_RD);
	long long k = 0;
	long long offsetRD = 0;
	long long offsetWR = 0;
	//正式文件处理
	
	//读文件
	if (0 == fopen_s(&stream_rd, FILE_RD, "rb"))
	{
		int Nodeindex = root[0];
		HNode rootNode = HT[Nodeindex];
		int targetindex = 0;
		
		int count_for_WR = 0;
		//unsigned long long aaa = 0,bbb=0;

		while (!feof(stream_rd))
		{
			
			//读
			num_read = fread(bufRD, sizeof(char), WR_SIZE, stream_rd);

			if (displayLoading == 1 && 0 != num_read)
			{
				system("cls");
				long long curpoision = _ftelli64(stream_rd); //得到当前加载位置
				double percent = (double)curpoision / (double)fileSize * 100;
				cout << "Decoding perccent: " << percent << "% " << endl;
			}

			if (0 == num_read)
				break;
			//变为二进制码
			long k = 0;
			for (int i = 0; i < num_read; i++, k += 8)
			{
				b2char(bufRD[i], buf, k);
			}
			//解码

			//aaa += num_read;

			for (long j = 0; j < k; j++)
			{
				int upflag = 0;
				//如果为1，访问右节点，否则左节点
				if (buf[j])
					//如果要访问右节点
					if (rootNode.rchild == -1) //如果已经是叶节点
					{
						if (rootNode.lchild != -1)
						{
							printf("r l error");
							exit(0);
						}
						targetindex = Nodeindex;
						j--;
						upflag = 1;
					}
					else
					{
						Nodeindex = rootNode.rchild;
						rootNode = HT[Nodeindex];
					}
				else
				{
					if (rootNode.lchild == -1)
					{
						if (rootNode.rchild != -1)
						{
							printf("l r error");
							exit(0);
						}
						targetindex = Nodeindex;
						j--;
						upflag = 1;
					}
					else
					{
						Nodeindex = rootNode.lchild;
						rootNode = HT[Nodeindex];
					}
				}
				if (upflag) //如果找到了一个根结点
				{
					bufWR[count_for_WR++] = (unsigned char)targetindex;
					targetindex = -1;
					Nodeindex = root[0];
					rootNode = HT[Nodeindex];
				}
			}
			//读文件更新
			offsetRD = num_read;				  //文件偏移
			//_fseeki64(stream_rd, offsetRD, SEEK_CUR); //注意，这样做不能随意更改文件流位置
			//写文件和文件更新
			num_written = fwrite(bufWR, sizeof(char), count_for_WR , stream_wr);
			long long debug1 = _ftelli64(stream_wr);
			/*
			if (displayLoading == 1 )
			{
				long long curpoision1 = _ftelli64(stream_wr); //得到当前加载位置
				double percent1 = (double)bbb / (double)aaa * 100;
				cout << "Decoding perccent1: " << percent1 << "% " << endl;
			}
			
			bbb += count_for_WR;
			*/
			count_for_WR = 0;//每次写完后清空
			offsetWR = num_written;
//			_fseeki64(stream_wr, offsetWR, SEEK_CUR);
		}
	}

	//资源释放
	delete[] bufRD;
	delete[] bufWR;
	delete[] buf;
	fclose(stream_rd);
	fclose(stream_wr);

	//清空
	delete[] HC;
	delete[] HT;
}
int main()
{
	/*
	unsigned char a[17] = "0110001111000001";
	unsigned char b[80];
	char2b(a, b);
	*/
	/*
	unsigned char a = 127;
	unsigned char code[8];
	b2char(a, code, 0);
	*/
	const char *FILE_RD = "1.exe"; //原文件
	const char *FILE_WR = "2.exe"; //待写入的文件
	const char *FILE_RE = "3.exe"; //解码出的文件
	for (int i = 0; i < chFreqSize; i++)
		chFreq[i] = 0;
	//读取和统计二进制文件频率
	read_count_bitFile(FILE_RD);

	//构造HUFFMAN TREE以及编码
	HNode *HT = new HNode[2 * chFreqSize - 1];
	HCode *HC = new HCode[chFreqSize];
	HuffmanCoding(HT, HC, chFreq, chFreqSize);
	//写入文件
	write_bitFile(FILE_RD, FILE_WR, HT, HC, chFreqSize);
	//HUFFMAN解码
	HuffmanDecoding(FILE_WR, FILE_RE);
	//清空
	delete[] HC;
	delete[] HT;

	return 0;
}

/*
#include <iostream>
#include <fstream>
using namespace std;

long print_get_FileSize(const char * filename)
{

	long l, m;
	ifstream in(filename, ios::in | ios::binary);
	l = in.tellg();
	in.seekg(0, ios::end);
	m = in.tellg();
	in.close();
	cout << "size of " << filename;
	cout << " is " << (m - l) << " bytes.\n";
	return (m - l);
}
int read_count_file(const char * filename)
{

}
int main()
{
	char * buffer;




	return 0;

}*/
