
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream fin("in.txt");
	int N, M, temp;
	fin >> N;
	int* arr1 = new int[N];

		for (int i = 0; i < N; ++i) {
		fin >> temp;
		arr1[i] = temp;
		}

		fin >> M;
		int* arr2 = new int[M];
		for (int i = 0; i < M; ++i) {
			fin >> temp;
			arr2[i] = temp;
		}
				
			fin.close();


					std::ofstream fout("out.txt");

					fout << M << std::endl;
					fout << arr2[M - 1] << ' ';
					for (int i = 0; i < M - 1; ++i) {
						fout << arr2[i] << ' ';
					}
					fout << std::endl;

					fout << N << std::endl;
					for (int i = 1; i < N; ++i) {
						fout << arr1[i] << ' ';
					}
					fout << arr1[0] << ' ';

						fout.close();


	delete[] arr1;
	delete[] arr2;

	return 0;
}

