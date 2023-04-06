#include <iostream>             
//Jawaban soal ke 6.buatlah sebuah program yang mengimplementasikan merge sort menggunakan bahasa c++, (QuicSort)
using namespace std;

//pembuatan array sesuai dengan NIM mahasiswa
int zan[17]; 
int cmp_count = 0; 
int mov_count = 0; 
int n; 

//prosedur input
void input() {
	 
	while (true)
	{
		cout << "Masukan panjang element array = ";
		cin >> n;

		if (n <= 17)
			break;
		else
			cout << "\nMaksimum panjang array adalah 17" << endl;
	}
	cout << "\n------------------" << endl;
	cout << "\nEnter array element" << endl;
	cout << "\n------------------" << endl;

	for (int i = 0; i < n; i++) {
		cout << "<" << (i + 1) << ">";
		cin >> zan[i];
	}
}

//prosedur penukaran element index x dan y
void swap(int x, int y) {
	int temp;

	temp = zan[x];
	zan[x] = zan[y];
	zan[y] = temp;
}

//prosedur quicksort
void q_sort(int low, int high) {     //langkah pertama
	int pivot, i, mf; //f merupakan inisial nama dari mahasiswa
	if (low > high)										
		return;

	pivot = zan[low];									//langkah kedua

	i = low + 1;										//langkah ketiga
	mf = high;											//langkah keempat

	while (i <= mf) {									//langkah kesepuluh
		//mencari elemen yang lebih besar dari pivot
		while ((zan[i] <= pivot) && (i <= high)) {		//langkah kelima
			i++;
			cmp_count++;								//langkah keenam
		}
		//mencari elemen yang lebih kecil dari pivot
		while ((zan[mf] > pivot) && (mf >= low)) {		//langkah ketujuh
			mf--;
			cmp_count++;								//langkah kedelapan
		}
		cmp_count++;

		if (i < mf) { 		//langkah kesembilan
			
			swap(i, mf);
			mov_count++;
		}
	}
	//j menganduk indeks dari elemen terakhir sorted list
	if (low < mf) {													//langkah kesebelas
		//ubah pivot ke posisi yang benar dari list
		swap(low, mf);
		mov_count++;
	}
	//urutkan list di kiri menggunakan quick sort
	q_sort(low, mf - 1);												//langkah keduabelas

}

//prosedur display
void display() {
	cout << "\n----------" << endl;
	cout << "Sorted Array" << endl;
	cout << "\n----------" << endl;

	for (int i = 0; i < n; i++) {
		cout << zan[i] << " ";
	}

	cout << "\n\nNumber of Comparasions: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}

int main()
{

	input();

	q_sort(0, n - 1);
	display();
	system("pause");

	return 0;
}

//soal no 1. jelaskan mengapa suatu algoritma dibutuhkan untuk menyelesaikan suatu masalah.
//soal no 2. dalam algoritma, di klasifikasikan menjadi 2 data struktur tersebut. Sebutkan 2 data struktur tersebut
//soal no 3. untuk mengukur sebuah efisiensi waktu suatu algoritma dibutuhkan beberapa faktor. Sebutkan faktor-faktor yang mempengaruhi 
//efisiensi waktu ekskusi suatu program
//soal no 4. dari 6 algoritma yang sudah dipelajari. algoritma manakah yang paling mudah dipahami dan diplememtasikan untuk menggunakan 
//data yang ukuranya besar.jelaskan mengapa anda memilih itu
//soal no 5. sebutkan dari algoritma yang telah dipelajari mana yang termasuk kedalam Quadrastil dan manakah tang termasuk kedalam logliner

//Jawaban acak sesuai dengan pengetahuan
//no 4. QuickSort, karna quik sort dapat menampung banyaknya data dan mudah dipahami
//no 5. yang termasuk dalam Quadrastic adalah QuickSort yang termasuk dalam loglinear adalah insertion
//no 2. 2 struktur data yang dimaksud pertama adalah statik => array dan dynamic
//no 3. faktor 1. kecepatan mesin ...faktor 2. definetenes ada awal dan akhir ....faktor 3. input.....faktor 4. output......faktor 5 pemilihan jenis data
//no 1. karena algoritma dapat menyelesaikan suatu masalah dengan bertahap tanpa melewatkan satu tahapan pun.
