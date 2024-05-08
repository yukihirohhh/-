#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//テンプレート　型をパラメータにとっていろいろな型に対応できる機能
//              多態性の一つ

//2つの整数のうち大きいほうを返す
int myMax(int a, int b);
//2つの単精度実数のうち大きいほうを返す
float myMax(float a, float b);
//2つのバイ制度実数のうち大きいほうを返す
double myMax(double a, double b);


int myMax(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
//2つの単精度実数(float)のうち大きいほうを返す

float myMax(float a, float b)
{
	if (a > b)
		return a;
	else
		return b;
}

double myMax(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;
}

// 関数テンプレート
template <typename T>
T tMax(T a, T b) {
	if (a > b)
		return a;
	else
		return b;
}

// クラステンプレート
template <typename T>
class Vec2
{
public:
	T x;
	T y;
	T GetX() { return(x); }
	void SetX(T _x) { x = _x; }
	void PrintVec() { cout << "(x,y)= (" << x << "," << y << ")" << endl; }	

	// ベクトルの長さを計算する関数
	T Length() const { return (T)sqrt(x*x + y*y); }

	// ベクトルの長さで比較する>演算子をオーバーロード
	bool operator > (const Vec2<T>& vec) const {
		return this->Length() > vec.Length();
	}

};

int main() {

	//int var1 = 10;
	//int var2 = 20;
	//int res = tMax<int>(var1, var2);
	//cout << "myMax 10 20 : " << res << endl;
	//float var3 = 10.6;
	//float var4 = 2.1;
	//float res2 = tMax<float>(var3, var4);
	//cout << "myMax : " << res2 << endl;
	//double var5 = 0.000062;
	//double var6 = 1e-15; // 10のマイナス15乗
	//double res3 = tMax<double>(var5, var6);
	//cout << "myMax : " << res3 << endl;

	Vec2 <int> v1;
	v1.x = 2.2;
	v1.y = 3.5;
	

	Vec2 <int> v2;
	v2.x = 4.4;
	v2.y = 1.7;
	

	// ベクトルの長さを比較
	/*if (v1 > v2) {
		v1.PrintVec();
	}
	else {
		v2.PrintVec();
	}*/

	Vec2<int> res = tMax(v1, v2);
	res.PrintVec();
	return 0;
}