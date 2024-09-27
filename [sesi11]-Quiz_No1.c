#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char nama[100];
    char nilai;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;
struct node* tail = NULL;

// fungsi untuk melakukan insert AFTER tail
void push(struct node** head, char* nama, char nilai) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    struct node* curr = (*head);

    strcpy(newNode->nama, nama);
    newNode->nilai = nilai;

    // Jika head masih kosong
    if (curr == NULL) {
        newNode->prev = newNode->next = NULL;
        (*head) = newNode;
    }
    // Jika tidak kosong
    else {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
        newNode->next = NULL;
    }
}

// fungsi untuk menukar posisi dua node dalam linked list
void swap(struct node* a, struct node* b) {
    char tempNama[100];
    char tempNilai;

    strcpy(tempNama, a->nama);
    tempNilai = a->nilai;

    strcpy(a->nama, b->nama);
    a->nilai = b->nilai;

    strcpy(b->nama, tempNama);
    b->nilai = tempNilai;
}

// fungsi untuk mensorting nilai
void sortList(struct node** head) {
    if (*head == NULL)
        return;

    struct node* current;
    int sorted;

    do {
        sorted = 1;
        current = *head;

        while (current->next != NULL) {
            if (current->nilai > current->next->nilai) {
                swap(current, current->next);
                sorted = 0;
            }

            current = current->next;
        }
    } while (!sorted);
}

// Fungsi untuk mencetak isi double linked list
void printList(struct node* head) {
    struct node* current = head;

    while (current != NULL) {
        printf("Nama: %s, Nilai: %c\n", current->nama, current->nilai);
        current = current->next;
    }
}

int main() {
    char nama[100];
    char nilai;
    int jumlah;
    int pilihan = 0;
    int i;

    while (pilihan != 3) {
        printf("Pilihan:\n");
        printf("1. Insert Data\n");
        printf("2. Lihat Data Sesuai Urutan Nilai\n");
        printf("3. Exit\n");

        printf("Choose: ");
        scanf("%d", &pilihan);

        if (pilihan == 1) {
            printf("Masukan jumlah data yang akan di-insert: ");
            scanf("%d", &jumlah);

            for (i = 1; i <= jumlah; i++) {
                printf("\nMasukan nama mahasiswa ke-%d: ", i);
                scanf("%s", nama);

                printf("Masukan nilai mahasiswa ke-%d: ", i);
                scanf(" %c", &nilai);

                push(&head, nama, nilai);
            }
            printf("\n");   
        } 
		else if (pilihan == 2) {
            sortList(&head);

            printf("\nData Sesuai Urutan Nilai:\n");
            printList(head);
            printf("\n");
        } 
		else if (pilihan == 3) {
            printf("Terima kasih, sampai jumpa!\n");
        } 
		else {
            printf("Maaf pilihan tidak tersedia, silahkan coba kembali.\n");
            printf("\n");
        }
    }

    return 0;
}

