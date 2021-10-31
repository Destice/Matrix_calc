#include <iostream>
#include <vector>
using namespace std;



class Matrix {

private:
	int width, height;
	vector <vector<int>> v; //domyslnie uzycie v[wiersze][kolumny]

public:
	Matrix(int height, int width) 
	{
		this->width = width;
		this->height = height;
		v.resize(height); //rozszerzam "1 kolumne" na podana liczbe wierszy
		for (int i = 0; i < height; i++) //petla przelatujaca rozszerzona kolumne "dla kazdego wiersza"
		{
			v[i].resize(width); //rozrzeszam kazdy wiersz do podanej wartosci
		}
	}
	void insert_value(int row, int column, int value) 
	{
		v[row][column] = value;
	}
	void auto_insert_values()
	{
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{
				v[j][i] = i; //przypisanie wartosci v[wiersz][kolumna]
			}
		}
	}
	void print_matrix()
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				cout<< v[i][j]; //wypisanie v[wiersz][kolumna]
			}
			cout << endl;
		}
	}
	int return_value(int row, int column)
	{
		return v[row][column];
	}
	int return_height()
	{
		return height;
	}
	int return_width()
	{
		return width;
	}
	Matrix matrix_addition(Matrix added)
	{
		try {

		
			if (added.return_height() == height && added.return_width() == width)
			{
				Matrix* m3 = new Matrix(height, width);
				for (int i = 0; i < height; i++)
				{
					for (int j = 0; j < width; j++)
					{
						m3->insert_value(i, j, v[i][j] + added.return_value(i, j));
					}

				}
				return *m3;
			}
			else
				cout << "Dodawanie niemozliwe - wymiary macierzy niezgodne";
		}
		catch (exception& e)
		{
			cerr << e.what();
		}
	}

};


int main()
{
	Matrix m1(5,3); //macierz(wiersze,kolumny)
	m1.auto_insert_values();
	m1.print_matrix();

	cout << endl;

	Matrix m2(4, 2);
	m2.auto_insert_values();
	m2.print_matrix();

	cout << endl;

	Matrix m3 = m1.matrix_addition(m2);
	m3.print_matrix();

	return 0;
}