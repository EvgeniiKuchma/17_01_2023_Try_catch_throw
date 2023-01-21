#include <iostream>
#include <utility>
#include <tuple>
#include <vector>
#include <unordered_map>
class DataManager
{
public:
	int mostPopChedKey()
	{
		std::unordered_map<int, int> keyAutom;
		for (size_t i = 0; i < _key.size(); i++)
		{
			const auto&  [it, isInserted] = keyAutom.insert({ _key[i], 1 });//достаем из вектора ключ пытаемся вставить в мап. в [it, isInsert] возвращает функция insert <указатель на элемент который мешает сделать инсерт, bool значение удалось вставить или нет>
			if (!isInserted)
			{
				auto value = it->second;
				value++;
				keyAutom[_key[i]] = value;//обращаемся через квадратные скобки так как фунция insert({}) не позволит вставить  а [] гарантированно вставят значения
			}
		}
		std::pair<int, int> key_biggestValue = { 0,0 };
		for (std::unordered_map<int, int>::const_iterator it = keyAutom.begin(); it != keyAutom.end(); it++)
		{
			if (key_biggestValue.second < it->second)
				key_biggestValue = std::make_pair(it->first, it->second);
		}
		return key_biggestValue.first;
	}
private:
	std::vector<int> _key = { 1,1,2,2,2,4,2,6,7,7,7,2 };

};

//try_cach
int errorFunk()
{
	throw 0;
	return 1;
}
int divide(int a, int b)
{
	if (b == 0)
	{
		throw "divizion by zero";
	}
	return a / b;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	//std::tuple <int, std::string, double, float> t{1, "hey", 5.4, 2.3f};
	//const auto& [a, b, c, d] = t;
	//std::tuple <int, int, double> t2;
	//std::cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	//std::cout << std::get<0>(t) << std::endl;//обращение к 0 элементу

	//std::vector<std::tuple<int, double, std::string>> vec;
	//vec.push_back({ 1, 2.5, "bob" });
	//vec.push_back({ 2, 3.14, "Alice" });

	//for (size_t i = 0; i < vec.size(); i++)
	//{
	//	const auto& [x, y, z] = vec[i];
	//	std::cout << x << ' ' << y << ' ' << z << std::endl;
	//}
	DataManager dm;
	std::cout << dm.mostPopChedKey() << std::endl;

	//try_cach
	//int x = 10, y = 0;
	//try 
	//{
	//errorFunk();
	//std::cout << divide(x, y) << std::endl;
	//}
	//catch (const char* msg)
	//{
	//std::cerr << msg << std::endl;//дискриптор 
	//}
	//catch (...)//cath all  - bad practice
	//{
	//	std::cerr << "Some exception has occured" << std::endl;
	//}

	//std::vector<int> v{ 1,2,3,4,5 };
	//try
	//{
	//	int z = v.at(10);//v[10] untifire beheviar неопределенное поведение - UB
	//}
	//catch (const std::out_of_range& e)
	//{
	//	std::cerr << e.what() << std::endl;
	//}
	return 0;
}