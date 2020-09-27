#include <iostream>
#include <random>

using namespace std;

class Random
{
private:
	int low_;
	int high_;
	uniform_int_distribution<> dist_;
public:
	Random(int low, int high) : low_(low), high_(high), dist_(low, high){}
	int DefaultRandomEngine()
	{
		static default_random_engine e;
		return dist_(e);
	}
	int MinstdRand()
	{
		static minstd_rand e;
		return dist_(e);
	}
	int MinstdRand0()
	{
		static minstd_rand e;
		return dist_(e);
	}
	int Mt19937()
	{
		static mt19937 e;
		return dist_(e);
	}
	int Mt19937_64()
	{
		static mt19937_64 e;
		return dist_(e);
	}
	int Ranlux24Base()
	{
		static ranlux24_base e;
		return dist_(e);
	}
	int Ranlux48Base()
	{
		static ranlux48_base e;
		return dist_(e);
	}
	int Ranlux24()
	{
		static ranlux24 e;
		return dist_(e);
	}
	int Ranlux48()
	{
		static ranlux48 e;
		return dist_(e);
	}
	int KnuthB()
	{
		static knuth_b e;
		return dist_(e);
	}
	int RandomDebvice()
	{
		static random_device e;
		return dist_(e);
	}
	int rand()
	{
		return rand() % high_ + low_;
	}
};

class Distribution
{
public:
	Distribution(){} 
	Random random(int low, int high) 
	{ 
		Random rnd(low, high);
		return rnd;
	}

};

int main()
{
	Distribution gen;
	vector<int> histogram(10);
	for (int i = 0; i != 200; ++i)
		++histogram[gen.random(0, 9).DefaultRandomEngine()];

	// print histogram
	for (int i = 0; i != histogram.size(); i++)
	{
		cout << i << " ";
		for (int j = 0; j != histogram[i]; ++j)
			cout << '*';
		cout << endl;
	}

	cin.get();
}