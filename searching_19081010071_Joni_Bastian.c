#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define BILLION  1000000000L;

struct mahasiswa{
	char nama[50];
	char npm[12];
	char alamat[50];
	char email[50];
	char nohp[15];
	char doswal[50];
	char smt[5];
	
};
typedef struct mahasiswa mhs;
mhs temp, data_mhs[]={
		{"Joni Bastian", "19081010071", "Jl. Sunaryo KM. 04", "19081010071@student.upnjatim.ac.id" ,"082284664698", "Made Hanindia Prami Swari", "3"},
		{"Joni", "19081010081", "Jl. Maju", "19081010081@tudent.upnjatim.ac.id", "081234562345", "Made Hanindia Prami Swari", "5"},
		{"Bastian", "19081010091", "Jl. Mundur", "19081010091@student.upnjatim.ac.id", "082232435465", "Made Hanindia Prami Swari", "4"},
		{"Jobas", "19081010101", "Jl. Tengah-tengah", "19081010101@student.upnjatim.ac.id", "082232425263", "Made Hanindia Prami Swari", "2"}
	};	
	
int data=0;

void insert(char nama[50],
			char npm[12],
			char alamat[50], 
			char email[30], 
			char nohp[15], 
			char doswal[50], 
			char smt[5]){
	
	strcpy(data_mhs[data].nama, nama);
	strcpy(data_mhs[data].npm, npm);
	strcpy(data_mhs[data].alamat, alamat);
	strcpy(data_mhs[data].email, email);
	strcpy(data_mhs[data].nohp, nohp);
	strcpy(data_mhs[data].doswal, doswal);
	strcpy(data_mhs[data].smt, smt);
	data++;
}

void update(int nomor,
			char nama[50],
			char npm[12],
			char alamat[50], 
			char email[30], 
			char nohp[15], 
			char doswal[50], 
			char smt[5]){
	
	strcpy(data_mhs[nomor].nama, nama);
	strcpy(data_mhs[nomor].npm, npm);
	strcpy(data_mhs[nomor].alamat, alamat);
	strcpy(data_mhs[nomor].email, email);
	strcpy(data_mhs[nomor].nohp, nohp);
	strcpy(data_mhs[nomor].doswal, doswal);
	strcpy(data_mhs[nomor].smt, smt);
}

void delete(int nomor){
	
	int i=0;
	for(i=0;i<data;i++){
		if(i==nomor){
			int y=0;
			for(y=i;y<data-1;y++){
				data_mhs[y]=data_mhs[y+1];
			}
			data--;
			break;
		}
	}
}


void bubble_sort(int type){
	int y,z;
	for(y = 0; y < data-1; y++) 
        {
            for(z = 0; z < data-1; z++)
            {
            	
				if(type==1){
					if(strcmp(data_mhs[z].npm, data_mhs[z+1].npm) > 0){
						mhs temp;
						temp=data_mhs[z];
						data_mhs[z]=data_mhs[z+1];
						data_mhs[z+1]=temp;
					}
				}
				if(type==2){
					if(strcmp(data_mhs[z].npm, data_mhs[z+1].npm) < 0){
						mhs temp;
						temp=data_mhs[z];
						data_mhs[z]=data_mhs[z+1];
						data_mhs[z+1]=temp;
					}
				}
            }
        }
}

void selection_sort(int type){
	int y, z, pos;
	if(type==1){
		for(y = 0; y < data-1; y++){
        	pos = y;
            for(z = y+1; z < data; z++)
            {
					if(pos = strcmp(data_mhs[z].npm,data_mhs[pos].npm) > 0){
						mhs temp;
			            temp=data_mhs[pos];
						data_mhs[pos]=data_mhs[z];
						data_mhs[z]=temp;
					}
				}
            }
	}else if(type==2){
		for(y = 0; y < data-1; y++){
        	pos = y;
            for(z = y+1; z < data; z++)
            {
					if(pos = strcmp(data_mhs[z].npm,data_mhs[pos].npm) < 0){
						mhs temp;
			            temp=data_mhs[pos];
						data_mhs[pos]=data_mhs[z];
						data_mhs[z]=temp;	
					}
				}
            }		
	}
	            
}

void sequential_search(int sistem){
	int flag = 0;
	int i;
	char find[100];
	
		selection_sort(1);
			
		printf("Masukkan NPM yang ingin anda cari menggunakan Sequential Search : ");				
		scanf("%s",&find);	
						
		for (i=0;i<data;i++){
			if(strcmp(data_mhs[i].npm,find) == 0){
				flag=i;
			}
		}
		
					if (flag >= 0){
						printf("\nNPM %s berhasil ditemukan dalam list, dan berada pada Mahasiswa Ke-%d\n\n", find, flag);
						printf("\nNama\t\t : %s",&data_mhs[flag].nama);
						printf("\nNPM\t\t : %s",&data_mhs[flag].npm);
						printf("\nAlamat\t\t : %s",&data_mhs[flag].alamat);
						printf("\nEmail\t\t : %s",&data_mhs[flag].email);
						printf("\nNomor HP\t : %s",&data_mhs[flag].nohp);
						printf("\nDosen Wali\t : %s",&data_mhs[flag].doswal);
						printf("\nSemester\t : %s\n",&data_mhs[flag].smt);
					}
					else {
						printf("\nNPM tidak ada dalam list Data Mahasiswa\n\n");
					}				
	
}

void binary_search(int sistem){
	
	
	int first;
	int mid;					
	int last= data - 1;
	int found = 0;
	int i=0;
	char find[100];
	
		bubble_sort( 1);
			
		printf("Masukkan NPM yang ingin anda cari menggunakan Binary Search \t: ");				
		scanf("%s",&find);	
						
		while(found==0 && i < data - 1){
			mid = (first + last)/2;
			if(strcmp(data_mhs[mid].npm,find) == 0){
				found = mid;
			}
			else{
				if(strcmp(data_mhs[mid].npm,find) < 0){
					first = mid + 1;
				}else{
					last = mid - 1;
				}
			}
			i++;
		}
		
					if (found == -1){
						printf("\nNPM tidak ada dalam list Data Mahasiswa\n\n");
					}
					else {
						printf("\nNPM %s berhasil ditemukan dalam list, dan berada pada Mahasiswa Ke-%d\n\n", find, found);
						printf("\nNama\t\t : %s",&data_mhs[found].nama);
						printf("\nNPM\t\t : %s",&data_mhs[found].npm);
						printf("\nAlamat\t\t : %s",&data_mhs[found].alamat);
						printf("\nEmail\t\t : %s",&data_mhs[found].email);
						printf("\nNomor HP\t : %s",&data_mhs[found].nohp);
						printf("\nDosen Wali\t : %s",&data_mhs[found].doswal);
						printf("\nSemester\t : %s\n",&data_mhs[found].smt);
					}				
}


void view(){
	
	int i;
	if(data>0){
		
		for(i=0;i<data;i++){
			printf("Mahasiswa ke \t\t: %d\n",i+1);
			printf("Nama \t\t\t: %s\n",data_mhs[i].nama);	
			printf("NPM \t\t\t: %s\n",data_mhs[i].npm);
			printf("Alamat \t\t\t: %s\n",data_mhs[i].alamat);
			printf("Email \t\t\t: %s\n",data_mhs[i].email);
			printf("Nomor HP\t\t: %s\n",data_mhs[i].nohp);
			printf("Dosen Wali \t\t: %s\n",data_mhs[i].doswal);
			printf("Semester \t\t: %s\n\n",data_mhs[i].smt);
		}
	}else{
		printf("TIDAK ADA DATA\n");
	}
}


int main() {
	
	data = sizeof(data_mhs)/sizeof(data_mhs[0]);
	int i=0;
	int pilih=0;
	char nama[50],npm[12],alamat[50],email[30],nohp[15],doswal[30],smt[5];
	awal:
	
	
	printf("\n\n");
	printf("*********************************************************************\n");
	printf("=========================== Data Mahasiswa ==========================\n");
	printf("*********************************************************************\n");
	printf("List Data Mahasiswa saat ini: \n\n");
	view();
	printf("Menu :\n1. Insert Data\n2. Update Data\n3. Delete Data\n4. Sorting Data berdasarkan NPM\n5. Searching data\n6. Exit\n\nPilih menu : ");
	scanf("%d",&pilih);
	
	if(pilih==1){
		printf("\nNama : ");
		scanf(" %[^\n]s",&nama);
		printf("NPM : ");
		scanf("%s",&npm);
		printf("Alamat : ");
		scanf(" %[^\n]s",&alamat);
		printf("Email : ");
		scanf("%s",&email);
		printf("Nomor HP : ");
		scanf("%s",&nohp);
		printf("Dosen Wali : ");
		scanf(" %[^\n]s",&doswal);
		printf("Semester : ");
		scanf("%s",&smt);
		insert(nama, npm, alamat, email, nohp, doswal, smt);
		system("cls");
		goto awal;	
		
	}else if(pilih==2){
		int no=-1;
		printf("Masukkan nomor data yang akan diedit : ");
		input_edit:
		scanf("%d",&no);
		
		if(no>data){
			printf("Data dengan nomor %d tidak ditemukan, mohon masukkan kembali : ");
			goto input_edit;
		}else{
			printf("Nama : ");
			scanf("%s",&nama);
			printf("NPM : ");
			scanf(" %[^\n]s",&npm);
			printf("Alamat : ");
			scanf("%s",&alamat);
			printf("Email : ");
			scanf("%s",&email);
			printf("Nomor HP : ");
			scanf("%s",&nohp);
			printf("Dosen Wali : ");
			scanf("%s",&doswal);
			printf("Semester : ");
			scanf("%s",&smt);
			update(no-1, nama, npm, alamat, email, nohp, doswal, smt);
			system("cls");
			goto awal;
		}
		
	}else if(pilih==3){
		int no=-1;
		printf("Masukkan nomor data yang akan dihapus : ");
		input_delete:
		scanf("%d",&no);
		if(no>data){
			printf("Data dengan nomor %d tidak ditemukan, mohon masukkan kembali : ");
			goto input_delete;
		}else{
			delete(no-1);
			system("cls");
			goto awal;
		}
		
	}else if(pilih==4){
		int type,metode;
		input_metode:
		printf("Silahkan masukkan metode pengurutan:\n1. Bubble Sort\n2. Selection Sort\nPilihan anda : ");
		scanf("%d",&metode);
		if(metode>2||metode<1){
			printf("Inputan anda salah.\n"); 
			goto input_metode;
		};
		
		input_type:
		printf("Silahkan pilih urutan:\n1. Ascending\n2. Descending\nPilihan anda : ");
		scanf("%d",&type);
		if(type>2||type<1){
			printf("Inputan anda salah.\n"); 
			goto input_type;
		};
		struct timespec t1,t2;
		double accum;
		clock_gettime(CLOCK_MONOTONIC, &t1);
		
		if(metode==1){
			bubble_sort(type);
			system("pause");
			system("cls");
		}else if(metode==2){
			selection_sort(type);
			system("cls");
		}
		clock_gettime(CLOCK_MONOTONIC, &t2);
		double diff = t2.tv_nsec - t1.tv_nsec/CLOCKS_PER_SEC;
		printf("Waktu eksekusi untuk ");
		printf(metode==1?"bubble sort ":"selection sort ");
		printf("adalah %ld nanosecond\nTekan tombol apa saja untuk kembali ke menu awal \n",(long)(t2.tv_nsec-t1.tv_nsec));
		getch();
		goto awal;
				
	}else if(pilih==5){
		int  sistem;
		int z;
		
		
		input_sistem:
		printf("Silahkan masukkan sistem pencarian:\n1. Sequential Search\n2. Binary Search\nPilihan anda : ");
		scanf("%d", &sistem);
		if(sistem>2||sistem<1){
			printf("Inputan anda salah.\n"); 
			goto input_sistem;
		};
		
		if(sistem==1){
			
            sequential_search(sistem);
            system("pause");
            system("cls");
            	
		}else if(sistem==2){
		
           	binary_search(sistem);
           	system("pause");
            system("cls");
		}
		goto awal;
		
	}else if(pilih==6){
		printf("Terima kasih");
		system("cls");
	
	}else{
		printf("Inputan Anda Invalid.");
}
	
	return 0;
}
