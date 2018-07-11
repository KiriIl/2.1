#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
void sort(int *mas, int n)
{
	int t;
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = 0; j < n - i - 1; j++) 
		{
			if (mas[j] > mas[j + 1]) 
			{
				t = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = t;
			}
		}
	}
}
void razbienie(int a, int *mas, int n, int del)
{
	int proc = 10;
	for (int i = 0; i < n; i++)
	{
		if (a >= -9 && a <= 9)
			mas[0] = a;
		else
		{
			if (i == 0)
			{
				mas[i] = a / del;
				del /= 10;
			}
			else
			{
				mas[i] = a / del % proc;
				del /= 10;
			}
		}
	}
}
void usl(int a)
{
	if (a == 1)
		cout << "Верно" << endl;
	else
		cout << "Неверно" << endl;
}
void task1_1(int *mas, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (mas[i] == mas[i + 1])
			count++;
	if (count == 1)
		usl(1);
	else usl(0);
}
void task1_2(int *mas, int n)
{
	bool tri = false;
	int count;
	for (int i = 0; i < 10; i++)
	{
		count = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == mas[j])
				count++;
		}
		if (count == 3)
		{
			usl(1); break;
		}
	}
	if (count != 3)
		usl(0);
}
void task1_3(int *mas, int n)
{
	int count = 0;
	for (int i = 0; i < n / 2; i++)
		if (mas[i] == mas[n - 1 - i])
			count++;
	if (count == n / 2)
		usl(1);
	else usl(0);
}
void task1_4(int *mas, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (mas[i] == mas[i + 1])
			count++;
	if (count > 0)
		usl(0);
	else usl(1);
}
void task1_5(int *mas, int n, int k)
{
	int count;
	for (int i = 0; i < 10; i++)
	{
		count = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == mas[j])
				count++;
		}
		if (count == k)
		{
			usl(1); break;
		}
	}
	if (count != k)
		usl(0);
}
void task1_7(int *mas, int n)
{
	bool tri = false;
	int count;
	for (int i = 0; i < 10; i++)
	{
		count = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == mas[j])
				count++;
		}
		if (count == 2)
		{
			usl(1); break;
		}
	}
	if (count != 2)
		usl(0);
}
void task1_8(int *mas, int n, int k)
{
	bool tri = false;
	int count;
	for (int i = 0; i < 10; i++)
	{
		count = 0;
		for (int j = 0; j < n; j++)
			if (i == mas[j])
				count++;
		if (count >= k)
			usl(1); break;
	}
	if (count < k)
		usl(0);
}
void task1_9(int *mas, int n, int k)
{
	int pervie = 0, poslednie = 0;
	if (k < n)
	{
		for (int i = 0; i < k; i++)
		{
			pervie += mas[i];
			poslednie += mas[n - 1 - i];
		}
		if (pervie == poslednie)
			usl(1);
		else usl(0);
	}
	else cout << "Неверный параметр k" << endl;
}
void task1_11(int *mas, int n, int k, int m)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (mas[i] < m)
			count++;
	cout << count << "   " << k << endl;
	if (count == k)
		usl(1);
	else usl(0);
}
void task1_12(int *mas, int n, int k)
{
	int count = 0;
	if (n >= 3)
	{
		for (int i = 2; i < n; i++)
			if (mas[0] + mas[1] < mas[i])
				count++;
		if (count >= k)
			usl(1);
		else usl(0);
	}
	else cout << "Не то число" << endl;
}
void task2_1(int *drobnaya, int n, int k)
{
	int count = 0;
	if (k <= n)
	{
		for (int i = 0; i < k; i++)
			if (drobnaya[i] == 9)
				count++;
		cout << count << " цифр" << endl;
	}
	else
		cout << "Неверное k для этого числа" << endl;
}
void task2_2(int *drobnaya, int n, int k)
{
	int sum = 0;
	if (k <= n)
	{
		for (int i = 0; i < k; i++)
			sum += drobnaya[i];
		cout << sum << endl;
	}
	else
		cout << "Неверное k для этого числа" << endl;
}
void task2_3(int *drobnaya, int n, int k, int m)
{
	if (k <= n && k + m <= n)
	{
		int sumk = 0, summ = 0;
		for (int i = 0; i < k; i++)
			sumk += drobnaya[i];
		for (int i = k; i < k + m; i++)
			summ += drobnaya[i];
		if (sumk == summ)
			usl(1);
		else usl(0);
	}
	else
		cout << "Неверное k или n для этого числа" << endl;
}
void task2_4(int *drobnaya, int n, int k, int m)
{
	if (k <= n && k + m <= n)
	{
		int t = drobnaya[k - 1], sum = 0;
		for (int i = k; i < k + m; i++)
			sum += drobnaya[i];
		if (t == sum)
			usl(1);
		else usl(0);
	}
	else
		cout << "Неверное k или n для этого числа" << endl;
}
void task2_5(int *drobnaya, int n, int k, int m)
{
	if (k <= n && k - m >= 0)
	{
		int t = drobnaya[k - 1], sum = 0;
		for (int i = k - m - 1; i < k - 1; i++)
			sum += drobnaya[i];
		if (t == sum)
			usl(1);
		else usl(0);
	}
	else
		cout << "Неверное k или n для этого числа" << endl;
}
void task2_6(int *drobnaya, int n, int k, int m)
{
	if (m <= n && k + m <= n)
	{
		int sum = 0;
		for (int i = m; i < k + m; i++)
			sum += drobnaya[i];
		cout << sum << endl;
	}
	else
		cout << "Неверное k или n для этого числа" << endl;
}
void task2_7(int *drobnaya, int *celaya, int nd, int nc, int k)
{
	if (k <= nd)
	{
		int sumc = 0, sumd = 0;
		for (int i = 0; i < k; i++)
			sumd += drobnaya[i];
		for (int i = 0; i < nc; i++)
			sumc += celaya[i];
		if (sumc == sumd)
			usl(1);
		else usl(0);
	}
	else
		cout << "Неверное k для этого числа" << endl;
}
void task2_8(int *drobnaya, int n, int k, int m)
{
	if (m + k <= n)
	{
		for (int i = m; i < m + k; i++)
			cout << drobnaya[i] << setw(3);
		cout << endl;
	}
	else cout << "Неверное k или n для этого числа" << endl;
}
void task2_9(int *drobnaya, int n, int m)
{
	if (m <= n)
	{
		int count = 0;
		for (int i = 0; i < m - 1; i++)
			if (drobnaya[i] == drobnaya[i + 1])
				count++;
		if (count == 0)
			usl(1);
		else usl(0);
	}
	else cout << "Неверное n для этого числа" << endl;
}
void task2_10(int *drobnaya, int n, int m)
{
	if (m <= n)
	{
		int count = 0;
		for (int i = 0; i < m - 1; i++)
			if (drobnaya[i] == drobnaya[i + 1])
				count++;
		if (count == m-1)
			usl(1);
		else usl(0);
	}
	else cout << "Неверное n для этого числа" << endl;
}
void task2_11(int *drobnaya, int n, int m)
{
	if (m <= n)
	{
		int count1 = 0, count2 = 0;
		for (int i = 0; i < m - 1; i++)
			if (drobnaya[i] <= drobnaya[i + 1])
				count1++;
		for (int i = 0; i < m - 1; i++)
			if (drobnaya[i] >= drobnaya[i + 1])
				count2++;
		if (count1 == m - 1 || count2 == m - 1)
			usl(1);
		else usl(0);
	}
	else cout << "Неверное n для этого числа" << endl;
}
void task2_12(int *drobnaya, int n, int m)
{
	if (m <= n && m>=2)
	{
		int d = drobnaya[1] - drobnaya[0], count = 0;
		for (int i = 0; i < m - 1; i++)
			if (drobnaya[i] + d == drobnaya[i + 1])
				count++;
		if (count == m - 1)
			usl(1);
		else usl(0);
	}
	else cout << "Неверное n для этого числа" << endl;
}
void schet(int a, int &n)
{
	if (a == 0)
		n++;
	else
		while (a > 0)
		{
			a /= 10;
			n++;
		}
}
void main()
{
	setlocale(LC_ALL, "rus");
	//					TASK 1
	double drob, ipart;
	int fpart, nd = 0, nc = 0, c1, del, c2, a, b, n = 0, proc = 10, k, m, *mas, *sorted, *drobnaya, *celaya;
	cin >> a;
	b = a;
	schet(b, n);
	del = pow(10, n - 1);
	mas = new int[n];
	sorted = new int[n];
	razbienie(a, mas, n, del);
	for (int i = 0; i < n; i++)
		sorted[i] = mas[i];
	sort(sorted, n);
	cout << "1.	Дано натуральное  n.  Верно ли, что это число содержит только две одинаковые цифры? ";
	task1_1(sorted, n);
	cout << "2.	Дано натуральное  n.  Верно ли, что это число содержит ровно три одинаковые цифры? ";
	task1_2(sorted, n);
	cout << "3.	 Дано натуральное n. Определить, является ли это число палиндромом. ";
	task1_3(mas, n);
	cout << "4.	 Дано  натуральное  n. Верно ли,  что все  цифры числа различны? ";
	task1_4(sorted, n);
	cout << "5.	 Дано натуральное  n.  Верно ли, что это число содержит ровно k одинаковыx цифр? " << endl;
	cout << "Введите k" << endl;
	cin >> k;
	task1_5(sorted, n, k);
	cout << "7.	Дано натуральное  n.  Верно ли, что это число содержит ровно 2 одинаковые цифры? ";
	task1_7(sorted, n);
	cout << "8.	Дано натуральное  n.  Верно ли, что это число содержит более k одинаковых цифр? " << endl;
	cout << "Введите k" << endl;
	cin >> k;
	task1_8(sorted, n, k);
	cout << "9.	Определить, равна ли сумма k первых цифр заданного натурального  числа, сумме  k его последних цифр. " << endl;
	cout << "Введите k" << endl;
	cin >> k;
	task1_9(mas, n, k);
	cout << "11.	 Дано натуральное  n.  Верно ли, что это число содержит  k цифр, значения которых меньше заданного  m? " << endl;
	cout << "Введите k и m" << endl;
	cin >> k >> m;
	task1_11(mas, n, k, m);
	cout << "12.	Дано натуральное  n.  Верно ли, что это число содержит более k цифр больших суммы первых 2 цифр." << endl;
	cout << "Введите k" << endl;
	cin >> k;
	task1_12(mas, n, k);
	//					TASK 2
	cout << endl;
	cout << endl;
	cin >> drob;
	fpart = modf(drob, &ipart);
	c2 = c1 = ipart;
	schet(c1, nc);
	celaya = new int[nc];
	del = pow(10, nc - 1);
	razbienie(c2, celaya, nc, del);
	while (modf(drob, &ipart) > 0)
	{
		fpart = modf(drob, &ipart) * 10;
		drob *= 10;
		nd++;
	}
	drobnaya = new int[nd];
	drob /= pow(10, nd);
	for (int i = 0; i < nd; i++)
	{
		fpart = modf(drob, &ipart) * 10;
		drob *= 10;
		drobnaya[i] = fpart;
	}
	cout << "Получилось число:   ";
	for (int i = 0; i < nc; i++)
		cout << celaya[i];
	cout << ".";
	for (int i = 0; i < nd; i++)
		cout << drobnaya[i];
	cout << endl;
	cout << "1.	Определить,  сколько среди первых k цифр  дробной части заданного положительного вещественного числа, цифр 9.  ";
	cout << "Введите k" << endl;
	cin >> k;
	task2_1(drobnaya, nd, k);
	cout << "2.	Определить сумму первых k цифр дробной части заданного положительного вещественного числа. ";
	cout << "Введите k" << endl;
	cin >> k;
	task2_2(drobnaya, nd, k);
	cout << "3.	Определить, равна ли сумма первых k цифр дробной части заданного положительного вещественного числа сумме n следующих цифр. ";
	cout << "Введите k и n" << endl;
	cin >> k >> m;
	task2_3(drobnaya, nd, k, m);
	cout << "4.	Определить, равна ли k-ая цифра дробной части заданного положительного вещественного числа сумме n следующих  цифр. ";
	cout << "Введите k и n" << endl;
	cin >> k >> m;
	task2_4(drobnaya, nd, k, m);
	cout << "5.	Определить, равна ли k-ая цифра дробной части заданного положительного вещественного числа сумме n предыдущих  цифр. ";
	cout << "Введите k и n" << endl;
	cin >> k >> m;
	task2_5(drobnaya, nd, k, m);
	cout << "6.	Определить сумму k цифр дробной части заданного положительного вещественного числа, которые следуют за n-ой цифрой. ";
	cout << "Введите k и n" << endl;
	cin >> k >> m;
	task2_6(drobnaya, nd, k, m);
	cout << "7.	Определить равна ли сумма k цифр дробной части заданного положительного вещественного числа сумме цифр целой части этого числа. ";
	cout << "Введите k" << endl;
	cin >> k;
	task2_7(drobnaya, celaya, nd, nc, k);
	cout << "8.	 Определить  цифр дробной части заданного положительного вещественного числа, которые следуют за n-ой цифрой. ";
	cout << "Введите k и m" << endl;
	cin >> k >> m;
	task2_8(drobnaya, nd, k, m);
	cout << "9.	Верно ли, что первые n цифр дробной части заданного положительного вещественного числа различны? ";
	cout << "Введите m" << endl;
	cin >> m;
	task2_9(drobnaya, nd, m);
	cout << "10.	Верно ли, что первые n цифр дробной части заданного положительного вещественного числа одинаковы? ";
	cout << "Введите m" << endl;
	cin >> m;
	task2_10(drobnaya, nd, m);
	cout << "11.	Верно ли, что первые n цифр дробной части заданного положительного вещественного числа образуют монотонную последовательность? ";
	cout << "Введите m" << endl;
	cin >> m;
	task2_11(drobnaya, nd, m);
	cout << "12.	Верно ли, что первые n цифр дробной части заданного положительного вещественного числа образуют арифметическую прогрессию? ";
	cout << "Введите m" << endl;
	cin >> m;
	task2_12(drobnaya, nd, m);
	delete[] drobnaya;
	delete[] celaya;
	delete[] mas;
	delete[] sorted;
	system("pause");
}